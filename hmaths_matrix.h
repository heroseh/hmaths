#ifndef _HMATHS_MATRIX_H_
#define _HMATHS_MATRIX_H_

// ===========================================
//
//
// Matrix
//
//
// ===========================================

//
// returns a matrix that is a result of multipling matrix 'a' with matrix 'b'
f32x2x2 mul_f32x2x2_f32x2x2(f32x2x2 a, f32x2x2 b);
f64x2x2 mul_f64x2x2_f64x2x2(f64x2x2 a, f64x2x2 b);
f32x2x3 mul_f32x2x3_f32x3x2(f32x2x3 a, f32x3x2 b);
f64x2x3 mul_f64x2x3_f64x3x2(f64x2x3 a, f64x3x2 b);
f32x2x4 mul_f32x2x4_f32x4x2(f32x2x4 a, f32x4x2 b);
f64x2x4 mul_f64x2x4_f64x4x2(f64x2x4 a, f64x4x2 b);
f32x3x2 mul_f32x3x2_f32x2x3(f32x3x2 a, f32x2x3 b);
f64x3x2 mul_f64x3x2_f64x2x3(f64x3x2 a, f64x2x3 b);
f32x3x3 mul_f32x3x3_f32x3x3(f32x3x3 a, f32x3x3 b);
f64x3x3 mul_f64x3x3_f64x3x3(f64x3x3 a, f64x3x3 b);
f32x3x4 mul_f32x3x4_f32x4x3(f32x3x4 a, f32x4x3 b);
f64x3x4 mul_f64x3x4_f64x4x3(f64x3x4 a, f64x4x3 b);
f32x4x2 mul_f32x4x2_f32x2x4(f32x4x2 a, f32x2x4 b);
f64x4x2 mul_f64x4x2_f64x2x4(f64x4x2 a, f64x2x4 b);
f32x4x3 mul_f32x4x3_f32x3x4(f32x4x3 a, f32x3x4 b);
f64x4x3 mul_f64x4x3_f64x3x4(f64x4x3 a, f64x3x4 b);
f32x4x4 mul_f32x4x4_f32x4x4(f32x4x4 a, f32x4x4 b);
f64x4x4 mul_f64x4x4_f64x4x4(f64x4x4 a, f64x4x4 b);

//
// returns a matrix that is a result of multipling matrix 'm' with scalar 's'
f32x2x2 muls_f32x2x2(f32x2x2 m, float s);
f64x2x2 muls_f64x2x2(f64x2x2 m, double s);
f32x2x3 muls_f32x2x3(f32x2x3 m, float s);
f64x2x3 muls_f64x2x3(f64x2x3 m, double s);
f32x2x4 muls_f32x2x4(f32x2x4 m, float s);
f64x2x4 muls_f64x2x4(f64x2x4 m, double s);
f32x3x2 muls_f32x3x2(f32x3x2 m, float s);
f64x3x2 muls_f64x3x2(f64x3x2 m, double s);
f32x3x3 muls_f32x3x3(f32x3x3 m, float s);
f64x3x3 muls_f64x3x3(f64x3x3 m, double s);
f32x3x4 muls_f32x3x4(f32x3x4 m, float s);
f64x3x4 muls_f64x3x4(f64x3x4 m, double s);
f32x4x2 muls_f32x4x2(f32x4x2 m, float s);
f64x4x2 muls_f64x4x2(f64x4x2 m, double s);
f32x4x3 muls_f32x4x3(f32x4x3 m, float s);
f64x4x3 muls_f64x4x3(f64x4x3 m, double s);
f32x4x4 muls_f32x4x4(f32x4x4 m, float s);
f64x4x4 muls_f64x4x4(f64x4x4 m, double s);

//
// returns a vector that is a result of multipling matrix 'm' with vector 'v'
f32x2 mul_f32x2x2_f32x2(f32x2x2 m, f32x2 v);
f64x2 mul_f64x2x2_f64x2(f64x2x2 m, f64x2 v);
f32x2 mul_f32x2x3_f32x2(f32x2x3 m, f32x2 v);
f64x2 mul_f64x2x3_f64x2(f64x2x3 m, f64x2 v);
f32x2 mul_f32x2x4_f32x2(f32x2x4 m, f32x2 v);
f64x2 mul_f64x2x4_f64x2(f64x2x4 m, f64x2 v);
f32x3 mul_f32x3x2_f32x3(f32x3x2 m, f32x3 v);
f64x3 mul_f64x3x2_f64x3(f64x3x2 m, f64x3 v);
f32x3 mul_f32x3x3_f32x3(f32x3x3 m, f32x3 v);
f64x3 mul_f64x3x3_f64x3(f64x3x3 m, f64x3 v);
f32x3 mul_f32x3x4_f32x3(f32x3x4 m, f32x3 v);
f64x3 mul_f64x3x4_f64x3(f64x3x4 m, f64x3 v);
f32x4 mul_f32x4x2_f32x4(f32x4x2 m, f32x4 v);
f64x4 mul_f64x4x2_f64x4(f64x4x2 m, f64x4 v);
f32x4 mul_f32x4x3_f32x4(f32x4x3 m, f32x4 v);
f64x4 mul_f64x4x3_f64x4(f64x4x3 m, f64x4 v);
f32x4 mul_f32x4x4_f32x4(f32x4x4 m, f32x4 v);
f64x4 mul_f64x4x4_f64x4(f64x4x4 m, f64x4 v);

