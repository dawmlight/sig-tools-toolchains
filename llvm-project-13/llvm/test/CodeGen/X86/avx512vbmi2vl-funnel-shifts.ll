; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=i686-unknown-unknown -mattr=+avx512vbmi2,+avx512vl | FileCheck %s --check-prefixes=CHECK,X86
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=+avx512vbmi2,+avx512vl -| FileCheck %s --check-prefixes=CHECK,X64

define <2 x i64> @avx512_funnel_shift_q_128(<2 x i64> %a0, <2 x i64> %a1) {
; X86-LABEL: avx512_funnel_shift_q_128:
; X86:       # %bb.0:
; X86-NEXT:    vpshldvq {{\.LCPI[0-9]+_[0-9]+}}, %xmm1, %xmm0
; X86-NEXT:    retl
;
; X64-LABEL: avx512_funnel_shift_q_128:
; X64:       # %bb.0:
; X64-NEXT:    vpshldvq {{.*}}(%rip), %xmm1, %xmm0
; X64-NEXT:    retq
  %1 =  shl <2 x i64> %a0, <i64 31, i64 33>
  %2 = lshr <2 x i64> %a1, <i64 33, i64 31>
  %3 = or <2 x i64> %1, %2
  ret <2 x i64> %3
}

define <4 x i64> @avx512_funnel_shift_q_256(<4 x i64> %a0, <4 x i64> %a1) {
; X86-LABEL: avx512_funnel_shift_q_256:
; X86:       # %bb.0:
; X86-NEXT:    vpshldvq {{\.LCPI[0-9]+_[0-9]+}}, %ymm1, %ymm0
; X86-NEXT:    retl
;
; X64-LABEL: avx512_funnel_shift_q_256:
; X64:       # %bb.0:
; X64-NEXT:    vpshldvq {{.*}}(%rip), %ymm1, %ymm0
; X64-NEXT:    retq
  %1 =  shl <4 x i64> %a0, <i64 31, i64 33, i64 31, i64 33>
  %2 = lshr <4 x i64> %a1, <i64 33, i64 31, i64 33, i64 31>
  %3 = or <4 x i64> %1, %2
  ret <4 x i64> %3
}

define <2 x i64> @avx512_funnel_shift_q_128_splat(<2 x i64> %a0, <2 x i64> %a1) {
; CHECK-LABEL: avx512_funnel_shift_q_128_splat:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpshldq $31, %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    ret{{[l|q]}}
  %1 =  shl <2 x i64> %a0, <i64 31, i64 31>
  %2 = lshr <2 x i64> %a1, <i64 33, i64 33>
  %3 = or <2 x i64> %1, %2
  ret <2 x i64> %3
}

define <4 x i64> @avx512_funnel_shift_q_256_splat(<4 x i64> %a0, <4 x i64> %a1) {
; CHECK-LABEL: avx512_funnel_shift_q_256_splat:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpshldq $31, %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %1 =  shl <4 x i64> %a0, <i64 31, i64 31, i64 31, i64 31>
  %2 = lshr <4 x i64> %a1, <i64 33, i64 33, i64 33, i64 33>
  %3 = or <4 x i64> %1, %2
  ret <4 x i64> %3
}

define <4 x i32> @avx512_funnel_shift_d_128(<4 x i32> %a0, <4 x i32> %a1) {
; X86-LABEL: avx512_funnel_shift_d_128:
; X86:       # %bb.0:
; X86-NEXT:    vpshldvd {{\.LCPI[0-9]+_[0-9]+}}, %xmm1, %xmm0
; X86-NEXT:    retl
;
; X64-LABEL: avx512_funnel_shift_d_128:
; X64:       # %bb.0:
; X64-NEXT:    vpshldvd {{.*}}(%rip), %xmm1, %xmm0
; X64-NEXT:    retq
  %1 =  shl <4 x i32> %a0, <i32 15, i32 17, i32 15, i32 17>
  %2 = lshr <4 x i32> %a1, <i32 17, i32 15, i32 17, i32 15>
  %3 = or <4 x i32> %1, %2
  ret <4 x i32> %3
}

