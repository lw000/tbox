/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2012, ruki All rights reserved.
 *
 * \author		ruki
 * \file		bits.h
 *
 */
#ifndef TB_UTILS_BITS_H
#define TB_UTILS_BITS_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

#if defined(TB_CONFIG_ARCH_x86)
# 	include "opt/bits_x86.h"
#elif defined(TB_CONFIG_ARCH_ARM)
# 	include "opt/bits_arm.h"
#elif defined(TB_CONFIG_ARCH_SH4)
# 	include "opt/bits_sh4.h"
#endif

/* ///////////////////////////////////////////////////////////////////////
 * macros
 */

// 1-bits
#define tb_bits_get_u1(p) 				(((*(p)) >> 7) & 1)
#define tb_bits_set_u1(p, x) 			do { *(p) &= 0x7f; *(p) |= (((x) & 0x1) << 7); } while (0)

// 8-bits
#define tb_bits_get_u8(p) 				(*(p))
#define tb_bits_get_s8(p) 				(*(p))

#define tb_bits_set_u8(p, x) 			do { *(p) = (x); } while (0)
#define tb_bits_set_s8(p, x) 			tb_bits_set_u8(p, x)

// 16-bits
#define tb_bits_get_u16_le_impl(p) 		(*((p) + 1) << 8 | *(p))
#define tb_bits_get_s16_le_impl(p) 		tb_bits_get_u16_le_impl(p)
#define tb_bits_get_u16_be_impl(p) 		(*((p)) << 8 | *((p) + 1))
#define tb_bits_get_s16_be_impl(p) 		tb_bits_get_u16_be_impl(p)
#define tb_bits_get_u16_ne_impl(p) 		(*((tb_uint16_t*)(p)))
#define tb_bits_get_s16_ne_impl(p) 		tb_bits_get_u16_ne_impl(p)

#define tb_bits_set_u16_le_impl(p, x) 	do { *(p) = (x) & 0xff; *((p) + 1) = ((x) >> 8) & 0xff; } while (0)
#define tb_bits_set_s16_le_impl(p, x) 	tb_bits_set_u16_le_impl(p, x)
#define tb_bits_set_u16_be_impl(p, x) 	do { *(p) = ((x) >> 8) & 0xff; *((p) + 1) = (x) & 0xff; } while (0)
#define tb_bits_set_s16_be_impl(p, x) 	tb_bits_set_u16_be_impl(p, x)
#define tb_bits_set_u16_ne_impl(p, x) 	do { *((tb_uint16_t*)(p)) = (tb_uint16_t)(x); } while (0)
#define tb_bits_set_s16_ne_impl(p, x) 	tb_bits_set_u16_ne_impl(p, x)

// 24-bits
#define tb_bits_get_u24_le_impl(p) 		(*((p) + 2) << 16 | *((p) + 1) << 8 | *(p))
#define tb_bits_get_s24_le_impl(p) 		((tb_bits_get_u24_le_impl(p) + 0xff800000) ^ 0xff800000)
#define tb_bits_get_u24_be_impl(p) 		(*(p) << 16 | *((p) + 1) << 8 | *((p) + 2))
#define tb_bits_get_s24_be_impl(p) 		((tb_bits_get_u24_be_impl(p) + 0xff800000) ^ 0xff800000)
#define tb_bits_get_u24_ne_impl(p) 		(*((tb_uint32_t*)(p)) & 0x00ffffff)
#define tb_bits_get_s24_ne_impl(p) 		((tb_bits_get_u24_ne_impl(p) + 0xff800000) ^ 0xff800000)

#define tb_bits_set_u24_le_impl(p, x) 	do { *(p) = (x) & 0xff; *((p) + 1) = ((x) >> 8) & 0xff; *((p) + 2) = ((x) >> 16) & 0xff;} while (0)
#define tb_bits_set_s24_le_impl(p, x) 	tb_bits_set_u24_le_impl(p, x)
#define tb_bits_set_u24_be_impl(p, x) 	do { *(p) = ((x) >> 16) & 0xff; *((p) + 1) = ((x) >> 8) & 0xff; *((p) + 2) = (x) & 0xff; } while (0)
#define tb_bits_set_s24_be_impl(p, x) 	tb_bits_set_u24_be_impl(p, x)
#define tb_bits_set_u24_ne_impl(p, x) 	do { *((tb_uint32_t*)(p)) = (tb_uint32_t)(x) & 0x00ffffff; } while (0)
#define tb_bits_set_s24_ne_impl(p, x) 	tb_bits_set_u24_ne_impl(p, x)

// 32-bits
#define tb_bits_get_u32_le_impl(p) 		(*((p) + 3) << 24 | *((p) + 2) << 16 | *((p) + 1) << 8 | *(p))
#define tb_bits_get_s32_le_impl(p) 		tb_bits_get_u32_le_impl(p)
#define tb_bits_get_u32_be_impl(p) 		(*(p) << 24 | *((p) + 1) << 16 | *((p) + 2) << 8 | *((p) + 3))
#define tb_bits_get_s32_be_impl(p) 		tb_bits_get_u32_be_impl(p)
#define tb_bits_get_u32_ne_impl(p) 		(*((tb_uint32_t*)(p)))
#define tb_bits_get_s32_ne_impl(p) 		tb_bits_get_u32_ne_impl(p)

