#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H

#include "../lib/calculate_hubs.h"
#include <vector>

template <typename T> class VectorMatrix : public MatrixBase<T> {
protected:
  explicit VectorMatrix(const std::vector<std::vector<T>> data) : data_(data) {}

public:
  std::size_t row_size() const override { return data_.size(); }
  std::size_t col_size() const override { return data_[0].size(); }

  const T *operator[](const std::size_t index) const override {
    return &*data_[index].begin();
  }

private:
  const std::vector<std::vector<T>> data_;
};
#endif
