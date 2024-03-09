#ifndef _HMATHS_SCALAR_H_
#define _HMATHS_SCALAR_H_

#include "hmaths_types.h"

// ===========================================
//
//
// Half type aka. float 16 bit
//
//
// ===========================================

float f16tof32(half v);
double f16tof64(half v);
half f32tof16(float v);
half f64tof16(double v);

// ===========================================
//
//
// Scalar
//
//
// ===========================================

static inline half add_f16(half a, half b) { return f32tof16(f16tof32(a) + f16tof32(b)); }
static inline float add_f32(float a, float b) { return a + b; }
static inline double add_f64(double a, double b) { return a + b; }
static inline int8_t add_s8(int8_t a, int8_t b) { return a + b; }
static inline int16_t add_s16(int16_t a, int16_t b) { return a + b; }
static inline int32_t add_s32(int32_t a, int32_t b) { return a + b; }
static inline int64_t add_s64(int64_t a, int64_t b) { return a + b; }
static inline uint8_t add_u8(uint8_t a, int8_t b) { return a + b; }
static inline uint16_t add_u16(uint16_t a, int16_t b) { return a + b; }
static inline uint32_t add_u32(uint32_t a, int32_t b) { return a + b; }
static inline uint64_t add_u64(uint64_t a, int64_t b) { return a + b; }

static inline half sub_f16(half a, half b) { return f32tof16(f16tof32(a) - f16tof32(b)); }
static inline float sub_f32(float a, float b) { return a - b; }
static inline double sub_f64(double a, double b) { return a - b; }
static inline int8_t sub_s8(int8_t a, int8_t b) { return a - b; }
static inline int16_t sub_s16(int16_t a, int16_t b) { return a - b; }
static inline int32_t sub_s32(int32_t a, int32_t b) { return a - b; }
static inline int64_t sub_s64(int64_t a, int64_t b) { return a - b; }
static inline uint8_t sub_u8(uint8_t a, uint8_t b) { return a - b; }
static inline uint16_t sub_u16(uint16_t a, uint16_t b) { return a - b; }
static inline uint32_t sub_u32(uint32_t a, uint32_t b) { return a - b; }
static inline uint64_t sub_u64(uint64_t a, uint64_t b) { return a - b; }

static inline half mul_f16(half a, half b) { return f32tof16(f16tof32(a) * f16tof32(b)); }
static inline float mul_f32(float a, float b) { return a * b; }
static inline double mul_f64(double a, double b) { return a * b; }
static inline int8_t mul_s8(int8_t a, int8_t b) { return a * b; }
static inline int16_t mul_s16(int16_t a, int16_t b) { return a * b; }
static inline int32_t mul_s32(int32_t a, int32_t b) { return a * b; }
static inline int64_t mul_s64(int64_t a, int64_t b) { return a * b; }
static inline uint8_t mul_u8(uint8_t a, uint8_t b) { return a * b; }
static inline uint16_t mul_u16(uint16_t a, uint16_t b) { return a * b; }
static inline uint32_t mul_u32(uint32_t a, uint32_t b) { return a * b; }
static inline uint64_t mul_u64(uint64_t a, uint64_t b) { return a * b; }

static inline half div_f16(half a, half b) { return f32tof16(f16tof32(a) / f16tof32(b)); }
static inline float div_f32(float a, float b) { return a / b; }
static inline double div_f64(double a, double b) { return a / b; }
static inline int8_t div_s8(int8_t a, int8_t b) { return a / b; }
static inline int16_t div_s16(int16_t a, int16_t b) { return a / b; }
static inline int32_t div_s32(int32_t a, int32_t b) { return a / b; }
static inline int64_t div_s64(int64_t a, int64_t b) { return a / b; }
static inline uint8_t div_u8(uint8_t a, uint8_t b) { return a / b; }
static inline uint16_t div_u16(uint16_t a, uint16_t b) { return a / b; }
static inline uint32_t div_u32(uint32_t a, uint32_t b) { return a / b; }
static inline uint64_t div_u64(uint64_t a, uint64_t b) { return a / b; }

