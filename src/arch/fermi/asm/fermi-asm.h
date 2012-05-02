/*
 *  Multi2Sim
 *  Copyright (C) 2011  Rafael Ubal (ubal@ece.neu.edu)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef FERMI_ASM_H
#define FERMI_ASM_H

#include <stdio.h>



/* Microcode Formats */
enum frm_fmt_enum
{
	FRM_FMT_NONE = 0, 

#define DEFINST(_name, _fmt_str, _fmt, _category, _opcode) \
	FRM_FMT_##_fmt,
#include <fermi-asm.dat>
#undef DEFINST

	/* Max */
	FRM_FMT_COUNT
};


/* Special Registers */
enum frm_sr_enum
{
	FRM_SR_Laneld = 0, 
	FRM_SR_VirtCfg = 2, 
	FRM_SR_VirtId, 
	FRM_SR_PM0, 
	FRM_SR_PM1, 
	FRM_SR_PM2, 
	FRM_SR_PM3, 
	FRM_SR_PM4, 
	FRM_SR_PM5, 
	FRM_SR_PM6, 
	FRM_SR_PM7, 
	FRM_SR_PRIM_TYPE = 16, 
	FRM_SR_INVOCATION_ID, 
	FRM_SR_Y_DIRECTION, 
	FRM_SR_MACHINE_ID_0 = 24, 
	FRM_SR_MACHINE_ID_1, 
	FRM_SR_MACHINE_ID_2, 
	FRM_SR_MACHINE_ID_3, 
	FRM_SR_AFFINITY, 
	FRM_SR_Tid = 32,  
	FRM_SR_Tid_X, 
	FRM_SR_Tid_Y, 
	FRM_SR_Tid_Z, 
	FRM_SR_CTAParam, 
	FRM_SR_CTAid_X, 
	FRM_SR_CTAid_Y, 
	FRM_SR_CTAid_Z, 
	FRM_SR_NTid, 
	FRM_SR_NTid_X, 
	FRM_SR_NTid_Y, 
	FRM_SR_NTid_Z, 
	FRM_SR_GridParam, 
	FRM_SR_NCTAid_X, 
	FRM_SR_NCTAid_Y, 
	FRM_SR_NCTAid_Z, 
	FRM_SR_SWinLo, 
	FRM_SR_SWINSZ, 
	FRM_SR_SMemSz, 
	FRM_SR_SMemBanks, 
	FRM_SR_LWinLo, 
	FRM_SR_LWINSZ, 
	FRM_SR_LMemLoSz, 
	FRM_SR_LMemHiOff, 
	FRM_SR_EqMask, 
	FRM_SR_LtMask, 
	FRM_SR_LeMask, 
	FRM_SR_GtMask, 
	FRM_SR_GeMask, 
	FRM_SR_ClockLo = 80, 
	FRM_SR_ClockHi, 

	/* Max */
	FRM_SR_COUNT
};




/* 
 * Structure of Microcode Format
 */

struct frm_fmt_fp_ffma_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int sat : 1; /* [5] */
	unsigned long long int ftzfmz : 2; /* [7:6] */
	unsigned long long int neg_src3 : 1; /* [8] */
	unsigned long long int neg_src2 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 1; /* [48] */
	unsigned long long int src3 : 6; /* [54:49] */
	unsigned long long int rnd : 2; /* [56:55] */
	unsigned long long int __reserved2 : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_fadd_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int ftz : 1; /* [5] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int abs_src1 : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int neg_src1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 1; /* [48] */
	unsigned long long int sat : 1; /* [49] */
	unsigned long long int __reserved2 : 5; /* [54:50] */
	unsigned long long int rnd : 2; /* [56:55] */
	unsigned long long int fma : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_fadd32i_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int ftz : 1; /* [5] */
	unsigned long long int __reserved1 : 1; /* [6] */
	unsigned long long int abs_src1 : 1; /* [7] */
	unsigned long long int __reserved2 : 1; /* [8] */
	unsigned long long int neg_src1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int imm32 : 32; /* [57:26] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_fcmp_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int ftz : 1; /* [5] */
	unsigned long long int __reserved1 : 4; /* [9:6] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved2 : 1; /* [48] */
	unsigned long long int src3 : 6; /* [54:49] */
	unsigned long long int cmp : 4; /* [58:55] */
	unsigned long long int op1 : 5; /* [63:59] */
};

