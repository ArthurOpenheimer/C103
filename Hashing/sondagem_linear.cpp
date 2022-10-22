#include <iostream>
using namespace std;

int hash_aux(int k, int m){
	int r = k % m;
	if (r < 0){
		r = r + m;
	}
	return (r);

}

int hash1(int k, int i, int m){

	int r = (hash_aux(k, m) + i) % m;
	if (r < 0){
		r = r + m;
	}
	return (r);
}

int main (){
	int k = 1, m = 1, h, i = 0;

	cin >> k;
	cin >> m;
	
	for (int i = 0; i < m; i++){
		h = hash1(k, i, m);
		cout << h << " ";	
	}
}