#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
    int i,j;
    int trab;
    bool troca;
    int limite;
    int contadorTrue = 0;
    
    troca = true;
    limite = tamanho-1;
    while(troca)
    {
        troca = false;
        for(i=0;i<limite;i++)
        if(vetor[i]>vetor[i+1])
        {
            trab = vetor[i];
            cout<<"New trab: "<<trab<<endl;
            vetor[i] = vetor[i+1];
            vetor[i+1]= trab;
            j = i;
            troca = true;
            contadorTrue++;
        }
        limite = j;
    }
    cout<<"Contador: "<<contadorTrue<<endl;
}

int main()
{
    int n;
    do{
        cin>>n;
    }while(n<1);
    int vetor[n];
    int i=0;
    for(i=0;i<n;i++)
    {
        cin>>vetor[i];
    }
    int tamanho;
    tamanho=i+1;
    bubbleSort(vetor,tamanho);
    
    return 0;
}