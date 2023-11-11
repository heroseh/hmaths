#ifndef _HMATHS_VECTOR_H_
#define _HMATHS_VECTOR_H_

#include "hmaths_types.h"
#include "hmaths_scalar.h"

// ===========================================
//
//
// Vector
//
//
// ===========================================
//
// these vectors have scalar alignment where their alignment is the same as their scalar type
// on the HCC and Clang compilers they will use vector extensions for +-*/ operator support and swizzling
//

#ifdef __HCC__
#define castv2(T, v) __hcc_castv2(vec2##T, v)
#define castv3(T, v) __hcc_castv3(vec3##T, v)
#define castv4(T, v) __hcc_castv4(vec4##T, v)
#else
#define castv2(T, v) v2##T((v).x, (v).y)
#define castv3(T, v) v3##T((v).x, (v).y, (v).z)
#define castv4(T, v) v4##T((v).x, (v).y, (v).z, (v).w)
#endif

//
// returns true if _any_ of the vector components are a non-zero value, otherwise false is returned
static inline bool any_boolx2(boolx2 v) { return v.x || v.y; }
static inline bool any_f16x2(f16x2 v) { return (bool)f16tof32(v.x) || (bool)f16tof32(v.y); }
static inline bool any_f32x2(f32x2 v) { return (bool)v.x || (bool)v.y; }
static inline bool any_f64x2(f64x2 v) { return (bool)v.x || (bool)v.y; }
static inline bool any_s8x2(s8x2 v) { return v.x || v.y; }
static inline bool any_s16x2(s16x2 v) { return v.x || v.y; }
static inline bool any_s32x2(s32x2 v) { return v.x || v.y; }
static inline bool any_s64x2(s64x2 v) { return v.x || v.y; }
static inline bool any_u8x2(u8x2 v) { return v.x || v.y; }
static inline bool any_u16x2(u16x2 v) { return v.x || v.y; }
static inline bool any_u32x2(u32x2 v) { return v.x || v.y; }
static inline bool any_u64x2(u64x2 v) { return v.x || v.y; }
static inline bool any_boolx3(boolx3 v) { return v.x || v.y || v.z; }
static inline bool any_f16x3(f16x3 v) { return (bool)f16tof32(v.x) || (bool)f16tof32(v.y) || (bool)f16tof32(v.z); }
static inline bool any_f32x3(f32x3 v) { return (bool)v.x || (bool)v.y || (bool)v.z; }
static inline bool any_f64x3(f64x3 v) { return (bool)v.x || (bool)v.y || (bool)v.z; }
static inline bool any_s8x3(s8x3 v) { return v.x || v.y || v.z; }
static inline bool any_s16x3(s16x3 v) { return v.x || v.y || v.z; }
static inline bool any_s32x3(s32x3 v) { return v.x || v.y || v.z; }
static inline bool any_s64x3(s64x3 v) { return v.x || v.y || v.z; }
static inline bool any_u8x3(u8x3 v) { return v.x || v.y || v.z; }
static inline bool any_u16x3(u16x3 v) { return v.x || v.y || v.z; }
static inline bool any_u32x3(u32x3 v) { return v.x || v.y || v.z; }
static inline bool any_u64x3(u64x3 v) { return v.x || v.y || v.z; }
static inline bool any_boolx4(boolx4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_f16x4(f16x4 v) { return (bool)f16tof32(v.x) || (bool)f16tof32(v.y) || (bool)f16tof32(v.z) || (bool)f16tof32(v.w); }
static inline bool any_f32x4(f32x4 v) { return (bool)v.x || (bool)v.y || (bool)v.z || (bool)v.w; }
static inline bool any_f64x4(f64x4 v) { return (bool)v.x || (bool)v.y || (bool)v.z || (bool)v.w; }
static inline bool any_s8x4(s8x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_s16x4(s16x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_s32x4(s32x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_s64x4(s64x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_u8x4(u8x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_u16x4(u16x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_u32x4(u32x4 v) { return v.x || v.y || v.z || v.w; }
static inline bool any_u64x4(u64x4 v) { return v.x || v.y || v.z || v.w; }

//
// returns true if _all_ of the vector components are a non-zero value, otherwise false is returned
static inline bool all_boolx2(boolx2 v) { return v.x && v.y; }
static inline bool all_f16x2(f16x2 v) { return (bool)f16tof32(v.x) && (bool)f16tof32(v.y); }
static inline bool all_f32x2(f32x2 v) { return (bool)v.x && (bool)v.y; }
static inline bool all_f64x2(f64x2 v) { return (bool)v.x && (bool)v.y; }
static inline bool all_s8x2(s8x2 v) { return v.x && v.y; }
static inline bool all_s16x2(s16x2 v) { return v.x && v.y; }
static inline bool all_s32x2(s32x2 v) { return v.x && v.y; }
static inline bool all_s64x2(s64x2 v) { return v.x && v.y; }
static inline bool all_u8x2(u8x2 v) { return v.x && v.y; }
static inline bool all_u16x2(u16x2 v) { return v.x && v.y; }
static inline bool all_u32x2(u32x2 v) { return v.x && v.y; }
static inline bool all_u64x2(u64x2 v) { return v.x && v.y; }
static inline bool all_boolx3(boolx3 v) { return v.x && v.y && v.z; }
static inline bool all_f16x3(f16x3 v) { return (bool)f16tof32(v.x) && (bool)f16tof32(v.y) && (bool)f16tof32(v.z); }
static inline bool all_f32x3(f32x3 v) { return (bool)v.x && (bool)v.y && (bool)v.z; }
static inline bool all_f64x3(f64x3 v) { return (bool)v.x && (bool)v.y && (bool)v.z; }
static inline bool all_s8x3(s8x3 v) { return v.x && v.y && v.z; }
static inline bool all_s16x3(s16x3 v) { return v.x && v.y && v.z; }
static inline bool all_s32x3(s32x3 v) { return v.x && v.y && v.z; }
static inline bool all_s64x3(s64x3 v) { return v.x && v.y && v.z; }
static inline bool all_u8x3(u8x3 v) { return v.x && v.y && v.z; }
static inline bool all_u16x3(u16x3 v) { return v.x && v.y && v.z; }
static inline bool all_u32x3(u32x3 v) { return v.x && v.y && v.z; }
static inline bool all_u64x3(u64x3 v) { return v.x && v.y && v.z; }
static inline bool all_boolx4(boolx4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_f16x4(f16x4 v) { return (bool)f16tof32(v.x) && (bool)f16tof32(v.y) && (bool)f16tof32(v.z) && (bool)f16tof32(v.w); }
static inline bool all_f32x4(f32x4 v) { return (bool)v.x && (bool)v.y && (bool)v.z && (bool)v.w; }
static inline bool all_f64x4(f64x4 v) { return (bool)v.x && (bool)v.y && (bool)v.z && (bool)v.w; }
static inline bool all_s8x4(s8x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_s16x4(s16x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_s32x4(s32x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_s64x4(s64x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_u8x4(u8x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_u16x4(u16x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_u32x4(u32x4 v) { return v.x && v.y && v.z && v.w; }
static inline bool all_u64x4(u64x4 v) { return v.x && v.y && v.z && v.w; }

//
// returns a boolean vector where each component is true if the component in 'v' is a zero value, otherwise it would be false
static inline boolx2 not_boolx2(boolx2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_f16x2(f16x2 v) { return boolx2(not_f16(v.x), not_f16(v.y)); }
static inline boolx2 not_f32x2(f32x2 v) { return boolx2(!(bool)v.x, !(bool)v.y); }
static inline boolx2 not_f64x2(f64x2 v) { return boolx2(!(bool)v.x, !(bool)v.y); }
static inline boolx2 not_s8x2(s8x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_s16x2(s16x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_s32x2(s32x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_s64x2(s64x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_u8x2(u8x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_u16x2(u16x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_u32x2(u32x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx2 not_u64x2(u64x2 v) { return boolx2(!v.x, !v.y); }
static inline boolx3 not_boolx3(boolx3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_f16x3(f16x3 v) { return boolx3(not_f16(v.x), not_f16(v.y), not_f16(v.z)); }
static inline boolx3 not_f32x3(f32x3 v) { return boolx3(!(bool)v.x, !(bool)v.y, !(bool)v.z); }
static inline boolx3 not_f64x3(f64x3 v) { return boolx3(!(bool)v.x, !(bool)v.y, !(bool)v.z); }
static inline boolx3 not_s8x3(s8x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_s16x3(s16x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_s32x3(s32x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_s64x3(s64x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_u8x3(u8x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_u16x3(u16x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_u32x3(u32x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx3 not_u64x3(u64x3 v) { return boolx3(!v.x, !v.y, !v.z); }
static inline boolx4 not_boolx4(boolx4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_f16x4(f16x4 v) { return boolx4(not_f16(v.x), not_f16(v.y), not_f16(v.z), not_f16(v.w)); }
static inline boolx4 not_f32x4(f32x4 v) { return boolx4(!(bool)v.x, !(bool)v.y, !(bool)v.z, !(bool)v.w); }
static inline boolx4 not_f64x4(f64x4 v) { return boolx4(!(bool)v.x, !(bool)v.y, !(bool)v.z, !(bool)v.w); }
static inline boolx4 not_s8x4(s8x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_s16x4(s16x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_s32x4(s32x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_s64x4(s64x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_u8x4(u8x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_u16x4(u16x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_u32x4(u32x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }
static inline boolx4 not_u64x4(u64x4 v) { return boolx4(!v.x, !v.y, !v.z, !v.w); }

//
// returns a vector where each component is the result from adding that component in 'a' to that component in 'b'
static inline f16x2 add_f16x2(f16x2 a, f16x2 b) { return f16x2(add_f16(a.x, b.x), add_f16(a.y, b.y)); }
static inline f32x2 add_f32x2(f32x2 a, f32x2 b) { return f32x2(a.x + b.x, a.y + b.y); }
static inline f64x2 add_f64x2(f64x2 a, f64x2 b) { return f64x2(a.x + b.x, a.y + b.y); }
static inline s8x2 add_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x + b.x, a.y + b.y); }
static inline s16x2 add_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x + b.x, a.y + b.y); }
static inline s32x2 add_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x + b.x, a.y + b.y); }
static inline s64x2 add_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x + b.x, a.y + b.y); }
static inline u8x2 add_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x + b.x, a.y + b.y); }
static inline u16x2 add_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x + b.x, a.y + b.y); }
static inline u32x2 add_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x + b.x, a.y + b.y); }
static inline u64x2 add_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x + b.x, a.y + b.y); }
static inline f16x3 add_f16x3(f16x3 a, f16x3 b) { return f16x3(add_f16(a.x, b.x), add_f16(a.y, b.y), add_f16(a.z, b.z)); }
static inline f32x3 add_f32x3(f32x3 a, f32x3 b) { return f32x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline f64x3 add_f64x3(f64x3 a, f64x3 b) { return f64x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline s8x3 add_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline s16x3 add_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline s32x3 add_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline s64x3 add_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline u8x3 add_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline u16x3 add_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline u32x3 add_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline u64x3 add_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline f16x4 add_f16x4(f16x4 a, f16x4 b) { return f16x4(add_f16(a.x, b.x), add_f16(a.y, b.y), add_f16(a.z, b.z), add_f16(a.w, b.w)); }
static inline f32x4 add_f32x4(f32x4 a, f32x4 b) { return f32x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline f64x4 add_f64x4(f64x4 a, f64x4 b) { return f64x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline s8x4 add_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline s16x4 add_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline s32x4 add_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline s64x4 add_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline u8x4 add_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline u16x4 add_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline u32x4 add_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
static inline u64x4 add_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }

//
// returns a vector where each component is the result from adding that component in 'v' to the value of 's'
static inline f16x2 adds_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return add_f16x2(v, ss); }
static inline f32x2 adds_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return add_f32x2(v, ss); }
static inline f64x2 adds_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return add_f64x2(v, ss); }
static inline s8x2 adds_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return add_s8x2(v, ss); }
static inline s16x2 adds_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return add_s16x2(v, ss); }
static inline s32x2 adds_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return add_s32x2(v, ss); }
static inline s64x2 adds_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return add_s64x2(v, ss); }
static inline u8x2 adds_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return add_u8x2(v, ss); }
static inline u16x2 adds_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return add_u16x2(v, ss); }
static inline u32x2 adds_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return add_u32x2(v, ss); }
static inline u64x2 adds_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return add_u64x2(v, ss); }
static inline f16x3 adds_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return add_f16x3(v, ss); }
static inline f32x3 adds_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return add_f32x3(v, ss); }
static inline f64x3 adds_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return add_f64x3(v, ss); }
static inline s8x3 adds_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return add_s8x3(v, ss); }
static inline s16x3 adds_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return add_s16x3(v, ss); }
static inline s32x3 adds_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return add_s32x3(v, ss); }
static inline s64x3 adds_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return add_s64x3(v, ss); }
static inline u8x3 adds_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return add_u8x3(v, ss); }
static inline u16x3 adds_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return add_u16x3(v, ss); }
static inline u32x3 adds_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return add_u32x3(v, ss); }
static inline u64x3 adds_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return add_u64x3(v, ss); }
static inline f16x4 adds_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return add_f16x4(v, ss); }
static inline f32x4 adds_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return add_f32x4(v, ss); }
static inline f64x4 adds_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return add_f64x4(v, ss); }
static inline s8x4 adds_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return add_s8x4(v, ss); }
static inline s16x4 adds_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return add_s16x4(v, ss); }
static inline s32x4 adds_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return add_s32x4(v, ss); }
static inline s64x4 adds_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return add_s64x4(v, ss); }
static inline u8x4 adds_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return add_u8x4(v, ss); }
static inline u16x4 adds_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return add_u16x4(v, ss); }
static inline u32x4 adds_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return add_u32x4(v, ss); }
static inline u64x4 adds_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return add_u64x4(v, ss); }

//
// returns a vector where each component is the result from subtracting that component in 'a' to that component in 'b'
static inline f16x2 sub_f16x2(f16x2 a, f16x2 b) { return f16x2(sub_f16(a.x, b.x), sub_f16(a.y, b.y)); }
static inline f32x2 sub_f32x2(f32x2 a, f32x2 b) { return f32x2(a.x - b.x, a.y - b.y); }
static inline f64x2 sub_f64x2(f64x2 a, f64x2 b) { return f64x2(a.x - b.x, a.y - b.y); }
static inline s8x2 sub_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x - b.x, a.y - b.y); }
static inline s16x2 sub_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x - b.x, a.y - b.y); }
static inline s32x2 sub_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x - b.x, a.y - b.y); }
static inline s64x2 sub_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x - b.x, a.y - b.y); }
static inline u8x2 sub_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x - b.x, a.y - b.y); }
static inline u16x2 sub_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x - b.x, a.y - b.y); }
static inline u32x2 sub_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x - b.x, a.y - b.y); }
static inline u64x2 sub_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x - b.x, a.y - b.y); }
static inline f16x3 sub_f16x3(f16x3 a, f16x3 b) { return f16x3(sub_f16(a.x, b.x), sub_f16(a.y, b.y), sub_f16(a.z, b.z)); }
static inline f32x3 sub_f32x3(f32x3 a, f32x3 b) { return f32x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline f64x3 sub_f64x3(f64x3 a, f64x3 b) { return f64x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline s8x3 sub_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline s16x3 sub_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline s32x3 sub_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline s64x3 sub_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline u8x3 sub_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline u16x3 sub_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline u32x3 sub_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline u64x3 sub_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline f16x4 sub_f16x4(f16x4 a, f16x4 b) { return f16x4(sub_f16(a.x, b.x), sub_f16(a.y, b.y), sub_f16(a.z, b.z), sub_f16(a.w, b.w)); }
static inline f32x4 sub_f32x4(f32x4 a, f32x4 b) { return f32x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline f64x4 sub_f64x4(f64x4 a, f64x4 b) { return f64x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline s8x4 sub_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline s16x4 sub_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline s32x4 sub_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline s64x4 sub_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline u8x4 sub_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline u16x4 sub_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline u32x4 sub_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
static inline u64x4 sub_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }

//
// returns a vector where each component is the result from subtracting that component in 'v' to the value of 's'
static inline f16x2 subs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return sub_f16x2(v, ss); }
static inline f32x2 subs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return sub_f32x2(v, ss); }
static inline f64x2 subs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return sub_f64x2(v, ss); }
static inline s8x2 subs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return sub_s8x2(v, ss); }
static inline s16x2 subs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return sub_s16x2(v, ss); }
static inline s32x2 subs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return sub_s32x2(v, ss); }
static inline s64x2 subs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return sub_s64x2(v, ss); }
static inline u8x2 subs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return sub_u8x2(v, ss); }
static inline u16x2 subs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return sub_u16x2(v, ss); }
static inline u32x2 subs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return sub_u32x2(v, ss); }
static inline u64x2 subs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return sub_u64x2(v, ss); }
static inline f16x3 subs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return sub_f16x3(v, ss); }
static inline f32x3 subs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return sub_f32x3(v, ss); }
static inline f64x3 subs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return sub_f64x3(v, ss); }
static inline s8x3 subs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return sub_s8x3(v, ss); }
static inline s16x3 subs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return sub_s16x3(v, ss); }
static inline s32x3 subs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return sub_s32x3(v, ss); }
static inline s64x3 subs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return sub_s64x3(v, ss); }
static inline u8x3 subs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return sub_u8x3(v, ss); }
static inline u16x3 subs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return sub_u16x3(v, ss); }
static inline u32x3 subs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return sub_u32x3(v, ss); }
static inline u64x3 subs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return sub_u64x3(v, ss); }
static inline f16x4 subs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return sub_f16x4(v, ss); }
static inline f32x4 subs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return sub_f32x4(v, ss); }
static inline f64x4 subs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return sub_f64x4(v, ss); }
static inline s8x4 subs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return sub_s8x4(v, ss); }
static inline s16x4 subs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return sub_s16x4(v, ss); }
static inline s32x4 subs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return sub_s32x4(v, ss); }
static inline s64x4 subs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return sub_s64x4(v, ss); }
static inline u8x4 subs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return sub_u8x4(v, ss); }
static inline u16x4 subs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return sub_u16x4(v, ss); }
static inline u32x4 subs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return sub_u32x4(v, ss); }
static inline u64x4 subs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return sub_u64x4(v, ss); }

//
// returns a vector where each component is the result from subtracting the value of 's' to that component in 'v'
static inline f16x2 ssub_f16x2(half s, f16x2 v) { f16x2 ss = f16x2s(s); return sub_f16x2(ss, v); }
static inline f32x2 ssub_f32x2(float s, f32x2 v) { f32x2 ss = f32x2s(s); return sub_f32x2(ss, v); }
static inline f64x2 ssub_f64x2(double s, f64x2 v) { f64x2 ss = f64x2s(s); return sub_f64x2(ss, v); }
static inline s8x2 ssub_s8x2(int8_t s, s8x2 v) { s8x2 ss = s8x2s(s); return sub_s8x2(ss, v); }
static inline s16x2 ssub_s16x2(int16_t s, s16x2 v) { s16x2 ss = s16x2s(s); return sub_s16x2(ss, v); }
static inline s32x2 ssub_s32x2(int32_t s, s32x2 v) { s32x2 ss = s32x2s(s); return sub_s32x2(ss, v); }
static inline s64x2 ssub_s64x2(int64_t s, s64x2 v) { s64x2 ss = s64x2s(s); return sub_s64x2(ss, v); }
static inline u8x2 ssub_u8x2(uint8_t s, u8x2 v) { u8x2 ss = u8x2s(s); return sub_u8x2(ss, v); }
static inline u16x2 ssub_u16x2(uint16_t s, u16x2 v) { u16x2 ss = u16x2s(s); return sub_u16x2(ss, v); }
static inline u32x2 ssub_u32x2(uint32_t s, u32x2 v) { u32x2 ss = u32x2s(s); return sub_u32x2(ss, v); }
static inline u64x2 ssub_u64x2(uint64_t s, u64x2 v) { u64x2 ss = u64x2s(s); return sub_u64x2(ss, v); }
static inline f16x3 ssub_f16x3(half s, f16x3 v) { f16x3 ss = f16x3s(s); return sub_f16x3(ss, v); }
static inline f32x3 ssub_f32x3(float s, f32x3 v) { f32x3 ss = f32x3s(s); return sub_f32x3(ss, v); }
static inline f64x3 ssub_f64x3(double s, f64x3 v) { f64x3 ss = f64x3s(s); return sub_f64x3(ss, v); }
static inline s8x3 ssub_s8x3(int8_t s, s8x3 v) { s8x3 ss = s8x3s(s); return sub_s8x3(ss, v); }
static inline s16x3 ssub_s16x3(int16_t s, s16x3 v) { s16x3 ss = s16x3s(s); return sub_s16x3(ss, v); }
static inline s32x3 ssub_s32x3(int32_t s, s32x3 v) { s32x3 ss = s32x3s(s); return sub_s32x3(ss, v); }
static inline s64x3 ssub_s64x3(int64_t s, s64x3 v) { s64x3 ss = s64x3s(s); return sub_s64x3(ss, v); }
static inline u8x3 ssub_u8x3(uint8_t s, u8x3 v) { u8x3 ss = u8x3s(s); return sub_u8x3(ss, v); }
static inline u16x3 ssub_u16x3(uint16_t s, u16x3 v) { u16x3 ss = u16x3s(s); return sub_u16x3(ss, v); }
static inline u32x3 ssub_u32x3(uint32_t s, u32x3 v) { u32x3 ss = u32x3s(s); return sub_u32x3(ss, v); }
static inline u64x3 ssub_u64x3(uint64_t s, u64x3 v) { u64x3 ss = u64x3s(s); return sub_u64x3(ss, v); }
static inline f16x4 ssub_f16x4(half s, f16x4 v) { f16x4 ss = f16x4s(s); return sub_f16x4(ss, v); }
static inline f32x4 ssub_f32x4(float s, f32x4 v) { f32x4 ss = f32x4s(s); return sub_f32x4(ss, v); }
static inline f64x4 ssub_f64x4(double s, f64x4 v) { f64x4 ss = f64x4s(s); return sub_f64x4(ss, v); }
static inline s8x4 ssub_s8x4(int8_t s, s8x4 v) { s8x4 ss = s8x4s(s); return sub_s8x4(ss, v); }
static inline s16x4 ssub_s16x4(int16_t s, s16x4 v) { s16x4 ss = s16x4s(s); return sub_s16x4(ss, v); }
static inline s32x4 ssub_s32x4(int32_t s, s32x4 v) { s32x4 ss = s32x4s(s); return sub_s32x4(ss, v); }
static inline s64x4 ssub_s64x4(int64_t s, s64x4 v) { s64x4 ss = s64x4s(s); return sub_s64x4(ss, v); }
static inline u8x4 ssub_u8x4(uint8_t s, u8x4 v) { u8x4 ss = u8x4s(s); return sub_u8x4(ss, v); }
static inline u16x4 ssub_u16x4(uint16_t s, u16x4 v) { u16x4 ss = u16x4s(s); return sub_u16x4(ss, v); }
static inline u32x4 ssub_u32x4(uint32_t s, u32x4 v) { u32x4 ss = u32x4s(s); return sub_u32x4(ss, v); }
static inline u64x4 ssub_u64x4(uint64_t s, u64x4 v) { u64x4 ss = u64x4s(s); return sub_u64x4(ss, v); }

//
// returns a vector where each component is the result from multiplying that component in 'a' to that component in 'b'
static inline f16x2 mul_f16x2(f16x2 a, f16x2 b) { return f16x2(mul_f16(a.x, b.x), mul_f16(a.y, b.y)); }
static inline f32x2 mul_f32x2(f32x2 a, f32x2 b) { return f32x2(a.x * b.x, a.y * b.y); }
static inline f64x2 mul_f64x2(f64x2 a, f64x2 b) { return f64x2(a.x * b.x, a.y * b.y); }
static inline s8x2 mul_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x * b.x, a.y * b.y); }
static inline s16x2 mul_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x * b.x, a.y * b.y); }
static inline s32x2 mul_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x * b.x, a.y * b.y); }
static inline s64x2 mul_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x * b.x, a.y * b.y); }
static inline u8x2 mul_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x * b.x, a.y * b.y); }
static inline u16x2 mul_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x * b.x, a.y * b.y); }
static inline u32x2 mul_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x * b.x, a.y * b.y); }
static inline u64x2 mul_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x * b.x, a.y * b.y); }
static inline f16x3 mul_f16x3(f16x3 a, f16x3 b) { return f16x3(mul_f16(a.x, b.x), mul_f16(a.y, b.y), mul_f16(a.z, b.z)); }
static inline f32x3 mul_f32x3(f32x3 a, f32x3 b) { return f32x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline f64x3 mul_f64x3(f64x3 a, f64x3 b) { return f64x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline s8x3 mul_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline s16x3 mul_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline s32x3 mul_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline s64x3 mul_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline u8x3 mul_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline u16x3 mul_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline u32x3 mul_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline u64x3 mul_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x * b.x, a.y * b.y, a.z * b.z); }
static inline f16x4 mul_f16x4(f16x4 a, f16x4 b) { return f16x4(mul_f16(a.x, b.x), mul_f16(a.y, b.y), mul_f16(a.z, b.z), mul_f16(a.w, b.w)); }
static inline f32x4 mul_f32x4(f32x4 a, f32x4 b) { return f32x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline f64x4 mul_f64x4(f64x4 a, f64x4 b) { return f64x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline s8x4 mul_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline s16x4 mul_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline s32x4 mul_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline s64x4 mul_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline u8x4 mul_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline u16x4 mul_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline u32x4 mul_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
static inline u64x4 mul_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }

//
// returns a vector where each component is the result from multiplying that component in 'v' to the value of 's'
static inline f16x2 muls_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return mul_f16x2(v, ss); }
static inline f32x2 muls_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return mul_f32x2(v, ss); }
static inline f64x2 muls_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return mul_f64x2(v, ss); }
static inline s8x2 muls_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return mul_s8x2(v, ss); }
static inline s16x2 muls_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return mul_s16x2(v, ss); }
static inline s32x2 muls_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return mul_s32x2(v, ss); }
static inline s64x2 muls_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return mul_s64x2(v, ss); }
static inline u8x2 muls_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return mul_u8x2(v, ss); }
static inline u16x2 muls_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return mul_u16x2(v, ss); }
static inline u32x2 muls_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return mul_u32x2(v, ss); }
static inline u64x2 muls_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return mul_u64x2(v, ss); }
static inline f16x3 muls_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return mul_f16x3(v, ss); }
static inline f32x3 muls_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return mul_f32x3(v, ss); }
static inline f64x3 muls_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return mul_f64x3(v, ss); }
static inline s8x3 muls_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return mul_s8x3(v, ss); }
static inline s16x3 muls_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return mul_s16x3(v, ss); }
static inline s32x3 muls_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return mul_s32x3(v, ss); }
static inline s64x3 muls_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return mul_s64x3(v, ss); }
static inline u8x3 muls_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return mul_u8x3(v, ss); }
static inline u16x3 muls_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return mul_u16x3(v, ss); }
static inline u32x3 muls_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return mul_u32x3(v, ss); }
static inline u64x3 muls_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return mul_u64x3(v, ss); }
static inline f16x4 muls_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return mul_f16x4(v, ss); }
static inline f32x4 muls_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return mul_f32x4(v, ss); }
static inline f64x4 muls_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return mul_f64x4(v, ss); }
static inline s8x4 muls_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return mul_s8x4(v, ss); }
static inline s16x4 muls_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return mul_s16x4(v, ss); }
static inline s32x4 muls_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return mul_s32x4(v, ss); }
static inline s64x4 muls_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return mul_s64x4(v, ss); }
static inline u8x4 muls_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return mul_u8x4(v, ss); }
static inline u16x4 muls_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return mul_u16x4(v, ss); }
static inline u32x4 muls_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return mul_u32x4(v, ss); }
static inline u64x4 muls_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return mul_u64x4(v, ss); }

//
// returns a vector where each component is the result from dividing that component in 'a' to that component in 'b'
static inline f16x2 div_f16x2(f16x2 a, f16x2 b) { return f16x2(div_f16(a.x, b.x), div_f16(a.y, b.y)); }
static inline f32x2 div_f32x2(f32x2 a, f32x2 b) { return f32x2(a.x / b.x, a.y / b.y); }
static inline f64x2 div_f64x2(f64x2 a, f64x2 b) { return f64x2(a.x / b.x, a.y / b.y); }
static inline s8x2 div_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x / b.x, a.y / b.y); }
static inline s16x2 div_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x / b.x, a.y / b.y); }
static inline s32x2 div_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x / b.x, a.y / b.y); }
static inline s64x2 div_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x / b.x, a.y / b.y); }
static inline u8x2 div_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x / b.x, a.y / b.y); }
static inline u16x2 div_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x / b.x, a.y / b.y); }
static inline u32x2 div_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x / b.x, a.y / b.y); }
static inline u64x2 div_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x / b.x, a.y / b.y); }
static inline f16x3 div_f16x3(f16x3 a, f16x3 b) { return f16x3(div_f16(a.x, b.x), div_f16(a.y, b.y), div_f16(a.z, b.z)); }
static inline f32x3 div_f32x3(f32x3 a, f32x3 b) { return f32x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline f64x3 div_f64x3(f64x3 a, f64x3 b) { return f64x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline s8x3 div_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline s16x3 div_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline s32x3 div_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline s64x3 div_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline u8x3 div_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline u16x3 div_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline u32x3 div_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline u64x3 div_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x / b.x, a.y / b.y, a.z / b.z); }
static inline f16x4 div_f16x4(f16x4 a, f16x4 b) { return f16x4(div_f16(a.x, b.x), div_f16(a.y, b.y), div_f16(a.z, b.z), div_f16(a.w, b.w)); }
static inline f32x4 div_f32x4(f32x4 a, f32x4 b) { return f32x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline f64x4 div_f64x4(f64x4 a, f64x4 b) { return f64x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline s8x4 div_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline s16x4 div_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline s32x4 div_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline s64x4 div_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline u8x4 div_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline u16x4 div_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline u32x4 div_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
static inline u64x4 div_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }

//
// returns a vector where each component is the result from dividing that component in 'v' to the value of 's'
static inline f16x2 divs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return div_f16x2(v, ss); }
static inline f32x2 divs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return div_f32x2(v, ss); }
static inline f64x2 divs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return div_f64x2(v, ss); }
static inline s8x2 divs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return div_s8x2(v, ss); }
static inline s16x2 divs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return div_s16x2(v, ss); }
static inline s32x2 divs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return div_s32x2(v, ss); }
static inline s64x2 divs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return div_s64x2(v, ss); }
static inline u8x2 divs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return div_u8x2(v, ss); }
static inline u16x2 divs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return div_u16x2(v, ss); }
static inline u32x2 divs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return div_u32x2(v, ss); }
static inline u64x2 divs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return div_u64x2(v, ss); }
static inline f16x3 divs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return div_f16x3(v, ss); }
static inline f32x3 divs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return div_f32x3(v, ss); }
static inline f64x3 divs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return div_f64x3(v, ss); }
static inline s8x3 divs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return div_s8x3(v, ss); }
static inline s16x3 divs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return div_s16x3(v, ss); }
static inline s32x3 divs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return div_s32x3(v, ss); }
static inline s64x3 divs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return div_s64x3(v, ss); }
static inline u8x3 divs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return div_u8x3(v, ss); }
static inline u16x3 divs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return div_u16x3(v, ss); }
static inline u32x3 divs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return div_u32x3(v, ss); }
static inline u64x3 divs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return div_u64x3(v, ss); }
static inline f16x4 divs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return div_f16x4(v, ss); }
static inline f32x4 divs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return div_f32x4(v, ss); }
static inline f64x4 divs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return div_f64x4(v, ss); }
static inline s8x4 divs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return div_s8x4(v, ss); }
static inline s16x4 divs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return div_s16x4(v, ss); }
static inline s32x4 divs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return div_s32x4(v, ss); }
static inline s64x4 divs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return div_s64x4(v, ss); }
static inline u8x4 divs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return div_u8x4(v, ss); }
static inline u16x4 divs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return div_u16x4(v, ss); }
static inline u32x4 divs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return div_u32x4(v, ss); }
static inline u64x4 divs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return div_u64x4(v, ss); }

