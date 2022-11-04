#include<iostream>
#include<list>
#define INT_MAX 999

using namespace std;

struct no{
    int v;    // destino
    int p; // peso
    int estado; // 0 = nao visitado, 1 = visitado, 2 = visitado e adicionado a fila
};

void bfs(list<no>adj[], int nVertices, int s){
    list<int>Q;
    list<no>::iterator p;
    int estado[nVertices];
    int pai[nVertices];
    int u;
    int v;
    for(u = 0; u < (nVertices); u++){
        if(u != s){
            estado[u] = 0;
            pai[u] = -1;
        }
    }

    estado[s] = 1;
    pai[s] = -1;
    Q.push_back(s);

    while(!Q.empty()){
        u = *Q.begin();
        Q.pop_front();
        cout << u << endl;
        for(p = adj[u].begin(); p != adj[u].end(); p++){
            v = p->v;
            cout << u << " " << v << endl;
            if(estado[v] == 0){
                estado[v] = 1;
                pai[v] = u;
                Q.push_back(v);
            }
        }
        estado[u] = 2;
    }
}

void prim(list<no>adj[], int nVertices, int inicial, int final){
    int u = 0, v = 0;
    int G = nVertices;
    int intree[nVertices];
    int distance[nVertices];
    int parent[nVertices];
    int destino;
    int weight;
    int dist;
    list<no>::iterator p;
    for(u = 0; u < G; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
    distance[inicial] = 0;
    v = inicial;
    while(intree[v] == false){
        intree[v] = true;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            destino = p->v;
            weight = p->p;
            if(distance[destino] > weight && intree[destino] == false){
               distance[destino] = weight;
                parent[destino] = v;
            }
        }
        v = 0;
        dist = INT_MAX;
        for(u = 0; u < G; u++){
            if(intree[u] == false && dist > distance[u]){
                dist = distance[u];
                v = u;
            }
        }
    }
    if(distance[final]==1){
        cout << "Ferrovia";
    }else{
        cout << "Rodovia";
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

int main(){

    list<no>adj[10];
    int nVertices;
    int u, v;             // origem e destino
    int p = 1;            // peso
    int i;                // contador
    list<no>::iterator q; // iterador para percorrer lista de adjacência
    int orientado = 0;
    int incial;
    int destino;

    cin >> nVertices;
    cin >> incial;
    cin >> destino;

    cin >> u >> v;
    while((u != -1)&&(v != -1)){
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v;
    }

    prim(adj, nVertices, incial, destino);


    return 0;
}