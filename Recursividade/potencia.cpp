#include <iostream>

using namespace std;


int pot(int a, int n){
	if(n == 0)
		return 1;
	else
		return a * pot(a, n-1);

}

int main()
{
	int a, n;
	cin >> a >> n;
	cout << pot(a,n);
}