//
// returns a vector where each component is the result from dividing the value of 's' to that component in 'v'
static inline f16x2 sdiv_f16x2(half s, f16x2 v) { f16x2 ss = f16x2s(s); return div_f16x2(ss, v); }
static inline f32x2 sdiv_f32x2(float s, f32x2 v) { f32x2 ss = f32x2s(s); return div_f32x2(ss, v); }
static inline f64x2 sdiv_f64x2(double s, f64x2 v) { f64x2 ss = f64x2s(s); return div_f64x2(ss, v); }
static inline s8x2 sdiv_s8x2(int8_t s, s8x2 v) { s8x2 ss = s8x2s(s); return div_s8x2(ss, v); }
static inline s16x2 sdiv_s16x2(int16_t s, s16x2 v) { s16x2 ss = s16x2s(s); return div_s16x2(ss, v); }
static inline s32x2 sdiv_s32x2(int32_t s, s32x2 v) { s32x2 ss = s32x2s(s); return div_s32x2(ss, v); }
static inline s64x2 sdiv_s64x2(int64_t s, s64x2 v) { s64x2 ss = s64x2s(s); return div_s64x2(ss, v); }
static inline u8x2 sdiv_u8x2(uint8_t s, u8x2 v) { u8x2 ss = u8x2s(s); return div_u8x2(ss, v); }
static inline u16x2 sdiv_u16x2(uint16_t s, u16x2 v) { u16x2 ss = u16x2s(s); return div_u16x2(ss, v); }
static inline u32x2 sdiv_u32x2(uint32_t s, u32x2 v) { u32x2 ss = u32x2s(s); return div_u32x2(ss, v); }
static inline u64x2 sdiv_u64x2(uint64_t s, u64x2 v) { u64x2 ss = u64x2s(s); return div_u64x2(ss, v); }
static inline f16x3 sdiv_f16x3(half s, f16x3 v) { f16x3 ss = f16x3s(s); return div_f16x3(ss, v); }
static inline f32x3 sdiv_f32x3(float s, f32x3 v) { f32x3 ss = f32x3s(s); return div_f32x3(ss, v); }
static inline f64x3 sdiv_f64x3(double s, f64x3 v) { f64x3 ss = f64x3s(s); return div_f64x3(ss, v); }
static inline s8x3 sdiv_s8x3(int8_t s, s8x3 v) { s8x3 ss = s8x3s(s); return div_s8x3(ss, v); }
static inline s16x3 sdiv_s16x3(int16_t s, s16x3 v) { s16x3 ss = s16x3s(s); return div_s16x3(ss, v); }
static inline s32x3 sdiv_s32x3(int32_t s, s32x3 v) { s32x3 ss = s32x3s(s); return div_s32x3(ss, v); }
static inline s64x3 sdiv_s64x3(int64_t s, s64x3 v) { s64x3 ss = s64x3s(s); return div_s64x3(ss, v); }
static inline u8x3 sdiv_u8x3(uint8_t s, u8x3 v) { u8x3 ss = u8x3s(s); return div_u8x3(ss, v); }
static inline u16x3 sdiv_u16x3(uint16_t s, u16x3 v) { u16x3 ss = u16x3s(s); return div_u16x3(ss, v); }
static inline u32x3 sdiv_u32x3(uint32_t s, u32x3 v) { u32x3 ss = u32x3s(s); return div_u32x3(ss, v); }
static inline u64x3 sdiv_u64x3(uint64_t s, u64x3 v) { u64x3 ss = u64x3s(s); return div_u64x3(ss, v); }
static inline f16x4 sdiv_f16x4(half s, f16x4 v) { f16x4 ss = f16x4s(s); return div_f16x4(ss, v); }
static inline f32x4 sdiv_f32x4(float s, f32x4 v) { f32x4 ss = f32x4s(s); return div_f32x4(ss, v); }
static inline f64x4 sdiv_f64x4(double s, f64x4 v) { f64x4 ss = f64x4s(s); return div_f64x4(ss, v); }
static inline s8x4 sdiv_s8x4(int8_t s, s8x4 v) { s8x4 ss = s8x4s(s); return div_s8x4(ss, v); }
static inline s16x4 sdiv_s16x4(int16_t s, s16x4 v) { s16x4 ss = s16x4s(s); return div_s16x4(ss, v); }
static inline s32x4 sdiv_s32x4(int32_t s, s32x4 v) { s32x4 ss = s32x4s(s); return div_s32x4(ss, v); }
static inline s64x4 sdiv_s64x4(int64_t s, s64x4 v) { s64x4 ss = s64x4s(s); return div_s64x4(ss, v); }
static inline u8x4 sdiv_u8x4(uint8_t s, u8x4 v) { u8x4 ss = u8x4s(s); return div_u8x4(ss, v); }
static inline u16x4 sdiv_u16x4(uint16_t s, u16x4 v) { u16x4 ss = u16x4s(s); return div_u16x4(ss, v); }
static inline u32x4 sdiv_u32x4(uint32_t s, u32x4 v) { u32x4 ss = u32x4s(s); return div_u32x4(ss, v); }
static inline u64x4 sdiv_u64x4(uint64_t s, u64x4 v) { u64x4 ss = u64x4s(s); return div_u64x4(ss, v); }

//
// returns a vector where each component is the result from moduloing that component in 'a' to that component in 'b'
static inline f16x2 mod_f16x2(f16x2 a, f16x2 b) { return f16x2(mod_f16(a.x, b.x), mod_f16(a.y, b.y)); }
static inline f32x2 mod_f32x2(f32x2 a, f32x2 b) { return f32x2(mod_f32(a.x, b.x), mod_f32(a.y, b.y)); }
static inline f64x2 mod_f64x2(f64x2 a, f64x2 b) { return f64x2(mod_f64(a.x, b.x), mod_f64(a.y, b.y)); }
static inline s8x2 mod_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x % b.x, a.y % b.y); }
static inline s16x2 mod_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x % b.x, a.y % b.y); }
static inline s32x2 mod_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x % b.x, a.y % b.y); }
static inline s64x2 mod_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x % b.x, a.y % b.y); }
static inline u8x2 mod_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x % b.x, a.y % b.y); }
static inline u16x2 mod_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x % b.x, a.y % b.y); }
static inline u32x2 mod_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x % b.x, a.y % b.y); }
static inline u64x2 mod_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x % b.x, a.y % b.y); }
static inline f16x3 mod_f16x3(f16x3 a, f16x3 b) { return f16x3(mod_f16(a.x, b.x), mod_f16(a.y, b.y), mod_f16(a.z, b.z)); }
static inline f32x3 mod_f32x3(f32x3 a, f32x3 b) { return f32x3(mod_f32(a.x, b.x), mod_f32(a.y, b.y), mod_f32(a.z, b.z)); }
static inline f64x3 mod_f64x3(f64x3 a, f64x3 b) { return f64x3(mod_f64(a.x, b.x), mod_f64(a.y, b.y), mod_f64(a.z, b.z)); }
static inline s8x3 mod_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline s16x3 mod_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline s32x3 mod_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline s64x3 mod_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline u8x3 mod_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline u16x3 mod_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline u32x3 mod_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline u64x3 mod_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x % b.x, a.y % b.y, a.z % b.z); }
static inline f16x4 mod_f16x4(f16x4 a, f16x4 b) { return f16x4(mod_f16(a.x, b.x), mod_f16(a.y, b.y), mod_f16(a.z, b.z), mod_f16(a.w, b.w)); }
static inline f32x4 mod_f32x4(f32x4 a, f32x4 b) { return f32x4(mod_f32(a.x, b.x), mod_f32(a.y, b.y), mod_f32(a.z, b.z), mod_f32(a.w, b.w)); }
static inline f64x4 mod_f64x4(f64x4 a, f64x4 b) { return f64x4(mod_f64(a.x, b.x), mod_f64(a.y, b.y), mod_f64(a.z, b.z), mod_f64(a.w, b.w)); }
static inline s8x4 mod_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline s16x4 mod_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline s32x4 mod_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline s64x4 mod_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline u8x4 mod_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline u16x4 mod_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline u32x4 mod_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }
static inline u64x4 mod_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w); }

//
// returns a vector where each component is the result from moduloing that component in 'v' to the value 's'
static inline f16x2 mods_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return mod_f16x2(v, ss); }
static inline f32x2 mods_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return mod_f32x2(v, ss); }
static inline f64x2 mods_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return mod_f64x2(v, ss); }
static inline s8x2 mods_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return mod_s8x2(v, ss); }
static inline s16x2 mods_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return mod_s16x2(v, ss); }
static inline s32x2 mods_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return mod_s32x2(v, ss); }
static inline s64x2 mods_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return mod_s64x2(v, ss); }
static inline u8x2 mods_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return mod_u8x2(v, ss); }
static inline u16x2 mods_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return mod_u16x2(v, ss); }
static inline u32x2 mods_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return mod_u32x2(v, ss); }
static inline u64x2 mods_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return mod_u64x2(v, ss); }
static inline f16x3 mods_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return mod_f16x3(v, ss); }
static inline f32x3 mods_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return mod_f32x3(v, ss); }
static inline f64x3 mods_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return mod_f64x3(v, ss); }
static inline s8x3 mods_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return mod_s8x3(v, ss); }
static inline s16x3 mods_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return mod_s16x3(v, ss); }
static inline s32x3 mods_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return mod_s32x3(v, ss); }
static inline s64x3 mods_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return mod_s64x3(v, ss); }
static inline u8x3 mods_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return mod_u8x3(v, ss); }
static inline u16x3 mods_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return mod_u16x3(v, ss); }
static inline u32x3 mods_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return mod_u32x3(v, ss); }
static inline u64x3 mods_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return mod_u64x3(v, ss); }
static inline f16x4 mods_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return mod_f16x4(v, ss); }
static inline f32x4 mods_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return mod_f32x4(v, ss); }
static inline f64x4 mods_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return mod_f64x4(v, ss); }
static inline s8x4 mods_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return mod_s8x4(v, ss); }
static inline s16x4 mods_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return mod_s16x4(v, ss); }
static inline s32x4 mods_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return mod_s32x4(v, ss); }
static inline s64x4 mods_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return mod_s64x4(v, ss); }
static inline u8x4 mods_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return mod_u8x4(v, ss); }
static inline u16x4 mods_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return mod_u16x4(v, ss); }
static inline u32x4 mods_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return mod_u32x4(v, ss); }
static inline u64x4 mods_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return mod_u64x4(v, ss); }

//
// returns a boolean vector where each component is true when that component in 'a' is equal to that component in 'b'
static inline boolx2 eq_f16x2(f16x2 a, f16x2 b) { return boolx2(eq_f16(a.x, b.x), eq_f16(a.y, b.y)); }
static inline boolx2 eq_f32x2(f32x2 a, f32x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_f64x2(f64x2 a, f64x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_s8x2(s8x2 a, s8x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_s16x2(s16x2 a, s16x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_s32x2(s32x2 a, s32x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_s64x2(s64x2 a, s64x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_u8x2(u8x2 a, u8x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_u16x2(u16x2 a, u16x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_u32x2(u32x2 a, u32x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx2 eq_u64x2(u64x2 a, u64x2 b) { return boolx2(a.x == b.x, a.y == b.y); }
static inline boolx3 eq_f16x3(f16x3 a, f16x3 b) { return boolx3(eq_f16(a.x, b.x), eq_f16(a.y, b.y), eq_f16(a.z, b.z)); }
static inline boolx3 eq_f32x3(f32x3 a, f32x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_f64x3(f64x3 a, f64x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_s8x3(s8x3 a, s8x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_s16x3(s16x3 a, s16x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_s32x3(s32x3 a, s32x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_s64x3(s64x3 a, s64x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_u8x3(u8x3 a, u8x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_u16x3(u16x3 a, u16x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_u32x3(u32x3 a, u32x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx3 eq_u64x3(u64x3 a, u64x3 b) { return boolx3(a.x == b.x, a.y == b.y, a.z == b.z); }
static inline boolx4 eq_f16x4(f16x4 a, f16x4 b) { return boolx4(eq_f16(a.x, b.x), eq_f16(a.y, b.y), eq_f16(a.z, b.z), eq_f16(a.w, b.w)); }
static inline boolx4 eq_f32x4(f32x4 a, f32x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_f64x4(f64x4 a, f64x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_s8x4(s8x4 a, s8x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_s16x4(s16x4 a, s16x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_s32x4(s32x4 a, s32x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_s64x4(s64x4 a, s64x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_u8x4(u8x4 a, u8x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_u16x4(u16x4 a, u16x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_u32x4(u32x4 a, u32x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }
static inline boolx4 eq_u64x4(u64x4 a, u64x4 b) { return boolx4(a.x == b.x, a.y == b.y, a.z == b.z, a.w == b.w); }

//
// returns a boolean vector where each component is true when that component in 'v' is equal to the value 's'
static inline boolx2 eqs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return eq_f16x2(v, ss); }
static inline boolx2 eqs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return eq_f32x2(v, ss); }
static inline boolx2 eqs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return eq_f64x2(v, ss); }
static inline boolx2 eqs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return eq_s8x2(v, ss); }
static inline boolx2 eqs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return eq_s16x2(v, ss); }
static inline boolx2 eqs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return eq_s32x2(v, ss); }
static inline boolx2 eqs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return eq_s64x2(v, ss); }
static inline boolx2 eqs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return eq_u8x2(v, ss); }
static inline boolx2 eqs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return eq_u16x2(v, ss); }
static inline boolx2 eqs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return eq_u32x2(v, ss); }
static inline boolx2 eqs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return eq_u64x2(v, ss); }
static inline boolx3 eqs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return eq_f16x3(v, ss); }
static inline boolx3 eqs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return eq_f32x3(v, ss); }
static inline boolx3 eqs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return eq_f64x3(v, ss); }
static inline boolx3 eqs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return eq_s8x3(v, ss); }
static inline boolx3 eqs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return eq_s16x3(v, ss); }
static inline boolx3 eqs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return eq_s32x3(v, ss); }
static inline boolx3 eqs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return eq_s64x3(v, ss); }
static inline boolx3 eqs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return eq_u8x3(v, ss); }
static inline boolx3 eqs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return eq_u16x3(v, ss); }
static inline boolx3 eqs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return eq_u32x3(v, ss); }
static inline boolx3 eqs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return eq_u64x3(v, ss); }
static inline boolx4 eqs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return eq_f16x4(v, ss); }
static inline boolx4 eqs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return eq_f32x4(v, ss); }
static inline boolx4 eqs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return eq_f64x4(v, ss); }
static inline boolx4 eqs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return eq_s8x4(v, ss); }
static inline boolx4 eqs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return eq_s16x4(v, ss); }
static inline boolx4 eqs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return eq_s32x4(v, ss); }
static inline boolx4 eqs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return eq_s64x4(v, ss); }
static inline boolx4 eqs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return eq_u8x4(v, ss); }
static inline boolx4 eqs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return eq_u16x4(v, ss); }
static inline boolx4 eqs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return eq_u32x4(v, ss); }
static inline boolx4 eqs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return eq_u64x4(v, ss); }

//
// returns a boolean vector where each component is true when that component in 'a' is not equal to that component in 'b'
static inline boolx2 neq_f16x2(f16x2 a, f16x2 b) { return boolx2(neq_f16(a.x, b.x), neq_f16(a.y, b.y)); }
static inline boolx2 neq_f32x2(f32x2 a, f32x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_f64x2(f64x2 a, f64x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_s8x2(s8x2 a, s8x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_s16x2(s16x2 a, s16x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_s32x2(s32x2 a, s32x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_s64x2(s64x2 a, s64x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_u8x2(u8x2 a, u8x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_u16x2(u16x2 a, u16x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_u32x2(u32x2 a, u32x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx2 neq_u64x2(u64x2 a, u64x2 b) { return boolx2(a.x != b.x, a.y != b.y); }
static inline boolx3 neq_f16x3(f16x3 a, f16x3 b) { return boolx3(neq_f16(a.x, b.x), neq_f16(a.y, b.y), neq_f16(a.z, b.z)); }
static inline boolx3 neq_f32x3(f32x3 a, f32x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_f64x3(f64x3 a, f64x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_s8x3(s8x3 a, s8x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_s16x3(s16x3 a, s16x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_s32x3(s32x3 a, s32x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_s64x3(s64x3 a, s64x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_u8x3(u8x3 a, u8x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_u16x3(u16x3 a, u16x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_u32x3(u32x3 a, u32x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx3 neq_u64x3(u64x3 a, u64x3 b) { return boolx3(a.x != b.x, a.y != b.y, a.z != b.z); }
static inline boolx4 neq_f16x4(f16x4 a, f16x4 b) { return boolx4(neq_f16(a.x, b.x), neq_f16(a.y, b.y), neq_f16(a.z, b.z), neq_f16(a.w, b.w)); }
static inline boolx4 neq_f32x4(f32x4 a, f32x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_f64x4(f64x4 a, f64x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_s8x4(s8x4 a, s8x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_s16x4(s16x4 a, s16x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_s32x4(s32x4 a, s32x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_s64x4(s64x4 a, s64x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_u8x4(u8x4 a, u8x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_u16x4(u16x4 a, u16x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_u32x4(u32x4 a, u32x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }
static inline boolx4 neq_u64x4(u64x4 a, u64x4 b) { return boolx4(a.x != b.x, a.y != b.y, a.z != b.z, a.w != b.w); }

//
// returns a boolean vector where each component is true when that component in 'v' is not equal to the value 's'
static inline boolx2 neqs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return neq_f16x2(v, ss); }
static inline boolx2 neqs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return neq_f32x2(v, ss); }
static inline boolx2 neqs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return neq_f64x2(v, ss); }
static inline boolx2 neqs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return neq_s8x2(v, ss); }
static inline boolx2 neqs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return neq_s16x2(v, ss); }
static inline boolx2 neqs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return neq_s32x2(v, ss); }
static inline boolx2 neqs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return neq_s64x2(v, ss); }
static inline boolx2 neqs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return neq_u8x2(v, ss); }
static inline boolx2 neqs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return neq_u16x2(v, ss); }
static inline boolx2 neqs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return neq_u32x2(v, ss); }
static inline boolx2 neqs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return neq_u64x2(v, ss); }
static inline boolx3 neqs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return neq_f16x3(v, ss); }
static inline boolx3 neqs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return neq_f32x3(v, ss); }
static inline boolx3 neqs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return neq_f64x3(v, ss); }
static inline boolx3 neqs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return neq_s8x3(v, ss); }
static inline boolx3 neqs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return neq_s16x3(v, ss); }
static inline boolx3 neqs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return neq_s32x3(v, ss); }
static inline boolx3 neqs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return neq_s64x3(v, ss); }
static inline boolx3 neqs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return neq_u8x3(v, ss); }
static inline boolx3 neqs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return neq_u16x3(v, ss); }
static inline boolx3 neqs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return neq_u32x3(v, ss); }
static inline boolx3 neqs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return neq_u64x3(v, ss); }
static inline boolx4 neqs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return neq_f16x4(v, ss); }
static inline boolx4 neqs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return neq_f32x4(v, ss); }
static inline boolx4 neqs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return neq_f64x4(v, ss); }
static inline boolx4 neqs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return neq_s8x4(v, ss); }
static inline boolx4 neqs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return neq_s16x4(v, ss); }
static inline boolx4 neqs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return neq_s32x4(v, ss); }
static inline boolx4 neqs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return neq_s64x4(v, ss); }
static inline boolx4 neqs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return neq_u8x4(v, ss); }
static inline boolx4 neqs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return neq_u16x4(v, ss); }
static inline boolx4 neqs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return neq_u32x4(v, ss); }
static inline boolx4 neqs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return neq_u64x4(v, ss); }

//
// returns a boolean vector where each component is true when that component in 'a' is less than to that component in 'b'
static inline boolx2 lt_f16x2(f16x2 a, f16x2 b) { return boolx2(lt_f16(a.x, b.x), lt_f16(a.y, b.y)); }
static inline boolx2 lt_f32x2(f32x2 a, f32x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_f64x2(f64x2 a, f64x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_s8x2(s8x2 a, s8x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_s16x2(s16x2 a, s16x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_s32x2(s32x2 a, s32x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_s64x2(s64x2 a, s64x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_u8x2(u8x2 a, u8x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_u16x2(u16x2 a, u16x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_u32x2(u32x2 a, u32x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx2 lt_u64x2(u64x2 a, u64x2 b) { return boolx2(a.x < b.x, a.y < b.y); }
static inline boolx3 lt_f16x3(f16x3 a, f16x3 b) { return boolx3(lt_f16(a.x, b.x), lt_f16(a.y, b.y), lt_f16(a.z, b.z)); }
static inline boolx3 lt_f32x3(f32x3 a, f32x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_f64x3(f64x3 a, f64x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_s8x3(s8x3 a, s8x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_s16x3(s16x3 a, s16x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_s32x3(s32x3 a, s32x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_s64x3(s64x3 a, s64x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_u8x3(u8x3 a, u8x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_u16x3(u16x3 a, u16x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_u32x3(u32x3 a, u32x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx3 lt_u64x3(u64x3 a, u64x3 b) { return boolx3(a.x < b.x, a.y < b.y, a.z < b.z); }
static inline boolx4 lt_f16x4(f16x4 a, f16x4 b) { return boolx4(lt_f16(a.x, b.x), lt_f16(a.y, b.y), lt_f16(a.z, b.z), lt_f16(a.w, b.w)); }
static inline boolx4 lt_f32x4(f32x4 a, f32x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_f64x4(f64x4 a, f64x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_s8x4(s8x4 a, s8x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_s16x4(s16x4 a, s16x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_s32x4(s32x4 a, s32x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_s64x4(s64x4 a, s64x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_u8x4(u8x4 a, u8x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_u16x4(u16x4 a, u16x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_u32x4(u32x4 a, u32x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }
static inline boolx4 lt_u64x4(u64x4 a, u64x4 b) { return boolx4(a.x < b.x, a.y < b.y, a.z < b.z, a.w < b.w); }

//
// returns a boolean vector where each component is true when that component in 'v' is less than to the value 's'
static inline boolx2 lts_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return lt_f16x2(v, ss); }
static inline boolx2 lts_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return lt_f32x2(v, ss); }
static inline boolx2 lts_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return lt_f64x2(v, ss); }
static inline boolx2 lts_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return lt_s8x2(v, ss); }
static inline boolx2 lts_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return lt_s16x2(v, ss); }
static inline boolx2 lts_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return lt_s32x2(v, ss); }
static inline boolx2 lts_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return lt_s64x2(v, ss); }
static inline boolx2 lts_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return lt_u8x2(v, ss); }
static inline boolx2 lts_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return lt_u16x2(v, ss); }
static inline boolx2 lts_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return lt_u32x2(v, ss); }
static inline boolx2 lts_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return lt_u64x2(v, ss); }
static inline boolx3 lts_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return lt_f16x3(v, ss); }
static inline boolx3 lts_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return lt_f32x3(v, ss); }
static inline boolx3 lts_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return lt_f64x3(v, ss); }
static inline boolx3 lts_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return lt_s8x3(v, ss); }
static inline boolx3 lts_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return lt_s16x3(v, ss); }
static inline boolx3 lts_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return lt_s32x3(v, ss); }
static inline boolx3 lts_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return lt_s64x3(v, ss); }
static inline boolx3 lts_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return lt_u8x3(v, ss); }
static inline boolx3 lts_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return lt_u16x3(v, ss); }
static inline boolx3 lts_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return lt_u32x3(v, ss); }
static inline boolx3 lts_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return lt_u64x3(v, ss); }
static inline boolx4 lts_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return lt_f16x4(v, ss); }
static inline boolx4 lts_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return lt_f32x4(v, ss); }
static inline boolx4 lts_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return lt_f64x4(v, ss); }
static inline boolx4 lts_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return lt_s8x4(v, ss); }
static inline boolx4 lts_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return lt_s16x4(v, ss); }
static inline boolx4 lts_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return lt_s32x4(v, ss); }
static inline boolx4 lts_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return lt_s64x4(v, ss); }
static inline boolx4 lts_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return lt_u8x4(v, ss); }
static inline boolx4 lts_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return lt_u16x4(v, ss); }
static inline boolx4 lts_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return lt_u32x4(v, ss); }
static inline boolx4 lts_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return lt_u64x4(v, ss); }

//
// returns a boolean vector where each component is true when that component in 'a' is less than or equal to that component in 'b'
static inline boolx2 lteq_f16x2(f16x2 a, f16x2 b) { return boolx2(lteq_f16(a.x, b.x), lteq_f16(a.y, b.y)); }
static inline boolx2 lteq_f32x2(f32x2 a, f32x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_f64x2(f64x2 a, f64x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_s8x2(s8x2 a, s8x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_s16x2(s16x2 a, s16x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_s32x2(s32x2 a, s32x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_s64x2(s64x2 a, s64x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_u8x2(u8x2 a, u8x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_u16x2(u16x2 a, u16x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_u32x2(u32x2 a, u32x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx2 lteq_u64x2(u64x2 a, u64x2 b) { return boolx2(a.x <= b.x, a.y <= b.y); }
static inline boolx3 lteq_f16x3(f16x3 a, f16x3 b) { return boolx3(lteq_f16(a.x, b.x), lteq_f16(a.y, b.y), lteq_f16(a.z, b.z)); }
static inline boolx3 lteq_f32x3(f32x3 a, f32x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_f64x3(f64x3 a, f64x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_s8x3(s8x3 a, s8x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_s16x3(s16x3 a, s16x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_s32x3(s32x3 a, s32x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_s64x3(s64x3 a, s64x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_u8x3(u8x3 a, u8x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_u16x3(u16x3 a, u16x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_u32x3(u32x3 a, u32x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx3 lteq_u64x3(u64x3 a, u64x3 b) { return boolx3(a.x <= b.x, a.y <= b.y, a.z <= b.z); }
static inline boolx4 lteq_f16x4(f16x4 a, f16x4 b) { return boolx4(lteq_f16(a.x, b.x), lteq_f16(a.y, b.y), lteq_f16(a.z, b.z), lteq_f16(a.w, b.w)); }
static inline boolx4 lteq_f32x4(f32x4 a, f32x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_f64x4(f64x4 a, f64x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_s8x4(s8x4 a, s8x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_s16x4(s16x4 a, s16x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_s32x4(s32x4 a, s32x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_s64x4(s64x4 a, s64x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_u8x4(u8x4 a, u8x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_u16x4(u16x4 a, u16x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_u32x4(u32x4 a, u32x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }
static inline boolx4 lteq_u64x4(u64x4 a, u64x4 b) { return boolx4(a.x <= b.x, a.y <= b.y, a.z <= b.z, a.w <= b.w); }

//
// returns a boolean vector where each component is true when that component in 'v' is less than or equal to the value 's'
static inline boolx2 lteqs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return lteq_f16x2(v, ss); }
static inline boolx2 lteqs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return lteq_f32x2(v, ss); }
static inline boolx2 lteqs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return lteq_f64x2(v, ss); }
static inline boolx2 lteqs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return lteq_s8x2(v, ss); }
static inline boolx2 lteqs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return lteq_s16x2(v, ss); }
static inline boolx2 lteqs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return lteq_s32x2(v, ss); }
static inline boolx2 lteqs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return lteq_s64x2(v, ss); }
static inline boolx2 lteqs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return lteq_u8x2(v, ss); }
static inline boolx2 lteqs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return lteq_u16x2(v, ss); }
static inline boolx2 lteqs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return lteq_u32x2(v, ss); }
static inline boolx2 lteqs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return lteq_u64x2(v, ss); }
static inline boolx3 lteqs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return lteq_f16x3(v, ss); }
static inline boolx3 lteqs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return lteq_f32x3(v, ss); }
static inline boolx3 lteqs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return lteq_f64x3(v, ss); }
static inline boolx3 lteqs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return lteq_s8x3(v, ss); }
static inline boolx3 lteqs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return lteq_s16x3(v, ss); }
static inline boolx3 lteqs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return lteq_s32x3(v, ss); }
static inline boolx3 lteqs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return lteq_s64x3(v, ss); }
static inline boolx3 lteqs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return lteq_u8x3(v, ss); }
static inline boolx3 lteqs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return lteq_u16x3(v, ss); }
static inline boolx3 lteqs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return lteq_u32x3(v, ss); }
static inline boolx3 lteqs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return lteq_u64x3(v, ss); }
static inline boolx4 lteqs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return lteq_f16x4(v, ss); }
static inline boolx4 lteqs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return lteq_f32x4(v, ss); }
static inline boolx4 lteqs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return lteq_f64x4(v, ss); }
static inline boolx4 lteqs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return lteq_s8x4(v, ss); }
static inline boolx4 lteqs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return lteq_s16x4(v, ss); }
static inline boolx4 lteqs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return lteq_s32x4(v, ss); }
static inline boolx4 lteqs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return lteq_s64x4(v, ss); }
static inline boolx4 lteqs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return lteq_u8x4(v, ss); }
static inline boolx4 lteqs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return lteq_u16x4(v, ss); }
static inline boolx4 lteqs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return lteq_u32x4(v, ss); }
static inline boolx4 lteqs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return lteq_u64x4(v, ss); }

//
// returns a boolean vector where each component is true when that component in 'a' is greater than to that component in 'b'
static inline boolx2 gt_f16x2(f16x2 a, f16x2 b) { return boolx2(gt_f16(a.x, b.x), gt_f16(a.y, b.y)); }
static inline boolx2 gt_f32x2(f32x2 a, f32x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_f64x2(f64x2 a, f64x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_s8x2(s8x2 a, s8x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_s16x2(s16x2 a, s16x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_s32x2(s32x2 a, s32x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_s64x2(s64x2 a, s64x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_u8x2(u8x2 a, u8x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_u16x2(u16x2 a, u16x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_u32x2(u32x2 a, u32x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx2 gt_u64x2(u64x2 a, u64x2 b) { return boolx2(a.x > b.x, a.y > b.y); }
static inline boolx3 gt_f16x3(f16x3 a, f16x3 b) { return boolx3(gt_f16(a.x, b.x), gt_f16(a.y, b.y), gt_f16(a.z, b.z)); }
static inline boolx3 gt_f32x3(f32x3 a, f32x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_f64x3(f64x3 a, f64x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_s8x3(s8x3 a, s8x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_s16x3(s16x3 a, s16x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_s32x3(s32x3 a, s32x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_s64x3(s64x3 a, s64x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_u8x3(u8x3 a, u8x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_u16x3(u16x3 a, u16x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_u32x3(u32x3 a, u32x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx3 gt_u64x3(u64x3 a, u64x3 b) { return boolx3(a.x > b.x, a.y > b.y, a.z > b.z); }
static inline boolx4 gt_f16x4(f16x4 a, f16x4 b) { return boolx4(gt_f16(a.x, b.x), gt_f16(a.y, b.y), gt_f16(a.z, b.z), gt_f16(a.w, b.w)); }
static inline boolx4 gt_f32x4(f32x4 a, f32x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_f64x4(f64x4 a, f64x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_s8x4(s8x4 a, s8x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_s16x4(s16x4 a, s16x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_s32x4(s32x4 a, s32x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_s64x4(s64x4 a, s64x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_u8x4(u8x4 a, u8x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_u16x4(u16x4 a, u16x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_u32x4(u32x4 a, u32x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }
static inline boolx4 gt_u64x4(u64x4 a, u64x4 b) { return boolx4(a.x > b.x, a.y > b.y, a.z > b.z, a.w > b.w); }

//
// returns a boolean vector where each component is true when that component in 'v' is greater than to the value 's'
static inline boolx2 gts_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return gt_f16x2(v, ss); }
static inline boolx2 gts_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return gt_f32x2(v, ss); }
static inline boolx2 gts_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return gt_f64x2(v, ss); }
static inline boolx2 gts_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return gt_s8x2(v, ss); }
static inline boolx2 gts_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return gt_s16x2(v, ss); }
static inline boolx2 gts_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return gt_s32x2(v, ss); }
static inline boolx2 gts_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return gt_s64x2(v, ss); }
static inline boolx2 gts_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return gt_u8x2(v, ss); }
static inline boolx2 gts_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return gt_u16x2(v, ss); }
static inline boolx2 gts_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return gt_u32x2(v, ss); }
static inline boolx2 gts_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return gt_u64x2(v, ss); }
static inline boolx3 gts_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return gt_f16x3(v, ss); }
static inline boolx3 gts_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return gt_f32x3(v, ss); }
static inline boolx3 gts_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return gt_f64x3(v, ss); }
static inline boolx3 gts_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return gt_s8x3(v, ss); }
static inline boolx3 gts_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return gt_s16x3(v, ss); }
static inline boolx3 gts_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return gt_s32x3(v, ss); }
static inline boolx3 gts_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return gt_s64x3(v, ss); }
static inline boolx3 gts_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return gt_u8x3(v, ss); }
static inline boolx3 gts_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return gt_u16x3(v, ss); }
static inline boolx3 gts_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return gt_u32x3(v, ss); }
static inline boolx3 gts_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return gt_u64x3(v, ss); }
static inline boolx4 gts_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return gt_f16x4(v, ss); }
static inline boolx4 gts_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return gt_f32x4(v, ss); }
static inline boolx4 gts_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return gt_f64x4(v, ss); }
static inline boolx4 gts_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return gt_s8x4(v, ss); }
static inline boolx4 gts_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return gt_s16x4(v, ss); }
static inline boolx4 gts_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return gt_s32x4(v, ss); }
static inline boolx4 gts_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return gt_s64x4(v, ss); }
static inline boolx4 gts_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return gt_u8x4(v, ss); }
static inline boolx4 gts_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return gt_u16x4(v, ss); }
static inline boolx4 gts_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return gt_u32x4(v, ss); }
static inline boolx4 gts_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return gt_u64x4(v, ss); }

//
// returns a boolean vector where each component is true when that component in 'a' is greater than or equal to that component in 'b'
static inline boolx2 gteq_f16x2(f16x2 a, f16x2 b) { return boolx2(gteq_f16(a.x, b.x), gteq_f16(a.y, b.y)); }
static inline boolx2 gteq_f32x2(f32x2 a, f32x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_f64x2(f64x2 a, f64x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_s8x2(s8x2 a, s8x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_s16x2(s16x2 a, s16x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_s32x2(s32x2 a, s32x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_s64x2(s64x2 a, s64x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_u8x2(u8x2 a, u8x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_u16x2(u16x2 a, u16x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_u32x2(u32x2 a, u32x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx2 gteq_u64x2(u64x2 a, u64x2 b) { return boolx2(a.x >= b.x, a.y >= b.y); }
static inline boolx3 gteq_f16x3(f16x3 a, f16x3 b) { return boolx3(gteq_f16(a.x, b.x), gteq_f16(a.y, b.y), gteq_f16(a.z, b.z)); }
static inline boolx3 gteq_f32x3(f32x3 a, f32x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_f64x3(f64x3 a, f64x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_s8x3(s8x3 a, s8x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_s16x3(s16x3 a, s16x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_s32x3(s32x3 a, s32x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_s64x3(s64x3 a, s64x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_u8x3(u8x3 a, u8x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_u16x3(u16x3 a, u16x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_u32x3(u32x3 a, u32x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx3 gteq_u64x3(u64x3 a, u64x3 b) { return boolx3(a.x >= b.x, a.y >= b.y, a.z >= b.z); }
static inline boolx4 gteq_f16x4(f16x4 a, f16x4 b) { return boolx4(gteq_f16(a.x, b.x), gteq_f16(a.y, b.y), gteq_f16(a.z, b.z), gteq_f16(a.w, b.w)); }
static inline boolx4 gteq_f32x4(f32x4 a, f32x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_f64x4(f64x4 a, f64x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_s8x4(s8x4 a, s8x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_s16x4(s16x4 a, s16x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_s32x4(s32x4 a, s32x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_s64x4(s64x4 a, s64x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_u8x4(u8x4 a, u8x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_u16x4(u16x4 a, u16x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_u32x4(u32x4 a, u32x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }
static inline boolx4 gteq_u64x4(u64x4 a, u64x4 b) { return boolx4(a.x >= b.x, a.y >= b.y, a.z >= b.z, a.w >= b.w); }

//
// returns a boolean vector where each component is true when that component in 'v' is greater than or equal to the value 's'
static inline boolx2 gteqs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return gteq_f16x2(v, ss); }
static inline boolx2 gteqs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return gteq_f32x2(v, ss); }
static inline boolx2 gteqs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return gteq_f64x2(v, ss); }
static inline boolx2 gteqs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return gteq_s8x2(v, ss); }
static inline boolx2 gteqs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return gteq_s16x2(v, ss); }
static inline boolx2 gteqs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return gteq_s32x2(v, ss); }
static inline boolx2 gteqs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return gteq_s64x2(v, ss); }
static inline boolx2 gteqs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return gteq_u8x2(v, ss); }
static inline boolx2 gteqs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return gteq_u16x2(v, ss); }
static inline boolx2 gteqs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return gteq_u32x2(v, ss); }
static inline boolx2 gteqs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return gteq_u64x2(v, ss); }
static inline boolx3 gteqs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return gteq_f16x3(v, ss); }
static inline boolx3 gteqs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return gteq_f32x3(v, ss); }
static inline boolx3 gteqs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return gteq_f64x3(v, ss); }
static inline boolx3 gteqs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return gteq_s8x3(v, ss); }
static inline boolx3 gteqs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return gteq_s16x3(v, ss); }
static inline boolx3 gteqs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return gteq_s32x3(v, ss); }
static inline boolx3 gteqs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return gteq_s64x3(v, ss); }
static inline boolx3 gteqs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return gteq_u8x3(v, ss); }
static inline boolx3 gteqs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return gteq_u16x3(v, ss); }
static inline boolx3 gteqs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return gteq_u32x3(v, ss); }
static inline boolx3 gteqs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return gteq_u64x3(v, ss); }
static inline boolx4 gteqs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return gteq_f16x4(v, ss); }
static inline boolx4 gteqs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return gteq_f32x4(v, ss); }
static inline boolx4 gteqs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return gteq_f64x4(v, ss); }
static inline boolx4 gteqs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return gteq_s8x4(v, ss); }
static inline boolx4 gteqs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return gteq_s16x4(v, ss); }
static inline boolx4 gteqs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return gteq_s32x4(v, ss); }
static inline boolx4 gteqs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return gteq_s64x4(v, ss); }
static inline boolx4 gteqs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return gteq_u8x4(v, ss); }
static inline boolx4 gteqs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return gteq_u16x4(v, ss); }
static inline boolx4 gteqs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return gteq_u32x4(v, ss); }
static inline boolx4 gteqs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return gteq_u64x4(v, ss); }