//
// returns a vector that is a result of multipling vector 'v' with matrix 'm'
f32x2 mul_f32x2_f32x2x2(f32x2 v, f32x2x2 m);
f64x2 mul_f64x2_f64x2x2(f64x2 v, f64x2x2 m);
f32x3 mul_f32x3_f32x2x3(f32x3 v, f32x2x3 m);
f64x3 mul_f64x3_f64x2x3(f64x3 v, f64x2x3 m);
f32x4 mul_f32x4_f32x2x4(f32x4 v, f32x2x4 m);
f64x4 mul_f64x4_f64x2x4(f64x4 v, f64x2x4 m);
f32x2 mul_f32x2_f32x3x2(f32x2 v, f32x3x2 m);
f64x2 mul_f64x2_f64x3x2(f64x2 v, f64x3x2 m);
f32x3 mul_f32x3_f32x3x3(f32x3 v, f32x3x3 m);
f64x3 mul_f64x3_f64x3x3(f64x3 v, f64x3x3 m);
f32x4 mul_f32x4_f32x3x4(f32x4 v, f32x3x4 m);
f64x4 mul_f64x4_f64x3x4(f64x4 v, f64x3x4 m);
f32x2 mul_f32x2_f32x4x2(f32x2 v, f32x4x2 m);
f64x2 mul_f64x2_f64x4x2(f64x2 v, f64x4x2 m);
f32x3 mul_f32x3_f32x4x3(f32x3 v, f32x4x3 m);
f64x3 mul_f64x3_f64x4x3(f64x3 v, f64x4x3 m);
f32x4 mul_f32x4_f32x4x4(f32x4 v, f32x4x4 m);
f64x4 mul_f64x4_f64x4x4(f64x4 v, f64x4x4 m);

//
// returns the transposed matrix of matrix 'm'
f32x2x2 transpose_f32x2x2(f32x2x2 m);
f64x2x2 transpose_f64x2x2(f64x2x2 m);
f32x3x2 transpose_f32x2x3(f32x2x3 m);
f64x3x2 transpose_f64x2x3(f64x2x3 m);
f32x4x2 transpose_f32x2x4(f32x2x4 m);
f64x4x2 transpose_f64x2x4(f64x2x4 m);
f32x2x3 transpose_f32x3x2(f32x3x2 m);
f64x2x3 transpose_f64x3x2(f64x3x2 m);
f32x3x3 transpose_f32x3x3(f32x3x3 m);
f64x3x3 transpose_f64x3x3(f64x3x3 m);
f32x4x3 transpose_f32x3x4(f32x3x4 m);
f64x4x3 transpose_f64x3x4(f64x3x4 m);
f32x2x4 transpose_f32x4x2(f32x4x2 m);
f64x2x4 transpose_f64x4x2(f64x4x2 m);
f32x3x4 transpose_f32x4x3(f32x4x3 m);
f64x3x4 transpose_f64x4x3(f64x4x3 m);
f32x4x4 transpose_f32x4x4(f32x4x4 m);
f64x4x4 transpose_f64x4x4(f64x4x4 m);

//
// returns a matrix from the outer product of vector 'a' and vector 'b'
f32x2x2 outerproduct_f32x2_f32x2(f32x2 c, f32x2 r);
f64x2x2 outerproduct_f64x2_f64x2(f64x2 c, f64x2 r);
f32x2x3 outerproduct_f32x2_f32x3(f32x2 c, f32x3 r);
f64x2x3 outerproduct_f64x2_f64x3(f64x2 c, f64x3 r);
f32x2x4 outerproduct_f32x2_f32x4(f32x2 c, f32x4 r);
f64x2x4 outerproduct_f64x2_f64x4(f64x2 c, f64x4 r);
f32x3x2 outerproduct_f32x3_f32x2(f32x3 c, f32x2 r);
f64x3x2 outerproduct_f64x3_f64x2(f64x3 c, f64x2 r);
f32x3x3 outerproduct_f32x3_f32x3(f32x3 c, f32x3 r);
f64x3x3 outerproduct_f64x3_f64x3(f64x3 c, f64x3 r);
f32x3x4 outerproduct_f32x3_f32x4(f32x3 c, f32x4 r);
f64x3x4 outerproduct_f64x3_f64x4(f64x3 c, f64x4 r);
f32x4x2 outerproduct_f32x4_f32x2(f32x4 c, f32x2 r);
f64x4x2 outerproduct_f64x4_f64x2(f64x4 c, f64x2 r);
f32x4x3 outerproduct_f32x4_f32x3(f32x4 c, f32x3 r);
f64x4x3 outerproduct_f64x4_f64x3(f64x4 c, f64x3 r);
f32x4x4 outerproduct_f32x4_f32x4(f32x4 c, f32x4 r);
f64x4x4 outerproduct_f64x4_f64x4(f64x4 c, f64x4 r);

//
// returns the determinant of matrix 'm'
float determinant_f32x2x2(f32x2x2 m);
double determinant_f64x2x2(f64x2x2 m);
float determinant_f32x3x3(f32x3x3 m);
double determinant_f64x3x3(f64x3x3 m);
float determinant_f32x4x4(f32x4x4 m);
double determinant_f64x4x4(f64x4x4 m);

//
// returns the inverse of matrix 'm'
f32x2x2 inverse_f32x2x2(f32x2x2 m);
f64x2x2 inverse_f64x2x2(f64x2x2 m);
f32x3x3 inverse_f32x3x3(f32x3x3 m);
f64x3x3 inverse_f64x3x3(f64x3x3 m);
f32x4x4 inverse_f32x4x4(f32x4x4 m);
f64x4x4 inverse_f64x4x4(f64x4x4 m);

#endif // _HMATHS_MATRIX_H_
