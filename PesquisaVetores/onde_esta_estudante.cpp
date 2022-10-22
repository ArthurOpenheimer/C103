#include <iostream>

using namespace std;

int main() {
    int mat[1000], i, x, n; 
    bool found = false;
    
    cin >> n;
    
    for(i=0; i<n; i++) 
        cin >> mat[i];
    
    cin >> x;
    i = 0;
    
    for(i=0; i<n; i++) 
        if(mat[i] == x) {
            cout << "Corredor " << i;
            found = true;
        }
    
    if (found == false) 
        cout << "Nao localizado";
    
    return 0;
}