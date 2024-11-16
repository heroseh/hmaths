#ifndef _HMATHS_TYPES_H_
#define _HMATHS_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

#ifndef HMATHS_ENABLE_VECTOR_EXTENSIONS
#if defined(__HCC__)
#define HMATHS_ENABLE_VECTOR_EXTENSIONS 1
#else
#define HMATHS_ENABLE_VECTOR_EXTENSIONS 0
#endif
#endif

#if HMATHS_ENABLE_VECTOR_EXTENSIONS
#if defined(__HCC__)
#define HMATHS_DEFINE_VECTOR(vector_t, scalar_t, num_comps) typedef __hcc_vector_t(scalar_t, num_comps) vector_t
#endif
#endif

#if defined(__HCC__)
typedef __hcc_half_t half;
#define HALF_CONST(lit, bits) (lit)
#define HMATHS_NATIVE_F16_SUPPORT
#elif defined(__clang__) && !defined(_WIN32)
typedef _Float16 half;
#define HALF_CONST(lit, bits) (lit)
#define HMATHS_NATIVE_F16_SUPPORT
#else
typedef struct half { uint16_t _bits; } half;
#define HALF_CONST(lit, bits_) ((half) { .bits = bits_ })
#endif

// ===========================================
//
//
// Scalar
//
//
// ===========================================

#define PI_F16 HALF_CONST(3.14159265358979323846f16, 0x4248)
#define PI_F32 3.14159265358979323846f
#define PI_F64 3.14159265358979323846
#define INFINITY_F16 HALF_CONST(1.f16 / 0.f16, 0x7c00)
#define INFINITY_F32 (1.f / 0.f)
#define INFINITY_F64 (1.0 / 0.0)
#define NAN_F16 HALF_CONST(0.f16 / 0.f16, 0xfc00)
#define NAN_F32 (0.f / 0.f)
#define NAN_F64 (0.0 / 0.0)

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

#if HMATHS_ENABLE_VECTOR_EXTENSIONS
HMATHS_DEFINE_VECTOR(f16x2, half, 2);
HMATHS_DEFINE_VECTOR(f32x2, float, 2);
HMATHS_DEFINE_VECTOR(f64x2, double, 2);
HMATHS_DEFINE_VECTOR(s8x2, int8_t, 2);
HMATHS_DEFINE_VECTOR(s16x2, int16_t, 2);
HMATHS_DEFINE_VECTOR(s32x2, int32_t, 2);
HMATHS_DEFINE_VECTOR(s64x2, int64_t, 2);
HMATHS_DEFINE_VECTOR(u8x2, uint8_t, 2);
HMATHS_DEFINE_VECTOR(u16x2, uint16_t, 2);
HMATHS_DEFINE_VECTOR(u32x2, uint32_t, 2);
HMATHS_DEFINE_VECTOR(u64x2, uint64_t, 2);

HMATHS_DEFINE_VECTOR(f16x3, half, 3);
HMATHS_DEFINE_VECTOR(f32x3, float, 3);
HMATHS_DEFINE_VECTOR(f64x3, double, 3);
HMATHS_DEFINE_VECTOR(s8x3, int8_t, 3);
HMATHS_DEFINE_VECTOR(s16x3, int16_t, 3);
HMATHS_DEFINE_VECTOR(s32x3, int32_t, 3);
HMATHS_DEFINE_VECTOR(s64x3, int64_t, 3);
HMATHS_DEFINE_VECTOR(u8x3, uint8_t, 3);
HMATHS_DEFINE_VECTOR(u16x3, uint16_t, 3);
HMATHS_DEFINE_VECTOR(u32x3, uint32_t, 3);
HMATHS_DEFINE_VECTOR(u64x3, uint64_t, 3);

HMATHS_DEFINE_VECTOR(f16x4, half, 4);
HMATHS_DEFINE_VECTOR(f32x4, float, 4);
HMATHS_DEFINE_VECTOR(f64x4, double, 4);
HMATHS_DEFINE_VECTOR(s8x4, int8_t, 4);
HMATHS_DEFINE_VECTOR(s16x4, int16_t, 4);
HMATHS_DEFINE_VECTOR(s32x4, int32_t, 4);
HMATHS_DEFINE_VECTOR(s64x4, int64_t, 4);
HMATHS_DEFINE_VECTOR(u8x4, uint8_t, 4);
HMATHS_DEFINE_VECTOR(u16x4, uint16_t, 4);
HMATHS_DEFINE_VECTOR(u32x4, uint32_t, 4);
HMATHS_DEFINE_VECTOR(u64x4, uint64_t, 4);

#else //!HMATHS_ENABLE_VECTOR_EXTENSIONS

typedef struct f16x2 f16x2;
typedef struct f32x2 f32x2;
typedef struct f64x2 f64x2;
typedef struct s8x2 s8x2;
typedef struct s16x2 s16x2;
typedef struct s32x2 s32x2;
typedef struct s64x2 s64x2;
typedef struct u8x2 u8x2;
typedef struct u16x2 u16x2;
typedef struct u32x2 u32x2;
typedef struct u64x2 u64x2;