#define tb_bits_set_u32_le_impl(p, x) 	do { *(p) = (x) & 0xff; *((p) + 1) = ((x) >> 8) & 0xff; *((p) + 2) = ((x) >> 16) & 0xff; *((p) + 3) = ((x) >> 24) & 0xff;} while (0)
#define tb_bits_set_s32_le_impl(p, x) 	tb_bits_set_u32_le_impl(p, x)
#define tb_bits_set_u32_be_impl(p, x) 	do { *(p) = ((x) >> 24) & 0xff; *((p) + 1) = ((x) >> 16) & 0xff; *((p) + 2) = ((x) >> 8) & 0xff; *((p) + 3) = (x) & 0xff; } while (0)
#define tb_bits_set_s32_be_impl(p, x) 	tb_bits_set_u32_be_impl(p, x)
#define tb_bits_set_u32_ne_impl(p, x) 	do { *((tb_uint32_t*)(p)) = (tb_uint32_t)(x); } while (0)
#define tb_bits_set_s32_ne_impl(p, x) 	tb_bits_set_u32_ne_impl(p, x)

// float
#ifdef TB_CONFIG_TYPE_FLOAT

# 	define tb_bits_get_float_le(p) 			tb_bits_get_float_le_inline(p)
# 	define tb_bits_get_float_be(p) 			tb_bits_get_float_be_inline(p)
# 	define tb_bits_get_float_ne(p) 			tb_bits_get_float_ne_inline(p)

# 	define tb_bits_set_float_le(p, x) 		tb_bits_set_float_le_inline(p, x)
# 	define tb_bits_set_float_be(p, x) 		tb_bits_set_float_be_inline(p, x)
# 	define tb_bits_set_float_ne(p, x) 		tb_bits_set_float_ne_inline(p, x)

# 	define tb_bits_get_double_ble(p) 		tb_bits_get_double_ble_inline(p)
# 	define tb_bits_get_double_bbe(p) 		tb_bits_get_double_bbe_inline(p)
# 	define tb_bits_get_double_bne(p) 		tb_bits_get_double_bne_inline(p)

# 	define tb_bits_get_double_lle(p) 		tb_bits_get_double_lle_inline(p)
# 	define tb_bits_get_double_lbe(p) 		tb_bits_get_double_lbe_inline(p)
# 	define tb_bits_get_double_lne(p) 		tb_bits_get_double_lne_inline(p)

# 	define tb_bits_get_double_nle(p) 		tb_bits_get_double_nle_inline(p)
# 	define tb_bits_get_double_nbe(p) 		tb_bits_get_double_nbe_inline(p)
# 	define tb_bits_get_double_nne(p) 		tb_bits_get_double_nne_inline(p)

# 	define tb_bits_set_double_ble(p, x) 	tb_bits_set_double_ble_inline(p, x)
# 	define tb_bits_set_double_bbe(p, x) 	tb_bits_set_double_bbe_inline(p, x)
# 	define tb_bits_set_double_bne(p, x) 	tb_bits_set_double_bne_inline(p, x)

# 	define tb_bits_set_double_lle(p, x) 	tb_bits_set_double_lle_inline(p, x)
# 	define tb_bits_set_double_lbe(p, x) 	tb_bits_set_double_lbe_inline(p, x)
# 	define tb_bits_set_double_lne(p, x) 	tb_bits_set_double_lne_inline(p, x)

# 	define tb_bits_set_double_nle(p, x) 	tb_bits_set_double_nle_inline(p, x)
# 	define tb_bits_set_double_nbe(p, x) 	tb_bits_set_double_nbe_inline(p, x)
# 	define tb_bits_set_double_nne(p, x) 	tb_bits_set_double_nne_inline(p, x)

#endif

#ifdef TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE

# 	ifdef TB_WORDS_BIGENDIAN
// 16-bits
# 	define tb_bits_get_u16_le(p) 		tb_bits_get_u16_le_impl(p)
# 	define tb_bits_get_s16_le(p) 		tb_bits_get_s16_le_impl(p)
# 	define tb_bits_get_u16_be(p) 		tb_bits_get_u16_ne_impl(p)
# 	define tb_bits_get_s16_be(p) 		tb_bits_get_s16_ne_impl(p)

# 	define tb_bits_set_u16_le(p, x) 	tb_bits_set_u16_le_impl(p, x)
# 	define tb_bits_set_s16_le(p, x) 	tb_bits_set_s16_le_impl(p, x)
# 	define tb_bits_set_u16_be(p, x) 	tb_bits_set_u16_ne_impl(p, x)
# 	define tb_bits_set_s16_be(p, x) 	tb_bits_set_s16_ne_impl(p, x)

// 24-bits
# 	define tb_bits_get_u24_le(p) 		tb_bits_get_u24_le_impl(p)
# 	define tb_bits_get_s24_le(p) 		tb_bits_get_s24_le_impl(p)
# 	define tb_bits_get_u24_be(p) 		tb_bits_get_u24_ne_impl(p)
# 	define tb_bits_get_s24_be(p) 		tb_bits_get_s24_ne_impl(p)

# 	define tb_bits_set_u24_le(p, x) 	tb_bits_set_u24_le_impl(p, x)
# 	define tb_bits_set_s24_le(p, x) 	tb_bits_set_s24_le_impl(p, x)
# 	define tb_bits_set_u24_be(p, x) 	tb_bits_set_u24_ne_impl(p, x)
# 	define tb_bits_set_s24_be(p, x) 	tb_bits_set_s24_ne_impl(p, x)

