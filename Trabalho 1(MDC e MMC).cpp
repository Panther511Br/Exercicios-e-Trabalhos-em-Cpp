#include <iostream>
using namespace std;

/*Dois numeros inteiros (a) e (b).
Depois encontra o resto (r).
Depois substitui (a) por (b), e (b) por (r).
repete os passos 2 e 3.  Quando (r) for zero, o valor de b nesse ponto sera o MDC.
*/
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


/*Recebe um vetor de inteiros "numeros" constante, e calcula o MDC de todos os elementos do vetor.
Comeca com o primeiro elemento e aplica a funcao mdc inteirativamente para cada elemento subsequente.
*/
int mdc_vetor(const int numeros[], int tamanho){
    int resultado = numeros[0];
    for (int i = 1; i < tamanho; i++){
        resultado = mdc(resultado, numeros[i]);
        if(resultado == 1){
            break; //O MDC de qualquer numero com 1 eh 1, entao podemos parar
        }
    }
    return resultado;
}


//funcao para calcular o MMC de dois numeros
int mmc(int a, int b){
    return (a * b)/ mdc(a, b);
}


/*Recebe um vetor de inteiros "numeros" constante, e calcula o MMC de todos os elementos do vetor.
Comeca com o primeiro elemento e aplica a funcao mmc inteirativamente para cada elemento subsequente.
*/
int mmc_vetor(const int numeros[], int tamanho){
    int resultado = numeros[0];
    for (int i = 1; i < tamanho; i++){
        resultado = mmc(resultado, numeros[i]);
    }
    return resultado;
}

int main(){
    int n, valor;

    cout<<"Digite a quantidade de numeros: ";
    cin>>n;

    int numeros[n];
    cout<<"Digite os numeros: ";
    for(int i=0; i<n; i++){
        cin>>numeros[i];
    }

   cout<<"O MDC dos numeros eh: "<<mdc_vetor(numeros, n)<<endl;
   cout<<"O MMC dos numeros eh: "<<mmc_vetor(numeros, n)<<endl;

    return 0;
}
