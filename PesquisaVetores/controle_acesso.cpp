#include <iostream>

using namespace std;

int main() {
    int vet[20];
    int i = -1;
    int x;
    bool access = false;
    
    do { 
        i++;
        cin >> vet[i];
    } while (vet[i] != -1);
    
    cin >> x;
    i = -1;
    
    do { 
        i++;
        if(vet[i] == x) {
            cout << "Possui acesso";
            access = true;
        }
    } while (vet[i] != -1);
    
    if (access == false) 
        cout << "Nao possui acesso";
    
    return 0;
}