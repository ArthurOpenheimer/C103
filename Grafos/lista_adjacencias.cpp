#include<iostream>
#include<list>

using namespace std;

struct no{
    int v; //destino
    int p; //peso
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
    no aux; //auxiliar para inserir arestas na lista

    aux.v = v;
    aux.p = p;

    adj[u].push_back(aux);
    //inserindo aresta da volta
    if(orientado == 0){
        aux.v = u;
        adj[v].push_back(aux);
    }
}

int main(){

    int nVertices;
    int ord;
    list<no>:: iterator q; //iterador para percorrer a lista
    list<no> adj[10];  //lista de adjacencia
    int u, v; //origem e destino da aresta
    int p; //peso da aresta

    cin >> nVertices >> ord;

    cin >> u >> v >> p;
    while((u != -1)&&(v != -1)&&(p != -1)){
        cria_aresta(adj, u, v, p, ord);
        cin >> u >> v >> p;
    }

    for(int i = 0; i<nVertices; i++){
        for(q=adj[i].begin(); q!=adj[i].end(); q++){
            cout << i << " " << q->v << " " << q->p << endl;
        }
    }

    return 0;
}