typedef struct f16x3 f16x3;
typedef struct f32x3 f32x3;
typedef struct f64x3 f64x3;
typedef struct s8x3 s8x3;
typedef struct s16x3 s16x3;
typedef struct s32x3 s32x3;
typedef struct s64x3 s64x3;
typedef struct u8x3 u8x3;
typedef struct u16x3 u16x3;
typedef struct u32x3 u32x3;
typedef struct u64x3 u64x3;

typedef struct f16x4 f16x4;
typedef struct f32x4 f32x4;
typedef struct f64x4 f64x4;
typedef struct s8x4 s8x4;
typedef struct s16x4 s16x4;
typedef struct s32x4 s32x4;
typedef struct s64x4 s64x4;
typedef struct u8x4 u8x4;
typedef struct u16x4 u16x4;
typedef struct u32x4 u32x4;
typedef struct u64x4 u64x4;

struct f16x2 {
	union {
		struct { half x; half y; };
		struct { half r; half g; };
	};
};

struct f32x2 {
	union {
		struct { float x; float y; };
		struct { float r; float g; };
	};
};

struct f64x2 {
	union {
		struct { double x; double y; };
		struct { double r; double g; };
	};
};

struct s8x2 {
	union {
		struct { int8_t x; int8_t y; };
		struct { int8_t r; int8_t g; };
	};
};

struct s16x2 {
	union {
		struct { int16_t x; int16_t y; };
		struct { int16_t r; int16_t g; };
	};
};

struct s32x2 {
	union {
		struct { int32_t x; int32_t y; };
		struct { int32_t r; int32_t g; };
	};
};

struct s64x2 {
	union {
		struct { int64_t x; int64_t y; };
		struct { int64_t r; int64_t g; };
	};
};

struct u8x2 {
	union {
		struct { uint8_t x; uint8_t y; };
		struct { uint8_t r; uint8_t g; };
	};
};

struct u16x2 {
	union {
		struct { uint16_t x; uint16_t y; };
		struct { uint16_t r; uint16_t g; };
	};
};

struct u32x2 {
	union {
		struct { uint32_t x; uint32_t y; };
		struct { uint32_t r; uint32_t g; };
	};
};

struct u64x2 {
	union {
		struct { uint64_t x; uint64_t y; };
		struct { uint64_t r; uint64_t g; };
	};
};

struct f16x3 {
	union {
		struct { half x; half y; half z; };
		struct { half r; half g; half b; };
		f16x2 xy;
		struct { half _; f16x2 yz; };
		f16x2 rg;
		struct { half __; f16x2 gb; };
	};
};

struct f32x3 {
	union {
		struct { float x; float y; float z; };
		struct { float r; float g; float b; };
		f32x2 xy;
		struct { float _; f32x2 yz; };
		f32x2 rg;
		struct { float __; f32x2 gb; };
	};
};

struct f64x3 {
	union {
		struct { double x; double y; double z; };
		struct { double r; double g; double b; };
		f64x2 xy;
		struct { double _; f64x2 yz; };
		f64x2 rg;
		struct { double __; f64x2 gb; };
	};
};

struct s8x3 {
	union {
		struct { int8_t x; int8_t y; int8_t z; };
		struct { int8_t r; int8_t g; int8_t b; };
		s8x2 xy;
		struct { int8_t _; s8x2 yz; };
		s8x2 rg;
		struct { int8_t __; s8x2 gb; };
	};
};

struct s16x3 {
	union {
		struct { int16_t x; int16_t y; int16_t z; };
		struct { int16_t r; int16_t g; int16_t b; };
		s16x2 xy;
		struct { int16_t _; s16x2 yz; };
		s16x2 rg;
		struct { int16_t __; s16x2 gb; };
	};
};

struct s32x3 {
	union {
		struct { int32_t x; int32_t y; int32_t z; };
		struct { int32_t r; int32_t g; int32_t b; };
		s32x2 xy;
		struct { int32_t _; s32x2 yz; };
		s32x2 rg;
		struct { int32_t __; s32x2 gb; };
	};
};

struct s64x3 {
	union {
		struct { int64_t x; int64_t y; int64_t z; };
		struct { int64_t r; int64_t g; int64_t b; };
		s64x2 xy;
		struct { int64_t _; s64x2 yz; };
		s64x2 rg;
		struct { int64_t __; s64x2 gb; };
	};
};

struct u8x3 {
	union {
		struct { uint8_t x; uint8_t y; uint8_t z; };
		struct { uint8_t r; uint8_t g; uint8_t b; };
		u8x2 xy;
		struct { uint8_t _; u8x2 yz; };
		u8x2 rg;
		struct { uint8_t __; u8x2 gb; };
	};
};

struct u16x3 {
	union {
		struct { uint16_t x; uint16_t y; uint16_t z; };
		struct { uint16_t r; uint16_t g; uint16_t b; };
		u16x2 xy;
		struct { uint16_t _; u16x2 yz; };
		u16x2 rg;
		struct { uint16_t __; u16x2 gb; };
	};
};

