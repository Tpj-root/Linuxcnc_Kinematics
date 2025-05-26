#!/bin/bash

echo "***********"
echo "Fully cpp code test_cpp"
./build/test_cpp
echo "***********"

sleep 1
echo "***********"
echo "Fully python binding with cpp code test_py"
PYTHONPATH=$(pwd)/build ./build/test_py
echo "***********"

sleep 1
echo "***********"
echo "Fully python bcode with CPP Binding main.py"
PYTHONPATH=$(pwd)/build python ./test/main.py
echo "***********"