struct frm_fmt_fp_fmul_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int sat : 1; /* [5] */
	unsigned long long int ftzfmz : 2; /* [7:6] */
	unsigned long long int fma_mode : 2; /* [9:8] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 7; /* [54:48] */
	unsigned long long int rnd : 2; /* [56:55] */
	unsigned long long int neg_src2 : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_fmul32i_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int sat : 1; /* [5] */
	unsigned long long int ftzfmz : 2; /* [7:6] */
	unsigned long long int fma_mode : 2; /* [9:8] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int imm32 : 32; /* [57:26] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_fsetp_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 2; /* [5:4] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int abs_src1 : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int neg_src1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int Q : 3; /* [16:14] */
	unsigned long long int P : 3; /* [19:17] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 1; /* [48] */
	unsigned long long int R : 4; /* [52:49] */
	unsigned long long int logic : 2; /* [54:53] */
	unsigned long long int cmp : 4; /* [58:55] */
	unsigned long long int op1 : 5; /* [63:59] */
};

struct frm_fmt_fp_mufu_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int sat : 1; /* [5] */
	unsigned long long int __reserved1 : 1; /* [6] */
	unsigned long long int abs_src1 : 1; /* [7] */
	unsigned long long int __reserved2 : 1; /* [8] */
	unsigned long long int neg_src1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int op : 3; /* [28:26] */
	unsigned long long int __reserved3 : 29; /* [57:29] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_dfma_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 4; /* [7:4] */
	unsigned long long int neg_src3 : 1; /* [8] */
	unsigned long long int neg_src2 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 1; /* [48] */
	unsigned long long int src3 : 6; /* [54:49] */
	unsigned long long int __reserved2 : 3; /* [57:55] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_dadd_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 2; /* [5:4] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int abs_src1 : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int neg_src1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 7; /* [54:48] */
	unsigned long long int rnd : 2; /* [56:55] */
	unsigned long long int __reserved2 : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_dmul_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 5; /* [8:4] */
	unsigned long long int neg_src2 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 7; /* [54:48] */
	unsigned long long int rnd : 2; /* [56:55] */
	unsigned long long int __reserved2 : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_fp_dsetp_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 2; /* [5:4] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int abs_src1 : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int neg_src1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int Q : 3; /* [16:14] */
	unsigned long long int P : 3; /* [19:17] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int src2_mod : 2; /* [47:46] */
	unsigned long long int __reserved1 : 1; /* [48] */
	unsigned long long int R : 4; /* [52:49] */
	unsigned long long int logic : 2; /* [54:53] */
	unsigned long long int cmp : 4; /* [58:55] */
	unsigned long long int op1 : 5; /* [63:59] */
};

struct frm_fmt_int_op3_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 6; /* [9:4] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved1 : 10; /* [57:48] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_int_op3_p_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 6; /* [9:4] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int p : 3; /* [16:14] */
	unsigned long long int P : 3; /* [19:17] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved1 : 1; /* [48] */
	unsigned long long int opp : 4; /* [52:49] */
	unsigned long long int logic_op : 2; /* [54:53] */
	unsigned long long int comp_op : 4; /* [58:55] */
	unsigned long long int op1 : 5; /* [63:59] */
};

