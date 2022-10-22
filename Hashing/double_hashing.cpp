#include <iostream>
using namespace std;

int hash_aux(int k, int m){
	int h;
	h=k % m;
	if(h<0){
		h+=m;
	}
	return h;
}

int h1(int k, int m){
	int h1;
	h1 = k % m;
	return h1;
}

int h2(int k, int m){
	int h2;
	h2 =1+(k %(m-1));
	if(h2<0){
		h2+=m;
	}
	return h2;  
}

int dhash(int k, int m, int i){
	int h3;
	h3 =(hash_aux(k,m) + i * h2(k,m)) % m;
	return h3;
}

int main()
{
	int k, m, i;
	cin>>k>>m;
	
	
	for(i=0;i<m;i++){
		cout<<dhash(k,m,i)<< " ";
	}
	return 0;
}