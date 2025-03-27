#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

void Hmm(double* v, int taglia) {
    if (taglia == 1) { //al caso base ho il mio valore
        return;
    } 
    else {
        int ind = taglia / 2;
       for(int i=0;i<ind;i++){
           double tmp;
           tmp=v[i];
           v[i]=v[i]+v[i+ind];
           v[i+ind]=tmp-v[i+ind];
       }
        Hmm(v,ind);
        Hmm(v+ind,ind);
    }
}

void Hmridotta(int*j,int k, double *v, int taglia) {
    if(k==0|| taglia==1)
        return;
    else{
        int ind=taglia/2;
        int s=0;
        while(j[s]<ind)
            { s++;}
        s++;
        for(int i=0;i<ind;i++){
            double tmp;
            tmp=v[i];
            v[i]=v[i]+v[i+ind];;
            v[i+ind]=tmp-v[i+ind];
        }
        Hmridotta(j,s,v,ind);
        Hmridotta(j+s,k-s,v+ind,ind);

        }

    }

void fwht(double* a, int n) {
    for (int h = 1; h < n; h = h* 2) { // log_2(n) iterazioni 
        for (int i = 0; i < n; i =i+ 2 * h) { // n/(2h) iterazioni 
            for (int j = i; j < i + h; j++) { //h iterazioni 
                double tmp = a[j];
                a[j] = a[j] + a[j+h];
                a[j + h] = tmp - a[j+h];;
            }
        }
    }
}
//in pratica h rappresenta la grandezza dei vettori da cui parto, da cui ricaverò un vettore di dimensione 2h.
// nel secondo ciclo , mi rappresenta il fatto che devo fare il procedimento per il numero di nodi n/h , solo che ogni volta ne prendo due, è per questo che lo faccio n/2h volte.

double fwht2(double a[],int n, int k){
    int m=log2(n);
    int rapp[m];
    double* temp = new double[n];
    
    for(int i=0;i<n;i++)
    temp[i]=a[i];
    for(int i=m-1;i>=0;i--)
        { if(k%2==0)
            rapp[i]=0;
         else 
        {rapp[i]=1;
        k--;}
        k=k/2;}

    //ora ho un array con la rappresentazione binaria di k
    for(int h=1;h<n;h=h*2){
        
        for(int i=0;i<n;i=i+2*h){
            
            int log=log2(h);
           if (rapp[m-1-log]==0)
           { 
               temp[i]=temp[i]+temp[i+h];}
            else 
           {
               temp[i]=temp[i]-temp[i+h];}
    }}
    double y_=temp[0];
    delete[] temp;
        return y_;
}

void rappresentazionebase2matriciale(int n, int *k, int m_){ //manca double *a
    int m=log2(n);
    int rapp[m_][m];//questa sarà una matrice che contiene le rappresentazioni binarie degli indici scelti in k: la riga rappresenta la scrittura binaria dell'indice scelto, mentre in una colonna ci sarà o 0 o 1 in base... 
    
for(int j=0;j<m_;j++){
    for(int i=m-1;i>=0;i--)
        { if(k[j]%2==0)
            rapp[j][i]=0;
         else 
        {rapp[j][i]=1;
        k[j]--;}
        k[j]=k[j]/2;}}

}
//avere la rappresentazione binaria di un array di k numeri costa O(klogn) che è minore del costo a cui vogliamo arrivare di O(nlogk), quindi va bene!
void fwht3(double*a,int n, int *k,int s){
    //s è la size di k;
    double temp[n];
    for(int i=0;i<n;i++){
        temp[i]=a[i];
    }
    for(int i=0;i<s;i++)
        a[k[i]]=fwht2(temp,n,k[i]);
}
int main() {
 double *x = nullptr;
    double *y= nullptr;
    double *z= nullptr;
    double *s=nullptr;
    int n = 8388608, k_ = 30;
    x = (double *) malloc(n * sizeof(double));
    std::clock_t c_start = std::clock();
    Hmm(x,n);
    std::clock_t c_end = std::clock();
    cout << "Dimensioni per il test: n = " << n << std::endl;
    cout << "Tempo impiegato per valutazione intera ricorsiva : " << (c_end - c_start) / 1000.0 << "ms" << std::endl;
    free(x);
     y = (double *) malloc(n * sizeof(double));
    
    int k[]={0,10,13,16,20,32,56,80,90,102};
        int taglia2 = sizeof(k)/sizeof(k[0]); 
    std::clock_t c_start1 = std::clock();
    Hmridotta(k,taglia2,y,n);
    std::clock_t c_end1 = std::clock();
    cout<<"Per calcolare solo "<< taglia2 << "indici ho impiegato:" << (c_end1 - c_start1)/1000.0 <<"ms"<< endl;
free(y);
    z=(double *) malloc (n * sizeof(double));
    std::clock_t c_start2 = std::clock();
    fwht(z,n);
    std::clock_t c_end2 = std::clock();
   cout<< "Per calcolare la trasformata col metodo iterativo impiego " << (c_end2 - c_start2)/1000.0 << "ms" << endl;
    free(z);
    s= (double *) malloc(n * sizeof(double));
    std::clock_t c_start3 = std::clock();
    fwht3(s,n,k,taglia2);
    std::clock_t c_end3 = std::clock();
    cout<< " Per calcolare la trasformata col metodo iterativo ho impiegato " << (c_end3 - c_start3 )/1000.0 << "ms" << endl;
free(s);
    return 0;
}