// 32-bits
# 	define tb_bits_get_u32_le(p) 		tb_bits_get_u32_le_impl(p)
# 	define tb_bits_get_s32_le(p) 		tb_bits_get_s32_le_impl(p)
# 	define tb_bits_get_u32_be(p) 		tb_bits_get_u32_ne_impl(p)
# 	define tb_bits_get_s32_be(p) 		tb_bits_get_s32_ne_impl(p)

# 	define tb_bits_set_u32_le(p, x) 	tb_bits_set_u32_le_impl(p, x)
# 	define tb_bits_set_s32_le(p, x) 	tb_bits_set_u32_le_impl(p, x)
# 	define tb_bits_set_u32_be(p, x) 	tb_bits_set_u32_ne_impl(p, x)
# 	define tb_bits_set_s32_be(p, x) 	tb_bits_set_s32_ne_impl(p, x)

# 	else

// 16-bits
# 	define tb_bits_get_u16_le(p) 		tb_bits_get_u16_ne_impl(p)
# 	define tb_bits_get_s16_le(p) 		tb_bits_get_s16_ne_impl(p)
# 	define tb_bits_get_u16_be(p) 		tb_bits_get_u16_be_impl(p)
# 	define tb_bits_get_s16_be(p) 		tb_bits_get_s16_be_impl(p)

# 	define tb_bits_set_u16_le(p, x) 	tb_bits_set_u16_ne_impl(p, x)
# 	define tb_bits_set_s16_le(p, x) 	tb_bits_set_s16_ne_impl(p, x)
# 	define tb_bits_set_u16_be(p, x) 	tb_bits_set_u16_be_impl(p, x)
# 	define tb_bits_set_s16_be(p, x) 	tb_bits_set_s16_be_impl(p, x)

// 24-bits
# 	define tb_bits_get_u24_le(p) 		tb_bits_get_u24_ne_impl(p)
# 	define tb_bits_get_s24_le(p) 		tb_bits_get_s24_ne_impl(p)
# 	define tb_bits_get_u24_be(p) 		tb_bits_get_u24_be_impl(p)
# 	define tb_bits_get_s24_be(p) 		tb_bits_get_s24_be_impl(p)

# 	define tb_bits_set_u24_le(p, x) 	tb_bits_set_u24_ne_impl(p, x)
# 	define tb_bits_set_s24_le(p, x) 	tb_bits_set_s24_ne_impl(p, x)
# 	define tb_bits_set_u24_be(p, x) 	tb_bits_set_u24_be_impl(p, x)
# 	define tb_bits_set_s24_be(p, x) 	tb_bits_set_s24_be_impl(p, x)

// 32-bits
# 	define tb_bits_get_u32_le(p) 		tb_bits_get_u32_ne_impl(p)
# 	define tb_bits_get_s32_le(p) 		tb_bits_get_s32_ne_impl(p)
# 	define tb_bits_get_u32_be(p) 		tb_bits_get_u32_be_impl(p)
# 	define tb_bits_get_s32_be(p) 		tb_bits_get_s32_be_impl(p)

# 	define tb_bits_set_u32_le(p, x) 	tb_bits_set_u32_le_impl(p, x)
# 	define tb_bits_set_s32_le(p, x) 	tb_bits_set_u32_le_impl(p, x)
# 	define tb_bits_set_u32_be(p, x) 	tb_bits_set_u32_be_impl(p, x)
# 	define tb_bits_set_s32_be(p, x) 	tb_bits_set_s32_be_impl(p, x)

# 	endif /* TB_WORDS_BIGENDIAN */

#else
// 16-bits
# 	define tb_bits_get_u16_le(p) 		tb_bits_get_u16_le_impl(p)
# 	define tb_bits_get_s16_le(p) 		tb_bits_get_s16_le_impl(p)
# 	define tb_bits_get_u16_be(p) 		tb_bits_get_u16_be_impl(p)
# 	define tb_bits_get_s16_be(p) 		tb_bits_get_s16_be_impl(p)

# 	define tb_bits_set_u16_le(p, x) 	tb_bits_set_u16_le_impl(p, x)
# 	define tb_bits_set_s16_le(p, x) 	tb_bits_set_s16_le_impl(p, x)
# 	define tb_bits_set_u16_be(p, x) 	tb_bits_set_u16_be_impl(p, x)
# 	define tb_bits_set_s16_be(p, x) 	tb_bits_set_s16_be_impl(p, x)

// 24-bits
# 	define tb_bits_get_u24_le(p) 		tb_bits_get_u24_le_impl(p)
# 	define tb_bits_get_s24_le(p) 		tb_bits_get_s24_le_impl(p)
# 	define tb_bits_get_u24_be(p) 		tb_bits_get_u24_be_impl(p)
# 	define tb_bits_get_s24_be(p) 		tb_bits_get_s24_be_impl(p)

# 	define tb_bits_set_u24_le(p, x) 	tb_bits_set_u24_le_impl(p, x)
# 	define tb_bits_set_s24_le(p, x) 	tb_bits_set_s24_le_impl(p, x)
# 	define tb_bits_set_u24_be(p, x) 	tb_bits_set_u24_be_impl(p, x)
# 	define tb_bits_set_s24_be(p, x) 	tb_bits_set_s24_be_impl(p, x)

