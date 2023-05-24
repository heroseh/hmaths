#ifndef _HMATHS_GENERICS_H_
#define _HMATHS_GENERICS_H_

//
// returns true if _any_ of the vector components are a non-zero value, otherwise false is returned
#define anyG(v) \
	_Generic((v), \
		boolx2: any_boolx2, \
		f16x2: any_f16x2, \
		f32x2: any_f32x2, \
		f64x2: any_f64x2, \
		s8x2: any_s8x2, \
		s16x2: any_s16x2, \
		s32x2: any_s32x2, \
		s64x2: any_s64x2, \
		u8x2: any_u8x2, \
		u16x2: any_u16x2, \
		u32x2: any_u32x2, \
		u64x2: any_u64x2, \
		boolx3: any_boolx3, \
		f16x3: any_f16x3, \
		f32x3: any_f32x3, \
		f64x3: any_f64x3, \
		s8x3: any_s8x3, \
		s16x3: any_s16x3, \
		s32x3: any_s32x3, \
		s64x3: any_s64x3, \
		u8x3: any_u8x3, \
		u16x3: any_u16x3, \
		u32x3: any_u32x3, \
		u64x3: any_u64x3, \
		boolx4: any_boolx4, \
		f16x4: any_f16x4, \
		f32x4: any_f32x4, \
		f64x4: any_f64x4, \
		s8x4: any_s8x4, \
		s16x4: any_s16x4, \
		s32x4: any_s32x4, \
		s64x4: any_s64x4, \
		u8x4: any_u8x4, \
		u16x4: any_u16x4, \
		u32x4: any_u32x4, \
		u64x4: any_u64x4 \
	)(v)

//
// returns true if _all_ of the vector components are a non-zero value, otherwise false is returned
#define allG(v) \
	_Generic((v), \
		boolx2: all_boolx2, \
		f16x2: all_f16x2, \
		f32x2: all_f32x2, \
		f64x2: all_f64x2, \
		s8x2: all_s8x2, \
		s16x2: all_s16x2, \
		s32x2: all_s32x2, \
		s64x2: all_s64x2, \
		u8x2: all_u8x2, \
		u16x2: all_u16x2, \
		u32x2: all_u32x2, \
		u64x2: all_u64x2, \
		boolx3: all_boolx3, \
		f16x3: all_f16x3, \
		f32x3: all_f32x3, \
		f64x3: all_f64x3, \
		s8x3: all_s8x3, \
		s16x3: all_s16x3, \
		s32x3: all_s32x3, \
		s64x3: all_s64x3, \
		u8x3: all_u8x3, \
		u16x3: all_u16x3, \
		u32x3: all_u32x3, \
		u64x3: all_u64x3, \
		boolx4: all_boolx4, \
		f16x4: all_f16x4, \
		f32x4: all_f32x4, \
		f64x4: all_f64x4, \
		s8x4: all_s8x4, \
		s16x4: all_s16x4, \
		s32x4: all_s32x4, \
		s64x4: all_s64x4, \
		u8x4: all_u8x4, \
		u16x4: all_u16x4, \
		u32x4: all_u32x4, \
		u64x4: all_u64x4 \
	)(v)

//
// returns a boolean vector where each component is true if the component in 'v' is a zero value, otherwise it would be false
#define notG(v) \
	_Generic((v), \
		half: not_f16, \
		float: not_f32, \
		double: not_f64, \
		int8_t: not_s8, \
		int16_t: not_s16, \
		int32_t: not_s32, \
		int64_t: not_s64, \
		uint8_t: not_u8, \
		uint16_t: not_u16, \
		uint32_t: not_u32, \
		uint64_t: not_u64, \
		boolx2: not_boolx2, \
		f16x2: not_f16x2, \
		f32x2: not_f32x2, \
		f64x2: not_f64x2, \
		s8x2: not_s8x2, \
		s16x2: not_s16x2, \
		s32x2: not_s32x2, \
		s64x2: not_s64x2, \
		u8x2: not_u8x2, \
		u16x2: not_u16x2, \
		u32x2: not_u32x2, \
		u64x2: not_u64x2, \
		boolx3: not_boolx3, \
		f16x3: not_f16x3, \
		f32x3: not_f32x3, \
		f64x3: not_f64x3, \
		s8x3: not_s8x3, \
		s16x3: not_s16x3, \
		s32x3: not_s32x3, \
		s64x3: not_s64x3, \
		u8x3: not_u8x3, \
		u16x3: not_u16x3, \
		u32x3: not_u32x3, \
		u64x3: not_u64x3, \
		boolx4: not_boolx4, \
		f16x4: not_f16x4, \
		f32x4: not_f32x4, \
		f64x4: not_f64x4, \
		s8x4: not_s8x4, \
		s16x4: not_s16x4, \
		s32x4: not_s32x4, \
		s64x4: not_s64x4, \
		u8x4: not_u8x4, \
		u16x4: not_u16x4, \
		u32x4: not_u32x4, \
		u64x4: not_u64x4 \
	)(v)