//
// returns a vector where each component is the result from negating that component in 'v'
static inline f16x2 neg_f16x2(f16x2 v) { return f16x2(neg_f16(v.x), neg_f16(v.y)); }
static inline f32x2 neg_f32x2(f32x2 v) { return f32x2(-v.x, -v.y); }
static inline f64x2 neg_f64x2(f64x2 v) { return f64x2(-v.x, -v.y); }
static inline s8x2 neg_s8x2(s8x2 v) { return s8x2(-v.x, -v.y); }
static inline s16x2 neg_s16x2(s16x2 v) { return s16x2(-v.x, -v.y); }
static inline s32x2 neg_s32x2(s32x2 v) { return s32x2(-v.x, -v.y); }
static inline s64x2 neg_s64x2(s64x2 v) { return s64x2(-v.x, -v.y); }
static inline u8x2 neg_u8x2(u8x2 v) { return u8x2(-v.x, -v.y); }
static inline u16x2 neg_u16x2(u16x2 v) { return u16x2(-v.x, -v.y); }
static inline u32x2 neg_u32x2(u32x2 v) { return u32x2(-v.x, -v.y); }
static inline u64x2 neg_u64x2(u64x2 v) { return u64x2(-v.x, -v.y); }
static inline f16x3 neg_f16x3(f16x3 v) { return f16x3(neg_f16(v.x), neg_f16(v.y), neg_f16(v.z)); }
static inline f32x3 neg_f32x3(f32x3 v) { return f32x3(-v.x, -v.y, -v.z); }
static inline f64x3 neg_f64x3(f64x3 v) { return f64x3(-v.x, -v.y, -v.z); }
static inline s8x3 neg_s8x3(s8x3 v) { return s8x3(-v.x, -v.y, -v.z); }
static inline s16x3 neg_s16x3(s16x3 v) { return s16x3(-v.x, -v.y, -v.z); }
static inline s32x3 neg_s32x3(s32x3 v) { return s32x3(-v.x, -v.y, -v.z); }
static inline s64x3 neg_s64x3(s64x3 v) { return s64x3(-v.x, -v.y, -v.z); }
static inline u8x3 neg_u8x3(u8x3 v) { return u8x3(-v.x, -v.y, -v.z); }
static inline u16x3 neg_u16x3(u16x3 v) { return u16x3(-v.x, -v.y, -v.z); }
static inline u32x3 neg_u32x3(u32x3 v) { return u32x3(-v.x, -v.y, -v.z); }
static inline u64x3 neg_u64x3(u64x3 v) { return u64x3(-v.x, -v.y, -v.z); }
static inline f16x4 neg_f16x4(f16x4 v) { return f16x4(neg_f16(v.x), neg_f16(v.y), neg_f16(v.z), neg_f16(v.w)); }
static inline f32x4 neg_f32x4(f32x4 v) { return f32x4(-v.x, -v.y, -v.z, -v.w); }
static inline f64x4 neg_f64x4(f64x4 v) { return f64x4(-v.x, -v.y, -v.z, -v.w); }
static inline s8x4 neg_s8x4(s8x4 v) { return s8x4(-v.x, -v.y, -v.z, -v.w); }
static inline s16x4 neg_s16x4(s16x4 v) { return s16x4(-v.x, -v.y, -v.z, -v.w); }
static inline s32x4 neg_s32x4(s32x4 v) { return s32x4(-v.x, -v.y, -v.z, -v.w); }
static inline s64x4 neg_s64x4(s64x4 v) { return s64x4(-v.x, -v.y, -v.z, -v.w); }
static inline u8x4 neg_u8x4(u8x4 v) { return u8x4(-v.x, -v.y, -v.z, -v.w); }
static inline u16x4 neg_u16x4(u16x4 v) { return u16x4(-v.x, -v.y, -v.z, -v.w); }
static inline u32x4 neg_u32x4(u32x4 v) { return u32x4(-v.x, -v.y, -v.z, -v.w); }
static inline u64x4 neg_u64x4(u64x4 v) { return u64x4(-v.x, -v.y, -v.z, -v.w); }

//
// returns a vector where each component is the minimum between that component in 'a' and that component in 'b'
static inline f16x2 min_f16x2(f16x2 a, f16x2 b) { return f16x2(min_f16(a.x, b.x), min_f16(a.y, b.y)); }
static inline f32x2 min_f32x2(f32x2 a, f32x2 b) { return f32x2(min_f32(a.x, b.x), min_f32(a.y, b.y)); }
static inline f64x2 min_f64x2(f64x2 a, f64x2 b) { return f64x2(min_f64(a.x, b.x), min_f64(a.y, b.y)); }
static inline s8x2 min_s8x2(s8x2 a, s8x2 b) { return s8x2(min_s8(a.x, b.x), min_s8(a.y, b.y)); }
static inline s16x2 min_s16x2(s16x2 a, s16x2 b) { return s16x2(min_s16(a.x, b.x), min_s16(a.y, b.y)); }
static inline s32x2 min_s32x2(s32x2 a, s32x2 b) { return s32x2(min_s32(a.x, b.x), min_s32(a.y, b.y)); }
static inline s64x2 min_s64x2(s64x2 a, s64x2 b) { return s64x2(min_s64(a.x, b.x), min_s64(a.y, b.y)); }
static inline u8x2 min_u8x2(u8x2 a, u8x2 b) { return u8x2(min_u8(a.x, b.x), min_u8(a.y, b.y)); }
static inline u16x2 min_u16x2(u16x2 a, u16x2 b) { return u16x2(min_u16(a.x, b.x), min_u16(a.y, b.y)); }
static inline u32x2 min_u32x2(u32x2 a, u32x2 b) { return u32x2(min_u32(a.x, b.x), min_u32(a.y, b.y)); }
static inline u64x2 min_u64x2(u64x2 a, u64x2 b) { return u64x2(min_u64(a.x, b.x), min_u64(a.y, b.y)); }
static inline f16x3 min_f16x3(f16x3 a, f16x3 b) { return f16x3(min_f16(a.x, b.x), min_f16(a.y, b.y), min_f16(a.z, b.z)); }
static inline f32x3 min_f32x3(f32x3 a, f32x3 b) { return f32x3(min_f32(a.x, b.x), min_f32(a.y, b.y), min_f32(a.z, b.z)); }
static inline f64x3 min_f64x3(f64x3 a, f64x3 b) { return f64x3(min_f64(a.x, b.x), min_f64(a.y, b.y), min_f64(a.z, b.z)); }
static inline s8x3 min_s8x3(s8x3 a, s8x3 b) { return s8x3(min_s8(a.x, b.x), min_s8(a.y, b.y), min_s8(a.z, b.z)); }
static inline s16x3 min_s16x3(s16x3 a, s16x3 b) { return s16x3(min_s16(a.x, b.x), min_s16(a.y, b.y), min_s16(a.z, b.z)); }
static inline s32x3 min_s32x3(s32x3 a, s32x3 b) { return s32x3(min_s32(a.x, b.x), min_s32(a.y, b.y), min_s32(a.z, b.z)); }
static inline s64x3 min_s64x3(s64x3 a, s64x3 b) { return s64x3(min_s64(a.x, b.x), min_s64(a.y, b.y), min_s64(a.z, b.z)); }
static inline u8x3 min_u8x3(u8x3 a, u8x3 b) { return u8x3(min_u8(a.x, b.x), min_u8(a.y, b.y), min_u8(a.z, b.z)); }
static inline u16x3 min_u16x3(u16x3 a, u16x3 b) { return u16x3(min_u16(a.x, b.x), min_u16(a.y, b.y), min_u16(a.z, b.z)); }
static inline u32x3 min_u32x3(u32x3 a, u32x3 b) { return u32x3(min_u32(a.x, b.x), min_u32(a.y, b.y), min_u32(a.z, b.z)); }
static inline u64x3 min_u64x3(u64x3 a, u64x3 b) { return u64x3(min_u64(a.x, b.x), min_u64(a.y, b.y), min_u64(a.z, b.z)); }
static inline f16x4 min_f16x4(f16x4 a, f16x4 b) { return f16x4(min_f16(a.x, b.x), min_f16(a.y, b.y), min_f16(a.z, b.z), min_f16(a.w, b.w)); }
static inline f32x4 min_f32x4(f32x4 a, f32x4 b) { return f32x4(min_f32(a.x, b.x), min_f32(a.y, b.y), min_f32(a.z, b.z), min_f32(a.w, b.w)); }
static inline f64x4 min_f64x4(f64x4 a, f64x4 b) { return f64x4(min_f64(a.x, b.x), min_f64(a.y, b.y), min_f64(a.z, b.z), min_f64(a.w, b.w)); }
static inline s8x4 min_s8x4(s8x4 a, s8x4 b) { return s8x4(min_s8(a.x, b.x), min_s8(a.y, b.y), min_s8(a.z, b.z), min_s8(a.w, b.w)); }
static inline s16x4 min_s16x4(s16x4 a, s16x4 b) { return s16x4(min_s16(a.x, b.x), min_s16(a.y, b.y), min_s16(a.z, b.z), min_s16(a.w, b.w)); }
static inline s32x4 min_s32x4(s32x4 a, s32x4 b) { return s32x4(min_s32(a.x, b.x), min_s32(a.y, b.y), min_s32(a.z, b.z), min_s32(a.w, b.w)); }
static inline s64x4 min_s64x4(s64x4 a, s64x4 b) { return s64x4(min_s64(a.x, b.x), min_s64(a.y, b.y), min_s64(a.z, b.z), min_s64(a.w, b.w)); }
static inline u8x4 min_u8x4(u8x4 a, u8x4 b) { return u8x4(min_u8(a.x, b.x), min_u8(a.y, b.y), min_u8(a.z, b.z), min_u8(a.w, b.w)); }
static inline u16x4 min_u16x4(u16x4 a, u16x4 b) { return u16x4(min_u16(a.x, b.x), min_u16(a.y, b.y), min_u16(a.z, b.z), min_u16(a.w, b.w)); }
static inline u32x4 min_u32x4(u32x4 a, u32x4 b) { return u32x4(min_u32(a.x, b.x), min_u32(a.y, b.y), min_u32(a.z, b.z), min_u32(a.w, b.w)); }
static inline u64x4 min_u64x4(u64x4 a, u64x4 b) { return u64x4(min_u64(a.x, b.x), min_u64(a.y, b.y), min_u64(a.z, b.z), min_u64(a.w, b.w)); }

//
// returns a vector where each component is the minimum between that component in 'a' and 's'
static inline f16x2 mins_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return min_f16x2(v, ss); }
static inline f32x2 mins_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return min_f32x2(v, ss); }
static inline f64x2 mins_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return min_f64x2(v, ss); }
static inline s8x2 mins_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return min_s8x2(v, ss); }
static inline s16x2 mins_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return min_s16x2(v, ss); }
static inline s32x2 mins_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return min_s32x2(v, ss); }
static inline s64x2 mins_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return min_s64x2(v, ss); }
static inline u8x2 mins_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return min_u8x2(v, ss); }
static inline u16x2 mins_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return min_u16x2(v, ss); }
static inline u32x2 mins_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return min_u32x2(v, ss); }
static inline u64x2 mins_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return min_u64x2(v, ss); }
static inline f16x3 mins_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return min_f16x3(v, ss); }
static inline f32x3 mins_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return min_f32x3(v, ss); }
static inline f64x3 mins_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return min_f64x3(v, ss); }
static inline s8x3 mins_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return min_s8x3(v, ss); }
static inline s16x3 mins_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return min_s16x3(v, ss); }
static inline s32x3 mins_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return min_s32x3(v, ss); }
static inline s64x3 mins_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return min_s64x3(v, ss); }
static inline u8x3 mins_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return min_u8x3(v, ss); }
static inline u16x3 mins_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return min_u16x3(v, ss); }
static inline u32x3 mins_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return min_u32x3(v, ss); }
static inline u64x3 mins_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return min_u64x3(v, ss); }
static inline f16x4 mins_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return min_f16x4(v, ss); }
static inline f32x4 mins_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return min_f32x4(v, ss); }
static inline f64x4 mins_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return min_f64x4(v, ss); }
static inline s8x4 mins_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return min_s8x4(v, ss); }
static inline s16x4 mins_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return min_s16x4(v, ss); }
static inline s32x4 mins_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return min_s32x4(v, ss); }
static inline s64x4 mins_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return min_s64x4(v, ss); }
static inline u8x4 mins_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return min_u8x4(v, ss); }
static inline u16x4 mins_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return min_u16x4(v, ss); }
static inline u32x4 mins_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return min_u32x4(v, ss); }
static inline u64x4 mins_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return min_u64x4(v, ss); }

//
// returns a vector where each component is the maximum between that component in 'a' and that component in 'b'
static inline f16x2 max_f16x2(f16x2 a, f16x2 b) { return f16x2(max_f16(a.x, b.x), max_f16(a.y, b.y)); }
static inline f32x2 max_f32x2(f32x2 a, f32x2 b) { return f32x2(max_f32(a.x, b.x), max_f32(a.y, b.y)); }
static inline f64x2 max_f64x2(f64x2 a, f64x2 b) { return f64x2(max_f64(a.x, b.x), max_f64(a.y, b.y)); }
static inline s8x2 max_s8x2(s8x2 a, s8x2 b) { return s8x2(max_s8(a.x, b.x), max_s8(a.y, b.y)); }
static inline s16x2 max_s16x2(s16x2 a, s16x2 b) { return s16x2(max_s16(a.x, b.x), max_s16(a.y, b.y)); }
static inline s32x2 max_s32x2(s32x2 a, s32x2 b) { return s32x2(max_s32(a.x, b.x), max_s32(a.y, b.y)); }
static inline s64x2 max_s64x2(s64x2 a, s64x2 b) { return s64x2(max_s64(a.x, b.x), max_s64(a.y, b.y)); }
static inline u8x2 max_u8x2(u8x2 a, u8x2 b) { return u8x2(max_u8(a.x, b.x), max_u8(a.y, b.y)); }
static inline u16x2 max_u16x2(u16x2 a, u16x2 b) { return u16x2(max_u16(a.x, b.x), max_u16(a.y, b.y)); }
static inline u32x2 max_u32x2(u32x2 a, u32x2 b) { return u32x2(max_u32(a.x, b.x), max_u32(a.y, b.y)); }
static inline u64x2 max_u64x2(u64x2 a, u64x2 b) { return u64x2(max_u64(a.x, b.x), max_u64(a.y, b.y)); }
static inline f16x3 max_f16x3(f16x3 a, f16x3 b) { return f16x3(max_f16(a.x, b.x), max_f16(a.y, b.y), max_f16(a.z, b.z)); }
static inline f32x3 max_f32x3(f32x3 a, f32x3 b) { return f32x3(max_f32(a.x, b.x), max_f32(a.y, b.y), max_f32(a.z, b.z)); }
static inline f64x3 max_f64x3(f64x3 a, f64x3 b) { return f64x3(max_f64(a.x, b.x), max_f64(a.y, b.y), max_f64(a.z, b.z)); }
static inline s8x3 max_s8x3(s8x3 a, s8x3 b) { return s8x3(max_s8(a.x, b.x), max_s8(a.y, b.y), max_s8(a.z, b.z)); }
static inline s16x3 max_s16x3(s16x3 a, s16x3 b) { return s16x3(max_s16(a.x, b.x), max_s16(a.y, b.y), max_s16(a.z, b.z)); }
static inline s32x3 max_s32x3(s32x3 a, s32x3 b) { return s32x3(max_s32(a.x, b.x), max_s32(a.y, b.y), max_s32(a.z, b.z)); }
static inline s64x3 max_s64x3(s64x3 a, s64x3 b) { return s64x3(max_s64(a.x, b.x), max_s64(a.y, b.y), max_s64(a.z, b.z)); }
static inline u8x3 max_u8x3(u8x3 a, u8x3 b) { return u8x3(max_u8(a.x, b.x), max_u8(a.y, b.y), max_u8(a.z, b.z)); }
static inline u16x3 max_u16x3(u16x3 a, u16x3 b) { return u16x3(max_u16(a.x, b.x), max_u16(a.y, b.y), max_u16(a.z, b.z)); }
static inline u32x3 max_u32x3(u32x3 a, u32x3 b) { return u32x3(max_u32(a.x, b.x), max_u32(a.y, b.y), max_u32(a.z, b.z)); }
static inline u64x3 max_u64x3(u64x3 a, u64x3 b) { return u64x3(max_u64(a.x, b.x), max_u64(a.y, b.y), max_u64(a.z, b.z)); }
static inline f16x4 max_f16x4(f16x4 a, f16x4 b) { return f16x4(max_f16(a.x, b.x), max_f16(a.y, b.y), max_f16(a.z, b.z), max_f16(a.w, b.w)); }
static inline f32x4 max_f32x4(f32x4 a, f32x4 b) { return f32x4(max_f32(a.x, b.x), max_f32(a.y, b.y), max_f32(a.z, b.z), max_f32(a.w, b.w)); }
static inline f64x4 max_f64x4(f64x4 a, f64x4 b) { return f64x4(max_f64(a.x, b.x), max_f64(a.y, b.y), max_f64(a.z, b.z), max_f64(a.w, b.w)); }
static inline s8x4 max_s8x4(s8x4 a, s8x4 b) { return s8x4(max_s8(a.x, b.x), max_s8(a.y, b.y), max_s8(a.z, b.z), max_s8(a.w, b.w)); }
static inline s16x4 max_s16x4(s16x4 a, s16x4 b) { return s16x4(max_s16(a.x, b.x), max_s16(a.y, b.y), max_s16(a.z, b.z), max_s16(a.w, b.w)); }
static inline s32x4 max_s32x4(s32x4 a, s32x4 b) { return s32x4(max_s32(a.x, b.x), max_s32(a.y, b.y), max_s32(a.z, b.z), max_s32(a.w, b.w)); }
static inline s64x4 max_s64x4(s64x4 a, s64x4 b) { return s64x4(max_s64(a.x, b.x), max_s64(a.y, b.y), max_s64(a.z, b.z), max_s64(a.w, b.w)); }
static inline u8x4 max_u8x4(u8x4 a, u8x4 b) { return u8x4(max_u8(a.x, b.x), max_u8(a.y, b.y), max_u8(a.z, b.z), max_u8(a.w, b.w)); }
static inline u16x4 max_u16x4(u16x4 a, u16x4 b) { return u16x4(max_u16(a.x, b.x), max_u16(a.y, b.y), max_u16(a.z, b.z), max_u16(a.w, b.w)); }
static inline u32x4 max_u32x4(u32x4 a, u32x4 b) { return u32x4(max_u32(a.x, b.x), max_u32(a.y, b.y), max_u32(a.z, b.z), max_u32(a.w, b.w)); }
static inline u64x4 max_u64x4(u64x4 a, u64x4 b) { return u64x4(max_u64(a.x, b.x), max_u64(a.y, b.y), max_u64(a.z, b.z), max_u64(a.w, b.w)); }

//
// returns a vector where each component is the maximum between that component in 'a' and 's'
static inline f16x2 maxs_f16x2(f16x2 v, half s) { f16x2 ss = f16x2s(s); return max_f16x2(v, ss); }
static inline f32x2 maxs_f32x2(f32x2 v, float s) { f32x2 ss = f32x2s(s); return max_f32x2(v, ss); }
static inline f64x2 maxs_f64x2(f64x2 v, double s) { f64x2 ss = f64x2s(s); return max_f64x2(v, ss); }
static inline s8x2 maxs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return max_s8x2(v, ss); }
static inline s16x2 maxs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return max_s16x2(v, ss); }
static inline s32x2 maxs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return max_s32x2(v, ss); }
static inline s64x2 maxs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return max_s64x2(v, ss); }
static inline u8x2 maxs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return max_u8x2(v, ss); }
static inline u16x2 maxs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return max_u16x2(v, ss); }
static inline u32x2 maxs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return max_u32x2(v, ss); }
static inline u64x2 maxs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return max_u64x2(v, ss); }
static inline f16x3 maxs_f16x3(f16x3 v, half s) { f16x3 ss = f16x3s(s); return max_f16x3(v, ss); }
static inline f32x3 maxs_f32x3(f32x3 v, float s) { f32x3 ss = f32x3s(s); return max_f32x3(v, ss); }
static inline f64x3 maxs_f64x3(f64x3 v, double s) { f64x3 ss = f64x3s(s); return max_f64x3(v, ss); }
static inline s8x3 maxs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return max_s8x3(v, ss); }
static inline s16x3 maxs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return max_s16x3(v, ss); }
static inline s32x3 maxs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return max_s32x3(v, ss); }
static inline s64x3 maxs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return max_s64x3(v, ss); }
static inline u8x3 maxs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return max_u8x3(v, ss); }
static inline u16x3 maxs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return max_u16x3(v, ss); }
static inline u32x3 maxs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return max_u32x3(v, ss); }
static inline u64x3 maxs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return max_u64x3(v, ss); }
static inline f16x4 maxs_f16x4(f16x4 v, half s) { f16x4 ss = f16x4s(s); return max_f16x4(v, ss); }
static inline f32x4 maxs_f32x4(f32x4 v, float s) { f32x4 ss = f32x4s(s); return max_f32x4(v, ss); }
static inline f64x4 maxs_f64x4(f64x4 v, double s) { f64x4 ss = f64x4s(s); return max_f64x4(v, ss); }
static inline s8x4 maxs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return max_s8x4(v, ss); }
static inline s16x4 maxs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return max_s16x4(v, ss); }
static inline s32x4 maxs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return max_s32x4(v, ss); }
static inline s64x4 maxs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return max_s64x4(v, ss); }
static inline u8x4 maxs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return max_u8x4(v, ss); }
static inline u16x4 maxs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return max_u16x4(v, ss); }
static inline u32x4 maxs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return max_u32x4(v, ss); }
static inline u64x4 maxs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return max_u64x4(v, ss); }

//
// returns a vector where each component is clamped between the minimum value that is the component in 'min' and the maximum value that is the component in 'max'
static inline f16x2 clamp_f16x2(f16x2 v, f16x2 min, f16x2 max) { return f16x2(clamp_f16(v.x, min.x, max.x), clamp_f16(v.y, min.y, max.y)); }
static inline f32x2 clamp_f32x2(f32x2 v, f32x2 min, f32x2 max) { return f32x2(clamp_f32(v.x, min.x, max.x), clamp_f32(v.y, min.y, max.y)); }
static inline f64x2 clamp_f64x2(f64x2 v, f64x2 min, f64x2 max) { return f64x2(clamp_f64(v.x, min.x, max.x), clamp_f64(v.y, min.y, max.y)); }
static inline s8x2 clamp_s8x2(s8x2 v, s8x2 min, s8x2 max) { return s8x2(clamp_s8(v.x, min.x, max.x), clamp_s8(v.y, min.y, max.y)); }
static inline s16x2 clamp_s16x2(s16x2 v, s16x2 min, s16x2 max) { return s16x2(clamp_s16(v.x, min.x, max.x), clamp_s16(v.y, min.y, max.y)); }
static inline s32x2 clamp_s32x2(s32x2 v, s32x2 min, s32x2 max) { return s32x2(clamp_s32(v.x, min.x, max.x), clamp_s32(v.y, min.y, max.y)); }
static inline s64x2 clamp_s64x2(s64x2 v, s64x2 min, s64x2 max) { return s64x2(clamp_s64(v.x, min.x, max.x), clamp_s64(v.y, min.y, max.y)); }
static inline u8x2 clamp_u8x2(u8x2 v, u8x2 min, u8x2 max) { return u8x2(clamp_u8(v.x, min.x, max.x), clamp_u8(v.y, min.y, max.y)); }
static inline u16x2 clamp_u16x2(u16x2 v, u16x2 min, u16x2 max) { return u16x2(clamp_u16(v.x, min.x, max.x), clamp_u16(v.y, min.y, max.y)); }
static inline u32x2 clamp_u32x2(u32x2 v, u32x2 min, u32x2 max) { return u32x2(clamp_u32(v.x, min.x, max.x), clamp_u32(v.y, min.y, max.y)); }
static inline u64x2 clamp_u64x2(u64x2 v, u64x2 min, u64x2 max) { return u64x2(clamp_u64(v.x, min.x, max.x), clamp_u64(v.y, min.y, max.y)); }
static inline f16x3 clamp_f16x3(f16x3 v, f16x3 min, f16x3 max) { return f16x3(clamp_f16(v.x, min.x, max.x), clamp_f16(v.y, min.y, max.y), clamp_f16(v.z, min.z, max.z)); }
static inline f32x3 clamp_f32x3(f32x3 v, f32x3 min, f32x3 max) { return f32x3(clamp_f32(v.x, min.x, max.x), clamp_f32(v.y, min.y, max.y), clamp_f32(v.z, min.z, max.z)); }
static inline f64x3 clamp_f64x3(f64x3 v, f64x3 min, f64x3 max) { return f64x3(clamp_f64(v.x, min.x, max.x), clamp_f64(v.y, min.y, max.y), clamp_f64(v.z, min.z, max.z)); }
static inline s8x3 clamp_s8x3(s8x3 v, s8x3 min, s8x3 max) { return s8x3(clamp_s8(v.x, min.x, max.x), clamp_s8(v.y, min.y, max.y), clamp_s8(v.z, min.z, max.z)); }
static inline s16x3 clamp_s16x3(s16x3 v, s16x3 min, s16x3 max) { return s16x3(clamp_s16(v.x, min.x, max.x), clamp_s16(v.y, min.y, max.y), clamp_s16(v.z, min.z, max.z)); }
static inline s32x3 clamp_s32x3(s32x3 v, s32x3 min, s32x3 max) { return s32x3(clamp_s32(v.x, min.x, max.x), clamp_s32(v.y, min.y, max.y), clamp_s32(v.z, min.z, max.z)); }
static inline s64x3 clamp_s64x3(s64x3 v, s64x3 min, s64x3 max) { return s64x3(clamp_s64(v.x, min.x, max.x), clamp_s64(v.y, min.y, max.y), clamp_s64(v.z, min.z, max.z)); }
static inline u8x3 clamp_u8x3(u8x3 v, u8x3 min, u8x3 max) { return u8x3(clamp_u8(v.x, min.x, max.x), clamp_u8(v.y, min.y, max.y), clamp_u8(v.z, min.z, max.z)); }
static inline u16x3 clamp_u16x3(u16x3 v, u16x3 min, u16x3 max) { return u16x3(clamp_u16(v.x, min.x, max.x), clamp_u16(v.y, min.y, max.y), clamp_u16(v.z, min.z, max.z)); }
static inline u32x3 clamp_u32x3(u32x3 v, u32x3 min, u32x3 max) { return u32x3(clamp_u32(v.x, min.x, max.x), clamp_u32(v.y, min.y, max.y), clamp_u32(v.z, min.z, max.z)); }
static inline u64x3 clamp_u64x3(u64x3 v, u64x3 min, u64x3 max) { return u64x3(clamp_u64(v.x, min.x, max.x), clamp_u64(v.y, min.y, max.y), clamp_u64(v.z, min.z, max.z)); }
static inline f16x4 clamp_f16x4(f16x4 v, f16x4 min, f16x4 max) { return f16x4(clamp_f16(v.x, min.x, max.x), clamp_f16(v.y, min.y, max.y), clamp_f16(v.z, min.z, max.z), clamp_f16(v.w, min.w, max.w)); }
static inline f32x4 clamp_f32x4(f32x4 v, f32x4 min, f32x4 max) { return f32x4(clamp_f32(v.x, min.x, max.x), clamp_f32(v.y, min.y, max.y), clamp_f32(v.z, min.z, max.z), clamp_f32(v.w, min.w, max.w)); }
static inline f64x4 clamp_f64x4(f64x4 v, f64x4 min, f64x4 max) { return f64x4(clamp_f64(v.x, min.x, max.x), clamp_f64(v.y, min.y, max.y), clamp_f64(v.z, min.z, max.z), clamp_f64(v.w, min.w, max.w)); }
static inline s8x4 clamp_s8x4(s8x4 v, s8x4 min, s8x4 max) { return s8x4(clamp_s8(v.x, min.x, max.x), clamp_s8(v.y, min.y, max.y), clamp_s8(v.z, min.z, max.z), clamp_s8(v.w, min.w, max.w)); }
static inline s16x4 clamp_s16x4(s16x4 v, s16x4 min, s16x4 max) { return s16x4(clamp_s16(v.x, min.x, max.x), clamp_s16(v.y, min.y, max.y), clamp_s16(v.z, min.z, max.z), clamp_s16(v.w, min.w, max.w)); }
static inline s32x4 clamp_s32x4(s32x4 v, s32x4 min, s32x4 max) { return s32x4(clamp_s32(v.x, min.x, max.x), clamp_s32(v.y, min.y, max.y), clamp_s32(v.z, min.z, max.z), clamp_s32(v.w, min.w, max.w)); }
static inline s64x4 clamp_s64x4(s64x4 v, s64x4 min, s64x4 max) { return s64x4(clamp_s64(v.x, min.x, max.x), clamp_s64(v.y, min.y, max.y), clamp_s64(v.z, min.z, max.z), clamp_s64(v.w, min.w, max.w)); }
static inline u8x4 clamp_u8x4(u8x4 v, u8x4 min, u8x4 max) { return u8x4(clamp_u8(v.x, min.x, max.x), clamp_u8(v.y, min.y, max.y), clamp_u8(v.z, min.z, max.z), clamp_u8(v.w, min.w, max.w)); }
static inline u16x4 clamp_u16x4(u16x4 v, u16x4 min, u16x4 max) { return u16x4(clamp_u16(v.x, min.x, max.x), clamp_u16(v.y, min.y, max.y), clamp_u16(v.z, min.z, max.z), clamp_u16(v.w, min.w, max.w)); }
static inline u32x4 clamp_u32x4(u32x4 v, u32x4 min, u32x4 max) { return u32x4(clamp_u32(v.x, min.x, max.x), clamp_u32(v.y, min.y, max.y), clamp_u32(v.z, min.z, max.z), clamp_u32(v.w, min.w, max.w)); }
static inline u64x4 clamp_u64x4(u64x4 v, u64x4 min, u64x4 max) { return u64x4(clamp_u64(v.x, min.x, max.x), clamp_u64(v.y, min.y, max.y), clamp_u64(v.z, min.z, max.z), clamp_u64(v.w, min.w, max.w)); }