// 32-bits
# 	define tb_bits_get_u32_le(p) 		tb_bits_get_u32_le_impl(p)
# 	define tb_bits_get_s32_le(p) 		tb_bits_get_s32_le_impl(p)
# 	define tb_bits_get_u32_be(p) 		tb_bits_get_u32_be_impl(p)
# 	define tb_bits_get_s32_be(p) 		tb_bits_get_s32_be_impl(p)

# 	define tb_bits_set_u32_le(p, x) 	tb_bits_set_u32_le_impl(p, x)
# 	define tb_bits_set_s32_le(p, x) 	tb_bits_set_u32_le_impl(p, x)
# 	define tb_bits_set_u32_be(p, x) 	tb_bits_set_u32_be_impl(p, x)
# 	define tb_bits_set_s32_be(p, x) 	tb_bits_set_s32_be_impl(p, x)

#endif /* TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE */

#ifdef TB_WORDS_BIGENDIAN
# 	define tb_bits_get_u16_ne(p) 		tb_bits_get_u16_be(p)
# 	define tb_bits_get_s16_ne(p) 		tb_bits_get_s16_be(p)
# 	define tb_bits_get_u24_ne(p) 		tb_bits_get_u24_be(p)
# 	define tb_bits_get_s24_ne(p) 		tb_bits_get_s24_be(p)
# 	define tb_bits_get_u32_ne(p) 		tb_bits_get_u32_be(p)
# 	define tb_bits_get_s32_ne(p) 		tb_bits_get_s32_be(p)

# 	define tb_bits_set_u16_ne(p, x) 	tb_bits_set_u16_be(p, x)
# 	define tb_bits_set_s16_ne(p, x)		tb_bits_set_s16_be(p, x)
# 	define tb_bits_set_u24_ne(p, x) 	tb_bits_set_u24_be(p, x)
# 	define tb_bits_set_s24_ne(p, x)		tb_bits_set_s24_be(p, x)
# 	define tb_bits_set_u32_ne(p, x)		tb_bits_set_u32_be(p, x)
# 	define tb_bits_set_s32_ne(p, x) 	tb_bits_set_s32_be(p, x)

#else
# 	define tb_bits_get_u16_ne(p) 		tb_bits_get_u16_le(p)
# 	define tb_bits_get_s16_ne(p) 		tb_bits_get_s16_le(p)
# 	define tb_bits_get_u24_ne(p) 		tb_bits_get_u24_le(p)
# 	define tb_bits_get_s24_ne(p) 		tb_bits_get_s24_le(p)
# 	define tb_bits_get_u32_ne(p) 		tb_bits_get_u32_le(p)
# 	define tb_bits_get_s32_ne(p) 		tb_bits_get_s32_le(p)

# 	define tb_bits_set_u16_ne(p, x) 	tb_bits_set_u16_le(p, x)
# 	define tb_bits_set_s16_ne(p, x)		tb_bits_set_s16_le(p, x)
# 	define tb_bits_set_u24_ne(p, x) 	tb_bits_set_u24_le(p, x)
# 	define tb_bits_set_s24_ne(p, x)		tb_bits_set_s24_le(p, x)
# 	define tb_bits_set_u32_ne(p, x)		tb_bits_set_u32_le(p, x)
# 	define tb_bits_set_s32_ne(p, x) 	tb_bits_set_s32_le(p, x)

#endif /* TB_WORDS_BIGENDIAN */

// swap
#ifndef tb_bits_swap_u16
# 	define tb_bits_swap_u16(x) 			tb_bits_swap_u16_inline(x)
#endif

#ifndef tb_bits_swap_u32
# 	define tb_bits_swap_u32(x) 			tb_bits_swap_u32_inline(x)
#endif

#ifndef tb_bits_swap_u64
# 	define tb_bits_swap_u64(x) 			tb_bits_swap_u64_inline(x)
#endif

#ifdef TB_WORDS_BIGENDIAN
# 	define tb_bits_be_to_ne_u16(x) 		(x)
# 	define tb_bits_le_to_ne_u16(x) 		tb_bits_swap_u16(x)
# 	define tb_bits_be_to_ne_u32(x) 		(x)
# 	define tb_bits_le_to_ne_u32(x) 		tb_bits_swap_u32(x)
# 	define tb_bits_be_to_ne_u64(x) 		(x)
# 	define tb_bits_le_to_ne_u64(x) 		tb_bits_swap_u64(x)
#else
# 	define tb_bits_be_to_ne_u16(x) 		tb_bits_swap_u16(x)
# 	define tb_bits_le_to_ne_u16(x) 		(x)
# 	define tb_bits_be_to_ne_u32(x) 		tb_bits_swap_u32(x)
# 	define tb_bits_le_to_ne_u32(x) 		(x)
# 	define tb_bits_be_to_ne_u64(x) 		tb_bits_swap_u64(x)
# 	define tb_bits_le_to_ne_u64(x) 		(x)
#endif