struct u32x3 {
	union {
		struct { uint32_t x; uint32_t y; uint32_t z; };
		struct { uint32_t r; uint32_t g; uint32_t b; };
		u32x2 xy;
		struct { uint32_t _; u32x2 yz; };
		u32x2 rg;
		struct { uint32_t __; u32x2 gb; };
	};
};

struct u64x3 {
	union {
		struct { uint64_t x; uint64_t y; uint64_t z; };
		struct { uint64_t r; uint64_t g; uint64_t b; };
		u64x2 xy;
		struct { uint64_t _; u64x2 yz; };
		u64x2 rg;
		struct { uint64_t __; u64x2 gb; };
	};
};

struct f16x4 {
	union {
		struct { half x; half y; half z; half w; };
		struct { half r; half g; half b; half a; };
		struct { f16x2 xy; f16x2 zw; };
		struct { f16x2 rg; f16x2 ba; };
		f16x3 xyz;
		struct { half _0; f16x3 yzw; };
		f16x3 rgb;
		struct { half _1; f16x3 gba; };
		struct { half _2; f16x2 yz; half _3; };
		struct { half _4; f16x2 gb; half _5; };
	};
};
struct f32x4 {
	union {
		struct { float x; float y; float z; float w; };
		struct { float r; float g; float b; float a; };
		struct { f32x2 xy; f32x2 zw; };
		struct { f32x2 rg; f32x2 ba; };
		f32x3 xyz;
		struct { float _0; f32x3 yzw; };
		f32x3 rgb;
		struct { float _1; f32x3 gba; };
		struct { float _2; f32x2 yz; float _3; };
		struct { float _4; f32x2 gb; float _5; };
	};
};
struct f64x4 {
	union {
		struct { double x; double y; double z; double w; };
		struct { double r; double g; double b; double a; };
		struct { f64x2 xy; f64x2 zw; };
		struct { f64x2 rg; f64x2 ba; };
		f64x3 xyz;
		struct { double _0; f64x3 yzw; };
		f64x3 rgb;
		struct { double _1; f64x3 gba; };
		struct { double _2; f64x2 yz; double _3; };
		struct { double _4; f64x2 gb; double _5; };
	};
};
struct s8x4 {
	union {
		struct { int8_t x; int8_t y; int8_t z; int8_t w; };
		struct { int8_t r; int8_t g; int8_t b; int8_t a; };
		struct { s8x2 xy; s8x2 zw; };
		struct { s8x2 rg; s8x2 ba; };
		s8x3 xyz;
		struct { int8_t _0; s8x3 yzw; };
		s8x3 rgb;
		struct { int8_t _1; s8x3 gba; };
		struct { int8_t _2; s8x2 yz; int8_t _3; };
		struct { int8_t _4; s8x2 gb; int8_t _5; };
	};
};
struct s16x4 {
	union {
		struct { int16_t x; int16_t y; int16_t z; int16_t w; };
		struct { int16_t r; int16_t g; int16_t b; int16_t a; };
		struct { s16x2 xy; s16x2 zw; };
		struct { s16x2 rg; s16x2 ba; };
		s16x3 xyz;
		struct { int16_t _0; s16x3 yzw; };
		s16x3 rgb;
		struct { int16_t _1; s16x3 gba; };
		struct { int16_t _2; s16x2 yz; int16_t _3; };
		struct { int16_t _4; s16x2 gb; int16_t _5; };
	};
};
struct s32x4 {
	union {
		struct { int32_t x; int32_t y; int32_t z; int32_t w; };
		struct { int32_t r; int32_t g; int32_t b; int32_t a; };
		struct { s32x2 xy; s32x2 zw; };
		struct { s32x2 rg; s32x2 ba; };
		s32x3 xyz;
		struct { int32_t _0; s32x3 yzw; };
		s32x3 rgb;
		struct { int32_t _1; s32x3 gba; };
		struct { int32_t _2; s32x2 yz; int32_t _3; };
		struct { int32_t _4; s32x2 gb; int32_t _5; };
	};
};
struct s64x4 {
	union {
		struct { int64_t x; int64_t y; int64_t z; int64_t w; };
		struct { int64_t r; int64_t g; int64_t b; int64_t a; };
		struct { s64x2 xy; s64x2 zw; };
		struct { s64x2 rg; s64x2 ba; };
		s64x3 xyz;
		struct { int64_t _0; s64x3 yzw; };
		s64x3 rgb;
		struct { int64_t _1; s64x3 gba; };
		struct { int64_t _2; s64x2 yz; int64_t _3; };
		struct { int64_t _4; s64x2 gb; int64_t _5; };
	};
};
struct u8x4 {
	union {
		struct { uint8_t x; uint8_t y; uint8_t z; uint8_t w; };
		struct { uint8_t r; uint8_t g; uint8_t b; uint8_t a; };
		struct { u8x2 xy; u8x2 zw; };
		struct { u8x2 rg; u8x2 ba; };
		u8x3 xyz;
		struct { uint8_t _0; u8x3 yzw; };
		u8x3 rgb;
		struct { uint8_t _1; u8x3 gba; };
		struct { uint8_t _2; u8x2 yz; uint8_t _3; };
		struct { uint8_t _4; u8x2 gb; uint8_t _5; };
	};
};
struct u16x4 {
	union {
		struct { uint16_t x; uint16_t y; uint16_t z; uint16_t w; };
		struct { uint16_t r; uint16_t g; uint16_t b; uint16_t a; };
		struct { u16x2 xy; u16x2 zw; };
		struct { u16x2 rg; u16x2 ba; };
		u16x3 xyz;
		struct { uint16_t _0; u16x3 yzw; };
		u16x3 rgb;
		struct { uint16_t _1; u16x3 gba; };
		struct { uint16_t _2; u16x2 yz; uint16_t _3; };
		struct { uint16_t _4; u16x2 gb; uint16_t _5; };
	};
};
struct u32x4 {
	union {
		struct { uint32_t x; uint32_t y; uint32_t z; uint32_t w; };
		struct { uint32_t r; uint32_t g; uint32_t b; uint32_t a; };
		struct { u32x2 xy; u32x2 zw; };
		struct { u32x2 rg; u32x2 ba; };
		u32x3 xyz;
		struct { uint32_t _0; u32x3 yzw; };
		u32x3 rgb;
		struct { uint32_t _1; u32x3 gba; };
		struct { uint32_t _2; u32x2 yz; uint32_t _3; };
		struct { uint32_t _4; u32x2 gb; uint32_t _5; };
	};
};
struct u64x4 {
	union {
		struct { uint64_t x; uint64_t y; uint64_t z; uint64_t w; };
		struct { uint64_t r; uint64_t g; uint64_t b; uint64_t a; };
		struct { u64x2 xy; u64x2 zw; };
		struct { u64x2 rg; u64x2 ba; };
		u64x3 xyz;
		struct { uint64_t _0; u64x3 yzw; };
		u64x3 rgb;
		struct { uint64_t _1; u64x3 gba; };
		struct { uint64_t _2; u64x2 yz; uint64_t _3; };
		struct { uint64_t _4; u64x2 gb; uint64_t _5; };
	};
};
#endif

