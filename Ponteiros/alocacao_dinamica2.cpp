#include<iostream>

using namespace std;

struct notas{
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    float media;
};


int main(){

    notas *p;
    int N;
    cin >> N;
    p = new notas[N];
    float aux = 0; //auxiliar pra calcular a média das médias

    for(int i = 0; i < N; i++){
        cin >> p[i].nota1;
        cin >> p[i].nota2;
        cin >> p[i].nota3;
        cin >> p[i].nota4;
        p[i].media = (p[i].nota1 + p[i].nota2 + p[i].nota3 + p[i].nota4)/4.0;
    }

    for(int i = 0; i < N; i++){
        aux += p[i].media;
    }
    aux /= N;
    cout << aux << endl;
    
    delete p;

    return 0;
}