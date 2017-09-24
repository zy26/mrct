#include "vector_matrix.h"
#include "../lib/calculate_hubs.h"
#include <memory>

std::vector<HubInfo>
calculate_hubs(const std::vector<std::vector<double>> &data,
               const double TN_p /*= 0.0025*/, const int k /*= 1000L*/) {
  return calculate_hubs(*std::make_unique<VectorMatrix>(data), TN_p, k);
}