//
// returns a vector where each component is clamped between the minimum value 'min' and the maximum value 'max'
static inline f16x2 clamps_f16x2(f16x2 v, half min, half max) { f16x2 mins = f16x2s(min); f16x2 maxs = f16x2s(max); return clamp_f16x2(v, mins, maxs); }
static inline f32x2 clamps_f32x2(f32x2 v, float min, float max) { f32x2 mins = f32x2s(min); f32x2 maxs = f32x2s(max); return clamp_f32x2(v, mins, maxs); }
static inline f64x2 clamps_f64x2(f64x2 v, double min, double max) { f64x2 mins = f64x2s(min); f64x2 maxs = f64x2s(max); return clamp_f64x2(v, mins, maxs); }
static inline s8x2 clamps_s8x2(s8x2 v, int8_t min, int8_t max) { s8x2 mins = s8x2s(min); s8x2 maxs = s8x2s(max); return clamp_s8x2(v, mins, maxs); }
static inline s16x2 clamps_s16x2(s16x2 v, int16_t min, int16_t max) { s16x2 mins = s16x2s(min); s16x2 maxs = s16x2s(max); return clamp_s16x2(v, mins, maxs); }
static inline s32x2 clamps_s32x2(s32x2 v, int32_t min, int32_t max) { s32x2 mins = s32x2s(min); s32x2 maxs = s32x2s(max); return clamp_s32x2(v, mins, maxs); }
static inline s64x2 clamps_s64x2(s64x2 v, int64_t min, int64_t max) { s64x2 mins = s64x2s(min); s64x2 maxs = s64x2s(max); return clamp_s64x2(v, mins, maxs); }
static inline u8x2 clamps_u8x2(u8x2 v, uint8_t min, uint8_t max) { u8x2 mins = u8x2s(min); u8x2 maxs = u8x2s(max); return clamp_u8x2(v, mins, maxs); }
static inline u16x2 clamps_u16x2(u16x2 v, uint16_t min, uint16_t max) { u16x2 mins = u16x2s(min); u16x2 maxs = u16x2s(max); return clamp_u16x2(v, mins, maxs); }
static inline u32x2 clamps_u32x2(u32x2 v, uint32_t min, uint32_t max) { u32x2 mins = u32x2s(min); u32x2 maxs = u32x2s(max); return clamp_u32x2(v, mins, maxs); }
static inline u64x2 clamps_u64x2(u64x2 v, uint64_t min, uint64_t max) { u64x2 mins = u64x2s(min); u64x2 maxs = u64x2s(max); return clamp_u64x2(v, mins, maxs); }
static inline f16x3 clamps_f16x3(f16x3 v, half min, half max) { f16x3 mins = f16x3s(min); f16x3 maxs = f16x3s(max); return clamp_f16x3(v, mins, maxs); }
static inline f32x3 clamps_f32x3(f32x3 v, float min, float max) { f32x3 mins = f32x3s(min); f32x3 maxs = f32x3s(max); return clamp_f32x3(v, mins, maxs); }
static inline f64x3 clamps_f64x3(f64x3 v, double min, double max) { f64x3 mins = f64x3s(min); f64x3 maxs = f64x3s(max); return clamp_f64x3(v, mins, maxs); }
static inline s8x3 clamps_s8x3(s8x3 v, int8_t min, int8_t max) { s8x3 mins = s8x3s(min); s8x3 maxs = s8x3s(max); return clamp_s8x3(v, mins, maxs); }
static inline s16x3 clamps_s16x3(s16x3 v, int16_t min, int16_t max) { s16x3 mins = s16x3s(min); s16x3 maxs = s16x3s(max); return clamp_s16x3(v, mins, maxs); }
static inline s32x3 clamps_s32x3(s32x3 v, int32_t min, int32_t max) { s32x3 mins = s32x3s(min); s32x3 maxs = s32x3s(max); return clamp_s32x3(v, mins, maxs); }
static inline s64x3 clamps_s64x3(s64x3 v, int64_t min, int64_t max) { s64x3 mins = s64x3s(min); s64x3 maxs = s64x3s(max); return clamp_s64x3(v, mins, maxs); }
static inline u8x3 clamps_u8x3(u8x3 v, uint8_t min, uint8_t max) { u8x3 mins = u8x3s(min); u8x3 maxs = u8x3s(max); return clamp_u8x3(v, mins, maxs); }
static inline u16x3 clamps_u16x3(u16x3 v, uint16_t min, uint16_t max) { u16x3 mins = u16x3s(min); u16x3 maxs = u16x3s(max); return clamp_u16x3(v, mins, maxs); }
static inline u32x3 clamps_u32x3(u32x3 v, uint32_t min, uint32_t max) { u32x3 mins = u32x3s(min); u32x3 maxs = u32x3s(max); return clamp_u32x3(v, mins, maxs); }
static inline u64x3 clamps_u64x3(u64x3 v, uint64_t min, uint64_t max) { u64x3 mins = u64x3s(min); u64x3 maxs = u64x3s(max); return clamp_u64x3(v, mins, maxs); }
static inline f16x4 clamps_f16x4(f16x4 v, half min, half max) { f16x4 mins = f16x4s(min); f16x4 maxs = f16x4s(max); return clamp_f16x4(v, mins, maxs); }
static inline f32x4 clamps_f32x4(f32x4 v, float min, float max) { f32x4 mins = f32x4s(min); f32x4 maxs = f32x4s(max); return clamp_f32x4(v, mins, maxs); }
static inline f64x4 clamps_f64x4(f64x4 v, double min, double max) { f64x4 mins = f64x4s(min); f64x4 maxs = f64x4s(max); return clamp_f64x4(v, mins, maxs); }
static inline s8x4 clamps_s8x4(s8x4 v, int8_t min, int8_t max) { s8x4 mins = s8x4s(min); s8x4 maxs = s8x4s(max); return clamp_s8x4(v, mins, maxs); }
static inline s16x4 clamps_s16x4(s16x4 v, int16_t min, int16_t max) { s16x4 mins = s16x4s(min); s16x4 maxs = s16x4s(max); return clamp_s16x4(v, mins, maxs); }
static inline s32x4 clamps_s32x4(s32x4 v, int32_t min, int32_t max) { s32x4 mins = s32x4s(min); s32x4 maxs = s32x4s(max); return clamp_s32x4(v, mins, maxs); }
static inline s64x4 clamps_s64x4(s64x4 v, int64_t min, int64_t max) { s64x4 mins = s64x4s(min); s64x4 maxs = s64x4s(max); return clamp_s64x4(v, mins, maxs); }
static inline u8x4 clamps_u8x4(u8x4 v, uint8_t min, uint8_t max) { u8x4 mins = u8x4s(min); u8x4 maxs = u8x4s(max); return clamp_u8x4(v, mins, maxs); }
static inline u16x4 clamps_u16x4(u16x4 v, uint16_t min, uint16_t max) { u16x4 mins = u16x4s(min); u16x4 maxs = u16x4s(max); return clamp_u16x4(v, mins, maxs); }
static inline u32x4 clamps_u32x4(u32x4 v, uint32_t min, uint32_t max) { u32x4 mins = u32x4s(min); u32x4 maxs = u32x4s(max); return clamp_u32x4(v, mins, maxs); }
static inline u64x4 clamps_u64x4(u64x4 v, uint64_t min, uint64_t max) { u64x4 mins = u64x4s(min); u64x4 maxs = u64x4s(max); return clamp_u64x4(v, mins, maxs); }

//
// returns a vector where each component is -1, 0, or 1 depending on the sign of that component that is in 'v'
static inline f16x2 sign_f16x2(f16x2 v) { return f16x2(sign_f16(v.x), sign_f16(v.y)); }
static inline f32x2 sign_f32x2(f32x2 v) { return f32x2(sign_f32(v.x), sign_f32(v.y)); }
static inline f64x2 sign_f64x2(f64x2 v) { return f64x2(sign_f64(v.x), sign_f64(v.y)); }
static inline s8x2 sign_s8x2(s8x2 v) { return s8x2(sign_s8(v.x), sign_s8(v.y)); }
static inline s16x2 sign_s16x2(s16x2 v) { return s16x2(sign_s16(v.x), sign_s16(v.y)); }
static inline s32x2 sign_s32x2(s32x2 v) { return s32x2(sign_s32(v.x), sign_s32(v.y)); }
static inline s64x2 sign_s64x2(s64x2 v) { return s64x2(sign_s64(v.x), sign_s64(v.y)); }
static inline f16x3 sign_f16x3(f16x3 v) { return f16x3(sign_f16(v.x), sign_f16(v.y), sign_f16(v.z)); }
static inline f32x3 sign_f32x3(f32x3 v) { return f32x3(sign_f32(v.x), sign_f32(v.y), sign_f32(v.z)); }
static inline f64x3 sign_f64x3(f64x3 v) { return f64x3(sign_f64(v.x), sign_f64(v.y), sign_f64(v.z)); }
static inline s8x3 sign_s8x3(s8x3 v) { return s8x3(sign_s8(v.x), sign_s8(v.y), sign_s8(v.z)); }
static inline s16x3 sign_s16x3(s16x3 v) { return s16x3(sign_s16(v.x), sign_s16(v.y), sign_s16(v.z)); }
static inline s32x3 sign_s32x3(s32x3 v) { return s32x3(sign_s32(v.x), sign_s32(v.y), sign_s32(v.z)); }
static inline s64x3 sign_s64x3(s64x3 v) { return s64x3(sign_s64(v.x), sign_s64(v.y), sign_s64(v.z)); }
static inline f16x4 sign_f16x4(f16x4 v) { return f16x4(sign_f16(v.x), sign_f16(v.y), sign_f16(v.z), sign_f16(v.w)); }
static inline f32x4 sign_f32x4(f32x4 v) { return f32x4(sign_f32(v.x), sign_f32(v.y), sign_f32(v.z), sign_f32(v.w)); }
static inline f64x4 sign_f64x4(f64x4 v) { return f64x4(sign_f64(v.x), sign_f64(v.y), sign_f64(v.z), sign_f64(v.w)); }
static inline s8x4 sign_s8x4(s8x4 v) { return s8x4(sign_s8(v.x), sign_s8(v.y), sign_s8(v.z), sign_s8(v.w)); }
static inline s16x4 sign_s16x4(s16x4 v) { return s16x4(sign_s16(v.x), sign_s16(v.y), sign_s16(v.z), sign_s16(v.w)); }
static inline s32x4 sign_s32x4(s32x4 v) { return s32x4(sign_s32(v.x), sign_s32(v.y), sign_s32(v.z), sign_s32(v.w)); }
static inline s64x4 sign_s64x4(s64x4 v) { return s64x4(sign_s64(v.x), sign_s64(v.y), sign_s64(v.z), sign_s64(v.w)); }

//
// returns a vector where each component is that component in 'v' with sign of that component in 'sign'
static inline f16x2 copysign_f16x2(f16x2 v, f16x2 sign) { return f16x2(copysign_f16(v.x, sign.x), copysign_f16(v.y, sign.y)); }
static inline f32x2 copysign_f32x2(f32x2 v, f32x2 sign) { return f32x2(copysign_f32(v.x, sign.x), copysign_f32(v.y, sign.y)); }
static inline f64x2 copysign_f64x2(f64x2 v, f64x2 sign) { return f64x2(copysign_f64(v.x, sign.x), copysign_f64(v.y, sign.y)); }
static inline s8x2 copysign_s8x2(s8x2 v, s8x2 sign) { return s8x2(copysign_s8(v.x, sign.x), copysign_s8(v.y, sign.y)); }
static inline s16x2 copysign_s16x2(s16x2 v, s16x2 sign) { return s16x2(copysign_s16(v.x, sign.x), copysign_s16(v.y, sign.y)); }
static inline s32x2 copysign_s32x2(s32x2 v, s32x2 sign) { return s32x2(copysign_s32(v.x, sign.x), copysign_s32(v.y, sign.y)); }
static inline s64x2 copysign_s64x2(s64x2 v, s64x2 sign) { return s64x2(copysign_s64(v.x, sign.x), copysign_s64(v.y, sign.y)); }
static inline f16x3 copysign_f16x3(f16x3 v, f16x3 sign) { return f16x3(copysign_f16(v.x, sign.x), copysign_f16(v.y, sign.y), copysign_f16(v.z, sign.z)); }
static inline f32x3 copysign_f32x3(f32x3 v, f32x3 sign) { return f32x3(copysign_f32(v.x, sign.x), copysign_f32(v.y, sign.y), copysign_f32(v.z, sign.z)); }
static inline f64x3 copysign_f64x3(f64x3 v, f64x3 sign) { return f64x3(copysign_f64(v.x, sign.x), copysign_f64(v.y, sign.y), copysign_f64(v.z, sign.z)); }
static inline s8x3 copysign_s8x3(s8x3 v, s8x3 sign) { return s8x3(copysign_s8(v.x, sign.x), copysign_s8(v.y, sign.y), copysign_s8(v.z, sign.z)); }
static inline s16x3 copysign_s16x3(s16x3 v, s16x3 sign) { return s16x3(copysign_s16(v.x, sign.x), copysign_s16(v.y, sign.y), copysign_s16(v.z, sign.z)); }
static inline s32x3 copysign_s32x3(s32x3 v, s32x3 sign) { return s32x3(copysign_s32(v.x, sign.x), copysign_s32(v.y, sign.y), copysign_s32(v.z, sign.z)); }
static inline s64x3 copysign_s64x3(s64x3 v, s64x3 sign) { return s64x3(copysign_s64(v.x, sign.x), copysign_s64(v.y, sign.y), copysign_s64(v.z, sign.z)); }
static inline f16x4 copysign_f16x4(f16x4 v, f16x4 sign) { return f16x4(copysign_f16(v.x, sign.x), copysign_f16(v.y, sign.y), copysign_f16(v.z, sign.z), copysign_f16(v.w, sign.w)); }
static inline f32x4 copysign_f32x4(f32x4 v, f32x4 sign) { return f32x4(copysign_f32(v.x, sign.x), copysign_f32(v.y, sign.y), copysign_f32(v.z, sign.z), copysign_f32(v.w, sign.w)); }
static inline f64x4 copysign_f64x4(f64x4 v, f64x4 sign) { return f64x4(copysign_f64(v.x, sign.x), copysign_f64(v.y, sign.y), copysign_f64(v.z, sign.z), copysign_f64(v.w, sign.w)); }
static inline s8x4 copysign_s8x4(s8x4 v, s8x4 sign) { return s8x4(copysign_s8(v.x, sign.x), copysign_s8(v.y, sign.y), copysign_s8(v.z, sign.z), copysign_s8(v.w, sign.w)); }
static inline s16x4 copysign_s16x4(s16x4 v, s16x4 sign) { return s16x4(copysign_s16(v.x, sign.x), copysign_s16(v.y, sign.y), copysign_s16(v.z, sign.z), copysign_s16(v.w, sign.w)); }
static inline s32x4 copysign_s32x4(s32x4 v, s32x4 sign) { return s32x4(copysign_s32(v.x, sign.x), copysign_s32(v.y, sign.y), copysign_s32(v.z, sign.z), copysign_s32(v.w, sign.w)); }
static inline s64x4 copysign_s64x4(s64x4 v, s64x4 sign) { return s64x4(copysign_s64(v.x, sign.x), copysign_s64(v.y, sign.y), copysign_s64(v.z, sign.z), copysign_s64(v.w, sign.w)); }

//
// returns a vector where each component is that component in 'v' with sign of 'sign'
static inline f16x2 copysigns_f16x2(f16x2 v, half sign) { return f16x2(copysign_f16(v.x, sign), copysign_f16(v.y, sign)); }
static inline f32x2 copysigns_f32x2(f32x2 v, float sign) { return f32x2(copysign_f32(v.x, sign), copysign_f32(v.y, sign)); }
static inline f64x2 copysigns_f64x2(f64x2 v, double sign) { return f64x2(copysign_f64(v.x, sign), copysign_f64(v.y, sign)); }
static inline s8x2 copysigns_s8x2(s8x2 v, int8_t sign) { return s8x2(copysign_s8(v.x, sign), copysign_s8(v.y, sign)); }
static inline s16x2 copysigns_s16x2(s16x2 v, int16_t sign) { return s16x2(copysign_s16(v.x, sign), copysign_s16(v.y, sign)); }
static inline s32x2 copysigns_s32x2(s32x2 v, int32_t sign) { return s32x2(copysign_s32(v.x, sign), copysign_s32(v.y, sign)); }
static inline s64x2 copysigns_s64x2(s64x2 v, int64_t sign) { return s64x2(copysign_s64(v.x, sign), copysign_s64(v.y, sign)); }
static inline f16x3 copysigns_f16x3(f16x3 v, half sign) { return f16x3(copysign_f16(v.x, sign), copysign_f16(v.y, sign), copysign_f16(v.z, sign)); }
static inline f32x3 copysigns_f32x3(f32x3 v, float sign) { return f32x3(copysign_f32(v.x, sign), copysign_f32(v.y, sign), copysign_f32(v.z, sign)); }
static inline f64x3 copysigns_f64x3(f64x3 v, double sign) { return f64x3(copysign_f64(v.x, sign), copysign_f64(v.y, sign), copysign_f64(v.z, sign)); }
static inline s8x3 copysigns_s8x3(s8x3 v, int8_t sign) { return s8x3(copysign_s8(v.x, sign), copysign_s8(v.y, sign), copysign_s8(v.z, sign)); }
static inline s16x3 copysigns_s16x3(s16x3 v, int16_t sign) { return s16x3(copysign_s16(v.x, sign), copysign_s16(v.y, sign), copysign_s16(v.z, sign)); }
static inline s32x3 copysigns_s32x3(s32x3 v, int32_t sign) { return s32x3(copysign_s32(v.x, sign), copysign_s32(v.y, sign), copysign_s32(v.z, sign)); }
static inline s64x3 copysigns_s64x3(s64x3 v, int64_t sign) { return s64x3(copysign_s64(v.x, sign), copysign_s64(v.y, sign), copysign_s64(v.z, sign)); }
static inline f16x4 copysigns_f16x4(f16x4 v, half sign) { return f16x4(copysign_f16(v.x, sign), copysign_f16(v.y, sign), copysign_f16(v.z, sign), copysign_f16(v.w, sign)); }
static inline f32x4 copysigns_f32x4(f32x4 v, float sign) { return f32x4(copysign_f32(v.x, sign), copysign_f32(v.y, sign), copysign_f32(v.z, sign), copysign_f32(v.w, sign)); }
static inline f64x4 copysigns_f64x4(f64x4 v, double sign) { return f64x4(copysign_f64(v.x, sign), copysign_f64(v.y, sign), copysign_f64(v.z, sign), copysign_f64(v.w, sign)); }
static inline s8x4 copysigns_s8x4(s8x4 v, int8_t sign) { return s8x4(copysign_s8(v.x, sign), copysign_s8(v.y, sign), copysign_s8(v.z, sign), copysign_s8(v.w, sign)); }
static inline s16x4 copysigns_s16x4(s16x4 v, int16_t sign) { return s16x4(copysign_s16(v.x, sign), copysign_s16(v.y, sign), copysign_s16(v.z, sign), copysign_s16(v.w, sign)); }
static inline s32x4 copysigns_s32x4(s32x4 v, int32_t sign) { return s32x4(copysign_s32(v.x, sign), copysign_s32(v.y, sign), copysign_s32(v.z, sign), copysign_s32(v.w, sign)); }
static inline s64x4 copysigns_s64x4(s64x4 v, int64_t sign) { return s64x4(copysign_s64(v.x, sign), copysign_s64(v.y, sign), copysign_s64(v.z, sign), copysign_s64(v.w, sign)); }

//
// returns a vector where each component is the absolute of that component in 'v'
static inline f16x2 abs_f16x2(f16x2 v) { return f16x2(abs_f16(v.x), abs_f16(v.y)); }
static inline f32x2 abs_f32x2(f32x2 v) { return f32x2(abs_f32(v.x), abs_f32(v.y)); }
static inline f64x2 abs_f64x2(f64x2 v) { return f64x2(abs_f64(v.x), abs_f64(v.y)); }
static inline s8x2 abs_s8x2(s8x2 v) { return s8x2(abs_s8(v.x), abs_s8(v.y)); }
static inline s16x2 abs_s16x2(s16x2 v) { return s16x2(abs_s16(v.x), abs_s16(v.y)); }
static inline s32x2 abs_s32x2(s32x2 v) { return s32x2(abs_s32(v.x), abs_s32(v.y)); }
static inline s64x2 abs_s64x2(s64x2 v) { return s64x2(abs_s64(v.x), abs_s64(v.y)); }
static inline f16x3 abs_f16x3(f16x3 v) { return f16x3(abs_f16(v.x), abs_f16(v.y), abs_f16(v.z)); }
static inline f32x3 abs_f32x3(f32x3 v) { return f32x3(abs_f32(v.x), abs_f32(v.y), abs_f32(v.z)); }
static inline f64x3 abs_f64x3(f64x3 v) { return f64x3(abs_f64(v.x), abs_f64(v.y), abs_f64(v.z)); }
static inline s8x3 abs_s8x3(s8x3 v) { return s8x3(abs_s8(v.x), abs_s8(v.y), abs_s8(v.z)); }
static inline s16x3 abs_s16x3(s16x3 v) { return s16x3(abs_s16(v.x), abs_s16(v.y), abs_s16(v.z)); }
static inline s32x3 abs_s32x3(s32x3 v) { return s32x3(abs_s32(v.x), abs_s32(v.y), abs_s32(v.z)); }
static inline s64x3 abs_s64x3(s64x3 v) { return s64x3(abs_s64(v.x), abs_s64(v.y), abs_s64(v.z)); }
static inline f16x4 abs_f16x4(f16x4 v) { return f16x4(abs_f16(v.x), abs_f16(v.y), abs_f16(v.z), abs_f16(v.w)); }
static inline f32x4 abs_f32x4(f32x4 v) { return f32x4(abs_f32(v.x), abs_f32(v.y), abs_f32(v.z), abs_f32(v.w)); }
static inline f64x4 abs_f64x4(f64x4 v) { return f64x4(abs_f64(v.x), abs_f64(v.y), abs_f64(v.z), abs_f64(v.w)); }
static inline s8x4 abs_s8x4(s8x4 v) { return s8x4(abs_s8(v.x), abs_s8(v.y), abs_s8(v.z), abs_s8(v.w)); }
static inline s16x4 abs_s16x4(s16x4 v) { return s16x4(abs_s16(v.x), abs_s16(v.y), abs_s16(v.z), abs_s16(v.w)); }
static inline s32x4 abs_s32x4(s32x4 v) { return s32x4(abs_s32(v.x), abs_s32(v.y), abs_s32(v.z), abs_s32(v.w)); }
static inline s64x4 abs_s64x4(s64x4 v) { return s64x4(abs_s64(v.x), abs_s64(v.y), abs_s64(v.z), abs_s64(v.w)); }

//
// returns a vector where each component is the result from bitwise anding that component in 'a' to that component in 'b'
static inline s8x2 bitand_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x & b.x, a.y & b.y); }
static inline s16x2 bitand_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x & b.x, a.y & b.y); }
static inline s32x2 bitand_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x & b.x, a.y & b.y); }
static inline s64x2 bitand_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x & b.x, a.y & b.y); }
static inline u8x2 bitand_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x & b.x, a.y & b.y); }
static inline u16x2 bitand_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x & b.x, a.y & b.y); }
static inline u32x2 bitand_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x & b.x, a.y & b.y); }
static inline u64x2 bitand_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x & b.x, a.y & b.y); }
static inline s8x3 bitand_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline s16x3 bitand_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline s32x3 bitand_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline s64x3 bitand_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline u8x3 bitand_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline u16x3 bitand_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline u32x3 bitand_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline u64x3 bitand_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x & b.x, a.y & b.y, a.z & b.z); }
static inline s8x4 bitand_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline s16x4 bitand_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline s32x4 bitand_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline s64x4 bitand_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline u8x4 bitand_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline u16x4 bitand_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline u32x4 bitand_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }
static inline u64x4 bitand_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w); }

//
// returns a vector where each component is the result from bitwise anding that component in 'v' to the value 's'
static inline s8x2 bitands_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return bitand_s8x2(v, ss); }
static inline s16x2 bitands_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return bitand_s16x2(v, ss); }
static inline s32x2 bitands_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return bitand_s32x2(v, ss); }
static inline s64x2 bitands_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return bitand_s64x2(v, ss); }
static inline u8x2 bitands_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return bitand_u8x2(v, ss); }
static inline u16x2 bitands_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return bitand_u16x2(v, ss); }
static inline u32x2 bitands_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return bitand_u32x2(v, ss); }
static inline u64x2 bitands_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return bitand_u64x2(v, ss); }
static inline s8x3 bitands_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return bitand_s8x3(v, ss); }
static inline s16x3 bitands_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return bitand_s16x3(v, ss); }
static inline s32x3 bitands_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return bitand_s32x3(v, ss); }
static inline s64x3 bitands_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return bitand_s64x3(v, ss); }
static inline u8x3 bitands_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return bitand_u8x3(v, ss); }
static inline u16x3 bitands_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return bitand_u16x3(v, ss); }
static inline u32x3 bitands_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return bitand_u32x3(v, ss); }
static inline u64x3 bitands_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return bitand_u64x3(v, ss); }
static inline s8x4 bitands_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return bitand_s8x4(v, ss); }
static inline s16x4 bitands_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return bitand_s16x4(v, ss); }
static inline s32x4 bitands_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return bitand_s32x4(v, ss); }
static inline s64x4 bitands_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return bitand_s64x4(v, ss); }
static inline u8x4 bitands_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return bitand_u8x4(v, ss); }
static inline u16x4 bitands_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return bitand_u16x4(v, ss); }
static inline u32x4 bitands_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return bitand_u32x4(v, ss); }
static inline u64x4 bitands_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return bitand_u64x4(v, ss); }

//
// returns a vector where each component is the result from bitwise oring that component in 'a' to that component in 'b'
static inline s8x2 bitor_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x | b.x, a.y | b.y); }
static inline s16x2 bitor_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x | b.x, a.y | b.y); }
static inline s32x2 bitor_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x | b.x, a.y | b.y); }
static inline s64x2 bitor_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x | b.x, a.y | b.y); }
static inline u8x2 bitor_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x | b.x, a.y | b.y); }
static inline u16x2 bitor_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x | b.x, a.y | b.y); }
static inline u32x2 bitor_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x | b.x, a.y | b.y); }
static inline u64x2 bitor_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x | b.x, a.y | b.y); }
static inline s8x3 bitor_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline s16x3 bitor_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline s32x3 bitor_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline s64x3 bitor_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline u8x3 bitor_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline u16x3 bitor_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline u32x3 bitor_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline u64x3 bitor_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x | b.x, a.y | b.y, a.z | b.z); }
static inline s8x4 bitor_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline s16x4 bitor_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline s32x4 bitor_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline s64x4 bitor_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline u8x4 bitor_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline u16x4 bitor_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline u32x4 bitor_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }
static inline u64x4 bitor_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w); }

//
// returns a vector where each component is the result from bitwise oring that component in 'v' to the value 's'
static inline s8x2 bitors_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return bitor_s8x2(v, ss); }
static inline s16x2 bitors_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return bitor_s16x2(v, ss); }
static inline s32x2 bitors_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return bitor_s32x2(v, ss); }
static inline s64x2 bitors_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return bitor_s64x2(v, ss); }
static inline u8x2 bitors_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return bitor_u8x2(v, ss); }
static inline u16x2 bitors_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return bitor_u16x2(v, ss); }
static inline u32x2 bitors_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return bitor_u32x2(v, ss); }
static inline u64x2 bitors_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return bitor_u64x2(v, ss); }
static inline s8x3 bitors_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return bitor_s8x3(v, ss); }
static inline s16x3 bitors_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return bitor_s16x3(v, ss); }
static inline s32x3 bitors_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return bitor_s32x3(v, ss); }
static inline s64x3 bitors_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return bitor_s64x3(v, ss); }
static inline u8x3 bitors_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return bitor_u8x3(v, ss); }
static inline u16x3 bitors_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return bitor_u16x3(v, ss); }
static inline u32x3 bitors_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return bitor_u32x3(v, ss); }
static inline u64x3 bitors_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return bitor_u64x3(v, ss); }
static inline s8x4 bitors_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return bitor_s8x4(v, ss); }
static inline s16x4 bitors_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return bitor_s16x4(v, ss); }
static inline s32x4 bitors_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return bitor_s32x4(v, ss); }
static inline s64x4 bitors_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return bitor_s64x4(v, ss); }
static inline u8x4 bitors_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return bitor_u8x4(v, ss); }
static inline u16x4 bitors_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return bitor_u16x4(v, ss); }
static inline u32x4 bitors_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return bitor_u32x4(v, ss); }
static inline u64x4 bitors_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return bitor_u64x4(v, ss); }

//
// returns a vector where each component is the result from bitwise xoring that component in 'a' to that component in 'b'
static inline s8x2 bitxor_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x ^ b.x, a.y ^ b.y); }
static inline s16x2 bitxor_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x ^ b.x, a.y ^ b.y); }
static inline s32x2 bitxor_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x ^ b.x, a.y ^ b.y); }
static inline s64x2 bitxor_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x ^ b.x, a.y ^ b.y); }
static inline u8x2 bitxor_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x ^ b.x, a.y ^ b.y); }
static inline u16x2 bitxor_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x ^ b.x, a.y ^ b.y); }
static inline u32x2 bitxor_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x ^ b.x, a.y ^ b.y); }
static inline u64x2 bitxor_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x ^ b.x, a.y ^ b.y); }
static inline s8x3 bitxor_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline s16x3 bitxor_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline s32x3 bitxor_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline s64x3 bitxor_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline u8x3 bitxor_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline u16x3 bitxor_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline u32x3 bitxor_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline u64x3 bitxor_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }
static inline s8x4 bitxor_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline s16x4 bitxor_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline s32x4 bitxor_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline s64x4 bitxor_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline u8x4 bitxor_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline u16x4 bitxor_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline u32x4 bitxor_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }
static inline u64x4 bitxor_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w); }

