#include <stdlib.h>
#include <ctime>
#include <iostream>

// Questo si potrebbe settare a long se usassimo una libreria BLAS con long invece che con int.
#define BLAS_INT_TYPE int

// Dichiariamo la funzione dgemv che useremo per calcolare il prodotto S * x. La funzione calcola, 
// in generale, il prodotto y := alpha*A*x + beta*y
    extern "C" {
    void dgemv_(char* trans, BLAS_INT_TYPE* m, BLAS_INT_TYPE* n, double* alpha,
        double* a, BLAS_INT_TYPE* lda, double* x, BLAS_INT_TYPE* incx,
        double* beta, double* y, BLAS_INT_TYPE* incy);
}
int main(int argc, const char *argv[]) {

    // Esempio di come si calcola uno sketch denso di dimension k x n. Qui non inseriamo 
    // all'interno della matrice S di riferimento delle entrate sensate (normalmente sarebbero
    // Gaussiane o simili). Dal punto di vista del costo computazionale questo non ha nessuna importanza.
    double *S = nullptr, *x = nullptr, *y = nullptr;
    BLAS_INT_TYPE n = 1000000, k = 30;
    double alpha = 1.0, beta = 0.0;
    char trans = 'N';
    BLAS_INT_TYPE incx = 1, incy = 1;

    // Allocazione della matrice S
    S = (double *) malloc(n * k * sizeof(double));

    // Un generico vettore x, e preparo l'output y
    x = (double *) malloc(n * sizeof(double));
    y = (double *) malloc(n * sizeof(double));

    // Utilizziamo le routine BLAS2 per il calcolo del prodotto S * x, e facciamo un timing 
    std::clock_t c_start = std::clock();
    dgemv_(&trans, &k, &n, &alpha, S, &k, x, &incx, &beta, y, &incy);
    std::clock_t c_end = std::clock();

    std::cout << "Dimensioni per il test: n = " << n << ", k = " << k << std::endl;
    std::cout << "Tempo impiegato per sketching denso: " << (c_end - c_start) / 1000.0 << "ms" << std::endl;

    // Release della memoria
    free(S);
    free(x);
    free(y);
}