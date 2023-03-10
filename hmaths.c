#include "hmaths.h"

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
// Vector
//
//
// ===========================================
//
// these vectors have scalar alignment where their alignment is the same as their scalar type
// on the HCC and Clang compilers they will use vector extensions for +-*/ operator support and swizzling
//


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
		((uint32_t)bitsfrom_f16(f32tof16(v.x)) << 0)  ||
	((uint32_t)bitsfrom_f16(f32tof16(v.y)) << 16)  ;
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
		((uint32_t)v.x << 0) ||
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
		((uint32_t)(uint16_t)(int16_t)v.x << 0) ||
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
		((uint32_t)v.x << 0)  ||
		((uint32_t)v.y << 8)  ||
		((uint32_t)v.z << 16) ||
		((uint32_t)v.w << 24)  ;
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
		((uint32_t)(uint8_t)(int8_t)v.x << 0)  ||
		((uint32_t)(uint8_t)(int8_t)v.y << 8)  ||
		((uint32_t)(uint8_t)(int8_t)v.z << 16) ||
		((uint32_t)(uint8_t)(int8_t)v.w << 24)  ;
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
f32x2x3 mul_f32x2x3_f32x3x2(f32x2x3 a, f32x3x2 b) {
	f32x2x3 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y;
	return m;
}
f64x2x3 mul_f64x2x3_f64x3x2(f64x2x3 a, f64x3x2 b) {
	f64x2x3 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y;
	return m;
}
f32x2x4 mul_f32x2x4_f32x4x2(f32x2x4 a, f32x4x2 b) {
	f32x2x4 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y;
	m.cols[0].w = a.cols[0].w * b.cols[0].x + a.cols[1].w * b.cols[0].y;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y;
	m.cols[1].w = a.cols[0].w * b.cols[1].x + a.cols[1].w * b.cols[1].y;
	return m;
}
f64x2x4 mul_f64x2x4_f64x4x2(f64x2x4 a, f64x4x2 b) {
	f64x2x4 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y;
	m.cols[0].w = a.cols[0].w * b.cols[0].x + a.cols[1].w * b.cols[0].y;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y;
	m.cols[1].w = a.cols[0].w * b.cols[1].x + a.cols[1].w * b.cols[1].y;
	return m;
}
f32x3x2 mul_f32x3x2_f32x2x3(f32x3x2 a, f32x2x3 b) {
	f32x3x2 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z;
	return m;
}
f64x3x2 mul_f64x3x2_f64x2x3(f64x3x2 a, f64x2x3 b) {
	f64x3x2 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z;
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
f32x3x4 mul_f32x3x4_f32x4x3(f32x3x4 a, f32x4x3 b) {
	f32x3x4 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z;
	m.cols[0].w = a.cols[0].w * b.cols[0].x + a.cols[1].w * b.cols[0].y + a.cols[2].w * b.cols[0].z;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z;
	m.cols[1].w = a.cols[0].w * b.cols[1].x + a.cols[1].w * b.cols[1].y + a.cols[2].w * b.cols[1].z;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z;
	m.cols[2].w = a.cols[0].w * b.cols[2].x + a.cols[1].w * b.cols[2].y + a.cols[2].w * b.cols[2].z;
	return m;
}
f64x3x4 mul_f64x3x4_f64x4x3(f64x3x4 a, f64x4x3 b) {
	f64x3x4 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z;
	m.cols[0].w = a.cols[0].w * b.cols[0].x + a.cols[1].w * b.cols[0].y + a.cols[2].w * b.cols[0].z;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z;
	m.cols[1].w = a.cols[0].w * b.cols[1].x + a.cols[1].w * b.cols[1].y + a.cols[2].w * b.cols[1].z;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z;
	m.cols[2].w = a.cols[0].w * b.cols[2].x + a.cols[1].w * b.cols[2].y + a.cols[2].w * b.cols[2].z;
	return m;
}
f32x4x2 mul_f32x4x2_f32x2x4(f32x4x2 a, f32x2x4 b) {
	f32x4x2 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z + a.cols[3].x * b.cols[0].w;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z + a.cols[3].y * b.cols[0].w;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z + a.cols[3].x * b.cols[1].w;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z + a.cols[3].y * b.cols[1].w;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z + a.cols[3].x * b.cols[2].w;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z + a.cols[3].y * b.cols[2].w;
	m.cols[3].x = a.cols[0].x * b.cols[3].x + a.cols[1].x * b.cols[3].y + a.cols[2].x * b.cols[3].z + a.cols[3].x * b.cols[3].w;
	m.cols[3].y = a.cols[0].y * b.cols[3].x + a.cols[1].y * b.cols[3].y + a.cols[2].y * b.cols[3].z + a.cols[3].y * b.cols[3].w;
	return m;
}
f64x4x2 mul_f64x4x2_f64x2x4(f64x4x2 a, f64x2x4 b) {
	f64x4x2 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z + a.cols[3].x * b.cols[0].w;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z + a.cols[3].y * b.cols[0].w;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z + a.cols[3].x * b.cols[1].w;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z + a.cols[3].y * b.cols[1].w;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z + a.cols[3].x * b.cols[2].w;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z + a.cols[3].y * b.cols[2].w;
	m.cols[3].x = a.cols[0].x * b.cols[3].x + a.cols[1].x * b.cols[3].y + a.cols[2].x * b.cols[3].z + a.cols[3].x * b.cols[3].w;
	m.cols[3].y = a.cols[0].y * b.cols[3].x + a.cols[1].y * b.cols[3].y + a.cols[2].y * b.cols[3].z + a.cols[3].y * b.cols[3].w;
	return m;
}
f32x4x3 mul_f32x4x3_f32x3x4(f32x4x3 a, f32x3x4 b) {
	f32x4x3 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z + a.cols[3].x * b.cols[0].w;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z + a.cols[3].y * b.cols[0].w;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z + a.cols[3].z * b.cols[0].w;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z + a.cols[3].x * b.cols[1].w;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z + a.cols[3].y * b.cols[1].w;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z + a.cols[3].z * b.cols[1].w;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z + a.cols[3].x * b.cols[2].w;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z + a.cols[3].y * b.cols[2].w;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z + a.cols[3].z * b.cols[2].w;
	m.cols[3].x = a.cols[0].x * b.cols[3].x + a.cols[1].x * b.cols[3].y + a.cols[2].x * b.cols[3].z + a.cols[3].x * b.cols[3].w;
	m.cols[3].y = a.cols[0].y * b.cols[3].x + a.cols[1].y * b.cols[3].y + a.cols[2].y * b.cols[3].z + a.cols[3].y * b.cols[3].w;
	m.cols[3].z = a.cols[0].z * b.cols[3].x + a.cols[1].z * b.cols[3].y + a.cols[2].z * b.cols[3].z + a.cols[3].z * b.cols[3].w;
	return m;
}
f64x4x3 mul_f64x4x3_f64x3x4(f64x4x3 a, f64x3x4 b) {
	f64x4x3 m;
	m.cols[0].x = a.cols[0].x * b.cols[0].x + a.cols[1].x * b.cols[0].y + a.cols[2].x * b.cols[0].z + a.cols[3].x * b.cols[0].w;
	m.cols[0].y = a.cols[0].y * b.cols[0].x + a.cols[1].y * b.cols[0].y + a.cols[2].y * b.cols[0].z + a.cols[3].y * b.cols[0].w;
	m.cols[0].z = a.cols[0].z * b.cols[0].x + a.cols[1].z * b.cols[0].y + a.cols[2].z * b.cols[0].z + a.cols[3].z * b.cols[0].w;
	m.cols[1].x = a.cols[0].x * b.cols[1].x + a.cols[1].x * b.cols[1].y + a.cols[2].x * b.cols[1].z + a.cols[3].x * b.cols[1].w;
	m.cols[1].y = a.cols[0].y * b.cols[1].x + a.cols[1].y * b.cols[1].y + a.cols[2].y * b.cols[1].z + a.cols[3].y * b.cols[1].w;
	m.cols[1].z = a.cols[0].z * b.cols[1].x + a.cols[1].z * b.cols[1].y + a.cols[2].z * b.cols[1].z + a.cols[3].z * b.cols[1].w;
	m.cols[2].x = a.cols[0].x * b.cols[2].x + a.cols[1].x * b.cols[2].y + a.cols[2].x * b.cols[2].z + a.cols[3].x * b.cols[2].w;
	m.cols[2].y = a.cols[0].y * b.cols[2].x + a.cols[1].y * b.cols[2].y + a.cols[2].y * b.cols[2].z + a.cols[3].y * b.cols[2].w;
	m.cols[2].z = a.cols[0].z * b.cols[2].x + a.cols[1].z * b.cols[2].y + a.cols[2].z * b.cols[2].z + a.cols[3].z * b.cols[2].w;
	m.cols[3].x = a.cols[0].x * b.cols[3].x + a.cols[1].x * b.cols[3].y + a.cols[2].x * b.cols[3].z + a.cols[3].x * b.cols[3].w;
	m.cols[3].y = a.cols[0].y * b.cols[3].x + a.cols[1].y * b.cols[3].y + a.cols[2].y * b.cols[3].z + a.cols[3].y * b.cols[3].w;
	m.cols[3].z = a.cols[0].z * b.cols[3].x + a.cols[1].z * b.cols[3].y + a.cols[2].z * b.cols[3].z + a.cols[3].z * b.cols[3].w;
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
f32x2x3 muls_f32x2x3(f32x2x3 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	return m;
}
f64x2x3 muls_f64x2x3(f64x2x3 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	return m;
}
f32x2x4 muls_f32x2x4(f32x2x4 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[0].w *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[1].w *= s;
	return m;
}
f64x2x4 muls_f64x2x4(f64x2x4 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[0].w *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[1].w *= s;
	return m;
}
f32x3x2 muls_f32x3x2(f32x3x2 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	return m;
}
f64x3x2 muls_f64x3x2(f64x3x2 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
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
f32x3x4 muls_f32x3x4(f32x3x4 m, float s) {
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
	return m;
}
f64x3x4 muls_f64x3x4(f64x3x4 m, double s) {
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
	return m;
}
f32x4x2 muls_f32x4x2(f32x4x2 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[3].x *= s;
	m.cols[3].y *= s;
	return m;
}
f64x4x2 muls_f64x4x2(f64x4x2 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[3].x *= s;
	m.cols[3].y *= s;
	return m;
}
f32x4x3 muls_f32x4x3(f32x4x3 m, float s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[2].z *= s;
	m.cols[3].x *= s;
	m.cols[3].y *= s;
	m.cols[3].z *= s;
	return m;
}
f64x4x3 muls_f64x4x3(f64x4x3 m, double s) {
	m.cols[0].x *= s;
	m.cols[0].y *= s;
	m.cols[0].z *= s;
	m.cols[1].x *= s;
	m.cols[1].y *= s;
	m.cols[1].z *= s;
	m.cols[2].x *= s;
	m.cols[2].y *= s;
	m.cols[2].z *= s;
	m.cols[3].x *= s;
	m.cols[3].y *= s;
	m.cols[3].z *= s;
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
f32x2 mul_f32x2x3_f32x2(f32x2x3 m, f32x2 v) {
	f32x2 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y;
	return ret;
}
f64x2 mul_f64x2x3_f64x2(f64x2x3 m, f64x2 v) {
	f64x2 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y;
	return ret;
}
f32x2 mul_f32x2x4_f32x2(f32x2x4 m, f32x2 v) {
	f32x2 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y;
	return ret;
}
f64x2 mul_f64x2x4_f64x2(f64x2x4 m, f64x2 v) {
	f64x2 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y;
	return ret;
}
f32x3 mul_f32x3x2_f32x3(f32x3x2 m, f32x3 v) {
	f32x3 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z;
	return ret;
}
f64x3 mul_f64x3x2_f64x3(f64x3x2 m, f64x3 v) {
	f64x3 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z;
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
f32x3 mul_f32x3x4_f32x3(f32x3x4 m, f32x3 v) {
	f32x3 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z;
	return ret;
}
f64x3 mul_f64x3x4_f64x3(f64x3x4 m, f64x3 v) {
	f64x3 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z;
	return ret;
}
f32x4 mul_f32x4x2_f32x4(f32x4x2 m, f32x4 v) {
	f32x4 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z + m.cols[3].x * v.w;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z + m.cols[3].y * v.w;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z + m.cols[3].z * v.w;
	ret.w = m.cols[0].w * v.x + m.cols[1].w * v.y + m.cols[2].w * v.z + m.cols[3].w * v.w;
	return ret;
}
f64x4 mul_f64x4x2_f64x4(f64x4x2 m, f64x4 v) {
	f64x4 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z + m.cols[3].x * v.w;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z + m.cols[3].y * v.w;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z + m.cols[3].z * v.w;
	ret.w = m.cols[0].w * v.x + m.cols[1].w * v.y + m.cols[2].w * v.z + m.cols[3].w * v.w;
	return ret;
}
f32x4 mul_f32x4x3_f32x4(f32x4x3 m, f32x4 v) {
	f32x4 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z + m.cols[3].x * v.w;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z + m.cols[3].y * v.w;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z + m.cols[3].z * v.w;
	ret.w = m.cols[0].w * v.x + m.cols[1].w * v.y + m.cols[2].w * v.z + m.cols[3].w * v.w;
	return ret;
}
f64x4 mul_f64x4x3_f64x4(f64x4x3 m, f64x4 v) {
	f64x4 ret;
	ret.x = m.cols[0].x * v.x + m.cols[1].x * v.y + m.cols[2].x * v.z + m.cols[3].x * v.w;
	ret.y = m.cols[0].y * v.x + m.cols[1].y * v.y + m.cols[2].y * v.z + m.cols[3].y * v.w;
	ret.z = m.cols[0].z * v.x + m.cols[1].z * v.y + m.cols[2].z * v.z + m.cols[3].z * v.w;
	ret.w = m.cols[0].w * v.x + m.cols[1].w * v.y + m.cols[2].w * v.z + m.cols[3].w * v.w;
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
f32x3 mul_f32x3_f32x2x3(f32x3 v, f32x2x3 m) {
	f32x3 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y;
	return ret;
}
f64x3 mul_f64x3_f64x2x3(f64x3 v, f64x2x3 m) {
	f64x3 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y;
	return ret;
}
f32x4 mul_f32x4_f32x2x4(f32x4 v, f32x2x4 m) {
	f32x4 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y;
	ret.w = v.x * m.cols[3].x + v.y * m.cols[3].y;
	return ret;
}
f64x4 mul_f64x4_f64x2x4(f64x4 v, f64x2x4 m) {
	f64x4 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y;
	ret.w = v.x * m.cols[3].x + v.y * m.cols[3].y;
	return ret;
}
f32x2 mul_f32x2_f32x3x2(f32x2 v, f32x3x2 m) {
	f32x2 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z;
	return ret;
}
f64x2 mul_f64x2_f64x3x2(f64x2 v, f64x3x2 m) {
	f64x2 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z;
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
f32x4 mul_f32x4_f32x3x4(f32x4 v, f32x3x4 m) {
	f32x4 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z;
	ret.w = v.x * m.cols[3].x + v.y * m.cols[3].y + v.z * m.cols[3].z;
	return ret;
}
f64x4 mul_f64x4_f64x3x4(f64x4 v, f64x3x4 m) {
	f64x4 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z;
	ret.w = v.x * m.cols[3].x + v.y * m.cols[3].y + v.z * m.cols[3].z;
	return ret;
}
f32x2 mul_f32x2_f32x4x2(f32x2 v, f32x4x2 m) {
	f32x2 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z + v.w * m.cols[0].w;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z + v.w * m.cols[1].w;
	return ret;
}
f64x2 mul_f64x2_f64x4x2(f64x2 v, f64x4x2 m) {
	f64x2 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z + v.w * m.cols[0].w;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z + v.w * m.cols[1].w;
	return ret;
}
f32x3 mul_f32x3_f32x4x3(f32x3 v, f32x4x3 m) {
	f32x3 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z + v.w * m.cols[0].w;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z + v.w * m.cols[1].w;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z + v.w * m.cols[2].w;
	return ret;
}
f64x3 mul_f64x3_f64x4x3(f64x3 v, f64x4x3 m) {
	f64x3 ret;
	ret.x = v.x * m.cols[0].x + v.y * m.cols[0].y + v.z * m.cols[0].z + v.w * m.cols[0].w;
	ret.y = v.x * m.cols[1].x + v.y * m.cols[1].y + v.z * m.cols[1].z + v.w * m.cols[1].w;
	ret.z = v.x * m.cols[2].x + v.y * m.cols[2].y + v.z * m.cols[2].z + v.w * m.cols[2].w;
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
f32x3x2 transpose_f32x2x3(f32x2x3 m) {
	f32x3x2 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	return ret;
}
f64x3x2 transpose_f64x2x3(f64x2x3 m) {
	f64x3x2 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	return ret;
}
f32x4x2 transpose_f32x2x4(f32x2x4 m) {
	f32x4x2 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[3].x = m.cols[0].w;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[3].y = m.cols[1].w;
	return ret;
}
f64x4x2 transpose_f64x2x4(f64x2x4 m) {
	f64x4x2 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[3].x = m.cols[0].w;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[3].y = m.cols[1].w;
	return ret;
}
f32x2x3 transpose_f32x3x2(f32x3x2 m) {
	f32x2x3 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	return ret;
}
f64x2x3 transpose_f64x3x2(f64x3x2 m) {
	f64x2x3 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
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
f32x4x3 transpose_f32x3x4(f32x3x4 m) {
	f32x4x3 ret;
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
	return ret;
}
f64x4x3 transpose_f64x3x4(f64x3x4 m) {
	f64x4x3 ret;
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
	return ret;
}
f32x2x4 transpose_f32x4x2(f32x4x2 m) {
	f32x2x4 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[0].w = m.cols[3].x;
	ret.cols[1].w = m.cols[3].y;
	return ret;
}
f64x2x4 transpose_f64x4x2(f64x4x2 m) {
	f64x2x4 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[0].w = m.cols[3].x;
	ret.cols[1].w = m.cols[3].y;
	return ret;
}
f32x3x4 transpose_f32x4x3(f32x4x3 m) {
	f32x3x4 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[2].z = m.cols[2].z;
	ret.cols[0].w = m.cols[3].x;
	ret.cols[1].w = m.cols[3].y;
	ret.cols[2].w = m.cols[3].z;
	return ret;
}
f64x3x4 transpose_f64x4x3(f64x4x3 m) {
	f64x3x4 ret;
	ret.cols[0].x = m.cols[0].x;
	ret.cols[1].x = m.cols[0].y;
	ret.cols[2].x = m.cols[0].z;
	ret.cols[0].y = m.cols[1].x;
	ret.cols[1].y = m.cols[1].y;
	ret.cols[2].y = m.cols[1].z;
	ret.cols[0].z = m.cols[2].x;
	ret.cols[1].z = m.cols[2].y;
	ret.cols[2].z = m.cols[2].z;
	ret.cols[0].w = m.cols[3].x;
	ret.cols[1].w = m.cols[3].y;
	ret.cols[2].w = m.cols[3].z;
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
f32x2x2 outerproduct_f32x2_f32x2(f32x2 c, f32x2 r) {
	f32x2x2 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	return ret;
}
f64x2x2 outerproduct_f64x2_f64x2(f64x2 c, f64x2 r) {
	f64x2x2 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	return ret;
}
f32x2x3 outerproduct_f32x2_f32x3(f32x2 c, f32x3 r) {
	f32x2x3 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	return ret;
}
f64x2x3 outerproduct_f64x2_f64x3(f64x2 c, f64x3 r) {
	f64x2x3 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	return ret;
}
f32x2x4 outerproduct_f32x2_f32x4(f32x2 c, f32x4 r) {
	f32x2x4 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[0].w = c.x * r.w;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[1].w = c.y * r.w;
	return ret;
}
f64x2x4 outerproduct_f64x2_f64x4(f64x2 c, f64x4 r) {
	f64x2x4 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[0].w = c.x * r.w;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[1].w = c.y * r.w;
	return ret;
}
f32x3x2 outerproduct_f32x3_f32x2(f32x3 c, f32x2 r) {
	f32x3x2 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	return ret;
}
f64x3x2 outerproduct_f64x3_f64x2(f64x3 c, f64x2 r) {
	f64x3x2 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	return ret;
}
f32x3x3 outerproduct_f32x3_f32x3(f32x3 c, f32x3 r) {
	f32x3x3 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	return ret;
}
f64x3x3 outerproduct_f64x3_f64x3(f64x3 c, f64x3 r) {
	f64x3x3 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	return ret;
}
f32x3x4 outerproduct_f32x3_f32x4(f32x3 c, f32x4 r) {
	f32x3x4 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[0].w = c.x * r.w;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[1].w = c.y * r.w;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	ret.cols[2].w = c.z * r.w;
	return ret;
}
f64x3x4 outerproduct_f64x3_f64x4(f64x3 c, f64x4 r) {
	f64x3x4 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[0].w = c.x * r.w;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[1].w = c.y * r.w;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	ret.cols[2].w = c.z * r.w;
	return ret;
}
f32x4x2 outerproduct_f32x4_f32x2(f32x4 c, f32x2 r) {
	f32x4x2 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[3].x = c.w * r.x;
	ret.cols[3].y = c.w * r.y;
	return ret;
}
f64x4x2 outerproduct_f64x4_f64x2(f64x4 c, f64x2 r) {
	f64x4x2 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[3].x = c.w * r.x;
	ret.cols[3].y = c.w * r.y;
	return ret;
}
f32x4x3 outerproduct_f32x4_f32x3(f32x4 c, f32x3 r) {
	f32x4x3 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	ret.cols[3].x = c.w * r.x;
	ret.cols[3].y = c.w * r.y;
	ret.cols[3].z = c.w * r.z;
	return ret;
}
f64x4x3 outerproduct_f64x4_f64x3(f64x4 c, f64x3 r) {
	f64x4x3 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	ret.cols[3].x = c.w * r.x;
	ret.cols[3].y = c.w * r.y;
	ret.cols[3].z = c.w * r.z;
	return ret;
}
f32x4x4 outerproduct_f32x4_f32x4(f32x4 c, f32x4 r) {
	f32x4x4 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[0].w = c.x * r.w;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[1].w = c.y * r.w;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	ret.cols[2].w = c.z * r.w;
	ret.cols[3].x = c.w * r.x;
	ret.cols[3].y = c.w * r.y;
	ret.cols[3].z = c.w * r.z;
	ret.cols[3].w = c.w * r.w;
	return ret;
}
f64x4x4 outerproduct_f64x4_f64x4(f64x4 c, f64x4 r) {
	f64x4x4 ret;
	ret.cols[0].x = c.x * r.x;
	ret.cols[0].y = c.x * r.y;
	ret.cols[0].z = c.x * r.z;
	ret.cols[0].w = c.x * r.w;
	ret.cols[1].x = c.y * r.x;
	ret.cols[1].y = c.y * r.y;
	ret.cols[1].z = c.y * r.z;
	ret.cols[1].w = c.y * r.w;
	ret.cols[2].x = c.z * r.x;
	ret.cols[2].y = c.z * r.y;
	ret.cols[2].z = c.z * r.z;
	ret.cols[2].w = c.z * r.w;
	ret.cols[3].x = c.w * r.x;
	ret.cols[3].y = c.w * r.y;
	ret.cols[3].z = c.w * r.z;
	ret.cols[3].w = c.w * r.w;
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
