#include <iostream>
#include <cstring>

using namespace std;

struct aluno{
    char nome[100];
    char curso[100];
    int matricula;
};

int main() {
    int N;
    char aluno_buscado[100];
    bool aux = false;

    cin >> N;
    aluno alunos[N];
    
    for(int i=0; i<N; i++) {
        cin.ignore();
        cin.getline(alunos[i].nome, 100);
        cin.getline(alunos[i].curso, 100);
        cin >> alunos[i].matricula;
    }
    
    cin.ignore();
    cin.getline(aluno_buscado, 100);
    
    for(int i=0; i<N; i++)
        if(strcmp(alunos[i].nome, aluno_buscado) == 0) {
            cout << alunos[i].nome << endl;
            cout << alunos[i].curso << endl;
            cout << alunos[i].matricula << endl;
            aux = true;
        }

    if(aux == false)
        cout << "Aluno nao localizado" << endl;	

    return 0;
}