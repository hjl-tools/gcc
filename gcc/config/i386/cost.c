#include "cost.h"

const int ix86_cost_model_size = sizeof (struct processor_costs);

static stringop_algs intel_memcpy[2] = {
  {libcall, {{11, loop, false}, {-1, rep_prefix_4_byte, false}}},
  {libcall, {{32, loop, false}, {64, rep_prefix_4_byte, false},
             {8192, rep_prefix_8_byte, false}, {-1, libcall, false}}}};
static stringop_algs intel_memset[2] = {
  {libcall, {{8, loop, false}, {15, unrolled_loop, false},
             {2048, rep_prefix_4_byte, false}, {-1, libcall, false}}},
  {libcall, {{24, loop, false}, {32, unrolled_loop, false},
             {8192, rep_prefix_8_byte, false}, {-1, libcall, false}}}};
const
struct processor_costs ix86_cost_model = {
  COSTS_N_INSNS (1),			/* cost of an add instruction */
  COSTS_N_INSNS (1) + 1,		/* cost of a lea instruction */
  COSTS_N_INSNS (1),			/* variable shift costs */
  COSTS_N_INSNS (1),			/* constant shift costs */
  {COSTS_N_INSNS (3),			/* cost of starting multiply for QI */
   COSTS_N_INSNS (3),			/*				 HI */
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

  /* All move costs are relative to integer->integer move times 2 and thus
     they are latency*2. */
  6,				     /* cost for loading QImode using movzbl */
  {4, 4, 4},				/* cost of loading integer registers
					   in QImode, HImode and SImode.
					   Relative to reg-reg move (2).  */
  {6, 6, 6},				/* cost of storing integer registers */
  2,					/* cost of reg,reg fld/fst */
  {6, 6, 8},				/* cost of loading fp registers
					   in SFmode, DFmode and XFmode */
  {6, 6, 10},				/* cost of storing fp registers
					   in SFmode, DFmode and XFmode */
  2,					/* cost of moving MMX register */
  {6, 6},				/* cost of loading MMX registers
					   in SImode and DImode */
  {6, 6},				/* cost of storing MMX registers
					   in SImode and DImode */
  2, 2, 2,				/* cost of moving XMM,YMM,ZMM register */
  {6, 6, 6, 6, 6},			/* cost of loading SSE registers
					   in 32,64,128,256 and 512-bit */
  {10, 10, 10, 10, 10},			/* cost of unaligned loads.  */
  {6, 6, 6, 6, 6},			/* cost of storing SSE registers
					   in 32,64,128,256 and 512-bit */
  {10, 10, 10, 10, 10},			/* cost of unaligned loads.  */
  4, 4,					/* SSE->integer and integer->SSE moves */
  6, 6,					/* Gather load static, per_elt.  */
  6, 6,					/* Gather store static, per_elt.  */
  32,					/* size of l1 cache.  */
  256,					/* size of l2 cache.  */
  64,					/* size of prefetch block */
  6,					/* number of parallel prefetches */
  3,					/* Branch cost */
  COSTS_N_INSNS (8),			/* cost of FADD and FSUB insns.  */
  COSTS_N_INSNS (8),			/* cost of FMUL instruction.  */
  COSTS_N_INSNS (20),			/* cost of FDIV instruction.  */
  COSTS_N_INSNS (8),			/* cost of FABS instruction.  */
  COSTS_N_INSNS (8),			/* cost of FCHS instruction.  */
  COSTS_N_INSNS (40),			/* cost of FSQRT instruction.  */

  COSTS_N_INSNS (8),			/* cost of cheap SSE instruction.  */
  COSTS_N_INSNS (8),			/* cost of ADDSS/SD SUBSS/SD insns.  */
  COSTS_N_INSNS (8),			/* cost of MULSS instruction.  */
  COSTS_N_INSNS (8),			/* cost of MULSD instruction.  */
  COSTS_N_INSNS (6),			/* cost of FMA SS instruction.  */
  COSTS_N_INSNS (6),			/* cost of FMA SD instruction.  */
  COSTS_N_INSNS (20),			/* cost of DIVSS instruction.  */
  COSTS_N_INSNS (20),			/* cost of DIVSD instruction.  */
  COSTS_N_INSNS (40),			/* cost of SQRTSS instruction.  */
  COSTS_N_INSNS (40),			/* cost of SQRTSD instruction.  */
  1, 4, 1, 1,				/* reassoc int, fp, vec_int, vec_fp.  */
  intel_memcpy,
  intel_memset,
  COSTS_N_INSNS (3),			/* cond_taken_branch_cost.  */
  COSTS_N_INSNS (1),			/* cond_not_taken_branch_cost.  */
};