//
// initializes a new vector with 2, 3 or 4 components of any of the following types:
//	bool, half, float, double, uint8_t, uint16_t, uint32_t, uint64_t, int8_t, int16_t, int32_t, or int64_t
#define f16x2(x, y) ((f16x2){ x, y })
#define f16x2s(s) ((f16x2){ s, s })
#define f32x2(x, y) ((f32x2){ x, y })
#define f32x2_cast(v) ((f32x2){ (float)(v).x, (float)(v).y })
#define f32x2s(s) ((f32x2){ s, s })
#define f64x2(x, y) ((f64x2){ x, y })
#define f64x2_cast(v) ((f64x2){ (double)(v).x, (double)(v).y })
#define f64x2s(s) ((f64x2){ s, s })
#define s8x2(x, y) ((s8x2){ x, y })
#define s8x2_cast(v) ((s8x2){ (int8_t)(v).x, (int8_t)(v).y })
#define s8x2s(s) ((s8x2){ s, s })
#define s16x2(x, y) ((s16x2){ x, y })
#define s16x2_cast(v) ((s16x2){ (int16_t)(v).x, (int16_t)(v).y })
#define s16x2s(s) ((s16x2){ s, s })
#define s32x2(x, y) ((s32x2){ x, y })
#define s32x2_cast(v) ((s32x2){ (int32_t)(v).x, (int32_t)(v).y })
#define s32x2s(s) ((s32x2){ s, s })
#define s64x2(x, y) ((s64x2){ x, y })
#define s64x2_cast(v) ((s64x2){ (int64_t)(v).x, (int64_t)(v).y })
#define s64x2s(s) ((s64x2){ s, s })
#define u8x2(x, y) ((u8x2){ x, y })
#define u8x2_cast(v) ((u8x2){ (uint8_t)(v).x, (uint8_t)(v).y })
#define u8x2s(s) ((u8x2){ s, s })
#define u16x2(x, y) ((u16x2){ x, y })
#define u16x2_cast(v) ((u16x2){ (uint16_t)(v).x, (uint16_t)(v).y })
#define u16x2s(s) ((u16x2){ s, s })
#define u32x2(x, y) ((u32x2){ x, y })
#define u32x2_cast(v) ((u32x2){ (uint32_t)(v).x, (uint32_t)(v).y })
#define u32x2s(s) ((u32x2){ s, s })
#define u64x2(x, y) ((u64x2){ x, y })
#define u64x2_cast(v) ((u64x2){ (uint64_t)(v).x, (uint64_t)(v).y })
#define u64x2s(s) ((u64x2){ s, s })

