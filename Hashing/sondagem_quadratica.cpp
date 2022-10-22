#include <iostream>
#include <cmath>

using namespace std;
 
int hash_aux(int k, int m){
    int aux;
    aux=k%m;
    
    if(aux<0){
        aux=aux+m;
    }

    return aux;
}

int hash2(int k, int i, int m, int c1, int c2){
    int x;
    
    x=(hash_aux(k,m)+c1*i+c2*pow(i,2));
    
    return x%m;
}
 
int main(){
  
    int k,m,c1,c2;
    
    cin>>k>>m>>c1>>c2;
    
    for(int i=0;i<m;i++){
        cout<<hash2(k,i,m,c1,c2)<<" ";
    }
}