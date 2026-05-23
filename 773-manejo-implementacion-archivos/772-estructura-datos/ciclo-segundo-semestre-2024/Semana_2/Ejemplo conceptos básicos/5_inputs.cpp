#include <iostream>

int main(int argc, char const *argv[])
{
    std::string nombre;
    int edad;

    std::cout << "Cual es tu nombre? " << std::endl;
    std::getline(std::cin, nombre);

    std::cout << "Cual es tu edad? " << std::endl;
    std::cin >> edad;
    //std::getline(std::cin >> std::ws, nombre);

    std::cout << edad << std::endl;
    std::cout << nombre << std::endl;
    return 0;
}
