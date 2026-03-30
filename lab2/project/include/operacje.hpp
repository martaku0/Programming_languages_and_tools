#include <iostream>
#include <algorithm>
#include <stdexcept>

const int MAX = 100;

extern int suma(int A[], int nA, int B[], int nB, int wynik[]);
extern int wspolna(int A[], int nA, int B[], int nB, int wynik[]);
extern int roznica(int A[], int nA, int B[], int nB, int wynik[]);
extern int sym(int A[], int nA, int B[], int nB, int wynik[]);
extern bool rowne(int A[], int nA, int B[], int nB);
extern bool podzbior(int A[], int nA, int B[], int nB);