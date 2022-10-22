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

    double media = 0;
    for (p = v; p < v + N; p++) {
        media += *p;
    }
    media /= N;

    cout << fixed << setprecision(2) << media << endl;

    delete[] v;
    return 0;
}