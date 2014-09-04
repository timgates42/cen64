//
// rsp/opcodes_priv.h: RSP opcode types and info.
//
// CEN64: Cycle-Accurate Nintendo 64 Simulator.
// Copyright (C) 2014, Tyler J. Stachecki.
//
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//

#ifndef __rsp_opcodes_priv_h__
#define __rsp_opcodes_priv_h__
#include "common.h"
#include "rsp/opcodes.h"

#define INFO1(x) (OPCODE_INFO_##x)
#define INFO2(x,y) (INFO1(x) | OPCODE_INFO_##y)
#define INFO3(x,y,z) (INFO2(x,y) | OPCODE_INFO_##z)
#define INFO4(x,y,z,a) (INFO3(x,y,z) | OPCODE_INFO_##a)
#define INFO5(x,y,z,a,b) (INFO4(x,y,z,a) | OPCODE_INFO_##b)
#define INVALID RSP_BUILD_OP(INVALID, INV, INFO1(NONE))
#define VINVALID RSP_BUILD_OP(VINVALID, VINV, INFO1(VECTOR))

#define ADDIU RSP_BUILD_OP(ADDIU, ADDIU_SUBIU, INFO1(NEEDRS))
#define ADDU RSP_BUILD_OP(ADDU, ADDU_SUBU, INFO2(NEEDRS, NEEDRT))
#define AND RSP_BUILD_OP(AND, AND_OR_XOR, INFO2(NEEDRS, NEEDRT))
#define ANDI RSP_BUILD_OP(ANDI, ANDI_ORI_XORI, INFO1(NEEDRS))
#define BEQ RSP_BUILD_OP(BEQ, BEQ_BNE, INFO3(BRANCH, NEEDRS, NEEDRT))
#define BGEZ RSP_BUILD_OP(BGEZ, BGEZ_BLTZ, INFO2(BRANCH, NEEDRS))
#define BGEZAL RSP_BUILD_OP(BGEZAL, BGEZAL_BLTZAL, INFO2(BRANCH, NEEDRS))
#define BGTZ RSP_BUILD_OP(BGTZ, BGTZ_BLEZ, INFO2(BRANCH, NEEDRS))
#define BLEZ RSP_BUILD_OP(BLEZ, BGTZ_BLEZ, INFO2(BRANCH, NEEDRS))
#define BLTZ RSP_BUILD_OP(BLTZ, BGEZ_BLTZ, INFO2(BRANCH, NEEDRS))
#define BLTZAL RSP_BUILD_OP(BLTZAL, BGEZAL_BLTZAL, INFO2(BRANCH, NEEDRS))
#define BNE RSP_BUILD_OP(BNE, BEQ_BNE, INFO3(BRANCH, NEEDRS, NEEDRT))
#define BREAK RSP_BUILD_OP(BREAK, INV, INFO1(NONE))
#define J RSP_BUILD_OP(J, J_JAL, INFO1(BRANCH))
#define JAL RSP_BUILD_OP(JAL, J_JAL, INFO1(BRANCH))
#define JALR RSP_BUILD_OP(JALR, JALR_JR, INFO2(BRANCH, NEEDRS))
#define JR RSP_BUILD_OP(JR, JALR_JR, INFO2(BRANCH, NEEDRS))
#define LB RSP_BUILD_OP(LB, LOAD, INFO1(NEEDRS))
#define LBU RSP_BUILD_OP(LBU, LOAD, INFO1(NEEDRS))
#define LH RSP_BUILD_OP(LH, LOAD, INFO1(NEEDRS))
#define LHU RSP_BUILD_OP(LHU, LOAD, INFO1(NEEDRS))
#define LUI RSP_BUILD_OP(LUI, LUI, INFO1(NONE))
#define LW RSP_BUILD_OP(LW, LOAD, INFO1(NEEDRS))
#define NOP RSP_BUILD_OP(NOP, INV, INFO1(NONE))
#define NOR RSP_BUILD_OP(NOR, NOR, INFO2(NEEDRS, NEEDRT))
#define OR RSP_BUILD_OP(OR, AND_OR_XOR, INFO2(NEEDRS, NEEDRT))
#define ORI RSP_BUILD_OP(ORI, ANDI_ORI_XORI, INFO1(NEEDRS))
#define SB RSP_BUILD_OP(SB, STORE, INFO2(NEEDRS, NEEDRT))
#define SH RSP_BUILD_OP(SH, STORE, INFO2(NEEDRS, NEEDRT))
#define SLL RSP_BUILD_OP(SLL, SLL, INFO1(NEEDRT))
#define SLLV RSP_BUILD_OP(SLLV, SLLV, INFO2(NEEDRS, NEEDRT))
#define SLT RSP_BUILD_OP(SLT, SLT, INFO2(NEEDRS, NEEDRT))
#define SLTI RSP_BUILD_OP(SLTI, SLTI, INFO1(NEEDRS))
#define SLTIU RSP_BUILD_OP(SLTIU, SLTIU, INFO1(NEEDRS))
#define SLTU RSP_BUILD_OP(SLTU, SLTU, INFO2(NEEDRS, NEEDRT))
#define SRA RSP_BUILD_OP(SRA, SRA, INFO1(NEEDRT))
#define SRAV RSP_BUILD_OP(SRAV, SRAV, INFO2(NEEDRS, NEEDRT))
#define SRL RSP_BUILD_OP(SRL, SRL, INFO1(NEEDRT))
#define SRLV RSP_BUILD_OP(SRLV, SRLV, INFO2(NEEDRS, NEEDRT))
#define SUBU RSP_BUILD_OP(SUBU, ADDU_SUBU, INFO1(NEEDRS))
#define SW RSP_BUILD_OP(SW, STORE, INFO2(NEEDRS, NEEDRT))
#define XOR RSP_BUILD_OP(XOR, AND_OR_XOR, INFO2(NEEDRS, NEEDRT))
#define XORI RSP_BUILD_OP(XORI, ANDI_ORI_XORI, INFO1(NEEDRS))

