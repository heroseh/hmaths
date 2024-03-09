#include "hmaths.h"

#include <math.h>

// ===========================================
//
//
// Half type aka. float 16 bit
//
//
// ===========================================

float f16tof32(half v) {
#ifdef HMATHS_NATIVE_F16_SUPPORT
	return (float)v;
#else
	if ((v._bits & 0x7c00) == 0x7c00) { // inf, -inf or nan
		if (v._bits & 0x03ff) return NAN_F32;
		else if (v._bits & 0x8000) return -INFINITY_F32;
		else return INFINITY_F32;
	}

	union { float f; uint32_t u; } t1;
	uint32_t t2;
	uint32_t t3;

	t1.u = v._bits & 0x7fff;      // non-sign bits
	t2 = v._bits & 0x8000;        // sign bit
	t3 = v._bits & 0x7c00;        // exponent

	t1.u <<= 13;                 // align mantissa on MSB
	t2 <<= 16;                   // shift sign bit into position

	t1.u += 0x38000000;          // adjust bias

	t1.u = (t3 == 0 ? 0 : t1.u); // denormals-as-zero

	t1.u |= t2;                  // re-insert sign bit

	return t1.f;
#endif
}

double f16tof64(half v) {
	return (double)f16tof32(v);
}

half f32tof16(float v) {
#ifdef HMATHS_NATIVE_F16_SUPPORT
	return (half)v;
#else
	if (isinf_f32(v)) return (half){ ._bits = v < 0.f ? 0xfc00 : 0x7c00 };
	if (isnan_f32(v)) return (half){ ._bits = 0xffff };

	union { float f; uint32_t u; } vu = { .f = v };
	uint32_t t1;
	uint32_t t2;
	uint32_t t3;

	t1 = vu.u & 0x7fffffff;                // non-sign bits
	t2 = vu.u & 0x80000000;                // sign bit
	t3 = vu.u & 0x7f800000;                // exponent

	t1 >>= 13;                             // align mantissa on MSB
	t2 >>= 16;                             // shift sign bit into position

	t1 -= 0x1c000;                         // adjust bias

	t1 = (t3 < 0x38800000) ? 0 : t1;       // flush-to-zero
	t1 = (t3 > 0x8e000000) ? 0x7bff : t1;  // clamp-to-max
	t1 = (t3 == 0 ? 0 : t1);               // denormals-as-zero

	t1 |= t2;                              // re-insert sign bit

	return (half){ ._bits = t1 };
#endif
}

half f64tof16(double v) {
	return f32tof16((float)v);
}

// ===========================================
//
//
// Scalar
//
//
// ===========================================

#ifndef __HCC__

half mod_f16(half a, half b) {
	return f32tof16(fmodf(f16tof32(a), f16tof32(b)));
}

float mod_f32(float a, float b) {
	return fmodf(a, b);
}

double mod_f64(double a, double b) {
	return fmod(a, b);
}

uint32_t bitlsb_u8(uint8_t v) {
	return bitlsb_u32(v);
}

uint32_t bitlsb_u16(uint16_t v) {
	return bitlsb_u32(v);
}

