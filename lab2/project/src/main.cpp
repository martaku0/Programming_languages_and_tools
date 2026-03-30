#include "../include/operacje.hpp"

void wczytajZbior(int A[], int &n){
    std::cin >> n;

    if(n < 0 || n > MAX)
        throw std::invalid_argument("Niepoprawny rozmiar zbioru");

    for(int i=0;i<n;i++)
        std::cin >> A[i];

    std::sort(A,A+n);
    n = std::unique(A,A+n) - A;
}

void wypisz(int A[], int n){
    std::cout<<"{ ";
    for(int i=0;i<n;i++)
        std::cout<<A[i]<<" ";
    std::cout<<"}"<<std::endl;
}

int main(){

    int operacja[MAX];

    int A[MAX][MAX];
    int B[MAX][MAX];

    int nA[MAX];
    int nB[MAX];

    int liczbaOp = 0;

    try{

        while(std::cin >> operacja[liczbaOp]){

            if(liczbaOp >= MAX){
                std::cerr<<"[WARNING] Za dużo operacji"<<std::endl;
                break;
            }

            wczytajZbior(A[liczbaOp], nA[liczbaOp]);
            wczytajZbior(B[liczbaOp], nB[liczbaOp]);

            liczbaOp++;
        }
        
        int wynik[MAX];
        int nW;

        for(int i=0;i<liczbaOp;i++){

            switch(operacja[i]){

                case 1:
                    nW = suma(A[i],nA[i],B[i],nB[i],wynik);
                    wypisz(wynik,nW);
                    break;

                case 2:
                    nW = wspolna(A[i],nA[i],B[i],nB[i],wynik);
                    wypisz(wynik,nW);
                    break;

                case 3:
                    nW = roznica(A[i],nA[i],B[i],nB[i],wynik);
                    wypisz(wynik,nW);
                    break;

                case 4:
                    nW = sym(A[i],nA[i],B[i],nB[i],wynik);
                    wypisz(wynik,nW);
                    break;

                case 5:
                    std::cout<<(rowne(A[i],nA[i],B[i],nB[i]) ? "TAK" : "NIE")<<std::endl;
                    break;

                case 6:
                    std::cout<<(podzbior(A[i],nA[i],B[i],nB[i]) ? "TAK" : "NIE")<<std::endl;
                    std::cout<<(podzbior(B[i],nB[i],A[i],nA[i]) ? "TAK" : "NIE")<<std::endl;
                    break;

                default:
                    std::cerr<<"[WARNING] Nieznana operacja"<<std::endl;
            }
        }

    }
    catch(const std::exception& e){
        std::cerr<<"[ERROR] "<<e.what()<<std::endl;
    }

    return 0;
}