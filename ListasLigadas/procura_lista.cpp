#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x){
    list<int>::iterator p;
    for(p = lista.begin(); p != lista.end(); p++){
        if(*p == x){
            return true;
        }
    }
    return false;
}

int main(){

    list<int> lista;    //"ponteiro" para a lista
    int x;    //variavel auxiliar para inserir na lista
    int N;    //variavel para procurar na lista

    cin >> x;

    while(x != 0){
        lista.push_back(x);
        cin >> x;
    }

    cin >> N;

    if(encontrar(lista, N)){    //se encontrar o elemento N na lista retorna true
        cout << "Encontrado" << endl;
    }else{
        cout << "Nao encontrado" << endl;
    }

    while(!lista.empty()){    //remove elementos da lista
        lista.pop_front();    
    }

    return 0;
}