#define tb_bits_ne_to_be_u16(x) 		tb_bits_be_to_ne_u16(x)
#define tb_bits_ne_to_le_u16(x) 		tb_bits_le_to_ne_u16(x)
#define tb_bits_ne_to_be_u32(x) 		tb_bits_be_to_ne_u32(x)
#define tb_bits_ne_to_le_u32(x) 		tb_bits_le_to_ne_u32(x)
#define tb_bits_ne_to_be_u64(x) 		tb_bits_be_to_ne_u64(x)
#define tb_bits_ne_to_le_u64(x) 		tb_bits_le_to_ne_u64(x)

// cl0, count leading bit 0
#ifdef TB_COMPILER_IS_GCC
# 	define tb_bits_cl0_u32_be(x) 		((x)? (tb_size_t)__builtin_clz((tb_uint32_t)(x)) : 32)
# 	define tb_bits_cl0_u32_le(x) 		((x)? (tb_size_t)__builtin_ctz((tb_uint32_t)(x)) : 32)
# 	if TB_CPU_BITSIZE == 64
# 		define tb_bits_cl0_u64_be(x) 	((x)? (tb_size_t)__builtin_clzl((tb_uint64_t)(x)) : 64)
# 		define tb_bits_cl0_u64_le(x) 	((x)? (tb_size_t)__builtin_ctzl((tb_uint64_t)(x)) : 64)
# 	endif
#endif

#ifndef tb_bits_cl0_u32_be 
# 	define tb_bits_cl0_u32_be(x) 		tb_bits_cl0_u32_be_inline(x)
#endif
#ifndef tb_bits_cl0_u32_le
# 	define tb_bits_cl0_u32_le(x) 		tb_bits_cl0_u32_le_inline(x)
#endif
#ifndef tb_bits_cl0_u64_be
# 	define tb_bits_cl0_u64_be(x) 		tb_bits_cl0_u64_be_inline(x)
#endif
#ifndef tb_bits_cl0_u64_le
# 	define tb_bits_cl0_u64_le(x) 		tb_bits_cl0_u64_le_inline(x)
#endif

// cl1, count leading bit 1
#ifndef tb_bits_cl1_u32_be 
# 	define tb_bits_cl1_u32_be(x) 		tb_bits_cl0_u32_be(~(tb_uint32_t)(x))
#endif
#ifndef tb_bits_cl1_u32_le
# 	define tb_bits_cl1_u32_le(x) 		tb_bits_cl0_u32_le(~(tb_uint32_t)(x))
#endif
#ifndef tb_bits_cl1_u64_be
# 	define tb_bits_cl1_u64_be(x) 		tb_bits_cl0_u64_be(~(tb_uint64_t)(x))
#endif
#ifndef tb_bits_cl1_u64_le
# 	define tb_bits_cl1_u64_le(x) 		tb_bits_cl0_u64_le(~(tb_uint64_t)(x))
#endif

// cb1, count bit 1
#ifdef TB_COMPILER_IS_GCC
# 	define tb_bits_cb1_u32(x) 			((x)? (tb_size_t)__builtin_popcount((tb_uint32_t)(x)) : 0)
# 	if TB_CPU_BITSIZE == 64
# 	define tb_bits_cb1_u64(x) 			((x)? (tb_size_t)__builtin_popcountl((tb_uint64_t)(x)) : 0)
# 	endif
#endif

#ifndef tb_bits_cb1_u32
# 	define tb_bits_cb1_u32(x) 			tb_bits_cb1_u32_inline(x)
#endif
#ifndef tb_bits_cb1_u64
# 	define tb_bits_cb1_u64(x) 			tb_bits_cb1_u64_inline(x)
#endif

// cb0, count bit 0
#ifndef tb_bits_cb0_u32
# 	define tb_bits_cb0_u32(x) 			((x)? (tb_size_t)tb_bits_cb1_u32(~(tb_uint32_t)(x)) : 32)
#endif
#ifndef tb_bits_cb0_u64
# 	define tb_bits_cb0_u64(x) 			((x)? (tb_size_t)tb_bits_cb1_u64(~(tb_uint64_t)(x)) : 64)
#endif

/* fb0, find the first bit 0
 * 
 * find bit zero by little endian, fb0(...11101101) == 1
 * find bit zero by big endian, fb0(...11101101) == 27
 */
#ifndef tb_bits_fb0_u32_be 
# 	define tb_bits_fb0_u32_be(x) 		((x)? tb_bits_cl0_u32_be(~(tb_uint32_t)(x)) : 0)
#endif
#ifndef tb_bits_fb0_u32_le
# 	define tb_bits_fb0_u32_le(x) 		((x)? tb_bits_cl0_u32_le(~(tb_uint32_t)(x)) : 0)
#endif
#ifndef tb_bits_fb0_u64_be 
# 	define tb_bits_fb0_u64_be(x) 		((x)? tb_bits_cl0_u64_be(~(tb_uint64_t)(x)) : 0)
#endif
#ifndef tb_bits_fb0_u64_le
# 	define tb_bits_fb0_u64_le(x) 		((x)? tb_bits_cl0_u64_le(~(tb_uint64_t)(x)) : 0)
#endif

// fb1, find the first bit 0
#ifdef TB_COMPILER_IS_GCC
# 	define tb_bits_fb1_u32_le(x) 		((x)? (tb_size_t)__builtin_ffs((tb_uint32_t)(x)) - 1 : 32)
# 	if TB_CPU_BITSIZE == 64
# 	define tb_bits_fb1_u64_le(x) 		((x)? (tb_size_t)__builtin_ffs((tb_uint64_t)(x)) - 1 : 64)
# 	endif
#endif

