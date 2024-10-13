#include <iostream>
using namespace std;

//Definindo um um nó
struct NO{
    int dado;
    NO *prox;
};

//Insere um novo nó no fim da lista
void enfileirar(NO* &cabeca, int novodado){
    NO* novono = new NO();
    novono->dado = novodado;
    novono->prox = nullptr;
    if(cabeca==nullptr){
        cabeca=novono;
    }
    else{
        NO *temp = cabeca;
        while(temp->prox != nullptr){
            temp = temp->prox;
        }
        temp->prox = novono;
    }
};

//Remove a cabeca da lista
void Remover(NO* &cabeca){
    if(cabeca!=nullptr){
        cout << "Removendo elemento: " << cabeca->dado << endl;
        NO* temp = cabeca;
        cabeca = cabeca->prox;
        delete temp;
    }
};

void IMPRIMIRLISTA(NO* cabeca){
NO *temp=cabeca;
cout<<"MINHA LISTA:";
while(temp!=nullptr){
    cout<< temp->dado <<"->";
    temp=temp->prox;
    }
    cout<<"NULL"<<endl;
};

int main(){
    NO* fila = nullptr;
    int valor1, valor2, valor3;

    cout<<"Insira um valor: ";
    cin>>valor1;
    enfileirar(fila, valor1);
    cout<<"Insira um valor: ";
    cin>>valor2;
    enfileirar(fila, valor2);
    cout<<"Insira um valor: ";
    cin>>valor3;
    enfileirar(fila, valor3);

    IMPRIMIRLISTA(fila);

    cout<<" "<<endl;

    Remover(fila);
    Remover(fila);
    Remover(fila);

    IMPRIMIRLISTA(fila);

    return 0;
}
