#include "../../mrct/src/fopen_matrix.h"

int fopen_matrix::internal::fscanf2(FILE *file, short *x) {
  return fscanf(file, "%hd", x);
}

int fopen_matrix::internal::fscanf2(FILE *file, double *x) {
  return fscanf(file, "%lf", x);
}

int fopen_matrix::internal::fscanf2(FILE *file, float *x) {
  return fscanf(file, "%f", x);
}

int fopen_matrix::internal::fscanf2(FILE *file, int *x) {
  return fscanf(file, "%d", x);
}
