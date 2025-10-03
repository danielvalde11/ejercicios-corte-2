#include<iostream>
#include<string>
#include<functional>
#include<unordered_map>
using namespace std;
using operacion = function<float(float, float)>;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Error, debe ingresar 3 argumentos" << endl;
        cerr << "Ejemplo: ./calculadora 5 + 3" << endl;
        return 1;
    }
    try {
        float op1 = stof(argv[1]);
        float op2 = stof(argv[3]);
        string operador = argv[2];
        unordered_map<string, operacion> operaciones = {
            {"+", [](float a, float b) { return a + b; }},
            {"-", [](float a, float b) { return a - b; }},
            {"*", [](float a, float b) { return a * b; }},
            {"/", [](float a, float b) {
                if (b == 0) {
                    throw runtime_error("Error: Division por cero");
                }
                return a / b;
            }}
        };
        if (operaciones.find(operador) == operaciones.end()) {
            cerr << "Error: Operador no válido" << endl;
            cerr << "Operadores válidos: +, -, *, /" << endl;
            return 1;
        }
        float resultado = operaciones[operador](op1, op2);
        cout << "Resultado: " << resultado << endl;
    } catch (invalid_argument& e) {
        cerr << "Error: Argumentos no válidos. Deben ser números." << endl;
        return 1;
    } catch (runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}