#include "cxxopts.hpp"
#include "../lib/calculate_hubs.h"
#include "fopen_matrix.h"
#include <fstream>
#include <iostream>

void write_em(const std::basic_string<char> &output_file_name2,
              const std::vector<HubInfo> &hub_info_all,
              const std::vector<std::size_t> &mr_id,
              const std::vector<std::vector<int>> &mr_em) {
  std::fstream fs2;
  fs2.open(output_file_name2, std::fstream::out | std::fstream::trunc);
  for (std::size_t i = 0; i < hub_info_all.size(); i++) {
    const auto &hub_info = hub_info_all[i];
    if (hub_info.if_hub > 0) {
      fs2 << mr_id[i];
      for (auto d : mr_em[i]) {
        fs2 << "\t" << d;
      }
      fs2 << std::endl;
    }
  }
}

void write_id(const std::basic_string<char> &output_file_name,
              const std::vector<HubInfo> &hub_info_all,
              const std::vector<std::size_t> &mr_id, const std::vector<std::basic_string<char>> &row_names) {
  std::fstream fs;
  fs.open(output_file_name, std::fstream::out | std::fstream::trunc);
  for (std::size_t i = 0; i < hub_info_all.size(); i++) {
    const auto &hub_info = hub_info_all[i];
    if (hub_info.if_hub > 0) {
      fs << hub_info.if_hub << "\t" << hub_info.cluster_bound << "\t"
         << hub_info.index << "\t" << mr_id[i] << "\t"<< row_names[mr_id[i]]<<std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
  try {
    cxxopts::Options options(argv[0],
                             "C++ demo for Mutual Rank based co-expression "
                             "hub/module identification");
    options.positional_help("[optional args]").show_positional_help();

    options.add_options()("i,input", "Input file name",
                          cxxopts::value<std::string>())(
        "o,id", "Output ID file name", cxxopts::value<std::string>())(
        "e,em", "Output MR file name", cxxopts::value<std::string>())(
        "k,cutoff", "Cutoff",
        cxxopts::value<std::size_t>()->default_value("500"))(
        "t,tn_p", "TN_p",
        cxxopts::value<double>()->default_value("1.0"))("h,help", "Print help");

    const auto result = options.parse(argc, argv);
    if (result.count("help")) {
      std::cout << options.help({""}) << std::endl;
      return 0;
    }

    auto tn_p = result["t"].as<double>();
    auto k = result["k"].as<std::size_t>();
    const auto input_file_name = result["i"].as<std::string>();
    const auto output_file_name = result["o"].as<std::string>();
    const auto output_file_name2 = result["e"].as<std::string>();

    const auto matrix =
        fopen_matrix::load_matrix<double>(input_file_name.c_str(), false);

    std::vector<HubInfo> hub_info_all;
    std::vector<std::size_t> mr_id;
    std::vector<std::vector<int>> mr_em;
    std::tie(hub_info_all, mr_id, mr_em) = calculate_hubs(matrix, tn_p, k);

    write_id(output_file_name, hub_info_all, mr_id, matrix.get_row_names());
    write_em(output_file_name2, hub_info_all, mr_id, mr_em);
    return 0;
  } catch (...) {
    std::cout << "Exception occured." << std::endl;
    return -1;
  }
}
