#include "trasformata2.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
 double *x = nullptr;
    double *y= nullptr;
    double *z= nullptr;
    double *s=nullptr;
    int n = 8388608;
    int k_ = 1;
    int k[k_];
    std::srand(std::time(nullptr));  // Inizializza il generatore di numeri casuali
    // Riempie l'array con numeri casuali
    for (int i = 0; i < k_; i++) {
        k[i] = std::rand() % (n + 1);
    }
    // Ordina l'array
    std::sort(k, k + k_);
    
    x = (double *) malloc(n * sizeof(double));
  //  std::clock_t c_start = std::clock();
   // Hmm(x,n);
    //std::clock_t c_end = std::clock();
    cout << "Dimensioni per il test: n = " << n << std::endl;
  //  cout << "Tempo impiegato per valutazione intera ricorsiva : " << (c_end - c_start) / 1000.0 << "ms" << std::endl;
    free(x);
     y = (double *) malloc(n * sizeof(double));
        int taglia2 = sizeof(k)/sizeof(k[0]); 
    std::clock_t c_start1 = std::clock();
    Hmridotta(k,taglia2,y,n);
    std::clock_t c_end1 = std::clock();
    cout<<"Per calcolare solo "<< taglia2 << " indici ho impiegato:" << (c_end1 - c_start1)/1000.0 <<"ms"<< endl;
free(y);
    z=(double *) malloc (n * sizeof(double));
   // std::clock_t c_start2 = std::clock();
   // fwht(z,n);
  //  std::clock_t c_end2 = std::clock();
  // cout<< "Per calcolare la trasformata col metodo iterativo impiego " << (c_end2 - c_start2)/1000.0 << "ms" << endl;
    free(z);
    s= (double *) malloc(n * sizeof(double));
    std::clock_t c_start3 = std::clock();
    fwht2(s,n,k[k_]);
    std::clock_t c_end3 = std::clock();
    cout<< " Per calcolare l'indice col metodo iterativo " << (c_end3 - c_start3 )/1000.0 << "ms" << endl;
free(s);
    return 0;
}