half mod_f16(half a, half b);
float mod_f32(float a, float b);
double mod_f64(double a, double b);
static inline int8_t mod_s8(int8_t a, int8_t b) { return a % b; }
static inline int16_t mod_s16(int16_t a, int16_t b) { return a % b; }
static inline int32_t mod_s32(int32_t a, int32_t b) { return a % b; }
static inline int64_t mod_s64(int64_t a, int64_t b) { return a % b; }
static inline uint8_t mod_u8(uint8_t a, uint8_t b) { return a % b; }
static inline uint16_t mod_u16(uint16_t a, uint16_t b) { return a % b; }
static inline uint32_t mod_u32(uint32_t a, uint32_t b) { return a % b; }
static inline uint64_t mod_u64(uint64_t a, uint64_t b) { return a % b; }

static inline bool eq_f16(half a, half b) { return f16tof32(a) == f16tof32(b); }
static inline bool eq_f32(float a, float b) { return a == b; }
static inline bool eq_f64(double a, double b) { return a == b; }
static inline bool eq_s8(int8_t a, int8_t b) { return a == b; }
static inline bool eq_s16(int16_t a, int16_t b) { return a == b; }
static inline bool eq_s32(int32_t a, int32_t b) { return a == b; }
static inline bool eq_s64(int64_t a, int64_t b) { return a == b; }
static inline bool eq_u8(uint8_t a, uint8_t b) { return a == b; }
static inline bool eq_u16(uint16_t a, uint16_t b) { return a == b; }
static inline bool eq_u32(uint32_t a, uint32_t b) { return a == b; }
static inline bool eq_u64(uint64_t a, uint64_t b) { return a == b; }

static inline bool neq_f16(half a, half b) { return f16tof32(a) != f16tof32(b); }
static inline bool neq_f32(float a, float b) { return a != b; }
static inline bool neq_f64(double a, double b) { return a != b; }
static inline bool neq_s8(int8_t a, int8_t b) { return a != b; }
static inline bool neq_s16(int16_t a, int16_t b) { return a != b; }
static inline bool neq_s32(int32_t a, int32_t b) { return a != b; }
static inline bool neq_s64(int64_t a, int64_t b) { return a != b; }
static inline bool neq_u8(uint8_t a, uint8_t b) { return a != b; }
static inline bool neq_u16(uint16_t a, uint16_t b) { return a != b; }
static inline bool neq_u32(uint32_t a, uint32_t b) { return a != b; }
static inline bool neq_u64(uint64_t a, uint64_t b) { return a != b; }

static inline bool lt_f16(half a, half b) { return f16tof32(a) < f16tof32(b); }
static inline bool lt_f32(float a, float b) { return a < b; }
static inline bool lt_f64(double a, double b) { return a < b; }
static inline bool lt_s8(int8_t a, int8_t b) { return a < b; }
static inline bool lt_s16(int16_t a, int16_t b) { return a < b; }
static inline bool lt_s32(int32_t a, int32_t b) { return a < b; }
static inline bool lt_s64(int64_t a, int64_t b) { return a < b; }
static inline bool lt_u8(uint8_t a, uint8_t b) { return a < b; }
static inline bool lt_u16(uint16_t a, uint16_t b) { return a < b; }
static inline bool lt_u32(uint32_t a, uint32_t b) { return a < b; }
static inline bool lt_u64(uint64_t a, uint64_t b) { return a < b; }

static inline bool lteq_f16(half a, half b) { return f16tof32(a) <= f16tof32(b); }
static inline bool lteq_f32(float a, float b) { return a <= b; }
static inline bool lteq_f64(double a, double b) { return a <= b; }
static inline bool lteq_s8(int8_t a, int8_t b) { return a <= b; }
static inline bool lteq_s16(int16_t a, int16_t b) { return a <= b; }
static inline bool lteq_s32(int32_t a, int32_t b) { return a <= b; }
static inline bool lteq_s64(int64_t a, int64_t b) { return a <= b; }
static inline bool lteq_u8(uint8_t a, uint8_t b) { return a <= b; }
static inline bool lteq_u16(uint16_t a, uint16_t b) { return a <= b; }
static inline bool lteq_u32(uint32_t a, uint32_t b) { return a <= b; }
static inline bool lteq_u64(uint64_t a, uint64_t b) { return a <= b; }

