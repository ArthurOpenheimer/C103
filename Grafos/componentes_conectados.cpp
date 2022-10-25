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

void bfs(list<no> adj[], int nVertices, int s){
    int u;
    int state[nVertices]; // estado do vertice
    int p[nVertices];     // p[u] = v é o pai de u
    int v;
    list<int> Q;

    for (u = 0; u < nVertices; u++){
        if (u != s){
            state[u] = -1; // não visitado
            p[u] = -1;     // sem pais
        }
    }

    state[s] = 0;   // visitado
    p[s] = -1;      // sem pais
    Q.push_back(s);

    list<no>::iterator it;

    while (!Q.empty()){
        u = Q.front();
        Q.pop_front();
        for (it = adj[u].begin(); it != adj[u].end(); it++){
            v = it->v;           // destino da aresta
            if (state[v] == -1){
                state[v] = 0;   // visitado
                p[v] = u;       // armazena o pai de v
                Q.push_back(v); // insere v na fila
            }
        }
        state[u] = 1;
    }

    for(int i = 0; i < nVertices; i++){
        if(state[i] == -1){     //se algum status for -1, o grafo não é conexo
            cout << "nao conexo" << endl;
            return;
        }
    }
    cout << "conexo" << endl;   //se todos os status forem 1, o grafo é conexo
}

int main(){

    int nVertices;
    int ord;
    list<no> adj[10];  //lista de adjacencia
    int u, v; //origem e destino da aresta

    cin >> nVertices >> ord;

    cin >> u >> v;
    while((u != -1)&&(v != -1)){
        cria_aresta(adj, u, v, 1, ord);
        cin >> u >> v;
    }

    bfs(adj, nVertices, ord);   
    
    return 0;
}