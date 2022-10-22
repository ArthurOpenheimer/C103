#include<iostream>
#include<list>

using namespace std;

int main(){

    list<int> lista;
    int i;
    int x;

    for(i = 0; i<4; i++){
        cin >> x;
        lista.push_back(x);
    }

    while(!lista.empty()){
        x = *lista.begin(); 
        cout << x << endl;
        lista.pop_front();
    }

    return 0;
}