static inline bool gt_f16(half a, half b) { return f16tof32(a) > f16tof32(b); }
static inline bool gt_f32(float a, float b) { return a > b; }
static inline bool gt_f64(double a, double b) { return a > b; }
static inline bool gt_s8(int8_t a, int8_t b) { return a > b; }
static inline bool gt_s16(int16_t a, int16_t b) { return a > b; }
static inline bool gt_s32(int32_t a, int32_t b) { return a > b; }
static inline bool gt_s64(int64_t a, int64_t b) { return a > b; }
static inline bool gt_u8(uint8_t a, uint8_t b) { return a > b; }
static inline bool gt_u1u16(uint16_t a, uint16_t b) { return a > b; }
static inline bool gt_u32(uint32_t a, uint32_t b) { return a > b; }
static inline bool gt_u64(uint64_t a, uint64_t b) { return a > b; }

static inline bool gteq_f16(half a, half b) { return f16tof32(a) >= f16tof32(b); }
static inline bool gteq_f32(float a, float b) { return a >= b; }
static inline bool gteq_f64(double a, double b) { return a >= b; }
static inline bool gteq_s8(int8_t a, int8_t b) { return a >= b; }
static inline bool gteq_s16(int16_t a, int16_t b) { return a >= b; }
static inline bool gteq_s32(int32_t a, int32_t b) { return a >= b; }
static inline bool gteq_s64(int64_t a, int64_t b) { return a >= b; }
static inline bool gteq_u8(uint8_t a, uint8_t b) { return a >= b; }
static inline bool gteq_u16(uint16_t a, uint16_t b) { return a >= b; }
static inline bool gteq_u32(uint32_t a, uint32_t b) { return a >= b; }
static inline bool gteq_u64(uint64_t a, uint64_t b) { return a >= b; }

static inline bool bitand_s8(int8_t a, int8_t b) { return a & b; }
static inline bool bitand_s16(int16_t a, int16_t b) { return a & b; }
static inline bool bitand_s32(int32_t a, int32_t b) { return a & b; }
static inline bool bitand_s64(int64_t a, int64_t b) { return a & b; }
static inline bool bitand_u8(uint8_t a, uint8_t b) { return a & b; }
static inline bool bitand_u16(uint16_t a, uint16_t b) { return a & b; }
static inline bool bitand_u32(uint32_t a, uint32_t b) { return a & b; }
static inline bool bitand_u64(uint64_t a, uint64_t b) { return a & b; }

static inline bool bitor_s8(int8_t a, int8_t b) { return a | b; }
static inline bool bitor_s16(int16_t a, int16_t b) { return a | b; }
static inline bool bitor_s32(int32_t a, int32_t b) { return a | b; }
static inline bool bitor_s64(int64_t a, int64_t b) { return a | b; }
static inline bool bitor_u8(uint8_t a, uint8_t b) { return a | b; }
static inline bool bitor_u16(uint16_t a, uint16_t b) { return a | b; }
static inline bool bitor_u32(uint32_t a, uint32_t b) { return a | b; }
static inline bool bitor_u64(uint64_t a, uint64_t b) { return a | b; }

static inline bool bitxor_s8(int8_t a, int8_t b) { return a ^ b; }
static inline bool bitxor_s16(int16_t a, int16_t b) { return a ^ b; }
static inline bool bitxor_s32(int32_t a, int32_t b) { return a ^ b; }
static inline bool bitxor_s64(int64_t a, int64_t b) { return a ^ b; }
static inline bool bitxor_u8(uint8_t a, uint8_t b) { return a ^ b; }
static inline bool bitxor_u16(uint16_t a, uint16_t b) { return a ^ b; }
static inline bool bitxor_u32(uint32_t a, uint32_t b) { return a ^ b; }
static inline bool bitxor_u64(uint64_t a, uint64_t b) { return a ^ b; }

