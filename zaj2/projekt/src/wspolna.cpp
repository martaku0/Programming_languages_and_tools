#include "../include/operacje.hpp"

int wspolna(int A[], int nA, int B[], int nB, int C[]){
    return std::set_intersection(A,A+nA,B,B+nB,C) - C;
}