#define MFC0 RSP_BUILD_OP(MFC0, INV, INFO1(NONE))
#define MTC0 RSP_BUILD_OP(MTC0, INV, INFO1(NEEDRT))

#define CFC2 RSP_BUILD_OP(CFC2, INV, INFO1(NONE))
#define CTC2 RSP_BUILD_OP(CTC2, INV, INFO1(NONE))
#define MFC2 RSP_BUILD_OP(MFC2, INV, INFO1(NONE))
#define MTC2 RSP_BUILD_OP(MTC2, INV, INFO1(NONE))

#define VABS RSP_BUILD_OP(VABS, VINV, INFO1(VECTOR))
#define VADD RSP_BUILD_OP(VADD, VINV, INFO1(VECTOR))
#define VADDC RSP_BUILD_OP(VADDC, VINV, INFO1(VECTOR))
#define VAND RSP_BUILD_OP(VAND, VINV, INFO1(VECTOR))
#define VCH RSP_BUILD_OP(VCH, VINV, INFO1(VECTOR))
#define VCL RSP_BUILD_OP(VCL, VINV, INFO1(VECTOR))
#define VCR RSP_BUILD_OP(VCR, VINV, INFO1(VECTOR))
#define VEQ RSP_BUILD_OP(VEQ, VINV, INFO1(VECTOR))
#define VGE RSP_BUILD_OP(VGE, VINV, INFO1(VECTOR))
#define VLT RSP_BUILD_OP(VLT, VINV, INFO1(VECTOR))
#define VMACF RSP_BUILD_OP(VMACF, VINV, INFO1(VECTOR))
#define VMACQ RSP_BUILD_OP(VMACQ, VINV, INFO1(VECTOR))
#define VMACU RSP_BUILD_OP(VMACU, VINV, INFO1(VECTOR))
#define VMADH RSP_BUILD_OP(VMADH, VINV, INFO1(VECTOR))
#define VMADL RSP_BUILD_OP(VMADL, VINV, INFO1(VECTOR))
#define VMADM RSP_BUILD_OP(VMADM, VINV, INFO1(VECTOR))
#define VMADN RSP_BUILD_OP(VMADN, VINV, INFO1(VECTOR))
#define VMOV RSP_BUILD_OP(VMOV, VINV, INFO1(VECTOR))
#define VMRG RSP_BUILD_OP(VMRG, VINV, INFO1(VECTOR))
#define VMUDH RSP_BUILD_OP(VMUDH, VINV, INFO1(VECTOR))
#define VMUDL RSP_BUILD_OP(VMUDL, VINV, INFO1(VECTOR))
#define VMUDM RSP_BUILD_OP(VMUDM, VINV, INFO1(VECTOR))
#define VMUDN RSP_BUILD_OP(VMUDN, VINV, INFO1(VECTOR))
#define VMULF RSP_BUILD_OP(VMULF, VINV, INFO1(VECTOR))
#define VMULQ RSP_BUILD_OP(VMULQ, VINV, INFO1(VECTOR))
#define VMULU RSP_BUILD_OP(VMULU, VINV, INFO1(VECTOR))
#define VNAND RSP_BUILD_OP(VNAND, VINV, INFO1(VECTOR))
#define VNE RSP_BUILD_OP(VNE, VINV, INFO1(VECTOR))
#define VNOP RSP_BUILD_OP(VNOP, INV, INFO1(VECTOR))
#define VNOR RSP_BUILD_OP(VNOR, VINV, INFO1(VECTOR))
#define VNXOR RSP_BUILD_OP(VNXOR, VINV, INFO1(VECTOR))
#define VOR RSP_BUILD_OP(VOR, VINV, INFO1(VECTOR))
#define VRCP RSP_BUILD_OP(VRCP, VINV, INFO1(VECTOR))
#define VRCPH RSP_BUILD_OP(VRCPH, VINV, INFO1(VECTOR))
#define VRCPL RSP_BUILD_OP(VRCPL, VINV, INFO1(VECTOR))
#define VRNDN RSP_BUILD_OP(VRNDN, VINV, INFO1(VECTOR))
#define VRNDP RSP_BUILD_OP(VRNUP, VINV, INFO1(VECTOR))
#define VRSQ RSP_BUILD_OP(VRSQ, VINV, INFO1(VECTOR))
#define VRSQH RSP_BUILD_OP(VRSQH, VINV, INFO1(VECTOR))
#define VRSQL RSP_BUILD_OP(VRSQL, VINV, INFO1(VECTOR))
#define VSAR RSP_BUILD_OP(VSAR, VINV, INFO1(VECTOR))
#define VSUB RSP_BUILD_OP(VSUB, VINV, INFO1(VECTOR))
#define VSUBC RSP_BUILD_OP(VSUBC, VINV, INFO1(VECTOR))
#define VXOR RSP_BUILD_OP(VXOR, VINV, INFO1(VECTOR))