static inline bool bitshl_s8(int8_t a, int8_t b) { return a << b; }
static inline bool bitshl_s16(int16_t a, int16_t b) { return a << b; }
static inline bool bitshl_s32(int32_t a, int32_t b) { return a << b; }
static inline bool bitshl_s64(int64_t a, int64_t b) { return a << b; }
static inline bool bitshl_u8(uint8_t a, uint8_t b) { return a << b; }
static inline bool bitshl_u16(uint16_t a, uint16_t b) { return a << b; }
static inline bool bitshl_u32(uint32_t a, uint32_t b) { return a << b; }
static inline bool bitshl_u64(uint64_t a, uint64_t b) { return a << b; }

static inline bool bitshr_s8(int8_t a, int8_t b) { return a >> b; }
static inline bool bitshr_s16(int16_t a, int16_t b) { return a >> b; }
static inline bool bitshr_s32(int32_t a, int32_t b) { return a >> b; }
static inline bool bitshr_s64(int64_t a, int64_t b) { return a >> b; }
static inline bool bitshr_u8(uint8_t a, uint8_t b) { return a >> b; }
static inline bool bitshr_u16(uint16_t a, uint16_t b) { return a >> b; }
static inline bool bitshr_u32(uint32_t a, uint32_t b) { return a >> b; }
static inline bool bitshr_u64(uint64_t a, uint64_t b) { return a >> b; }

static inline bool bitnot_s8(int8_t v) { return ~v; }
static inline bool bitnot_s16(int16_t v) { return ~v; }
static inline bool bitnot_s32(int32_t v) { return ~v; }
static inline bool bitnot_s64(int64_t v) { return ~v; }
static inline bool bitnot_u8(uint8_t v) { return ~v; }
static inline bool bitnot_u16(uint16_t v) { return ~v; }
static inline bool bitnot_u32(uint32_t v) { return ~v; }
static inline bool bitnot_u64(uint64_t v) { return ~v; }

//
// returns the index of the _least_ significant bit, if 'v == 0' then all bits in the return value will be set. aka -1
uint32_t bitlsb_u8(uint8_t v);
uint32_t bitlsb_u16(uint16_t v);
uint32_t bitlsb_u32(uint32_t v);
uint32_t bitlsb_u64(uint64_t v);

//
// returns the index of the _most_ significant bit, if 'v == 0' then all bits in the return value will be set. aka -1
uint32_t bitmsb_u8(uint8_t v);
uint32_t bitmsb_u16(uint16_t v);
uint32_t bitmsb_u32(uint32_t v);
uint32_t bitmsb_u64(uint64_t v);

//
// returns a count of the number of bits set to 1
uint32_t bitcount_u8(uint8_t v);
uint32_t bitcount_u16(uint16_t v);
uint32_t bitcount_u32(uint32_t v);
uint32_t bitcount_u64(uint64_t v);

static inline bool not_f16(half v) { return !(bool)f16tof32(v); }
static inline bool not_f32(float v) { return !(bool)v; }
static inline bool not_f64(double v) { return !(bool)v; }
static inline bool not_s8(int8_t v) { return !v; }
static inline bool not_s16(int16_t v) { return !v; }
static inline bool not_s32(int32_t v) { return !v; }
static inline bool not_s64(int64_t v) { return !v; }
static inline bool not_u8(uint8_t v) { return !v; }
static inline bool not_u16(uint16_t v) { return !v; }
static inline bool not_u32(uint32_t v) { return !v; }
static inline bool not_u64(uint64_t v) { return !v; }

static inline half neg_f16(half v) { return f32tof16(-f16tof32(v)); }
static inline float neg_f32(float v) { return -v; }
static inline double neg_f64(double v) { return -v; }
static inline int8_t neg_s8(int8_t v) { return -v; }
static inline int16_t neg_s16(int16_t v) { return -v; }
static inline int32_t neg_s32(int32_t v) { return -v; }
static inline int64_t neg_s64(int64_t v) { return -v; }
static inline uint8_t neg_u8(uint8_t v) { return -v; }
static inline uint16_t neg_u16(uint16_t v) { return -v; }
static inline uint32_t neg_u32(uint32_t v) { return -v; }
static inline uint64_t neg_u64(uint64_t v) { return -v; }

