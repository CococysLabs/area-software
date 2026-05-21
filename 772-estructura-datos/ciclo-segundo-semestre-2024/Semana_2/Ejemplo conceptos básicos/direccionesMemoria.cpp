#include <iostream>

int main(int argc, char const *argv[])
{
    std::string nombre = "Jose";
    int edad = 22;
    bool estudiante = true;

    std::cout << &nombre << '\n';
    std::cout << &edad << '\n';
    std::cout << &estudiante << '\n';

    std::string *pNombre = &nombre;
    std::cout << pNombre << '\n';
    std::cout << *pNombre << '\n';

    
    return 0;
}