#define f16x3(x, y, z) ((f16x3){ x, y, z })
#define f16x3s(s) ((f16x3){ s, s, s })
#define f16x3sv2(x, v) ((f16x3){ x, (v).x, (v).y })
#define f16x3v2s(v, z) ((f16x3){ (v).x, (v).y, z })
#define f32x3(x, y, z) ((f32x3){ x, y, z })
#define f32x3_cast(v) ((f32x3){ (float)(v).x, (float)(v).y, (float)(v).z })
#define f32x3s(s) ((f32x3){ s, s, s })
#define f32x3sv2(s, v) ((f32x3){ s, (v).x, (v).y })
#define f32x3v2s(v, s) ((f32x3){ (v).x, (v).y, s })
#define f64x3(x, y, z) ((f64x3){ x, y, z })
#define f64x3_cast(v) ((f64x3){ (double)(v).x, (double)(v).y, (double)(v).z })
#define f64x3s(s) ((f64x3){ s, s, s })
#define f64x3sv2(s, v) ((f64x3){ s, (v).x, (v).y })
#define f64x3v2s(v, s) ((f64x3){ (v).x, (v).y, s })
#define s8x3(x, y, z) ((s8x3){ x, y, z })
#define s8x3_cast(v) ((s8x3){ (int8_t)(v).x, (int8_t)(v).y, (int8_t)(v).z })
#define s8x3s(s) ((s8x3){ s, s, s })
#define s8x3sv2(s, v) ((s8x3){ s, (v).x, (v).y })
#define s8x3v2s(v, s) ((s8x3){ (v).x, (v).y, s })
#define s16x3(x, y, z) ((s16x3){ x, y, z })
#define s16x3_cast(v) ((s16x3){ (int16_t)(v).x, (int16_t)(v).y, (int16_t)(v).z })
#define s16x3s(s) ((s16x3){ s, s, s })
#define s16x3sv2(s, v) ((s16x3){ s, (v).x, (v).y })
#define s16x3v2s(v, s) ((s16x3){ (v).x, (v).y, s })
#define s32x3(x, y, z) ((s32x3){ x, y, z })
#define s32x3_cast(v) ((s32x3){ (int32_t)(v).x, (int32_t)(v).y, (int32_t)(v).z })
#define s32x3s(s) ((s32x3){ s, s, s })
#define s32x3sv2(s, v) ((s32x3){ s, (v).x, (v).y })
#define s32x3v2s(v, s) ((s32x3){ (v).x, (v).y, s })
#define s64x3(x, y, z) ((s64x3){ x, y, z })
#define s64x3_cast(v) ((s64x3){ (int64_t)(v).x, (int64_t)(v).y, (int64_t)(v).z })
#define s64x3s(s) ((s64x3){ s, s, s })
#define s64x3sv2(s, v) ((s64x3){ s, (v).x, (v).y })
#define s64x3v2s(v, s) ((s64x3){ (v).x, (v).y, s })
#define u8x3(x, y, z) ((u8x3){ x, y, z })
#define u8x3_cast(v) ((u8x3){ (uint8_t)(v).x, (uint8_t)(v).y, (uint8_t)(v).z })
#define u8x3s(s) ((u8x3){ s, s, s })
#define u8x3sv2(s, v) ((u8x3){ s, (v).x, (v).y })
#define u8x3v2s(v, s) ((u8x3){ (v).x, (v).y, s })
#define u16x3(x, y, z) ((u16x3){ x, y, z })
#define u16x3_cast(v) ((u16x3){ (uint16_t)(v).x, (uint16_t)(v).y, (uint16_t)(v).z })
#define u16x3s(s) ((u16x3){ s, s, s })
#define u16x3sv2(s, v) ((u16x3){ s, (v).x, (v).y })
#define u16x3v2s(v, s) ((u16x3){ (v).x, (v).y, s })
#define u32x3(x, y, z) ((u32x3){ x, y, z })
#define u32x3_cast(v) ((u32x3){ (uint32_t)(v).x, (uint32_t)(v).y, (uint32_t)(v).z })
#define u32x3s(s) ((u32x3){ s, s, s })
#define u32x3sv2(s, v) ((u32x3){ x, (v).x, (v).y })
#define u32x3v2s(v, z) ((u32x3){ (v).x, (v).y, s })
#define u64x3(x, y, z) ((u64x3){ x, y, z })
#define u64x3_cast(v) ((u64x3){ (uint64_t)(v).x, (uint64_t)(v).y, (uint64_t)(v).z })
#define u64x3s(s) ((u64x3){ s, s, s })
#define u64x3sv2(s, v) ((u64x3){ s, (v).x, (v).y })
#define u64x3v2s(v, s) ((u64x3){ (v).x, (v).y, s })