struct frm_fmt_int_op4_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 6; /* [9:4] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int cc : 1; /* [48] */
	unsigned long long int src3 : 6; /* [54:49] */
	unsigned long long int __reserved1 : 1; /* [55] */
	unsigned long long int sat : 1; /* [56] */
	unsigned long long int __reserved2 : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_int_op4_s_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int shamt : 5; /* [9:5] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved1 : 10; /* [57:48] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_conv_f2f_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int s : 1; /* [4] */
	unsigned long long int sat : 1; /* [5] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int pass_round : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int __reserved1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int dtype : 2; /* [21:20] */
	unsigned long long int __reserved2 : 1; /* [22] */
	unsigned long long int stype : 2; /* [24:23] */
	unsigned long long int __reserved3 : 1; /* [25] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved4 : 1; /* [48] */
	unsigned long long int rnd : 2; /* [50:49] */
	unsigned long long int __reserved5 : 4; /* [54:51] */
	unsigned long long int ftz : 1; /* [55] */
	unsigned long long int __reserved6 : 2; /* [57:56] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_conv_f2i_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 2; /* [4:5] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int dtype_s : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int __reserved1 : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int dtype_n : 2; /* [21:20] */
	unsigned long long int __reserved2 : 1; /* [22] */
	unsigned long long int stype : 2; /* [24:23] */
	unsigned long long int __reserved3 : 1; /* [25] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved4 : 1; /* [48] */
	unsigned long long int rnd : 2; /* [50:49] */
	unsigned long long int __reserved5 : 4; /* [54:51] */
	unsigned long long int ftz : 1; /* [55] */
	unsigned long long int __reserved6 : 2; /* [57:56] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_conv_i2f_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 2; /* [5:4] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int __reserved1 : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int stype_s : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int dtype : 2; /* [21:20] */
	unsigned long long int __reserved2 : 1; /* [22] */
	unsigned long long int stype_n : 2; /* [24:23] */
	unsigned long long int __reserved3 : 1; /* [25] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved4 : 1; /* [48] */
	unsigned long long int rnd : 2; /* [50:49] */
	unsigned long long int __reserved5 : 7; /* [57:51] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_conv_i2i_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int sat : 1; /* [5] */
	unsigned long long int abs_src2 : 1; /* [6] */
	unsigned long long int dtype_s : 1; /* [7] */
	unsigned long long int neg_src2 : 1; /* [8] */
	unsigned long long int stype_s : 1; /* [9] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int dtype_n : 2; /* [21:20] */
	unsigned long long int __reserved2 : 1; /* [22] */
	unsigned long long int stype_n : 2; /* [24:23] */
	unsigned long long int __reserved3 : 1; /* [25] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int cc_dst : 1; /* [48] */
	unsigned long long int __reserved5 : 6; /* [54:49] */
	unsigned long long int b_src2 : 2; /* [56:55] */
	unsigned long long int __reserved6 : 1; /* [57] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_mov_op2_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 6; /* [9:4] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int __reserved1 : 6; /* [25:20] */
	unsigned long long int src2 : 20; /* [45:26] */
	unsigned long long int sel_src2 : 2; /* [47:46] */
	unsigned long long int __reserved2 : 10; /* [57:48] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_ldst_ld_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int type : 3; /* [7:5] */
	unsigned long long int cop : 2; /* [9:8] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int __reserved1 : 16; /* [41:26] */
	unsigned long long int offset : 16; /* [57:42] */
	unsigned long long int e : 1; /* [58] */
	unsigned long long int op1 : 5; /* [63:59] */
};

struct frm_fmt_ldst_st_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 1; /* [4] */
	unsigned long long int type : 3; /* [7:5] */
	unsigned long long int cop : 2; /* [9:8] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int src1 : 6; /* [25:20] */
	unsigned long long int __reserved1 : 16; /* [41:26] */
	unsigned long long int offset : 16; /* [57:42] */
	unsigned long long int e : 1; /* [58] */
	unsigned long long int op1 : 5; /* [63:59] */
};


struct frm_fmt_ctrl_none_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 54; /* [57:4] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_ctrl_op1_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 6; /* [9:4] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int op_mode : 1; /* [14] */
	unsigned long long int u : 1; /* [15] */
	unsigned long long int lmt : 1; /* [16] */
	unsigned long long int __reserved1 : 9; /* [25:17] */
	unsigned long long int imm : 24; /* [49:26] */
	unsigned long long int __reserved2 : 8; /* [57:50] */
	unsigned long long int op1 : 6; /* [63:58] */
};

struct frm_fmt_misc_op2_sreg_t
{
	unsigned long long int op0 : 4; /* [3:0] */
	unsigned long long int __reserved0 : 6; /* [9:4] */
	unsigned long long int pred : 4; /* [13:10] */
	unsigned long long int dst : 6; /* [19:14] */
	unsigned long long int __reserved1 : 6; /* [25:20] */
	unsigned long long int sreg : 8; /* [33:26] */
	unsigned long long int __reserved2 : 24; /* [57:34] */
	unsigned long long int op1 : 6; /* [63:58] */
};


