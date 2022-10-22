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
    p = new notas;

    cin >> p->nota1;
    cin >> p->nota2;
    cin >> p->nota3;
    cin >> p->nota4;

    p-> media = (p->nota1 + p->nota2 + p->nota3 + p->nota4)/4.0;

    cout << p->media << endl;

    delete p;

    return 0;
}