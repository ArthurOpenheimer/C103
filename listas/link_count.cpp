#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista){
    list<int>::iterator p;  //"ponteiro"iterador para a lista
    int cont = 0;   //contador de elementos da lista
    for(p = lista.begin(); p != lista.end(); p++){
        cont++;
    }
    return cont;
}

int main(){

    list<int> lista;    //"ponteiro" para a lista
    int x;    //variavel auxiliar para inserir na lista

    cin >> x;

    while(x != 0){
        lista.push_back(x);
        cin >> x;
    }

    cout << contar(lista) << endl;  //chama a funcao contar e imprime o resultado
    
    while(!lista.empty()){
        lista.pop_front();    //remove o primeiro elemento da lista
    }

    return 0;
}