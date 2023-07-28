#!/bin/bash
build_path=/home/swc/Plus/others/occ_demo/patchwork-plusplus/build
demo=/home/swc/Plus/others/occ_demo/patchwork-plusplus/build/examples/cpp/demo_visualize
bin_path=/home/swc/Plus/datasets/vis/iv_hesai/bin/000081.1672995580.993410.20230106T165434_j7-00004_1_100to120.bin

cd $build_path
cmake ..
make

$demo $bin_path