//
// returns a vector where each component is the result from bitwise xoring that component in 'v' to the value 's'
static inline s8x2 bitxors_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return bitxor_s8x2(v, ss); }
static inline s16x2 bitxors_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return bitxor_s16x2(v, ss); }
static inline s32x2 bitxors_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return bitxor_s32x2(v, ss); }
static inline s64x2 bitxors_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return bitxor_s64x2(v, ss); }
static inline u8x2 bitxors_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return bitxor_u8x2(v, ss); }
static inline u16x2 bitxors_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return bitxor_u16x2(v, ss); }
static inline u32x2 bitxors_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return bitxor_u32x2(v, ss); }
static inline u64x2 bitxors_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return bitxor_u64x2(v, ss); }
static inline s8x3 bitxors_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return bitxor_s8x3(v, ss); }
static inline s16x3 bitxors_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return bitxor_s16x3(v, ss); }
static inline s32x3 bitxors_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return bitxor_s32x3(v, ss); }
static inline s64x3 bitxors_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return bitxor_s64x3(v, ss); }
static inline u8x3 bitxors_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return bitxor_u8x3(v, ss); }
static inline u16x3 bitxors_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return bitxor_u16x3(v, ss); }
static inline u32x3 bitxors_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return bitxor_u32x3(v, ss); }
static inline u64x3 bitxors_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return bitxor_u64x3(v, ss); }
static inline s8x4 bitxors_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return bitxor_s8x4(v, ss); }
static inline s16x4 bitxors_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return bitxor_s16x4(v, ss); }
static inline s32x4 bitxors_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return bitxor_s32x4(v, ss); }
static inline s64x4 bitxors_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return bitxor_s64x4(v, ss); }
static inline u8x4 bitxors_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return bitxor_u8x4(v, ss); }
static inline u16x4 bitxors_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return bitxor_u16x4(v, ss); }
static inline u32x4 bitxors_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return bitxor_u32x4(v, ss); }
static inline u64x4 bitxors_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return bitxor_u64x4(v, ss); }

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the left by the component in 'b'
static inline s8x2 bitshl_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x << b.x, a.y << b.y); }
static inline s16x2 bitshl_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x << b.x, a.y << b.y); }
static inline s32x2 bitshl_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x << b.x, a.y << b.y); }
static inline s64x2 bitshl_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x << b.x, a.y << b.y); }
static inline u8x2 bitshl_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x << b.x, a.y << b.y); }
static inline u16x2 bitshl_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x << b.x, a.y << b.y); }
static inline u32x2 bitshl_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x << b.x, a.y << b.y); }
static inline u64x2 bitshl_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x << b.x, a.y << b.y); }
static inline s8x3 bitshl_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline s16x3 bitshl_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline s32x3 bitshl_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline s64x3 bitshl_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline u8x3 bitshl_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline u16x3 bitshl_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline u32x3 bitshl_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline u64x3 bitshl_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x << b.x, a.y << b.y, a.z << b.z); }
static inline s8x4 bitshl_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline s16x4 bitshl_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline s32x4 bitshl_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline s64x4 bitshl_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline u8x4 bitshl_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline u16x4 bitshl_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline u32x4 bitshl_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }
static inline u64x4 bitshl_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w); }

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the left by the value 's'
static inline s8x2 bitshls_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return bitshl_s8x2(v, ss); }
static inline s16x2 bitshls_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return bitshl_s16x2(v, ss); }
static inline s32x2 bitshls_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return bitshl_s32x2(v, ss); }
static inline s64x2 bitshls_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return bitshl_s64x2(v, ss); }
static inline u8x2 bitshls_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return bitshl_u8x2(v, ss); }
static inline u16x2 bitshls_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return bitshl_u16x2(v, ss); }
static inline u32x2 bitshls_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return bitshl_u32x2(v, ss); }
static inline u64x2 bitshls_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return bitshl_u64x2(v, ss); }
static inline s8x3 bitshls_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return bitshl_s8x3(v, ss); }
static inline s16x3 bitshls_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return bitshl_s16x3(v, ss); }
static inline s32x3 bitshls_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return bitshl_s32x3(v, ss); }
static inline s64x3 bitshls_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return bitshl_s64x3(v, ss); }
static inline u8x3 bitshls_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return bitshl_u8x3(v, ss); }
static inline u16x3 bitshls_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return bitshl_u16x3(v, ss); }
static inline u32x3 bitshls_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return bitshl_u32x3(v, ss); }
static inline u64x3 bitshls_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return bitshl_u64x3(v, ss); }
static inline s8x4 bitshls_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return bitshl_s8x4(v, ss); }
static inline s16x4 bitshls_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return bitshl_s16x4(v, ss); }
static inline s32x4 bitshls_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return bitshl_s32x4(v, ss); }
static inline s64x4 bitshls_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return bitshl_s64x4(v, ss); }
static inline u8x4 bitshls_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return bitshl_u8x4(v, ss); }
static inline u16x4 bitshls_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return bitshl_u16x4(v, ss); }
static inline u32x4 bitshls_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return bitshl_u32x4(v, ss); }
static inline u64x4 bitshls_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return bitshl_u64x4(v, ss); }

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the right by the component in 'b'
static inline s8x2 bitshr_s8x2(s8x2 a, s8x2 b) { return s8x2(a.x >> b.x, a.y >> b.y); }
static inline s16x2 bitshr_s16x2(s16x2 a, s16x2 b) { return s16x2(a.x >> b.x, a.y >> b.y); }
static inline s32x2 bitshr_s32x2(s32x2 a, s32x2 b) { return s32x2(a.x >> b.x, a.y >> b.y); }
static inline s64x2 bitshr_s64x2(s64x2 a, s64x2 b) { return s64x2(a.x >> b.x, a.y >> b.y); }
static inline u8x2 bitshr_u8x2(u8x2 a, u8x2 b) { return u8x2(a.x >> b.x, a.y >> b.y); }
static inline u16x2 bitshr_u16x2(u16x2 a, u16x2 b) { return u16x2(a.x >> b.x, a.y >> b.y); }
static inline u32x2 bitshr_u32x2(u32x2 a, u32x2 b) { return u32x2(a.x >> b.x, a.y >> b.y); }
static inline u64x2 bitshr_u64x2(u64x2 a, u64x2 b) { return u64x2(a.x >> b.x, a.y >> b.y); }
static inline s8x3 bitshr_s8x3(s8x3 a, s8x3 b) { return s8x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline s16x3 bitshr_s16x3(s16x3 a, s16x3 b) { return s16x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline s32x3 bitshr_s32x3(s32x3 a, s32x3 b) { return s32x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline s64x3 bitshr_s64x3(s64x3 a, s64x3 b) { return s64x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline u8x3 bitshr_u8x3(u8x3 a, u8x3 b) { return u8x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline u16x3 bitshr_u16x3(u16x3 a, u16x3 b) { return u16x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline u32x3 bitshr_u32x3(u32x3 a, u32x3 b) { return u32x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline u64x3 bitshr_u64x3(u64x3 a, u64x3 b) { return u64x3(a.x >> b.x, a.y >> b.y, a.z >> b.z); }
static inline s8x4 bitshr_s8x4(s8x4 a, s8x4 b) { return s8x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline s16x4 bitshr_s16x4(s16x4 a, s16x4 b) { return s16x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline s32x4 bitshr_s32x4(s32x4 a, s32x4 b) { return s32x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline s64x4 bitshr_s64x4(s64x4 a, s64x4 b) { return s64x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline u8x4 bitshr_u8x4(u8x4 a, u8x4 b) { return u8x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline u16x4 bitshr_u16x4(u16x4 a, u16x4 b) { return u16x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline u32x4 bitshr_u32x4(u32x4 a, u32x4 b) { return u32x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }
static inline u64x4 bitshr_u64x4(u64x4 a, u64x4 b) { return u64x4(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w); }

//
// returns a vector where each component is the result from bitwise shifting that component in 'v' to the right by the value 's'
static inline s8x2 bitshrs_s8x2(s8x2 v, int8_t s) { s8x2 ss = s8x2s(s); return bitshr_s8x2(v, ss); }
static inline s16x2 bitshrs_s16x2(s16x2 v, int16_t s) { s16x2 ss = s16x2s(s); return bitshr_s16x2(v, ss); }
static inline s32x2 bitshrs_s32x2(s32x2 v, int32_t s) { s32x2 ss = s32x2s(s); return bitshr_s32x2(v, ss); }
static inline s64x2 bitshrs_s64x2(s64x2 v, int64_t s) { s64x2 ss = s64x2s(s); return bitshr_s64x2(v, ss); }
static inline u8x2 bitshrs_u8x2(u8x2 v, uint8_t s) { u8x2 ss = u8x2s(s); return bitshr_u8x2(v, ss); }
static inline u16x2 bitshrs_u16x2(u16x2 v, uint16_t s) { u16x2 ss = u16x2s(s); return bitshr_u16x2(v, ss); }
static inline u32x2 bitshrs_u32x2(u32x2 v, uint32_t s) { u32x2 ss = u32x2s(s); return bitshr_u32x2(v, ss); }
static inline u64x2 bitshrs_u64x2(u64x2 v, uint64_t s) { u64x2 ss = u64x2s(s); return bitshr_u64x2(v, ss); }
static inline s8x3 bitshrs_s8x3(s8x3 v, int8_t s) { s8x3 ss = s8x3s(s); return bitshr_s8x3(v, ss); }
static inline s16x3 bitshrs_s16x3(s16x3 v, int16_t s) { s16x3 ss = s16x3s(s); return bitshr_s16x3(v, ss); }
static inline s32x3 bitshrs_s32x3(s32x3 v, int32_t s) { s32x3 ss = s32x3s(s); return bitshr_s32x3(v, ss); }
static inline s64x3 bitshrs_s64x3(s64x3 v, int64_t s) { s64x3 ss = s64x3s(s); return bitshr_s64x3(v, ss); }
static inline u8x3 bitshrs_u8x3(u8x3 v, uint8_t s) { u8x3 ss = u8x3s(s); return bitshr_u8x3(v, ss); }
static inline u16x3 bitshrs_u16x3(u16x3 v, uint16_t s) { u16x3 ss = u16x3s(s); return bitshr_u16x3(v, ss); }
static inline u32x3 bitshrs_u32x3(u32x3 v, uint32_t s) { u32x3 ss = u32x3s(s); return bitshr_u32x3(v, ss); }
static inline u64x3 bitshrs_u64x3(u64x3 v, uint64_t s) { u64x3 ss = u64x3s(s); return bitshr_u64x3(v, ss); }
static inline s8x4 bitshrs_s8x4(s8x4 v, int8_t s) { s8x4 ss = s8x4s(s); return bitshr_s8x4(v, ss); }
static inline s16x4 bitshrs_s16x4(s16x4 v, int16_t s) { s16x4 ss = s16x4s(s); return bitshr_s16x4(v, ss); }
static inline s32x4 bitshrs_s32x4(s32x4 v, int32_t s) { s32x4 ss = s32x4s(s); return bitshr_s32x4(v, ss); }
static inline s64x4 bitshrs_s64x4(s64x4 v, int64_t s) { s64x4 ss = s64x4s(s); return bitshr_s64x4(v, ss); }
static inline u8x4 bitshrs_u8x4(u8x4 v, uint8_t s) { u8x4 ss = u8x4s(s); return bitshr_u8x4(v, ss); }
static inline u16x4 bitshrs_u16x4(u16x4 v, uint16_t s) { u16x4 ss = u16x4s(s); return bitshr_u16x4(v, ss); }
static inline u32x4 bitshrs_u32x4(u32x4 v, uint32_t s) { u32x4 ss = u32x4s(s); return bitshr_u32x4(v, ss); }
static inline u64x4 bitshrs_u64x4(u64x4 v, uint64_t s) { u64x4 ss = u64x4s(s); return bitshr_u64x4(v, ss); }

//
// returns the index of the _least_ significant bit, if 'v == 0' then 0 is returned
static inline u8x2 bitlsb_u8x2(u16x2 v) { return u8x2(bitlsb_u8(v.x), bitlsb_u8(v.y)); }
static inline u16x2 bitlsb_u16x2(u16x2 v) { return u16x2(bitlsb_u16(v.x), bitlsb_u16(v.y)); }
static inline u32x2 bitlsb_u32x2(u32x2 v) { return u32x2(bitlsb_u32(v.x), bitlsb_u32(v.y)); }
static inline u64x2 bitlsb_u64x2(u64x2 v) { return u64x2(bitlsb_u64(v.x), bitlsb_u64(v.y)); }
static inline u8x3 bitlsb_u8x3(u16x3 v) { return u8x3(bitlsb_u8(v.x), bitlsb_u8(v.y), bitlsb_u8(v.z)); }
static inline u16x3 bitlsb_u16x3(u16x3 v) { return u16x3(bitlsb_u16(v.x), bitlsb_u16(v.y), bitlsb_u16(v.z)); }
static inline u32x3 bitlsb_u32x3(u32x3 v) { return u32x3(bitlsb_u32(v.x), bitlsb_u32(v.y), bitlsb_u32(v.z)); }
static inline u64x3 bitlsb_u64x3(u64x3 v) { return u64x3(bitlsb_u64(v.x), bitlsb_u64(v.y), bitlsb_u64(v.z)); }
static inline u8x4 bitlsb_u8x4(u16x4 v) { return u8x4(bitlsb_u8(v.x), bitlsb_u8(v.y), bitlsb_u8(v.z), bitlsb_u8(v.w)); }
static inline u16x4 bitlsb_u16x4(u16x4 v) { return u16x4(bitlsb_u16(v.x), bitlsb_u16(v.y), bitlsb_u16(v.z), bitlsb_u16(v.w)); }
static inline u32x4 bitlsb_u32x4(u32x4 v) { return u32x4(bitlsb_u32(v.x), bitlsb_u32(v.y), bitlsb_u32(v.z), bitlsb_u32(v.w)); }
static inline u64x4 bitlsb_u64x4(u64x4 v) { return u64x4(bitlsb_u64(v.x), bitlsb_u64(v.y), bitlsb_u64(v.z), bitlsb_u64(v.w)); }

//
// returns the index of the _most_ significant bit, if 'v == 0' then 0 is returned
static inline u8x2 bitmsb_u8x2(u16x2 v) { return u8x2(bitmsb_u8(v.x), bitmsb_u8(v.y)); }
static inline u16x2 bitmsb_u16x2(u16x2 v) { return u16x2(bitmsb_u16(v.x), bitmsb_u16(v.y)); }
static inline u32x2 bitmsb_u32x2(u32x2 v) { return u32x2(bitmsb_u32(v.x), bitmsb_u32(v.y)); }
static inline u64x2 bitmsb_u64x2(u64x2 v) { return u64x2(bitmsb_u64(v.x), bitmsb_u64(v.y)); }
static inline u8x3 bitmsb_u8x3(u16x3 v) { return u8x3(bitmsb_u8(v.x), bitmsb_u8(v.y), bitmsb_u8(v.z)); }
static inline u16x3 bitmsb_u16x3(u16x3 v) { return u16x3(bitmsb_u16(v.x), bitmsb_u16(v.y), bitmsb_u16(v.z)); }
static inline u32x3 bitmsb_u32x3(u32x3 v) { return u32x3(bitmsb_u32(v.x), bitmsb_u32(v.y), bitmsb_u32(v.z)); }
static inline u64x3 bitmsb_u64x3(u64x3 v) { return u64x3(bitmsb_u64(v.x), bitmsb_u64(v.y), bitmsb_u64(v.z)); }
static inline u8x4 bitmsb_u8x4(u16x4 v) { return u8x4(bitmsb_u8(v.x), bitmsb_u8(v.y), bitmsb_u8(v.z), bitmsb_u8(v.w)); }
static inline u16x4 bitmsb_u16x4(u16x4 v) { return u16x4(bitmsb_u16(v.x), bitmsb_u16(v.y), bitmsb_u16(v.z), bitmsb_u16(v.w)); }
static inline u32x4 bitmsb_u32x4(u32x4 v) { return u32x4(bitmsb_u32(v.x), bitmsb_u32(v.y), bitmsb_u32(v.z), bitmsb_u32(v.w)); }
static inline u64x4 bitmsb_u64x4(u64x4 v) { return u64x4(bitmsb_u64(v.x), bitmsb_u64(v.y), bitmsb_u64(v.z), bitmsb_u64(v.w)); }

//
// returns a vector where each component is the result from bitwise noting that component in 'v'
static inline s8x2 bitnot_s8x2(s8x2 v) { return s8x2(~v.x, ~v.y); }
static inline s16x2 bitnot_s16x2(s16x2 v) { return s16x2(~v.x, ~v.y); }
static inline s32x2 bitnot_s32x2(s32x2 v) { return s32x2(~v.x, ~v.y); }
static inline s64x2 bitnot_s64x2(s64x2 v) { return s64x2(~v.x, ~v.y); }
static inline u8x2 bitnot_u8x2(u8x2 v) { return u8x2(~v.x, ~v.y); }
static inline u16x2 bitnot_u16x2(u16x2 v) { return u16x2(~v.x, ~v.y); }
static inline u32x2 bitnot_u32x2(u32x2 v) { return u32x2(~v.x, ~v.y); }
static inline u64x2 bitnot_u64x2(u64x2 v) { return u64x2(~v.x, ~v.y); }
static inline s8x3 bitnot_s8x3(s8x3 v) { return s8x3(~v.x, ~v.y, ~v.z); }
static inline s16x3 bitnot_s16x3(s16x3 v) { return s16x3(~v.x, ~v.y, ~v.z); }
static inline s32x3 bitnot_s32x3(s32x3 v) { return s32x3(~v.x, ~v.y, ~v.z); }
static inline s64x3 bitnot_s64x3(s64x3 v) { return s64x3(~v.x, ~v.y, ~v.z); }
static inline u8x3 bitnot_u8x3(u8x3 v) { return u8x3(~v.x, ~v.y, ~v.z); }
static inline u16x3 bitnot_u16x3(u16x3 v) { return u16x3(~v.x, ~v.y, ~v.z); }
static inline u32x3 bitnot_u32x3(u32x3 v) { return u32x3(~v.x, ~v.y, ~v.z); }
static inline u64x3 bitnot_u64x3(u64x3 v) { return u64x3(~v.x, ~v.y, ~v.z); }
static inline s8x4 bitnot_s8x4(s8x4 v) { return s8x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline s16x4 bitnot_s16x4(s16x4 v) { return s16x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline s32x4 bitnot_s32x4(s32x4 v) { return s32x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline s64x4 bitnot_s64x4(s64x4 v) { return s64x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline u8x4 bitnot_u8x4(u8x4 v) { return u8x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline u16x4 bitnot_u16x4(u16x4 v) { return u16x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline u32x4 bitnot_u32x4(u32x4 v) { return u32x4(~v.x, ~v.y, ~v.z, ~v.w); }
static inline u64x4 bitnot_u64x4(u64x4 v) { return u64x4(~v.x, ~v.y, ~v.z, ~v.w); }

//
// returns a vector where each component (x) is calculated like so x = (a.x * b.x) + c.x
static inline f16x2 fma_f16x2(f16x2 a, f16x2 b, f16x2 c) { return f16x2(fma_f16(a.x, b.x, c.x), fma_f16(a.y, b.y, c.y)); }
static inline f32x2 fma_f32x2(f32x2 a, f32x2 b, f32x2 c) { return f32x2(fma_f32(a.x, b.x, c.x), fma_f32(a.y, b.y, c.y)); }
static inline f64x2 fma_f64x2(f64x2 a, f64x2 b, f64x2 c) { return f64x2(fma_f64(a.x, b.x, c.x), fma_f64(a.y, b.y, c.y)); }
static inline f16x3 fma_f16x3(f16x3 a, f16x3 b, f16x3 c) { return f16x3(fma_f16(a.x, b.x, c.x), fma_f16(a.y, b.y, c.y), fma_f16(a.z, b.z, c.z)); }
static inline f32x3 fma_f32x3(f32x3 a, f32x3 b, f32x3 c) { return f32x3(fma_f32(a.x, b.x, c.x), fma_f32(a.y, b.y, c.y), fma_f32(a.z, b.z, c.z)); }
static inline f64x3 fma_f64x3(f64x3 a, f64x3 b, f64x3 c) { return f64x3(fma_f64(a.x, b.x, c.x), fma_f64(a.y, b.y, c.y), fma_f64(a.z, b.z, c.z)); }
static inline f16x4 fma_f16x4(f16x4 a, f16x4 b, f16x4 c) { return f16x4(fma_f16(a.x, b.x, c.x), fma_f16(a.y, b.y, c.y), fma_f16(a.z, b.z, c.z), fma_f16(a.w, b.w, c.w)); }
static inline f32x4 fma_f32x4(f32x4 a, f32x4 b, f32x4 c) { return f32x4(fma_f32(a.x, b.x, c.x), fma_f32(a.y, b.y, c.y), fma_f32(a.z, b.z, c.z), fma_f32(a.w, b.w, c.w)); }
static inline f64x4 fma_f64x4(f64x4 a, f64x4 b, f64x4 c) { return f64x4(fma_f64(a.x, b.x, c.x), fma_f64(a.y, b.y, c.y), fma_f64(a.z, b.z, c.z), fma_f64(a.w, b.w, c.w)); }

//
// returns a vector where each component (x) is calculated like so x = (a.x * b.x) + c
static inline f16x2 fmas_f16x2(f16x2 a, f16x2 b, half c) { f16x2 cs = f16x2s(c); return fma_f16x2(a, b, cs); }
static inline f32x2 fmas_f32x2(f32x2 a, f32x2 b, float c) { f32x2 cs = f32x2s(c); return fma_f32x2(a, b, cs); }
static inline f64x2 fmas_f64x2(f64x2 a, f64x2 b, double c) { f64x2 cs = f64x2s(c); return fma_f64x2(a, b, cs); }
static inline f16x3 fmas_f16x3(f16x3 a, f16x3 b, half c) { f16x3 cs = f16x3s(c); return fma_f16x3(a, b, cs); }
static inline f32x3 fmas_f32x3(f32x3 a, f32x3 b, float c) { f32x3 cs = f32x3s(c); return fma_f32x3(a, b, cs); }
static inline f64x3 fmas_f64x3(f64x3 a, f64x3 b, double c) { f64x3 cs = f64x3s(c); return fma_f64x3(a, b, cs); }
static inline f16x4 fmas_f16x4(f16x4 a, f16x4 b, half c) { f16x4 cs = f16x4s(c); return fma_f16x4(a, b, cs); }
static inline f32x4 fmas_f32x4(f32x4 a, f32x4 b, float c) { f32x4 cs = f32x4s(c); return fma_f32x4(a, b, cs); }
static inline f64x4 fmas_f64x4(f64x4 a, f64x4 b, double c) { f64x4 cs = f64x4s(c); return fma_f64x4(a, b, cs); }

//
// returns a vector where each component (x) is calculated like so x = (a.x * b) + c
static inline f16x2 fmass_f16x2(f16x2 a, half b, half c) { f16x2 bs = f16x2s(b); f16x2 cs = f16x2s(c); return fma_f16x2(a, bs, cs); }
static inline f32x2 fmass_f32x2(f32x2 a, float b, float c) { f32x2 bs = f32x2s(b); f32x2 cs = f32x2s(c); return fma_f32x2(a, bs, cs); }
static inline f64x2 fmass_f64x2(f64x2 a, double b, double c) { f64x2 bs = f64x2s(b); f64x2 cs = f64x2s(c); return fma_f64x2(a, bs, cs); }
static inline f16x3 fmass_f16x3(f16x3 a, half b, half c) { f16x3 bs = f16x3s(b); f16x3 cs = f16x3s(c); return fma_f16x3(a, bs, cs); }
static inline f32x3 fmass_f32x3(f32x3 a, float b, float c) { f32x3 bs = f32x3s(b); f32x3 cs = f32x3s(c); return fma_f32x3(a, bs, cs); }
static inline f64x3 fmass_f64x3(f64x3 a, double b, double c) { f64x3 bs = f64x3s(b); f64x3 cs = f64x3s(c); return fma_f64x3(a, bs, cs); }
static inline f16x4 fmass_f16x4(f16x4 a, half b, half c) { f16x4 bs = f16x4s(b); f16x4 cs = f16x4s(c); return fma_f16x4(a, bs, cs); }
static inline f32x4 fmass_f32x4(f32x4 a, float b, float c) { f32x4 bs = f32x4s(b); f32x4 cs = f32x4s(c); return fma_f32x4(a, bs, cs); }
static inline f64x4 fmass_f64x4(f64x4 a, double b, double c) { f64x4 bs = f64x4s(b); f64x4 cs = f64x4s(c); return fma_f64x4(a, bs, cs); }

//
// return a vector where each component is the result of appling 'floor' to that component in 'v'
static inline f16x2 floor_f16x2(f16x2 v) { return f16x2(floor_f16(v.x), floor_f16(v.y)); }
static inline f32x2 floor_f32x2(f32x2 v) { return f32x2(floor_f32(v.x), floor_f32(v.y)); }
static inline f64x2 floor_f64x2(f64x2 v) { return f64x2(floor_f64(v.x), floor_f64(v.y)); }
static inline f16x3 floor_f16x3(f16x3 v) { return f16x3(floor_f16(v.x), floor_f16(v.y), floor_f16(v.z)); }
static inline f32x3 floor_f32x3(f32x3 v) { return f32x3(floor_f32(v.x), floor_f32(v.y), floor_f32(v.z)); }
static inline f64x3 floor_f64x3(f64x3 v) { return f64x3(floor_f64(v.x), floor_f64(v.y), floor_f64(v.z)); }
static inline f16x4 floor_f16x4(f16x4 v) { return f16x4(floor_f16(v.x), floor_f16(v.y), floor_f16(v.z), floor_f16(v.w)); }
static inline f32x4 floor_f32x4(f32x4 v) { return f32x4(floor_f32(v.x), floor_f32(v.y), floor_f32(v.z), floor_f32(v.w)); }
static inline f64x4 floor_f64x4(f64x4 v) { return f64x4(floor_f64(v.x), floor_f64(v.y), floor_f64(v.z), floor_f64(v.w)); }

//
// return a vector where each component is the result of appling 'ceil' to that component in 'v'
static inline f16x2 ceil_f16x2(f16x2 v) { return f16x2(ceil_f16(v.x), ceil_f16(v.y)); }
static inline f32x2 ceil_f32x2(f32x2 v) { return f32x2(ceil_f32(v.x), ceil_f32(v.y)); }
static inline f64x2 ceil_f64x2(f64x2 v) { return f64x2(ceil_f64(v.x), ceil_f64(v.y)); }
static inline f16x3 ceil_f16x3(f16x3 v) { return f16x3(ceil_f16(v.x), ceil_f16(v.y), ceil_f16(v.z)); }
static inline f32x3 ceil_f32x3(f32x3 v) { return f32x3(ceil_f32(v.x), ceil_f32(v.y), ceil_f32(v.z)); }
static inline f64x3 ceil_f64x3(f64x3 v) { return f64x3(ceil_f64(v.x), ceil_f64(v.y), ceil_f64(v.z)); }
static inline f16x4 ceil_f16x4(f16x4 v) { return f16x4(ceil_f16(v.x), ceil_f16(v.y), ceil_f16(v.z), ceil_f16(v.w)); }
static inline f32x4 ceil_f32x4(f32x4 v) { return f32x4(ceil_f32(v.x), ceil_f32(v.y), ceil_f32(v.z), ceil_f32(v.w)); }
static inline f64x4 ceil_f64x4(f64x4 v) { return f64x4(ceil_f64(v.x), ceil_f64(v.y), ceil_f64(v.z), ceil_f64(v.w)); }

//
// return a vector where each component is the result of appling 'round' to that component in 'v'
static inline f16x2 round_f16x2(f16x2 v) { return f16x2(round_f16(v.x), round_f16(v.y)); }
static inline f32x2 round_f32x2(f32x2 v) { return f32x2(round_f32(v.x), round_f32(v.y)); }
static inline f64x2 round_f64x2(f64x2 v) { return f64x2(round_f64(v.x), round_f64(v.y)); }
static inline f16x3 round_f16x3(f16x3 v) { return f16x3(round_f16(v.x), round_f16(v.y), round_f16(v.z)); }
static inline f32x3 round_f32x3(f32x3 v) { return f32x3(round_f32(v.x), round_f32(v.y), round_f32(v.z)); }
static inline f64x3 round_f64x3(f64x3 v) { return f64x3(round_f64(v.x), round_f64(v.y), round_f64(v.z)); }
static inline f16x4 round_f16x4(f16x4 v) { return f16x4(round_f16(v.x), round_f16(v.y), round_f16(v.z), round_f16(v.w)); }
static inline f32x4 round_f32x4(f32x4 v) { return f32x4(round_f32(v.x), round_f32(v.y), round_f32(v.z), round_f32(v.w)); }
static inline f64x4 round_f64x4(f64x4 v) { return f64x4(round_f64(v.x), round_f64(v.y), round_f64(v.z), round_f64(v.w)); }

//
// return a vector where each component is the result of appling 'trunc' to that component in 'v'
static inline f16x2 trunc_f16x2(f16x2 v) { return f16x2(trunc_f16(v.x), trunc_f16(v.y)); }
static inline f32x2 trunc_f32x2(f32x2 v) { return f32x2(trunc_f32(v.x), trunc_f32(v.y)); }
static inline f64x2 trunc_f64x2(f64x2 v) { return f64x2(trunc_f64(v.x), trunc_f64(v.y)); }
static inline f16x3 trunc_f16x3(f16x3 v) { return f16x3(trunc_f16(v.x), trunc_f16(v.y), trunc_f16(v.z)); }
static inline f32x3 trunc_f32x3(f32x3 v) { return f32x3(trunc_f32(v.x), trunc_f32(v.y), trunc_f32(v.z)); }
static inline f64x3 trunc_f64x3(f64x3 v) { return f64x3(trunc_f64(v.x), trunc_f64(v.y), trunc_f64(v.z)); }
static inline f16x4 trunc_f16x4(f16x4 v) { return f16x4(trunc_f16(v.x), trunc_f16(v.y), trunc_f16(v.z), trunc_f16(v.w)); }
static inline f32x4 trunc_f32x4(f32x4 v) { return f32x4(trunc_f32(v.x), trunc_f32(v.y), trunc_f32(v.z), trunc_f32(v.w)); }
static inline f64x4 trunc_f64x4(f64x4 v) { return f64x4(trunc_f64(v.x), trunc_f64(v.y), trunc_f64(v.z), trunc_f64(v.w)); }

//
// return a vector where each component is the result of appling 'fract' to that component in 'v'
static inline f16x2 fract_f16x2(f16x2 v) { return f16x2(fract_f16(v.x), fract_f16(v.y)); }
static inline f32x2 fract_f32x2(f32x2 v) { return f32x2(fract_f32(v.x), fract_f32(v.y)); }
static inline f64x2 fract_f64x2(f64x2 v) { return f64x2(fract_f64(v.x), fract_f64(v.y)); }
static inline f16x3 fract_f16x3(f16x3 v) { return f16x3(fract_f16(v.x), fract_f16(v.y), fract_f16(v.z)); }
static inline f32x3 fract_f32x3(f32x3 v) { return f32x3(fract_f32(v.x), fract_f32(v.y), fract_f32(v.z)); }
static inline f64x3 fract_f64x3(f64x3 v) { return f64x3(fract_f64(v.x), fract_f64(v.y), fract_f64(v.z)); }
static inline f16x4 fract_f16x4(f16x4 v) { return f16x4(fract_f16(v.x), fract_f16(v.y), fract_f16(v.z), fract_f16(v.w)); }
static inline f32x4 fract_f32x4(f32x4 v) { return f32x4(fract_f32(v.x), fract_f32(v.y), fract_f32(v.z), fract_f32(v.w)); }
static inline f64x4 fract_f64x4(f64x4 v) { return f64x4(fract_f64(v.x), fract_f64(v.y), fract_f64(v.z), fract_f64(v.w)); }

//
// return a vector where each component is the result of appling 'radians' to that component in 'v'
static inline f16x2 radians_f16x2(f16x2 v) { return f16x2(radians_f16(v.x), radians_f16(v.y)); }
static inline f32x2 radians_f32x2(f32x2 v) { return f32x2(radians_f32(v.x), radians_f32(v.y)); }
static inline f64x2 radians_f64x2(f64x2 v) { return f64x2(radians_f64(v.x), radians_f64(v.y)); }
static inline f16x3 radians_f16x3(f16x3 v) { return f16x3(radians_f16(v.x), radians_f16(v.y), radians_f16(v.z)); }
static inline f32x3 radians_f32x3(f32x3 v) { return f32x3(radians_f32(v.x), radians_f32(v.y), radians_f32(v.z)); }
static inline f64x3 radians_f64x3(f64x3 v) { return f64x3(radians_f64(v.x), radians_f64(v.y), radians_f64(v.z)); }
static inline f16x4 radians_f16x4(f16x4 v) { return f16x4(radians_f16(v.x), radians_f16(v.y), radians_f16(v.z), radians_f16(v.w)); }
static inline f32x4 radians_f32x4(f32x4 v) { return f32x4(radians_f32(v.x), radians_f32(v.y), radians_f32(v.z), radians_f32(v.w)); }
static inline f64x4 radians_f64x4(f64x4 v) { return f64x4(radians_f64(v.x), radians_f64(v.y), radians_f64(v.z), radians_f64(v.w)); }

//
// return a vector where each component is the result of appling 'degrees' to that component in 'v'
static inline f16x2 degrees_f16x2(f16x2 v) { return f16x2(degrees_f16(v.x), degrees_f16(v.y)); }
static inline f32x2 degrees_f32x2(f32x2 v) { return f32x2(degrees_f32(v.x), degrees_f32(v.y)); }
static inline f64x2 degrees_f64x2(f64x2 v) { return f64x2(degrees_f64(v.x), degrees_f64(v.y)); }
static inline f16x3 degrees_f16x3(f16x3 v) { return f16x3(degrees_f16(v.x), degrees_f16(v.y), degrees_f16(v.z)); }
static inline f32x3 degrees_f32x3(f32x3 v) { return f32x3(degrees_f32(v.x), degrees_f32(v.y), degrees_f32(v.z)); }
static inline f64x3 degrees_f64x3(f64x3 v) { return f64x3(degrees_f64(v.x), degrees_f64(v.y), degrees_f64(v.z)); }
static inline f16x4 degrees_f16x4(f16x4 v) { return f16x4(degrees_f16(v.x), degrees_f16(v.y), degrees_f16(v.z), degrees_f16(v.w)); }
static inline f32x4 degrees_f32x4(f32x4 v) { return f32x4(degrees_f32(v.x), degrees_f32(v.y), degrees_f32(v.z), degrees_f32(v.w)); }
static inline f64x4 degrees_f64x4(f64x4 v) { return f64x4(degrees_f64(v.x), degrees_f64(v.y), degrees_f64(v.z), degrees_f64(v.w)); }

//
// return a vector where each component is the result of appling 'step' to that component in 'v'
static inline f16x2 step_f16x2(f16x2 v, f16x2 edge) { return f16x2(step_f16(v.x, edge.x), step_f16(v.y, edge.y)); }
static inline f32x2 step_f32x2(f32x2 v, f32x2 edge) { return f32x2(step_f32(v.x, edge.x), step_f32(v.y, edge.y)); }
static inline f64x2 step_f64x2(f64x2 v, f64x2 edge) { return f64x2(step_f64(v.x, edge.x), step_f64(v.y, edge.y)); }
static inline f16x3 step_f16x3(f16x3 v, f16x3 edge) { return f16x3(step_f16(v.x, edge.x), step_f16(v.y, edge.y), step_f16(v.z, edge.z)); }
static inline f32x3 step_f32x3(f32x3 v, f32x3 edge) { return f32x3(step_f32(v.x, edge.x), step_f32(v.y, edge.y), step_f32(v.z, edge.z)); }
static inline f64x3 step_f64x3(f64x3 v, f64x3 edge) { return f64x3(step_f64(v.x, edge.x), step_f64(v.y, edge.y), step_f64(v.z, edge.z)); }
static inline f16x4 step_f16x4(f16x4 v, f16x4 edge) { return f16x4(step_f16(v.x, edge.x), step_f16(v.y, edge.y), step_f16(v.z, edge.z), step_f16(v.w, edge.w)); }
static inline f32x4 step_f32x4(f32x4 v, f32x4 edge) { return f32x4(step_f32(v.x, edge.x), step_f32(v.y, edge.y), step_f32(v.z, edge.z), step_f32(v.w, edge.w)); }
static inline f64x4 step_f64x4(f64x4 v, f64x4 edge) { return f64x4(step_f64(v.x, edge.x), step_f64(v.y, edge.y), step_f64(v.z, edge.z), step_f64(v.w, edge.w)); }

//
// return a vector where each component is the result of appling 'step' to that component in 'v'
static inline f16x2 steps_f16x2(f16x2 v, half edge) { f16x2 edges = f16x2s(edge); return step_f16x2(v, edges); }
static inline f32x2 steps_f32x2(f32x2 v, float edge) { f32x2 edges = f32x2s(edge); return step_f32x2(v, edges); }
static inline f64x2 steps_f64x2(f64x2 v, double edge) { f64x2 edges = f64x2s(edge); return step_f64x2(v, edges); }
static inline f16x3 steps_f16x3(f16x3 v, half edge) { f16x3 edges = f16x3s(edge); return step_f16x3(v, edges); }
static inline f32x3 steps_f32x3(f32x3 v, float edge) { f32x3 edges = f32x3s(edge); return step_f32x3(v, edges); }
static inline f64x3 steps_f64x3(f64x3 v, double edge) { f64x3 edges = f64x3s(edge); return step_f64x3(v, edges); }
static inline f16x4 steps_f16x4(f16x4 v, half edge) { f16x4 edges = f16x4s(edge); return step_f16x4(v, edges); }
static inline f32x4 steps_f32x4(f32x4 v, float edge) { f32x4 edges = f32x4s(edge); return step_f32x4(v, edges); }
static inline f64x4 steps_f64x4(f64x4 v, double edge) { f64x4 edges = f64x4s(edge); return step_f64x4(v, edges); }

//
// return a vector where each component is the result of appling 'smoothstep' to that component in 'v'
static inline f16x2 smoothstep_f16x2(f16x2 edge0, f16x2 edge1, f16x2 v) { return f16x2(smoothstep_f16(edge0.x, edge1.x, v.x), smoothstep_f16(edge0.y, edge1.y, v.y)); }
static inline f32x2 smoothstep_f32x2(f32x2 edge0, f32x2 edge1, f32x2 v) { return f32x2(smoothstep_f32(edge0.x, edge1.x, v.x), smoothstep_f32(edge0.y, edge1.y, v.y)); }
static inline f64x2 smoothstep_f64x2(f64x2 edge0, f64x2 edge1, f64x2 v) { return f64x2(smoothstep_f64(edge0.x, edge1.x, v.x), smoothstep_f64(edge0.y, edge1.y, v.y)); }
static inline f16x3 smoothstep_f16x3(f16x3 edge0, f16x3 edge1, f16x3 v) { return f16x3(smoothstep_f16(edge0.x, edge1.x, v.x), smoothstep_f16(edge0.y, edge1.y, v.y), smoothstep_f16(edge0.z, edge1.z, v.z)); }
static inline f32x3 smoothstep_f32x3(f32x3 edge0, f32x3 edge1, f32x3 v) { return f32x3(smoothstep_f32(edge0.x, edge1.x, v.x), smoothstep_f32(edge0.y, edge1.y, v.y), smoothstep_f32(edge0.z, edge1.z, v.z)); }
static inline f64x3 smoothstep_f64x3(f64x3 edge0, f64x3 edge1, f64x3 v) { return f64x3(smoothstep_f64(edge0.x, edge1.x, v.x), smoothstep_f64(edge0.y, edge1.y, v.y), smoothstep_f64(edge0.z, edge1.z, v.z)); }
static inline f16x4 smoothstep_f16x4(f16x4 edge0, f16x4 edge1, f16x4 v) { return f16x4(smoothstep_f16(edge0.x, edge1.x, v.x), smoothstep_f16(edge0.y, edge1.y, v.y), smoothstep_f16(edge0.z, edge1.z, v.z), smoothstep_f16(edge0.w, edge1.w, v.w)); }
static inline f32x4 smoothstep_f32x4(f32x4 edge0, f32x4 edge1, f32x4 v) { return f32x4(smoothstep_f32(edge0.x, edge1.x, v.x), smoothstep_f32(edge0.y, edge1.y, v.y), smoothstep_f32(edge0.z, edge1.z, v.z), smoothstep_f32(edge0.w, edge1.w, v.w)); }
static inline f64x4 smoothstep_f64x4(f64x4 edge0, f64x4 edge1, f64x4 v) { return f64x4(smoothstep_f64(edge0.x, edge1.x, v.x), smoothstep_f64(edge0.y, edge1.y, v.y), smoothstep_f64(edge0.z, edge1.z, v.z), smoothstep_f64(edge0.w, edge1.w, v.w)); }

//
// return a vector where each component is the result of appling 'smoothstep' to that component in 'v'
static inline f16x2 smoothsteps_f16x2(f16x2 edge0, f16x2 edge1, half v) { f16x2 vs = f16x2s(v); return smoothstep_f16x2(edge0, edge1, vs); }
static inline f32x2 smoothsteps_f32x2(f32x2 edge0, f32x2 edge1, float v) { f32x2 vs = f32x2s(v); return smoothstep_f32x2(edge0, edge1, vs); }
static inline f64x2 smoothsteps_f64x2(f64x2 edge0, f64x2 edge1, double v) { f64x2 vs = f64x2s(v); return smoothstep_f64x2(edge0, edge1, vs); }
static inline f16x3 smoothsteps_f16x3(f16x3 edge0, f16x3 edge1, half v) { f16x3 vs = f16x3s(v); return smoothstep_f16x3(edge0, edge1, vs); }
static inline f32x3 smoothsteps_f32x3(f32x3 edge0, f32x3 edge1, float v) { f32x3 vs = f32x3s(v); return smoothstep_f32x3(edge0, edge1, vs); }
static inline f64x3 smoothsteps_f64x3(f64x3 edge0, f64x3 edge1, double v) { f64x3 vs = f64x3s(v); return smoothstep_f64x3(edge0, edge1, vs); }
static inline f16x4 smoothsteps_f16x4(f16x4 edge0, f16x4 edge1, half v) { f16x4 vs = f16x4s(v); return smoothstep_f16x4(edge0, edge1, vs); }
static inline f32x4 smoothsteps_f32x4(f32x4 edge0, f32x4 edge1, float v) { f32x4 vs = f32x4s(v); return smoothstep_f32x4(edge0, edge1, vs); }
static inline f64x4 smoothsteps_f64x4(f64x4 edge0, f64x4 edge1, double v) { f64x4 vs = f64x4s(v); return smoothstep_f64x4(edge0, edge1, vs); }

//
// return a vector where each component is the result of appling 'smoothstep' to that component in 'v'
static inline f16x2 smoothstepss_f16x2(f16x2 edge0, half edge1, half v) { f16x2 edge1s = f16x2s(edge1); f16x2 vs = f16x2s(v); return smoothstep_f16x2(edge0, edge1s, vs); }
static inline f32x2 smoothstepss_f32x2(f32x2 edge0, float edge1, float v) { f32x2 edge1s = f32x2s(edge1); f32x2 vs = f32x2s(v); return smoothstep_f32x2(edge0, edge1s, vs); }
static inline f64x2 smoothstepss_f64x2(f64x2 edge0, double edge1, double v) { f64x2 edge1s = f64x2s(edge1); f64x2 vs = f64x2s(v); return smoothstep_f64x2(edge0, edge1s, vs); }
static inline f16x3 smoothstepss_f16x3(f16x3 edge0, half edge1, half v) { f16x3 edge1s = f16x3s(edge1); f16x3 vs = f16x3s(v); return smoothstep_f16x3(edge0, edge1s, vs); }
static inline f32x3 smoothstepss_f32x3(f32x3 edge0, float edge1, float v) { f32x3 edge1s = f32x3s(edge1); f32x3 vs = f32x3s(v); return smoothstep_f32x3(edge0, edge1s, vs); }
static inline f64x3 smoothstepss_f64x3(f64x3 edge0, double edge1, double v) { f64x3 edge1s = f64x3s(edge1); f64x3 vs = f64x3s(v); return smoothstep_f64x3(edge0, edge1s, vs); }
static inline f16x4 smoothstepss_f16x4(f16x4 edge0, half edge1, half v) { f16x4 edge1s = f16x4s(edge1); f16x4 vs = f16x4s(v); return smoothstep_f16x4(edge0, edge1s, vs); }
static inline f32x4 smoothstepss_f32x4(f32x4 edge0, float edge1, float v) { f32x4 edge1s = f32x4s(edge1); f32x4 vs = f32x4s(v); return smoothstep_f32x4(edge0, edge1s, vs); }
static inline f64x4 smoothstepss_f64x4(f64x4 edge0, double edge1, double v) { f64x4 edge1s = f64x4s(edge1); f64x4 vs = f64x4s(v); return smoothstep_f64x4(edge0, edge1s, vs); }

//
// return a vector where each component is the result of appling 'remap' to that component in 'v', 'from_min', 'from_max', 'to_min' and 'to_max'
static inline f16x2 remap_f16x2(f16x2 v, f16x2 from_min, f16x2 from_max, f16x2 to_min, f16x2 to_max) { return f16x2(remap_f16(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f16(v.y, from_min.y, from_max.y, to_min.y, to_max.y)); }
static inline f32x2 remap_f32x2(f32x2 v, f32x2 from_min, f32x2 from_max, f32x2 to_min, f32x2 to_max) { return f32x2(remap_f32(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f32(v.y, from_min.y, from_max.y, to_min.y, to_max.y)); }
static inline f64x2 remap_f64x2(f64x2 v, f64x2 from_min, f64x2 from_max, f64x2 to_min, f64x2 to_max) { return f64x2(remap_f64(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f64(v.y, from_min.y, from_max.y, to_min.y, to_max.y)); }
static inline f16x3 remap_f16x3(f16x3 v, f16x3 from_min, f16x3 from_max, f16x3 to_min, f16x3 to_max) { return f16x3(remap_f16(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f16(v.y, from_min.y, from_max.y, to_min.y, to_max.y), remap_f16(v.z, from_min.z, from_max.z, to_min.z, to_max.z)); }
static inline f32x3 remap_f32x3(f32x3 v, f32x3 from_min, f32x3 from_max, f32x3 to_min, f32x3 to_max) { return f32x3(remap_f32(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f32(v.y, from_min.y, from_max.y, to_min.y, to_max.y), remap_f32(v.z, from_min.z, from_max.z, to_min.z, to_max.z)); }
static inline f64x3 remap_f64x3(f64x3 v, f64x3 from_min, f64x3 from_max, f64x3 to_min, f64x3 to_max) { return f64x3(remap_f64(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f64(v.y, from_min.y, from_max.y, to_min.y, to_max.y), remap_f64(v.z, from_min.z, from_max.z, to_min.z, to_max.z)); }
static inline f16x4 remap_f16x4(f16x4 v, f16x4 from_min, f16x4 from_max, f16x4 to_min, f16x4 to_max) { return f16x4(remap_f16(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f16(v.y, from_min.y, from_max.y, to_min.y, to_max.y), remap_f16(v.z, from_min.z, from_max.z, to_min.z, to_max.z), remap_f16(v.w, from_min.w, from_max.w, to_min.w, to_max.w)); }
static inline f32x4 remap_f32x4(f32x4 v, f32x4 from_min, f32x4 from_max, f32x4 to_min, f32x4 to_max) { return f32x4(remap_f32(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f32(v.y, from_min.y, from_max.y, to_min.y, to_max.y), remap_f32(v.z, from_min.z, from_max.z, to_min.z, to_max.z), remap_f32(v.w, from_min.w, from_max.w, to_min.w, to_max.w)); }
static inline f64x4 remap_f64x4(f64x4 v, f64x4 from_min, f64x4 from_max, f64x4 to_min, f64x4 to_max) { return f64x4(remap_f64(v.x, from_min.x, from_max.x, to_min.x, to_max.x), remap_f64(v.y, from_min.y, from_max.y, to_min.y, to_max.y), remap_f64(v.z, from_min.z, from_max.z, to_min.z, to_max.z), remap_f64(v.w, from_min.w, from_max.w, to_min.w, to_max.w)); }

//
// return a vector where each component is the result of appling 'remap' to that component in 'v' with scalar 'from_min', 'from_max', 'to_min' and 'to_max'
static inline f16x2 remaps_f16x2(f16x2 v, half from_min, half from_max, half to_min, half to_max) { return f16x2(remap_f16(v.x, from_min, from_max, to_min, to_max), remap_f16(v.y, from_min, from_max, to_min, to_max)); }
static inline f32x2 remaps_f32x2(f32x2 v, float from_min, float from_max, float to_min, float to_max) { return f32x2(remap_f32(v.x, from_min, from_max, to_min, to_max), remap_f32(v.y, from_min, from_max, to_min, to_max)); }
static inline f64x2 remaps_f64x2(f64x2 v, double from_min, double from_max, double to_min, double to_max) { return f64x2(remap_f64(v.x, from_min, from_max, to_min, to_max), remap_f64(v.y, from_min, from_max, to_min, to_max)); }
static inline f16x3 remaps_f16x3(f16x3 v, half from_min, half from_max, half to_min, half to_max) { return f16x3(remap_f16(v.x, from_min, from_max, to_min, to_max), remap_f16(v.y, from_min, from_max, to_min, to_max), remap_f16(v.z, from_min, from_max, to_min, to_max)); }
static inline f32x3 remaps_f32x3(f32x3 v, float from_min, float from_max, float to_min, float to_max) { return f32x3(remap_f32(v.x, from_min, from_max, to_min, to_max), remap_f32(v.y, from_min, from_max, to_min, to_max), remap_f32(v.z, from_min, from_max, to_min, to_max)); }
static inline f64x3 remaps_f64x3(f64x3 v, double from_min, double from_max, double to_min, double to_max) { return f64x3(remap_f64(v.x, from_min, from_max, to_min, to_max), remap_f64(v.y, from_min, from_max, to_min, to_max), remap_f64(v.z, from_min, from_max, to_min, to_max)); }
static inline f16x4 remaps_f16x4(f16x4 v, half from_min, half from_max, half to_min, half to_max) { return f16x4(remap_f16(v.x, from_min, from_max, to_min, to_max), remap_f16(v.y, from_min, from_max, to_min, to_max), remap_f16(v.z, from_min, from_max, to_min, to_max), remap_f16(v.w, from_min, from_max, to_min, to_max)); }
static inline f32x4 remaps_f32x4(f32x4 v, float from_min, float from_max, float to_min, float to_max) { return f32x4(remap_f32(v.x, from_min, from_max, to_min, to_max), remap_f32(v.y, from_min, from_max, to_min, to_max), remap_f32(v.z, from_min, from_max, to_min, to_max), remap_f32(v.w, from_min, from_max, to_min, to_max)); }
static inline f64x4 remaps_f64x4(f64x4 v, double from_min, double from_max, double to_min, double to_max) { return f64x4(remap_f64(v.x, from_min, from_max, to_min, to_max), remap_f64(v.y, from_min, from_max, to_min, to_max), remap_f64(v.z, from_min, from_max, to_min, to_max), remap_f64(v.w, from_min, from_max, to_min, to_max)); }

//
// return a vector where each component is the result of appling 'roundtomultiple' to that component in 'v' and 'multiple'
static inline f16x2 roundtomultiple_f16x2(f16x2 a, f16x2 b) { return f16x2(roundtomultiple_f16(a.x, b.x), roundtomultiple_f16(a.y, b.y)); }
static inline f32x2 roundtomultiple_f32x2(f32x2 a, f32x2 b) { return f32x2(roundtomultiple_f32(a.x, b.x), roundtomultiple_f32(a.y, b.y)); }
static inline f64x2 roundtomultiple_f64x2(f64x2 a, f64x2 b) { return f64x2(roundtomultiple_f64(a.x, b.x), roundtomultiple_f64(a.y, b.y)); }
static inline f16x3 roundtomultiple_f16x3(f16x3 a, f16x3 b) { return f16x3(roundtomultiple_f16(a.x, b.x), roundtomultiple_f16(a.y, b.y), roundtomultiple_f16(a.z, b.z)); }
static inline f32x3 roundtomultiple_f32x3(f32x3 a, f32x3 b) { return f32x3(roundtomultiple_f32(a.x, b.x), roundtomultiple_f32(a.y, b.y), roundtomultiple_f32(a.z, b.z)); }
static inline f64x3 roundtomultiple_f64x3(f64x3 a, f64x3 b) { return f64x3(roundtomultiple_f64(a.x, b.x), roundtomultiple_f64(a.y, b.y), roundtomultiple_f64(a.z, b.z)); }
static inline f16x4 roundtomultiple_f16x4(f16x4 a, f16x4 b) { return f16x4(roundtomultiple_f16(a.x, b.x), roundtomultiple_f16(a.y, b.y), roundtomultiple_f16(a.z, b.z), roundtomultiple_f16(a.w, b.w)); }
static inline f32x4 roundtomultiple_f32x4(f32x4 a, f32x4 b) { return f32x4(roundtomultiple_f32(a.x, b.x), roundtomultiple_f32(a.y, b.y), roundtomultiple_f32(a.z, b.z), roundtomultiple_f32(a.w, b.w)); }
static inline f64x4 roundtomultiple_f64x4(f64x4 a, f64x4 b) { return f64x4(roundtomultiple_f64(a.x, b.x), roundtomultiple_f64(a.y, b.y), roundtomultiple_f64(a.z, b.z), roundtomultiple_f64(a.w, b.w)); }

//
// return a vector where each component is the result of appling 'roundtomultiple' to that component in 'v' with scalar 'multiple'
static inline f16x2 roundtomultiples_f16x2(f16x2 v, half s) { return f16x2(roundtomultiple_f16(v.x, s), roundtomultiple_f16(v.y, s)); }
static inline f32x2 roundtomultiples_f32x2(f32x2 v, float s) { return f32x2(roundtomultiple_f32(v.x, s), roundtomultiple_f32(v.y, s)); }
static inline f64x2 roundtomultiples_f64x2(f64x2 v, double s) { return f64x2(roundtomultiple_f64(v.x, s), roundtomultiple_f64(v.y, s)); }
static inline f16x3 roundtomultiples_f16x3(f16x3 v, half s) { return f16x3(roundtomultiple_f16(v.x, s), roundtomultiple_f16(v.y, s), roundtomultiple_f16(v.z, s)); }
static inline f32x3 roundtomultiples_f32x3(f32x3 v, float s) { return f32x3(roundtomultiple_f32(v.x, s), roundtomultiple_f32(v.y, s), roundtomultiple_f32(v.z, s)); }
static inline f64x3 roundtomultiples_f64x3(f64x3 v, double s) { return f64x3(roundtomultiple_f64(v.x, s), roundtomultiple_f64(v.y, s), roundtomultiple_f64(v.z, s)); }
static inline f16x4 roundtomultiples_f16x4(f16x4 v, half s) { return f16x4(roundtomultiple_f16(v.x, s), roundtomultiple_f16(v.y, s), roundtomultiple_f16(v.z, s), roundtomultiple_f16(v.w, s)); }
static inline f32x4 roundtomultiples_f32x4(f32x4 v, float s) { return f32x4(roundtomultiple_f32(v.x, s), roundtomultiple_f32(v.y, s), roundtomultiple_f32(v.z, s), roundtomultiple_f32(v.w, s)); }
static inline f64x4 roundtomultiples_f64x4(f64x4 v, double s) { return f64x4(roundtomultiple_f64(v.x, s), roundtomultiple_f64(v.y, s), roundtomultiple_f64(v.z, s), roundtomultiple_f64(v.w, s)); }

//
// return a vector where each component is the result of appling 'rounduptomultiple' to that component in 'v' and 'multiple'
static inline f16x2 rounduptomultiple_f16x2(f16x2 a, f16x2 b) { return f16x2(rounduptomultiple_f16(a.x, b.x), rounduptomultiple_f16(a.y, b.y)); }
static inline f32x2 rounduptomultiple_f32x2(f32x2 a, f32x2 b) { return f32x2(rounduptomultiple_f32(a.x, b.x), rounduptomultiple_f32(a.y, b.y)); }
static inline f64x2 rounduptomultiple_f64x2(f64x2 a, f64x2 b) { return f64x2(rounduptomultiple_f64(a.x, b.x), rounduptomultiple_f64(a.y, b.y)); }
static inline f16x3 rounduptomultiple_f16x3(f16x3 a, f16x3 b) { return f16x3(rounduptomultiple_f16(a.x, b.x), rounduptomultiple_f16(a.y, b.y), rounduptomultiple_f16(a.z, b.z)); }
static inline f32x3 rounduptomultiple_f32x3(f32x3 a, f32x3 b) { return f32x3(rounduptomultiple_f32(a.x, b.x), rounduptomultiple_f32(a.y, b.y), rounduptomultiple_f32(a.z, b.z)); }
static inline f64x3 rounduptomultiple_f64x3(f64x3 a, f64x3 b) { return f64x3(rounduptomultiple_f64(a.x, b.x), rounduptomultiple_f64(a.y, b.y), rounduptomultiple_f64(a.z, b.z)); }
static inline f16x4 rounduptomultiple_f16x4(f16x4 a, f16x4 b) { return f16x4(rounduptomultiple_f16(a.x, b.x), rounduptomultiple_f16(a.y, b.y), rounduptomultiple_f16(a.z, b.z), rounduptomultiple_f16(a.w, b.w)); }
static inline f32x4 rounduptomultiple_f32x4(f32x4 a, f32x4 b) { return f32x4(rounduptomultiple_f32(a.x, b.x), rounduptomultiple_f32(a.y, b.y), rounduptomultiple_f32(a.z, b.z), rounduptomultiple_f32(a.w, b.w)); }
static inline f64x4 rounduptomultiple_f64x4(f64x4 a, f64x4 b) { return f64x4(rounduptomultiple_f64(a.x, b.x), rounduptomultiple_f64(a.y, b.y), rounduptomultiple_f64(a.z, b.z), rounduptomultiple_f64(a.w, b.w)); }

//
// return a vector where each component is the result of appling 'rounduptomultiple' to that component in 'v' with scalar 'multiple'
static inline f16x2 rounduptomultiples_f16x2(f16x2 v, half s) { return f16x2(rounduptomultiple_f16(v.x, s), rounduptomultiple_f16(v.y, s)); }
static inline f32x2 rounduptomultiples_f32x2(f32x2 v, float s) { return f32x2(rounduptomultiple_f32(v.x, s), rounduptomultiple_f32(v.y, s)); }
static inline f64x2 rounduptomultiples_f64x2(f64x2 v, double s) { return f64x2(rounduptomultiple_f64(v.x, s), rounduptomultiple_f64(v.y, s)); }
static inline f16x3 rounduptomultiples_f16x3(f16x3 v, half s) { return f16x3(rounduptomultiple_f16(v.x, s), rounduptomultiple_f16(v.y, s), rounduptomultiple_f16(v.z, s)); }
static inline f32x3 rounduptomultiples_f32x3(f32x3 v, float s) { return f32x3(rounduptomultiple_f32(v.x, s), rounduptomultiple_f32(v.y, s), rounduptomultiple_f32(v.z, s)); }
static inline f64x3 rounduptomultiples_f64x3(f64x3 v, double s) { return f64x3(rounduptomultiple_f64(v.x, s), rounduptomultiple_f64(v.y, s), rounduptomultiple_f64(v.z, s)); }
static inline f16x4 rounduptomultiples_f16x4(f16x4 v, half s) { return f16x4(rounduptomultiple_f16(v.x, s), rounduptomultiple_f16(v.y, s), rounduptomultiple_f16(v.z, s), rounduptomultiple_f16(v.w, s)); }
static inline f32x4 rounduptomultiples_f32x4(f32x4 v, float s) { return f32x4(rounduptomultiple_f32(v.x, s), rounduptomultiple_f32(v.y, s), rounduptomultiple_f32(v.z, s), rounduptomultiple_f32(v.w, s)); }
static inline f64x4 rounduptomultiples_f64x4(f64x4 v, double s) { return f64x4(rounduptomultiple_f64(v.x, s), rounduptomultiple_f64(v.y, s), rounduptomultiple_f64(v.z, s), rounduptomultiple_f64(v.w, s)); }

//
// return a vector where each component is the result of appling 'rounddowntomultiple' to that component in 'v' and 'multiple'
static inline f16x2 rounddowntomultiple_f16x2(f16x2 a, f16x2 b) { return f16x2(rounddowntomultiple_f16(a.x, b.x), rounddowntomultiple_f16(a.y, b.y)); }
static inline f32x2 rounddowntomultiple_f32x2(f32x2 a, f32x2 b) { return f32x2(rounddowntomultiple_f32(a.x, b.x), rounddowntomultiple_f32(a.y, b.y)); }
static inline f64x2 rounddowntomultiple_f64x2(f64x2 a, f64x2 b) { return f64x2(rounddowntomultiple_f64(a.x, b.x), rounddowntomultiple_f64(a.y, b.y)); }
static inline f16x3 rounddowntomultiple_f16x3(f16x3 a, f16x3 b) { return f16x3(rounddowntomultiple_f16(a.x, b.x), rounddowntomultiple_f16(a.y, b.y), rounddowntomultiple_f16(a.z, b.z)); }
static inline f32x3 rounddowntomultiple_f32x3(f32x3 a, f32x3 b) { return f32x3(rounddowntomultiple_f32(a.x, b.x), rounddowntomultiple_f32(a.y, b.y), rounddowntomultiple_f32(a.z, b.z)); }
static inline f64x3 rounddowntomultiple_f64x3(f64x3 a, f64x3 b) { return f64x3(rounddowntomultiple_f64(a.x, b.x), rounddowntomultiple_f64(a.y, b.y), rounddowntomultiple_f64(a.z, b.z)); }
static inline f16x4 rounddowntomultiple_f16x4(f16x4 a, f16x4 b) { return f16x4(rounddowntomultiple_f16(a.x, b.x), rounddowntomultiple_f16(a.y, b.y), rounddowntomultiple_f16(a.z, b.z), rounddowntomultiple_f16(a.w, b.w)); }
static inline f32x4 rounddowntomultiple_f32x4(f32x4 a, f32x4 b) { return f32x4(rounddowntomultiple_f32(a.x, b.x), rounddowntomultiple_f32(a.y, b.y), rounddowntomultiple_f32(a.z, b.z), rounddowntomultiple_f32(a.w, b.w)); }
static inline f64x4 rounddowntomultiple_f64x4(f64x4 a, f64x4 b) { return f64x4(rounddowntomultiple_f64(a.x, b.x), rounddowntomultiple_f64(a.y, b.y), rounddowntomultiple_f64(a.z, b.z), rounddowntomultiple_f64(a.w, b.w)); }

//
// return a vector where each component is the result of appling 'rounddowntomultiple' to that component in 'v' with scalar 'multiple'
static inline f16x2 rounddowntomultiples_f16x2(f16x2 v, half s) { return f16x2(rounddowntomultiple_f16(v.x, s), rounddowntomultiple_f16(v.y, s)); }
static inline f32x2 rounddowntomultiples_f32x2(f32x2 v, float s) { return f32x2(rounddowntomultiple_f32(v.x, s), rounddowntomultiple_f32(v.y, s)); }
static inline f64x2 rounddowntomultiples_f64x2(f64x2 v, double s) { return f64x2(rounddowntomultiple_f64(v.x, s), rounddowntomultiple_f64(v.y, s)); }
static inline f16x3 rounddowntomultiples_f16x3(f16x3 v, half s) { return f16x3(rounddowntomultiple_f16(v.x, s), rounddowntomultiple_f16(v.y, s), rounddowntomultiple_f16(v.z, s)); }
static inline f32x3 rounddowntomultiples_f32x3(f32x3 v, float s) { return f32x3(rounddowntomultiple_f32(v.x, s), rounddowntomultiple_f32(v.y, s), rounddowntomultiple_f32(v.z, s)); }
static inline f64x3 rounddowntomultiples_f64x3(f64x3 v, double s) { return f64x3(rounddowntomultiple_f64(v.x, s), rounddowntomultiple_f64(v.y, s), rounddowntomultiple_f64(v.z, s)); }
static inline f16x4 rounddowntomultiples_f16x4(f16x4 v, half s) { return f16x4(rounddowntomultiple_f16(v.x, s), rounddowntomultiple_f16(v.y, s), rounddowntomultiple_f16(v.z, s), rounddowntomultiple_f16(v.w, s)); }
static inline f32x4 rounddowntomultiples_f32x4(f32x4 v, float s) { return f32x4(rounddowntomultiple_f32(v.x, s), rounddowntomultiple_f32(v.y, s), rounddowntomultiple_f32(v.z, s), rounddowntomultiple_f32(v.w, s)); }
static inline f64x4 rounddowntomultiples_f64x4(f64x4 v, double s) { return f64x4(rounddowntomultiple_f64(v.x, s), rounddowntomultiple_f64(v.y, s), rounddowntomultiple_f64(v.z, s), rounddowntomultiple_f64(v.w, s)); }

//
// return a vector where each component is the result of appling 'bitsto' to that component in 'v'
static inline f16x2 bitsto_f16x2(u16x2 v) { return f16x2(bitsto_f16(v.x), bitsto_f16(v.y)); }
static inline f32x2 bitsto_f32x2(u32x2 v) { return f32x2(bitsto_f32(v.x), bitsto_f32(v.y)); }
static inline f64x2 bitsto_f64x2(u64x2 v) { return f64x2(bitsto_f64(v.x), bitsto_f64(v.y)); }
static inline f16x3 bitsto_f16x3(u16x3 v) { return f16x3(bitsto_f16(v.x), bitsto_f16(v.y), bitsto_f16(v.z)); }
static inline f32x3 bitsto_f32x3(u32x3 v) { return f32x3(bitsto_f32(v.x), bitsto_f32(v.y), bitsto_f32(v.z)); }
static inline f64x3 bitsto_f64x3(u64x3 v) { return f64x3(bitsto_f64(v.x), bitsto_f64(v.y), bitsto_f64(v.z)); }
static inline f16x4 bitsto_f16x4(u16x4 v) { return f16x4(bitsto_f16(v.x), bitsto_f16(v.y), bitsto_f16(v.z), bitsto_f16(v.w)); }
static inline f32x4 bitsto_f32x4(u32x4 v) { return f32x4(bitsto_f32(v.x), bitsto_f32(v.y), bitsto_f32(v.z), bitsto_f32(v.w)); }
static inline f64x4 bitsto_f64x4(u64x4 v) { return f64x4(bitsto_f64(v.x), bitsto_f64(v.y), bitsto_f64(v.z), bitsto_f64(v.w)); }

//
// return a vector where each component is the result of appling 'bitsfrom' to that component in 'v'
static inline u16x2 bitsfrom_f16x2(f16x2 v) { return u16x2(bitsfrom_f16(v.x), bitsfrom_f16(v.y)); }
static inline u32x2 bitsfrom_f32x2(f32x2 v) { return u32x2(bitsfrom_f32(v.x), bitsfrom_f32(v.y)); }
static inline u64x2 bitsfrom_f64x2(f64x2 v) { return u64x2(bitsfrom_f64(v.x), bitsfrom_f64(v.y)); }
static inline u16x3 bitsfrom_f16x3(f16x3 v) { return u16x3(bitsfrom_f16(v.x), bitsfrom_f16(v.y), bitsfrom_f16(v.z)); }
static inline u32x3 bitsfrom_f32x3(f32x3 v) { return u32x3(bitsfrom_f32(v.x), bitsfrom_f32(v.y), bitsfrom_f32(v.z)); }
static inline u64x3 bitsfrom_f64x3(f64x3 v) { return u64x3(bitsfrom_f64(v.x), bitsfrom_f64(v.y), bitsfrom_f64(v.z)); }
static inline u16x4 bitsfrom_f16x4(f16x4 v) { return u16x4(bitsfrom_f16(v.x), bitsfrom_f16(v.y), bitsfrom_f16(v.z), bitsfrom_f16(v.w)); }
static inline u32x4 bitsfrom_f32x4(f32x4 v) { return u32x4(bitsfrom_f32(v.x), bitsfrom_f32(v.y), bitsfrom_f32(v.z), bitsfrom_f32(v.w)); }
static inline u64x4 bitsfrom_f64x4(f64x4 v) { return u64x4(bitsfrom_f64(v.x), bitsfrom_f64(v.y), bitsfrom_f64(v.z), bitsfrom_f64(v.w)); }

//
// return a vector where each component is the result of appling 'sin' to that component in 'v'
static inline f16x2 sin_f16x2(f16x2 v) { return f16x2(sin_f16(v.x), sin_f16(v.y)); }
static inline f32x2 sin_f32x2(f32x2 v) { return f32x2(sin_f32(v.x), sin_f32(v.y)); }
static inline f64x2 sin_f64x2(f64x2 v) { return f64x2(sin_f64(v.x), sin_f64(v.y)); }
static inline f16x3 sin_f16x3(f16x3 v) { return f16x3(sin_f16(v.x), sin_f16(v.y), sin_f16(v.z)); }
static inline f32x3 sin_f32x3(f32x3 v) { return f32x3(sin_f32(v.x), sin_f32(v.y), sin_f32(v.z)); }
static inline f64x3 sin_f64x3(f64x3 v) { return f64x3(sin_f64(v.x), sin_f64(v.y), sin_f64(v.z)); }
static inline f16x4 sin_f16x4(f16x4 v) { return f16x4(sin_f16(v.x), sin_f16(v.y), sin_f16(v.z), sin_f16(v.w)); }
static inline f32x4 sin_f32x4(f32x4 v) { return f32x4(sin_f32(v.x), sin_f32(v.y), sin_f32(v.z), sin_f32(v.w)); }
static inline f64x4 sin_f64x4(f64x4 v) { return f64x4(sin_f64(v.x), sin_f64(v.y), sin_f64(v.z), sin_f64(v.w)); }

//
// return a vector where each component is the result of appling 'cos' to that component in 'v'
static inline f16x2 cos_f16x2(f16x2 v) { return f16x2(cos_f16(v.x), cos_f16(v.y)); }
static inline f32x2 cos_f32x2(f32x2 v) { return f32x2(cos_f32(v.x), cos_f32(v.y)); }
static inline f64x2 cos_f64x2(f64x2 v) { return f64x2(cos_f64(v.x), cos_f64(v.y)); }
static inline f16x3 cos_f16x3(f16x3 v) { return f16x3(cos_f16(v.x), cos_f16(v.y), cos_f16(v.z)); }
static inline f32x3 cos_f32x3(f32x3 v) { return f32x3(cos_f32(v.x), cos_f32(v.y), cos_f32(v.z)); }
static inline f64x3 cos_f64x3(f64x3 v) { return f64x3(cos_f64(v.x), cos_f64(v.y), cos_f64(v.z)); }
static inline f16x4 cos_f16x4(f16x4 v) { return f16x4(cos_f16(v.x), cos_f16(v.y), cos_f16(v.z), cos_f16(v.w)); }
static inline f32x4 cos_f32x4(f32x4 v) { return f32x4(cos_f32(v.x), cos_f32(v.y), cos_f32(v.z), cos_f32(v.w)); }
static inline f64x4 cos_f64x4(f64x4 v) { return f64x4(cos_f64(v.x), cos_f64(v.y), cos_f64(v.z), cos_f64(v.w)); }

//
// return a vector where each component is the result of appling 'tan' to that component in 'v'
static inline f16x2 tan_f16x2(f16x2 v) { return f16x2(tan_f16(v.x), tan_f16(v.y)); }
static inline f32x2 tan_f32x2(f32x2 v) { return f32x2(tan_f32(v.x), tan_f32(v.y)); }
static inline f64x2 tan_f64x2(f64x2 v) { return f64x2(tan_f64(v.x), tan_f64(v.y)); }
static inline f16x3 tan_f16x3(f16x3 v) { return f16x3(tan_f16(v.x), tan_f16(v.y), tan_f16(v.z)); }
static inline f32x3 tan_f32x3(f32x3 v) { return f32x3(tan_f32(v.x), tan_f32(v.y), tan_f32(v.z)); }
static inline f64x3 tan_f64x3(f64x3 v) { return f64x3(tan_f64(v.x), tan_f64(v.y), tan_f64(v.z)); }
static inline f16x4 tan_f16x4(f16x4 v) { return f16x4(tan_f16(v.x), tan_f16(v.y), tan_f16(v.z), tan_f16(v.w)); }
static inline f32x4 tan_f32x4(f32x4 v) { return f32x4(tan_f32(v.x), tan_f32(v.y), tan_f32(v.z), tan_f32(v.w)); }
static inline f64x4 tan_f64x4(f64x4 v) { return f64x4(tan_f64(v.x), tan_f64(v.y), tan_f64(v.z), tan_f64(v.w)); }

//
// return a vector where each component is the result of appling 'asin' to that component in 'v'
static inline f16x2 asin_f16x2(f16x2 v) { return f16x2(asin_f16(v.x), asin_f16(v.y)); }
static inline f32x2 asin_f32x2(f32x2 v) { return f32x2(asin_f32(v.x), asin_f32(v.y)); }
static inline f64x2 asin_f64x2(f64x2 v) { return f64x2(asin_f64(v.x), asin_f64(v.y)); }
static inline f16x3 asin_f16x3(f16x3 v) { return f16x3(asin_f16(v.x), asin_f16(v.y), asin_f16(v.z)); }
static inline f32x3 asin_f32x3(f32x3 v) { return f32x3(asin_f32(v.x), asin_f32(v.y), asin_f32(v.z)); }
static inline f64x3 asin_f64x3(f64x3 v) { return f64x3(asin_f64(v.x), asin_f64(v.y), asin_f64(v.z)); }
static inline f16x4 asin_f16x4(f16x4 v) { return f16x4(asin_f16(v.x), asin_f16(v.y), asin_f16(v.z), asin_f16(v.w)); }
static inline f32x4 asin_f32x4(f32x4 v) { return f32x4(asin_f32(v.x), asin_f32(v.y), asin_f32(v.z), asin_f32(v.w)); }
static inline f64x4 asin_f64x4(f64x4 v) { return f64x4(asin_f64(v.x), asin_f64(v.y), asin_f64(v.z), asin_f64(v.w)); }

//
// return a vector where each component is the result of appling 'acos' to that component in 'v'
static inline f16x2 acos_f16x2(f16x2 v) { return f16x2(acos_f16(v.x), acos_f16(v.y)); }
static inline f32x2 acos_f32x2(f32x2 v) { return f32x2(acos_f32(v.x), acos_f32(v.y)); }
static inline f64x2 acos_f64x2(f64x2 v) { return f64x2(acos_f64(v.x), acos_f64(v.y)); }
static inline f16x3 acos_f16x3(f16x3 v) { return f16x3(acos_f16(v.x), acos_f16(v.y), acos_f16(v.z)); }
static inline f32x3 acos_f32x3(f32x3 v) { return f32x3(acos_f32(v.x), acos_f32(v.y), acos_f32(v.z)); }
static inline f64x3 acos_f64x3(f64x3 v) { return f64x3(acos_f64(v.x), acos_f64(v.y), acos_f64(v.z)); }
static inline f16x4 acos_f16x4(f16x4 v) { return f16x4(acos_f16(v.x), acos_f16(v.y), acos_f16(v.z), acos_f16(v.w)); }
static inline f32x4 acos_f32x4(f32x4 v) { return f32x4(acos_f32(v.x), acos_f32(v.y), acos_f32(v.z), acos_f32(v.w)); }
static inline f64x4 acos_f64x4(f64x4 v) { return f64x4(acos_f64(v.x), acos_f64(v.y), acos_f64(v.z), acos_f64(v.w)); }

//
// return a vector where each component is the result of appling 'atan' to that component in 'v'
static inline f16x2 atan_f16x2(f16x2 v) { return f16x2(atan_f16(v.x), atan_f16(v.y)); }
static inline f32x2 atan_f32x2(f32x2 v) { return f32x2(atan_f32(v.x), atan_f32(v.y)); }
static inline f64x2 atan_f64x2(f64x2 v) { return f64x2(atan_f64(v.x), atan_f64(v.y)); }
static inline f16x3 atan_f16x3(f16x3 v) { return f16x3(atan_f16(v.x), atan_f16(v.y), atan_f16(v.z)); }
static inline f32x3 atan_f32x3(f32x3 v) { return f32x3(atan_f32(v.x), atan_f32(v.y), atan_f32(v.z)); }
static inline f64x3 atan_f64x3(f64x3 v) { return f64x3(atan_f64(v.x), atan_f64(v.y), atan_f64(v.z)); }
static inline f16x4 atan_f16x4(f16x4 v) { return f16x4(atan_f16(v.x), atan_f16(v.y), atan_f16(v.z), atan_f16(v.w)); }
static inline f32x4 atan_f32x4(f32x4 v) { return f32x4(atan_f32(v.x), atan_f32(v.y), atan_f32(v.z), atan_f32(v.w)); }
static inline f64x4 atan_f64x4(f64x4 v) { return f64x4(atan_f64(v.x), atan_f64(v.y), atan_f64(v.z), atan_f64(v.w)); }

//
// return a vector where each component is the result of appling 'sinh' to that component in 'v'
static inline f16x2 sinh_f16x2(f16x2 v) { return f16x2(sinh_f16(v.x), sinh_f16(v.y)); }
static inline f32x2 sinh_f32x2(f32x2 v) { return f32x2(sinh_f32(v.x), sinh_f32(v.y)); }
static inline f64x2 sinh_f64x2(f64x2 v) { return f64x2(sinh_f64(v.x), sinh_f64(v.y)); }
static inline f16x3 sinh_f16x3(f16x3 v) { return f16x3(sinh_f16(v.x), sinh_f16(v.y), sinh_f16(v.z)); }
static inline f32x3 sinh_f32x3(f32x3 v) { return f32x3(sinh_f32(v.x), sinh_f32(v.y), sinh_f32(v.z)); }
static inline f64x3 sinh_f64x3(f64x3 v) { return f64x3(sinh_f64(v.x), sinh_f64(v.y), sinh_f64(v.z)); }
static inline f16x4 sinh_f16x4(f16x4 v) { return f16x4(sinh_f16(v.x), sinh_f16(v.y), sinh_f16(v.z), sinh_f16(v.w)); }
static inline f32x4 sinh_f32x4(f32x4 v) { return f32x4(sinh_f32(v.x), sinh_f32(v.y), sinh_f32(v.z), sinh_f32(v.w)); }
static inline f64x4 sinh_f64x4(f64x4 v) { return f64x4(sinh_f64(v.x), sinh_f64(v.y), sinh_f64(v.z), sinh_f64(v.w)); }

//
// return a vector where each component is the result of appling 'cosh' to that component in 'v'
static inline f16x2 cosh_f16x2(f16x2 v) { return f16x2(cosh_f16(v.x), cosh_f16(v.y)); }
static inline f32x2 cosh_f32x2(f32x2 v) { return f32x2(cosh_f32(v.x), cosh_f32(v.y)); }
static inline f64x2 cosh_f64x2(f64x2 v) { return f64x2(cosh_f64(v.x), cosh_f64(v.y)); }
static inline f16x3 cosh_f16x3(f16x3 v) { return f16x3(cosh_f16(v.x), cosh_f16(v.y), cosh_f16(v.z)); }
static inline f32x3 cosh_f32x3(f32x3 v) { return f32x3(cosh_f32(v.x), cosh_f32(v.y), cosh_f32(v.z)); }
static inline f64x3 cosh_f64x3(f64x3 v) { return f64x3(cosh_f64(v.x), cosh_f64(v.y), cosh_f64(v.z)); }
static inline f16x4 cosh_f16x4(f16x4 v) { return f16x4(cosh_f16(v.x), cosh_f16(v.y), cosh_f16(v.z), cosh_f16(v.w)); }
static inline f32x4 cosh_f32x4(f32x4 v) { return f32x4(cosh_f32(v.x), cosh_f32(v.y), cosh_f32(v.z), cosh_f32(v.w)); }
static inline f64x4 cosh_f64x4(f64x4 v) { return f64x4(cosh_f64(v.x), cosh_f64(v.y), cosh_f64(v.z), cosh_f64(v.w)); }

//
// return a vector where each component is the result of appling 'tanh' to that component in 'v'
static inline f16x2 tanh_f16x2(f16x2 v) { return f16x2(tanh_f16(v.x), tanh_f16(v.y)); }
static inline f32x2 tanh_f32x2(f32x2 v) { return f32x2(tanh_f32(v.x), tanh_f32(v.y)); }
static inline f64x2 tanh_f64x2(f64x2 v) { return f64x2(tanh_f64(v.x), tanh_f64(v.y)); }
static inline f16x3 tanh_f16x3(f16x3 v) { return f16x3(tanh_f16(v.x), tanh_f16(v.y), tanh_f16(v.z)); }
static inline f32x3 tanh_f32x3(f32x3 v) { return f32x3(tanh_f32(v.x), tanh_f32(v.y), tanh_f32(v.z)); }
static inline f64x3 tanh_f64x3(f64x3 v) { return f64x3(tanh_f64(v.x), tanh_f64(v.y), tanh_f64(v.z)); }
static inline f16x4 tanh_f16x4(f16x4 v) { return f16x4(tanh_f16(v.x), tanh_f16(v.y), tanh_f16(v.z), tanh_f16(v.w)); }
static inline f32x4 tanh_f32x4(f32x4 v) { return f32x4(tanh_f32(v.x), tanh_f32(v.y), tanh_f32(v.z), tanh_f32(v.w)); }
static inline f64x4 tanh_f64x4(f64x4 v) { return f64x4(tanh_f64(v.x), tanh_f64(v.y), tanh_f64(v.z), tanh_f64(v.w)); }

//
// return a vector where each component is the result of appling 'asinh' to that component in 'v'
static inline f16x2 asinh_f16x2(f16x2 v) { return f16x2(asinh_f16(v.x), asinh_f16(v.y)); }
static inline f32x2 asinh_f32x2(f32x2 v) { return f32x2(asinh_f32(v.x), asinh_f32(v.y)); }
static inline f64x2 asinh_f64x2(f64x2 v) { return f64x2(asinh_f64(v.x), asinh_f64(v.y)); }
static inline f16x3 asinh_f16x3(f16x3 v) { return f16x3(asinh_f16(v.x), asinh_f16(v.y), asinh_f16(v.z)); }
static inline f32x3 asinh_f32x3(f32x3 v) { return f32x3(asinh_f32(v.x), asinh_f32(v.y), asinh_f32(v.z)); }
static inline f64x3 asinh_f64x3(f64x3 v) { return f64x3(asinh_f64(v.x), asinh_f64(v.y), asinh_f64(v.z)); }
static inline f16x4 asinh_f16x4(f16x4 v) { return f16x4(asinh_f16(v.x), asinh_f16(v.y), asinh_f16(v.z), asinh_f16(v.w)); }
static inline f32x4 asinh_f32x4(f32x4 v) { return f32x4(asinh_f32(v.x), asinh_f32(v.y), asinh_f32(v.z), asinh_f32(v.w)); }
static inline f64x4 asinh_f64x4(f64x4 v) { return f64x4(asinh_f64(v.x), asinh_f64(v.y), asinh_f64(v.z), asinh_f64(v.w)); }

//
// return a vector where each component is the result of appling 'acosh' to that component in 'v'
static inline f16x2 acosh_f16x2(f16x2 v) { return f16x2(acosh_f16(v.x), acosh_f16(v.y)); }
static inline f32x2 acosh_f32x2(f32x2 v) { return f32x2(acosh_f32(v.x), acosh_f32(v.y)); }
static inline f64x2 acosh_f64x2(f64x2 v) { return f64x2(acosh_f64(v.x), acosh_f64(v.y)); }
static inline f16x3 acosh_f16x3(f16x3 v) { return f16x3(acosh_f16(v.x), acosh_f16(v.y), acosh_f16(v.z)); }
static inline f32x3 acosh_f32x3(f32x3 v) { return f32x3(acosh_f32(v.x), acosh_f32(v.y), acosh_f32(v.z)); }
static inline f64x3 acosh_f64x3(f64x3 v) { return f64x3(acosh_f64(v.x), acosh_f64(v.y), acosh_f64(v.z)); }
static inline f16x4 acosh_f16x4(f16x4 v) { return f16x4(acosh_f16(v.x), acosh_f16(v.y), acosh_f16(v.z), acosh_f16(v.w)); }
static inline f32x4 acosh_f32x4(f32x4 v) { return f32x4(acosh_f32(v.x), acosh_f32(v.y), acosh_f32(v.z), acosh_f32(v.w)); }
static inline f64x4 acosh_f64x4(f64x4 v) { return f64x4(acosh_f64(v.x), acosh_f64(v.y), acosh_f64(v.z), acosh_f64(v.w)); }

//
// return a vector where each component is the result of appling 'atanh' to that component in 'v'
static inline f16x2 atanh_f16x2(f16x2 v) { return f16x2(atanh_f16(v.x), atanh_f16(v.y)); }
static inline f32x2 atanh_f32x2(f32x2 v) { return f32x2(atanh_f32(v.x), atanh_f32(v.y)); }
static inline f64x2 atanh_f64x2(f64x2 v) { return f64x2(atanh_f64(v.x), atanh_f64(v.y)); }
static inline f16x3 atanh_f16x3(f16x3 v) { return f16x3(atanh_f16(v.x), atanh_f16(v.y), atanh_f16(v.z)); }
static inline f32x3 atanh_f32x3(f32x3 v) { return f32x3(atanh_f32(v.x), atanh_f32(v.y), atanh_f32(v.z)); }
static inline f64x3 atanh_f64x3(f64x3 v) { return f64x3(atanh_f64(v.x), atanh_f64(v.y), atanh_f64(v.z)); }
static inline f16x4 atanh_f16x4(f16x4 v) { return f16x4(atanh_f16(v.x), atanh_f16(v.y), atanh_f16(v.z), atanh_f16(v.w)); }
static inline f32x4 atanh_f32x4(f32x4 v) { return f32x4(atanh_f32(v.x), atanh_f32(v.y), atanh_f32(v.z), atanh_f32(v.w)); }
static inline f64x4 atanh_f64x4(f64x4 v) { return f64x4(atanh_f64(v.x), atanh_f64(v.y), atanh_f64(v.z), atanh_f64(v.w)); }

//
// return a vector where each component is the result of appling 'atan2' to that component in 'v'
static inline f16x2 atan2_f16x2(f16x2 y, f16x2 x) { return f16x2(atan2_f16(y.x, x.x), atan2_f16(y.y, x.y)); }
static inline f32x2 atan2_f32x2(f32x2 y, f32x2 x) { return f32x2(atan2_f32(y.x, x.x), atan2_f32(y.y, x.y)); }
static inline f64x2 atan2_f64x2(f64x2 y, f64x2 x) { return f64x2(atan2_f64(y.x, x.x), atan2_f64(y.y, x.y)); }
static inline f16x3 atan2_f16x3(f16x3 y, f16x3 x) { return f16x3(atan2_f16(y.x, x.x), atan2_f16(y.y, x.y), atan2_f16(y.z, x.z)); }
static inline f32x3 atan2_f32x3(f32x3 y, f32x3 x) { return f32x3(atan2_f32(y.x, x.x), atan2_f32(y.y, x.y), atan2_f32(y.z, x.z)); }
static inline f64x3 atan2_f64x3(f64x3 y, f64x3 x) { return f64x3(atan2_f64(y.x, x.x), atan2_f64(y.y, x.y), atan2_f64(y.z, x.z)); }
static inline f16x4 atan2_f16x4(f16x4 y, f16x4 x) { return f16x4(atan2_f16(y.x, x.x), atan2_f16(y.y, x.y), atan2_f16(y.z, x.z), atan2_f16(y.w, x.w)); }
static inline f32x4 atan2_f32x4(f32x4 y, f32x4 x) { return f32x4(atan2_f32(y.x, x.x), atan2_f32(y.y, x.y), atan2_f32(y.z, x.z), atan2_f32(y.w, x.w)); }
static inline f64x4 atan2_f64x4(f64x4 y, f64x4 x) { return f64x4(atan2_f64(y.x, x.x), atan2_f64(y.y, x.y), atan2_f64(y.z, x.z), atan2_f64(y.w, x.w)); }

//
// return a vector where each component is the result of appling 'pow' to that component in 'v'
static inline f16x2 pow_f16x2(f16x2 a, f16x2 b) { return f16x2(pow_f16(a.x, b.x), pow_f16(a.y, b.y)); }
static inline f32x2 pow_f32x2(f32x2 a, f32x2 b) { return f32x2(pow_f32(a.x, b.x), pow_f32(a.y, b.y)); }
static inline f64x2 pow_f64x2(f64x2 a, f64x2 b) { return f64x2(pow_f64(a.x, b.x), pow_f64(a.y, b.y)); }
static inline f16x3 pow_f16x3(f16x3 a, f16x3 b) { return f16x3(pow_f16(a.x, b.x), pow_f16(a.y, b.y), pow_f16(a.z, b.z)); }
static inline f32x3 pow_f32x3(f32x3 a, f32x3 b) { return f32x3(pow_f32(a.x, b.x), pow_f32(a.y, b.y), pow_f32(a.z, b.z)); }
static inline f64x3 pow_f64x3(f64x3 a, f64x3 b) { return f64x3(pow_f64(a.x, b.x), pow_f64(a.y, b.y), pow_f64(a.z, b.z)); }
static inline f16x4 pow_f16x4(f16x4 a, f16x4 b) { return f16x4(pow_f16(a.x, b.x), pow_f16(a.y, b.y), pow_f16(a.z, b.z), pow_f16(a.w, b.w)); }
static inline f32x4 pow_f32x4(f32x4 a, f32x4 b) { return f32x4(pow_f32(a.x, b.x), pow_f32(a.y, b.y), pow_f32(a.z, b.z), pow_f32(a.w, b.w)); }
static inline f64x4 pow_f64x4(f64x4 a, f64x4 b) { return f64x4(pow_f64(a.x, b.x), pow_f64(a.y, b.y), pow_f64(a.z, b.z), pow_f64(a.w, b.w)); }

//
// return a vector where each component is the result of appling 'exp' to that component in 'v'
static inline f16x2 exp_f16x2(f16x2 v) { return f16x2(exp_f16(v.x), exp_f16(v.y)); }
static inline f32x2 exp_f32x2(f32x2 v) { return f32x2(exp_f32(v.x), exp_f32(v.y)); }
static inline f64x2 exp_f64x2(f64x2 v) { return f64x2(exp_f64(v.x), exp_f64(v.y)); }
static inline f16x3 exp_f16x3(f16x3 v) { return f16x3(exp_f16(v.x), exp_f16(v.y), exp_f16(v.z)); }
static inline f32x3 exp_f32x3(f32x3 v) { return f32x3(exp_f32(v.x), exp_f32(v.y), exp_f32(v.z)); }
static inline f64x3 exp_f64x3(f64x3 v) { return f64x3(exp_f64(v.x), exp_f64(v.y), exp_f64(v.z)); }
static inline f16x4 exp_f16x4(f16x4 v) { return f16x4(exp_f16(v.x), exp_f16(v.y), exp_f16(v.z), exp_f16(v.w)); }
static inline f32x4 exp_f32x4(f32x4 v) { return f32x4(exp_f32(v.x), exp_f32(v.y), exp_f32(v.z), exp_f32(v.w)); }
static inline f64x4 exp_f64x4(f64x4 v) { return f64x4(exp_f64(v.x), exp_f64(v.y), exp_f64(v.z), exp_f64(v.w)); }

//
// return a vector where each component is the result of appling 'log' to that component in 'v'
static inline f16x2 log_f16x2(f16x2 v) { return f16x2(log_f16(v.x), log_f16(v.y)); }
static inline f32x2 log_f32x2(f32x2 v) { return f32x2(log_f32(v.x), log_f32(v.y)); }
static inline f64x2 log_f64x2(f64x2 v) { return f64x2(log_f64(v.x), log_f64(v.y)); }
static inline f16x3 log_f16x3(f16x3 v) { return f16x3(log_f16(v.x), log_f16(v.y), log_f16(v.z)); }
static inline f32x3 log_f32x3(f32x3 v) { return f32x3(log_f32(v.x), log_f32(v.y), log_f32(v.z)); }
static inline f64x3 log_f64x3(f64x3 v) { return f64x3(log_f64(v.x), log_f64(v.y), log_f64(v.z)); }
static inline f16x4 log_f16x4(f16x4 v) { return f16x4(log_f16(v.x), log_f16(v.y), log_f16(v.z), log_f16(v.w)); }
static inline f32x4 log_f32x4(f32x4 v) { return f32x4(log_f32(v.x), log_f32(v.y), log_f32(v.z), log_f32(v.w)); }
static inline f64x4 log_f64x4(f64x4 v) { return f64x4(log_f64(v.x), log_f64(v.y), log_f64(v.z), log_f64(v.w)); }

//
// return a vector where each component is the result of appling 'exp2' to that component in 'v'
static inline f16x2 exp2_f16x2(f16x2 v) { return f16x2(exp2_f16(v.x), exp2_f16(v.y)); }
static inline f32x2 exp2_f32x2(f32x2 v) { return f32x2(exp2_f32(v.x), exp2_f32(v.y)); }
static inline f64x2 exp2_f64x2(f64x2 v) { return f64x2(exp2_f64(v.x), exp2_f64(v.y)); }
static inline f16x3 exp2_f16x3(f16x3 v) { return f16x3(exp2_f16(v.x), exp2_f16(v.y), exp2_f16(v.z)); }
static inline f32x3 exp2_f32x3(f32x3 v) { return f32x3(exp2_f32(v.x), exp2_f32(v.y), exp2_f32(v.z)); }
static inline f64x3 exp2_f64x3(f64x3 v) { return f64x3(exp2_f64(v.x), exp2_f64(v.y), exp2_f64(v.z)); }
static inline f16x4 exp2_f16x4(f16x4 v) { return f16x4(exp2_f16(v.x), exp2_f16(v.y), exp2_f16(v.z), exp2_f16(v.w)); }
static inline f32x4 exp2_f32x4(f32x4 v) { return f32x4(exp2_f32(v.x), exp2_f32(v.y), exp2_f32(v.z), exp2_f32(v.w)); }
static inline f64x4 exp2_f64x4(f64x4 v) { return f64x4(exp2_f64(v.x), exp2_f64(v.y), exp2_f64(v.z), exp2_f64(v.w)); }

//
// return a vector where each component is the result of appling 'log2' to that component in 'v'
static inline f16x2 log2_f16x2(f16x2 v) { return f16x2(log2_f16(v.x), log2_f16(v.y)); }
static inline f32x2 log2_f32x2(f32x2 v) { return f32x2(log2_f32(v.x), log2_f32(v.y)); }
static inline f64x2 log2_f64x2(f64x2 v) { return f64x2(log2_f64(v.x), log2_f64(v.y)); }
static inline f16x3 log2_f16x3(f16x3 v) { return f16x3(log2_f16(v.x), log2_f16(v.y), log2_f16(v.z)); }
static inline f32x3 log2_f32x3(f32x3 v) { return f32x3(log2_f32(v.x), log2_f32(v.y), log2_f32(v.z)); }
static inline f64x3 log2_f64x3(f64x3 v) { return f64x3(log2_f64(v.x), log2_f64(v.y), log2_f64(v.z)); }
static inline f16x4 log2_f16x4(f16x4 v) { return f16x4(log2_f16(v.x), log2_f16(v.y), log2_f16(v.z), log2_f16(v.w)); }
static inline f32x4 log2_f32x4(f32x4 v) { return f32x4(log2_f32(v.x), log2_f32(v.y), log2_f32(v.z), log2_f32(v.w)); }
static inline f64x4 log2_f64x4(f64x4 v) { return f64x4(log2_f64(v.x), log2_f64(v.y), log2_f64(v.z), log2_f64(v.w)); }

//
// return a vector where each component is the result of appling 'sqrt' to that component in 'v'
static inline f16x2 sqrt_f16x2(f16x2 v) { return f16x2(sqrt_f16(v.x), sqrt_f16(v.y)); }
static inline f32x2 sqrt_f32x2(f32x2 v) { return f32x2(sqrt_f32(v.x), sqrt_f32(v.y)); }
static inline f64x2 sqrt_f64x2(f64x2 v) { return f64x2(sqrt_f64(v.x), sqrt_f64(v.y)); }
static inline f16x3 sqrt_f16x3(f16x3 v) { return f16x3(sqrt_f16(v.x), sqrt_f16(v.y), sqrt_f16(v.z)); }
static inline f32x3 sqrt_f32x3(f32x3 v) { return f32x3(sqrt_f32(v.x), sqrt_f32(v.y), sqrt_f32(v.z)); }
static inline f64x3 sqrt_f64x3(f64x3 v) { return f64x3(sqrt_f64(v.x), sqrt_f64(v.y), sqrt_f64(v.z)); }
static inline f16x4 sqrt_f16x4(f16x4 v) { return f16x4(sqrt_f16(v.x), sqrt_f16(v.y), sqrt_f16(v.z), sqrt_f16(v.w)); }
static inline f32x4 sqrt_f32x4(f32x4 v) { return f32x4(sqrt_f32(v.x), sqrt_f32(v.y), sqrt_f32(v.z), sqrt_f32(v.w)); }
static inline f64x4 sqrt_f64x4(f64x4 v) { return f64x4(sqrt_f64(v.x), sqrt_f64(v.y), sqrt_f64(v.z), sqrt_f64(v.w)); }

//
// return a vector where each component is the result of appling 'rsqrt' to that component in 'v'
static inline f16x2 rsqrt_f16x2(f16x2 v) { return f16x2(rsqrt_f16(v.x), rsqrt_f16(v.y)); }
static inline f32x2 rsqrt_f32x2(f32x2 v) { return f32x2(rsqrt_f32(v.x), rsqrt_f32(v.y)); }
static inline f64x2 rsqrt_f64x2(f64x2 v) { return f64x2(rsqrt_f64(v.x), rsqrt_f64(v.y)); }
static inline f16x3 rsqrt_f16x3(f16x3 v) { return f16x3(rsqrt_f16(v.x), rsqrt_f16(v.y), rsqrt_f16(v.z)); }
static inline f32x3 rsqrt_f32x3(f32x3 v) { return f32x3(rsqrt_f32(v.x), rsqrt_f32(v.y), rsqrt_f32(v.z)); }
static inline f64x3 rsqrt_f64x3(f64x3 v) { return f64x3(rsqrt_f64(v.x), rsqrt_f64(v.y), rsqrt_f64(v.z)); }
static inline f16x4 rsqrt_f16x4(f16x4 v) { return f16x4(rsqrt_f16(v.x), rsqrt_f16(v.y), rsqrt_f16(v.z), rsqrt_f16(v.w)); }
static inline f32x4 rsqrt_f32x4(f32x4 v) { return f32x4(rsqrt_f32(v.x), rsqrt_f32(v.y), rsqrt_f32(v.z), rsqrt_f32(v.w)); }
static inline f64x4 rsqrt_f64x4(f64x4 v) { return f64x4(rsqrt_f64(v.x), rsqrt_f64(v.y), rsqrt_f64(v.z), rsqrt_f64(v.w)); }

//
// returns true if each component in 'a' is 'epsilon' away from that component that is in 'b'
static inline boolx2 approxeq_f16x2(f16x2 a, f16x2 b, half epsilon) { return boolx2(approxeq_f16(a.x, b.x, epsilon), approxeq_f16(a.y, b.y, epsilon)); }
static inline boolx2 approxeq_f32x2(f32x2 a, f32x2 b, float epsilon) { return boolx2(approxeq_f32(a.x, b.x, epsilon), approxeq_f32(a.y, b.y, epsilon)); }
static inline boolx2 approxeq_f64x2(f64x2 a, f64x2 b, double epsilon) { return boolx2(approxeq_f64(a.x, b.x, epsilon), approxeq_f64(a.y, b.y, epsilon)); }
static inline boolx3 approxeq_f16x3(f16x3 a, f16x3 b, half epsilon) { return boolx3(approxeq_f16(a.x, b.x, epsilon), approxeq_f16(a.y, b.y, epsilon), approxeq_f16(a.z, b.z, epsilon)); }
static inline boolx3 approxeq_f32x3(f32x3 a, f32x3 b, float epsilon) { return boolx3(approxeq_f32(a.x, b.x, epsilon), approxeq_f32(a.y, b.y, epsilon), approxeq_f32(a.z, b.z, epsilon)); }
static inline boolx3 approxeq_f64x3(f64x3 a, f64x3 b, double epsilon) { return boolx3(approxeq_f64(a.x, b.x, epsilon), approxeq_f64(a.y, b.y, epsilon), approxeq_f64(a.z, b.z, epsilon)); }
static inline boolx4 approxeq_f16x4(f16x4 a, f16x4 b, half epsilon) { return boolx4(approxeq_f16(a.x, b.x, epsilon), approxeq_f16(a.y, b.y, epsilon), approxeq_f16(a.z, b.z, epsilon), approxeq_f16(a.w, b.w, epsilon)); }
static inline boolx4 approxeq_f32x4(f32x4 a, f32x4 b, float epsilon) { return boolx4(approxeq_f32(a.x, b.x, epsilon), approxeq_f32(a.y, b.y, epsilon), approxeq_f32(a.z, b.z, epsilon), approxeq_f32(a.w, b.w, epsilon)); }
static inline boolx4 approxeq_f64x4(f64x4 a, f64x4 b, double epsilon) { return boolx4(approxeq_f64(a.x, b.x, epsilon), approxeq_f64(a.y, b.y, epsilon), approxeq_f64(a.z, b.z, epsilon), approxeq_f64(a.w, b.w, epsilon)); }

//
// returns true if each component in 'v' is 'epsilon' away from 's'
static inline boolx2 approxeqs_f16x2(f16x2 v, half s, half epsilon) { return boolx2(approxeq_f16(v.x, s, epsilon), approxeq_f16(v.y, s, epsilon)); }
static inline boolx2 approxeqs_f32x2(f32x2 v, float s, float epsilon) { return boolx2(approxeq_f32(v.x, s, epsilon), approxeq_f32(v.y, s, epsilon)); }
static inline boolx2 approxeqs_f64x2(f64x2 v, double s, double epsilon) { return boolx2(approxeq_f64(v.x, s, epsilon), approxeq_f64(v.y, s, epsilon)); }
static inline boolx3 approxeqs_f16x3(f16x3 v, half s, half epsilon) { return boolx3(approxeq_f16(v.x, s, epsilon), approxeq_f16(v.y, s, epsilon), approxeq_f16(v.z, s, epsilon)); }
static inline boolx3 approxeqs_f32x3(f32x3 v, float s, float epsilon) { return boolx3(approxeq_f32(v.x, s, epsilon), approxeq_f32(v.y, s, epsilon), approxeq_f32(v.z, s, epsilon)); }
static inline boolx3 approxeqs_f64x3(f64x3 v, double s, double epsilon) { return boolx3(approxeq_f64(v.x, s, epsilon), approxeq_f64(v.y, s, epsilon), approxeq_f64(v.z, s, epsilon)); }
static inline boolx4 approxeqs_f16x4(f16x4 v, half s, half epsilon) { return boolx4(approxeq_f16(v.x, s, epsilon), approxeq_f16(v.y, s, epsilon), approxeq_f16(v.z, s, epsilon), approxeq_f16(v.w, s, epsilon)); }
static inline boolx4 approxeqs_f32x4(f32x4 v, float s, float epsilon) { return boolx4(approxeq_f32(v.x, s, epsilon), approxeq_f32(v.y, s, epsilon), approxeq_f32(v.z, s, epsilon), approxeq_f32(v.w, s, epsilon)); }
static inline boolx4 approxeqs_f64x4(f64x4 v, double s, double epsilon) { return boolx4(approxeq_f64(v.x, s, epsilon), approxeq_f64(v.y, s, epsilon), approxeq_f64(v.z, s, epsilon), approxeq_f64(v.w, s, epsilon)); }

//
// return a vector where each component is the result of appling 'isinf' to that component in 'v'
static inline boolx2 isinf_f16x2(f16x2 v) { return boolx2(isinf_f16(v.x), isinf_f16(v.y)); }
static inline boolx2 isinf_f32x2(f32x2 v) { return boolx2(isinf_f32(v.x), isinf_f32(v.y)); }
static inline boolx2 isinf_f64x2(f64x2 v) { return boolx2(isinf_f64(v.x), isinf_f64(v.y)); }
static inline boolx3 isinf_f16x3(f16x3 v) { return boolx3(isinf_f16(v.x), isinf_f16(v.y), isinf_f16(v.z)); }
static inline boolx3 isinf_f32x3(f32x3 v) { return boolx3(isinf_f32(v.x), isinf_f32(v.y), isinf_f32(v.z)); }
static inline boolx3 isinf_f64x3(f64x3 v) { return boolx3(isinf_f64(v.x), isinf_f64(v.y), isinf_f64(v.z)); }
static inline boolx4 isinf_f16x4(f16x4 v) { return boolx4(isinf_f16(v.x), isinf_f16(v.y), isinf_f16(v.z), isinf_f16(v.w)); }
static inline boolx4 isinf_f32x4(f32x4 v) { return boolx4(isinf_f32(v.x), isinf_f32(v.y), isinf_f32(v.z), isinf_f32(v.w)); }
static inline boolx4 isinf_f64x4(f64x4 v) { return boolx4(isinf_f64(v.x), isinf_f64(v.y), isinf_f64(v.z), isinf_f64(v.w)); }

//
// return a vector where each component is the result of appling 'isnan' to that component in 'v'
static inline boolx2 isnan_f16x2(f16x2 v) { return boolx2(isnan_f16(v.x), isnan_f16(v.y)); }
static inline boolx2 isnan_f32x2(f32x2 v) { return boolx2(isnan_f32(v.x), isnan_f32(v.y)); }
static inline boolx2 isnan_f64x2(f64x2 v) { return boolx2(isnan_f64(v.x), isnan_f64(v.y)); }
static inline boolx3 isnan_f16x3(f16x3 v) { return boolx3(isnan_f16(v.x), isnan_f16(v.y), isnan_f16(v.z)); }
static inline boolx3 isnan_f32x3(f32x3 v) { return boolx3(isnan_f32(v.x), isnan_f32(v.y), isnan_f32(v.z)); }
static inline boolx3 isnan_f64x3(f64x3 v) { return boolx3(isnan_f64(v.x), isnan_f64(v.y), isnan_f64(v.z)); }
static inline boolx4 isnan_f16x4(f16x4 v) { return boolx4(isnan_f16(v.x), isnan_f16(v.y), isnan_f16(v.z), isnan_f16(v.w)); }
static inline boolx4 isnan_f32x4(f32x4 v) { return boolx4(isnan_f32(v.x), isnan_f32(v.y), isnan_f32(v.z), isnan_f32(v.w)); }
static inline boolx4 isnan_f64x4(f64x4 v) { return boolx4(isnan_f64(v.x), isnan_f64(v.y), isnan_f64(v.z), isnan_f64(v.w)); }

//
// return a vector where each component is the result of appling 'lerp' to that component in 'start', 'end' and 't'
static inline f16x2 lerp_f16x2(f16x2 start, f16x2 end, f16x2 t) { return f16x2(lerp_f16(start.x, end.x, t.x), lerp_f16(start.y, end.y, t.y)); }
static inline f32x2 lerp_f32x2(f32x2 start, f32x2 end, f32x2 t) { return f32x2(lerp_f32(start.x, end.x, t.x), lerp_f32(start.y, end.y, t.y)); }
static inline f64x2 lerp_f64x2(f64x2 start, f64x2 end, f64x2 t) { return f64x2(lerp_f64(start.x, end.x, t.x), lerp_f64(start.y, end.y, t.y)); }
static inline f16x3 lerp_f16x3(f16x3 start, f16x3 end, f16x3 t) { return f16x3(lerp_f16(start.x, end.x, t.x), lerp_f16(start.y, end.y, t.y), lerp_f16(start.z, end.z, t.z)); }
static inline f32x3 lerp_f32x3(f32x3 start, f32x3 end, f32x3 t) { return f32x3(lerp_f32(start.x, end.x, t.x), lerp_f32(start.y, end.y, t.y), lerp_f32(start.z, end.z, t.z)); }
static inline f64x3 lerp_f64x3(f64x3 start, f64x3 end, f64x3 t) { return f64x3(lerp_f64(start.x, end.x, t.x), lerp_f64(start.y, end.y, t.y), lerp_f64(start.z, end.z, t.z)); }
static inline f16x4 lerp_f16x4(f16x4 start, f16x4 end, f16x4 t) { return f16x4(lerp_f16(start.x, end.x, t.x), lerp_f16(start.y, end.y, t.y), lerp_f16(start.z, end.z, t.z), lerp_f16(start.w, end.w, t.w)); }
static inline f32x4 lerp_f32x4(f32x4 start, f32x4 end, f32x4 t) { return f32x4(lerp_f32(start.x, end.x, t.x), lerp_f32(start.y, end.y, t.y), lerp_f32(start.z, end.z, t.z), lerp_f32(start.w, end.w, t.w)); }
static inline f64x4 lerp_f64x4(f64x4 start, f64x4 end, f64x4 t) { return f64x4(lerp_f64(start.x, end.x, t.x), lerp_f64(start.y, end.y, t.y), lerp_f64(start.z, end.z, t.z), lerp_f64(start.w, end.w, t.w)); }

//
// return a vector where each component is the result of appling 'lerp' to that component in 'start', 'end' and scalar 't'
static inline f16x2 lerps_f16x2(f16x2 start, f16x2 end, half t) { f16x2 vt = f16x2s(t); return lerp_f16x2(start, end, vt); }
static inline f32x2 lerps_f32x2(f32x2 start, f32x2 end, float t) { f32x2 vt = f32x2s(t); return lerp_f32x2(start, end, vt); }
static inline f64x2 lerps_f64x2(f64x2 start, f64x2 end, double t) { f64x2 vt = f64x2s(t); return lerp_f64x2(start, end, vt); }
static inline f16x3 lerps_f16x3(f16x3 start, f16x3 end, half t) { f16x3 vt = f16x3s(t); return lerp_f16x3(start, end, vt); }
static inline f32x3 lerps_f32x3(f32x3 start, f32x3 end, float t) { f32x3 vt = f32x3s(t); return lerp_f32x3(start, end, vt); }
static inline f64x3 lerps_f64x3(f64x3 start, f64x3 end, double t) { f64x3 vt = f64x3s(t); return lerp_f64x3(start, end, vt); }
static inline f16x4 lerps_f16x4(f16x4 start, f16x4 end, half t) { f16x4 vt = f16x4s(t); return lerp_f16x4(start, end, vt); }
static inline f32x4 lerps_f32x4(f32x4 start, f32x4 end, float t) { f32x4 vt = f32x4s(t); return lerp_f32x4(start, end, vt); }
static inline f64x4 lerps_f64x4(f64x4 start, f64x4 end, double t) { f64x4 vt = f64x4s(t); return lerp_f64x4(start, end, vt); }

//
// return a vector where each component is the result of appling 'invlerp' to that component in 'start', 'end' and 't'
static inline f16x2 invlerp_f16x2(f16x2 start, f16x2 end, f16x2 v) { return f16x2(invlerp_f16(start.x, end.x, v.x), invlerp_f16(start.y, end.y, v.y)); }
static inline f32x2 invlerp_f32x2(f32x2 start, f32x2 end, f32x2 v) { return f32x2(invlerp_f32(start.x, end.x, v.x), invlerp_f32(start.y, end.y, v.y)); }
static inline f64x2 invlerp_f64x2(f64x2 start, f64x2 end, f64x2 v) { return f64x2(invlerp_f64(start.x, end.x, v.x), invlerp_f64(start.y, end.y, v.y)); }
static inline f16x3 invlerp_f16x3(f16x3 start, f16x3 end, f16x3 v) { return f16x3(invlerp_f16(start.x, end.x, v.x), invlerp_f16(start.y, end.y, v.y), invlerp_f16(start.z, end.z, v.z)); }
static inline f32x3 invlerp_f32x3(f32x3 start, f32x3 end, f32x3 v) { return f32x3(invlerp_f32(start.x, end.x, v.x), invlerp_f32(start.y, end.y, v.y), invlerp_f32(start.z, end.z, v.z)); }
static inline f64x3 invlerp_f64x3(f64x3 start, f64x3 end, f64x3 v) { return f64x3(invlerp_f64(start.x, end.x, v.x), invlerp_f64(start.y, end.y, v.y), invlerp_f64(start.z, end.z, v.z)); }
static inline f16x4 invlerp_f16x4(f16x4 start, f16x4 end, f16x4 v) { return f16x4(invlerp_f16(start.x, end.x, v.x), invlerp_f16(start.y, end.y, v.y), invlerp_f16(start.z, end.z, v.z), invlerp_f16(start.w, end.w, v.w)); }
static inline f32x4 invlerp_f32x4(f32x4 start, f32x4 end, f32x4 v) { return f32x4(invlerp_f32(start.x, end.x, v.x), invlerp_f32(start.y, end.y, v.y), invlerp_f32(start.z, end.z, v.z), invlerp_f32(start.w, end.w, v.w)); }
static inline f64x4 invlerp_f64x4(f64x4 start, f64x4 end, f64x4 v) { return f64x4(invlerp_f64(start.x, end.x, v.x), invlerp_f64(start.y, end.y, v.y), invlerp_f64(start.z, end.z, v.z), invlerp_f64(start.w, end.w, v.w)); }

//
// return a vector where each component is the result of appling 'lerp' to that component in 'start', 'end' and scalar 't'
static inline f16x2 invlerps_f16x2(f16x2 start, f16x2 end, half v) { f16x2 vt = f16x2s(v); return invlerp_f16x2(start, end, vt); }
static inline f32x2 invlerps_f32x2(f32x2 start, f32x2 end, float v) { f32x2 vt = f32x2s(v); return invlerp_f32x2(start, end, vt); }
static inline f64x2 invlerps_f64x2(f64x2 start, f64x2 end, double v) { f64x2 vt = f64x2s(v); return invlerp_f64x2(start, end, vt); }
static inline f16x3 invlerps_f16x3(f16x3 start, f16x3 end, half v) { f16x3 vt = f16x3s(v); return invlerp_f16x3(start, end, vt); }
static inline f32x3 invlerps_f32x3(f32x3 start, f32x3 end, float v) { f32x3 vt = f32x3s(v); return invlerp_f32x3(start, end, vt); }
static inline f64x3 invlerps_f64x3(f64x3 start, f64x3 end, double v) { f64x3 vt = f64x3s(v); return invlerp_f64x3(start, end, vt); }
static inline f16x4 invlerps_f16x4(f16x4 start, f16x4 end, half v) { f16x4 vt = f16x4s(v); return invlerp_f16x4(start, end, vt); }
static inline f32x4 invlerps_f32x4(f32x4 start, f32x4 end, float v) { f32x4 vt = f32x4s(v); return invlerp_f32x4(start, end, vt); }
static inline f64x4 invlerps_f64x4(f64x4 start, f64x4 end, double v) { f64x4 vt = f64x4s(v); return invlerp_f64x4(start, end, vt); }

//
// returns a vector which is the cross product of 'a' and 'b'
static inline half cross_f16x2(f16x2 a, f16x2 b) { return sub_f16(mul_f16(a.x, b.y), mul_f16(b.x, a.y)); }
static inline float cross_f32x2(f32x2 a, f32x2 b) { return (a.x * b.y) - (b.x * a.y); }
static inline double cross_f64x2(f64x2 a, f64x2 b) { return (a.x * b.y) - (b.x * a.y); }
static inline half cross_f16x3(f16x3 a, f16x3 b) { return add_f16(mul_f16(a.x, b.x), add_f16(mul_f16(a.y, b.y), mul_f16(a.z, b.z))); }
static inline f32x3 cross_f32x3(f32x3 a, f32x3 b) {
	return f32x3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}
static inline f64x3 cross_f64x3(f64x3 a, f64x3 b) {
	return f64x3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

//
// returns a vector which is the dot product of 'a' and 'b'
static inline half dot_f16x2(f16x2 a, f16x2 b) { return add_f16(mul_f16(a.x, b.x), mul_f16(a.y, b.y)); }
static inline float dot_f32x2(f32x2 a, f32x2 b) { return (a.x * b.x) + (a.y * b.y); }
static inline double dot_f64x2(f64x2 a, f64x2 b) { return (a.x * b.x) + (a.y * b.y); }
static inline half dot_f16x3(f16x3 a, f16x3 b) { return add_f16(mul_f16(a.x, b.x), add_f16(mul_f16(a.y, b.y), mul_f16(a.z, b.z))); }
static inline float dot_f32x3(f32x3 a, f32x3 b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
static inline double dot_f64x3(f64x3 a, f64x3 b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
static inline half dot_f16x4(f16x4 a, f16x4 b) { return add_f16(mul_f16(a.x, b.x), add_f16(mul_f16(a.y, b.y), add_f16(mul_f16(a.z, b.z), mul_f16(a.w, b.w)))); }
static inline float dot_f32x4(f32x4 a, f32x4 b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w); }
static inline double dot_f64x4(f64x4 a, f64x4 b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w); }

//
// returns a euclidean length of the vector 'v' aka. L2 norm
static inline half len_f16x2(f16x2 v) { return sqrt_f16(add_f16(mul_f16(v.x, v.x), mul_f16(v.y, v.y))); }
static inline float len_f32x2(f32x2 v) { return sqrt_f32((v.x * v.x) + (v.y * v.y)); }
static inline double len_f64x2(f64x2 v) { return sqrt_f64((v.x * v.x) + (v.y * v.y)); }
static inline half len_f16x3(f16x3 v) { return sqrt_f16(add_f16(mul_f16(v.x, v.x), add_f16(mul_f16(v.y, v.y), mul_f16(v.z, v.z)))); }
static inline float len_f32x3(f32x3 v) { return sqrt_f32((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }
static inline double len_f64x3(f64x3 v) { return sqrt_f64((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }
static inline half len_f16x4(f16x4 v) { return sqrt_f16(add_f16(mul_f16(v.x, v.x), add_f16(mul_f16(v.y, v.y), add_f16(mul_f16(v.z, v.z), mul_f16(v.w, v.w))))); }
static inline float len_f32x4(f32x4 v) { return sqrt_f32((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)); }
static inline double len_f64x4(f64x4 v) { return sqrt_f64((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)); }

//
// returns the squared euclidean length of the vector 'v', this avoids doing the square root. useful when you want to compare of one length is less than another vector length without paying the cost of a sqrt instruction
static inline half lensq_f16x2(f16x2 v) { return dot_f16x2(v, v); }
static inline float lensq_f32x2(f32x2 v) { return dot_f32x2(v, v); }
static inline double lensq_f64x2(f64x2 v) { return dot_f64x2(v, v); }
static inline int8_t lensq_s8x2(s8x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline int16_t lensq_s16x2(s16x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline int32_t lensq_s32x2(s32x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline int64_t lensq_s64x2(s64x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline uint8_t lensq_u8x2(u8x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline uint16_t lensq_u16x2(u16x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline uint32_t lensq_u32x2(u32x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline uint64_t lensq_u64x2(u64x2 v) { return (v.x * v.x) + (v.y * v.y); }
static inline half lensq_f16x3(f16x3 v) { return dot_f16x3(v, v); }
static inline float lensq_f32x3(f32x3 v) { return dot_f32x3(v, v); }
static inline double lensq_f64x3(f64x3 v) { return dot_f64x3(v, v); }
static inline int8_t lensq_s8x3(s8x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline int16_t lensq_s16x3(s16x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline int32_t lensq_s32x3(s32x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline int64_t lensq_s64x3(s64x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline uint8_t lensq_u8x3(u8x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline uint16_t lensq_u16x3(u16x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline uint32_t lensq_u32x3(u32x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline uint64_t lensq_u64x3(u64x3 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
static inline half lensq_f16x4(f16x4 v) { return dot_f16x4(v, v); }
static inline float lensq_f32x4(f32x4 v) { return dot_f32x4(v, v); }
static inline double lensq_f64x4(f64x4 v) { return dot_f64x4(v, v); }
static inline int8_t lensq_s8x4(s8x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline int16_t lensq_s16x4(s16x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline int32_t lensq_s32x4(s32x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline int64_t lensq_s64x4(s64x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline uint8_t lensq_u8x4(u8x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline uint16_t lensq_u16x4(u16x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline uint32_t lensq_u32x4(u32x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
static inline uint64_t lensq_u64x4(u64x4 v) { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }

//
// returns a version of 'v' where the magnatude is a unit length of 1.f
static inline f16x2 norm_f16x2(f16x2 v) { half k = rsqrt_f16(add_f16(mul_f16(v.x, v.x), mul_f16(v.y, v.y))); return f16x2(mul_f16(v.x, k), mul_f16(v.y, k)); }
static inline f32x2 norm_f32x2(f32x2 v) { float k = rsqrt_f32((v.x * v.x) + (v.y * v.y)); return f32x2(v.x * k, v.y * k); }
static inline f64x2 norm_f64x2(f64x2 v) { double k = rsqrt_f64((v.x * v.x) + (v.y * v.y)); return f64x2(v.x * k, v.y * k); }
static inline f16x3 norm_f16x3(f16x3 v) { half k = rsqrt_f16(add_f16(mul_f16(v.x, v.x), add_f16(mul_f16(v.y, v.y), mul_f16(v.z, v.z)))); return f16x3(mul_f16(v.x, k), mul_f16(v.y, k), mul_f16(v.z, k)); }
static inline f32x3 norm_f32x3(f32x3 v) { float k = rsqrt_f32((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); return f32x3(v.x * k, v.y * k, v.z * k); }
static inline f64x3 norm_f64x3(f64x3 v) { double k = rsqrt_f64((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); return f64x3(v.x * k, v.y * k, v.z * k); }
static inline f16x4 norm_f16x4(f16x4 v) { half k = rsqrt_f16(add_f16(mul_f16(v.x, v.x), add_f16(mul_f16(v.y, v.y), add_f16(mul_f16(v.z, v.z), mul_f16(v.w, v.w))))); return f16x4(mul_f16(v.x, k), mul_f16(v.y, k), mul_f16(v.z, k), mul_f16(v.w, k)); }
static inline f32x4 norm_f32x4(f32x4 v) { float k = rsqrt_f32((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)); return f32x4(v.x * k, v.y * k, v.z * k, v.w * k); }
static inline f64x4 norm_f64x4(f64x4 v) { double k = rsqrt_f64((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)); return f64x4(v.x * k, v.y * k, v.z * k, v.w * k); }

//
// returns a vector that is vector 'v' reflected against surface 'normal'
f16x2 reflect_f16x2(f16x2 v, f16x2 normal);
f32x2 reflect_f32x2(f32x2 v, f32x2 normal);
f64x2 reflect_f64x2(f64x2 v, f64x2 normal);
f16x3 reflect_f16x3(f16x3 v, f16x3 normal);
f32x3 reflect_f32x3(f32x3 v, f32x3 normal);
f64x3 reflect_f64x3(f64x3 v, f64x3 normal);
f16x4 reflect_f16x4(f16x4 v, f16x4 normal);
f32x4 reflect_f32x4(f32x4 v, f32x4 normal);
f64x4 reflect_f64x4(f64x4 v, f64x4 normal);

//
// returns the refraction vector for vector 'v' against surface 'normal' with the ratio 'eta'
f16x2 refract_f16x2(f16x2 v, f16x2 normal, half eta);
f32x2 refract_f32x2(f32x2 v, f32x2 normal, float eta);
f64x2 refract_f64x2(f64x2 v, f64x2 normal, double eta);
f16x3 refract_f16x3(f16x3 v, f16x3 normal, half eta);
f32x3 refract_f32x3(f32x3 v, f32x3 normal, float eta);
f64x3 refract_f64x3(f64x3 v, f64x3 normal, double eta);
f16x4 refract_f16x4(f16x4 v, f16x4 normal, half eta);
f32x4 refract_f32x4(f32x4 v, f32x4 normal, float eta);
f64x4 refract_f64x4(f64x4 v, f64x4 normal, double eta);

//
// returns the minimum value from each of the components in 'v'
static inline half minelmt_f16x2(f16x2 v) { return min_f16(v.x, v.y); }
static inline float minelmt_f32x2(f32x2 v) { return min_f32(v.x, v.y); }
static inline double minelmt_f64x2(f64x2 v) { return min_f64(v.x, v.y); }
static inline int8_t minelmt_s8x2(s8x2 v) { return min_s8(v.x, v.y); }
static inline int16_t minelmt_s16x2(s16x2 v) { return min_s16(v.x, v.y); }
static inline int32_t minelmt_s32x2(s32x2 v) { return min_s32(v.x, v.y); }
static inline int64_t minelmt_s64x2(s64x2 v) { return min_s64(v.x, v.y); }
static inline uint8_t minelmt_u8x2(u8x2 v) { return min_u8(v.x, v.y); }
static inline uint16_t minelmt_u16x2(u16x2 v) { return min_u16(v.x, v.y); }
static inline uint32_t minelmt_u32x2(u32x2 v) { return min_u32(v.x, v.y); }
static inline uint64_t minelmt_u64x2(u64x2 v) { return min_u64(v.x, v.y); }
static inline half minelmt_f16x3(f16x3 v) { return min_f16(v.x, min_f16(v.y, v.z)); }
static inline float minelmt_f32x3(f32x3 v) { return min_f32(v.x, min_f32(v.y, v.z)); }
static inline double minelmt_f64x3(f64x3 v) { return min_f64(v.x, min_f64(v.y, v.z)); }
static inline int8_t minelmt_s8x3(s8x3 v) { return min_s8(v.x, min_s8(v.y, v.z)); }
static inline int16_t minelmt_s16x3(s16x3 v) { return min_s16(v.x, min_s16(v.y, v.z)); }
static inline int32_t minelmt_s32x3(s32x3 v) { return min_s32(v.x, min_s32(v.y, v.z)); }
static inline int64_t minelmt_s64x3(s64x3 v) { return min_s64(v.x, min_s64(v.y, v.z)); }
static inline uint8_t minelmt_u8x3(u8x3 v) { return min_u8(v.x, min_u8(v.y, v.z)); }
static inline uint16_t minelmt_u16x3(u16x3 v) { return min_u16(v.x, min_u16(v.y, v.z)); }
static inline uint32_t minelmt_u32x3(u32x3 v) { return min_u32(v.x, min_u32(v.y, v.z)); }
static inline uint64_t minelmt_u64x3(u64x3 v) { return min_u64(v.x, min_u64(v.y, v.z)); }
static inline half minelmt_f16x4(f16x4 v) { return min_f16(v.x, min_f16(v.y, min_f16(v.z, v.w))); }
static inline float minelmt_f32x4(f32x4 v) { return min_f32(v.x, min_f32(v.y, min_f32(v.z, v.w))); }
static inline double minelmt_f64x4(f64x4 v) { return min_f64(v.x, min_f64(v.y, min_f64(v.z, v.w))); }
static inline int8_t minelmt_s8x4(s8x4 v) { return min_s8(v.x, min_s8(v.y, min_s8(v.z, v.w))); }
static inline int16_t minelmt_s16x4(s16x4 v) { return min_s16(v.x, min_s16(v.y, min_s16(v.z, v.w))); }
static inline int32_t minelmt_s32x4(s32x4 v) { return min_s32(v.x, min_s32(v.y, min_s32(v.z, v.w))); }
static inline int64_t minelmt_s64x4(s64x4 v) { return min_s64(v.x, min_s64(v.y, min_s64(v.z, v.w))); }
static inline uint8_t minelmt_u8x4(u8x4 v) { return min_u8(v.x, min_u8(v.y, min_u8(v.z, v.w))); }
static inline uint16_t minelmt_u16x4(u16x4 v) { return min_u16(v.x, min_u16(v.y, min_u16(v.z, v.w))); }
static inline uint32_t minelmt_u32x4(u32x4 v) { return min_u32(v.x, min_u32(v.y, min_u32(v.z, v.w))); }
static inline uint64_t minelmt_u64x4(u64x4 v) { return min_u64(v.x, min_u64(v.y, min_u64(v.z, v.w))); }

//
// returns the maximum value from each of the components in 'v' aka. L infinity norm
static inline half maxelmt_f16x2(f16x2 v) { return max_f16(v.x, v.y); }
static inline float maxelmt_f32x2(f32x2 v) { return max_f32(v.x, v.y); }
static inline double maxelmt_f64x2(f64x2 v) { return max_f64(v.x, v.y); }
static inline int8_t maxelmt_s8x2(s8x2 v) { return max_s8(v.x, v.y); }
static inline int16_t maxelmt_s16x2(s16x2 v) { return max_s16(v.x, v.y); }
static inline int32_t maxelmt_s32x2(s32x2 v) { return max_s32(v.x, v.y); }
static inline int64_t maxelmt_s64x2(s64x2 v) { return max_s64(v.x, v.y); }
static inline uint8_t maxelmt_u8x2(u8x2 v) { return max_u8(v.x, v.y); }
static inline uint16_t maxelmt_u16x2(u16x2 v) { return max_u16(v.x, v.y); }
static inline uint32_t maxelmt_u32x2(u32x2 v) { return max_u32(v.x, v.y); }
static inline uint64_t maxelmt_u64x2(u64x2 v) { return max_u64(v.x, v.y); }
static inline half maxelmt_f16x3(f16x3 v) { return max_f16(v.x, max_f16(v.y, v.z)); }
static inline float maxelmt_f32x3(f32x3 v) { return max_f32(v.x, max_f32(v.y, v.z)); }
static inline double maxelmt_f64x3(f64x3 v) { return max_f64(v.x, max_f64(v.y, v.z)); }
static inline int8_t maxelmt_s8x3(s8x3 v) { return max_s8(v.x, max_s8(v.y, v.z)); }
static inline int16_t maxelmt_s16x3(s16x3 v) { return max_s16(v.x, max_s16(v.y, v.z)); }
static inline int32_t maxelmt_s32x3(s32x3 v) { return max_s32(v.x, max_s32(v.y, v.z)); }
static inline int64_t maxelmt_s64x3(s64x3 v) { return max_s64(v.x, max_s64(v.y, v.z)); }
static inline uint8_t maxelmt_u8x3(u8x3 v) { return max_u8(v.x, max_u8(v.y, v.z)); }
static inline uint16_t maxelmt_u16x3(u16x3 v) { return max_u16(v.x, max_u16(v.y, v.z)); }
static inline uint32_t maxelmt_u32x3(u32x3 v) { return max_u32(v.x, max_u32(v.y, v.z)); }
static inline uint64_t maxelmt_u64x3(u64x3 v) { return max_u64(v.x, max_u64(v.y, v.z)); }
static inline half maxelmt_f16x4(f16x4 v) { return max_f16(v.x, max_f16(v.y, max_f16(v.z, v.w))); }
static inline float maxelmt_f32x4(f32x4 v) { return max_f32(v.x, max_f32(v.y, max_f32(v.z, v.w))); }
static inline double maxelmt_f64x4(f64x4 v) { return max_f64(v.x, max_f64(v.y, max_f64(v.z, v.w))); }
static inline int8_t maxelmt_s8x4(s8x4 v) { return max_s8(v.x, max_s8(v.y, max_s8(v.z, v.w))); }
static inline int16_t maxelmt_s16x4(s16x4 v) { return max_s16(v.x, max_s16(v.y, max_s16(v.z, v.w))); }
static inline int32_t maxelmt_s32x4(s32x4 v) { return max_s32(v.x, max_s32(v.y, max_s32(v.z, v.w))); }
static inline int64_t maxelmt_s64x4(s64x4 v) { return max_s64(v.x, max_s64(v.y, max_s64(v.z, v.w))); }
static inline uint8_t maxelmt_u8x4(u8x4 v) { return max_u8(v.x, max_u8(v.y, max_u8(v.z, v.w))); }
static inline uint16_t maxelmt_u16x4(u16x4 v) { return max_u16(v.x, max_u16(v.y, max_u16(v.z, v.w))); }
static inline uint32_t maxelmt_u32x4(u32x4 v) { return max_u32(v.x, max_u32(v.y, max_u32(v.z, v.w))); }
static inline uint64_t maxelmt_u64x4(u64x4 v) { return max_u64(v.x, max_u64(v.y, max_u64(v.z, v.w))); }

//
// returns the sum of all of the components in 'v'
static inline half sumelmts_f16x2(f16x2 v) { return add_f16(v.x, v.y); }
static inline float sumelmts_f32x2(f32x2 v) { return v.x + v.y; }
static inline double sumelmts_f64x2(f64x2 v) { return v.x + v.y; }
static inline int8_t sumelmts_s8x2(s8x2 v) { return v.x + v.y; }
static inline int16_t sumelmts_s16x2(s16x2 v) { return v.x + v.y; }
static inline int32_t sumelmts_s32x2(s32x2 v) { return v.x + v.y; }
static inline int64_t sumelmts_s64x2(s64x2 v) { return v.x + v.y; }
static inline uint8_t sumelmts_u8x2(u8x2 v) { return v.x + v.y; }
static inline uint16_t sumelmts_u16x2(u16x2 v) { return v.x + v.y; }
static inline uint32_t sumelmts_u32x2(u32x2 v) { return v.x + v.y; }
static inline uint64_t sumelmts_u64x2(u64x2 v) { return v.x + v.y; }
static inline half sumelmts_f16x3(f16x3 v) { return add_f16(v.x, add_f16(v.y, v.z)); }
static inline float sumelmts_f32x3(f32x3 v) { return v.x + v.y + v.z; }
static inline double sumelmts_f64x3(f64x3 v) { return v.x + v.y + v.z; }
static inline int8_t sumelmts_s8x3(s8x3 v) { return v.x + v.y + v.z; }
static inline int16_t sumelmts_s16x3(s16x3 v) { return v.x + v.y + v.z; }
static inline int32_t sumelmts_s32x3(s32x3 v) { return v.x + v.y + v.z; }
static inline int64_t sumelmts_s64x3(s64x3 v) { return v.x + v.y + v.z; }
static inline uint8_t sumelmts_u8x3(u8x3 v) { return v.x + v.y + v.z; }
static inline uint16_t sumelmts_u16x3(u16x3 v) { return v.x + v.y + v.z; }
static inline uint32_t sumelmts_u32x3(u32x3 v) { return v.x + v.y + v.z; }
static inline uint64_t sumelmts_u64x3(u64x3 v) { return v.x + v.y + v.z; }
static inline half sumelmts_f16x4(f16x4 v) { return add_f16(v.x, add_f16(v.y, add_f16(v.z, v.w))); }
static inline float sumelmts_f32x4(f32x4 v) { return v.x + v.y + v.z + v.w; }
static inline double sumelmts_f64x4(f64x4 v) { return v.x + v.y + v.z + v.w; }
static inline int8_t sumelmts_s8x4(s8x4 v) { return v.x + v.y + v.z + v.w; }
static inline int16_t sumelmts_s16x4(s16x4 v) { return v.x + v.y + v.z + v.w; }
static inline int32_t sumelmts_s32x4(s32x4 v) { return v.x + v.y + v.z + v.w; }
static inline int64_t sumelmts_s64x4(s64x4 v) { return v.x + v.y + v.z + v.w; }
static inline uint8_t sumelmts_u8x4(u8x4 v) { return v.x + v.y + v.z + v.w; }
static inline uint16_t sumelmts_u16x4(u16x4 v) { return v.x + v.y + v.z + v.w; }
static inline uint32_t sumelmts_u32x4(u32x4 v) { return v.x + v.y + v.z + v.w; }
static inline uint64_t sumelmts_u64x4(u64x4 v) { return v.x + v.y + v.z + v.w; }

//
// returns the product of all of the components in 'v'
static inline half productelmts_f16x2(f16x2 v) { return mul_f16(v.x, v.y); }
static inline float productelmts_f32x2(f32x2 v) { return v.x * v.y; }
static inline double productelmts_f64x2(f64x2 v) { return v.x * v.y; }
static inline int8_t productelmts_s8x2(s8x2 v) { return v.x * v.y; }
static inline int16_t productelmts_s16x2(s16x2 v) { return v.x * v.y; }
static inline int32_t productelmts_s32x2(s32x2 v) { return v.x * v.y; }
static inline int64_t productelmts_s64x2(s64x2 v) { return v.x * v.y; }
static inline uint8_t productelmts_u8x2(u8x2 v) { return v.x * v.y; }
static inline uint16_t productelmts_u16x2(u16x2 v) { return v.x * v.y; }
static inline uint32_t productelmts_u32x2(u32x2 v) { return v.x * v.y; }
static inline uint64_t productelmts_u64x2(u64x2 v) { return v.x * v.y; }
static inline half productelmts_f16x3(f16x3 v) { return mul_f16(v.x, mul_f16(v.y, v.z)); }
static inline float productelmts_f32x3(f32x3 v) { return v.x * v.y * v.z; }
static inline double productelmts_f64x3(f64x3 v) { return v.x * v.y * v.z; }
static inline int8_t productelmts_s8x3(s8x3 v) { return v.x * v.y * v.z; }
static inline int16_t productelmts_s16x3(s16x3 v) { return v.x * v.y * v.z; }
static inline int32_t productelmts_s32x3(s32x3 v) { return v.x * v.y * v.z; }
static inline int64_t productelmts_s64x3(s64x3 v) { return v.x * v.y * v.z; }
static inline uint8_t productelmts_u8x3(u8x3 v) { return v.x * v.y * v.z; }
static inline uint16_t productelmts_u16x3(u16x3 v) { return v.x * v.y * v.z; }
static inline uint32_t productelmts_u32x3(u32x3 v) { return v.x * v.y * v.z; }
static inline uint64_t productelmts_u64x3(u64x3 v) { return v.x * v.y * v.z; }
static inline half productelmts_f16x4(f16x4 v) { return mul_f16(v.x, mul_f16(v.y, mul_f16(v.z, v.w))); }
static inline float productelmts_f32x4(f32x4 v) { return v.x * v.y * v.z * v.w; }
static inline double productelmts_f64x4(f64x4 v) { return v.x * v.y * v.z * v.w; }
static inline int8_t productelmts_s8x4(s8x4 v) { return v.x * v.y * v.z * v.w; }
static inline int16_t productelmts_s16x4(s16x4 v) { return v.x * v.y * v.z * v.w; }
static inline int32_t productelmts_s32x4(s32x4 v) { return v.x * v.y * v.z * v.w; }
static inline int64_t productelmts_s64x4(s64x4 v) { return v.x * v.y * v.z * v.w; }
static inline uint8_t productelmts_u8x4(u8x4 v) { return v.x * v.y * v.z * v.w; }
static inline uint16_t productelmts_u16x4(u16x4 v) { return v.x * v.y * v.z * v.w; }
static inline uint32_t productelmts_u32x4(u32x4 v) { return v.x * v.y * v.z * v.w; }
static inline uint64_t productelmts_u64x4(u64x4 v) { return v.x * v.y * v.z * v.w; }

//
// returns a vector where each component is the square of itself
static inline f16x2 square_f16x2(f16x2 v) { return f16x2(mul_f16(v.x, v.x), mul_f16(v.y, v.y)); }
static inline f32x2 square_f32x2(f32x2 v) { return f32x2(v.x * v.x, v.y * v.y); }
static inline f64x2 square_f64x2(f64x2 v) { return f64x2(v.x * v.x, v.y * v.y); }
static inline s8x2 square_s8x2(s8x2 v) { return s8x2(v.x * v.x, v.y * v.y); }
static inline s16x2 square_s16x2(s16x2 v) { return s16x2(v.x * v.x, v.y * v.y); }
static inline s32x2 square_s32x2(s32x2 v) { return s32x2(v.x * v.x, v.y * v.y); }
static inline s64x2 square_s64x2(s64x2 v) { return s64x2(v.x * v.x, v.y * v.y); }
static inline u8x2 square_u8x2(u8x2 v) { return u8x2(v.x * v.x, v.y * v.y); }
static inline u16x2 square_u16x2(u16x2 v) { return u16x2(v.x * v.x, v.y * v.y); }
static inline u32x2 square_u32x2(u32x2 v) { return u32x2(v.x * v.x, v.y * v.y); }
static inline u64x2 square_u64x2(u64x2 v) { return u64x2(v.x * v.x, v.y * v.y); }
static inline f16x3 square_f16x3(f16x3 v) { return f16x3(mul_f16(v.x, v.x), mul_f16(v.y, v.y), mul_f16(v.z, v.z)); }
static inline f32x3 square_f32x3(f32x3 v) { return f32x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline f64x3 square_f64x3(f64x3 v) { return f64x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline s8x3 square_s8x3(s8x3 v) { return s8x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline s16x3 square_s16x3(s16x3 v) { return s16x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline s32x3 square_s32x3(s32x3 v) { return s32x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline s64x3 square_s64x3(s64x3 v) { return s64x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline u8x3 square_u8x3(u8x3 v) { return u8x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline u16x3 square_u16x3(u16x3 v) { return u16x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline u32x3 square_u32x3(u32x3 v) { return u32x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline u64x3 square_u64x3(u64x3 v) { return u64x3(v.x * v.x, v.y * v.y, v.z * v.z); }
static inline f16x4 square_f16x4(f16x4 v) { return f16x4(mul_f16(v.x, v.x), mul_f16(v.y, v.y), mul_f16(v.z, v.z), mul_f16(v.w, v.w)); }
static inline f32x4 square_f32x4(f32x4 v) { return f32x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline f64x4 square_f64x4(f64x4 v) { return f64x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline s8x4 square_s8x4(s8x4 v) { return s8x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline s16x4 square_s16x4(s16x4 v) { return s16x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline s32x4 square_s32x4(s32x4 v) { return s32x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline s64x4 square_s64x4(s64x4 v) { return s64x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline u8x4 square_u8x4(u8x4 v) { return u8x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline u16x4 square_u16x4(u16x4 v) { return u16x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline u32x4 square_u32x4(u32x4 v) { return u32x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }
static inline u64x4 square_u64x4(u64x4 v) { return u64x4(v.x * v.x, v.y * v.y, v.z * v.z, v.w * v.w); }

//
// packs a f32x2 into a 32 bit integer comprised of two float 16 bits
uint32_t pack_f16x2_f32x2(f32x2 v);

//
// unpacks a f32x2 from a 32 bit integer comprised of two float 16 bits
f32x2 unpack_f16x2_f32x2(uint32_t v);

//
// packs a unsigned normalized f32x2 into a 32 bit integer where each component is given 16 bits
uint32_t pack_u16x2_f32x2(f32x2 v);

//
// unpacks a unsigned normalized f32x2 from a 32 bit integer where each component is given 16 bits
f32x2 unpack_u16x2_f32x2(uint32_t v);

//
// packs a signed normalized f32x2 into a 32 bit integer where each component is given 16 bits
uint32_t pack_s16x2_f32x2(f32x2 v);

//
// unpacks a signed normalized f32x2 from a 32 bit integer where each component is given 16 bits
f32x2 unpack_s16x2_f32x2(uint32_t v);

//
// packs a unsigned normalized f32x4 into a 32 bit integer where each component is given 8 bits
uint32_t pack_u8x4_f32x4(f32x4 v);

//
// unpacks a unsigned normalized f32x4 from a 32 bit integer where each component is given 8 bits
f32x4 unpack_u8x4_f32x4(uint32_t v);

//
// packs a signed normalized f32x4 into a 32 bit integer where each component is given 8 bits
uint32_t pack_s8x4_f32x4(f32x4 v);

//
// unpacks a signed normalized f32x4 from a 32 bit integer where each component is given 8 bits
f32x4 unpack_s8x4_f32x4(uint32_t v);

#endif // _HMATHS_VECTOR_H_
