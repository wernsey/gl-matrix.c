/*
https://github.com/wernsey/gl-matrix.c
This was forked from https://github.com/coreh/gl-matrix.c
with some additions for vec2_t and vec4_t types.

This is a fairly straightforward port of gl-matrix.js (https://github.com/toji/gl-matrix)
from JavaScript to C.
*/
#ifndef GL_MATRIX_H
#define GL_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * gl-matrix.c - High performance matrix and vector operations for OpenGL
 * Version 1.2.3
 */

#define GL_MATRIX_MAJOR_VERSION 1
#define GL_MATRIX_MINOR_VERSION 2
#define GL_MATRIX_MICRO_VERSION 3

#define GL_MATRIX_VERSION  "1.2.3"

/* Hex version number. A value of 0x010203 means version 1.2.3.
  useful for comparisons. e.g. GL_MATRIX_VERSION_HEX >= 0x010203 */
#define GL_MATRIX_VERSION_HEX  ((GL_MATRIX_MAJOR_VERSION << 16) | \
                              (GL_MATRIX_MINOR_VERSION << 8) | \
                              (GL_MATRIX_MICRO_VERSION))

typedef float numeric_t;

typedef numeric_t *vec2_t;
typedef numeric_t *vec3_t;
typedef numeric_t *vec4_t;
typedef numeric_t *mat3_t;
typedef numeric_t *mat4_t;
typedef numeric_t *quat_t;

/*
 * vec2_t - 2 Dimensional Vector
 */

/*
 * vec2_create
 * Creates a new instance of a vec2_t
 *
 * Params:
 * vec - Optional, vec2_t containing values to initialize with. If NULL, the
 * vector will be initialized with zeroes.
 *
 * Returns:
 * New vec2
 */
vec2_t vec2_create(vec2_t vec);

/*
 * vec2_set
 * Copies the values of one vec2_t to another
 *
 * Params:
 * vec - vec2_t containing values to copy
 * dest - vec2_t receiving copied values
 *
 * Returns:
 * dest
 */
vec2_t vec2_set(vec2_t vec, vec2_t dest);

/*
 * vec2_zeroes
 * Sets the value of a vec2_t to {0,0}
 *
 * Params:
 * vec - vec2_t to set
 *
 * Returns:
 * vec
 */
vec2_t vec2_zeroes(vec2_t vec);

/*
 * vec2_ones
 * Sets the value of a vec2_t to {1,1}
 *
 * Params:
 * vec - vec2_t to set
 *
 * Returns:
 * vec
 */
vec2_t vec2_ones(vec2_t vec);

/*
 * vec2_add
 * Performs a vector addition
 *
 * Params:
 * vec - vec2, first operand
 * vec2 - vec2, second operand
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_add(vec2_t vec, vec2_t vec2, vec2_t dest);

/*
 * vec2_subtract
 * Performs a vector subtraction
 *
 * Params:
 * vec - vec2, first operand
 * vec2 - vec2, second operand
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_subtract(vec2_t vec, vec2_t vec2, vec2_t dest);

/*
 * vec2_negate
 * Negates the components of a vec2
 *
 * Params:
 * vec - vec2_t to negate
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_negate(vec2_t vec, vec2_t dest);

/*
 * vec2_scale
 * Multiplies the components of a vec2_t by a scalar value
 *
 * Params:
 * vec - vec2_t to scale
 * val - Numeric value to scale by
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_scale(vec2_t vec, numeric_t val, vec2_t dest);

/*
 * vec2_normalize
 * Generates a unit vector of the same direction as the provided vec2
 * If vector length is 0, returns [0, 0]
 *
 * Params:
 * vec - vec2_t to normalize
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_normalize(vec2_t vec, vec2_t dest);

/*
 * vec2_length
 * Caclulates the length of a vec2
 *
 * Params:
 * vec - vec2_t to calculate length of
 *
 * Returns:
 * Length of vec
 */
numeric_t vec2_length(vec2_t vec);

