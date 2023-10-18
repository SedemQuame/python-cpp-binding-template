#!/bin/bash
pip3 install pybind11
cd src/cpp

g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) main.cpp ImageManipulation.cpp -o ImageManipulation$(python3-config --extension-suffix) $(pkg-config --cflags --libs opencv)

mv ImageManipulation*.so ../py/

cd ../py

pip install -r requirements.txt