uint32_t bitlsb_u32(uint32_t v) {
	if (v == 0) {
		return 0xffffffff;
	}

#ifdef __GNUC__
	return __builtin_ctz(v);
#elif defined(_WIN32)
	unsigned long idx;
	_BitScanForward(&idx, v);
	return idx;
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitlsb_u64(uint64_t v) {
	if (v == 0) {
		return 0xffffffff;
	}

#ifdef __GNUC__
	return __builtin_ctzl(v);
#elif defined(_WIN32)
	unsigned long idx;
	_BitScanForward64(&idx, v);
	return idx;
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitmsb_u8(uint8_t v) {
	if (v == 0) {
		return 0xffffffff;
	}

#ifdef __GNUC__
	return ((sizeof(uint32_t) * 8) - __builtin_clz(v)) - 24;
#elif defined(_WIN32)
	unsigned long idx;
	_BitScanReverse(&idx, v);
	return idx - 24;
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitmsb_u16(uint16_t v) {
	if (v == 0) {
		return 0xffffffff;
	}

#ifdef __GNUC__
	return ((sizeof(uint32_t) * 8) - __builtin_clz(v)) - 16 - 1;
#elif defined(_WIN32)
	unsigned long idx;
	_BitScanReverse(&idx, v);
	return idx - 16;
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitmsb_u32(uint32_t v) {
	if (v == 0) {
		return 0xffffffff;
	}

#ifdef __GNUC__
	return (sizeof(uint32_t) * 8) - __builtin_clz(v) - 1;
#elif defined(_WIN32)
	unsigned long idx;
	_BitScanReverse(&idx, v);
	return idx;
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitmsb_u64(uint64_t v) {
	if (v == 0) {
		return 0xffffffff;
	}

#ifdef __GNUC__
	return (sizeof(uint64_t) * 8) - __builtin_clzl(v) - 1;
#elif defined(_WIN32)
	unsigned long idx;
	_BitScanReverse64(&idx, v);
	return idx;
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitcount_u8(uint8_t v) {
#ifdef __GNUC__
	return __builtin_popcount(v);
#elif defined(_WIN32)
	return __popcnt(v);
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitcount_u16(uint16_t v) {
#ifdef __GNUC__
	return __builtin_popcount(v);
#elif defined(_WIN32)
	return __popcnt(v);
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitcount_u32(uint32_t v) {
#ifdef __GNUC__
	return __builtin_popcount(v);
#elif defined(_WIN32)
	return __popcnt(v);
#else
#error "unsupported fartcount"
#endif
}

uint32_t bitcount_u64(uint64_t v) {
#ifdef __GNUC__
	return __builtin_popcountll(v);
#elif defined(_WIN32)
	return __popcnt64(v);
#else
#error "unsupported fartcount"
#endif
}

bool isinf_f16(half v) {
	return isinf_f32(f16tof32(v));
}

bool isinf_f32(float v) {
	return isinf(v);
}

bool isinf_f64(double v) {
	return isinf(v);
}

bool isnan_f16(half v) {
	return isnan_f32(f16tof32(v));
}

bool isnan_f32(float v) {
	return isnan(v);
}

bool isnan_f64(double v) {
	return isnan(v);
}

half floor_f16(half v) {
	return f32tof16(floorf(f16tof32(v)));
}

float floor_f32(float v) {
	return floorf(v);
}

double floor_f64(double v) {
	return floor(v);
}

half ceil_f16(half v) {
	return f32tof16(ceilf(f16tof32(v)));
}

float ceil_f32(float v) {
	return ceilf(v);
}

double ceil_f64(double v) {
	return ceil(v);
}

half round_f16(half v) {
	return f32tof16(roundf(f16tof32(v)));
}

float round_f32(float v) {
	return roundf(v);
}

double round_f64(double v) {
	return round(v);
}

half trunc_f16(half v) {
	return f32tof16(trunc(f16tof32(v)));
}

float trunc_f32(float v) {
	return v - floorf(v);
}

double trunc_f64(double v) {
	return v - floor(v);
}

half sin_f16(half v) {
	return f32tof16(sinf(f16tof32(v)));
}

float sin_f32(float v) {
	return sinf(v);
}

double sin_f64(double v) {
	return sin(v);
}

half cos_f16(half v) {
	return f32tof16(cosf(f16tof32(v)));
}

float cos_f32(float v) {
	return cosf(v);
}

double cos_f64(double v) {
	return cos(v);
}

half tan_f16(half v) {
	return f32tof16(tanf(f16tof32(v)));
}

float tan_f32(float v) {
	return tanf(v);
}

double tan_f64(double v) {
	return tan(v);
}

half asin_f16(half v) {
	return f32tof16(asinf(f16tof32(v)));
}

float asin_f32(float v) {
	return asinf(v);
}

double asin_f64(double v) {
	return asin(v);
}

half acos_f16(half v) {
	return f32tof16(acosf(f16tof32(v)));
}

float acos_f32(float v) {
	return acosf(v);
}

double acos_f64(double v) {
	return acos(v);
}

half atan_f16(half v) {
	return f32tof16(atanf(f16tof32(v)));
}

float atan_f32(float v) {
	return atanf(v);
}

double atan_f64(double v) {
	return atan(v);
}

half sinh_f16(half v) {
	return f32tof16(sinhf(f16tof32(v)));
}

float sinh_f32(float v) {
	return sinhf(v);
}

double sinh_f64(double v) {
	return sinh(v);
}

half cosh_f16(half v) {
	return f32tof16(coshf(f16tof32(v)));
}

float cosh_f32(float v) {
	return coshf(v);
}

double cosh_f64(double v) {
	return cosh(v);
}

half tanh_f16(half v) {
	return f32tof16(tanhf(f16tof32(v)));
}

float tanh_f32(float v) {
	return tanhf(v);
}

double tanh_f64(double v) {
	return tanh(v);
}

half asinh_f16(half v) {
	return f32tof16(asinhf(f16tof32(v)));
}

float asinh_f32(float v) {
	return asinhf(v);
}

double asinh_f64(double v) {
	return asinh(v);
}

half acosh_f16(half v) {
	return f32tof16(acoshf(f16tof32(v)));
}

float acosh_f32(float v) {
	return acoshf(v);
}

double acosh_f64(double v) {
	return acosh(v);
}

half atanh_f16(half v) {
	return f32tof16(atanhf(f16tof32(v)));
}

float atanh_f32(float v) {
	return atanhf(v);
}

double atanh_f64(double v) {
	return atanh(v);
}

half atan2_f16(half y, half x) {
	return f32tof16(atan2f(f16tof32(y), f16tof32(x)));
}

float atan2_f32(float y, float x) {
	return atan2f(y, x);
}

double atan2_f64(double y, double x) {
	return atan2(y, x);
}

half fma_f16(half a, half b, half c) {
	return f32tof16(fmaf(f16tof32(a), f16tof32(b), f16tof32(c)));
}

float fma_f32(float a, float b, float c) {
	return fmaf(a, b, c);
}

double fma_f64(double a, double b, double c) {
	return fma(a, b, c);
}

half sqrt_f16(half v) {
	return f32tof16(sqrtf(f16tof32(v)));
}

float sqrt_f32(float v) {
	return sqrtf(v);
}

double sqrt_f64(double v) {
	return sqrt(v);
}

half pow_f16(half a, half b) {
	return f32tof16(powf(f16tof32(a), f16tof32(b)));
}

float pow_f32(float a, float b) {
	return powf(a, b);
}

double pow_f64(double a, double b) {
	return pow(a, b);
}

half exp_f16(half v) {
	return f32tof16(expf(f16tof32(v)));
}

float exp_f32(float v) {
	return expf(v);
}

double exp_f64(double v) {
	return exp(v);
}

half log_f16(half v) {
	return f32tof16(logf(f16tof32(v)));
}

float log_f32(float v) {
	return logf(v);
}

double log_f64(double v) {
	return log(v);
}

half exp2_f16(half v) {
	return f32tof16(exp2f(f16tof32(v)));
}

float exp2_f32(float v) {
	return exp2f(v);
}

double exp2_f64(double v) {
	return exp2(v);
}

half log2_f16(half v) {
	return f32tof16(log2f(f16tof32(v)));
}

float log2_f32(float v) {
	return log2f(v);
}

double log2_f64(double v) {
	return log2(v);
}

#endif // ifndef __HCC__

// ===========================================
//
//
// Vector
//
//
// ===========================================

//
// returns a vector that is vector 'v' reflected against surface 'normal'
f16x2 reflect_f16x2(f16x2 v, f16x2 normal) {
	half dot_2 = mul_f16(dot_f16x2(normal, v), f32tof16(2.f));
	return sub_f16x2(v, muls_f16x2(normal, dot_2));
}
f32x2 reflect_f32x2(f32x2 v, f32x2 normal) {
	float dot_2 = dot_f32x2(normal, v) * 2.f;
	return sub_f32x2(v, muls_f32x2(normal, dot_2));
}
f64x2 reflect_f64x2(f64x2 v, f64x2 normal) {
	double dot_2 = dot_f64x2(normal, v) * 2.f;
	return sub_f64x2(v, muls_f64x2(normal, dot_2));
}
f16x3 reflect_f16x3(f16x3 v, f16x3 normal) {
	half dot_2 = mul_f16(dot_f16x3(normal, v), f32tof16(2.f));
	return sub_f16x3(v, muls_f16x3(normal, dot_2));
}
f32x3 reflect_f32x3(f32x3 v, f32x3 normal) {
	float dot_2 = dot_f32x3(normal, v) * 2.f;
	return sub_f32x3(v, muls_f32x3(normal, dot_2));
}
f64x3 reflect_f64x3(f64x3 v, f64x3 normal) {
	double dot_2 = dot_f64x3(normal, v) * 2.f;
	return sub_f64x3(v, muls_f64x3(normal, dot_2));
}
f16x4 reflect_f16x4(f16x4 v, f16x4 normal) {
	half dot_2 = mul_f16(dot_f16x4(normal, v), f32tof16(2.f));
	return sub_f16x4(v, muls_f16x4(normal, dot_2));
}
f32x4 reflect_f32x4(f32x4 v, f32x4 normal) {
	float dot_2 = dot_f32x4(normal, v) * 2.f;
	return sub_f32x4(v, muls_f32x4(normal, dot_2));
}
f64x4 reflect_f64x4(f64x4 v, f64x4 normal) {
	double dot_2 = dot_f64x4(normal, v) * 2.f;
	return sub_f64x4(v, muls_f64x4(normal, dot_2));
}

//
// returns the refraction vector for vector 'v' against surface 'normal' with the ratio 'eta'
f16x2 refract_f16x2(f16x2 v, f16x2 normal, half eta) {
	half dot = dot_f16x2(normal, v);
	half inv_dot_sq = sub_f16(f32tof16(1.f), mul_f16(dot, dot));
	half eta_sq = mul_f16(eta, eta);
	half k = sub_f16(f32tof16(1.f), mul_f16(eta_sq, inv_dot_sq));
	if (lt_f16(k, f32tof16(0.f))) {
		return f16x2s(f32tof16(0.f));
	}
	return sub_f16x2(muls_f16x2(v, eta), muls_f16x2(normal, ((add_f16(mul_f16(eta, dot_f16x2(normal, v)), sqrt_f16(k))))));
}
f32x2 refract_f32x2(f32x2 v, f32x2 normal, float eta) {
	float dot = dot_f32x2(normal, v);
	float inv_dot_sq = 1.f - dot * dot;
	float eta_sq = eta * eta;
	float k = 1.f - eta_sq * inv_dot_sq;
	if (k < 0.f) {
		return f32x2s(0.f);
	}
	return sub_f32x2(muls_f32x2(v, eta), muls_f32x2(normal, ((eta * dot_f32x2(normal, v) + sqrt_f32(k)))));
}
f64x2 refract_f64x2(f64x2 v, f64x2 normal, double eta) {
	double dot = dot_f64x2(normal, v);
	double inv_dot_sq = 1.f - dot * dot;
	double eta_sq = eta * eta;
	double k = 1.f - eta_sq * inv_dot_sq;
	if (k < 0.f) {
		return f64x2s(0.f);
	}
	return sub_f64x2(muls_f64x2(v, eta), muls_f64x2(normal, ((eta * dot_f64x2(normal, v) + sqrt_f32(k)))));
}
f16x3 refract_f16x3(f16x3 v, f16x3 normal, half eta) {
	half dot = dot_f16x3(normal, v);
	half inv_dot_sq = sub_f16(f32tof16(1.f), mul_f16(dot, dot));
	half eta_sq = mul_f16(eta, eta);
	half k = sub_f16(f32tof16(1.f), mul_f16(eta_sq, inv_dot_sq));
	if (lt_f16(k, f32tof16(0.f))) {
		return f16x3s(f32tof16(0.f));
	}
	return sub_f16x3(muls_f16x3(v, eta), muls_f16x3(normal, ((add_f16(mul_f16(eta, dot_f16x3(normal, v)), sqrt_f16(k))))));
}
f32x3 refract_f32x3(f32x3 v, f32x3 normal, float eta) {
	float dot = dot_f32x3(normal, v);
	float inv_dot_sq = 1.f - dot * dot;
	float eta_sq = eta * eta;
	float k = 1.f - eta_sq * inv_dot_sq;
	if (k < 0.f) {
		return f32x3s(0.f);
	}
	return sub_f32x3(muls_f32x3(v, eta), muls_f32x3(normal, ((eta * dot_f32x3(normal, v) + sqrt_f32(k)))));
}
f64x3 refract_f64x3(f64x3 v, f64x3 normal, double eta) {
	double dot = dot_f64x3(normal, v);
	double inv_dot_sq = 1.f - dot * dot;
	double eta_sq = eta * eta;
	double k = 1.f - eta_sq * inv_dot_sq;
	if (k < 0.f) {
		return f64x3s(0.f);
	}
	return sub_f64x3(muls_f64x3(v, eta), muls_f64x3(normal, ((eta * dot_f64x3(normal, v) + sqrt_f32(k)))));
}
f16x4 refract_f16x4(f16x4 v, f16x4 normal, half eta) {
	half dot = dot_f16x4(normal, v);
	half inv_dot_sq = sub_f16(f32tof16(1.f), mul_f16(dot, dot));
	half eta_sq = mul_f16(eta, eta);
	half k = sub_f16(f32tof16(1.f), mul_f16(eta_sq, inv_dot_sq));
	if (lt_f16(k, f32tof16(0.f))) {
		return f16x4s(f32tof16(0.f));
	}
	return sub_f16x4(muls_f16x4(v, eta), muls_f16x4(normal, ((add_f16(mul_f16(eta, dot_f16x4(normal, v)), sqrt_f16(k))))));
}
f32x4 refract_f32x4(f32x4 v, f32x4 normal, float eta) {
	float dot = dot_f32x4(normal, v);
	float inv_dot_sq = 1.f - dot * dot;
	float eta_sq = eta * eta;
	float k = 1.f - eta_sq * inv_dot_sq;
	if (k < 0.f) {
		return f32x4s(0.f);
	}
	return sub_f32x4(muls_f32x4(v, eta), muls_f32x4(normal, ((eta * dot_f32x4(normal, v) + sqrt_f32(k)))));
}
f64x4 refract_f64x4(f64x4 v, f64x4 normal, double eta) {
	double dot = dot_f64x4(normal, v);
	double inv_dot_sq = 1.f - dot * dot;
	double eta_sq = eta * eta;
	double k = 1.f - eta_sq * inv_dot_sq;
	if (k < 0.f) {
		return f64x4s(0.f);
	}
	return sub_f64x4(muls_f64x4(v, eta), muls_f64x4(normal, ((eta * dot_f64x4(normal, v) + sqrt_f32(k)))));
}

uint32_t pack_f16x2_f32x2(f32x2 v) {
	return
		((uint32_t)bitsfrom_f16(f32tof16(v.x)) << 0)  |
		((uint32_t)bitsfrom_f16(f32tof16(v.y)) << 16) ;
}

f32x2 unpack_f16x2_f32x2(uint32_t v) {
	return f32x2(
		f16tof32(bitsto_f16(v & 0xffff)),
		f16tof32(bitsto_f16(v >> 16))
	);
}

uint32_t pack_u16x2_f32x2(f32x2 v) {
	v = round_f32x2(muls_f32x2(clamps_f32x2(v, 0.f, 1.f), 65535.f));
	return
		((uint32_t)v.x << 0)  |
		((uint32_t)v.y << 16) ;
}

f32x2 unpack_u16x2_f32x2(uint32_t v) {
	return f32x2(
		(float)(v & 0xffff) / 65535.f,
		(float)(v >> 16) / 65535.f
	);
}

uint32_t pack_s16x2_f32x2(f32x2 v) {
	v = round_f32x2(muls_f32x2(clamps_f32x2(v, -1.f, 1.f), 32767.f));
	return
		((uint32_t)(uint16_t)(int16_t)v.x << 0)  |
		((uint32_t)(uint16_t)(int16_t)v.y << 16) ;
}

f32x2 unpack_s16x2_f32x2(uint32_t v) {
	return f32x2(
		clamp_f32((float)(int32_t)(int16_t)(v & 0xffff) / 32767.f, -1.f, 1.f),
		clamp_f32((float)(int32_t)(int16_t)(v >> 16) / 32767.f, -1.f, 1.f)
	);
}

uint32_t pack_u8x4_f32x4(f32x4 v) {
	v = round_f32x4(muls_f32x4(clamps_f32x4(v, 0.f, 1.f), 255.f));
	return
		((uint32_t)v.x << 0)  |
		((uint32_t)v.y << 8)  |
		((uint32_t)v.z << 16) |
		((uint32_t)v.w << 24) ;
}

f32x4 unpack_u8x4_f32x4(uint32_t v) {
	return f32x4(
		(float)((v >> 0)  & 0xff) / 255.f,
		(float)((v >> 8)  & 0xff) / 255.f,
		(float)((v >> 16) & 0xff) / 255.f,
		(float)((v >> 24) & 0xff) / 255.f
	);
}

uint32_t pack_s8x4_f32x4(f32x4 v) {
	v = round_f32x4(muls_f32x4(clamps_f32x4(v, -1.f, 1.f), 127.f));
	return
		((uint32_t)(uint8_t)(int8_t)v.x << 0)  |
		((uint32_t)(uint8_t)(int8_t)v.y << 8)  |
		((uint32_t)(uint8_t)(int8_t)v.z << 16) |
		((uint32_t)(uint8_t)(int8_t)v.w << 24) ;
}

f32x4 unpack_s8x4_f32x4(uint32_t v) {
	return clamps_f32x4(
		f32x4(
			((float)(int32_t)(int8_t)((v >> 0)  & 0xff) / 127.f),
			((float)(int32_t)(int8_t)((v >> 8)  & 0xff) / 127.f),
			((float)(int32_t)(int8_t)((v >> 16) & 0xff) / 127.f),
			((float)(int32_t)(int8_t)((v >> 24) & 0xff) / 127.f)
		), -1.f, 1.f
	);
}

// ===========================================
//
//
// Matrix
//
//
// ===========================================


//
// returns a matrix that is a result of multipling matrix 'a' with matrix 'b'
f32x2x2 mul_f32x2x2_f32x2x2(f32x2x2 a, f32x2x2 b) {
	f32x2x2 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y;
	return m;
}
f64x2x2 mul_f64x2x2_f64x2x2(f64x2x2 a, f64x2x2 b) {
	f64x2x2 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y;
	return m;
}
f32x3x3 mul_f32x3x3_f32x3x3(f32x3x3 a, f32x3x3 b) {
	f32x3x3 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z;
	return m;
}
f64x3x3 mul_f64x3x3_f64x3x3(f64x3x3 a, f64x3x3 b) {
	f64x3x3 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z;
	return m;
}
f32x4x4 mul_f32x4x4_f32x4x4(f32x4x4 a, f32x4x4 b) {
	f32x4x4 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z + a.cols[3].x * b.cols[0].w;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z + a.cols[3].y * b.cols[0].w;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z + a.cols[3].z * b.cols[0].w;
	m.cols[0].w = a.cols[0].w * b.cols[0].x + a.cols[1].w * b.cols[0].y + a.cols[2].w * b.cols[0].z + a.cols[3].w * b.cols[0].w;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z + a.cols[3].x * b.cols[1].w;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z + a.cols[3].y * b.cols[1].w;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z + a.cols[3].z * b.cols[1].w;
	m.cols[1].w = a.cols[0].w * b.cols[1].x + a.cols[1].w * b.cols[1].y + a.cols[2].w * b.cols[1].z + a.cols[3].w * b.cols[1].w;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z + a.cols[3].x * b.cols[2].w;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z + a.cols[3].y * b.cols[2].w;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z + a.cols[3].z * b.cols[2].w;
	m.cols[2].w = a.cols[0].w * b.cols[2].x + a.cols[1].w * b.cols[2].y + a.cols[2].w * b.cols[2].z + a.cols[3].w * b.cols[2].w;
	m.cols[3].x = a.cols[0].x * b.cols[3].x + a.cols[1].x * b.cols[3].y + a.cols[2].x * b.cols[3].z + a.cols[3].x * b.cols[3].w;
	m.cols[3].y = a.cols[0].y * b.cols[3].x + a.cols[1].y * b.cols[3].y + a.cols[2].y * b.cols[3].z + a.cols[3].y * b.cols[3].w;
	m.cols[3].z = a.cols[0].z * b.cols[3].x + a.cols[1].z * b.cols[3].y + a.cols[2].z * b.cols[3].z + a.cols[3].z * b.cols[3].w;
	m.cols[3].w = a.cols[0].w * b.cols[3].x + a.cols[1].w * b.cols[3].y + a.cols[2].w * b.cols[3].z + a.cols[3].w * b.cols[3].w;
	return m;
}
f64x4x4 mul_f64x4x4_f64x4x4(f64x4x4 a, f64x4x4 b) {
	f64x4x4 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z + a.cols[3].x * b.cols[0].w;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z + a.cols[3].y * b.cols[0].w;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z + a.cols[3].z * b.cols[0].w;
	m.cols[0].w = a.cols[0].w * b.cols[0].x + a.cols[1].w * b.cols[0].y + a.cols[2].w * b.cols[0].z + a.cols[3].w * b.cols[0].w;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z + a.cols[3].x * b.cols[1].w;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z + a.cols[3].y * b.cols[1].w;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z + a.cols[3].z * b.cols[1].w;
	m.cols[1].w = a.cols[0].w * b.cols[1].x + a.cols[1].w * b.cols[1].y + a.cols[2].w * b.cols[1].z + a.cols[3].w * b.cols[1].w;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z + a.cols[3].x * b.cols[2].w;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z + a.cols[3].y * b.cols[2].w;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z + a.cols[3].z * b.cols[2].w;
	m.cols[2].w = a.cols[0].w * b.cols[2].x + a.cols[1].w * b.cols[2].y + a.cols[2].w * b.cols[2].z + a.cols[3].w * b.cols[2].w;
	m.cols[3].x = a.cols[0].x * b.cols[3].x + a.cols[1].x * b.cols[3].y + a.cols[2].x * b.cols[3].z + a.cols[3].x * b.cols[3].w;
	m.cols[3].y = a.cols[0].y * b.cols[3].x + a.cols[1].y * b.cols[3].y + a.cols[2].y * b.cols[3].z + a.cols[3].y * b.cols[3].w;
	m.cols[3].z = a.cols[0].z * b.cols[3].x + a.cols[1].z * b.cols[3].y + a.cols[2].z * b.cols[3].z + a.cols[3].z * b.cols[3].w;
	m.cols[3].w = a.cols[0].w * b.cols[3].x + a.cols[1].w * b.cols[3].y + a.cols[2].w * b.cols[3].z + a.cols[3].w * b.cols[3].w;
	return m;
}

//
// returns a matrix that is a result of multipling matrix 'm' with scalar 's'
f32x2x2 muls_f32x2x2(f32x2x2 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	return m;
}
f64x2x2 muls_f64x2x2(f64x2x2 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	return m;
}
f32x3x3 muls_f32x3x3(f32x3x3 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[2].z *= s;
	return m;
}
f64x3x3 muls_f64x3x3(f64x3x3 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[2].z *= s;
	return m;
}
f32x4x4 muls_f32x4x4(f32x4x4 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[0].w *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[1].w *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[2].z *= s;
	m.cols[2].w *= s;
	m.cols[3].x *= s;
	m.cols[3].y *= s;
	m.cols[3].z *= s;
	m.cols[3].w *= s;
	return m;
}
f64x4x4 muls_f64x4x4(f64x4x4 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[0].w *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[1].w *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[2].z *= s;
	m.cols[2].w *= s;
	m.cols[3].x *= s;
	m.cols[3].y *= s;
	m.cols[3].z *= s;
	m.cols[3].w *= s;
	return m;
}

//
// returns a vector that is a result of multipling matrix 'm' with vector 'v'
f32x2 mul_f32x2x2_f32x2(f32x2x2 m, f32x2 v) {
	f32x2 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y;
	return ret;
}
f64x2 mul_f64x2x2_f64x2(f64x2x2 m, f64x2 v) {
	f64x2 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y;
	return ret;
}
f32x3 mul_f32x3x3_f32x3(f32x3x3 m, f32x3 v) {
	f32x3 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z;
	return ret;
}
f64x3 mul_f64x3x3_f64x3(f64x3x3 m, f64x3 v) {
	f64x3 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z;
	return ret;
}
f32x4 mul_f32x4x4_f32x4(f32x4x4 m, f32x4 v) {
	f32x4 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z + m.cols[3].x * v.w;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z + m.cols[3].y * v.w;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z + m.cols[3].z * v.w;
	ret.w = m.cols[0].w * v.x + m.cols[1].w * v.y + m.cols[2].w * v.z + m.cols[3].w * v.w;
	return ret;
}
f64x4 mul_f64x4x4_f64x4(f64x4x4 m, f64x4 v) {
	f64x4 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z + m.cols[3].x * v.w;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z + m.cols[3].y * v.w;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z + m.cols[3].z * v.w;
	ret.w = m.cols[0].w * v.x + m.cols[1].w * v.y + m.cols[2].w * v.z + m.cols[3].w * v.w;
	return ret;
}

//
// returns a vector that is a result of multipling vector 'v' with matrix 'm'
f32x2 mul_f32x2_f32x2x2(f32x2 v, f32x2x2 m) {
	f32x2 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y;
	return ret;
}
f64x2 mul_f64x2_f64x2x2(f64x2 v, f64x2x2 m) {
	f64x2 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y;
	return ret;
}
f32x3 mul_f32x3_f32x3x3(f32x3 v, f32x3x3 m) {
	f32x3 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z;
	return ret;
}
f64x3 mul_f64x3_f64x3x3(f64x3 v, f64x3x3 m) {
	f64x3 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z;
	return ret;
}
f32x4 mul_f32x4_f32x4x4(f32x4 v, f32x4x4 m) {
	f32x4 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z + v.w * m.cols[0].w;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z + v.w * m.cols[1].w;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z + v.w * m.cols[2].w;
	ret.w = v.x * m.cols[3].x + v.y * m.cols[3].y + v.z * m.cols[3].z + v.w * m.cols[3].w;
	return ret;
}
f64x4 mul_f64x4_f64x4x4(f64x4 v, f64x4x4 m) {
	f64x4 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z + v.w * m.cols[0].w;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z + v.w * m.cols[1].w;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z + v.w * m.cols[2].w;
	ret.w = v.x * m.cols[3].x + v.y * m.cols[3].y + v.z * m.cols[3].z + v.w * m.cols[3].w;
	return ret;
}

//
// returns the transposed matrix of matrix 'm'
f32x2x2 transpose_f32x2x2(f32x2x2 m) {
	f32x2x2 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	return ret;
}
f64x2x2 transpose_f64x2x2(f64x2x2 m) {
	f64x2x2 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	return ret;
}
f32x3x3 transpose_f32x3x3(f32x3x3 m) {
	f32x3x3 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[2].z = m.cols[2].z;
	return ret;
}
f64x3x3 transpose_f64x3x3(f64x3x3 m) {
	f64x3x3 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[2].z = m.cols[2].z;
	return ret;
}
f32x4x4 transpose_f32x4x4(f32x4x4 m) {
	f32x4x4 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[3].x = m.cols[0].w;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[3].y = m.cols[1].w;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[2].z = m.cols[2].z;
	ret.cols[3].z = m.cols[2].w;
	ret.cols[0].w = m.cols[3].x;
	ret.cols[1].w = m.cols[3].y;
	ret.cols[2].w = m.cols[3].z;
	ret.cols[3].w = m.cols[3].w;
	return ret;
}
f64x4x4 transpose_f64x4x4(f64x4x4 m) {
	f64x4x4 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[3].x = m.cols[0].w;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[3].y = m.cols[1].w;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[2].z = m.cols[2].z;
	ret.cols[3].z = m.cols[2].w;
	ret.cols[0].w = m.cols[3].x;
	ret.cols[1].w = m.cols[3].y;
	ret.cols[2].w = m.cols[3].z;
	ret.cols[3].w = m.cols[3].w;
	return ret;
}

//
// returns a matrix from the outer product of vector 'a' and vector 'b'
f32x2x2 outerproduct_f32x2_f32x2(f32x2 r, f32x2 c) {
	f32x2x2 ret;
	ret.cols[0].x = r.x * c.x;
	ret.cols[0].y = r.x * c.y;
	ret.cols[1].x = r.y * c.x;
	ret.cols[1].y = r.y * c.y;
	return ret;
}
f64x2x2 outerproduct_f64x2_f64x2(f64x2 r, f64x2 c) {
	f64x2x2 ret;
	ret.cols[0].x = r.x * c.x;
	ret.cols[0].y = r.x * c.y;
	ret.cols[1].x = r.y * c.x;
	ret.cols[1].y = r.y * c.y;
	return ret;
}
f32x3x3 outerproduct_f32x3_f32x3(f32x3 r, f32x3 c) {
	f32x3x3 ret;
	ret.cols[0].x = r.x * c.x;
	ret.cols[0].y = r.x * c.y;
	ret.cols[0].z = r.x * c.z;
	ret.cols[1].x = r.y * c.x;
	ret.cols[1].y = r.y * c.y;
	ret.cols[1].z = r.y * c.z;
	ret.cols[2].x = r.z * c.x;
	ret.cols[2].y = r.z * c.y;
	ret.cols[2].z = r.z * c.z;
	return ret;
}
f64x3x3 outerproduct_f64x3_f64x3(f64x3 r, f64x3 c) {
	f64x3x3 ret;
	ret.cols[0].x = r.x * c.x;
	ret.cols[0].y = r.x * c.y;
	ret.cols[0].z = r.x * c.z;
	ret.cols[1].x = r.y * c.x;
	ret.cols[1].y = r.y * c.y;
	ret.cols[1].z = r.y * c.z;
	ret.cols[2].x = r.z * c.x;
	ret.cols[2].y = r.z * c.y;
	ret.cols[2].z = r.z * c.z;
	return ret;
}
f32x4x4 outerproduct_f32x4_f32x4(f32x4 r, f32x4 c) {
	f32x4x4 ret;
	ret.cols[0].x = r.x * c.x;
	ret.cols[0].y = r.x * c.y;
	ret.cols[0].z = r.x * c.z;
	ret.cols[0].w = r.x * c.w;
	ret.cols[1].x = r.y * c.x;
	ret.cols[1].y = r.y * c.y;
	ret.cols[1].z = r.y * c.z;
	ret.cols[1].w = r.y * c.w;
	ret.cols[2].x = r.z * c.x;
	ret.cols[2].y = r.z * c.y;
	ret.cols[2].z = r.z * c.z;
	ret.cols[2].w = r.z * c.w;
	ret.cols[3].x = r.w * c.x;
	ret.cols[3].y = r.w * c.y;
	ret.cols[3].z = r.w * c.z;
	ret.cols[3].w = r.w * c.w;
	return ret;
}
f64x4x4 outerproduct_f64x4_f64x4(f64x4 r, f64x4 c) {
	f64x4x4 ret;
	ret.cols[0].x = r.x * c.x;
	ret.cols[0].y = r.x * c.y;
	ret.cols[0].z = r.x * c.z;
	ret.cols[0].w = r.x * c.w;
	ret.cols[1].x = r.y * c.x;
	ret.cols[1].y = r.y * c.y;
	ret.cols[1].z = r.y * c.z;
	ret.cols[1].w = r.y * c.w;
	ret.cols[2].x = r.z * c.x;
	ret.cols[2].y = r.z * c.y;
	ret.cols[2].z = r.z * c.z;
	ret.cols[2].w = r.z * c.w;
	ret.cols[3].x = r.w * c.x;
	ret.cols[3].y = r.w * c.y;
	ret.cols[3].z = r.w * c.z;
	ret.cols[3].w = r.w * c.w;
	return ret;
}

//
// returns the determinant of matrix 'm'
float determinant_f32x2x2(f32x2x2 m) {
	return m.cols[0].x * m.cols[1].y - m.cols[1].x * m.cols[0].y;
}
double determinant_f64x2x2(f64x2x2 m) {
	return m.cols[0].x * m.cols[1].y - m.cols[1].x * m.cols[0].y;
}
float determinant_f32x3x3(f32x3x3 m) {
	float s[3];
	s[0] = (m.cols[1].y * m.cols[2].z) - (m.cols[2].y * m.cols[1].z);
	s[1] = (m.cols[1].x * m.cols[2].z) - (m.cols[1].z * m.cols[2].x);
	s[2] = (m.cols[1].x * m.cols[2].y) - (m.cols[1].y * m.cols[2].x);
	float det = s[0] - s[1] + s[2];
	return det;
}
double determinant_f64x3x3(f64x3x3 m) {
	double s[3];
	s[0] = (m.cols[1].y * m.cols[2].z) - (m.cols[2].y * m.cols[1].z);
	s[1] = (m.cols[1].x * m.cols[2].z) - (m.cols[1].z * m.cols[2].x);
	s[2] = (m.cols[1].x * m.cols[2].y) - (m.cols[1].y * m.cols[2].x);
	double det = s[0] - s[1] + s[2];
	return det;
}
float determinant_f32x4x4(f32x4x4 m) {
	float s[6];
	float c[6];

	s[0] = m.cols[0].x*m.cols[1].y - m.cols[1].x*m.cols[0].y;
	s[1] = m.cols[0].x*m.cols[1].z - m.cols[1].x*m.cols[0].z;
	s[2] = m.cols[0].x*m.cols[1].w - m.cols[1].x*m.cols[0].w;
	s[3] = m.cols[0].y*m.cols[1].z - m.cols[1].y*m.cols[0].z;
	s[4] = m.cols[0].y*m.cols[1].w - m.cols[1].y*m.cols[0].w;
	s[5] = m.cols[0].z*m.cols[1].w - m.cols[1].z*m.cols[0].w;

	c[0] = m.cols[2].x*m.cols[3].y - m.cols[3].x*m.cols[2].y;
	c[1] = m.cols[2].x*m.cols[3].z - m.cols[3].x*m.cols[2].z;
	c[2] = m.cols[2].x*m.cols[3].w - m.cols[3].x*m.cols[2].w;
	c[3] = m.cols[2].y*m.cols[3].z - m.cols[3].y*m.cols[2].z;
	c[4] = m.cols[2].y*m.cols[3].w - m.cols[3].y*m.cols[2].w;
	c[5] = m.cols[2].z*m.cols[3].w - m.cols[3].z*m.cols[2].w;

	float det = s[0]*c[5]-s[1]*c[4]+s[2]*c[3]+s[3]*c[2]-s[4]*c[1]+s[5]*c[0];
	return det;
}
double determinant_f64x4x4(f64x4x4 m) {
	double s[6];
	double c[6];

	s[0] = m.cols[0].x*m.cols[1].y - m.cols[1].x*m.cols[0].y;
	s[1] = m.cols[0].x*m.cols[1].z - m.cols[1].x*m.cols[0].z;
	s[2] = m.cols[0].x*m.cols[1].w - m.cols[1].x*m.cols[0].w;
	s[3] = m.cols[0].y*m.cols[1].z - m.cols[1].y*m.cols[0].z;
	s[4] = m.cols[0].y*m.cols[1].w - m.cols[1].y*m.cols[0].w;
	s[5] = m.cols[0].z*m.cols[1].w - m.cols[1].z*m.cols[0].w;

	c[0] = m.cols[2].x*m.cols[3].y - m.cols[3].x*m.cols[2].y;
	c[1] = m.cols[2].x*m.cols[3].z - m.cols[3].x*m.cols[2].z;
	c[2] = m.cols[2].x*m.cols[3].w - m.cols[3].x*m.cols[2].w;
	c[3] = m.cols[2].y*m.cols[3].z - m.cols[3].y*m.cols[2].z;
	c[4] = m.cols[2].y*m.cols[3].w - m.cols[3].y*m.cols[2].w;
	c[5] = m.cols[2].z*m.cols[3].w - m.cols[3].z*m.cols[2].w;

	double det = s[0]*c[5]-s[1]*c[4]+s[2]*c[3]+s[3]*c[2]-s[4]*c[1]+s[5]*c[0];
	return det;
}

//
// returns the inverse of matrix 'm'
f32x2x2 inverse_f32x2x2(f32x2x2 m) {
	float inv_det = 1.f / determinant_f32x2x2(m);
	f32x2x2 ret;
	ret.cols[0].x = m.cols[1].y * inv_det;
	ret.cols[0].y = -m.cols[0].y * inv_det;

	ret.cols[1].x = -m.cols[1].x * inv_det;
	ret.cols[1].y = m.cols[0].x * inv_det;
	return ret;
}
f64x2x2 inverse_f64x2x2(f64x2x2 m) {
	double inv_det = 1.f / determinant_f64x2x2(m);
	f64x2x2 ret;
	ret.cols[0].x = m.cols[1].y * inv_det;
	ret.cols[0].y = -m.cols[0].y * inv_det;

	ret.cols[1].x = -m.cols[1].x * inv_det;
	ret.cols[1].y = m.cols[0].x * inv_det;
	return ret;
}
f32x3x3 inverse_f32x3x3(f32x3x3 m) {
	float s[3];
	s[0] = (m.cols[1].y * m.cols[2].z) - (m.cols[2].y * m.cols[1].z);
	s[1] = (m.cols[1].x * m.cols[2].z) - (m.cols[1].z * m.cols[2].x);
	s[2] = (m.cols[1].x * m.cols[2].y) - (m.cols[1].y * m.cols[2].x);
	float det = s[0] - s[1] + s[2];
	float inv_det = 1.f / det;
	f32x3x3 ret;
	ret.cols[0].x = s[0] * inv_det;
	ret.cols[0].y = (m.cols[0].z * m.cols[2].y - m.cols[0].y * m.cols[2].z) * inv_det;
	ret.cols[0].z = (m.cols[0].y * m.cols[1].z - m.cols[0].z * m.cols[1].y) * inv_det;

	ret.cols[1].x = -s[1] * inv_det;
	ret.cols[1].y = (m.cols[0].x * m.cols[2].z - m.cols[0].z * m.cols[2].x) * inv_det;
	ret.cols[1].z = (m.cols[1].x * m.cols[0].z - m.cols[0].x * m.cols[1].z) * inv_det;

	ret.cols[2].x = s[2] * inv_det;
	ret.cols[2].y = (m.cols[2].x * m.cols[0].y - m.cols[0].x * m.cols[2].y) * inv_det;
	ret.cols[2].z = (m.cols[0].x * m.cols[1].y - m.cols[1].x * m.cols[0].y) * inv_det;
	return ret;
}
f64x3x3 inverse_f64x3x3(f64x3x3 m) {
	double s[3];
	s[0] = (m.cols[1].y * m.cols[2].z) - (m.cols[2].y * m.cols[1].z);
	s[1] = (m.cols[1].x * m.cols[2].z) - (m.cols[1].z * m.cols[2].x);
	s[2] = (m.cols[1].x * m.cols[2].y) - (m.cols[1].y * m.cols[2].x);
	double det = s[0] - s[1] + s[2];
	double inv_det = 1.f / det;
	f64x3x3 ret;
	ret.cols[0].x = s[0] * inv_det;
	ret.cols[0].y = (m.cols[0].z * m.cols[2].y - m.cols[0].y * m.cols[2].z) * inv_det;
	ret.cols[0].z = (m.cols[0].y * m.cols[1].z - m.cols[0].z * m.cols[1].y) * inv_det;

	ret.cols[1].x = -s[1] * inv_det;
	ret.cols[1].y = (m.cols[0].x * m.cols[2].z - m.cols[0].z * m.cols[2].x) * inv_det;
	ret.cols[1].z = (m.cols[1].x * m.cols[0].z - m.cols[0].x * m.cols[1].z) * inv_det;

	ret.cols[2].x = s[2] * inv_det;
	ret.cols[2].y = (m.cols[2].x * m.cols[0].y - m.cols[0].x * m.cols[2].y) * inv_det;
	ret.cols[2].z = (m.cols[0].x * m.cols[1].y - m.cols[1].x * m.cols[0].y) * inv_det;
	return ret;
}
f32x4x4 inverse_f32x4x4(f32x4x4 m) {
	float s[6];
	float c[6];

	s[0] = m.cols[0].x*m.cols[1].y - m.cols[1].x*m.cols[0].y;
	s[1] = m.cols[0].x*m.cols[1].z - m.cols[1].x*m.cols[0].z;
	s[2] = m.cols[0].x*m.cols[1].w - m.cols[1].x*m.cols[0].w;
	s[3] = m.cols[0].y*m.cols[1].z - m.cols[1].y*m.cols[0].z;
	s[4] = m.cols[0].y*m.cols[1].w - m.cols[1].y*m.cols[0].w;
	s[5] = m.cols[0].z*m.cols[1].w - m.cols[1].z*m.cols[0].w;

	c[0] = m.cols[2].x*m.cols[3].y - m.cols[3].x*m.cols[2].y;
	c[1] = m.cols[2].x*m.cols[3].z - m.cols[3].x*m.cols[2].z;
	c[2] = m.cols[2].x*m.cols[3].w - m.cols[3].x*m.cols[2].w;
	c[3] = m.cols[2].y*m.cols[3].z - m.cols[3].y*m.cols[2].z;
	c[4] = m.cols[2].y*m.cols[3].w - m.cols[3].y*m.cols[2].w;
	c[5] = m.cols[2].z*m.cols[3].w - m.cols[3].z*m.cols[2].w;

	float det = s[0]*c[5]-s[1]*c[4]+s[2]*c[3]+s[3]*c[2]-s[4]*c[1]+s[5]*c[0];
	float inv_det = 1.f / det;
	f32x4x4 ret;
	ret.cols[0].x = ( m.cols[1].y * c[5] - m.cols[1].z * c[4] + m.cols[1].w * c[3]) * inv_det;
	ret.cols[0].y = (-m.cols[0].y * c[5] + m.cols[0].z * c[4] - m.cols[0].w * c[3]) * inv_det;
	ret.cols[0].z = ( m.cols[3].y * s[5] - m.cols[3].z * s[4] + m.cols[3].w * s[3]) * inv_det;
	ret.cols[0].w = (-m.cols[2].y * s[5] + m.cols[2].z * s[4] - m.cols[2].w * s[3]) * inv_det;

	ret.cols[1].x = (-m.cols[1].x * c[5] + m.cols[1].z * c[2] - m.cols[1].w * c[1]) * inv_det;
	ret.cols[1].y = ( m.cols[0].x * c[5] - m.cols[0].z * c[2] + m.cols[0].w * c[1]) * inv_det;
	ret.cols[1].z = (-m.cols[3].x * s[5] + m.cols[3].z * s[2] - m.cols[3].w * s[1]) * inv_det;
	ret.cols[1].w = ( m.cols[2].x * s[5] - m.cols[2].z * s[2] + m.cols[2].w * s[1]) * inv_det;

	ret.cols[2].x = ( m.cols[1].x * c[4] - m.cols[1].y * c[2] + m.cols[1].w * c[0]) * inv_det;
	ret.cols[2].y = (-m.cols[0].x * c[4] + m.cols[0].y * c[2] - m.cols[0].w * c[0]) * inv_det;
	ret.cols[2].z = ( m.cols[3].x * s[4] - m.cols[3].y * s[2] + m.cols[3].w * s[0]) * inv_det;
	ret.cols[2].w = (-m.cols[2].x * s[4] + m.cols[2].y * s[2] - m.cols[2].w * s[0]) * inv_det;

	ret.cols[3].x = (-m.cols[1].x * c[3] + m.cols[1].y * c[1] - m.cols[1].z * c[0]) * inv_det;
	ret.cols[3].y = ( m.cols[0].x * c[3] - m.cols[0].y * c[1] + m.cols[0].z * c[0]) * inv_det;
	ret.cols[3].z = (-m.cols[3].x * s[3] + m.cols[3].y * s[1] - m.cols[3].z * s[0]) * inv_det;
	ret.cols[3].w = ( m.cols[2].x * s[3] - m.cols[2].y * s[1] + m.cols[2].z * s[0]) * inv_det;
	return ret;
}
f64x4x4 inverse_f64x4x4(f64x4x4 m) {
	double s[6];
	double c[6];

	s[0] = m.cols[0].x*m.cols[1].y - m.cols[1].x*m.cols[0].y;
	s[1] = m.cols[0].x*m.cols[1].z - m.cols[1].x*m.cols[0].z;
	s[2] = m.cols[0].x*m.cols[1].w - m.cols[1].x*m.cols[0].w;
	s[3] = m.cols[0].y*m.cols[1].z - m.cols[1].y*m.cols[0].z;
	s[4] = m.cols[0].y*m.cols[1].w - m.cols[1].y*m.cols[0].w;
	s[5] = m.cols[0].z*m.cols[1].w - m.cols[1].z*m.cols[0].w;

	c[0] = m.cols[2].x*m.cols[3].y - m.cols[3].x*m.cols[2].y;
	c[1] = m.cols[2].x*m.cols[3].z - m.cols[3].x*m.cols[2].z;
	c[2] = m.cols[2].x*m.cols[3].w - m.cols[3].x*m.cols[2].w;
	c[3] = m.cols[2].y*m.cols[3].z - m.cols[3].y*m.cols[2].z;
	c[4] = m.cols[2].y*m.cols[3].w - m.cols[3].y*m.cols[2].w;
	c[5] = m.cols[2].z*m.cols[3].w - m.cols[3].z*m.cols[2].w;

	double det = s[0]*c[5]-s[1]*c[4]+s[2]*c[3]+s[3]*c[2]-s[4]*c[1]+s[5]*c[0];
	double inv_det = 1.f / det;
	f64x4x4 ret;
	ret.cols[0].x = ( m.cols[1].y * c[5] - m.cols[1].z * c[4] + m.cols[1].w * c[3]) * inv_det;
	ret.cols[0].y = (-m.cols[0].y * c[5] + m.cols[0].z * c[4] - m.cols[0].w * c[3]) * inv_det;
	ret.cols[0].z = ( m.cols[3].y * s[5] - m.cols[3].z * s[4] + m.cols[3].w * s[3]) * inv_det;
	ret.cols[0].w = (-m.cols[2].y * s[5] + m.cols[2].z * s[4] - m.cols[2].w * s[3]) * inv_det;

	ret.cols[1].x = (-m.cols[1].x * c[5] + m.cols[1].z * c[2] - m.cols[1].w * c[1]) * inv_det;
	ret.cols[1].y = ( m.cols[0].x * c[5] - m.cols[0].z * c[2] + m.cols[0].w * c[1]) * inv_det;
	ret.cols[1].z = (-m.cols[3].x * s[5] + m.cols[3].z * s[2] - m.cols[3].w * s[1]) * inv_det;
	ret.cols[1].w = ( m.cols[2].x * s[5] - m.cols[2].z * s[2] + m.cols[2].w * s[1]) * inv_det;

	ret.cols[2].x = ( m.cols[1].x * c[4] - m.cols[1].y * c[2] + m.cols[1].w * c[0]) * inv_det;
	ret.cols[2].y = (-m.cols[0].x * c[4] + m.cols[0].y * c[2] - m.cols[0].w * c[0]) * inv_det;
	ret.cols[2].z = ( m.cols[3].x * s[4] - m.cols[3].y * s[2] + m.cols[3].w * s[0]) * inv_det;
	ret.cols[2].w = (-m.cols[2].x * s[4] + m.cols[2].y * s[2] - m.cols[2].w * s[0]) * inv_det;

	ret.cols[3].x = (-m.cols[1].x * c[3] + m.cols[1].y * c[1] - m.cols[1].z * c[0]) * inv_det;
	ret.cols[3].y = ( m.cols[0].x * c[3] - m.cols[0].y * c[1] + m.cols[0].z * c[0]) * inv_det;
	ret.cols[3].z = (-m.cols[3].x * s[3] + m.cols[3].y * s[1] - m.cols[3].z * s[0]) * inv_det;
	ret.cols[3].w = ( m.cols[2].x * s[3] - m.cols[2].y * s[1] + m.cols[2].z * s[0]) * inv_det;
	return ret;
}
