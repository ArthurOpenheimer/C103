#include<iostream>
#include<list>

using namespace std;

void print (list<int> lista){
    list<int>::iterator p;
    int cont = 0;
    for(p = lista.begin(); p != lista.end(); p++){
        cout << *p << " ";
        cont++;
    }
}


int main(){

    list<int> estoque;
    list<int> venda;

    int N, op, cod;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> op;
        if(op == 1){
            cin >> cod;
            estoque.push_back(cod);
        }else if(op == 2){
            cod = estoque.front();
            estoque.pop_front();
            venda.push_front(cod);
        }
    }
    
    

    cout << "Estoque: ";
    print(estoque);
    cout << endl;
    cout << "Venda: ";
    print(venda);
    cout << endl;

    while(!estoque.empty()){
        estoque.pop_front();
    }

    while(!venda.empty()){
        venda.pop_front();
    }

    return 0;
}