bool isinf_f16(half v);
bool isinf_f32(float v);
bool isinf_f64(double v);

bool isnan_f16(half v);
bool isnan_f32(float v);
bool isnan_f64(double v);

half floor_f16(half v);
float floor_f32(float v);
double floor_f64(double v);

half ceil_f16(half v);
float ceil_f32(float v);
double ceil_f64(double v);

half round_f16(half v);
float round_f32(float v);
double round_f64(double v);

half trunc_f16(half v);
float trunc_f32(float v);
double trunc_f64(double v);

half sin_f16(half v);
float sin_f32(float v);
double sin_f64(double v);

half cos_f16(half v);
float cos_f32(float v);
double cos_f64(double v);

half tan_f16(half v);
float tan_f32(float v);
double tan_f64(double v);

half asin_f16(half v);
float asin_f32(float v);
double asin_f64(double v);

half acos_f16(half v);
float acos_f32(float v);
double acos_f64(double v);

half atan_f16(half v);
float atan_f32(float v);
double atan_f64(double v);

half sinh_f16(half v);
float sinh_f32(float v);
double sinh_f64(double v);

half cosh_f16(half v);
float cosh_f32(float v);
double cosh_f64(double v);

half tanh_f16(half v);
float tanh_f32(float v);
double tanh_f64(double v);

half asinh_f16(half v);
float asinh_f32(float v);
double asinh_f64(double v);

half acosh_f16(half v);
float acosh_f32(float v);
double acosh_f64(double v);

half atanh_f16(half v);
float atanh_f32(float v);
double atanh_f64(double v);

half atan2_f16(half y, half x);
float atan2_f32(float y, float x);
double atan2_f64(double y, double x);

half fma_f16(half a, half b, half c);
float fma_f32(float a, float b, float c);
double fma_f64(double a, double b, double c);

half sqrt_f16(half v);
float sqrt_f32(float v);
double sqrt_f64(double v);

half pow_f16(half a, half b);
float pow_f32(float a, float b);
double pow_f64(double a, double b);

half exp_f16(half v);
float exp_f32(float v);
double exp_f64(double v);

half log_f16(half v);
float log_f32(float v);
double log_f64(double v);

half exp2_f16(half v);
float exp2_f32(float v);
double exp2_f64(double v);

half log2_f16(half v);
float log2_f32(float v);
double log2_f64(double v);

//
// returns the minimum value between 'a' and 'b'
static inline half min_f16(half a, half b) { return lt_f16(a, b) ? a : b; }
static inline float min_f32(float a, float b) { return a < b ? a : b; }
static inline double min_f64(double a, double b) { return a < b ? a : b; }
static inline int8_t min_s8(int8_t a, int8_t b) { return a < b ? a : b; }
static inline int16_t min_s16(int16_t a, int16_t b) { return a < b ? a : b; }
static inline int32_t min_s32(int32_t a, int32_t b) { return a < b ? a : b; }
static inline int64_t min_s64(int64_t a, int64_t b) { return a < b ? a : b; }
static inline uint8_t min_u8(uint8_t a, uint8_t b) { return a < b ? a : b; }
static inline uint16_t min_u16(uint16_t a, uint16_t b) { return a < b ? a : b; }
static inline uint32_t min_u32(uint32_t a, uint32_t b) { return a < b ? a : b; }
static inline uint64_t min_u64(uint64_t a, uint64_t b) { return a < b ? a : b; }

//
// returns the maximum value between 'a' and 'b'
static inline half max_f16(half a, half b) { return gt_f16(a, b) ? a : b; }
static inline float max_f32(float a, float b) { return a > b ? a : b; }
static inline double max_f64(double a, double b) { return a > b ? a : b; }
static inline int8_t max_s8(int8_t a, int8_t b) { return a > b ? a : b; }
static inline int16_t max_s16(int16_t a, int16_t b) { return a > b ? a : b; }
static inline int32_t max_s32(int32_t a, int32_t b) { return a > b ? a : b; }
static inline int64_t max_s64(int64_t a, int64_t b) { return a > b ? a : b; }
static inline uint8_t max_u8(uint8_t a, uint8_t b) { return a > b ? a : b; }
static inline uint16_t max_u16(uint16_t a, uint16_t b) { return a > b ? a : b; }
static inline uint32_t max_u32(uint32_t a, uint32_t b) { return a > b ? a : b; }
static inline uint64_t max_u64(uint64_t a, uint64_t b) { return a > b ? a : b; }

