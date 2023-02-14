#!/bin/bash
for i in {1..100}
do
   python gen.py
   g++ -o main main.cpp
   ./main
   cat output.txt >> time_res.txt
   cat output.txt
done