#ifndef tb_bits_fb1_u32_be 
# 	define tb_bits_fb1_u32_be(x) 		((x)? tb_bits_cl0_u32_be(x) : 32)
#endif
#ifndef tb_bits_fb1_u32_le
# 	define tb_bits_fb1_u32_le(x) 		((x)? tb_bits_cl0_u32_le(x) : 32)
#endif
#ifndef tb_bits_fb1_u64_be 
# 	define tb_bits_fb1_u64_be(x) 		((x)? tb_bits_cl0_u64_be(x) : 64)
#endif
#ifndef tb_bits_fb1_u64_le
# 	define tb_bits_fb1_u64_le(x) 		((x)? tb_bits_cl0_u64_le(x) : 64)
#endif

/* ///////////////////////////////////////////////////////////////////////
 * interfaces
 */

tb_uint32_t tb_bits_get_ubits32(tb_byte_t const* p, tb_size_t b, tb_size_t n);
tb_sint32_t tb_bits_get_sbits32(tb_byte_t const* p, tb_size_t b, tb_size_t n);

tb_void_t 	tb_bits_set_ubits32(tb_byte_t* p, tb_size_t b, tb_uint32_t x, tb_size_t n);
tb_void_t 	tb_bits_set_sbits32(tb_byte_t* p, tb_size_t b, tb_sint32_t x, tb_size_t n);

/* ///////////////////////////////////////////////////////////////////////
 * swap
 */

// swap
static __tb_inline__ tb_uint16_t const tb_bits_swap_u16_inline(tb_uint16_t x)
{
    x = (x >> 8) | (x << 8);
    return x;
}
static __tb_inline__ tb_uint32_t const tb_bits_swap_u32_inline(tb_uint32_t x)
{
    x = ((x << 8) & 0xff00ff00) | ((x >> 8) & 0x00ff00ff);
    x = (x >> 16) | (x << 16);
    return x;
}
static __tb_inline__ tb_hize_t const tb_bits_swap_u64_inline(tb_hize_t x)
{
	union 
	{
		tb_hize_t u64;
		tb_uint32_t u32[2];

	} w, r;

	w.u64 = x;

	r.u32[0] = tb_bits_swap_u32(w.u32[1]);
	r.u32[1] = tb_bits_swap_u32(w.u32[0]);

	return r.u64;
}

/* ///////////////////////////////////////////////////////////////////////
 * cl0
 */
static __tb_inline__ tb_size_t tb_bits_cl0_u32_be_inline(tb_uint32_t x)
{
    tb_check_return_val(x, 32);

	tb_size_t n = 31;
	if (x & 0xffff0000) { n -= 16; 	x >>= 16; 	}
	if (x & 0xff00) 	{ n -= 8; 	x >>= 8; 	}
	if (x & 0xf0) 		{ n -= 4; 	x >>= 4; 	}
	if (x & 0xc) 		{ n -= 2; 	x >>= 2; 	}
	if (x & 0x2) 		{ n--; 					}

    return n;
}
static __tb_inline__ tb_size_t tb_bits_cl0_u32_le_inline(tb_uint32_t x)
{
    tb_check_return_val(x, 32);

	tb_size_t n = 31;
	if (x & 0x0000ffff) { n -= 16; 	} else x >>= 16;
	if (x & 0x00ff) 	{ n -= 8; 	} else x >>= 8;
	if (x & 0x0f) 		{ n -= 4; 	} else x >>= 4;
	if (x & 0x3) 		{ n -= 2; 	} else x >>= 2;
	if (x & 0x1) 		{ n--; 		}

    return n;
}
static __tb_inline__ tb_size_t tb_bits_cl0_u64_be_inline(tb_uint64_t x)
{
    tb_check_return_val(x, 64);

	tb_size_t n = tb_bits_cl0_u32_be((tb_uint32_t)(x >> 32));
	if (n == 32) n += tb_bits_cl0_u32_be((tb_uint32_t)x);

    return n;
}
static __tb_inline__ tb_size_t tb_bits_cl0_u64_le_inline(tb_uint64_t x)
{
    tb_check_return_val(x, 64);

	tb_size_t n = tb_bits_cl0_u32_le((tb_uint32_t)x);
	if (n == 32) n += tb_bits_cl0_u32_le((tb_uint32_t)(x >> 32));

    return n;
}

/* ///////////////////////////////////////////////////////////////////////
 * cb1
 */
static __tb_inline__ tb_size_t tb_bits_cb1_u32_inline(tb_uint32_t x)
{
    tb_check_return_val(x, 0);

#if 0
	/* 
	 * 0x55555555 = 01010101010101010101010101010101 
	 * 0x33333333 = 00110011001100110011001100110011 
	 * 0x0f0f0f0f = 00001111000011110000111100001111 
	 * 0x00ff00ff = 00000000111111110000000011111111 
	 * 0x0000ffff = 00000000000000001111111111111111 
	 */  

	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);  
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);  
	x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);  
	x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);  
	x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff); 
#elif 0
	// mit hackmem count
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f;
	x = x + (x >> 8);
	x = x + (x >> 16);
	x &= 0x7f;
#elif 0
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4) & 0x0f0f0f0f);
	x = (x * 0x01010101) >> 24;
