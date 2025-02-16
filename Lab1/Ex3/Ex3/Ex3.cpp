#include <iostream>
using namespace std;


bool Palindrom(int v[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (v[i] != v[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void GenereazaSecvente(int v[], int n, int secventa[], int idx, int lungime) {
    if (idx == lungime) {


        if (Palindrom(secventa, lungime)) {
            for (int i = 0; i < lungime; ++i) {
                cout << secventa[i];
            }
            cout << endl;
        }
        return;
    }

    
    for (int i = 0; i < n; ++i) {
        secventa[idx] = v[i];
        GenereazaSecvente(v, n, secventa, idx + 1, lungime); 
    }
}

int main() {
    int v[] = { 0, 1, 2 }; 
    int n = 3; 
    int secventa[5];

    for (int lungime = 1; lungime <= 5; ++lungime) {
        GenereazaSecvente(v, n, secventa, 0, lungime); 
    }

    return 0;
}
