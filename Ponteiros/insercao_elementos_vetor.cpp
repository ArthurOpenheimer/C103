#include<iostream>

using namespace std;

int main(){
    int N;
    int *vetor;
    int *p;

    cin >> N;

    vetor = new int[N];
    p = vetor;

    for(int i=0; i<N; i++){
        cin >> *p;
        p++;
    }

    p = vetor;
    
    for(int i=0; i<N; i++){
        cout << *p << endl;
        p++;
    }
}