//
// returns a vector where each component is the result from adding that component in 'a' to that component in 'b'
#define addG(a, b) \
	_Generic((a), \
		half: add_f16, \
		float: add_f32, \
		double: add_f64, \
		int8_t: add_s8, \
		int16_t: add_s16, \
		int32_t: add_s32, \
		int64_t: add_s64, \
		uint8_t: add_u8, \
		uint16_t: add_u16, \
		uint32_t: add_u32, \
		uint64_t: add_u64, \
		f16x2: add_f16x2, \
		f32x2: add_f32x2, \
		f64x2: add_f64x2, \
		s8x2: add_s8x2, \
		s16x2: add_s16x2, \
		s32x2: add_s32x2, \
		s64x2: add_s64x2, \
		u8x2: add_u8x2, \
		u16x2: add_u16x2, \
		u32x2: add_u32x2, \
		u64x2: add_u64x2, \
		f16x3: add_f16x3, \
		f32x3: add_f32x3, \
		f64x3: add_f64x3, \
		s8x3: add_s8x3, \
		s16x3: add_s16x3, \
		s32x3: add_s32x3, \
		s64x3: add_s64x3, \
		u8x3: add_u8x3, \
		u16x3: add_u16x3, \
		u32x3: add_u32x3, \
		u64x3: add_u64x3, \
		f16x4: add_f16x4, \
		f32x4: add_f32x4, \
		f64x4: add_f64x4, \
		s8x4: add_s8x4, \
		s16x4: add_s16x4, \
		s32x4: add_s32x4, \
		s64x4: add_s64x4, \
		u8x4: add_u8x4, \
		u16x4: add_u16x4, \
		u32x4: add_u32x4, \
		u64x4: add_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from adding that component in 'v' to the value of 's'
#define addsG(v, s) \
	_Generic((v), \
		f16x2: adds_f16x2, \
		f32x2: adds_f32x2, \
		f64x2: adds_f64x2, \
		s8x2: adds_s8x2, \
		s16x2: adds_s16x2, \
		s32x2: adds_s32x2, \
		s64x2: adds_s64x2, \
		u8x2: adds_u8x2, \
		u16x2: adds_u16x2, \
		u32x2: adds_u32x2, \
		u64x2: adds_u64x2, \
		f16x3: adds_f16x3, \
		f32x3: adds_f32x3, \
		f64x3: adds_f64x3, \
		s8x3: adds_s8x3, \
		s16x3: adds_s16x3, \
		s32x3: adds_s32x3, \
		s64x3: adds_s64x3, \
		u8x3: adds_u8x3, \
		u16x3: adds_u16x3, \
		u32x3: adds_u32x3, \
		u64x3: adds_u64x3, \
		f16x4: adds_f16x4, \
		f32x4: adds_f32x4, \
		f64x4: adds_f64x4, \
		s8x4: adds_s8x4, \
		s16x4: adds_s16x4, \
		s32x4: adds_s32x4, \
		s64x4: adds_s64x4, \
		u8x4: adds_u8x4, \
		u16x4: adds_u16x4, \
		u32x4: adds_u32x4, \
		u64x4: adds_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from subtracting that component in 'a' to that component in 'b'
#define subG(a, b) \
	_Generic((a), \
		half: sub_f16, \
		float: sub_f32, \
		double: sub_f64, \
		int8_t: sub_s8, \
		int16_t: sub_s16, \
		int32_t: sub_s32, \
		int64_t: sub_s64, \
		uint8_t: sub_u8, \
		uint16_t: sub_u16, \
		uint32_t: sub_u32, \
		uint64_t: sub_u64, \
		f16x2: sub_f16x2, \
		f32x2: sub_f32x2, \
		f64x2: sub_f64x2, \
		s8x2: sub_s8x2, \
		s16x2: sub_s16x2, \
		s32x2: sub_s32x2, \
		s64x2: sub_s64x2, \
		u8x2: sub_u8x2, \
		u16x2: sub_u16x2, \
		u32x2: sub_u32x2, \
		u64x2: sub_u64x2, \
		f16x3: sub_f16x3, \
		f32x3: sub_f32x3, \
		f64x3: sub_f64x3, \
		s8x3: sub_s8x3, \
		s16x3: sub_s16x3, \
		s32x3: sub_s32x3, \
		s64x3: sub_s64x3, \
		u8x3: sub_u8x3, \
		u16x3: sub_u16x3, \
		u32x3: sub_u32x3, \
		u64x3: sub_u64x3, \
		f16x4: sub_f16x4, \
		f32x4: sub_f32x4, \
		f64x4: sub_f64x4, \
		s8x4: sub_s8x4, \
		s16x4: sub_s16x4, \
		s32x4: sub_s32x4, \
		s64x4: sub_s64x4, \
		u8x4: sub_u8x4, \
		u16x4: sub_u16x4, \
		u32x4: sub_u32x4, \
		u64x4: sub_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from subtracting that component in 'v' to the value of 's'
#define subsG(v, s) \
	_Generic((v), \
		f16x2: subs_f16x2, \
		f32x2: subs_f32x2, \
		f64x2: subs_f64x2, \
		s8x2: subs_s8x2, \
		s16x2: subs_s16x2, \
		s32x2: subs_s32x2, \
		s64x2: subs_s64x2, \
		u8x2: subs_u8x2, \
		u16x2: subs_u16x2, \
		u32x2: subs_u32x2, \
		u64x2: subs_u64x2, \
		f16x3: subs_f16x3, \
		f32x3: subs_f32x3, \
		f64x3: subs_f64x3, \
		s8x3: subs_s8x3, \
		s16x3: subs_s16x3, \
		s32x3: subs_s32x3, \
		s64x3: subs_s64x3, \
		u8x3: subs_u8x3, \
		u16x3: subs_u16x3, \
		u32x3: subs_u32x3, \
		u64x3: subs_u64x3, \
		f16x4: subs_f16x4, \
		f32x4: subs_f32x4, \
		f64x4: subs_f64x4, \
		s8x4: subs_s8x4, \
		s16x4: subs_s16x4, \
		s32x4: subs_s32x4, \
		s64x4: subs_s64x4, \
		u8x4: subs_u8x4, \
		u16x4: subs_u16x4, \
		u32x4: subs_u32x4, \
		u64x4: subs_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from subtracting the value of 's' to that component in 'v'
#define ssubG(s, v) \
	_Generic((v), \
		f16x2: ssub_f16x2, \
		f32x2: ssub_f32x2, \
		f64x2: ssub_f64x2, \
		s8x2: ssub_s8x2, \
		s16x2: ssub_s16x2, \
		s32x2: ssub_s32x2, \
		s64x2: ssub_s64x2, \
		u8x2: ssub_u8x2, \
		u16x2: ssub_u16x2, \
		u32x2: ssub_u32x2, \
		u64x2: ssub_u64x2, \
		f16x3: ssub_f16x3, \
		f32x3: ssub_f32x3, \
		f64x3: ssub_f64x3, \
		s8x3: ssub_s8x3, \
		s16x3: ssub_s16x3, \
		s32x3: ssub_s32x3, \
		s64x3: ssub_s64x3, \
		u8x3: ssub_u8x3, \
		u16x3: ssub_u16x3, \
		u32x3: ssub_u32x3, \
		u64x3: ssub_u64x3, \
		f16x4: ssub_f16x4, \
		f32x4: ssub_f32x4, \
		f64x4: ssub_f64x4, \
		s8x4: ssub_s8x4, \
		s16x4: ssub_s16x4, \
		s32x4: ssub_s32x4, \
		s64x4: ssub_s64x4, \
		u8x4: ssub_u8x4, \
		u16x4: ssub_u16x4, \
		u32x4: ssub_u32x4, \
		u64x4: ssub_u64x4 \
	)(s, v)

//
// returns a vector where each component is the result from multiplying that component in 'a' to that component in 'b'
#define mulG(a, b) \
	_Generic((a), \
		half: mul_f16, \
		float: mul_f32, \
		double: mul_f64, \
		int8_t: mul_s8, \
		int16_t: mul_s16, \
		int32_t: mul_s32, \
		int64_t: mul_s64, \
		uint8_t: mul_u8, \
		uint16_t: mul_u16, \
		uint32_t: mul_u32, \
		uint64_t: mul_u64, \
		f16x2: mul_f16x2, \
		f32x2: mul_f32x2, \
		f64x2: mul_f64x2, \
		s8x2: mul_s8x2, \
		s16x2: mul_s16x2, \
		s32x2: mul_s32x2, \
		s64x2: mul_s64x2, \
		u8x2: mul_u8x2, \
		u16x2: mul_u16x2, \
		u32x2: mul_u32x2, \
		u64x2: mul_u64x2, \
		f16x3: mul_f16x3, \
		f32x3: mul_f32x3, \
		f64x3: mul_f64x3, \
		s8x3: mul_s8x3, \
		s16x3: mul_s16x3, \
		s32x3: mul_s32x3, \
		s64x3: mul_s64x3, \
		u8x3: mul_u8x3, \
		u16x3: mul_u16x3, \
		u32x3: mul_u32x3, \
		u64x3: mul_u64x3, \
		f16x4: mul_f16x4, \
		f32x4: mul_f32x4, \
		f64x4: mul_f64x4, \
		s8x4: mul_s8x4, \
		s16x4: mul_s16x4, \
		s32x4: mul_s32x4, \
		s64x4: mul_s64x4, \
		u8x4: mul_u8x4, \
		u16x4: mul_u16x4, \
		u32x4: mul_u32x4, \
		u64x4: mul_u64x4, \
		f32x2x2: mul_f32x2x2_f32x2x2, \
		f64x2x2: mul_f64x2x2_f64x2x2, \
		f32x3x3: mul_f32x3x3_f32x3x3, \
		f64x3x3: mul_f64x3x3_f64x3x3, \
		f32x4x4: mul_f32x4x4_f32x4x4, \
		f64x4x4: mul_f64x4x4_f64x4x4 \
	)(a, b)

//
// returns a vector where each component is the result from multiplying that component in 'v' to the value of 's'
#define mulsG(v, s) \
	_Generic((v), \
		f16x2: muls_f16x2, \
		f32x2: muls_f32x2, \
		f64x2: muls_f64x2, \
		s8x2: muls_s8x2, \
		s16x2: muls_s16x2, \
		s32x2: muls_s32x2, \
		s64x2: muls_s64x2, \
		u8x2: muls_u8x2, \
		u16x2: muls_u16x2, \
		u32x2: muls_u32x2, \
		u64x2: muls_u64x2, \
		f16x3: muls_f16x3, \
		f32x3: muls_f32x3, \
		f64x3: muls_f64x3, \
		s8x3: muls_s8x3, \
		s16x3: muls_s16x3, \
		s32x3: muls_s32x3, \
		s64x3: muls_s64x3, \
		u8x3: muls_u8x3, \
		u16x3: muls_u16x3, \
		u32x3: muls_u32x3, \
		u64x3: muls_u64x3, \
		f16x4: muls_f16x4, \
		f32x4: muls_f32x4, \
		f64x4: muls_f64x4, \
		s8x4: muls_s8x4, \
		s16x4: muls_s16x4, \
		s32x4: muls_s32x4, \
		s64x4: muls_s64x4, \
		u8x4: muls_u8x4, \
		u16x4: muls_u16x4, \
		u32x4: muls_u32x4, \
		u64x4: muls_u64x4, \
		f32x2x2: muls_f32x2x2, \
		f64x2x2: muls_f64x2x2, \
		f32x3x3: muls_f32x3x3, \
		f64x3x3: muls_f64x3x3, \
		f32x4x4: muls_f32x4x4, \
		f64x4x4: muls_f64x4x4 \
	)(v, s)

//
// returns a vector that is a result of multipling matrix 'm' with vector 'v'
#define mulvG(m, v) \
	_Generic((m), \
		f32x2x2: mul_f32x2x2_f32x2, \
		f64x2x2: mul_f64x2x2_f64x2, \
		f32x3x3: mul_f32x3x3_f32x3, \
		f64x3x3: mul_f64x3x3_f64x3, \
		f32x4x4: mul_f32x4x4_f32x4, \
		f64x4x4: mul_f64x4x4_f64x4 \
	)(m, v)

//
// returns a vector that is a result of multipling vector 'v' with matrix 'm'
#define vmulG(v, m) \
	_Generic((m), \
		f32x2x2: mul_f32x2_f32x2x2, \
		f64x2x2: mul_f64x2_f64x2x2, \
		f32x3x3: mul_f32x3_f32x3x3, \
		f64x3x3: mul_f64x3_f64x3x3, \
		f32x4x4: mul_f32x4_f32x4x4, \
		f64x4x4: mul_f64x4_f64x4x4 \
	)(v, m)

//
// returns a vector where each component is the result from dividing that component in 'a' to that component in 'b'
#define divG(a, b) \
	_Generic((a), \
		half: div_f16, \
		float: div_f32, \
		double: div_f64, \
		int8_t: div_s8, \
		int16_t: div_s16, \
		int32_t: div_s32, \
		int64_t: div_s64, \
		uint8_t: div_u8, \
		uint16_t: div_u16, \
		uint32_t: div_u32, \
		uint64_t: div_u64, \
		f16x2: div_f16x2, \
		f32x2: div_f32x2, \
		f64x2: div_f64x2, \
		s8x2: div_s8x2, \
		s16x2: div_s16x2, \
		s32x2: div_s32x2, \
		s64x2: div_s64x2, \
		u8x2: div_u8x2, \
		u16x2: div_u16x2, \
		u32x2: div_u32x2, \
		u64x2: div_u64x2, \
		f16x3: div_f16x3, \
		f32x3: div_f32x3, \
		f64x3: div_f64x3, \
		s8x3: div_s8x3, \
		s16x3: div_s16x3, \
		s32x3: div_s32x3, \
		s64x3: div_s64x3, \
		u8x3: div_u8x3, \
		u16x3: div_u16x3, \
		u32x3: div_u32x3, \
		u64x3: div_u64x3, \
		f16x4: div_f16x4, \
		f32x4: div_f32x4, \
		f64x4: div_f64x4, \
		s8x4: div_s8x4, \
		s16x4: div_s16x4, \
		s32x4: div_s32x4, \
		s64x4: div_s64x4, \
		u8x4: div_u8x4, \
		u16x4: div_u16x4, \
		u32x4: div_u32x4, \
		u64x4: div_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from dividing that component in 'v' to the value of 's'
#define divsG(v, s) \
	_Generic((v), \
		f16x2: divs_f16x2, \
		f32x2: divs_f32x2, \
		f64x2: divs_f64x2, \
		s8x2: divs_s8x2, \
		s16x2: divs_s16x2, \
		s32x2: divs_s32x2, \
		s64x2: divs_s64x2, \
		u8x2: divs_u8x2, \
		u16x2: divs_u16x2, \
		u32x2: divs_u32x2, \
		u64x2: divs_u64x2, \
		f16x3: divs_f16x3, \
		f32x3: divs_f32x3, \
		f64x3: divs_f64x3, \
		s8x3: divs_s8x3, \
		s16x3: divs_s16x3, \
		s32x3: divs_s32x3, \
		s64x3: divs_s64x3, \
		u8x3: divs_u8x3, \
		u16x3: divs_u16x3, \
		u32x3: divs_u32x3, \
		u64x3: divs_u64x3, \
		f16x4: divs_f16x4, \
		f32x4: divs_f32x4, \
		f64x4: divs_f64x4, \
		s8x4: divs_s8x4, \
		s16x4: divs_s16x4, \
		s32x4: divs_s32x4, \
		s64x4: divs_s64x4, \
		u8x4: divs_u8x4, \
		u16x4: divs_u16x4, \
		u32x4: divs_u32x4, \
		u64x4: divs_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from dividing the value of 's' to that component in 'v'
#define sdivG(s, v) \
	_Generic((v), \
		f16x2: sdiv_f16x2, \
		f32x2: sdiv_f32x2, \
		f64x2: sdiv_f64x2, \
		s8x2: sdiv_s8x2, \
		s16x2: sdiv_s16x2, \
		s32x2: sdiv_s32x2, \
		s64x2: sdiv_s64x2, \
		u8x2: sdiv_u8x2, \
		u16x2: sdiv_u16x2, \
		u32x2: sdiv_u32x2, \
		u64x2: sdiv_u64x2, \
		f16x3: sdiv_f16x3, \
		f32x3: sdiv_f32x3, \
		f64x3: sdiv_f64x3, \
		s8x3: sdiv_s8x3, \
		s16x3: sdiv_s16x3, \
		s32x3: sdiv_s32x3, \
		s64x3: sdiv_s64x3, \
		u8x3: sdiv_u8x3, \
		u16x3: sdiv_u16x3, \
		u32x3: sdiv_u32x3, \
		u64x3: sdiv_u64x3, \
		f16x4: sdiv_f16x4, \
		f32x4: sdiv_f32x4, \
		f64x4: sdiv_f64x4, \
		s8x4: sdiv_s8x4, \
		s16x4: sdiv_s16x4, \
		s32x4: sdiv_s32x4, \
		s64x4: sdiv_s64x4, \
		u8x4: sdiv_u8x4, \
		u16x4: sdiv_u16x4, \
		u32x4: sdiv_u32x4, \
		u64x4: sdiv_u64x4 \
	)(s, v)

//
// returns a vector where each component is the result from moduloing that component in 'a' to that component in 'b'
#define modG(a, b) \
	_Generic((a), \
		half: mod_f16, \
		float: mod_f32, \
		double: mod_f64, \
		int8_t: mod_s8, \
		int16_t: mod_s16, \
		int32_t: mod_s32, \
		int64_t: mod_s64, \
		uint8_t: mod_u8, \
		uint16_t: mod_u16, \
		uint32_t: mod_u32, \
		uint64_t: mod_u64, \
		f16x2: mod_f16x2, \
		f32x2: mod_f32x2, \
		f64x2: mod_f64x2, \
		s8x2: mod_s8x2, \
		s16x2: mod_s16x2, \
		s32x2: mod_s32x2, \
		s64x2: mod_s64x2, \
		u8x2: mod_u8x2, \
		u16x2: mod_u16x2, \
		u32x2: mod_u32x2, \
		u64x2: mod_u64x2, \
		f16x3: mod_f16x3, \
		f32x3: mod_f32x3, \
		f64x3: mod_f64x3, \
		s8x3: mod_s8x3, \
		s16x3: mod_s16x3, \
		s32x3: mod_s32x3, \
		s64x3: mod_s64x3, \
		u8x3: mod_u8x3, \
		u16x3: mod_u16x3, \
		u32x3: mod_u32x3, \
		u64x3: mod_u64x3, \
		f16x4: mod_f16x4, \
		f32x4: mod_f32x4, \
		f64x4: mod_f64x4, \
		s8x4: mod_s8x4, \
		s16x4: mod_s16x4, \
		s32x4: mod_s32x4, \
		s64x4: mod_s64x4, \
		u8x4: mod_u8x4, \
		u16x4: mod_u16x4, \
		u32x4: mod_u32x4, \
		u64x4: mod_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from moduloing that component in 'v' to the value 's'
#define modsG(v, s) \
	_Generic((v), \
		f16x2: mods_f16x2, \
		f32x2: mods_f32x2, \
		f64x2: mods_f64x2, \
		s8x2: mods_s8x2, \
		s16x2: mods_s16x2, \
		s32x2: mods_s32x2, \
		s64x2: mods_s64x2, \
		u8x2: mods_u8x2, \
		u16x2: mods_u16x2, \
		u32x2: mods_u32x2, \
		u64x2: mods_u64x2, \
		f16x3: mods_f16x3, \
		f32x3: mods_f32x3, \
		f64x3: mods_f64x3, \
		s8x3: mods_s8x3, \
		s16x3: mods_s16x3, \
		s32x3: mods_s32x3, \
		s64x3: mods_s64x3, \
		u8x3: mods_u8x3, \
		u16x3: mods_u16x3, \
		u32x3: mods_u32x3, \
		u64x3: mods_u64x3, \
		f16x4: mods_f16x4, \
		f32x4: mods_f32x4, \
		f64x4: mods_f64x4, \
		s8x4: mods_s8x4, \
		s16x4: mods_s16x4, \
		s32x4: mods_s32x4, \
		s64x4: mods_s64x4, \
		u8x4: mods_u8x4, \
		u16x4: mods_u16x4, \
		u32x4: mods_u32x4, \
		u64x4: mods_u64x4 \
	)(v, s)

//
// returns a boolean vector where each component is true when that component in 'a' is equal to that component in 'b'
#define eqG(a, b) \
	_Generic((a), \
		half: eq_f16, \
		float: eq_f32, \
		double: eq_f64, \
		int8_t: eq_s8, \
		int16_t: eq_s16, \
		int32_t: eq_s32, \
		int64_t: eq_s64, \
		uint8_t: eq_u8, \
		uint16_t: eq_u16, \
		uint32_t: eq_u32, \
		uint64_t: eq_u64, \
		f16x2: eq_f16x2, \
		f32x2: eq_f32x2, \
		f64x2: eq_f64x2, \
		s8x2: eq_s8x2, \
		s16x2: eq_s16x2, \
		s32x2: eq_s32x2, \
		s64x2: eq_s64x2, \
		u8x2: eq_u8x2, \
		u16x2: eq_u16x2, \
		u32x2: eq_u32x2, \
		u64x2: eq_u64x2, \
		f16x3: eq_f16x3, \
		f32x3: eq_f32x3, \
		f64x3: eq_f64x3, \
		s8x3: eq_s8x3, \
		s16x3: eq_s16x3, \
		s32x3: eq_s32x3, \
		s64x3: eq_s64x3, \
		u8x3: eq_u8x3, \
		u16x3: eq_u16x3, \
		u32x3: eq_u32x3, \
		u64x3: eq_u64x3, \
		f16x4: eq_f16x4, \
		f32x4: eq_f32x4, \
		f64x4: eq_f64x4, \
		s8x4: eq_s8x4, \
		s16x4: eq_s16x4, \
		s32x4: eq_s32x4, \
		s64x4: eq_s64x4, \
		u8x4: eq_u8x4, \
		u16x4: eq_u16x4, \
		u32x4: eq_u32x4, \
		u64x4: eq_u64x4 \
	)(a, b)

//
// returns a boolean vector where each component is true when that component in 'v' is equal to the value 's'
#define eqsG(v, s) \
	_Generic((v), \
		f16x2: eqs_f16x2, \
		f32x2: eqs_f32x2, \
		f64x2: eqs_f64x2, \
		s8x2: eqs_s8x2, \
		s16x2: eqs_s16x2, \
		s32x2: eqs_s32x2, \
		s64x2: eqs_s64x2, \
		u8x2: eqs_u8x2, \
		u16x2: eqs_u16x2, \
		u32x2: eqs_u32x2, \
		u64x2: eqs_u64x2, \
		f16x3: eqs_f16x3, \
		f32x3: eqs_f32x3, \
		f64x3: eqs_f64x3, \
		s8x3: eqs_s8x3, \
		s16x3: eqs_s16x3, \
		s32x3: eqs_s32x3, \
		s64x3: eqs_s64x3, \
		u8x3: eqs_u8x3, \
		u16x3: eqs_u16x3, \
		u32x3: eqs_u32x3, \
		u64x3: eqs_u64x3, \
		f16x4: eqs_f16x4, \
		f32x4: eqs_f32x4, \
		f64x4: eqs_f64x4, \
		s8x4: eqs_s8x4, \
		s16x4: eqs_s16x4, \
		s32x4: eqs_s32x4, \
		s64x4: eqs_s64x4, \
		u8x4: eqs_u8x4, \
		u16x4: eqs_u16x4, \
		u32x4: eqs_u32x4, \
		u64x4: eqs_u64x4 \
	)(v, s)

//
// returns a boolean vector where each component is true when that component in 'a' is not equal to that component in 'b'
#define neqG(a, b) \
	_Generic((a), \
		half: neq_f16, \
		float: neq_f32, \
		double: neq_f64, \
		int8_t: neq_s8, \
		int16_t: neq_s16, \
		int32_t: neq_s32, \
		int64_t: neq_s64, \
		uint8_t: neq_u8, \
		uint16_t: neq_u16, \
		uint32_t: neq_u32, \
		uint64_t: neq_u64, \
		f16x2: neq_f16x2, \
		f32x2: neq_f32x2, \
		f64x2: neq_f64x2, \
		s8x2: neq_s8x2, \
		s16x2: neq_s16x2, \
		s32x2: neq_s32x2, \
		s64x2: neq_s64x2, \
		u8x2: neq_u8x2, \
		u16x2: neq_u16x2, \
		u32x2: neq_u32x2, \
		u64x2: neq_u64x2, \
		f16x3: neq_f16x3, \
		f32x3: neq_f32x3, \
		f64x3: neq_f64x3, \
		s8x3: neq_s8x3, \
		s16x3: neq_s16x3, \
		s32x3: neq_s32x3, \
		s64x3: neq_s64x3, \
		u8x3: neq_u8x3, \
		u16x3: neq_u16x3, \
		u32x3: neq_u32x3, \
		u64x3: neq_u64x3, \
		f16x4: neq_f16x4, \
		f32x4: neq_f32x4, \
		f64x4: neq_f64x4, \
		s8x4: neq_s8x4, \
		s16x4: neq_s16x4, \
		s32x4: neq_s32x4, \
		s64x4: neq_s64x4, \
		u8x4: neq_u8x4, \
		u16x4: neq_u16x4, \
		u32x4: neq_u32x4, \
		u64x4: neq_u64x4 \
	)(a, b)

//
// returns a boolean vector where each component is true when that component in 'v' is not equal to the value 's'
#define neqsG(v, s) \
	_Generic((v), \
		f16x2: neqs_f16x2, \
		f32x2: neqs_f32x2, \
		f64x2: neqs_f64x2, \
		s8x2: neqs_s8x2, \
		s16x2: neqs_s16x2, \
		s32x2: neqs_s32x2, \
		s64x2: neqs_s64x2, \
		u8x2: neqs_u8x2, \
		u16x2: neqs_u16x2, \
		u32x2: neqs_u32x2, \
		u64x2: neqs_u64x2, \
		f16x3: neqs_f16x3, \
		f32x3: neqs_f32x3, \
		f64x3: neqs_f64x3, \
		s8x3: neqs_s8x3, \
		s16x3: neqs_s16x3, \
		s32x3: neqs_s32x3, \
		s64x3: neqs_s64x3, \
		u8x3: neqs_u8x3, \
		u16x3: neqs_u16x3, \
		u32x3: neqs_u32x3, \
		u64x3: neqs_u64x3, \
		f16x4: neqs_f16x4, \
		f32x4: neqs_f32x4, \
		f64x4: neqs_f64x4, \
		s8x4: neqs_s8x4, \
		s16x4: neqs_s16x4, \
		s32x4: neqs_s32x4, \
		s64x4: neqs_s64x4, \
		u8x4: neqs_u8x4, \
		u16x4: neqs_u16x4, \
		u32x4: neqs_u32x4, \
		u64x4: neqs_u64x4 \
	)(v, s)

//
// returns a boolean vector where each component is true when that component in 'a' is less than to that component in 'b'
#define ltG(a, b) \
	_Generic((a), \
		half: lt_f16, \
		float: lt_f32, \
		double: lt_f64, \
		int8_t: lt_s8, \
		int16_t: lt_s16, \
		int32_t: lt_s32, \
		int64_t: lt_s64, \
		uint8_t: lt_u8, \
		uint16_t: lt_u16, \
		uint32_t: lt_u32, \
		uint64_t: lt_u64, \
		f16x2: lt_f16x2, \
		f32x2: lt_f32x2, \
		f64x2: lt_f64x2, \
		s8x2: lt_s8x2, \
		s16x2: lt_s16x2, \
		s32x2: lt_s32x2, \
		s64x2: lt_s64x2, \
		u8x2: lt_u8x2, \
		u16x2: lt_u16x2, \
		u32x2: lt_u32x2, \
		u64x2: lt_u64x2, \
		f16x3: lt_f16x3, \
		f32x3: lt_f32x3, \
		f64x3: lt_f64x3, \
		s8x3: lt_s8x3, \
		s16x3: lt_s16x3, \
		s32x3: lt_s32x3, \
		s64x3: lt_s64x3, \
		u8x3: lt_u8x3, \
		u16x3: lt_u16x3, \
		u32x3: lt_u32x3, \
		u64x3: lt_u64x3, \
		f16x4: lt_f16x4, \
		f32x4: lt_f32x4, \
		f64x4: lt_f64x4, \
		s8x4: lt_s8x4, \
		s16x4: lt_s16x4, \
		s32x4: lt_s32x4, \
		s64x4: lt_s64x4, \
		u8x4: lt_u8x4, \
		u16x4: lt_u16x4, \
		u32x4: lt_u32x4, \
		u64x4: lt_u64x4 \
	)(a, b)

//
// returns a boolean vector where each component is true when that component in 'v' is less than to the value 's'
#define ltsG(v, s) \
	_Generic((v), \
		f16x2: lts_f16x2, \
		f32x2: lts_f32x2, \
		f64x2: lts_f64x2, \
		s8x2: lts_s8x2, \
		s16x2: lts_s16x2, \
		s32x2: lts_s32x2, \
		s64x2: lts_s64x2, \
		u8x2: lts_u8x2, \
		u16x2: lts_u16x2, \
		u32x2: lts_u32x2, \
		u64x2: lts_u64x2, \
		f16x3: lts_f16x3, \
		f32x3: lts_f32x3, \
		f64x3: lts_f64x3, \
		s8x3: lts_s8x3, \
		s16x3: lts_s16x3, \
		s32x3: lts_s32x3, \
		s64x3: lts_s64x3, \
		u8x3: lts_u8x3, \
		u16x3: lts_u16x3, \
		u32x3: lts_u32x3, \
		u64x3: lts_u64x3, \
		f16x4: lts_f16x4, \
		f32x4: lts_f32x4, \
		f64x4: lts_f64x4, \
		s8x4: lts_s8x4, \
		s16x4: lts_s16x4, \
		s32x4: lts_s32x4, \
		s64x4: lts_s64x4, \
		u8x4: lts_u8x4, \
		u16x4: lts_u16x4, \
		u32x4: lts_u32x4, \
		u64x4: lts_u64x4 \
	)(v, s)

//
// returns a boolean vector where each component is true when that component in 'a' is less than or equal to that component in 'b'
#define lteqG(a, b) \
	_Generic((a), \
		half: lteq_f16, \
		float: lteq_f32, \
		double: lteq_f64, \
		int8_t: lteq_s8, \
		int16_t: lteq_s16, \
		int32_t: lteq_s32, \
		int64_t: lteq_s64, \
		uint8_t: lteq_u8, \
		uint16_t: lteq_u16, \
		uint32_t: lteq_u32, \
		uint64_t: lteq_u64, \
		f16x2: lteq_f16x2, \
		f32x2: lteq_f32x2, \
		f64x2: lteq_f64x2, \
		s8x2: lteq_s8x2, \
		s16x2: lteq_s16x2, \
		s32x2: lteq_s32x2, \
		s64x2: lteq_s64x2, \
		u8x2: lteq_u8x2, \
		u16x2: lteq_u16x2, \
		u32x2: lteq_u32x2, \
		u64x2: lteq_u64x2, \
		f16x3: lteq_f16x3, \
		f32x3: lteq_f32x3, \
		f64x3: lteq_f64x3, \
		s8x3: lteq_s8x3, \
		s16x3: lteq_s16x3, \
		s32x3: lteq_s32x3, \
		s64x3: lteq_s64x3, \
		u8x3: lteq_u8x3, \
		u16x3: lteq_u16x3, \
		u32x3: lteq_u32x3, \
		u64x3: lteq_u64x3, \
		f16x4: lteq_f16x4, \
		f32x4: lteq_f32x4, \
		f64x4: lteq_f64x4, \
		s8x4: lteq_s8x4, \
		s16x4: lteq_s16x4, \
		s32x4: lteq_s32x4, \
		s64x4: lteq_s64x4, \
		u8x4: lteq_u8x4, \
		u16x4: lteq_u16x4, \
		u32x4: lteq_u32x4, \
		u64x4: lteq_u64x4 \
	)(a, b)

//
// returns a boolean vector where each component is true when that component in 'v' is less than or equal to the value 's'
#define lteqsG(v, s) \
	_Generic((v), \
		f16x2: lteqs_f16x2, \
		f32x2: lteqs_f32x2, \
		f64x2: lteqs_f64x2, \
		s8x2: lteqs_s8x2, \
		s16x2: lteqs_s16x2, \
		s32x2: lteqs_s32x2, \
		s64x2: lteqs_s64x2, \
		u8x2: lteqs_u8x2, \
		u16x2: lteqs_u16x2, \
		u32x2: lteqs_u32x2, \
		u64x2: lteqs_u64x2, \
		f16x3: lteqs_f16x3, \
		f32x3: lteqs_f32x3, \
		f64x3: lteqs_f64x3, \
		s8x3: lteqs_s8x3, \
		s16x3: lteqs_s16x3, \
		s32x3: lteqs_s32x3, \
		s64x3: lteqs_s64x3, \
		u8x3: lteqs_u8x3, \
		u16x3: lteqs_u16x3, \
		u32x3: lteqs_u32x3, \
		u64x3: lteqs_u64x3, \
		f16x4: lteqs_f16x4, \
		f32x4: lteqs_f32x4, \
		f64x4: lteqs_f64x4, \
		s8x4: lteqs_s8x4, \
		s16x4: lteqs_s16x4, \
		s32x4: lteqs_s32x4, \
		s64x4: lteqs_s64x4, \
		u8x4: lteqs_u8x4, \
		u16x4: lteqs_u16x4, \
		u32x4: lteqs_u32x4, \
		u64x4: lteqs_u64x4 \
	)(v, s)

//
// returns a boolean vector where each component is true when that component in 'a' is greater than to that component in 'b'
#define gtG(a, b) \
	_Generic((a), \
		half: gt_f16, \
		float: gt_f32, \
		double: gt_f64, \
		int8_t: gt_s8, \
		int16_t: gt_s16, \
		int32_t: gt_s32, \
		int64_t: gt_s64, \
		uint8_t: gt_u8, \
		uint16_t: gt_u16, \
		uint32_t: gt_u32, \
		uint64_t: gt_u64, \
		f16x2: gt_f16x2, \
		f32x2: gt_f32x2, \
		f64x2: gt_f64x2, \
		s8x2: gt_s8x2, \
		s16x2: gt_s16x2, \
		s32x2: gt_s32x2, \
		s64x2: gt_s64x2, \
		u8x2: gt_u8x2, \
		u16x2: gt_u16x2, \
		u32x2: gt_u32x2, \
		u64x2: gt_u64x2, \
		f16x3: gt_f16x3, \
		f32x3: gt_f32x3, \
		f64x3: gt_f64x3, \
		s8x3: gt_s8x3, \
		s16x3: gt_s16x3, \
		s32x3: gt_s32x3, \
		s64x3: gt_s64x3, \
		u8x3: gt_u8x3, \
		u16x3: gt_u16x3, \
		u32x3: gt_u32x3, \
		u64x3: gt_u64x3, \
		f16x4: gt_f16x4, \
		f32x4: gt_f32x4, \
		f64x4: gt_f64x4, \
		s8x4: gt_s8x4, \
		s16x4: gt_s16x4, \
		s32x4: gt_s32x4, \
		s64x4: gt_s64x4, \
		u8x4: gt_u8x4, \
		u16x4: gt_u16x4, \
		u32x4: gt_u32x4, \
		u64x4: gt_u64x4 \
	)(a, b)

//
// returns a boolean vector where each component is true when that component in 'v' is greater than to the value 's'
#define gtsG(v, s) \
	_Generic((v), \
		f16x2: gts_f16x2, \
		f32x2: gts_f32x2, \
		f64x2: gts_f64x2, \
		s8x2: gts_s8x2, \
		s16x2: gts_s16x2, \
		s32x2: gts_s32x2, \
		s64x2: gts_s64x2, \
		u8x2: gts_u8x2, \
		u16x2: gts_u16x2, \
		u32x2: gts_u32x2, \
		u64x2: gts_u64x2, \
		f16x3: gts_f16x3, \
		f32x3: gts_f32x3, \
		f64x3: gts_f64x3, \
		s8x3: gts_s8x3, \
		s16x3: gts_s16x3, \
		s32x3: gts_s32x3, \
		s64x3: gts_s64x3, \
		u8x3: gts_u8x3, \
		u16x3: gts_u16x3, \
		u32x3: gts_u32x3, \
		u64x3: gts_u64x3, \
		f16x4: gts_f16x4, \
		f32x4: gts_f32x4, \
		f64x4: gts_f64x4, \
		s8x4: gts_s8x4, \
		s16x4: gts_s16x4, \
		s32x4: gts_s32x4, \
		s64x4: gts_s64x4, \
		u8x4: gts_u8x4, \
		u16x4: gts_u16x4, \
		u32x4: gts_u32x4, \
		u64x4: gts_u64x4 \
	)(v, s)

//
// returns a boolean vector where each component is true when that component in 'a' is greater than or equal to that component in 'b'
#define gteqG(a, b) \
	_Generic((a), \
		half: gteq_f16, \
		float: gteq_f32, \
		double: gteq_f64, \
		int8_t: gteq_s8, \
		int16_t: gteq_s16, \
		int32_t: gteq_s32, \
		int64_t: gteq_s64, \
		uint8_t: gteq_u8, \
		uint16_t: gteq_u16, \
		uint32_t: gteq_u32, \
		uint64_t: gteq_u64, \
		f16x2: gteq_f16x2, \
		f32x2: gteq_f32x2, \
		f64x2: gteq_f64x2, \
		s8x2: gteq_s8x2, \
		s16x2: gteq_s16x2, \
		s32x2: gteq_s32x2, \
		s64x2: gteq_s64x2, \
		u8x2: gteq_u8x2, \
		u16x2: gteq_u16x2, \
		u32x2: gteq_u32x2, \
		u64x2: gteq_u64x2, \
		f16x3: gteq_f16x3, \
		f32x3: gteq_f32x3, \
		f64x3: gteq_f64x3, \
		s8x3: gteq_s8x3, \
		s16x3: gteq_s16x3, \
		s32x3: gteq_s32x3, \
		s64x3: gteq_s64x3, \
		u8x3: gteq_u8x3, \
		u16x3: gteq_u16x3, \
		u32x3: gteq_u32x3, \
		u64x3: gteq_u64x3, \
		f16x4: gteq_f16x4, \
		f32x4: gteq_f32x4, \
		f64x4: gteq_f64x4, \
		s8x4: gteq_s8x4, \
		s16x4: gteq_s16x4, \
		s32x4: gteq_s32x4, \
		s64x4: gteq_s64x4, \
		u8x4: gteq_u8x4, \
		u16x4: gteq_u16x4, \
		u32x4: gteq_u32x4, \
		u64x4: gteq_u64x4 \
	)(a, b)

//
// returns a boolean vector where each component is true when that component in 'v' is greater than or equal to the value 's'
#define gteqsG(v, s) \
	_Generic((v), \
		f16x2: gteqs_f16x2, \
		f32x2: gteqs_f32x2, \
		f64x2: gteqs_f64x2, \
		s8x2: gteqs_s8x2, \
		s16x2: gteqs_s16x2, \
		s32x2: gteqs_s32x2, \
		s64x2: gteqs_s64x2, \
		u8x2: gteqs_u8x2, \
		u16x2: gteqs_u16x2, \
		u32x2: gteqs_u32x2, \
		u64x2: gteqs_u64x2, \
		f16x3: gteqs_f16x3, \
		f32x3: gteqs_f32x3, \
		f64x3: gteqs_f64x3, \
		s8x3: gteqs_s8x3, \
		s16x3: gteqs_s16x3, \
		s32x3: gteqs_s32x3, \
		s64x3: gteqs_s64x3, \
		u8x3: gteqs_u8x3, \
		u16x3: gteqs_u16x3, \
		u32x3: gteqs_u32x3, \
		u64x3: gteqs_u64x3, \
		f16x4: gteqs_f16x4, \
		f32x4: gteqs_f32x4, \
		f64x4: gteqs_f64x4, \
		s8x4: gteqs_s8x4, \
		s16x4: gteqs_s16x4, \
		s32x4: gteqs_s32x4, \
		s64x4: gteqs_s64x4, \
		u8x4: gteqs_u8x4, \
		u16x4: gteqs_u16x4, \
		u32x4: gteqs_u32x4, \
		u64x4: gteqs_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from negating that component in 'v'
#define negG(v) \
	_Generic((v), \
		half: neg_f16, \
		float: neg_f32, \
		double: neg_f64, \
		int8_t: neg_s8, \
		int16_t: neg_s16, \
		int32_t: neg_s32, \
		int64_t: neg_s64, \
		f16x2: neg_f16x2, \
		f32x2: neg_f32x2, \
		f64x2: neg_f64x2, \
		s8x2: neg_s8x2, \
		s16x2: neg_s16x2, \
		s32x2: neg_s32x2, \
		s64x2: neg_s64x2, \
		u8x2: neg_u8x2, \
		u16x2: neg_u16x2, \
		u32x2: neg_u32x2, \
		u64x2: neg_u64x2, \
		f16x3: neg_f16x3, \
		f32x3: neg_f32x3, \
		f64x3: neg_f64x3, \
		s8x3: neg_s8x3, \
		s16x3: neg_s16x3, \
		s32x3: neg_s32x3, \
		s64x3: neg_s64x3, \
		u8x3: neg_u8x3, \
		u16x3: neg_u16x3, \
		u32x3: neg_u32x3, \
		u64x3: neg_u64x3, \
		f16x4: neg_f16x4, \
		f32x4: neg_f32x4, \
		f64x4: neg_f64x4, \
		s8x4: neg_s8x4, \
		s16x4: neg_s16x4, \
		s32x4: neg_s32x4, \
		s64x4: neg_s64x4, \
		u8x4: neg_u8x4, \
		u16x4: neg_u16x4, \
		u32x4: neg_u32x4, \
		u64x4: neg_u64x4 \
	)(v)

//
// returns a vector where each component is the minimum between that component in 'a' and that component in 'b'
#define minG(a, b) \
	_Generic((a), \
		half: min_f16, \
		float: min_f32, \
		double: min_f64, \
		int8_t: min_s8, \
		int16_t: min_s16, \
		int32_t: min_s32, \
		int64_t: min_s64, \
		uint8_t: min_u8, \
		uint16_t: min_u16, \
		uint32_t: min_u32, \
		uint64_t: min_u64, \
		f16x2: min_f16x2, \
		f32x2: min_f32x2, \
		f64x2: min_f64x2, \
		s8x2: min_s8x2, \
		s16x2: min_s16x2, \
		s32x2: min_s32x2, \
		s64x2: min_s64x2, \
		u8x2: min_u8x2, \
		u16x2: min_u16x2, \
		u32x2: min_u32x2, \
		u64x2: min_u64x2, \
		f16x3: min_f16x3, \
		f32x3: min_f32x3, \
		f64x3: min_f64x3, \
		s8x3: min_s8x3, \
		s16x3: min_s16x3, \
		s32x3: min_s32x3, \
		s64x3: min_s64x3, \
		u8x3: min_u8x3, \
		u16x3: min_u16x3, \
		u32x3: min_u32x3, \
		u64x3: min_u64x3, \
		f16x4: min_f16x4, \
		f32x4: min_f32x4, \
		f64x4: min_f64x4, \
		s8x4: min_s8x4, \
		s16x4: min_s16x4, \
		s32x4: min_s32x4, \
		s64x4: min_s64x4, \
		u8x4: min_u8x4, \
		u16x4: min_u16x4, \
		u32x4: min_u32x4, \
		u64x4: min_u64x4 \
	)(a, b)

//
// returns a vector where each component is the minimum between that component in 'a' and 's'
#define minsG(v, s) \
	_Generic((v), \
		f16x2: mins_f16x2, \
		f32x2: mins_f32x2, \
		f64x2: mins_f64x2, \
		s8x2: mins_s8x2, \
		s16x2: mins_s16x2, \
		s32x2: mins_s32x2, \
		s64x2: mins_s64x2, \
		u8x2: mins_u8x2, \
		u16x2: mins_u16x2, \
		u32x2: mins_u32x2, \
		u64x2: mins_u64x2, \
		f16x3: mins_f16x3, \
		f32x3: mins_f32x3, \
		f64x3: mins_f64x3, \
		s8x3: mins_s8x3, \
		s16x3: mins_s16x3, \
		s32x3: mins_s32x3, \
		s64x3: mins_s64x3, \
		u8x3: mins_u8x3, \
		u16x3: mins_u16x3, \
		u32x3: mins_u32x3, \
		u64x3: mins_u64x3, \
		f16x4: mins_f16x4, \
		f32x4: mins_f32x4, \
		f64x4: mins_f64x4, \
		s8x4: mins_s8x4, \
		s16x4: mins_s16x4, \
		s32x4: mins_s32x4, \
		s64x4: mins_s64x4, \
		u8x4: mins_u8x4, \
		u16x4: mins_u16x4, \
		u32x4: mins_u32x4, \
		u64x4: mins_u64x4 \
	)(v, s)

//
// returns a vector where each component is the maximum between that component in 'a' and that component in 'b'
#define maxG(a, b) \
	_Generic((a), \
		half: max_f16, \
		float: max_f32, \
		double: max_f64, \
		int8_t: max_s8, \
		int16_t: max_s16, \
		int32_t: max_s32, \
		int64_t: max_s64, \
		uint8_t: max_u8, \
		uint16_t: max_u16, \
		uint32_t: max_u32, \
		uint64_t: max_u64, \
		f16x2: max_f16x2, \
		f32x2: max_f32x2, \
		f64x2: max_f64x2, \
		s8x2: max_s8x2, \
		s16x2: max_s16x2, \
		s32x2: max_s32x2, \
		s64x2: max_s64x2, \
		u8x2: max_u8x2, \
		u16x2: max_u16x2, \
		u32x2: max_u32x2, \
		u64x2: max_u64x2, \
		f16x3: max_f16x3, \
		f32x3: max_f32x3, \
		f64x3: max_f64x3, \
		s8x3: max_s8x3, \
		s16x3: max_s16x3, \
		s32x3: max_s32x3, \
		s64x3: max_s64x3, \
		u8x3: max_u8x3, \
		u16x3: max_u16x3, \
		u32x3: max_u32x3, \
		u64x3: max_u64x3, \
		f16x4: max_f16x4, \
		f32x4: max_f32x4, \
		f64x4: max_f64x4, \
		s8x4: max_s8x4, \
		s16x4: max_s16x4, \
		s32x4: max_s32x4, \
		s64x4: max_s64x4, \
		u8x4: max_u8x4, \
		u16x4: max_u16x4, \
		u32x4: max_u32x4, \
		u64x4: max_u64x4 \
	)(a, b)

//
// returns a vector where each component is the maximum between that component in 'a' and 's'
#define maxsG(v, s) \
	_Generic((v), \
		f16x2: maxs_f16x2, \
		f32x2: maxs_f32x2, \
		f64x2: maxs_f64x2, \
		s8x2: maxs_s8x2, \
		s16x2: maxs_s16x2, \
		s32x2: maxs_s32x2, \
		s64x2: maxs_s64x2, \
		u8x2: maxs_u8x2, \
		u16x2: maxs_u16x2, \
		u32x2: maxs_u32x2, \
		u64x2: maxs_u64x2, \
		f16x3: maxs_f16x3, \
		f32x3: maxs_f32x3, \
		f64x3: maxs_f64x3, \
		s8x3: maxs_s8x3, \
		s16x3: maxs_s16x3, \
		s32x3: maxs_s32x3, \
		s64x3: maxs_s64x3, \
		u8x3: maxs_u8x3, \
		u16x3: maxs_u16x3, \
		u32x3: maxs_u32x3, \
		u64x3: maxs_u64x3, \
		f16x4: maxs_f16x4, \
		f32x4: maxs_f32x4, \
		f64x4: maxs_f64x4, \
		s8x4: maxs_s8x4, \
		s16x4: maxs_s16x4, \
		s32x4: maxs_s32x4, \
		s64x4: maxs_s64x4, \
		u8x4: maxs_u8x4, \
		u16x4: maxs_u16x4, \
		u32x4: maxs_u32x4, \
		u64x4: maxs_u64x4 \
	)(v, s)

//
// returns a vector where each component is clamped between the minimum value that is the component in 'min' and the maximum value that is the component in 'max'
#define clampG(v, min, max) \
	_Generic((v), \
		half: clamp_f16, \
		float: clamp_f32, \
		double: clamp_f64, \
		int8_t: clamp_s8, \
		int16_t: clamp_s16, \
		int32_t: clamp_s32, \
		int64_t: clamp_s64, \
		uint8_t: clamp_u8, \
		uint16_t: clamp_u16, \
		uint32_t: clamp_u32, \
		uint64_t: clamp_u64, \
		f16x2: clamp_f16x2, \
		f32x2: clamp_f32x2, \
		f64x2: clamp_f64x2, \
		s8x2: clamp_s8x2, \
		s16x2: clamp_s16x2, \
		s32x2: clamp_s32x2, \
		s64x2: clamp_s64x2, \
		u8x2: clamp_u8x2, \
		u16x2: clamp_u16x2, \
		u32x2: clamp_u32x2, \
		u64x2: clamp_u64x2, \
		f16x3: clamp_f16x3, \
		f32x3: clamp_f32x3, \
		f64x3: clamp_f64x3, \
		s8x3: clamp_s8x3, \
		s16x3: clamp_s16x3, \
		s32x3: clamp_s32x3, \
		s64x3: clamp_s64x3, \
		u8x3: clamp_u8x3, \
		u16x3: clamp_u16x3, \
		u32x3: clamp_u32x3, \
		u64x3: clamp_u64x3, \
		f16x4: clamp_f16x4, \
		f32x4: clamp_f32x4, \
		f64x4: clamp_f64x4, \
		s8x4: clamp_s8x4, \
		s16x4: clamp_s16x4, \
		s32x4: clamp_s32x4, \
		s64x4: clamp_s64x4, \
		u8x4: clamp_u8x4, \
		u16x4: clamp_u16x4, \
		u32x4: clamp_u32x4, \
		u64x4: clamp_u64x4 \
	)(v, min, max)

//
// returns a vector where each component is clamped between the minimum value 'min' and the maximum value 'max'
#define clampsG(v, min, max) \
	_Generic((v), \
		f16x2: clamps_f16x2, \
		f32x2: clamps_f32x2, \
		f64x2: clamps_f64x2, \
		s8x2: clamps_s8x2, \
		s16x2: clamps_s16x2, \
		s32x2: clamps_s32x2, \
		s64x2: clamps_s64x2, \
		u8x2: clamps_u8x2, \
		u16x2: clamps_u16x2, \
		u32x2: clamps_u32x2, \
		u64x2: clamps_u64x2, \
		f16x3: clamps_f16x3, \
		f32x3: clamps_f32x3, \
		f64x3: clamps_f64x3, \
		s8x3: clamps_s8x3, \
		s16x3: clamps_s16x3, \
		s32x3: clamps_s32x3, \
		s64x3: clamps_s64x3, \
		u8x3: clamps_u8x3, \
		u16x3: clamps_u16x3, \
		u32x3: clamps_u32x3, \
		u64x3: clamps_u64x3, \
		f16x4: clamps_f16x4, \
		f32x4: clamps_f32x4, \
		f64x4: clamps_f64x4, \
		s8x4: clamps_s8x4, \
		s16x4: clamps_s16x4, \
		s32x4: clamps_s32x4, \
		s64x4: clamps_s64x4, \
		u8x4: clamps_u8x4, \
		u16x4: clamps_u16x4, \
		u32x4: clamps_u32x4, \
		u64x4: clamps_u64x4 \
	)(v, min, max)

//
// returns a vector where each component is -1, 0, or 1 depending on the sign of that component that is in 'v'
#define signG(v) \
	_Generic((v), \
		half: sign_f16, \
		float: sign_f32, \
		double: sign_f64, \
		int8_t: sign_s8, \
		int16_t: sign_s16, \
		int32_t: sign_s32, \
		int64_t: sign_s64, \
		f16x2: sign_f16x2, \
		f32x2: sign_f32x2, \
		f64x2: sign_f64x2, \
		s8x2: sign_s8x2, \
		s16x2: sign_s16x2, \
		s32x2: sign_s32x2, \
		s64x2: sign_s64x2, \
		f16x3: sign_f16x3, \
		f32x3: sign_f32x3, \
		f64x3: sign_f64x3, \
		s8x3: sign_s8x3, \
		s16x3: sign_s16x3, \
		s32x3: sign_s32x3, \
		s64x3: sign_s64x3, \
		f16x4: sign_f16x4, \
		f32x4: sign_f32x4, \
		f64x4: sign_f64x4, \
		s8x4: sign_s8x4, \
		s16x4: sign_s16x4, \
		s32x4: sign_s32x4, \
		s64x4: sign_s64x4 \
	)(v)

//
// returns a vector where each component is that component in 'v' with sign of that component in 'sign'
#define copysignG(v, sign) \
	_Generic((v), \
		half: copysign_f16, \
		float: copysign_f32, \
		double: copysign_f64, \
		int8_t: copysign_s8, \
		int16_t: copysign_s16, \
		int32_t: copysign_s32, \
		int64_t: copysign_s64, \
		f16x2: copysign_f16x2, \
		f32x2: copysign_f32x2, \
		f64x2: copysign_f64x2, \
		s8x2: copysign_s8x2, \
		s16x2: copysign_s16x2, \
		s32x2: copysign_s32x2, \
		s64x2: copysign_s64x2, \
		f16x3: copysign_f16x3, \
		f32x3: copysign_f32x3, \
		f64x3: copysign_f64x3, \
		s8x3: copysign_s8x3, \
		s16x3: copysign_s16x3, \
		s32x3: copysign_s32x3, \
		s64x3: copysign_s64x3, \
		f16x4: copysign_f16x4, \
		f32x4: copysign_f32x4, \
		f64x4: copysign_f64x4, \
		s8x4: copysign_s8x4, \
		s16x4: copysign_s16x4, \
		s32x4: copysign_s32x4, \
		s64x4: copysign_s64x4 \
	)(v, sign)

//
// returns a vector where each component is that component in 'v' with sign of 'sign'
#define copysignsG(v, sign) \
	_Generic((v), \
		f16x2: copysigns_f16x2, \
		f32x2: copysigns_f32x2, \
		f64x2: copysigns_f64x2, \
		s8x2: copysigns_s8x2, \
		s16x2: copysigns_s16x2, \
		s32x2: copysigns_s32x2, \
		s64x2: copysigns_s64x2, \
		f16x3: copysigns_f16x3, \
		f32x3: copysigns_f32x3, \
		f64x3: copysigns_f64x3, \
		s8x3: copysigns_s8x3, \
		s16x3: copysigns_s16x3, \
		s32x3: copysigns_s32x3, \
		s64x3: copysigns_s64x3, \
		f16x4: copysigns_f16x4, \
		f32x4: copysigns_f32x4, \
		f64x4: copysigns_f64x4, \
		s8x4: copysigns_s8x4, \
		s16x4: copysigns_s16x4, \
		s32x4: copysigns_s32x4, \
		s64x4: copysigns_s64x4 \
	)(v, sign)

//
// returns a vector where each component is the absolute of that component in 'v'
#define absG(v) \
	_Generic((v), \
		half: abs_f16, \
		float: abs_f32, \
		double: abs_f64, \
		int8_t: abs_s8, \
		int16_t: abs_s16, \
		int32_t: abs_s32, \
		int64_t: abs_s64, \
		f16x2: abs_f16x2, \
		f32x2: abs_f32x2, \
		f64x2: abs_f64x2, \
		s8x2: abs_s8x2, \
		s16x2: abs_s16x2, \
		s32x2: abs_s32x2, \
		s64x2: abs_s64x2, \
		f16x3: abs_f16x3, \
		f32x3: abs_f32x3, \
		f64x3: abs_f64x3, \
		s8x3: abs_s8x3, \
		s16x3: abs_s16x3, \
		s32x3: abs_s32x3, \
		s64x3: abs_s64x3, \
		f16x4: abs_f16x4, \
		f32x4: abs_f32x4, \
		f64x4: abs_f64x4, \
		s8x4: abs_s8x4, \
		s16x4: abs_s16x4, \
		s32x4: abs_s32x4, \
		s64x4: abs_s64x4 \
	)(v)

//
// returns a vector where each component is the result from bitwise anding that component in 'a' to that component in 'b'
#define bitandG(a, b) \
	_Generic((a), \
		int8_t: bitand_s8, \
		int16_t: bitand_s16, \
		int32_t: bitand_s32, \
		int64_t: bitand_s64, \
		uint8_t: bitand_u8, \
		uint16_t: bitand_u16, \
		uint32_t: bitand_u32, \
		uint64_t: bitand_u64, \
		s8x2: bitand_s8x2, \
		s16x2: bitand_s16x2, \
		s32x2: bitand_s32x2, \
		s64x2: bitand_s64x2, \
		u8x2: bitand_u8x2, \
		u16x2: bitand_u16x2, \
		u32x2: bitand_u32x2, \
		u64x2: bitand_u64x2, \
		s8x3: bitand_s8x3, \
		s16x3: bitand_s16x3, \
		s32x3: bitand_s32x3, \
		s64x3: bitand_s64x3, \
		u8x3: bitand_u8x3, \
		u16x3: bitand_u16x3, \
		u32x3: bitand_u32x3, \
		u64x3: bitand_u64x3, \
		s8x4: bitand_s8x4, \
		s16x4: bitand_s16x4, \
		s32x4: bitand_s32x4, \
		s64x4: bitand_s64x4, \
		u8x4: bitand_u8x4, \
		u16x4: bitand_u16x4, \
		u32x4: bitand_u32x4, \
		u64x4: bitand_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from bitwise anding that component in 'v' to the value 's'
#define bitandsG(v, s) \
	_Generic((v), \
		s8x2: bitands_s8x2, \
		s16x2: bitands_s16x2, \
		s32x2: bitands_s32x2, \
		s64x2: bitands_s64x2, \
		u8x2: bitands_u8x2, \
		u16x2: bitands_u16x2, \
		u32x2: bitands_u32x2, \
		u64x2: bitands_u64x2, \
		s8x3: bitands_s8x3, \
		s16x3: bitands_s16x3, \
		s32x3: bitands_s32x3, \
		s64x3: bitands_s64x3, \
		u8x3: bitands_u8x3, \
		u16x3: bitands_u16x3, \
		u32x3: bitands_u32x3, \
		u64x3: bitands_u64x3, \
		s8x4: bitands_s8x4, \
		s16x4: bitands_s16x4, \
		s32x4: bitands_s32x4, \
		s64x4: bitands_s64x4, \
		u8x4: bitands_u8x4, \
		u16x4: bitands_u16x4, \
		u32x4: bitands_u32x4, \
		u64x4: bitands_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from bitwise oring that component in 'a' to that component in 'b'
#define bitorG(a, b) \
	_Generic((a), \
		int8_t: bitor_s8, \
		int16_t: bitor_s16, \
		int32_t: bitor_s32, \
		int64_t: bitor_s64, \
		uint8_t: bitor_u8, \
		uint16_t: bitor_u16, \
		uint32_t: bitor_u32, \
		uint64_t: bitor_u64, \
		s8x2: bitor_s8x2, \
		s16x2: bitor_s16x2, \
		s32x2: bitor_s32x2, \
		s64x2: bitor_s64x2, \
		u8x2: bitor_u8x2, \
		u16x2: bitor_u16x2, \
		u32x2: bitor_u32x2, \
		u64x2: bitor_u64x2, \
		s8x3: bitor_s8x3, \
		s16x3: bitor_s16x3, \
		s32x3: bitor_s32x3, \
		s64x3: bitor_s64x3, \
		u8x3: bitor_u8x3, \
		u16x3: bitor_u16x3, \
		u32x3: bitor_u32x3, \
		u64x3: bitor_u64x3, \
		s8x4: bitor_s8x4, \
		s16x4: bitor_s16x4, \
		s32x4: bitor_s32x4, \
		s64x4: bitor_s64x4, \
		u8x4: bitor_u8x4, \
		u16x4: bitor_u16x4, \
		u32x4: bitor_u32x4, \
		u64x4: bitor_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from bitwise oring that component in 'v' to the value 's'
#define bitorsG(v, s) \
	_Generic((v), \
		s8x2: bitors_s8x2, \
		s16x2: bitors_s16x2, \
		s32x2: bitors_s32x2, \
		s64x2: bitors_s64x2, \
		u8x2: bitors_u8x2, \
		u16x2: bitors_u16x2, \
		u32x2: bitors_u32x2, \
		u64x2: bitors_u64x2, \
		s8x3: bitors_s8x3, \
		s16x3: bitors_s16x3, \
		s32x3: bitors_s32x3, \
		s64x3: bitors_s64x3, \
		u8x3: bitors_u8x3, \
		u16x3: bitors_u16x3, \
		u32x3: bitors_u32x3, \
		u64x3: bitors_u64x3, \
		s8x4: bitors_s8x4, \
		s16x4: bitors_s16x4, \
		s32x4: bitors_s32x4, \
		s64x4: bitors_s64x4, \
		u8x4: bitors_u8x4, \
		u16x4: bitors_u16x4, \
		u32x4: bitors_u32x4, \
		u64x4: bitors_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from bitwise xoring that component in 'a' to that component in 'b'
#define bitxorG(a, b) \
	_Generic((a), \
		int8_t: bitxor_s8, \
		int16_t: bitxor_s16, \
		int32_t: bitxor_s32, \
		int64_t: bitxor_s64, \
		uint8_t: bitxor_u8, \
		uint16_t: bitxor_u16, \
		uint32_t: bitxor_u32, \
		uint64_t: bitxor_u64, \
		s8x2: bitxor_s8x2, \
		s16x2: bitxor_s16x2, \
		s32x2: bitxor_s32x2, \
		s64x2: bitxor_s64x2, \
		u8x2: bitxor_u8x2, \
		u16x2: bitxor_u16x2, \
		u32x2: bitxor_u32x2, \
		u64x2: bitxor_u64x2, \
		s8x3: bitxor_s8x3, \
		s16x3: bitxor_s16x3, \
		s32x3: bitxor_s32x3, \
		s64x3: bitxor_s64x3, \
		u8x3: bitxor_u8x3, \
		u16x3: bitxor_u16x3, \
		u32x3: bitxor_u32x3, \
		u64x3: bitxor_u64x3, \
		s8x4: bitxor_s8x4, \
		s16x4: bitxor_s16x4, \
		s32x4: bitxor_s32x4, \
		s64x4: bitxor_s64x4, \
		u8x4: bitxor_u8x4, \
		u16x4: bitxor_u16x4, \
		u32x4: bitxor_u32x4, \
		u64x4: bitxor_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from bitwise xoring that component in 'v' to the value 's'
#define bitxorsG(v, s) \
	_Generic((v), \
		s8x2: bitxors_s8x2, \
		s16x2: bitxors_s16x2, \
		s32x2: bitxors_s32x2, \
		s64x2: bitxors_s64x2, \
		u8x2: bitxors_u8x2, \
		u16x2: bitxors_u16x2, \
		u32x2: bitxors_u32x2, \
		u64x2: bitxors_u64x2, \
		s8x3: bitxors_s8x3, \
		s16x3: bitxors_s16x3, \
		s32x3: bitxors_s32x3, \
		s64x3: bitxors_s64x3, \
		u8x3: bitxors_u8x3, \
		u16x3: bitxors_u16x3, \
		u32x3: bitxors_u32x3, \
		u64x3: bitxors_u64x3, \
		s8x4: bitxors_s8x4, \
		s16x4: bitxors_s16x4, \
		s32x4: bitxors_s32x4, \
		s64x4: bitxors_s64x4, \
		u8x4: bitxors_u8x4, \
		u16x4: bitxors_u16x4, \
		u32x4: bitxors_u32x4, \
		u64x4: bitxors_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the left by the component in 'b'
#define bitshlG(a, b) \
	_Generic((a), \
		int8_t: bitshl_s8, \
		int16_t: bitshl_s16, \
		int32_t: bitshl_s32, \
		int64_t: bitshl_s64, \
		uint8_t: bitshl_u8, \
		uint16_t: bitshl_u16, \
		uint32_t: bitshl_u32, \
		uint64_t: bitshl_u64, \
		s8x2: bitshl_s8x2, \
		s16x2: bitshl_s16x2, \
		s32x2: bitshl_s32x2, \
		s64x2: bitshl_s64x2, \
		u8x2: bitshl_u8x2, \
		u16x2: bitshl_u16x2, \
		u32x2: bitshl_u32x2, \
		u64x2: bitshl_u64x2, \
		s8x3: bitshl_s8x3, \
		s16x3: bitshl_s16x3, \
		s32x3: bitshl_s32x3, \
		s64x3: bitshl_s64x3, \
		u8x3: bitshl_u8x3, \
		u16x3: bitshl_u16x3, \
		u32x3: bitshl_u32x3, \
		u64x3: bitshl_u64x3, \
		s8x4: bitshl_s8x4, \
		s16x4: bitshl_s16x4, \
		s32x4: bitshl_s32x4, \
		s64x4: bitshl_s64x4, \
		u8x4: bitshl_u8x4, \
		u16x4: bitshl_u16x4, \
		u32x4: bitshl_u32x4, \
		u64x4: bitshl_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the left by the value 's'
#define bitshlsG(v, s) \
	_Generic((v), \
		s8x2: bitshls_s8x2, \
		s16x2: bitshls_s16x2, \
		s32x2: bitshls_s32x2, \
		s64x2: bitshls_s64x2, \
		u8x2: bitshls_u8x2, \
		u16x2: bitshls_u16x2, \
		u32x2: bitshls_u32x2, \
		u64x2: bitshls_u64x2, \
		s8x3: bitshls_s8x3, \
		s16x3: bitshls_s16x3, \
		s32x3: bitshls_s32x3, \
		s64x3: bitshls_s64x3, \
		u8x3: bitshls_u8x3, \
		u16x3: bitshls_u16x3, \
		u32x3: bitshls_u32x3, \
		u64x3: bitshls_u64x3, \
		s8x4: bitshls_s8x4, \
		s16x4: bitshls_s16x4, \
		s32x4: bitshls_s32x4, \
		s64x4: bitshls_s64x4, \
		u8x4: bitshls_u8x4, \
		u16x4: bitshls_u16x4, \
		u32x4: bitshls_u32x4, \
		u64x4: bitshls_u64x4 \
	)(v, s)

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the right by the component in 'b'
#define bitshrG(a, b) \
	_Generic((a), \
		int8_t: bitshr_s8, \
		int16_t: bitshr_s16, \
		int32_t: bitshr_s32, \
		int64_t: bitshr_s64, \
		uint8_t: bitshr_u8, \
		uint16_t: bitshr_u16, \
		uint32_t: bitshr_u32, \
		uint64_t: bitshr_u64, \
		s8x2: bitshr_s8x2, \
		s16x2: bitshr_s16x2, \
		s32x2: bitshr_s32x2, \
		s64x2: bitshr_s64x2, \
		u8x2: bitshr_u8x2, \
		u16x2: bitshr_u16x2, \
		u32x2: bitshr_u32x2, \
		u64x2: bitshr_u64x2, \
		s8x3: bitshr_s8x3, \
		s16x3: bitshr_s16x3, \
		s32x3: bitshr_s32x3, \
		s64x3: bitshr_s64x3, \
		u8x3: bitshr_u8x3, \
		u16x3: bitshr_u16x3, \
		u32x3: bitshr_u32x3, \
		u64x3: bitshr_u64x3, \
		s8x4: bitshr_s8x4, \
		s16x4: bitshr_s16x4, \
		s32x4: bitshr_s32x4, \
		s64x4: bitshr_s64x4, \
		u8x4: bitshr_u8x4, \
		u16x4: bitshr_u16x4, \
		u32x4: bitshr_u32x4, \
		u64x4: bitshr_u64x4 \
	)(a, b)

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the right by the value 's'
#define bitshrsG(v, s) \
	_Generic((v), \
		s8x2: bitshrs_s8x2, \
		s16x2: bitshrs_s16x2, \
		s32x2: bitshrs_s32x2, \
		s64x2: bitshrs_s64x2, \
		u8x2: bitshrs_u8x2, \
		u16x2: bitshrs_u16x2, \
		u32x2: bitshrs_u32x2, \
		u64x2: bitshrs_u64x2, \
		s8x3: bitshrs_s8x3, \
		s16x3: bitshrs_s16x3, \
		s32x3: bitshrs_s32x3, \
		s64x3: bitshrs_s64x3, \
		u8x3: bitshrs_u8x3, \
		u16x3: bitshrs_u16x3, \
		u32x3: bitshrs_u32x3, \
		u64x3: bitshrs_u64x3, \
		s8x4: bitshrs_s8x4, \
		s16x4: bitshrs_s16x4, \
		s32x4: bitshrs_s32x4, \
		s64x4: bitshrs_s64x4, \
		u8x4: bitshrs_u8x4, \
		u16x4: bitshrs_u16x4, \
		u32x4: bitshrs_u32x4, \
		u64x4: bitshrs_u64x4 \
	)(v, s)

//
// returns the index of the _least_ significant bit, if 'v == 0' then 0 is returned
#define bitlsbG(v) \
	_Generic((v), \
		int8_t: bitlsb_u8, \
		int16_t: bitlsb_u16, \
		int32_t: bitlsb_u32, \
		int64_t: bitlsb_u64, \
		uint8_t: bitlsb_u8, \
		uint16_t: bitlsb_u16, \
		uint32_t: bitlsb_u32, \
		uint64_t: bitlsb_u64, \
		s8x2: bitlsb_u8x2, \
		s16x2: bitlsb_u16x2, \
		s32x2: bitlsb_u32x2, \
		s64x2: bitlsb_u64x2, \
		u8x2: bitlsb_u8x2, \
		u16x2: bitlsb_u16x2, \
		u32x2: bitlsb_u32x2, \
		u64x2: bitlsb_u64x2, \
		s8x3: bitlsb_u8x3, \
		s16x3: bitlsb_u16x3, \
		s32x3: bitlsb_u32x3, \
		s64x3: bitlsb_u64x3, \
		u8x3: bitlsb_u8x3, \
		u16x3: bitlsb_u16x3, \
		u32x3: bitlsb_u32x3, \
		u64x3: bitlsb_u64x3, \
		s8x4: bitlsb_u8x4, \
		s16x4: bitlsb_u16x4, \
		s32x4: bitlsb_u32x4, \
		s64x4: bitlsb_u64x4, \
		u8x4: bitlsb_u8x4, \
		u16x4: bitlsb_u16x4, \
		u32x4: bitlsb_u32x4, \
		u64x4: bitlsb_u64x4 \
	)(v)

//
// returns the index of the _most_ significant bit, if 'v == 0' then 0 is returned
#define bitmsbG(v) \
	_Generic((v), \
		int8_t: bitmsb_u8, \
		int16_t: bitmsb_u16, \
		int32_t: bitmsb_u32, \
		int64_t: bitmsb_u64, \
		uint8_t: bitmsb_u8, \
		uint16_t: bitmsb_u16, \
		uint32_t: bitmsb_u32, \
		uint64_t: bitmsb_u64, \
		s8x2: bitmsb_u8x2, \
		s16x2: bitmsb_u16x2, \
		s32x2: bitmsb_u32x2, \
		s64x2: bitmsb_u64x2, \
		u8x2: bitmsb_u8x2, \
		u16x2: bitmsb_u16x2, \
		u32x2: bitmsb_u32x2, \
		u64x2: bitmsb_u64x2, \
		s8x3: bitmsb_u8x3, \
		s16x3: bitmsb_u16x3, \
		s32x3: bitmsb_u32x3, \
		s64x3: bitmsb_u64x3, \
		u8x3: bitmsb_u8x3, \
		u16x3: bitmsb_u16x3, \
		u32x3: bitmsb_u32x3, \
		u64x3: bitmsb_u64x3, \
		s8x4: bitmsb_u8x4, \
		s16x4: bitmsb_u16x4, \
		s32x4: bitmsb_u32x4, \
		s64x4: bitmsb_u64x4, \
		u8x4: bitmsb_u8x4, \
		u16x4: bitmsb_u16x4, \
		u32x4: bitmsb_u32x4, \
		u64x4: bitmsb_u64x4 \
	)(v)

//
// returns a vector where each component is the result from bitwise noting that component in 'v'
#define bitnotG(v) \
	_Generic((v), \
		int8_t: bitnot_s8, \
		int16_t: bitnot_s16, \
		int32_t: bitnot_s32, \
		int64_t: bitnot_s64, \
		uint8_t: bitnot_u8, \
		uint16_t: bitnot_u16, \
		uint32_t: bitnot_u32, \
		uint64_t: bitnot_u64, \
		s8x2: bitnot_s8x2, \
		s16x2: bitnot_s16x2, \
		s32x2: bitnot_s32x2, \
		s64x2: bitnot_s64x2, \
		u8x2: bitnot_u8x2, \
		u16x2: bitnot_u16x2, \
		u32x2: bitnot_u32x2, \
		u64x2: bitnot_u64x2, \
		s8x3: bitnot_s8x3, \
		s16x3: bitnot_s16x3, \
		s32x3: bitnot_s32x3, \
		s64x3: bitnot_s64x3, \
		u8x3: bitnot_u8x3, \
		u16x3: bitnot_u16x3, \
		u32x3: bitnot_u32x3, \
		u64x3: bitnot_u64x3, \
		s8x4: bitnot_s8x4, \
		s16x4: bitnot_s16x4, \
		s32x4: bitnot_s32x4, \
		s64x4: bitnot_s64x4, \
		u8x4: bitnot_u8x4, \
		u16x4: bitnot_u16x4, \
		u32x4: bitnot_u32x4, \
		u64x4: bitnot_u64x4 \
	)(v)

//
// returns a vector where each component (x) is calculated like so x = (a.x * b.x) + c.x
#define fmaG(a, b, c) \
	_Generic((a), \
		half: fma_f16, \
		float: fma_f32, \
		double: fma_f64, \
		f16x2: fma_f16x2, \
		f32x2: fma_f32x2, \
		f64x2: fma_f64x2, \
		f16x3: fma_f16x3, \
		f32x3: fma_f32x3, \
		f64x3: fma_f64x3, \
		f16x4: fma_f16x4, \
		f32x4: fma_f32x4, \
		f64x4: fma_f64x4 \
	)(a, b, c)

//
// returns a vector where each component (x) is calculated like so x = (a.x * b.x) + c
#define fmasG(a, b, c) \
	_Generic((a), \
		f16x2: fmas_f16x2, \
		f32x2: fmas_f32x2, \
		f64x2: fmas_f64x2, \
		f16x3: fmas_f16x3, \
		f32x3: fmas_f32x3, \
		f64x3: fmas_f64x3, \
		f16x4: fmas_f16x4, \
		f32x4: fmas_f32x4, \
		f64x4: fmas_f64x4 \
	)(a, b, c)

//
// returns a vector where each component (x) is calculated like so x = (a.x * b) + c
#define fmassG(a, b, c) \
	_Generic((a), \
		f16x2: fmass_f16x2, \
		f32x2: fmass_f32x2, \
		f64x2: fmass_f64x2, \
		f16x3: fmass_f16x3, \
		f32x3: fmass_f32x3, \
		f64x3: fmass_f64x3, \
		f16x4: fmass_f16x4, \
		f32x4: fmass_f32x4, \
		f64x4: fmass_f64x4 \
	)(a, b, c)

//
// return a vector where each component is the result of appling 'floor' to that component in 'v'
#define floorG(v) \
	_Generic((v), \
		half: floor_f16, \
		float: floor_f32, \
		double: floor_f64, \
		f16x2: floor_f16x2, \
		f32x2: floor_f32x2, \
		f64x2: floor_f64x2, \
		f16x3: floor_f16x3, \
		f32x3: floor_f32x3, \
		f64x3: floor_f64x3, \
		f16x4: floor_f16x4, \
		f32x4: floor_f32x4, \
		f64x4: floor_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'ceil' to that component in 'v'
#define ceilG(v) \
	_Generic((v), \
		half: ceil_f16, \
		float: ceil_f32, \
		double: ceil_f64, \
		f16x2: ceil_f16x2, \
		f32x2: ceil_f32x2, \
		f64x2: ceil_f64x2, \
		f16x3: ceil_f16x3, \
		f32x3: ceil_f32x3, \
		f64x3: ceil_f64x3, \
		f16x4: ceil_f16x4, \
		f32x4: ceil_f32x4, \
		f64x4: ceil_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'round' to that component in 'v'
#define roundG(v) \
	_Generic((v), \
		half: round_f16, \
		float: round_f32, \
		double: round_f64, \
		f16x2: round_f16x2, \
		f32x2: round_f32x2, \
		f64x2: round_f64x2, \
		f16x3: round_f16x3, \
		f32x3: round_f32x3, \
		f64x3: round_f64x3, \
		f16x4: round_f16x4, \
		f32x4: round_f32x4, \
		f64x4: round_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'trunc' to that component in 'v'
#define truncG(v) \
	_Generic((v), \
		half: trunc_f16, \
		float: trunc_f32, \
		double: trunc_f64, \
		f16x2: trunc_f16x2, \
		f32x2: trunc_f32x2, \
		f64x2: trunc_f64x2, \
		f16x3: trunc_f16x3, \
		f32x3: trunc_f32x3, \
		f64x3: trunc_f64x3, \
		f16x4: trunc_f16x4, \
		f32x4: trunc_f32x4, \
		f64x4: trunc_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'fract' to that component in 'v'
#define fractG(v) \
	_Generic((v), \
		half: fract_f16, \
		float: fract_f32, \
		double: fract_f64, \
		f16x2: fract_f16x2, \
		f32x2: fract_f32x2, \
		f64x2: fract_f64x2, \
		f16x3: fract_f16x3, \
		f32x3: fract_f32x3, \
		f64x3: fract_f64x3, \
		f16x4: fract_f16x4, \
		f32x4: fract_f32x4, \
		f64x4: fract_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'radians' to that component in 'v'
#define radiansG(v) \
	_Generic((v), \
		half: radians_f16, \
		float: radians_f32, \
		double: radians_f64, \
		f16x2: radians_f16x2, \
		f32x2: radians_f32x2, \
		f64x2: radians_f64x2, \
		f16x3: radians_f16x3, \
		f32x3: radians_f32x3, \
		f64x3: radians_f64x3, \
		f16x4: radians_f16x4, \
		f32x4: radians_f32x4, \
		f64x4: radians_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'degrees' to that component in 'v'
#define degreesG(v) \
	_Generic((v), \
		half: degrees_f16, \
		float: degrees_f32, \
		double: degrees_f64, \
		f16x2: degrees_f16x2, \
		f32x2: degrees_f32x2, \
		f64x2: degrees_f64x2, \
		f16x3: degrees_f16x3, \
		f32x3: degrees_f32x3, \
		f64x3: degrees_f64x3, \
		f16x4: degrees_f16x4, \
		f32x4: degrees_f32x4, \
		f64x4: degrees_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'step' to that component in 'v'
#define stepG(v, edge) \
	_Generic((v), \
		half: step_f16, \
		float: step_f32, \
		double: step_f64, \
		f16x2: step_f16x2, \
		f32x2: step_f32x2, \
		f64x2: step_f64x2, \
		f16x3: step_f16x3, \
		f32x3: step_f32x3, \
		f64x3: step_f64x3, \
		f16x4: step_f16x4, \
		f32x4: step_f32x4, \
		f64x4: step_f64x4 \
	)(v, edge)

//
// return a vector where each component is the result of appling 'step' to that component in 'v'
#define stepsG(v, edge) \
	_Generic((v), \
		f16x2: steps_f16x2, \
		f32x2: steps_f32x2, \
		f64x2: steps_f64x2, \
		f16x3: steps_f16x3, \
		f32x3: steps_f32x3, \
		f64x3: steps_f64x3, \
		f16x4: steps_f16x4, \
		f32x4: steps_f32x4, \
		f64x4: steps_f64x4 \
	)(v, edge)

//
// return a vector where each component is the result of appling 'smoothstep' to that component in 'v'
#define smoothstepG(edge0, edge1, v) \
	_Generic((edge0), \
		half: smoothstep_f16, \
		float: smoothstep_f32, \
		double: smoothstep_f64, \
		f16x2: smoothstep_f16x2, \
		f32x2: smoothstep_f32x2, \
		f64x2: smoothstep_f64x2, \
		f16x3: smoothstep_f16x3, \
		f32x3: smoothstep_f32x3, \
		f64x3: smoothstep_f64x3, \
		f16x4: smoothstep_f16x4, \
		f32x4: smoothstep_f32x4, \
		f64x4: smoothstep_f64x4 \
	)(edge0, edge1, v)

//
// return a vector where each component is the result of appling 'smoothstep' to that component in 'v'
#define smoothstepsG(edge0, edge1, v) \
	_Generic((edge0), \
		f16x2: smoothsteps_f16x2, \
		f32x2: smoothsteps_f32x2, \
		f64x2: smoothsteps_f64x2, \
		f16x3: smoothsteps_f16x3, \
		f32x3: smoothsteps_f32x3, \
		f64x3: smoothsteps_f64x3, \
		f16x4: smoothsteps_f16x4, \
		f32x4: smoothsteps_f32x4, \
		f64x4: smoothsteps_f64x4 \
	)(edge0, edge1, v)

//
// return a vector where each component is the result of appling 'smoothstep' to that component in 'v'
#define smoothstepssG(edge0, edge1, v) \
	_Generic((edge0), \
		f16x2: smoothstepss_f16x2, \
		f32x2: smoothstepss_f32x2, \
		f64x2: smoothstepss_f64x2, \
		f16x3: smoothstepss_f16x3, \
		f32x3: smoothstepss_f32x3, \
		f64x3: smoothstepss_f64x3, \
		f16x4: smoothstepss_f16x4, \
		f32x4: smoothstepss_f32x4, \
		f64x4: smoothstepss_f64x4 \
	)(edge0, edge1, v)

//
// return a vector where each component is the result of appling 'remap' to that component in 'v', 'from_min', 'from_max', 'to_min' and 'to_max'
#define remapG(v, from_min, from_max, to_min, to_max) \
	_Generic((v), \
		half: remap_f16, \
		float: remap_f32, \
		double: remap_f64, \
		f16x2: remap_f16x2, \
		f32x2: remap_f32x2, \
		f64x2: remap_f64x2, \
		f16x3: remap_f16x3, \
		f32x3: remap_f32x3, \
		f64x3: remap_f64x3, \
		f16x4: remap_f16x4, \
		f32x4: remap_f32x4, \
		f64x4: remap_f64x4 \
	)(v, from_min, from_max, to_min, to_max)

//
// return a vector where each component is the result of appling 'remap' to that component in 'v' with scalar 'from_min', 'from_max', 'to_min' and 'to_max'
#define remapsG(v, from_min, from_max, to_min, to_max) \
	_Generic((v), \
		f16x2: remaps_f16x2, \
		f32x2: remaps_f32x2, \
		f64x2: remaps_f64x2, \
		f16x3: remaps_f16x3, \
		f32x3: remaps_f32x3, \
		f64x3: remaps_f64x3, \
		f16x4: remaps_f16x4, \
		f32x4: remaps_f32x4, \
		f64x4: remaps_f64x4 \
	)(v, from_min, from_max, to_min, to_max)

//
// return a vector where each component is the result of appling 'roundtomultiple' to that component in 'v' and 'multiple'
#define roundtomultipleG(a, b) \
	_Generic((a), \
		half: roundtomultiple_f16, \
		float: roundtomultiple_f32, \
		double: roundtomultiple_f64, \
		f16x2: roundtomultiple_f16x2, \
		f32x2: roundtomultiple_f32x2, \
		f64x2: roundtomultiple_f64x2, \
		f16x3: roundtomultiple_f16x3, \
		f32x3: roundtomultiple_f32x3, \
		f64x3: roundtomultiple_f64x3, \
		f16x4: roundtomultiple_f16x4, \
		f32x4: roundtomultiple_f32x4, \
		f64x4: roundtomultiple_f64x4 \
	)(a, b)

//
// return a vector where each component is the result of appling 'roundtomultiple' to that component in 'v' with scalar 'multiple'
#define roundtomultiplesG(v, s) \
	_Generic((v), \
		f16x2: roundtomultiples_f16x2, \
		f32x2: roundtomultiples_f32x2, \
		f64x2: roundtomultiples_f64x2, \
		f16x3: roundtomultiples_f16x3, \
		f32x3: roundtomultiples_f32x3, \
		f64x3: roundtomultiples_f64x3, \
		f16x4: roundtomultiples_f16x4, \
		f32x4: roundtomultiples_f32x4, \
		f64x4: roundtomultiples_f64x4 \
	)(v, s)

//
// return a vector where each component is the result of appling 'rounduptomultiple' to that component in 'v' and 'multiple'
#define rounduptomultipleG(a, b) \
	_Generic((a), \
		half: rounduptomultiple_f16, \
		float: rounduptomultiple_f32, \
		double: rounduptomultiple_f64, \
		f16x2: rounduptomultiple_f16x2, \
		f32x2: rounduptomultiple_f32x2, \
		f64x2: rounduptomultiple_f64x2, \
		f16x3: rounduptomultiple_f16x3, \
		f32x3: rounduptomultiple_f32x3, \
		f64x3: rounduptomultiple_f64x3, \
		f16x4: rounduptomultiple_f16x4, \
		f32x4: rounduptomultiple_f32x4, \
		f64x4: rounduptomultiple_f64x4 \
	)(a, b)

//
// return a vector where each component is the result of appling 'rounduptomultiple' to that component in 'v' with scalar 'multiple'
#define rounduptomultiplesG(v, s) \
	_Generic((v), \
		f16x2: rounduptomultiples_f16x2, \
		f32x2: rounduptomultiples_f32x2, \
		f64x2: rounduptomultiples_f64x2, \
		f16x3: rounduptomultiples_f16x3, \
		f32x3: rounduptomultiples_f32x3, \
		f64x3: rounduptomultiples_f64x3, \
		f16x4: rounduptomultiples_f16x4, \
		f32x4: rounduptomultiples_f32x4, \
		f64x4: rounduptomultiples_f64x4 \
	)(v, s)

//
// return a vector where each component is the result of appling 'rounddowntomultiple' to that component in 'v' and 'multiple'
#define rounddowntomultipleG(a, b) \
	_Generic((a), \
		half: rounddowntomultiple_f16, \
		float: rounddowntomultiple_f32, \
		double: rounddowntomultiple_f64, \
		f16x2: rounddowntomultiple_f16x2, \
		f32x2: rounddowntomultiple_f32x2, \
		f64x2: rounddowntomultiple_f64x2, \
		f16x3: rounddowntomultiple_f16x3, \
		f32x3: rounddowntomultiple_f32x3, \
		f64x3: rounddowntomultiple_f64x3, \
		f16x4: rounddowntomultiple_f16x4, \
		f32x4: rounddowntomultiple_f32x4, \
		f64x4: rounddowntomultiple_f64x4 \
	)(a, b)

//
// return a vector where each component is the result of appling 'rounddowntomultiple' to that component in 'v' with scalar 'multiple'
#define rounddowntomultiplesG(v, s) \
	_Generic((v), \
		f16x2: rounddowntomultiples_f16x2, \
		f32x2: rounddowntomultiples_f32x2, \
		f64x2: rounddowntomultiples_f64x2, \
		f16x3: rounddowntomultiples_f16x3, \
		f32x3: rounddowntomultiples_f32x3, \
		f64x3: rounddowntomultiples_f64x3, \
		f16x4: rounddowntomultiples_f16x4, \
		f32x4: rounddowntomultiples_f32x4, \
		f64x4: rounddowntomultiples_f64x4 \
	)(v, s)

//
// return a vector where each component is the result of appling 'bitsto' to that component in 'v'
#define bitstoG(v) \
	_Generic((v), \
		half: bitsto_f16, \
		float: bitsto_f32, \
		double: bitsto_f64, \
		s16x2: bitsto_f16x2, \
		s32x2: bitsto_f32x2, \
		s64x2: bitsto_f64x2, \
		s16x3: bitsto_f16x3, \
		s32x3: bitsto_f32x3, \
		s64x3: bitsto_f64x3, \
		s16x4: bitsto_f16x4, \
		s32x4: bitsto_f32x4, \
		s64x4: bitsto_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'bitsfrom' to that component in 'v'
#define bitsfromG(v) \
	_Generic((v), \
		half: bitsfrom_f16, \
		float: bitsfrom_f32, \
		double: bitsfrom_f64, \
		f16x2: bitsfrom_f16x2, \
		f32x2: bitsfrom_f32x2, \
		f64x2: bitsfrom_f64x2, \
		f16x3: bitsfrom_f16x3, \
		f32x3: bitsfrom_f32x3, \
		f64x3: bitsfrom_f64x3, \
		f16x4: bitsfrom_f16x4, \
		f32x4: bitsfrom_f32x4, \
		f64x4: bitsfrom_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'sin' to that component in 'v'
#define sinG(v) \
	_Generic((v), \
		half: sin_f16, \
		float: sin_f32, \
		double: sin_f64, \
		f16x2: sin_f16x2, \
		f32x2: sin_f32x2, \
		f64x2: sin_f64x2, \
		f16x3: sin_f16x3, \
		f32x3: sin_f32x3, \
		f64x3: sin_f64x3, \
		f16x4: sin_f16x4, \
		f32x4: sin_f32x4, \
		f64x4: sin_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'cos' to that component in 'v'
#define cosG(v) \
	_Generic((v), \
		half: cos_f16, \
		float: cos_f32, \
		double: cos_f64, \
		f16x2: cos_f16x2, \
		f32x2: cos_f32x2, \
		f64x2: cos_f64x2, \
		f16x3: cos_f16x3, \
		f32x3: cos_f32x3, \
		f64x3: cos_f64x3, \
		f16x4: cos_f16x4, \
		f32x4: cos_f32x4, \
		f64x4: cos_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'tan' to that component in 'v'
#define tanG(v) \
	_Generic((v), \
		half: tan_f16, \
		float: tan_f32, \
		double: tan_f64, \
		f16x2: tan_f16x2, \
		f32x2: tan_f32x2, \
		f64x2: tan_f64x2, \
		f16x3: tan_f16x3, \
		f32x3: tan_f32x3, \
		f64x3: tan_f64x3, \
		f16x4: tan_f16x4, \
		f32x4: tan_f32x4, \
		f64x4: tan_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'asin' to that component in 'v'
#define asinG(v) \
	_Generic((v), \
		half: asin_f16, \
		float: asin_f32, \
		double: asin_f64, \
		f16x2: asin_f16x2, \
		f32x2: asin_f32x2, \
		f64x2: asin_f64x2, \
		f16x3: asin_f16x3, \
		f32x3: asin_f32x3, \
		f64x3: asin_f64x3, \
		f16x4: asin_f16x4, \
		f32x4: asin_f32x4, \
		f64x4: asin_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'acos' to that component in 'v'
#define acosG(v) \
	_Generic((v), \
		half: acos_f16, \
		float: acos_f32, \
		double: acos_f64, \
		f16x2: acos_f16x2, \
		f32x2: acos_f32x2, \
		f64x2: acos_f64x2, \
		f16x3: acos_f16x3, \
		f32x3: acos_f32x3, \
		f64x3: acos_f64x3, \
		f16x4: acos_f16x4, \
		f32x4: acos_f32x4, \
		f64x4: acos_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'atan' to that component in 'v'
#define atanG(v) \
	_Generic((v), \
		half: atan_f16, \
		float: atan_f32, \
		double: atan_f64, \
		f16x2: atan_f16x2, \
		f32x2: atan_f32x2, \
		f64x2: atan_f64x2, \
		f16x3: atan_f16x3, \
		f32x3: atan_f32x3, \
		f64x3: atan_f64x3, \
		f16x4: atan_f16x4, \
		f32x4: atan_f32x4, \
		f64x4: atan_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'sinh' to that component in 'v'
#define sinhG(v) \
	_Generic((v), \
		half: sinh_f16, \
		float: sinh_f32, \
		double: sinh_f64, \
		f16x2: sinh_f16x2, \
		f32x2: sinh_f32x2, \
		f64x2: sinh_f64x2, \
		f16x3: sinh_f16x3, \
		f32x3: sinh_f32x3, \
		f64x3: sinh_f64x3, \
		f16x4: sinh_f16x4, \
		f32x4: sinh_f32x4, \
		f64x4: sinh_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'cosh' to that component in 'v'
#define coshG(v) \
	_Generic((v), \
		half: cosh_f16, \
		float: cosh_f32, \
		double: cosh_f64, \
		f16x2: cosh_f16x2, \
		f32x2: cosh_f32x2, \
		f64x2: cosh_f64x2, \
		f16x3: cosh_f16x3, \
		f32x3: cosh_f32x3, \
		f64x3: cosh_f64x3, \
		f16x4: cosh_f16x4, \
		f32x4: cosh_f32x4, \
		f64x4: cosh_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'tanh' to that component in 'v'
#define tanhG(v) \
	_Generic((v), \
		half: tanh_f16, \
		float: tanh_f32, \
		double: tanh_f64, \
		f16x2: tanh_f16x2, \
		f32x2: tanh_f32x2, \
		f64x2: tanh_f64x2, \
		f16x3: tanh_f16x3, \
		f32x3: tanh_f32x3, \
		f64x3: tanh_f64x3, \
		f16x4: tanh_f16x4, \
		f32x4: tanh_f32x4, \
		f64x4: tanh_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'asinh' to that component in 'v'
#define asinhG(v) \
	_Generic((v), \
		half: asinh_f16, \
		float: asinh_f32, \
		double: asinh_f64, \
		f16x2: asinh_f16x2, \
		f32x2: asinh_f32x2, \
		f64x2: asinh_f64x2, \
		f16x3: asinh_f16x3, \
		f32x3: asinh_f32x3, \
		f64x3: asinh_f64x3, \
		f16x4: asinh_f16x4, \
		f32x4: asinh_f32x4, \
		f64x4: asinh_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'acosh' to that component in 'v'
#define acoshG(v) \
	_Generic((v), \
		half: acosh_f16, \
		float: acosh_f32, \
		double: acosh_f64, \
		f16x2: acosh_f16x2, \
		f32x2: acosh_f32x2, \
		f64x2: acosh_f64x2, \
		f16x3: acosh_f16x3, \
		f32x3: acosh_f32x3, \
		f64x3: acosh_f64x3, \
		f16x4: acosh_f16x4, \
		f32x4: acosh_f32x4, \
		f64x4: acosh_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'atanh' to that component in 'v'
#define atanhG(v) \
	_Generic((v), \
		half: atanh_f16, \
		float: atanh_f32, \
		double: atanh_f64, \
		f16x2: atanh_f16x2, \
		f32x2: atanh_f32x2, \
		f64x2: atanh_f64x2, \
		f16x3: atanh_f16x3, \
		f32x3: atanh_f32x3, \
		f64x3: atanh_f64x3, \
		f16x4: atanh_f16x4, \
		f32x4: atanh_f32x4, \
		f64x4: atanh_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'atan2' to that component in 'v'
#define atan2G(y, x) \
	_Generic((y), \
		half: atan2_f16, \
		float: atan2_f32, \
		double: atan2_f64, \
		f16x2: atan2_f16x2, \
		f32x2: atan2_f32x2, \
		f64x2: atan2_f64x2, \
		f16x3: atan2_f16x3, \
		f32x3: atan2_f32x3, \
		f64x3: atan2_f64x3, \
		f16x4: atan2_f16x4, \
		f32x4: atan2_f32x4, \
		f64x4: atan2_f64x4 \
	)(y, x)

//
// return a vector where each component is the result of appling 'pow' to that component in 'v'
#define powG(a, b) \
	_Generic((a), \
		half: pow_f16, \
		float: pow_f32, \
		double: pow_f64, \
		f16x2: pow_f16x2, \
		f32x2: pow_f32x2, \
		f64x2: pow_f64x2, \
		f16x3: pow_f16x3, \
		f32x3: pow_f32x3, \
		f64x3: pow_f64x3, \
		f16x4: pow_f16x4, \
		f32x4: pow_f32x4, \
		f64x4: pow_f64x4 \
	)(a, b)

//
// return a vector where each component is the result of appling 'exp' to that component in 'v'
#define expG(v) \
	_Generic((v), \
		half: exp_f16, \
		float: exp_f32, \
		double: exp_f64, \
		f16x2: exp_f16x2, \
		f32x2: exp_f32x2, \
		f64x2: exp_f64x2, \
		f16x3: exp_f16x3, \
		f32x3: exp_f32x3, \
		f64x3: exp_f64x3, \
		f16x4: exp_f16x4, \
		f32x4: exp_f32x4, \
		f64x4: exp_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'log' to that component in 'v'
#define logG(v) \
	_Generic((v), \
		half: log_f16, \
		float: log_f32, \
		double: log_f64, \
		f16x2: log_f16x2, \
		f32x2: log_f32x2, \
		f64x2: log_f64x2, \
		f16x3: log_f16x3, \
		f32x3: log_f32x3, \
		f64x3: log_f64x3, \
		f16x4: log_f16x4, \
		f32x4: log_f32x4, \
		f64x4: log_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'exp2' to that component in 'v'
#define exp2G(v) \
	_Generic((v), \
		half: exp2_f16, \
		float: exp2_f32, \
		double: exp2_f64, \
		f16x2: exp2_f16x2, \
		f32x2: exp2_f32x2, \
		f64x2: exp2_f64x2, \
		f16x3: exp2_f16x3, \
		f32x3: exp2_f32x3, \
		f64x3: exp2_f64x3, \
		f16x4: exp2_f16x4, \
		f32x4: exp2_f32x4, \
		f64x4: exp2_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'log2' to that component in 'v'
#define log2G(v) \
	_Generic((v), \
		half: log2_f16, \
		float: log2_f32, \
		double: log2_f64, \
		f16x2: log2_f16x2, \
		f32x2: log2_f32x2, \
		f64x2: log2_f64x2, \
		f16x3: log2_f16x3, \
		f32x3: log2_f32x3, \
		f64x3: log2_f64x3, \
		f16x4: log2_f16x4, \
		f32x4: log2_f32x4, \
		f64x4: log2_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'sqrt' to that component in 'v'
#define sqrtG(v) \
	_Generic((v), \
		half: sqrt_f16, \
		float: sqrt_f32, \
		double: sqrt_f64, \
		f16x2: sqrt_f16x2, \
		f32x2: sqrt_f32x2, \
		f64x2: sqrt_f64x2, \
		f16x3: sqrt_f16x3, \
		f32x3: sqrt_f32x3, \
		f64x3: sqrt_f64x3, \
		f16x4: sqrt_f16x4, \
		f32x4: sqrt_f32x4, \
		f64x4: sqrt_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'rsqrt' to that component in 'v'
#define rsqrtG(v) \
	_Generic((v), \
		half: rsqrt_f16, \
		float: rsqrt_f32, \
		double: rsqrt_f64, \
		f16x2: rsqrt_f16x2, \
		f32x2: rsqrt_f32x2, \
		f64x2: rsqrt_f64x2, \
		f16x3: rsqrt_f16x3, \
		f32x3: rsqrt_f32x3, \
		f64x3: rsqrt_f64x3, \
		f16x4: rsqrt_f16x4, \
		f32x4: rsqrt_f32x4, \
		f64x4: rsqrt_f64x4 \
	)(v)

//
// returns true if each component in 'a' is 'epsilon' away from that component that is in 'b'
#define approxeqG(a, b, epsilon) \
	_Generic((a), \
		half: approxeq_f16, \
		float: approxeq_f32, \
		double: approxeq_f64, \
		f16x2: approxeq_f16x2, \
		f32x2: approxeq_f32x2, \
		f64x2: approxeq_f64x2, \
		f16x3: approxeq_f16x3, \
		f32x3: approxeq_f32x3, \
		f64x3: approxeq_f64x3, \
		f16x4: approxeq_f16x4, \
		f32x4: approxeq_f32x4, \
		f64x4: approxeq_f64x4 \
	)(a, b, epsilon)

//
// returns true if each component in 'v' is 'epsilon' away from 's'
#define approxeqsG(v, s, epsilon) \
	_Generic((v), \
		f16x2: approxeqs_f16x2, \
		f32x2: approxeqs_f32x2, \
		f64x2: approxeqs_f64x2, \
		f16x3: approxeqs_f16x3, \
		f32x3: approxeqs_f32x3, \
		f64x3: approxeqs_f64x3, \
		f16x4: approxeqs_f16x4, \
		f32x4: approxeqs_f32x4, \
		f64x4: approxeqs_f64x4 \
	)(v, s, epsilon)

//
// return a vector where each component is the result of appling 'isinf' to that component in 'v'
#define isinfG(v) \
	_Generic((v), \
		half: isinf_f16, \
		float: isinf_f32, \
		double: isinf_f64, \
		f16x2: isinf_f16x2, \
		f32x2: isinf_f32x2, \
		f64x2: isinf_f64x2, \
		f16x3: isinf_f16x3, \
		f32x3: isinf_f32x3, \
		f64x3: isinf_f64x3, \
		f16x4: isinf_f16x4, \
		f32x4: isinf_f32x4, \
		f64x4: isinf_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'isnan' to that component in 'v'
#define isnanG(v) \
	_Generic((v), \
		half: isnan_f16, \
		float: isnan_f32, \
		double: isnan_f64, \
		f16x2: isnan_f16x2, \
		f32x2: isnan_f32x2, \
		f64x2: isnan_f64x2, \
		f16x3: isnan_f16x3, \
		f32x3: isnan_f32x3, \
		f64x3: isnan_f64x3, \
		f16x4: isnan_f16x4, \
		f32x4: isnan_f32x4, \
		f64x4: isnan_f64x4 \
	)(v)

//
// return a vector where each component is the result of appling 'lerp' to that component in 'start', 'end' and 't'
#define lerpG(start, end, t) \
	_Generic((start), \
		half: lerp_f16, \
		float: lerp_f32, \
		double: lerp_f64, \
		f16x2: lerp_f16x2, \
		f32x2: lerp_f32x2, \
		f64x2: lerp_f64x2, \
		f16x3: lerp_f16x3, \
		f32x3: lerp_f32x3, \
		f64x3: lerp_f64x3, \
		f16x4: lerp_f16x4, \
		f32x4: lerp_f32x4, \
		f64x4: lerp_f64x4 \
	)(start, end, t)

//
// return a vector where each component is the result of appling 'lerp' to that component in 'start', 'end' and scalar 't'
#define lerpsG(start, end, t) \
	_Generic((start), \
		half: lerps_f16, \
		float: lerps_f32, \
		double: lerps_f64, \
		f16x2: lerps_f16x2, \
		f32x2: lerps_f32x2, \
		f64x2: lerps_f64x2, \
		f16x3: lerps_f16x3, \
		f32x3: lerps_f32x3, \
		f64x3: lerps_f64x3, \
		f16x4: lerps_f16x4, \
		f32x4: lerps_f32x4, \
		f64x4: lerps_f64x4 \
	)(start, end, t)

//
// return a vector where each component is the result of appling 'invlerp' to that component in 'start', 'end' and 't'
#define invlerpG(start, end, v) \
	_Generic((start), \
		half: invlerp_f16, \
		float: invlerp_f32, \
		double: invlerp_f64, \
		f16x2: invlerp_f16x2, \
		f32x2: invlerp_f32x2, \
		f64x2: invlerp_f64x2, \
		f16x3: invlerp_f16x3, \
		f32x3: invlerp_f32x3, \
		f64x3: invlerp_f64x3, \
		f16x4: invlerp_f16x4, \
		f32x4: invlerp_f32x4, \
		f64x4: invlerp_f64x4 \
	)(start, end, v)

//
// return a vector where each component is the result of appling 'invlerp' to that component in 'start', 'end' and scalar 't'
#define invlerpsG(start, end, v) \
	_Generic((start), \
		half: invlerps_f16, \
		float: invlerps_f32, \
		double: invlerps_f64, \
		f16x2: invlerps_f16x2, \
		f32x2: invlerps_f32x2, \
		f64x2: invlerps_f64x2, \
		f16x3: invlerps_f16x3, \
		f32x3: invlerps_f32x3, \
		f64x3: invlerps_f64x3, \
		f16x4: invlerps_f16x4, \
		f32x4: invlerps_f32x4, \
		f64x4: invlerps_f64x4 \
	)(start, end, v)

//
// returns a vector which is the cross product of 'a' and 'b'
#define crossG(a, b) \
	_Generic((a), \
		f16x2: cross_f16x2, \
		f32x2: cross_f32x2, \
		f64x2: cross_f64x2, \
		f16x3: cross_f16x3, \
		f32x3: cross_f32x3, \
		f64x3: cross_f64x3 \
	)(a, b)

//
// returns a vector which is the dot product of 'a' and 'b'
#define dotG(a, b) \
	_Generic((a), \
		f16x2: dot_f16x2, \
		f32x2: dot_f32x2, \
		f64x2: dot_f64x2, \
		f16x3: dot_f16x3, \
		f32x3: dot_f32x3, \
		f64x3: dot_f64x3, \
		f16x4: dot_f16x4, \
		f32x4: dot_f32x4, \
		f64x4: dot_f64x4 \
	)(a, b)

//
// returns a euclidean length of the vector 'v' aka. L2 norm
#define lenG(v) \
	_Generic((v), \
		f16x2: len_f16x2, \
		f32x2: len_f32x2, \
		f64x2: len_f64x2, \
		f16x3: len_f16x3, \
		f32x3: len_f32x3, \
		f64x3: len_f64x3, \
		f16x4: len_f16x4, \
		f32x4: len_f32x4, \
		f64x4: len_f64x4 \
	)(v)

//
// returns the squared euclidean length of the vector 'v', this avoids doing the square root. useful when you want to compare of one length is less than another vector length without paying the cost of a sqrt instruction
#define lensqG(v) \
	_Generic((v), \
		f16x2: lensq_f16x2, \
		f32x2: lensq_f32x2, \
		f64x2: lensq_f64x2, \
		s8x2: lensq_s8x2, \
		s16x2: lensq_s16x2, \
		s32x2: lensq_s32x2, \
		s64x2: lensq_s64x2, \
		u8x2: lensq_u8x2, \
		u16x2: lensq_u16x2, \
		u32x2: lensq_u32x2, \
		u64x2: lensq_u64x2, \
		f16x3: lensq_f16x3, \
		f32x3: lensq_f32x3, \
		f64x3: lensq_f64x3, \
		s8x3: lensq_s8x3, \
		s16x3: lensq_s16x3, \
		s32x3: lensq_s32x3, \
		s64x3: lensq_s64x3, \
		u8x3: lensq_u8x3, \
		u16x3: lensq_u16x3, \
		u32x3: lensq_u32x3, \
		u64x3: lensq_u64x3, \
		f16x4: lensq_f16x4, \
		f32x4: lensq_f32x4, \
		f64x4: lensq_f64x4, \
		s8x4: lensq_s8x4, \
		s16x4: lensq_s16x4, \
		s32x4: lensq_s32x4, \
		s64x4: lensq_s64x4, \
		u8x4: lensq_u8x4, \
		u16x4: lensq_u16x4, \
		u32x4: lensq_u32x4, \
		u64x4: lensq_u64x4 \
	)(v)

//
// returns a version of 'v' where the magnatude is a unit length of 1.f
#define normG(v) \
	_Generic((v), \
		f16x2: norm_f16x2, \
		f32x2: norm_f32x2, \
		f64x2: norm_f64x2, \
		f16x3: norm_f16x3, \
		f32x3: norm_f32x3, \
		f64x3: norm_f64x3, \
		f16x4: norm_f16x4, \
		f32x4: norm_f32x4, \
		f64x4: norm_f64x4 \
	)(v)

//
// returns a vector that is vector 'v' reflected against surface 'normal'
#define reflectG(v, normal) \
	_Generic((v), \
		f16x2: reflect_f16x2, \
		f32x2: reflect_f32x2, \
		f64x2: reflect_f64x2, \
		f16x3: reflect_f16x3, \
		f32x3: reflect_f32x3, \
		f64x3: reflect_f64x3, \
		f16x4: reflect_f16x4, \
		f32x4: reflect_f32x4, \
		f64x4: reflect_f64x4 \
	)(v, normal)

//
// returns the refraction vector for vector 'v' against surface 'normal' with the ratio 'eta'
#define refractG(v, normal, eta) \
	_Generic((v), \
		f16x2: refract_f16x2, \
		f32x2: refract_f32x2, \
		f64x2: refract_f64x2, \
		f16x3: refract_f16x3, \
		f32x3: refract_f32x3, \
		f64x3: refract_f64x3, \
		f16x4: refract_f16x4, \
		f32x4: refract_f32x4, \
		f64x4: refract_f64x4 \
	)(v, normal, eta)

//
// returns the minimum value from each of the components in 'v'
#define minelmtG(v) \
	_Generic((v), \
		f16x2: minelmt_f16x2, \
		f32x2: minelmt_f32x2, \
		f64x2: minelmt_f64x2, \
		s8x2: minelmt_s8x2, \
		s16x2: minelmt_s16x2, \
		s32x2: minelmt_s32x2, \
		s64x2: minelmt_s64x2, \
		u8x2: minelmt_u8x2, \
		u16x2: minelmt_u16x2, \
		u32x2: minelmt_u32x2, \
		u64x2: minelmt_u64x2, \
		f16x3: minelmt_f16x3, \
		f32x3: minelmt_f32x3, \
		f64x3: minelmt_f64x3, \
		s8x3: minelmt_s8x3, \
		s16x3: minelmt_s16x3, \
		s32x3: minelmt_s32x3, \
		s64x3: minelmt_s64x3, \
		u8x3: minelmt_u8x3, \
		u16x3: minelmt_u16x3, \
		u32x3: minelmt_u32x3, \
		u64x3: minelmt_u64x3, \
		f16x4: minelmt_f16x4, \
		f32x4: minelmt_f32x4, \
		f64x4: minelmt_f64x4, \
		s8x4: minelmt_s8x4, \
		s16x4: minelmt_s16x4, \
		s32x4: minelmt_s32x4, \
		s64x4: minelmt_s64x4, \
		u8x4: minelmt_u8x4, \
		u16x4: minelmt_u16x4, \
		u32x4: minelmt_u32x4, \
		u64x4: minelmt_u64x4 \
	)(v)

//
// returns the maximum value from each of the components in 'v' aka. L infinity norm
#define maxelmtG(v) \
	_Generic((v), \
		f16x2: maxelmt_f16x2, \
		f32x2: maxelmt_f32x2, \
		f64x2: maxelmt_f64x2, \
		s8x2: maxelmt_s8x2, \
		s16x2: maxelmt_s16x2, \
		s32x2: maxelmt_s32x2, \
		s64x2: maxelmt_s64x2, \
		u8x2: maxelmt_u8x2, \
		u16x2: maxelmt_u16x2, \
		u32x2: maxelmt_u32x2, \
		u64x2: maxelmt_u64x2, \
		f16x3: maxelmt_f16x3, \
		f32x3: maxelmt_f32x3, \
		f64x3: maxelmt_f64x3, \
		s8x3: maxelmt_s8x3, \
		s16x3: maxelmt_s16x3, \
		s32x3: maxelmt_s32x3, \
		s64x3: maxelmt_s64x3, \
		u8x3: maxelmt_u8x3, \
		u16x3: maxelmt_u16x3, \
		u32x3: maxelmt_u32x3, \
		u64x3: maxelmt_u64x3, \
		f16x4: maxelmt_f16x4, \
		f32x4: maxelmt_f32x4, \
		f64x4: maxelmt_f64x4, \
		s8x4: maxelmt_s8x4, \
		s16x4: maxelmt_s16x4, \
		s32x4: maxelmt_s32x4, \
		s64x4: maxelmt_s64x4, \
		u8x4: maxelmt_u8x4, \
		u16x4: maxelmt_u16x4, \
		u32x4: maxelmt_u32x4, \
		u64x4: maxelmt_u64x4 \
	)(v)

//
// returns the sum of all of the components in 'v'
#define sumelmtsG(v) \
	_Generic((v), \
		f16x2: sumelmts_f16x2, \
		f32x2: sumelmts_f32x2, \
		f64x2: sumelmts_f64x2, \
		s8x2: sumelmts_s8x2, \
		s16x2: sumelmts_s16x2, \
		s32x2: sumelmts_s32x2, \
		s64x2: sumelmts_s64x2, \
		u8x2: sumelmts_u8x2, \
		u16x2: sumelmts_u16x2, \
		u32x2: sumelmts_u32x2, \
		u64x2: sumelmts_u64x2, \
		f16x3: sumelmts_f16x3, \
		f32x3: sumelmts_f32x3, \
		f64x3: sumelmts_f64x3, \
		s8x3: sumelmts_s8x3, \
		s16x3: sumelmts_s16x3, \
		s32x3: sumelmts_s32x3, \
		s64x3: sumelmts_s64x3, \
		u8x3: sumelmts_u8x3, \
		u16x3: sumelmts_u16x3, \
		u32x3: sumelmts_u32x3, \
		u64x3: sumelmts_u64x3, \
		f16x4: sumelmts_f16x4, \
		f32x4: sumelmts_f32x4, \
		f64x4: sumelmts_f64x4, \
		s8x4: sumelmts_s8x4, \
		s16x4: sumelmts_s16x4, \
		s32x4: sumelmts_s32x4, \
		s64x4: sumelmts_s64x4, \
		u8x4: sumelmts_u8x4, \
		u16x4: sumelmts_u16x4, \
		u32x4: sumelmts_u32x4, \
		u64x4: sumelmts_u64x4 \
	)(v)

//
// returns the product of all of the components in 'v'
#define productelmtsG(v) \
	_Generic((v), \
		f16x2: productelmts_f16x2, \
		f32x2: productelmts_f32x2, \
		f64x2: productelmts_f64x2, \
		s8x2: productelmts_s8x2, \
		s16x2: productelmts_s16x2, \
		s32x2: productelmts_s32x2, \
		s64x2: productelmts_s64x2, \
		u8x2: productelmts_u8x2, \
		u16x2: productelmts_u16x2, \
		u32x2: productelmts_u32x2, \
		u64x2: productelmts_u64x2, \
		f16x3: productelmts_f16x3, \
		f32x3: productelmts_f32x3, \
		f64x3: productelmts_f64x3, \
		s8x3: productelmts_s8x3, \
		s16x3: productelmts_s16x3, \
		s32x3: productelmts_s32x3, \
		s64x3: productelmts_s64x3, \
		u8x3: productelmts_u8x3, \
		u16x3: productelmts_u16x3, \
		u32x3: productelmts_u32x3, \
		u64x3: productelmts_u64x3, \
		f16x4: productelmts_f16x4, \
		f32x4: productelmts_f32x4, \
		f64x4: productelmts_f64x4, \
		s8x4: productelmts_s8x4, \
		s16x4: productelmts_s16x4, \
		s32x4: productelmts_s32x4, \
		s64x4: productelmts_s64x4, \
		u8x4: productelmts_u8x4, \
		u16x4: productelmts_u16x4, \
		u32x4: productelmts_u32x4, \
		u64x4: productelmts_u64x4 \
	)(v)

//
// returns a vector where each component is the square of itself
#define squareG(v) \
	_Generic((v), \
		f16x2: square_f16x2, \
		f32x2: square_f32x2, \
		f64x2: square_f64x2, \
		s8x2: square_s8x2, \
		s16x2: square_s16x2, \
		s32x2: square_s32x2, \
		s64x2: square_s64x2, \
		u8x2: square_u8x2, \
		u16x2: square_u16x2, \
		u32x2: square_u32x2, \
		u64x2: square_u64x2, \
		f16x3: square_f16x3, \
		f32x3: square_f32x3, \
		f64x3: square_f64x3, \
		s8x3: square_s8x3, \
		s16x3: square_s16x3, \
		s32x3: square_s32x3, \
		s64x3: square_s64x3, \
		u8x3: square_u8x3, \
		u16x3: square_u16x3, \
		u32x3: square_u32x3, \
		u64x3: square_u64x3, \
		f16x4: square_f16x4, \
		f32x4: square_f32x4, \
		f64x4: square_f64x4, \
		s8x4: square_s8x4, \
		s16x4: square_s16x4, \
		s32x4: square_s32x4, \
		s64x4: square_s64x4, \
		u8x4: square_u8x4, \
		u16x4: square_u16x4, \
		u32x4: square_u32x4, \
		u64x4: square_u64x4 \
	)(v)

//
// returns the transposed matrix of matrix 'm'
#define transposeG(m) \
	_Generic((m), \
		f32x2x2: transpose_f32x2x2, \
		f64x2x2: transpose_f64x2x2, \
		f32x2x3: transpose_f32x2x3, \
		f64x2x3: transpose_f64x2x3, \
		f32x2x4: transpose_f32x2x4, \
		f64x2x4: transpose_f64x2x4, \
		f32x3x2: transpose_f32x3x2, \
		f64x3x2: transpose_f64x3x2, \
		f32x3x3: transpose_f32x3x3, \
		f64x3x3: transpose_f64x3x3, \
		f32x3x4: transpose_f32x3x4, \
		f64x3x4: transpose_f64x3x4, \
		f32x4x2: transpose_f32x4x2, \
		f64x4x2: transpose_f64x4x2, \
		f32x4x3: transpose_f32x4x3, \
		f64x4x3: transpose_f64x4x3, \
		f32x4x4: transpose_f32x4x4, \
		f64x4x4: transpose_f64x4x4 \
	)(m)

//
// returns a matrix from the outer product of vector 'a' and vector 'b'
#define outerproductG(a, b) \
	_Generic((a), \
		f32x2: \
			_Generic((b), \
				f32x2: outerproduct_f32x2_f32x2, \
				f32x3: outerproduct_f32x2_f32x3, \
				f32x4: outerproduct_f32x2_f32x4 \
			), \
		f64x2: \
			_Generic((b), \
				f64x2: outerproduct_f64x2_f64x2, \
				f64x3: outerproduct_f64x2_f64x3, \
				f64x4: outerproduct_f64x2_f64x4 \
			), \
		f32x3: \
			_Generic((b), \
				f32x2: outerproduct_f32x3_f32x2, \
				f32x3: outerproduct_f32x3_f32x3, \
				f32x4: outerproduct_f32x3_f32x4 \
			), \
		f64x3: \
			_Generic((b), \
				f64x2: outerproduct_f64x3_f64x2, \
				f64x3: outerproduct_f64x3_f64x3, \
				f64x4: outerproduct_f64x3_f64x4 \
			), \
		f32x4: \
			_Generic((b), \
				f32x2: outerproduct_f32x4_f32x2, \
				f32x3: outerproduct_f32x4_f32x3, \
				f32x4: outerproduct_f32x4_f32x4 \
			), \
		f64x4: \
			_Generic((b), \
				f64x2: outerproduct_f64x4_f64x2, \
				f64x3: outerproduct_f64x4_f64x3, \
				f64x4: outerproduct_f64x4_f64x4 \
			) \
	)(a, b)

//
// returns the determinant of matrix 'm'
#define determinantG(m) \
	_Generic((m), \
		f32x2x2: determinant_f32x2x2, \
		f64x2x2: determinant_f64x2x2, \
		f32x3x3: determinant_f32x3x3, \
		f64x3x3: determinant_f64x3x3, \
		f32x4x4: determinant_f32x4x4, \
		f64x4x4: determinant_f64x4x4 \
	)(m)

//
// returns the inverse of matrix 'm'
#define inverseG(m) \
	_Generic((m), \
		f32x2x2: inverse_f32x2x2, \
		f64x2x2: inverse_f64x2x2, \
		f32x3x3: inverse_f32x3x3, \
		f64x3x3: inverse_f64x3x3, \
		f32x4x4: inverse_f32x4x4, \
		f64x4x4: inverse_f64x4x4 \
	)(m)

#endif // _HMATHS_GENERICS_H_

