#include "../include/operacje.hpp"

int roznica(int A[], int nA, int B[], int nB, int C[]){
    return std::set_difference(A,A+nA,B,B+nB,C) - C;
}