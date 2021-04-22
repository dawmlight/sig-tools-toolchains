// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-v -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV32 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-v -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV32-LABEL: @test_vfirst_m_b1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv64i1.i32(<vscale x 64 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv64i1.i64(<vscale x 64 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b1(vbool1_t op1, size_t vl) { return vfirst_m_b1(op1, vl); }

// CHECK-RV32-LABEL: @test_vfirst_m_b2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv32i1.i32(<vscale x 32 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv32i1.i64(<vscale x 32 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b2(vbool2_t op1, size_t vl) { return vfirst_m_b2(op1, vl); }

// CHECK-RV32-LABEL: @test_vfirst_m_b4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv16i1.i32(<vscale x 16 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv16i1.i64(<vscale x 16 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b4(vbool4_t op1, size_t vl) { return vfirst_m_b4(op1, vl); }

// CHECK-RV32-LABEL: @test_vfirst_m_b8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv8i1.i32(<vscale x 8 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv8i1.i64(<vscale x 8 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b8(vbool8_t op1, size_t vl) { return vfirst_m_b8(op1, vl); }

// CHECK-RV32-LABEL: @test_vfirst_m_b16(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv4i1.i32(<vscale x 4 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv4i1.i64(<vscale x 4 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b16(vbool16_t op1, size_t vl) {
  return vfirst_m_b16(op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b32(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv2i1.i32(<vscale x 2 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv2i1.i64(<vscale x 2 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b32(vbool32_t op1, size_t vl) {
  return vfirst_m_b32(op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b64(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.nxv1i1.i32(<vscale x 1 x i1> [[OP1:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.nxv1i1.i64(<vscale x 1 x i1> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b64(vbool64_t op1, size_t vl) {
  return vfirst_m_b64(op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv64i1.i32(<vscale x 64 x i1> [[OP1:%.*]], <vscale x 64 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv64i1.i64(<vscale x 64 x i1> [[OP1:%.*]], <vscale x 64 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b1_m(vbool1_t mask, vbool1_t op1, size_t vl) {
  return vfirst_m_b1_m(mask, op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv32i1.i32(<vscale x 32 x i1> [[OP1:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv32i1.i64(<vscale x 32 x i1> [[OP1:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b2_m(vbool2_t mask, vbool2_t op1, size_t vl) {
  return vfirst_m_b2_m(mask, op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv16i1.i32(<vscale x 16 x i1> [[OP1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv16i1.i64(<vscale x 16 x i1> [[OP1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b4_m(vbool4_t mask, vbool4_t op1, size_t vl) {
  return vfirst_m_b4_m(mask, op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv8i1.i32(<vscale x 8 x i1> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv8i1.i64(<vscale x 8 x i1> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b8_m(vbool8_t mask, vbool8_t op1, size_t vl) {
  return vfirst_m_b8_m(mask, op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b16_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv4i1.i32(<vscale x 4 x i1> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv4i1.i64(<vscale x 4 x i1> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b16_m(vbool16_t mask, vbool16_t op1, size_t vl) {
  return vfirst_m_b16_m(mask, op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b32_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv2i1.i32(<vscale x 2 x i1> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv2i1.i64(<vscale x 2 x i1> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b32_m(vbool32_t mask, vbool32_t op1, size_t vl) {
  return vfirst_m_b32_m(mask, op1, vl);
}

// CHECK-RV32-LABEL: @test_vfirst_m_b64_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.vfirst.mask.nxv1i1.i32(<vscale x 1 x i1> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret i32 [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfirst_m_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.vfirst.mask.nxv1i1.i64(<vscale x 1 x i1> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret i64 [[TMP0]]
//
long test_vfirst_m_b64_m(vbool64_t mask, vbool64_t op1, size_t vl) {
  return vfirst_m_b64_m(mask, op1, vl);
}