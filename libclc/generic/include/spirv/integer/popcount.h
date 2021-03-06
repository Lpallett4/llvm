//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#define __SPIRV_FUNCTION __spirv_ocl_popcount
#define __SPIRV_BODY <spirv/integer/unary.inc>
#include <spirv/integer/gentype.inc>
#undef __SPIRV_FUNCTION
#undef __SPIRV_BODY
