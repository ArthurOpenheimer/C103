#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    int *v;
    int *p;
    int contadorParePositivo = 0;
    
    cin >> N;
    v = new int[N];

    for (p = v; p < v + N; p++) {
        cin >> *p; 
    }


    for (p = v; p < v + N; p++) {
        if (*p % 2 == 0 && *p > 0) {
            contadorParePositivo++;
        }
    }

    cout << contadorParePositivo << endl;

    return 0;
}