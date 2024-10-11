#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring> 	//para strln()
using namespace std;

struct Candidato{
	string nome;
	int idade;
	string identificador;
	int numero;
};

struct Eleitor{
	string nome;
	int idade;
	string identificador;
	string voto;	
};

bool validarIdentificador(const string& identificador){
//Verifica se o identificador possui exatamente 5 digitos
	return identificador.size() == 5 && strspn(identificador.c_str(), "0123456789") == 5;
}
	int main(){
	map<string, int> votos_eleitores;
//Mapa para armazenar os votos dos eleitores por nummero de candidato
	vector<Eleitor> eleitores;
//Vetor para armazenar os eleitores
	vector<Candidato> candidatos;
//Vetor para armazenar os candidatos
	string nome, identificador, voto;
	int idade, numero;
	
	const int maxEleitores = 2; 	//Definindo o numero maximo de eleitores
	
	//Definindo a variavel candidatos fora do loop while
	string vencedor;
	int maxVotos = 0;
	
	int numEleitores = 0; 			//Variavel para contar  o numero atual dos eleitores
	
	while (numEleitores < maxEleitores){
	//Verifica se o numero  atual de eleitores e menor que o limite
		Eleitor novo_eleitor;
	
	cout<<"\nDigite o nome do eleitor: ";
	cin>>nome;
	novo_eleitor.nome = nome;
	
	cout<<"Digite a idade do eleitor: ";
	cin>>idade;
	novo_eleitor.idade = idade;

	//Validacao do identificador
	do {
		cout<<"Digite o identificador do eleitor(5 digitos): ";
		cin>>identificador;
	} while (!validarIdentificador(identificador));
	novo_eleitor.identificador = identificador;
	
	cout<<"Digite o nome do candidato que deseja votar (Ou 'branco' para voto bem branco: ";
	cin>>voto;
	novo_eleitor.voto = voto;

	eleitores.push_back(novo_eleitor);		//Adiciona o eleitor ao vetor de eleitores
	votos_eleitores[voto]++; //Incrementa os votos para o candidato conrrespondente
	numEleitores++; 		//Incrementa o contador de eleitores
//Atualiza o numero maximo de votos

if (votos_eleitores[voto] > maxVotos){
	maxVotos = votos_eleitores[voto];
	}
}

if (numEleitores == 0){
	cout<<"Nao houve eleitores. Encerrando o programa."<<endl;
} else {
if (maxVotos > 0){
cout<< "O vencedor da eleicao e: " <<vencedor<< ", com" <<maxVotos<< " votos." <<endl;
} else {
cout<<"Nao houve votos lancados. Nao ha vencedor."<<endl;
		}
	}

return 0;
}
