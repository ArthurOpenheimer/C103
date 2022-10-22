#include <iostream>

using namespace std;

int hash_aux(int k, int m){
    int h;
    while(k < 0){
        k += m;
    }
    h = k % m;
    return h;
}

int main() {
    int k, m;
    cin >> k >> m;
    while((k!= 0)&&(m!= 0)){
        int hashing = hash_aux(k, m);
        cin >> k >> m;
        cout << hashing << endl;
    }

    return 0;
}