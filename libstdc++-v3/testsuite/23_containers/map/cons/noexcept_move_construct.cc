// { dg-do compile { target c++11 } }

// 2011-06-01  Paolo Carlini  <paolo.carlini@oracle.com>
//
// Copyright (C) 2011-2018 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <map>

typedef std::map<int, int> mtype;

static_assert( std::is_nothrow_move_constructible<mtype>::value,
	       "noexcept move constructor" );
static_assert( std::is_nothrow_constructible<mtype,
	       mtype&&, const typename mtype::allocator_type&>::value,
	       "noexcept move constructor with allocator" );

struct not_noexcept_less
{
  not_noexcept_less() = default;
  not_noexcept_less(const not_noexcept_less&) /* noexcept */
  { }

  bool
  operator()(int l, int r) const
  { return l < r; }
};

typedef std::map<int, int, not_noexcept_less> emtype;

static_assert( !std::is_nothrow_constructible<emtype, emtype&&,
	       const typename emtype::allocator_type&>::value,
	       "except move constructor with allocator" );