//
// clamps 'v' so that it is inbetween 'a' and 'b'
static inline half clamp_f16(half v, half min, half max) { return gt_f16(v, max) ? max : (gteq_f16(v, min) ? v : min); }
static inline float clamp_f32(float v, float min, float max) { return v > max ? max : (v >= min ? v : min); }
static inline double clamp_f64(double v, double min, double max) { return v > max ? max : (v >= min ? v : min); }
static inline int8_t clamp_s8(int8_t v, int8_t min, int8_t max) { return v > max ? max : (v >= min ? v : min); }
static inline int16_t clamp_s16(int16_t v, int16_t min, int16_t max) { return v > max ? max : (v >= min ? v : min); }
static inline int32_t clamp_s32(int32_t v, int32_t min, int32_t max) { return v > max ? max : (v >= min ? v : min); }
static inline int64_t clamp_s64(int64_t v, int64_t min, int64_t max) { return v > max ? max : (v >= min ? v : min); }
static inline uint8_t clamp_u8(uint8_t v, uint8_t min, uint8_t max) { return v > max ? max : (v >= min ? v : min); }
static inline uint16_t clamp_u16(uint16_t v, uint16_t min, uint16_t max) { return v > max ? max : (v >= min ? v : min); }
static inline uint32_t clamp_u32(uint32_t v, uint32_t min, uint32_t max) { return v > max ? max : (v >= min ? v : min); }
static inline uint64_t clamp_u64(uint64_t v, uint64_t min, uint64_t max) { return v > max ? max : (v >= min ? v : min); }

//
// returns the absolute (positive) value of 'v'
static inline half abs_f16(half v) { return f16tof32(v) < 0.f ? neg_f16(v) : v; }
static inline float abs_f32(float v) { return v < 0.f ? -v : v; }
static inline double abs_f64(double v) { return v < 0.f ? -v : v; }
static inline int8_t abs_s8(int8_t v) { return v < 0 ? -v : v; }
static inline int16_t abs_s16(int16_t v) { return v < 0 ? -v : v; }
static inline int32_t abs_s32(int32_t v) { return v < 0 ? -v : v; }
static inline int64_t abs_s64(int64_t v) { return v < 0 ? -v : v; }

//
// returns the reciprocal square root of 'v' aka. inverse square root
static inline half rsqrt_f16(half v) { return f32tof16(1.f / sqrt_f32(f16tof32(v))); }
static inline float rsqrt_f32(float v) { return 1.f / sqrt_f32(v); }
static inline double rsqrt_f64(double v) { return 1.f / sqrt_f64(v); }

//
// returns true if 'a' and 'b' are 'epsilon' away from eachother
static inline bool approxeq_f16(half a, half b, half epsilon) { return abs_f32(f16tof32(a) - f16tof32(b)) <= f16tof32(epsilon); }
static inline bool approxeq_f32(float a, float b, float epsilon) { return abs_f32(a - b) <= epsilon; }
static inline bool approxeq_f64(double a, double b, double epsilon) { return abs_f64(a - b) <= epsilon; }

//
// returns -1 if 'v' is less than 0, 1 if 'v' is greater than 0 or 0 if 'v' is 0
static inline half sign_f16(half v) { return f32tof16(f16tof32(v) == 0.f ? 0.f : (f16tof32(v) < 0.f ? -1.f : 1.f)); }
static inline float sign_f32(float v) { return v == 0.f ? 0.f : (v < 0.f ? -1.f : 1.f); }
static inline double sign_f64(double v) { return v == 0.f ? 0.f : (v < 0.f ? -1.f : 1.f); }
static inline int8_t sign_s8(int8_t v) { return v == 0 ? 0 : (v < 0 ? -1 : 1); }
static inline int16_t sign_s16(int16_t v) { return v == 0 ? 0 : (v < 0 ? -1 : 1); }
static inline int32_t sign_s32(int32_t v) { return v == 0 ? 0 : (v < 0 ? -1 : 1); }
static inline int64_t sign_s64(int64_t v) { return v == 0 ? 0 : (v < 0 ? -1 : 1); }

