#include<iostream>
#include<iomanip>
#include<list>

using namespace std;

float calcMedia(list<int> lista){
    float media = 0;
    int i = 0;
    list<int>::iterator p;  //"ponteiro"iterador para a lista

    for(p = lista.begin(); p != lista.end(); p++){  //calcula media
        media += *p;  
        i++;
    }

    return media/i;
}

int main(){

    list<int> lista;    //"ponteiro" para a lista
    int x;    //variavel auxiliar para inserir na lista

    cin >> x;

    while(x != 0){
        lista.push_back(x);
        cin >> x;
    }

    cout << fixed << setprecision(2) << calcMedia(lista) << endl;

    while(!lista.empty()){  //limpa a lista
        x = *lista.begin();
        lista.pop_front();
    }

    return 0;
}