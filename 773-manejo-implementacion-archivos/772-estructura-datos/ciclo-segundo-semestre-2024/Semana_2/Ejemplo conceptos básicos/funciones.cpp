#include <iostream>

void holaMundo(std::string &nombre);
std::string holaMundoReturn(std::string nombre);

int main(int argc, char const *argv[])
{
    std::string resultado = "Jose";
    std::cout << resultado << std::endl;
    holaMundo(resultado);
    std::cout << resultado << std::endl;
    return 0;
}

void holaMundo(std::string &nombre){
    nombre = "Hola mundo " + nombre;
}

std::string holaMundoReturn(std::string nombre){
    return  "Hola mundo " + nombre;
}