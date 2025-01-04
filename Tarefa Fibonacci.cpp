#include <iostream>
using namespace std;

int FIBONACCI(int n){
    //Definindo os dois primeiros numeros da sequencia como um
    int NUM[100000];
    NUM[0] = 1;
    NUM[1] = 1;

    //Calcula os números subsequentes da sequência de Fibonacci, até o índice n
    for(int i = 2; i <= n; i++){
        NUM[i] = NUM[i-1] + NUM[i-2];
    }
    //Retorna o n-ésimo número da sequência de Fibonacci.
    return NUM[n-1];
}
int main()
{   int n;

    cout<<"Digite o numero da sequencia: ";
    cin>>n;
    cout<<FIBONACCI(n)<<endl;
    return 0;
}