//
// returns a 'v' with sign copied from 'sign'
static inline half copysign_f16(half v, half sign) { return f32tof16(abs_f32(f16tof32(v)) * sign_f32(f16tof32(sign))); }
static inline float copysign_f32(float v, float sign) { return abs_f32(v) * sign_f32(sign); }
static inline double copysign_f64(double v, double sign) { return abs_f64(v) * sign_f64(sign); }
static inline int8_t copysign_s8(int8_t v, int8_t sign) { return abs_s8(v) * sign_s8(sign); }
static inline int16_t copysign_s16(int16_t v, int16_t sign) { return abs_s16(v) * sign_s16(sign); }
static inline int32_t copysign_s32(int32_t v, int32_t sign) { return abs_s32(v) * sign_s32(sign); }
static inline int64_t copysign_s64(int64_t v, int64_t sign) { return abs_s64(v) * sign_s64(sign); }

//
// returns a linear interpolation from 'start' to 'end' at the point of 't' where 't' = 0.f = 'start' and 't' = 1.f = 'end'
static inline half lerp_f16(half start, half end, half t) { return add_f16(mul_f16(sub_f16(end, start), t), start); }
static inline float lerp_f32(float start, float end, float t) { return (end - start) * t + start; }
static inline double lerp_f64(double start, double end, double t) { return (end - start) * t + start; }

//
// returns a value from 0.f to 1.f at the point where 'v' is in relation to 'start' and 'end' where 'v' = 0.f = 'start' and 'v' = 1.f = 'end'
static inline half invlerp_f16(half start, half end, half v) { return div_f16(sub_f16(v, start), sub_f16(end, start)); }
static inline float invlerp_f32(float start, float end, float v) { return (v - start) / (end - start); }
static inline double invlerp_f64(double start, double end, double v) { return (v - start) / (end - start); }

//
// returns the fractional part of a 'v'
static inline half fract_f16(half v) { return sub_f16(v, floor_f16(v)); }
static inline float fract_f32(float v) { return v - floor_f32(v); }
static inline double fract_f64(double v) { return v - floor_f64(v); }

//
// converts 'v' radians to degrees
static inline half degrees_f16(half v) { return f32tof16(f16tof32(v) * (180.f / PI_F32)); }
static inline float degrees_f32(float v) { return v * (180.f / PI_F32); }
static inline double degrees_f64(double v) { return v * (180.f / PI_F64); }

//
// converts 'v' degrees to radians
static inline half radians_f16(half v) { return f32tof16(f16tof32(v) * (PI_F32 / 180.f)); }
static inline float radians_f32(float v) { return v * (PI_F32 / 180.f); }
static inline double radians_f64(double v) { return v * (PI_F64 / 180.f); }

//
// returns 0.f if 'v' < 'edge', otherwise 1.f is returned
static inline half step_f16(half edge, half v) { return f32tof16(f16tof32(v) < f16tof32(edge) ? 0.f : 1.f); }
static inline float step_f32(float edge, float v) { return v < edge ? 0.f : 1.f; }
static inline double step_f64(double edge, double v) { return v < edge ? 0.f : 1.f; }

//
// returns a smooth Hermite interpolation between 0.f and 1.f when 'edge0' < 'x' < 'edge1'
static inline half smoothstep_f16(half edge0, half edge1, half v) { float t = clamp_f32((f16tof32(v) - f16tof32(edge0)) / (f16tof32(edge1) - f16tof32(edge0)), 0.f, 1.f); return f32tof16(t * t * (3.f - 2.f * t)); }
static inline float smoothstep_f32(float edge0, float edge1, float v) { float t = clamp_f32((v - edge0) / (edge1 - edge0), 0.f, 1.f); return t * t * (3.f - 2.f * t); }
static inline double smoothstep_f64(double edge0, double edge1, double v) { double t = clamp_f64((v - edge0) / (edge1 - edge0), 0.f, 1.f); return t * t * (3.f - 2.f * t); }

