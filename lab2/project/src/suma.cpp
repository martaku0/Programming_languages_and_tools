#include "../include/operacje.hpp"

int suma(int A[], int nA, int B[], int nB, int C[]){
    return std::set_union(A,A+nA,B,B+nB,C) - C;
}