/*
 * vec2_dot
 * Caclulates the dot product of two vec2s
 *
 * Params:
 * vec - vec2, first operand
 * vec2 - vec2, second operand
 *
 * Returns:
 * Dot product of vec and vec2
 */
numeric_t vec2_dot(vec2_t vec, vec2_t vec2);

/*
 * vec2_direction
 * Generates a unit vector pointing from one vector to another
 *
 * Params:
 * vec - origin vec2
 * vec2 - vec2_t to point to
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_direction (vec2_t vec, vec2_t vec2, vec2_t dest);

/*
 * vec2_lerp
 * Performs a linear interpolation between two vec2
 *
 * Params:
 * vec - vec2, first vector
 * vec2 - vec2, second vector
 * lerp - interpolation amount between the two inputs
 * dest - Optional, vec2_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec2_t vec2_lerp(vec2_t vec, vec2_t vec2, numeric_t lerp, vec2_t dest);

/*
 * vec2_dist
 * Calculates the euclidian distance between two vec2
 *
 * Params:
 * vec - vec2, first vector
 * vec2 - vec2, second vector
 *
 * Returns:
 * distance between vec and vec2
 */
numeric_t vec2_dist(vec2_t vec, vec2_t vec2);

/*
 * vec2_str
 * Writes a string representation of a vector
 *
 * Params:
 * vec - vec2_t to represent as a string
 * buffer - char * to store the results
 */
void vec2_str(vec2_t vec, char *buffer);

/*
 * vec3_t - 3 Dimensional Vector
 */

/*
 * vec3_create
 * Creates a new instance of a vec3_t
 *
 * Params:
 * vec - Optional, vec3_t containing values to initialize with. If NULL, the
 * vector will be initialized with zeroes.
 *
 * Returns:
 * New vec3
 */
vec3_t vec3_create(vec3_t vec);

/*
 * vec3_set
 * Copies the values of one vec3_t to another
 *
 * Params:
 * vec - vec3_t containing values to copy
 * dest - vec3_t receiving copied values
 *
 * Returns:
 * dest
 */
vec3_t vec3_set(vec3_t vec, vec3_t dest);

/*
 * vec3_zeroes
 * Sets the value of a vec3_t to {0,0,0}
 *
 * Params:
 * vec - vec3_t to set
 *
 * Returns:
 * vec
 */
vec3_t vec3_zeroes(vec3_t vec);

/*
 * vec3_ones
 * Sets the value of a vec3_t to {1,1,1}
 *
 * Params:
 * vec - vec3_t to set
 *
 * Returns:
 * vec
 */
vec3_t vec3_ones(vec3_t vec);

/*
 * vec3_add
 * Performs a vector addition
 *
 * Params:
 * vec - vec3, first operand
 * vec2 - vec3, second operand
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_add(vec3_t vec, vec3_t vec2, vec3_t dest);

/*
 * vec3_subtract
 * Performs a vector subtraction
 *
 * Params:
 * vec - vec3, first operand
 * vec2 - vec3, second operand
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_subtract(vec3_t vec, vec3_t vec2, vec3_t dest);

/*
 * vec3_multiply
 * Performs a vector multiplication
 *
 * Params:
 * vec - vec3, first operand
 * vec2 - vec3, second operand
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_multiply(vec3_t vec, vec3_t vec2, vec3_t dest);

/*
 * vec3_negate
 * Negates the components of a vec3
 *
 * Params:
 * vec - vec3_t to negate
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_negate(vec3_t vec, vec3_t dest);

/*
 * vec3_scale
 * Multiplies the components of a vec3_t by a scalar value
 *
 * Params:
 * vec - vec3_t to scale
 * val - Numeric value to scale by
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_scale(vec3_t vec, numeric_t val, vec3_t dest);

/*
 * vec3_normalize
 * Generates a unit vector of the same direction as the provided vec3
 * If vector length is 0, returns [0, 0, 0]
 *
 * Params:
 * vec - vec3_t to normalize
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_normalize(vec3_t vec, vec3_t dest);

/*
 * vec3_cross
 * Generates the cross product of two vec3s
 *
 * Params:
 * vec - vec3, first operand
 * vec2 - vec3, second operand
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_cross (vec3_t vec, vec3_t vec2, vec3_t dest);

/*
 * vec3_length
 * Caclulates the length of a vec3
 *
 * Params:
 * vec - vec3_t to calculate length of
 *
 * Returns:
 * Length of vec
 */
