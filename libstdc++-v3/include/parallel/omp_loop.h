// -*- C++ -*-

// Copyright (C) 2007 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software
// Foundation; either version 2, or (at your option) any later
// version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
// MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free
// software library without restriction.  Specifically, if other files
// instantiate templates or use macros or inline functions from this
// file, or you compile this file and link it with other files to
// produce an executable, this file does not by itself cause the
// resulting executable to be covered by the GNU General Public
// License.  This exception does not however invalidate any other
// reasons why the executable file might be covered by the GNU General
// Public License.

/** @file parallel/omp_loop.h
 *  @brief Parallelization of embarrassingly parallel execution by
 *  means of an OpenMP for loop.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Felix Putze.

#ifndef _GLIBCXX_PARALLEL_OMP_LOOP_H
#define _GLIBCXX_PARALLEL_OMP_LOOP_H 1

#include <omp.h>

#include <parallel/settings.h>
#include <parallel/basic_iterator.h>

namespace __gnu_parallel
{
  /** @brief Embarrassingly parallel algorithm for random access
   * iterators, using an OpenMP for loop.
   *
   *  @param begin Begin iterator of element sequence.
   *  @param end End iterator of element sequence.
   *  @param o User-supplied functor (comparator, predicate, adding
   *  functor, etc.).
   *  @param f Functor to "process" an element with op (depends on
   *  desired functionality, e. g. for std::for_each(), ...).
   *  @param r Functor to "add" a single result to the already
   *  processed elements (depends on functionality).
   *  @param base Base value for reduction.
   *  @param output Pointer to position where final result is written to
   *  @param bound Maximum number of elements processed (e. g. for
   *  std::count_n()).
   *  @return User-supplied functor (that may contain a part of the result).
   */
  template<typename RandomAccessIterator, typename Op, typename Fu, typename Red, typename Result>
  Op
  for_each_template_random_access_omp_loop(RandomAccessIterator begin, RandomAccessIterator end, Op o, Fu& f, Red r, Result base, Result& output, typename std::iterator_traits<RandomAccessIterator>::difference_type bound)
  {
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;

    thread_index_t num_threads = (get_max_threads() < (end - begin)) ? get_max_threads() : static_cast<thread_index_t>((end - begin));
    Result *thread_results = new Result[num_threads];
    difference_type length = end - begin;

    for (thread_index_t i = 0; i < num_threads; i++)
      {
	thread_results[i] = r(thread_results[i], f(o, begin+i));
      }

#pragma omp parallel num_threads(num_threads)
    {
#pragma omp for schedule(dynamic, Settings::workstealing_chunk_size)
      for (difference_type pos = 0; pos < length; pos++)
	{
	  thread_results[omp_get_thread_num()] = r(thread_results[omp_get_thread_num()], f(o, begin+pos));
	}
    }

    for (thread_index_t i = 0; i < num_threads; i++)
      {
	output = r(output, thread_results[i]);
      }

    delete [] thread_results;

    // Points to last element processed (needed as return value for
    // some algorithms like transform).
    f.finish_iterator = begin + length;

    return o;
  }
} // end namespace

#endif
