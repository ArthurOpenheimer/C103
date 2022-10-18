#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> lista;    //"ponteiro" para a lista
    list<int>::iterator p;    //"ponteiro"iterador para a lista
    int x;    //variavel auxiliar para inserir na lista
    int soma = 0;

    cin >> x;

    while(x != 0){
        lista.push_back(x);
        cin >> x;
    }

    for(p = lista.begin(); p != lista.end(); p++){
        soma += *p
    }

    cout << "soma" << soma << endl;
    
    while(!lista.empty()){
        lista.pop_front();    //remove o primeiro elemento da lista
    }

    return 0;
}