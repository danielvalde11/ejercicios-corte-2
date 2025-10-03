#include<iostream>
using namespace std;

bool esPalindromoNumero(int num) {
    int original = num;
    int invertido = 0;
    while(num > 0){
        invertido = invertido * 10 + num % 10;
        num = num / 10;    
    }
    return original == invertido;
}

int main() {
    int num;
    cout << "Ingresa un numero: ";
    cin >> num;
    if(esPalindromoNumero(num)) {
        cout << "El numero es un palindromo." << endl;
    } else {
        cout << "El numero no es un palindromo." << endl;
    }
    return 0;
}