#include "trasformata2.h"
#include <iostream>

using namespace std;

int main() {
    double v[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,7.0,8.0,9.0,10.0,16.0,12.0,-4.5, 108.2,15.0,16.0}; 
    double w[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,7.0,8.0,9.0,10.0,16.0,12.0,-4.5, 108.2,15.0,16.0}; 
    // double j[] = {1.0, 2.0, 3.0, 4.0, 5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0};
    // double s[] = {1.0, 2.0, 3.0, 4.0, 5.0,6.0,7.0,8.,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0};

    int taglia = sizeof(v) / sizeof(v[0]);
    // Calcolo la dimensione dell'array
    // Inizializzo l'array per il risultato
    Hmm(v, taglia);
    cout << "la trasformata vale:[";
    for (int i = 0; i < taglia; i++) {
        cout << v[i] << " ";
    }
    cout << "]"<< endl;

    int k[]={0,1,3,4,5,6,8,10,14};
    int taglia2=sizeof(k)/sizeof(k[0]); 
    Hmridotta(k,taglia2,w,taglia);
    cout << "la trasformata ridotta vale:[";
    for (int i = 0; i < taglia2; i++){
        cout << w[k[i]]<< " ";
    }
    cout<<"]"<<endl;

    return 0;
}