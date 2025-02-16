#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

string genereazaA() {
    int num_a = randomInt(0, 5); 
    return string(num_a, 'a');
}

string genereazaB() {
    int num_b = randomInt(0, 5);
    return string(num_b, 'b');
}

string genereazaCuvant() {
    return genereazaA() + genereazaB();
}

int main() {
    srand(time(0));

    int numarCuvinte = 0;

    cout << "Numarul de cuvinte: " << endl;
    cin >> numarCuvinte;

    for (int i = 0; i < numarCuvinte; i++) {
        cout << "Cuvant " << i + 1 << ": " << genereazaCuvant() << endl;
    }

    return 0;
}
