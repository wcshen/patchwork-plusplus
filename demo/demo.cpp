#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <Eigen/Dense>

void read_bin(std::string bin_path) {
    FILE* file = fopen(bin_path.c_str(), "rb");
    if (!file) {
        std::cerr << "error: failed to load " << bin_path << std::endl;
        return;
    }

    std::vector<double> buffer(1000000);
    size_t num_points =
            fread(reinterpret_cast<char*>(buffer.data()), sizeof(double), buffer.size(), file) / 4;
    printf("num_points = %d\n", (int)num_points);

    for (int i = 0; i < num_points; i++) {
        printf("xyzi: %f, %f, %f, %f\n",
               buffer[i * 4],
               buffer[i * 4 + 1],
               buffer[i * 4 + 2],
               buffer[i * 4 + 3]);
    }
}

int main() {
    std::string bin_path =
            "/home/swc/Plus/datasets/vis/iv_hesai/bin/"
            "000042.1672998227.593434.20230106T165434_j7-00004_12_67to87.bin";
    // std::ifstream file(bin_path, std::ios::in | std::ios::binary);
    // if (!file)
    //     return EXIT_FAILURE;

    // float item;
    // while (file.read((char *)&item, 4))
    // {
    //     std::cout << "[" << item;
    //     if (std::round(item) == item)
    //         std::cout << ".";
    //     std::cout << "]\n";
    // }
    read_bin(bin_path);
    return 0;
}