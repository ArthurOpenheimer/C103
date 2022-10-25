#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v;    // destino
    int p; // peso
};

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
        cout << u << endl;
        for (it = adj[u].begin(); it != adj[u].end(); it++){
            v = it->v;                     // destino da aresta
            cout << u << " " << v << endl; // imprime vértice u e vértice v
            if (state[v] == -1){
                state[v] = 0;   // visitado
                p[v] = u;       // armazena o pai de v
                Q.push_back(v); // insere v na fila
            }
        }
        state[u] = 1;
    }
}

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

int main()
{

    list<no> adj[100];
    int nVertices;
    int u, v;             // origem e destino
    int p;                // peso
    int i;                // contador
    list<no>::iterator q; // iterador para percorrer lista de adjacência
    int orientado;
    int inicial;

    cin >> nVertices >> inicial;

    //inserindo aresta
    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1){
        cria_aresta(adj, u, v, p, 0);
        cin >> u >> v >> p;
    }

    //imprime versos e arestas visitados
    bfs(adj, nVertices, inicial);

    //limpar a memória
    for (i = 0; i < nVertices; i++){
        adj[i].clear();
    }

    return 0;
}