#include <iostream>
using namespace std;

//Funcao que imprime os elementos do array.
void imp(int num[], int n){
    for(int i =0; i<6; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
/*
void Troca(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}
*/

int main()
{   int num[6] = {3, 1, 5, 11, 17, 2};
    imp(num, 6); //Chama a função de impressão para mostrar o array inicial.

//Usa um laço for para iterar sobre os elementos do array a partir do segundo elemento.
        int valor=num[i];
        int aux=num[i];//Salva valor 1
        for(int j=i-1; j>=0; j--){
            num[j+1]=num[j];
            if(num[j]<aux){
                num[j+1]=aux;
                break;
            /*Salva o valor atual em aux e move os elementos para a direita até encontrar a posição correta para inserir aux,
            de forma que todos os elementos à esquerda estejam em ordem decrescente.*/
            }
            if(j==0){
            num[j]=aux;
            }
        }
        imp(num, 6); //Imprime o array após cada iteração.
    }
}