numeric_t vec3_length(vec3_t vec);

/*
 * vec3_dot
 * Caclulates the dot product of two vec3s
 *
 * Params:
 * vec - vec3, first operand
 * vec2 - vec3, second operand
 *
 * Returns:
 * Dot product of vec and vec2
 */
numeric_t vec3_dot(vec3_t vec, vec3_t vec2);

/*
 * vec3_direction
 * Generates a unit vector pointing from one vector to another
 *
 * Params:
 * vec - origin vec3
 * vec2 - vec3_t to point to
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_direction (vec3_t vec, vec3_t vec2, vec3_t dest);

/*
 * vec3_lerp
 * Performs a linear interpolation between two vec3
 *
 * Params:
 * vec - vec3, first vector
 * vec2 - vec3, second vector
 * lerp - interpolation amount between the two inputs
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */

vec3_t vec3_lerp(vec3_t vec, vec3_t vec2, numeric_t lerp, vec3_t dest);

/*
 * vec3_dist
 * Calculates the euclidian distance between two vec3
 *
 * Params:
 * vec - vec3, first vector
 * vec2 - vec3, second vector
 *
 * Returns:
 * distance between vec and vec2
 */
numeric_t vec3_dist(vec3_t vec, vec3_t vec2);

/*
 * vec3_unproject
 * Projects the specified vec3_t from screen space into object space
 * Based on Mesa gluUnProject implementation at:
 * http://webcvs.freedesktop.org/mesa/Mesa/src/glu/mesa/project.c?revision=1.4&view=markup
 *
 * Params:
 * vec - vec3, screen-space vector to project
 * view - mat4, View matrix
 * proj - mat4, Projection matrix
 * viewport - vec4, Viewport as given to gl.viewport [x, y, width, height]
 * dest - Optional, vec3_t receiving unprojected result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t vec3_unproject(vec3_t vec, mat4_t view, mat4_t proj, vec4_t viewport, vec3_t dest);

/*
 * vec3_str
 * Writes a string representation of a vector
 *
 * Params:
 * vec - vec3_t to represent as a string
 * buffer - char * to store the results
 */
void vec3_str(vec3_t vec, char *buffer);

/*
 * vec4_t - 4 Dimensional Vector
 */

/*
 * vec4_create
 * Creates a new instance of a vec4_t
 *
 * Params:
 * vec - Optional, vec4_t containing values to initialize with. If NULL, the
 * vector will be initialized with zeroes.
 *
 * Returns:
 * New vec4
 */
vec4_t vec4_create(vec4_t vec);

/*
 * vec4_set
 * Copies the values of one vec4_t to another
 *
 * Params:
 * vec - vec4_t containing values to copy
 * dest - vec4_t receiving copied values
 *
 * Returns:
 * dest
 */
vec4_t vec4_set(vec4_t vec, vec4_t dest);

/*
 * vec4_zeroes
 * Sets the value of a vec4_t to {0,0,0,0}
 *
 * Params:
 * vec - vec4_t to set
 *
 * Returns:
 * vec
 */
vec4_t vec4_zeroes(vec4_t vec);

/*
 * vec4_ones
 * Sets the value of a vec4_t to {1,1,1,1}
 *
 * Params:
 * vec - vec4_t to set
 *
 * Returns:
 * vec
 */
vec4_t vec4_ones(vec4_t vec);

