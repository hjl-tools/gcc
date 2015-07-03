#include "cost.h"

const int ix86_cost_model_size = sizeof (struct processor_costs);

/* Generic should produce code tuned for Core-i7 (and newer chips)
   and btver1 (and newer chips).  */

static stringop_algs generic_memcpy[2] = {
  {libcall, {{32, loop, false}, {8192, rep_prefix_4_byte, false},
             {-1, libcall, false}}},
  {libcall, {{32, loop, false}, {8192, rep_prefix_8_byte, false},
             {-1, libcall, false}}}};
static stringop_algs generic_memset[2] = {
  {libcall, {{32, loop, false}, {8192, rep_prefix_4_byte, false},
             {-1, libcall, false}}},
  {libcall, {{32, loop, false}, {8192, rep_prefix_8_byte, false},
             {-1, libcall, false}}}};
const
struct processor_costs ix86_cost_model = {
  COSTS_N_INSNS (1),			/* cost of an add instruction */
  /* On all chips taken into consideration lea is 2 cycles and more.  With
     this cost however our current implementation of synth_mult results in
     use of unnecessary temporary registers causing regression on several
     SPECfp benchmarks.  */
  COSTS_N_INSNS (1) + 1,		/* cost of a lea instruction */
  COSTS_N_INSNS (1),			/* variable shift costs */
  COSTS_N_INSNS (1),			/* constant shift costs */
  {COSTS_N_INSNS (3),			/* cost of starting multiply for QI */
   COSTS_N_INSNS (4),			/*				 HI */
   COSTS_N_INSNS (3),			/*				 SI */
   COSTS_N_INSNS (4),			/*				 DI */
   COSTS_N_INSNS (2)},			/*			      other */
  0,					/* cost of multiply per each bit set */
  {COSTS_N_INSNS (18),			/* cost of a divide/mod for QI */
   COSTS_N_INSNS (26),			/*			    HI */
   COSTS_N_INSNS (42),			/*			    SI */
   COSTS_N_INSNS (74),			/*			    DI */
   COSTS_N_INSNS (74)},			/*			    other */
  COSTS_N_INSNS (1),			/* cost of movsx */
  COSTS_N_INSNS (1),			/* cost of movzx */
  8,					/* "large" insn */
  17,					/* MOVE_RATIO */
  4,				     /* cost for loading QImode using movzbl */
  {4, 4, 4},				/* cost of loading integer registers
					   in QImode, HImode and SImode.
					   Relative to reg-reg move (2).  */
  {4, 4, 4},				/* cost of storing integer registers */
  4,					/* cost of reg,reg fld/fst */
  {12, 12, 12},				/* cost of loading fp registers
					   in SFmode, DFmode and XFmode */
  {6, 6, 8},				/* cost of storing fp registers
					   in SFmode, DFmode and XFmode */
  2,					/* cost of moving MMX register */
  {8, 8},				/* cost of loading MMX registers
					   in SImode and DImode */
  {8, 8},				/* cost of storing MMX registers
					   in SImode and DImode */
  2,					/* cost of moving SSE register */
  {8, 8, 8},				/* cost of loading SSE registers
					   in SImode, DImode and TImode */
  {8, 8, 8},				/* cost of storing SSE registers
					   in SImode, DImode and TImode */
  5,					/* MMX or SSE register to integer */
  32,					/* size of l1 cache.  */
  512,					/* size of l2 cache.  */
  64,					/* size of prefetch block */
  6,					/* number of parallel prefetches */
  /* Benchmarks shows large regressions on K8 sixtrack benchmark when this
     value is increased to perhaps more appropriate value of 5.  */
  3,					/* Branch cost */
  COSTS_N_INSNS (8),			/* cost of FADD and FSUB insns.  */
  COSTS_N_INSNS (8),			/* cost of FMUL instruction.  */
  COSTS_N_INSNS (20),			/* cost of FDIV instruction.  */
  COSTS_N_INSNS (8),			/* cost of FABS instruction.  */
  COSTS_N_INSNS (8),			/* cost of FCHS instruction.  */
  COSTS_N_INSNS (40),			/* cost of FSQRT instruction.  */
  generic_memcpy,
  generic_memset,
  1,					/* scalar_stmt_cost.  */
  1,					/* scalar load_cost.  */
  1,					/* scalar_store_cost.  */
  1,					/* vec_stmt_cost.  */
  1,					/* vec_to_scalar_cost.  */
  1,					/* scalar_to_vec_cost.  */
  1,					/* vec_align_load_cost.  */
  2,					/* vec_unalign_load_cost.  */
  1,					/* vec_store_cost.  */
  3,					/* cond_taken_branch_cost.  */
  1,					/* cond_not_taken_branch_cost.  */
};
