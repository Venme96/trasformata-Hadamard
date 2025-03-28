#include <iostream>
#include <cmath>

using namespace std;

void Hmm(double* v, int taglia) {
    if (taglia == 1) { //al caso base ho il mio valore
        return;
    } 
    else {
         double tmp;
        int ind = taglia / 2;
       for(int i=0;i<ind;i++){
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
         double tmp;
        while(j[s]<ind)
            { s++;}
        s++;
        for(int i=0;i<ind;i++){
            tmp=v[i];
            v[i]=v[i]+v[i+ind];;
            v[i+ind]=tmp-v[i+ind];
        }
        Hmridotta(j,s,v,ind);
        Hmridotta(j+s,k-s,v+ind,ind);

        }

    }

void fwht(double* a, int n) {
     double tmp;
    for (int h = 1; h < n; h = h* 2) { // log_2(n) iterazioni 
        for (int i = 0; i < n; i =i+ 2 * h) { // n/(2h) iterazioni 
            for (int j = i; j < i + h; j++) { //h iterazioni 
                tmp = a[j];
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
    double temp[n];
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
        return temp[0];
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
    fwht3(s,taglia,k,taglia2);
    cout<<"la trasformata ridotta vale:[";
    for (int i = 0; i < taglia2; i++)
        cout<<s[k[i]]<< " ";
     cout<<"]"<<endl;

    return 0;
}