/*
 * vec4_add
 * Performs a vector addition
 *
 * Params:
 * vec - vec4, first operand
 * vec2 - vec4, second operand
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_add(vec4_t vec, vec4_t vec2, vec4_t dest);

/*
 * vec4_subtract
 * Performs a vector subtraction
 *
 * Params:
 * vec - vec4, first operand
 * vec2 - vec4, second operand
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_subtract(vec4_t vec, vec4_t vec2, vec4_t dest);

/*
 * vec4_negate
 * Negates the components of a vec4
 *
 * Params:
 * vec - vec4_t to negate
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_negate(vec4_t vec, vec4_t dest);

/*
 * vec4_scale
 * Multiplies the components of a vec4_t by a scalar value
 *
 * Params:
 * vec - vec4_t to scale
 * val - Numeric value to scale by
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_scale(vec4_t vec, numeric_t val, vec4_t dest);

/*
 * vec4_normalize
 * Generates a unit vector of the same direction as the provided vec4
 * If vector length is 0, returns [0, 0, 0, 0]
 *
 * Params:
 * vec - vec4_t to normalize
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_normalize(vec4_t vec, vec4_t dest);

/*
 * vec4_length
 * Caclulates the length of a vec4
 *
 * Params:
 * vec - vec4_t to calculate length of
 *
 * Returns:
 * Length of vec
 */
numeric_t vec4_length(vec4_t vec);

/*
 * vec4_dot
 * Caclulates the dot product of two vec4s
 *
 * Params:
 * vec - vec4, first operand
 * vec2 - vec4, second operand
 *
 * Returns:
 * Dot product of vec and vec2
 */
numeric_t vec4_dot(vec4_t vec, vec4_t vec2);

/*
 * vec4_direction
 * Generates a unit vector pointing from one vector to another
 *
 * Params:
 * vec - origin vec4
 * vec2 - vec4_t to point to
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_direction (vec4_t vec, vec4_t vec2, vec4_t dest);

/*
 * vec4_lerp
 * Performs a linear interpolation between two vec4
 *
 * Params:
 * vec - vec4, first vector
 * vec2 - vec4, second vector
 * lerp - interpolation amount between the two inputs
 * dest - Optional, vec4_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t vec4_lerp(vec4_t vec, vec4_t vec2, numeric_t lerp, vec4_t dest);

/*
 * vec4_dist
 * Calculates the euclidian distance between two vec4
 *
 * Params:
 * vec - vec4, first vector
 * vec2 - vec4, second vector
 *
 * Returns:
 * distance between vec and vec2
 */
numeric_t vec4_dist(vec4_t vec, vec4_t vec2);

/*
 * vec4_str
 * Writes a string representation of a vector
 *
 * Params:
 * vec - vec4_t to represent as a string
 * buffer - char * to store the results
 */
void vec4_str(vec4_t vec, char *buffer);

/*
 * mat3_t - 3x3 Matrix
 */

/*
 * mat3_create
 * Creates a new instance of a mat3_t
 *
 * Params:
 * mat - Optional, mat3_t containing values to initialize with. If NULL the result
 * will be initialized with zeroes.
 *
 * Returns:
 * New mat3
 */
mat3_t mat3_create(mat3_t mat);

/*
 * mat3_set
 * Copies the values of one mat3_t to another
 *
 * Params:
 * mat - mat3_t containing values to copy
 * dest - mat3_t receiving copied values
 *
 * Returns:
 * dest
 */
mat3_t mat3_set(mat3_t mat, mat3_t dest);

/*
 * mat3_identity
 * Sets a mat3_t to an identity matrix
 *
 * Params:
 * dest - mat3_t to set
 *
 * Returns:
 * dest
 */
 mat3_t mat3_identity(mat3_t dest);

/*
 * mat4.transpose
 * Transposes a mat3_t (flips the values over the diagonal)
 *
 * Params:
 * mat - mat3_t to transpose
 * dest - Optional, mat3_t receiving transposed values. If NULL, result is written to mat
 *
 * Returns:
 * dest is specified, mat otherwise
 */
mat3_t mat3_transpose(mat3_t mat, mat3_t dest);