//
// returns 'v' remapped from a range of 'from_min' to 'from_max' to the range of 'to_min' to 'to_max'
static inline half remap_f16(half v, half from_min, half from_max, half to_min, half to_max) { return add_f16(to_min, div_f16(mul_f16(sub_f16(v, from_min), sub_f16(to_max, to_min)), sub_f16(from_max, from_min))); }
static inline float remap_f32(float v, float from_min, float from_max, float to_min, float to_max) { return to_min + (v - from_min) * (to_max - to_min) / (from_max - from_min); }
static inline double remap_f64(double v, double from_min, double from_max, double to_min, double to_max) { return to_min + (v - from_min) * (to_max - to_min) / (from_max - from_min); }

//
// returns 'v' rounded to the nearest 'multiple'
static inline half roundtomultiple_f16(half v, half multiple) { v = fma_f16(multiple, f32tof16(0.5f), v); half rem = mod_f16(v, multiple); if (gt_f16(v, f32tof16(0.f))) { return sub_f16(v, rem); } else { return sub_f16(sub_f16(v, rem), multiple); } }
static inline float roundtomultiple_f32(float v, float multiple) { v = fma_f32(multiple, 0.5f, v); float rem = mod_f32(v, multiple); if (v > 0.f) { return v - rem; } else { return v - rem - multiple; } }
static inline double roundtomultiple_f64(double v, double multiple) { v = fma_f64(multiple, 0.5f, v); double rem = mod_f64(v, multiple); if (v > 0.f) { return v - rem; } else { return v - rem - multiple; } }

//
// returns 'v' rounded _up_ to the nearest 'multiple'
static inline half rounduptomultiple_f16(half v, half multiple) { half rem = mod_f16(v, multiple); if (gt_f16(v, f32tof16(0.f))) { return sub_f16(add_f16(v, multiple), rem); } else { return sub_f16(v, rem); } }
static inline float rounduptomultiple_f32(float v, float multiple) { float rem = mod_f32(v, multiple); if (v > 0.f) { return v + multiple - rem; } else { return v - rem; } }
static inline double rounduptomultiple_f64(double v, double multiple) { double rem = mod_f64(v, multiple); if (v > 0.f) { return v + multiple - rem; } else { return v - rem; } }

//
// returns 'v' rounded _down_ to the nearest 'multiple'
static inline half rounddowntomultiple_f16(half v, half multiple) { half rem = mod_f16(v, multiple); if (gt_f16(v, f32tof16(0.f))) { return sub_f16(v, rem); } else { return sub_f16(sub_f16(v, rem), multiple); } }
static inline float rounddowntomultiple_f32(float v, float multiple) { float rem = mod_f32(v, multiple); if (v > 0.f) { return v - rem; } else { return v - rem - multiple; } }
static inline double rounddowntomultiple_f64(double v, double multiple) { double rem = mod_f64(v, multiple); if (v > 0.f) { return v - rem; } else { return v - rem - multiple; } }

//
// returns 'v' bitcasted into a float from an integer, no convertion is performed
static inline half bitsto_f16(uint16_t v) { union { uint16_t u; half f; } d = { .u = v }; return d.f; }
static inline float bitsto_f32(uint32_t v) { union { uint32_t u; float f; } d = { .u = v }; return d.f; }
static inline double bitsto_f64(uint64_t v) { union { uint64_t u; double f; } d = { .u = v }; return d.f; }

//
// returns 'v' bitcasted into an integer from a float, no convertion is performed
static inline uint16_t bitsfrom_f16(half v) { union { uint16_t u; half f; } d = { .f = v }; return d.u; }
static inline uint32_t bitsfrom_f32(float v) { union { uint32_t u; float f; } d = { .f = v }; return d.u; }
static inline uint64_t bitsfrom_f64(double v) { union { uint64_t u; double f; } d = { .f = v }; return d.u; }

#endif // _HMATHS_SCALAR_H_
