#include <iostream>
using namespace std;

struct dado
{
	int k;
	int status;
};

//Função Hashing Auxiliar 1
int h1(int k, int m)
{
	int h = k % m;
	if(h < 0)
		h += m;
	return h;
}

//Função Hashing Auxiliar 2
int h2(int k, int m)
{
	int h = 1 + (k % (m - 1));
	if(h < 0)
		h += m;
	return h;
}

//Função Double Hashing
int dhash(int k, int m, int i)
{
	int h = (h1(k, m) + (i * h2(k, m))) % m;
	return h;
}

//Função Hashing Sondagem Linear
int hash1(int k, int i, int m)
{
	int h = (h1(k, m) + i) % m; //Chamando a função Auxiliar   	
	return h;
}

//Função Hashing Incersão de Dados
int hash_insert(dado t[], int m, int k)
{
	int i = 0;
	int j;
	do
	{
		j = dhash(k, m, i);// Chamando a função Double Hashing
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
			i++;
	}while(i != m);
	
	return -1;   	
}

//Função Hashing Pesquisa
int hash_search(dado t[], int m, int k)
{
	int i = 0;
	int j;
	do{
		j = hash1(k, i, m);//Chamando a função Sondagem Linear
		if(t[j].k == k)
			return j;
		
		i++;
	}while(t[j].status != 0 && i < m);
	return -1;
}

//Função Hashing Remoção
int hash_remove(dado t[], int m, int k)
{
	int j = hash_search(t, m, k);//Chamando a função Pesquisa
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0;//Removeu
	}
	else
		return -1;//K não esta na tabela
}

//Função Principal
int main(int argc, char** argv)
{
	//Variáveis
	dado T[20];//Tabela struct com os valores das chaves
	int m;//Tamanho da tabela
	int option;//Opção
	int k;//Valor da chave
	bool flag = false;
	
	//Entrando com o tamanho da tabela
	cin >> m;
	
	//Declarando os valores iniciais
	for(int i = 0; i < m; i++)
	{
		T[i].status = 0;
		T[i].k = -1;
	}
	
	//Processamento
	do{
		cin >> option;
		switch(option)
		{
		case 1://Inserir
			cin >> k;
			hash_insert(T, m, k);
			break;
		
		case 2://Pesquisar
			cin >> k;
			cout << hash_search(T, m, k);
			cout << endl;
			break;
		
		case 3://Remover
			cin >> k;
			hash_remove(T, m, k);
			break;
		
		case 4://Listar tabela
			for(int i = 0; i < m; i++)
			{
				cout << T[i].k << " ";
			}
			cout << endl;
			break;
		
		default://Sair
			flag = true;
			break;
		}
	}
	while(flag != true);
	
	cout << endl;
	
	return 0;
}