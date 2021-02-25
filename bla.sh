#! /bin/sh

g++ -std=c++17 fistine.cc -O3
./a.out < a.txt > a_sol.txt
./a.out < b.txt > b_sol.txt
./a.out < c.txt > c_sol.txt
./a.out < d.txt > d_sol.txt
./a.out < e.txt > e_sol.txt
./a.out < f.txt > f_sol.txt
