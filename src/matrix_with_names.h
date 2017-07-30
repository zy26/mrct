#ifndef MATRIX_H
#define MATRIX_H

#include "vector_matrix.h"
#include <string>
#include <vector>

template <typename T> class MatrixWithNames : public VectorMatrix<T> {
public:
  explicit MatrixWithNames(const std::vector<std::vector<T>> data,
                           const std::vector<std::string> row_names,
                           const std::vector<std::string> col_names)
      : VectorMatrix<T>(data), row_names_(row_names), col_names_(col_names) {}
  const std::vector<std::string> &get_row_names() const { return row_names_; }
  const std::vector<std::string> &get_col_names() const { return col_names_; }

private:
  const std::vector<std::string> row_names_;
  const std::vector<std::string> col_names_;
};

#endif
