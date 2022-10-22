#include <iostream>

using namespace std;

struct dado{
    int k;      //chave
    int status; //0:vazio 1:ocupado 
};

int hash_aux(int k, int m){
    int h;
    while(k < 0){
        k += m;
    }
    h = k % m;
    return h;
}

int hash1(int k, int i, int m){
    int h;
    h = (hash_aux(k, m) + i) % m;
    return h;
}

int hash_insert(dado t[], int m, int k){
    int i = 0;
    int h = hash1(k, i, m);
    while((t[h].status == 1) && (i < m)){
        i++;
        h = hash1(k, i, m);
    }
    if(i < m){
        t[h].k = k;
        t[h].status = 1;
        return h;
    }
    else{
        return -1;
    }
}

int main()
{
    int m;
    cin >> m;
    dado t[m];
    for(int i = 0; i < m; i++){
        t[i].k = -1;
        t[i].status = 0;
    }
    int k;
    cin >> k;
    while(k != 0){
        hash_insert(t, m, k);
        cin >> k;
    }
    for(int i = 0; i < m; i++){
        cout << t[i].k << " ";
    }

    return 0;
}
