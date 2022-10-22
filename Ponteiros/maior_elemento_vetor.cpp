#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    int *v;
    int *p;
    
    cin >> N;
    v = new int[N];

    for (p = v; p < v + N; p++) {
        cin >> *p; 
    }

    int maior = *v; 
    for (p = v; p < v + N; p++) { 
        if (*p > maior) { 
            maior = *p;
        }
    }

    cout << maior << endl;
    return 0;
}