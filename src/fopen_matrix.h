#ifndef FOPEN_MATRIX_H
#define FOPEN_MATRIX_H

#include "matrix_with_names.h"

#include <cassert>
#include <cstdio>
#include <cstring>

namespace fopen_matrix {
namespace internal {

#define MAX_LINE 100000
#define LABEL_LEN 64

int fscanf2(FILE *file, short *x);

int fscanf2(FILE *file, int *x);

int fscanf2(FILE *file, float *x);

int fscanf2(FILE *file, double *x);

template <typename T>
MatrixWithNames<T> load_matrix_from_file(FILE *fp, std::size_t reserved_count,
                                         const bool ignore_first) {
  std::vector<std::string> row_names;
  std::vector<std::string> col_names;
  std::vector<std::vector<T>> data;

  char line[MAX_LINE];
  if (fgets(line, MAX_LINE, fp) == nullptr)
    throw - 1;

  const char delims[] = " \t\r\n";
  char *pch = strtok(line, delims);
  if (pch == nullptr)
    throw - 1;
  if (ignore_first)
    pch = strtok(nullptr, delims); // ignore the first value
  while (pch != nullptr) {
    col_names.push_back(pch);
    pch = strtok(nullptr, delims);
  }

  char value[LABEL_LEN] = {0};
  while (1 == fscanf(fp, "%s", value)) {
    row_names.push_back(value);
    std::vector<T> line_data(col_names.size());
    for (std::size_t i = 0; i < col_names.size(); i++) {
      fscanf2(fp, &line_data[i]);
    }
    data.emplace_back(line_data);
  }
  assert(row_names.size() == data.size());
  MatrixWithNames<T> matrix(data, row_names, col_names);
  return matrix;
}
} // namespace internal

template <typename T>
MatrixWithNames<T> load_matrix(const char *file_name,
                               std::size_t reserved_count,
                               const bool ignore_first = true) {
  FILE *fp = fopen(file_name, "r");
  if (nullptr == fp) {
    printf("Failed to open '%s'", file_name);
    throw - 1;
  }
  MatrixWithNames<T> matrix =
      internal::load_matrix_from_file<T>(fp, reserved_count,
                                         ignore_first); // RVO
  fclose(fp);
  return matrix; // RVO
}

template <typename T>
MatrixWithNames<T> load_matrix(const char *file_name,
                               const bool ignore_first = true) {
  return load_matrix<T>(file_name, 4096, ignore_first); // RVO
}
} // namespace fopen_matrix
#endif