#elif 0
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4) & 0x0f0f0f0f) % 255;
#else
	x = x - ((x >> 1) & 0x77777777) - ((x >> 2) & 0x33333333) - ((x >> 3) & 0x11111111);
	x = (x + (x >> 4) & 0x0f0f0f0f);
	x = (x * 0x01010101) >> 24;
#endif

    return x;
}
static __tb_inline__ tb_size_t tb_bits_cb1_u64_inline(tb_uint64_t x)
{
    tb_check_return_val(x, 0);

#if 0
	x = x - ((x >> 1) & 0x5555555555555555L);
	x = (x & 0x3333333333333333L) + ((x >> 2) & 0x3333333333333333L);
	x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fL;
	x = x + (x >> 8);
	x = x + (x >> 16);
	x = x + (x >> 32);
	x &= 0x7f;
#else
	x = x - ((x >> 1) & 0x7777777777777777L) - ((x >> 2) & 0x3333333333333333L) - ((x >> 3) & 0x1111111111111111L);
	x = (x + (x >> 4) & 0x0f0f0f0f0f0f0f0fL);
	x = (x * 0x0101010101010101L) >> 56;
#endif

    return x;
}

#ifdef TB_CONFIG_TYPE_FLOAT
/* ///////////////////////////////////////////////////////////////////////
 * get float
 */
static __tb_inline__ tb_float_t tb_bits_get_float_le_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
	&& !defined(TB_WORDS_BIGENDIAN)
	return *((float*)p);
#else
	union 
	{
		tb_uint32_t i;
		float 		f;

	} conv;

	conv.i = tb_bits_get_u32_le(p);
	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_float_be_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
	&& defined(TB_WORDS_BIGENDIAN)
	return *((float*)p);
#else
	union 
	{
		tb_uint32_t i;
		float 		f;

	} conv;

	conv.i = tb_bits_get_u32_be(p);
	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_float_ne_inline(tb_byte_t const* p)
{
#ifdef TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE
	return *((float*)p);
#else
	union 
	{
		tb_uint32_t i;
		float 		f;

	} conv;

	conv.i = tb_bits_get_u32_ne(p);
	return (tb_float_t)conv.f;
#endif
}

/* ///////////////////////////////////////////////////////////////////////
 * set float
 */

static __tb_inline__ tb_void_t tb_bits_set_float_le_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
	&& !defined(TB_WORDS_BIGENDIAN)
	*((float*)p) = x;
#else
	union 
	{
		tb_uint32_t i;
		float 		f;

	} conv;

	conv.f = (float)x;
	tb_bits_set_u32_le(p, conv.i);
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_float_be_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
	&& defined(TB_WORDS_BIGENDIAN)
	*((float*)p) = x;
#else
	union 
	{
		tb_uint32_t i;
		float 		f;

	} conv;

	conv.f = (float)x;
	tb_bits_set_u32_be(p, conv.i);
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_float_ne_inline(tb_byte_t* p, tb_float_t x)
{
#ifdef TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE
	*((float*)p) = x;
#else
	union 
	{
		tb_uint32_t i;
		float 		f;

	} conv;

	conv.f = (float)x;
	tb_bits_set_u32_ne(p, conv.i);
#endif
}


/* ///////////////////////////////////////////////////////////////////////
 * get double
 */
static __tb_inline__ tb_float_t tb_bits_get_double_bbe_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_FLOAT_BIGENDIAN) \
			&& defined(TB_WORDS_BIGENDIAN)
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

	conv.i[1] = tb_bits_get_u32_be(p);
	conv.i[0] = tb_bits_get_u32_be(p + 4);

	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_double_ble_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_FLOAT_BIGENDIAN) \
			&& !defined(TB_WORDS_BIGENDIAN)
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;


	conv.i[1] = tb_bits_get_u32_le(p);
	conv.i[0] = tb_bits_get_u32_le(p + 4);

	return (tb_float_t)conv.f;
#endif
}

static __tb_inline__ tb_float_t tb_bits_get_double_bne_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_FLOAT_BIGENDIAN) 
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;


	conv.i[1] = tb_bits_get_u32_ne(p);
	conv.i[0] = tb_bits_get_u32_ne(p + 4);

	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_double_lbe_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_FLOAT_BIGENDIAN) \
			&& defined(TB_WORDS_BIGENDIAN)
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

	conv.i[0] = tb_bits_get_u32_be(p);
	conv.i[1] = tb_bits_get_u32_be(p + 4);

	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_double_lle_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_FLOAT_BIGENDIAN) \
			&& !defined(TB_WORDS_BIGENDIAN)
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

	conv.i[0] = tb_bits_get_u32_le(p);
	conv.i[1] = tb_bits_get_u32_le(p + 4);
	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_double_lne_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_FLOAT_BIGENDIAN) 
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

	conv.i[0] = tb_bits_get_u32_ne(p);
	conv.i[1] = tb_bits_get_u32_ne(p + 4);
	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_double_nbe_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_WORDS_BIGENDIAN) 
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

#ifdef TB_FLOAT_BIGENDIAN
	conv.i[1] = tb_bits_get_u32_be(p);
	conv.i[0] = tb_bits_get_u32_be(p + 4);
#else
	conv.i[0] = tb_bits_get_u32_be(p);
	conv.i[1] = tb_bits_get_u32_be(p + 4);