/*
 * mat3_toMat4
 * Copies the elements of a mat3_t into the upper 3x3 elements of a mat4
 *
 * Params:
 * mat - mat3_t containing values to copy
 * dest - Optional, mat4_t receiving copied values
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
mat4_t mat3_toMat4(mat3_t mat, mat4_t dest);

/*
 * mat3_multiplyVec3
 * Transforms a vec3_t with the given matrix
 *
 * Params:
 * mat - mat3_t to transform the vector with
 * vec - vec3_t to transform
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t mat3_multiplyVec3(mat3_t mat, vec3_t vec, vec3_t dest);

/*
 * mat3_str
 * Writes a string representation of a mat3
 *
 * Params:
 * mat - mat3_t to represent as a string
 * buffer - char * to store the results
 */
void mat3_str(mat3_t mat, char *buffer);

/*
 * mat4_t - 4x4 Matrix
 */

/*
 * mat4_create
 * Creates a new instance of a mat4_t
 *
 * Params:
 * mat - Optional, mat4_t containing values to initialize with
 *
 * Returns:
 * New mat4
 */
mat4_t mat4_create(mat4_t mat);

/*
 * mat4_set
 * Copies the values of one mat4_t to another
 *
 * Params:
 * mat - mat4_t containing values to copy
 * dest - mat4_t receiving copied values
 *
 * Returns:
 * dest
 */
mat4_t mat4_set(mat4_t mat, mat4_t dest);

/*
 * mat4_identity
 * Sets a mat4_t to an identity matrix
 *
 * Params:
 * dest - mat4_t to set
 *
 * Returns:
 * dest
 */
mat4_t mat4_identity(mat4_t dest);

/*
 * mat4_transpose
 * Transposes a mat4_t (flips the values over the diagonal)
 *
 * Params:
 * mat - mat4_t to transpose
 * dest - Optional, mat4_t receiving transposed values. If NULL, result is written to mat
 *
 * Returns:
 * dest is specified, mat otherwise
 */
mat4_t mat4_transpose(mat4_t mat, mat4_t dest);

/*
 * mat4_determinant
 * Calculates the determinant of a mat4
 *
 * Params:
 * mat - mat4_t to calculate determinant of
 *
 * Returns:
 * determinant of mat
 */
numeric_t mat4_determinant(mat4_t mat);

/*
 * mat4_inverse
 * Calculates the inverse matrix of a mat4
 *
 * Params:
 * mat - mat4_t to calculate inverse of
 * dest - Optional, mat4_t receiving inverse matrix. If NULL, result is written to mat
 *
 * Returns:
 * dest is specified, mat otherwise, NULL if matrix cannot be inverted
 */
mat4_t mat4_inverse(mat4_t mat, mat4_t dest);

/*
 * mat4_toRotationMat
 * Copies the upper 3x3 elements of a mat4_t into another mat4
 *
 * Params:
 * mat - mat4_t containing values to copy
 * dest - Optional, mat4_t receiving copied values
 *
 * Returns:
 * dest is specified, a new mat4_t otherwise
 */
mat4_t mat4_toRotationMat(mat4_t mat, mat4_t dest);

/*
 * mat4_toMat3
 * Copies the upper 3x3 elements of a mat4_t into a mat3
 *
 * Params:
 * mat - mat4_t containing values to copy
 * dest - Optional, mat3_t receiving copied values
 *
 * Returns:
 * dest is specified, a new mat3_t otherwise
 */
mat3_t mat4_toMat3(mat4_t mat, mat3_t dest);

/*
 * mat4_toInverseMat3
 * Calculates the inverse of the upper 3x3 elements of a mat4_t and copies the result into a mat3
 * The resulting matrix is useful for calculating transformed normals
 *
 * Params:
 * mat - mat4_t containing values to invert and copy
 * dest - Optional, mat3_t receiving values
 *
 * Returns:
 * dest is specified, a new mat3_t otherwise, NULL if the matrix cannot be inverted
 */
