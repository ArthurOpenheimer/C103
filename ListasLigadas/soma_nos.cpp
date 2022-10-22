#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista){
    list<int>::iterator p;
    int soma = 0;
    for(p = lista.begin(); p != lista.end(); p++){
        soma += *p;
    }
    return soma;
}
int main(){

    list<int> lista;    //"ponteiro" para a lista
    int x;    //variavel auxiliar para inserir na lista

    cin >> x;

    while(x != 0){
        lista.push_back(x);
        cin >> x;
    }

    cout << soma(lista) << endl;   //chama a funcao soma e imprime o resultado
    
    while(!lista.empty()){
        lista.pop_front();    //remove o primeiro elemento da lista
    }

    return 0;
}