#define f16x4(x, y, z, w) ((f16x4){ x, y, z, w })
#define f16x4s(s) ((f16x4){ s, s, s, s })
#define f16x4sv2(sx, sy, v) ((f16x4){ sx, sy, (v).x, (v).y })
#define f16x4v2s(v, sz, sw) ((f16x4){ (v).x, (v).y, z, sw })
#define f16x4sv2s(sx, v, sw) ((f16x4){ sx, (v).x, (v).y, sw })
#define f16x4sv3(sx, v) ((f16x4){ sx, (v).x, (v).y, (v).z })
#define f16x4v3s(v, sw) ((f16x4){ (v).x, (v).y, (v).z, sw })
#define f32x4(x, y, z, w) ((f32x4){ x, y, z, w })
#define f32x4_cast(v) ((f32x4){ (float)(v).x, (float)(v).y, (float)(v).z, (float)(v).w })
#define f32x4s(s) ((f32x4){ s, s, s, s })
#define f32x4sv2(sx, sy, v) ((f32x4){ sx, sy, (v).x, (v).y })
#define f32x4v2s(v, sz, sw) ((f32x4){ (v).x, (v).y, z, sw })
#define f32x4sv2s(sx, v, sw) ((f32x4){ sx, (v).x, (v).y, sw })
#define f32x4sv3(sx, v) ((f32x4){ sx, (v).x, (v).y, (v).z })
#define f32x4v3s(v, sw) ((f32x4){ (v).x, (v).y, (v).z, sw })
#define f64x4(x, y, z, w) ((f64x4){ x, y, z, w })
#define f64x4_cast(v) ((f64x4){ (double)(v).x, (double)(v).y, (double)(v).z, (double)(v).w })
#define f64x4s(s) ((f64x4){ s, s, s, s })
#define f64x4sv2(sx, sy, v) ((f64x4){ sx, sy, (v).x, (v).y })
#define f64x4v2s(v, sz, sw) ((f64x4){ (v).x, (v).y, z, sw })
#define f64x4sv2s(sx, v, sw) ((f64x4){ sx, (v).x, (v).y, sw })
#define f64x4sv3(sx, v) ((f64x4){ sx, (v).x, (v).y, (v).z })
#define f64x4v3s(v, sw) ((f64x4){ (v).x, (v).y, (v).z, sw })
#define s8x4(x, y, z, w) ((s8x4){ x, y, z, w })
#define s8x4_cast(v) ((s8x4){ (int8_t)(v).x, (int8_t)(v).y, (int8_t)(v).z, (int8_t)(v).w })
#define s8x4s(s) ((s8x4){ s, s, s, s })
#define s8x4sv2(sx, sy, v) ((s8x4){ sx, sy, (v).x, (v).y })
#define s8x4v2s(v, sz, sw) ((s8x4){ (v).x, (v).y, z, sw })
#define s8x4sv2s(sx, v, sw) ((s8x4){ sx, (v).x, (v).y, sw })
#define s8x4sv3(sx, v) ((s8x4){ sx, (v).x, (v).y, (v).z })
#define s8x4v3s(v, sw) ((s8x4){ (v).x, (v).y, (v).z, sw })
#define s16x4(x, y, z, w) ((s16x4){ x, y, z, w })
#define s16x4_cast(v) ((s16x4){ (int16_t)(v).x, (int16_t)(v).y, (int16_t)(v).z, (int16_t)(v).w })
#define s16x4s(s) ((s16x4){ s, s, s, s })
#define s16x4sv2(sx, sy, v) ((s16x4){ sx, sy, (v).x, (v).y })
#define s16x4v2s(v, sz, sw) ((s16x4){ (v).x, (v).y, z, sw })
#define s16x4sv2s(sx, v, sw) ((s16x4){ sx, (v).x, (v).y, sw })
#define s16x4sv3(sx, v) ((s16x4){ sx, (v).x, (v).y, (v).z })
#define s16x4v3s(v, sw) ((s16x4){ (v).x, (v).y, (v).z, sw })
#define s32x4(x, y, z, w) ((s32x4){ x, y, z, w })
#define s32x4_cast(v) ((s32x4){ (int32_t)(v).x, (int32_t)(v).y, (int32_t)(v).z, (int32_t)(v).w })
#define s32x4s(s) ((s32x4){ s, s, s, s })
#define s32x4sv2(sx, sy, v) ((s32x4){ sx, sy, (v).x, (v).y })
#define s32x4v2s(v, sz, sw) ((s32x4){ (v).x, (v).y, z, sw })
#define s32x4sv2s(sx, v, sw) ((s32x4){ sx, (v).x, (v).y, sw })
#define s32x4sv3(sx, v) ((s32x4){ sx, (v).x, (v).y, (v).z })
#define s32x4v3s(v, sw) ((s32x4){ (v).x, (v).y, (v).z, sw })
#define s64x4(x, y, z, w) ((s64x4){ x, y, z, w })
#define s64x4_cast(v) ((s64x4){ (int64_t)(v).x, (int64_t)(v).y, (int64_t)(v).z, (int64_t)(v).w })
#define s64x4s(s) ((s64x4){ s, s, s, s })
#define s64x4sv2(sx, sy, v) ((s64x4){ sx, sy, (v).x, (v).y })
#define s64x4v2s(v, sz, sw) ((s64x4){ (v).x, (v).y, z, sw })
#define s64x4sv2s(sx, v, sw) ((s64x4){ sx, (v).x, (v).y, sw })
#define s64x4sv3(sx, v) ((s64x4){ sx, (v).x, (v).y, (v).z })
#define s64x4v3s(v, sw) ((s64x4){ (v).x, (v).y, (v).z, sw })
#define u8x4(x, y, z, w) ((u8x4){ x, y, z, w })
#define u8x4_cast(v) ((u8x4){ (uint8_t)(v).x, (uint8_t)(v).y, (uint8_t)(v).z, (uint8_t)(v).w })
#define u8x4s(s) ((u8x4){ s, s, s, s })
#define u8x4sv2(sx, sy, v) ((u8x4){ sx, sy, (v).x, (v).y })
#define u8x4v2s(v, sz, sw) ((u8x4){ (v).x, (v).y, z, sw })
#define u8x4sv2s(sx, v, sw) ((u8x4){ sx, (v).x, (v).y, sw })
#define u8x4sv3(sx, v) ((u8x4){ sx, (v).x, (v).y, (v).z })
#define u8x4v3s(v, sw) ((u8x4){ (v).x, (v).y, (v).z, sw })
#define u16x4(x, y, z, w) ((u16x4){ x, y, z, w })
#define u16x4_cast(v) ((u16x4){ (uint16_t)(v).x, (uint16_t)(v).y, (uint16_t)(v).z, (uint16_t)(v).w })
#define u16x4s(s) ((u16x4){ s, s, s, s })
#define u16x4sv2(sx, sy, v) ((u16x4){ sx, sy, (v).x, (v).y })
#define u16x4v2s(v, sz, sw) ((u16x4){ (v).x, (v).y, z, sw })
#define u16x4sv2s(sx, v, sw) ((u16x4){ sx, (v).x, (v).y, sw })
#define u16x4sv3(sx, v) ((u16x4){ sx, (v).x, (v).y, (v).z })
#define u16x4v3s(v, sw) ((u16x4){ (v).x, (v).y, (v).z, sw })
#define u32x4(x, y, z, w) ((u32x4){ x, y, z, w })
#define u32x4_cast(v) ((u32x4){ (uint32_t)(v).x, (uint32_t)(v).y, (uint32_t)(v).z, (uint32_t)(v).w })
#define u32x4s(s) ((u32x4){ s, s, s, s })
#define u32x4sv2(sx, sy, v) ((u32x4){ sx, sy, (v).x, (v).y })
#define u32x4v2s(v, sz, sw) ((u32x4){ (v).x, (v).y, z, sw })
#define u32x4sv2s(sx, v, sw) ((u32x4){ sx, (v).x, (v).y, sw })
#define u32x4sv3(sx, v) ((u32x4){ sx, (v).x, (v).y, (v).z })
#define u32x4v3s(v, sw) ((u32x4){ (v).x, (v).y, (v).z, sw })
#define u64x4(x, y, z, w) ((u64x4){ x, y, z, w })
#define u64x4_cast(v) ((u64x4){ (uint64_t)(v).x, (uint64_t)(v).y, (uint64_t)(v).z, (uint64_t)(v).w })
#define u64x4s(s) ((u64x4){ s, s, s, s })
#define u64x4sv2(sx, sy, v) ((u64x4){ sx, sy, (v).x, (v).y })
#define u64x4v2s(v, sz, sw) ((u64x4){ (v).x, (v).y, z, sw })
#define u64x4sv2s(sx, v, sw) ((u64x4){ sx, (v).x, (v).y, sw })
#define u64x4sv3(sx, v) ((u64x4){ sx, (v).x, (v).y, (v).z })
#define u64x4v3s(v, sw) ((u64x4){ (v).x, (v).y, (v).z, sw })