enum frm_inst_category_enum
{
	FRM_INST_CAT_NONE = 0,

	FRM_INST_CAT_FP,  /* Floating point instructions */
	FRM_INST_CAT_INT,  /* Integer instructions */
	FRM_INST_CAT_CONV,  /* Conversion instructions */
	FRM_INST_CAT_MOV,  /* Movement instructions */
	FRM_INST_CAT_PRED,  /* Predicate/CC instructions */
	FRM_INST_CAT_TEX,  /* Texture instructions */
	FRM_INST_CAT_LDST, /* Compute load/store instructions */
	FRM_INST_CAT_SURF, /* Surface memory instructions */
	FRM_INST_CAT_CTRL, /* Control instructions */
	FRM_INST_CAT_MISC, /* Miscellaneous instructions */

	FRM_INST_CAT_COUNT
};


enum frm_inst_enum
{
	FRM_INST_NONE = 0, 

#define DEFINST(_name, _fmt_str, _fmt, _category, _opcode) \
	FRM_INST_##_name,
#include <fermi-asm.dat>
#undef DEFINST

	/* Max */
	FRM_INST_COUNT
};


union frm_inst_dword_t
{
	unsigned char bytes[8];

	struct frm_fmt_fp_ffma_t fp_ffma;
	struct frm_fmt_fp_fadd_t fp_fadd;
	struct frm_fmt_fp_fadd32i_t fp_fadd32i;
	struct frm_fmt_fp_fcmp_t fp_fcmp;
	struct frm_fmt_fp_fmul_t fp_fmul;
	struct frm_fmt_fp_fmul32i_t fp_fmul32i;
	struct frm_fmt_fp_fsetp_t fp_fsetp;
	struct frm_fmt_fp_mufu_t fp_mufu;
	struct frm_fmt_fp_dfma_t fp_dfma;
	struct frm_fmt_fp_dadd_t fp_dadd;
	struct frm_fmt_fp_dmul_t fp_dmul;
	struct frm_fmt_fp_dsetp_t fp_dsetp;
	struct frm_fmt_int_op3_t int_op3;
	struct frm_fmt_int_op3_p_t int_op3_p;
	struct frm_fmt_int_op4_t int_op4;
	struct frm_fmt_int_op4_s_t int_op4_s;
	struct frm_fmt_conv_f2f_t conv_f2f;
	struct frm_fmt_conv_f2i_t conv_f2i;
	struct frm_fmt_conv_i2f_t conv_i2f;
	struct frm_fmt_conv_i2i_t conv_i2i;
	struct frm_fmt_mov_op2_t mov_op2;
	struct frm_fmt_ldst_ld_t ldst_ld;
	struct frm_fmt_ldst_st_t ldst_st;
	struct frm_fmt_ctrl_none_t ctrl_none;
	struct frm_fmt_ctrl_op1_t ctrl_op1;
	struct frm_fmt_misc_op2_sreg_t misc_op2_sreg;
};


struct frm_inst_info_t
{
	enum frm_inst_enum inst;
	enum frm_inst_category_enum category;
	char *name;
	char *fmt_str;
	enum frm_fmt_enum fmt;
	unsigned int opcode;
	int size;
};

struct frm_inst_t
{
	unsigned int addr;
	union frm_inst_dword_t dword;
	struct frm_inst_info_t *info;
};


void frm_disasm_init(void);
void frm_inst_dump(FILE *f, char *str, int inst_str_size, unsigned char *buf, int inst_index);
void frm_inst_hex_dump(FILE *f, unsigned char *buf, int inst_index);

void frm_inst_dump_pred(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_ext(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_dst(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_P(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_Q(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_src1(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_src2(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_src3(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_imm(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_R(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);
void frm_inst_dump_offset(char **inst_str_ptr, int *inst_str_size, struct frm_inst_t *inst, enum frm_fmt_enum fmt);

void frm_inst_decode(struct frm_inst_t *inst);

#endif