mat3_t mat4_toInverseMat3(mat4_t mat, mat3_t dest);

/*
 * mat4_multiply
 * Performs a matrix multiplication
 *
 * Params:
 * mat - mat4, first operand
 * mat2 - mat4, second operand
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_multiply(mat4_t mat, mat4_t mat2, mat4_t dest);

/*
 * mat4_multiplyVec3
 * Transforms a vec3_t with the given matrix
 * 4th vector component is implicitly '1'
 *
 * Params:
 * mat - mat4_t to transform the vector with
 * vec - vec3_t to transform
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec3_t mat4_multiplyVec3(mat4_t mat, vec3_t vec, vec3_t dest);

/*
 * mat4_multiplyVec4
 * Transforms a vec4 with the given matrix
 *
 * Params:
 * mat - mat4_t to transform the vector with
 * vec - vec4 to transform
 * dest - Optional, vec4 receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
vec4_t mat4_multiplyVec4(mat4_t mat, vec4_t vec, vec4_t dest);

/*
 * mat4_translate
 * Translates a matrix by the given vector
 *
 * Params:
 * mat - mat4_t to translate
 * vec - vec3_t specifying the translation
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_translate(mat4_t mat, vec3_t vec, mat4_t dest);

/*
 * mat4_scale
 * Scales a matrix by the given vector
 *
 * Params:
 * mat - mat4_t to scale
 * vec - vec3_t specifying the scale for each axis
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_scale(mat4_t mat, vec3_t vec, mat4_t dest);

/*
 * mat4_scale_scalar
 * Scales a matrix by the given scalar
 *
 * Params:
 * mat - mat4_t to scale
 * scalar - scalar specifying the scale for each axis
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_scale_scalar(mat4_t mat, numeric_t scalar, mat4_t dest);

/*
 * mat4_rotate
 * Rotates a matrix by the given angle around the specified axis
 * If rotating around a primary axis (X,Y,Z) one of the specialized rotation functions should be used instead for performance
 *
 * Params:
 * mat - mat4_t to rotate
 * angle - angle (in radians) to rotate
 * axis - vec3_t representing the axis to rotate around
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_rotate(mat4_t mat, numeric_t angle, vec3_t axis, mat4_t dest);

/*
 * mat4_rotateX
 * Rotates a matrix by the given angle around the X axis
 *
 * Params:
 * mat - mat4_t to rotate
 * angle - angle (in radians) to rotate
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_rotateX(mat4_t mat, numeric_t angle, mat4_t dest);

/*
 * mat4_rotateY
 * Rotates a matrix by the given angle around the Y axis
 *
 * Params:
 * mat - mat4_t to rotate
 * angle - angle (in radians) to rotate
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_rotateY(mat4_t mat, numeric_t angle, mat4_t dest);

/*
 * mat4_rotateZ
 * Rotates a matrix by the given angle around the Z axis
 *
 * Params:
 * mat - mat4_t to rotate
 * angle - angle (in radians) to rotate
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to mat
 *
 * Returns:
 * dest if not NULL, mat otherwise
 */
mat4_t mat4_rotateZ(mat4_t mat, numeric_t angle, mat4_t dest);

