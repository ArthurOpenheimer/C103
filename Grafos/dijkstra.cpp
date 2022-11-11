    #include<iostream>
    #include<list>
    #define INT_MAX 999

    using namespace std;

    struct no{
        int v; //destino
        int p; //peso
    };

    void dijkstra(list<no>adj[], int nVertices, int start, int end){
        int distancia[nVertices];
        int parent[nVertices];
        int intree[nVertices];
        int v, destino, weight, dist;
        int custo = 0;
        int i;
        list<no>:: iterator q; 

        for(i=0; i<nVertices; i++){
            distancia[i] = INT_MAX;
            parent[i] = -1;
            intree[i] = 0;
        }

        distancia[start] = 0;
        v = start;

        while(intree[v] == false){
            intree [v] = true;
            for(q=adj[v].begin(); q!=adj[v].end(); q++){
                destino = q->v;
                weight = q->p;
                // if((distancia[destino] > weight) && (intree[destino] == false)){
                //     distancia[destino] = weight;
                //     parent[destino] = v;
                // }
                if (distancia[destino] > distancia[v] + weight){
                    distancia[destino] = distancia[v] + weight;
                    parent[destino] = v;
                }
            }

            v = 0;
            dist = INT_MAX;
            for(i=0; i<nVertices; i++){
                if((distancia[i] < dist) && (intree[i] == false)){
                    dist = distancia[i];
                    v = i;
                }
            }
        }

        list<int> caminho;

        caminho.push_front(end);

        for (int pai = parent[end]; pai != -1; pai = parent[pai]){
            caminho.push_front(pai);
        }

        cout << "Menor caminho: " << endl;

        for(list<int>::iterator it = caminho.begin(); it != caminho.end(); it++){
            cout << *it << " ";
        }

        cout << endl;
        cout << "Custo: " << distancia[end] << endl;
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

        list<no> adj[10];     
        int nVertices;        
        int u, v, p;             //origem, destino e peso
        list<no>::iterator q; 
        int orientado;        
        int inicial;
        int destino;     

        cin >> nVertices >> orientado >> inicial >> destino;

        cin >> u >> v >> p;
        while (u != -1 && v != -1 && p != -1)
        {
            cria_aresta(adj, u, v, p, orientado);
            cin >> u >> v >> p;
        }
        
        dijkstra(adj, nVertices, inicial, destino);

        return 0;
    }