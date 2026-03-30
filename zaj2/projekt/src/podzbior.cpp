#include "../include/operacje.hpp"

bool podzbior(int A[], int nA, int B[], int nB){
    return std::includes(B,B+nB,A,A+nA);
}