#include <iostream>
using namespace std;

//Definindo o NO
struct NO{
    int dado;
    NO *prox;
};

//Funcao que adiciona novo dado
void inserirFinal(NO* &cabeca, int novodado){
    NO* novono = new NO();
    novono->dado = novodado;
    novono->prox = nullptr;
    if(cabeca == nullptr){
        cabeca = novono;
    }
    else{
        NO *temp = cabeca;
        while(temp->prox != nullptr){
            temp = temp->prox;
        }
        temp->prox = novono;
    }
};

//Imprime a lista
void IMPRIMIRLISTA(NO* cabeca){
    NO *temp = cabeca;
    cout<<"LISTA: ";
    while(temp != nullptr){
        cout<<temp->dado<<"->";
        temp = temp->prox;
    }
    cout<<"NULL"<<endl;
};

//Funcao que organiza a lista
void selectSort(NO* cabeca){

    //Procura o menor elemento
    NO* temp = cabeca;
    while(temp != nullptr){
        NO* menor = temp;
        NO* temp2 = temp->prox;
        while(temp2 != nullptr){
            if(temp2->dado < menor->dado){
                menor = temp2;
            }
            temp2 = temp2->prox;
        }
        //Trocando os dados
        int aux = temp->dado;
        temp->dado = menor->dado;
        menor->dado = aux;

        temp = temp->prox; //Atualizando para o proximo no
    }
};

int main(){
    NO* Lista = nullptr;
    int num1, num2, num3, num4;

    cout<<"Digite um numero: ";
    cin>>num1;
    inserirFinal(Lista, num1);
    cout<<"Digite um numero: ";
    cin>>num2;
    inserirFinal(Lista, num2);
    cout<<"Digite um numero: ";
    cin>>num3;
    inserirFinal(Lista, num3);
    cout<<"Digite um numero: ";
    cin>>num4;
    inserirFinal(Lista, num4);

    IMPRIMIRLISTA(Lista);

    selectSort(Lista);
    cout<<"\nLISTA ORDENADA:"<<endl;
    IMPRIMIRLISTA(Lista);
}
