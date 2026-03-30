#include "../include/operacje.hpp"

bool rowne(int A[], int nA, int B[], int nB){
    if(nA != nB) return false;
    return std::equal(A,A+nA,B);
}