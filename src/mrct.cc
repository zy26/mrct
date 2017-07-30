#include "../lib/calculate_hubs.h"
#include "fopen_matrix.h"
#include <fstream>
#include <iostream>

void show_usage(char *exe_name, const char *text) {
  std::cerr << text << std::endl;
  std::cerr << "\tUsage: " << exe_name << " "
            << "<input file name> <output file name> [TN_p]" << std::endl;
  std::cerr << "\tExample: " << exe_name << " "
            << "testdata/E_coli_anaerobic.txt E_coli_anaerobic.out 0.0025"
            << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    show_usage(argv[0], "File name should not be ommited.");
    return -1;
  }
  double TN_p = 0.0025;
  if (argc > 3) {
    char *e;
    errno = 0;
    TN_p = std::strtod(argv[3], &e);

    if (*e != '\0' || errno != 0) {
      show_usage(argv[0], "TN_p should be double.");
      return -2;
    }
  }

  char *input_file_name = argv[1];
  char *output_file_name = argv[2];
  Matrix<double> matrix =
      FopenMatrix::load_matrix<double>(input_file_name, false);
  auto hub_info_all = calculate_hubs(matrix.get_data(), TN_p);

  std::fstream fs;
  fs.open(output_file_name, std::fstream::out | std::fstream::trunc);
  for (auto it = hub_info_all.begin(); it != hub_info_all.end(); ++it)
    fs << it->if_hub << " " << it->cluster_bound << " " << it->index + 1
       << std::endl;
  return 0;
}