#define INFINITY_F16X2 f16x2(INFINITY_F16, INFINITY_F16)
#define INFINITY_F32X2 f32x2(INFINITY_F32, INFINITY_F32)
#define INFINITY_F64X2 f64x2(INFINITY_F64, INFINITY_F64)
#define INFINITY_F16X3 f16x3(INFINITY_F16, INFINITY_F16, INFINITY_F16)
#define INFINITY_F32X3 f32x3(INFINITY_F32, INFINITY_F32, INFINITY_F32)
#define INFINITY_F64X3 f64x3(INFINITY_F64, INFINITY_F64, INFINITY_F64)
#define INFINITY_F16X4 f16x4(INFINITY_F16, INFINITY_F16, INFINITY_F16, INFINITY_F16)
#define INFINITY_F32X4 f32x4(INFINITY_F32, INFINITY_F32, INFINITY_F32, INFINITY_F32)
#define INFINITY_F64X4 f64x4(INFINITY_F64, INFINITY_F64, INFINITY_F64, INFINITY_F64)

#define NEGINFINITY_F16X2 f16x2(NEGINFINITY_F16, NEGINFINITY_F16)
#define NEGINFINITY_F32X2 f32x2(NEGINFINITY_F32, NEGINFINITY_F32)
#define NEGINFINITY_F64X2 f64x2(NEGINFINITY_F64, NEGINFINITY_F64)
#define NEGINFINITY_F16X3 f16x3(NEGINFINITY_F16, NEGINFINITY_F16, NEGINFINITY_F16)
#define NEGINFINITY_F32X3 f32x3(NEGINFINITY_F32, NEGINFINITY_F32, NEGINFINITY_F32)
#define NEGINFINITY_F64X3 f64x3(NEGINFINITY_F64, NEGINFINITY_F64, NEGINFINITY_F64)
#define NEGINFINITY_F16X4 f16x4(NEGINFINITY_F16, NEGINFINITY_F16, NEGINFINITY_F16, NEGINFINITY_F16)
#define NEGINFINITY_F32X4 f32x4(NEGINFINITY_F32, NEGINFINITY_F32, NEGINFINITY_F32, NEGINFINITY_F32)
#define NEGINFINITY_F64X4 f64x4(NEGINFINITY_F64, NEGINFINITY_F64, NEGINFINITY_F64, NEGINFINITY_F64)

