#!/bin/bash
g++ main2.cpp HugeNumber_Function.cpp -o file
g++ generate.cpp -o generate
./generate > data
./file < data > rst
g++ main3.cpp -o main3
./main3 < rst > rst2
diff rst rst2
rm file generate main3 data
rm rst*

