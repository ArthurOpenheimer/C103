#include <iostream>

using namespace std;

void insertionSort(int vetor[], int tamanho)
{
    int i,j;
    int chave;
    for(j=0;j<tamanho;j++)
    {
        chave = vetor[j];
        i = j-1;
        while((i>=0)&&(vetor[i]<chave))
        {
            vetor[i+1]=vetor[i];
            i=i-1;
        }
        vetor[i+1]=chave;
    }
}

int main() {
    int vetor[100];
    int tamanho = 0;
    int valor;
    cin >> valor;
    
    while (valor != 0){
        vetor[tamanho] = valor;
        tamanho++;
        cin >> valor;
    }
    
    insertionSort(vetor, tamanho);
    
    for(int i=0;i<tamanho-1;i++)
        cout<<vetor[i]<<"\n";    
    cout<<vetor[tamanho-1];
    
    return 0;
}