/*
 * mat4_frustum
 * Generates a frustum matrix with the given bounds
 *
 * Params:
 * left, right - scalar, left and right bounds of the frustum
 * bottom, top - scalar, bottom and top bounds of the frustum
 * near, far - scalar, near and far bounds of the frustum
 * dest - Optional, mat4_t frustum matrix will be written into
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
mat4_t mat4_frustum(numeric_t left, numeric_t right, numeric_t bottom, numeric_t top, numeric_t near, numeric_t far, mat4_t dest);

/*
 * mat4_perspective
 * Generates a perspective projection matrix with the given bounds
 *
 * Params:
 * fovy - scalar, vertical field of view (in degrees)
 * aspect - scalar, aspect ratio. typically viewport width/height
 * near, far - scalar, near and far bounds of the frustum
 * dest - Optional, mat4_t frustum matrix will be written into
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
mat4_t mat4_perspective(numeric_t fovy, numeric_t aspect, numeric_t near, numeric_t far, mat4_t dest);

/*
 * mat4_ortho
 * Generates a orthogonal projection matrix with the given bounds
 *
 * Params:
 * left, right - scalar, left and right bounds of the frustum
 * bottom, top - scalar, bottom and top bounds of the frustum
 * near, far - scalar, near and far bounds of the frustum
 * dest - Optional, mat4_t frustum matrix will be written into
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
mat4_t mat4_ortho(numeric_t left, numeric_t right, numeric_t bottom, numeric_t top, numeric_t near, numeric_t far, mat4_t dest);

/*
 * mat4_lookAt
 * Generates a look-at matrix with the given eye position, focal point, and up axis
 *
 * Params:
 * eye - vec3, position of the viewer
 * center - vec3, point the viewer is looking at
 * up - vec3_t pointing "up"
 * dest - Optional, mat4_t frustum matrix will be written into
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
mat4_t mat4_lookAt(vec3_t eye, vec3_t center, vec3_t up, mat4_t dest);

/*
 * mat4_fromRotationTranslation
 * Creates a matrix from a quaternion rotation and vector translation
 * This is equivalent to (but much faster than):
 *
 *     mat4_identity(dest);
 *     mat4_translate(dest, vec);
 *     mat4_t quatMat = mat4_create();
 *     quat_toMat4(quat, quatMat);
 *     mat4_multiply(dest, quatMat);
 *
 * Params:
 * quat - quat specifying the rotation by
 * vec - vec3_t specifying the translation
 * dest - Optional, mat4_t receiving operation result. If NULL, result is written to a new mat4
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
mat4_t mat4_fromRotationTranslation(quat_t quat, vec3_t vec, mat4_t dest);

/*
 * mat4_alignVectors
 * Creates a matrix that will rotate one vector to point into the direction of another.
 *
 * If the resulting matrix is applied to the source vector it will point in the
 * direction of the target vector.
 *
 * Params:
 * source - Source orientation
 * target - Target orientation
 * dest - mat4_t receiving operation result.
 *
 * Returns:
 * dest
 */
mat4_t mat4_alignVectors(vec3_t source, vec3_t target, mat4_t dest);

/*
 * mat4_str
 * Writes a string representation of a mat4
 *
 * Params:
 * mat - mat4_t to represent as a string
 * buffer - char * to store the results
 */
void mat4_str(mat4_t mat, char *buffer);

/*
 * quat - Quaternions
 */

/*
 * quat_create
 * Creates a new instance of a quat_t
 *
 * Params:
 * quat - Optional, quat_t containing values to initialize with
 *
 * Returns:
 * New quat_t
 */
quat_t quat_create(quat_t quat);

/*
 * quat_set
 * Copies the values of one quat_t to another
 *
 * Params:
 * quat - quat_t containing values to copy
 * dest - quat_t receiving copied values
 *
 * Returns:
 * dest
 */
quat_t quat_set(quat_t quat, quat_t dest);

/*
 * quat_calculateW
 * Calculates the W component of a quat_t from the X, Y, and Z components.
 * Assumes that quaternion is 1 unit in length.
 * Any existing W component will be ignored.
 *
 * Params:
 * quat - quat_t to calculate W component of
 * dest - Optional, quat_t receiving calculated values. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_calculateW(quat_t quat, quat_t dest);

/**
 * quat_dot
 * Calculates the dot product of two quaternions
 *
 * @param {quat4} quat First operand
 * @param {quat4} quat2 Second operand
 *
 * @return {number} Dot product of quat and quat2
 */
numeric_t quat_dot(quat_t quat, quat_t quat2);

