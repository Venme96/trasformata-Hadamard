

    
#include <iostream>
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

void fwht2(double*a,int n, int k){
    int m=log2(n);
    int rapp[m];
    int tem=k;
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
               a[i]=a[i]+a[i+h];}
            else 
           {
               a[i]=a[i]-a[i+h];}
    }}
        cout<<"il risultato è: a["<<tem<<"]="<<a[0]<<endl;
}


int main() {
    double v[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0}; 
    double w[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0}; 
    double j[] = {1.0, 2.0, 3.0, 4.0, 5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0};
    double s[] = {1.0, 2.0, 3.0, 4.0, 5.0,6.0,7.0,8.,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0};
    int taglia = sizeof(v) / sizeof(v[0]);
    // Calcolo la dimensione dell'array
    // Inizializzo l'array per il risultato
    Hmm(v, taglia);
    cout << "la trasformata vale:[";
    for (int i = 0; i < taglia; i++) {
        cout << v[i] << " ";
    }
    cout << "]"<< endl;

    int k[]={0,1,3,4,5,6,7,10,14};
    int taglia2=sizeof(k)/sizeof(k[0]); 
    Hmridotta(k,taglia2,w,taglia);
    cout << "la trasformata ridotta vale:[";
    for (int i = 0; i < taglia2; i++){
        cout << w[k[i]]<< " ";
    }
    cout<<"]"<<endl;

    fwht(j,taglia);
    cout<<"la trasformata intera col metodo iterativo vale: [";
    for(int i=0;i<taglia;i++){
        cout<<j[i]<<" ";
    }
    cout<<"]"<<endl;
    fwht2(s,taglia,8);

    return 0;
}