define <8 x i32> @avx512_funnel_shift_d_256(<8 x i32> %a0, <8 x i32> %a1) {
; X86-LABEL: avx512_funnel_shift_d_256:
; X86:       # %bb.0:
; X86-NEXT:    vpshldvd {{\.LCPI[0-9]+_[0-9]+}}, %ymm1, %ymm0
; X86-NEXT:    retl
;
; X64-LABEL: avx512_funnel_shift_d_256:
; X64:       # %bb.0:
; X64-NEXT:    vpshldvd {{.*}}(%rip), %ymm1, %ymm0
; X64-NEXT:    retq
  %1 =  shl <8 x i32> %a0, <i32 15, i32 17, i32 15, i32 17, i32 15, i32 17, i32 15, i32 17>
  %2 = lshr <8 x i32> %a1, <i32 17, i32 15, i32 17, i32 15, i32 17, i32 15, i32 17, i32 15>
  %3 = or <8 x i32> %1, %2
  ret <8 x i32> %3
}

define <4 x i32> @avx512_funnel_shift_d_128_splat(<4 x i32> %a0, <4 x i32> %a1) {
; CHECK-LABEL: avx512_funnel_shift_d_128_splat:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpshldd $15, %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    ret{{[l|q]}}
  %1 =  shl <4 x i32> %a0, <i32 15, i32 15, i32 15, i32 15>
  %2 = lshr <4 x i32> %a1, <i32 17, i32 17, i32 17, i32 17>
  %3 = or <4 x i32> %1, %2
  ret <4 x i32> %3
}

define <8 x i32> @avx512_funnel_shift_d_256_splat(<8 x i32> %a0, <8 x i32> %a1) {
; CHECK-LABEL: avx512_funnel_shift_d_256_splat:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpshldd $15, %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %1 =  shl <8 x i32> %a0, <i32 15, i32 15, i32 15, i32 15, i32 15, i32 15, i32 15, i32 15>
  %2 = lshr <8 x i32> %a1, <i32 17, i32 17, i32 17, i32 17, i32 17, i32 17, i32 17, i32 17>
  %3 = or <8 x i32> %1, %2
  ret <8 x i32> %3
}

define <8 x i16> @avx512_funnel_shift_w_128(<8 x i16> %a0, <8 x i16> %a1) {
; X86-LABEL: avx512_funnel_shift_w_128:
; X86:       # %bb.0:
; X86-NEXT:    vpshldvw {{\.LCPI[0-9]+_[0-9]+}}, %xmm1, %xmm0
; X86-NEXT:    retl
;
; X64-LABEL: avx512_funnel_shift_w_128:
; X64:       # %bb.0:
; X64-NEXT:    vpshldvw {{.*}}(%rip), %xmm1, %xmm0
; X64-NEXT:    retq
  %1 =  shl <8 x i16> %a0, <i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9>
  %2 = lshr <8 x i16> %a1, <i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7>
  %3 = or <8 x i16> %1, %2
  ret <8 x i16> %3
}

define <16 x i16> @avx512_funnel_shift_w_256(<16 x i16> %a0, <16 x i16> %a1) {
; X86-LABEL: avx512_funnel_shift_w_256:
; X86:       # %bb.0:
; X86-NEXT:    vpshldvw {{\.LCPI[0-9]+_[0-9]+}}, %ymm1, %ymm0
; X86-NEXT:    retl
;
; X64-LABEL: avx512_funnel_shift_w_256:
; X64:       # %bb.0:
; X64-NEXT:    vpshldvw {{.*}}(%rip), %ymm1, %ymm0
; X64-NEXT:    retq
  %1 =  shl <16 x i16> %a0, <i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9>
  %2 = lshr <16 x i16> %a1, <i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7, i16 9, i16 7>
  %3 = or <16 x i16> %1, %2
  ret <16 x i16> %3
}

define <8 x i16> @avx512_funnel_shift_w_128_splat(<8 x i16> %a0, <8 x i16> %a1) {
; CHECK-LABEL: avx512_funnel_shift_w_128_splat:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpshldw $7, %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    ret{{[l|q]}}
  %1 =  shl <8 x i16> %a0, <i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7>
  %2 = lshr <8 x i16> %a1, <i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9>
  %3 = or <8 x i16> %1, %2
  ret <8 x i16> %3
}

define <16 x i16> @avx512_funnel_shift_w_256_splat(<16 x i16> %a0, <16 x i16> %a1) {
; CHECK-LABEL: avx512_funnel_shift_w_256_splat:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vpshldw $7, %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %1 =  shl <16 x i16> %a0, <i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7, i16 7>
  %2 = lshr <16 x i16> %a1, <i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9, i16 9>
  %3 = or <16 x i16> %1, %2
  ret <16 x i16> %3
}