/*
 * quat_inverse
 * Calculates the inverse of a quat_t
 *
 * Params:
 * quat - quat_t to calculate inverse of
 * dest - Optional, quat_t receiving inverse values. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_inverse(quat_t quat, quat_t dest);

/*
 * quat_conjugate
 * Calculates the conjugate of a quat_t
 *
 * Params:
 * quat - quat_t to calculate conjugate of
 * dest - Optional, quat_t receiving conjugate values. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_conjugate(quat_t quat, quat_t dest);

/*
 * quat_length
 * Calculates the length of a quat_t
 *
 * Params:
 * quat - quat_t to calculate length of
 *
 * Returns:
 * Length of quat
 */
numeric_t quat_length(quat_t quat);

/*
 * quat_normalize
 * Generates a unit quaternion of the same direction as the provided quat_t
 * If quaternion length is 0, returns [0, 0, 0, 0]
 *
 * Params:
 * quat - quat_t to normalize
 * dest - Optional, quat_ receiving operation result. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_normalize(quat_t quat, quat_t dest);

/*
 * quat_multiply
 * Performs a quaternion multiplication
 *
 * Params:
 * quat - quat_t, first operand
 * quat2 - quat_t, second operand
 * dest - Optional, quat_t receiving operation result. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_multiply(quat_t quat, quat_t quat2, quat_t dest);

/*
 * quat_multiplyVec3
 * Transforms a vec3_t with the given quaternion
 *
 * Params:
 * quat - quat_t to transform the vector with
 * vec - vec3_t to transform
 * dest - Optional, vec3_t receiving operation result. If NULL, result is written to vec
 *
 * Returns:
 * dest if not NULL, vec otherwise
 */
quat_t quat_multiplyVec3(quat_t quat, vec3_t vec, vec3_t dest);

/*
 * quat_toMat3
 * Calculates a 3x3 matrix from the given quat_t
 *
 * Params:
 * quat - quat_t to create matrix from
 * dest - Optional, mat3_t receiving operation result
 *
 * Returns:
 * dest if not NULL, a new mat3_t otherwise
 */
mat3_t quat_toMat3(quat_t quat, mat3_t dest);

/*
 * quat_toMat4
 * Calculates a 4x4 matrix from the given quat_t
 *
 * Params:
 * quat - quat_t to create matrix from
 * dest - Optional, mat4_t receiving operation result
 *
 * Returns:
 * dest if not NULL, a new mat4_t otherwise
 */
quat_t quat_toMat4(quat_t quat, mat4_t dest);

/*
 * quat_slerp
 * Performs a spherical linear interpolation between two quat_t
 *
 * Params:
 * quat - quat_t, first quaternion
 * quat2 - quat_t, second quaternion
 * slerp - interpolation amount between the two inputs
 * dest - Optional, quat_t receiving operation result. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_slerp(quat_t quat, quat_t quat2, numeric_t slerp, quat_t dest);

/*
 * quat_axisFromAngle
 * Creates a quaternion to rotate objects around a specific axis by a specific angle
 *
 * Params:
 * axis - The axis to rotate around
 * angle - The angle to rotate
 * dest - quat_t receiving operation result
 *
 * Returns:
 * dest
 */
quat_t quat_axisFromAngle(vec3_t axis, numeric_t angle, quat_t dest);

/*
 * quat_rotate
 * Rotates a point around a quaternion by applying the formula
 *
 *    r = q.p.q*
 *
 * where q is the quaternion, q* is its conjugate, and p is the
 * point to be rotated.
 *
 * Params:
 * quat - quat_t, first quaternion
 * p - vec3_t, the point to rotate
 * dest - Optional, quat_t receiving operation result. If NULL, result is written to quat
 *
 * Returns:
 * dest if not NULL, quat otherwise
 */
quat_t quat_rotate(quat_t quat, vec3_t p, quat_t dest);

/*
 * quat_str
 * Writes a string representation of a quaternion
 *
 * Params:
 * quat - quat_t to represent as a string
 * buffer - char * to store the results
 */
void quat_str(quat_t quat, char *buffer);

#ifdef __cplusplus
}
#endif

#endif