#define NAN_F16X2 f16x2(NAN_F16, NAN_F16)
#define NAN_F32X2 f32x2(NAN_F32, NAN_F32)
#define NAN_F64X2 f64x2(NAN_F64, NAN_F64)
#define NAN_F16X3 f16x3(NAN_F16, NAN_F16, NAN_F16)
#define NAN_F32X3 f32x3(NAN_F32, NAN_F32, NAN_F32)
#define NAN_F64X3 f64x3(NAN_F64, NAN_F64, NAN_F64)
#define NAN_F16X4 f16x4(NAN_F16, NAN_F16, NAN_F16, NAN_F16)
#define NAN_F32X4 f32x4(NAN_F32, NAN_F32, NAN_F32, NAN_F32)
#define NAN_F64X4 f64x4(NAN_F64, NAN_F64, NAN_F64, NAN_F64)

#define splat2(v) (v).x, (v).y
#define splat3(v) (v).x, (v).y, (v).z
#define splat4(v) (v).x, (v).y, (v).z, (v).w

// ===========================================
//
//
// Matrix
//
//
// ===========================================

typedef struct f32x2x2 f32x2x2;
typedef struct f64x2x2 f64x2x2;
typedef struct f32x2x3 f32x2x3;
typedef struct f64x2x3 f64x2x3;
typedef struct f32x2x4 f32x2x4;
typedef struct f64x2x4 f64x2x4;
typedef struct f32x3x2 f32x3x2;
typedef struct f64x3x2 f64x3x2;
typedef struct f32x3x3 f32x3x3;
typedef struct f64x3x3 f64x3x3;
typedef struct f32x3x4 f32x3x4;
typedef struct f64x3x4 f64x3x4;
typedef struct f32x4x2 f32x4x2;
typedef struct f64x4x2 f64x4x2;
typedef struct f32x4x3 f32x4x3;
typedef struct f64x4x3 f64x4x3;
typedef struct f32x4x4 f32x4x4;
typedef struct f64x4x4 f64x4x4;

struct f32x2x2 { f32x2 cols[2]; };
struct f64x2x2 { f64x2 cols[2]; };
struct f32x2x3 { f32x2 cols[3]; };
struct f64x2x3 { f64x2 cols[3]; };
struct f32x2x4 { f32x2 cols[4]; };
struct f64x2x4 { f64x2 cols[4]; };
struct f32x3x2 { f32x3 cols[2]; };
struct f64x3x2 { f64x3 cols[2]; };
struct f32x3x3 { f32x3 cols[3]; };
struct f64x3x3 { f64x3 cols[3]; };
struct f32x3x4 { f32x3 cols[4]; };
struct f64x3x4 { f64x3 cols[4]; };
struct f32x4x2 { f32x4 cols[2]; };
struct f64x4x2 { f64x4 cols[2]; };
struct f32x4x3 { f32x4 cols[3]; };
struct f64x4x3 { f64x4 cols[3]; };
struct f32x4x4 { f32x4 cols[4]; };
struct f64x4x4 { f64x4 cols[4]; };

#define IDENTITY_F32X2X2 ((f32x2x2) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F64X2X2 ((f64x2x2) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F32X2X3 ((f32x2x3) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F64X2X3 ((f64x2x3) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F32X2X4 ((f32x2x4) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F64X2X4 ((f64x2x4) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F32X3X2 ((f32x3x2) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F64X3X2 ((f64x3x2) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F32X3X3 ((f32x3x3) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f })
#define IDENTITY_F64X3X3 ((f64x3x3) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f })
#define IDENTITY_F32X3X4 ((f32x3x4) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f })
#define IDENTITY_F64X3X4 ((f64x3x4) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f })
#define IDENTITY_F32X4X2 ((f32x4x2) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F64X4X2 ((f64x4x2) { .cols[0].x = 1.f, .cols[1].y = 1.f })
#define IDENTITY_F32X4X3 ((f32x4x3) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f })
#define IDENTITY_F64X4X3 ((f64x4x3) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f })
#define IDENTITY_F32X4X4 ((f32x4x4) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f, .cols[3].w = 1.f })
#define IDENTITY_F64X4X4 ((f64x4x4) { .cols[0].x = 1.f, .cols[1].y = 1.f, .cols[2].z = 1.f, .cols[3].w = 1.f })

#endif // _HMATHS_TYPES_H_