#endif
	return (tb_float_t)conv.f;
#endif
}
static __tb_inline__ tb_float_t tb_bits_get_double_nle_inline(tb_byte_t const* p)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_WORDS_BIGENDIAN)
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

#ifdef TB_FLOAT_BIGENDIAN
	conv.i[1] = tb_bits_get_u32_le(p);
	conv.i[0] = tb_bits_get_u32_le(p + 4);
#else
	conv.i[0] = tb_bits_get_u32_le(p);
	conv.i[1] = tb_bits_get_u32_le(p + 4);
#endif
	return (tb_float_t)conv.f;
#endif
}

static __tb_inline__ tb_float_t tb_bits_get_double_nne_inline(tb_byte_t const* p)
{
#ifdef TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE
	return *((double*)p);
#else
	union 
	{
		tb_uint32_t i[2];
		double 		f;

	} conv;

#ifdef TB_FLOAT_BIGENDIAN
	conv.i[1] = tb_bits_get_u32_ne(p);
	conv.i[0] = tb_bits_get_u32_ne(p + 4);
#else
	conv.i[0] = tb_bits_get_u32_ne(p);
	conv.i[1] = tb_bits_get_u32_ne(p + 4);
#endif
	return (tb_float_t)conv.f;
#endif
}

/* ///////////////////////////////////////////////////////////////////////
 * set double
 */

// big float endian & big words endian
// 7 6 5 4 3 2 1 0
static __tb_inline__ tb_void_t tb_bits_set_double_bbe_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_FLOAT_BIGENDIAN) \
			&& defined(TB_WORDS_BIGENDIAN)
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

	tb_bits_set_u32_be(p, 		conv.i[1]);
	tb_bits_set_u32_be(p + 4, 	conv.i[0]);
#endif
}
// big float endian & litte words endian
// 4 5 6 7 0 1 2 3
static __tb_inline__ tb_void_t tb_bits_set_double_ble_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_FLOAT_BIGENDIAN) \
			&& !defined(TB_WORDS_BIGENDIAN)
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

	tb_bits_set_u32_le(p, 		conv.i[1]);
	tb_bits_set_u32_le(p + 4, 	conv.i[0]);
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_double_bne_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_FLOAT_BIGENDIAN) 
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

	tb_bits_set_u32_ne(p, 		conv.i[1]);
	tb_bits_set_u32_ne(p + 4, 	conv.i[0]);
#endif
}
// litte float endian & big words endian
// 3 2 1 0 7 6 5 4
static __tb_inline__ tb_void_t tb_bits_set_double_lbe_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_FLOAT_BIGENDIAN) \
			&& defined(TB_WORDS_BIGENDIAN)
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

	tb_bits_set_u32_be(p, 		conv.i[0]);
	tb_bits_set_u32_be(p + 4, 	conv.i[1]);
#endif
}
// litte float endian & litte words endian
// 0 1 2 3 4 5 6 7
static __tb_inline__ tb_void_t tb_bits_set_double_lle_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_FLOAT_BIGENDIAN) \
			&& !defined(TB_WORDS_BIGENDIAN)
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

	tb_bits_set_u32_le(p, 		conv.i[0]);
	tb_bits_set_u32_le(p + 4, 	conv.i[1]);
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_double_lne_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_FLOAT_BIGENDIAN) 
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

	tb_bits_set_u32_ne(p, 		conv.i[0]);
	tb_bits_set_u32_ne(p + 4, 	conv.i[1]);
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_double_nbe_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& defined(TB_WORDS_BIGENDIAN)
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

#ifdef TB_FLOAT_BIGENDIAN
	tb_bits_set_u32_be(p, 		conv.i[1]);
	tb_bits_set_u32_be(p + 4, 	conv.i[0]);
#else
	tb_bits_set_u32_be(p, 		conv.i[0]);
	tb_bits_set_u32_be(p + 4, 	conv.i[1]);
#endif
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_double_nle_inline(tb_byte_t* p, tb_float_t x)
{
#if defined(TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE) \
		&& !defined(TB_WORDS_BIGENDIAN)
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;

#ifdef TB_FLOAT_BIGENDIAN
	tb_bits_set_u32_le(p, 		conv.i[1]);
	tb_bits_set_u32_le(p + 4, 	conv.i[0]);
#else
	tb_bits_set_u32_le(p, 		conv.i[0]);
	tb_bits_set_u32_le(p + 4, 	conv.i[1]);
#endif
#endif
}
static __tb_inline__ tb_void_t tb_bits_set_double_nne_inline(tb_byte_t* p, tb_float_t x)
{
#ifdef TB_CONFIG_MEMORY_UNALIGNED_ACCESS_ENABLE
	*((double*)p) = x;
#else
	union 
	{
		tb_uint32_t 	i[2];
		double 			f;

	} conv;

	conv.f = x;


#ifdef TB_FLOAT_BIGENDIAN
	tb_bits_set_u32_ne(p, 		conv.i[1]);
	tb_bits_set_u32_ne(p + 4, 	conv.i[0]);
#else
	tb_bits_set_u32_ne(p, 		conv.i[0]);
	tb_bits_set_u32_ne(p + 4, 	conv.i[1]);
#endif
#endif
}

#endif /* TB_CONFIG_TYPE_FLOAT */

#endif

