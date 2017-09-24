#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H
#include "../lib/calculate_hubs.h"
#include <vector>

class VectorMatrix : public IMatrix<double> {
public:
  explicit VectorMatrix(const std::vector<std::vector<double>> &data)
      : data_(data) {}

  std::size_t RowSize() const override { return data_.size(); }
  std::size_t ColSize() const override { return data_[0].size(); }

  const double *operator[](std::size_t index) const override {
    return &*data_[index].begin();
  }

private:
  const std::vector<std::vector<double>> &data_;
};

std::vector<HubInfo>
calculate_hubs(const std::vector<std::vector<double>> &data,
               const double TN_p = 0.0025, const int k = 1000L);
#endif