#define LBV RSP_BUILD_OP(LBV, INV, INFO1(NONE))
#define LDV RSP_BUILD_OP(LDV, INV, INFO1(NONE))
#define LFV RSP_BUILD_OP(LFV, INV, INFO1(NONE))
#define LHV RSP_BUILD_OP(LHV, INV, INFO1(NONE))
#define LLV RSP_BUILD_OP(LLV, INV, INFO1(NONE))
#define LPV RSP_BUILD_OP(LPV, INV, INFO1(NONE))
#define LQV RSP_BUILD_OP(LQV, INV, INFO1(NONE))
#define LRV RSP_BUILD_OP(LRV, INV, INFO1(NONE))
#define LSV RSP_BUILD_OP(LSV, INV, INFO1(NONE))
#define LTV RSP_BUILD_OP(LTV, INV, INFO1(NONE))
#define LUV RSP_BUILD_OP(LUV, INV, INFO1(NONE))

#define SBV RSP_BUILD_OP(SBV, INV, INFO1(NONE))
#define SDV RSP_BUILD_OP(SDV, INV, INFO1(NONE))
#define SFV RSP_BUILD_OP(SFV, INV, INFO1(NONE))
#define SHV RSP_BUILD_OP(SHV, INV, INFO1(NONE))
#define SLV RSP_BUILD_OP(SLV, INV, INFO1(NONE))
#define SPV RSP_BUILD_OP(SPV, INV, INFO1(NONE))
#define SQV RSP_BUILD_OP(SQV, INV, INFO1(NONE))
#define SRV RSP_BUILD_OP(SRV, INV, INFO1(NONE))
#define SSV RSP_BUILD_OP(SSV, INV, INFO1(NONE))
#define STV RSP_BUILD_OP(STV, INV, INFO1(NONE))
#define SUV RSP_BUILD_OP(SUV, INV, INFO1(NONE))
#define SWV RSP_BUILD_OP(SWV, INV, INFO1(NONE))

#endif

