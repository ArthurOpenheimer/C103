#include <iostream>

using namespace std;

struct dado{
int k;			
int status;
};

int hash_aux (int k, int m){
    int aux;
    aux = k % m;

    if (aux < 0){
        aux = +m;
    }
    return aux;
}

int hash1 (int k, int i, int m){
    int h1;
    h1 = hash_aux (k, m);

    return (h1 + i) % m;
}

int hash_insert (dado t[], int m, int k){
    int i = 0;
    int j;
    do{
        j = hash1 (k, i, m);
        if ((t[j].status) != 1)
        {
        t[j].k = k;
        t[j].status = 1;
        return j;
        }
        else
        i++;
    }while (i != m);
    return -1;
}

int hash_search (dado t[], int m, int k){
    int i = 0;
    int j;
    do{
        j = hash1(k, i, m);
        if (t[j].k == k)
        return j;
        i++;
        }while (t[j].status != 0 && i < m);

    return -1;
}

int main (){
    dado t[100];
    int m, k, x;
    int i = 0;
    int pos;

    cin >> m;
    cin >> k;

    for (i = 0; i < m; i++){
        t[i].k = -1;
        t[i].status = 0;
    }

    while (k != 0){
        hash_insert (t, m, k);
        cin >> k;
    }

    cin >> x;

    pos = hash_search (t, m, x);
    if (pos == -1){
        cout << "Chave " <<x<< " nao encontrada" << endl;
    }
    else{
        cout << "Chave " <<x<< " encontrada na posicao " << pos << endl;
    }
    return 0;
}