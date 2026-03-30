#include "../include/operacje.hpp"

int sym(int A[], int nA, int B[], int nB, int C[]){
    return std::set_symmetric_difference(A,A+nA,B,B+nB,C) - C;
}