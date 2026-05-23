#include <iostream>

int main(int argc, char const *argv[])
{
    std::string nombre;

    while(nombre.empty()){
        std::cout << "Ingresa tu nombre: ";
        std::getline(std::cin, nombre);
    }

    std::cout << "Hola: " << nombre << std::endl;

    do
    {
        /* code */
    } while (false);

    for (int i = 0; i < 3; i++)
    {
        /* code */
    }
    
    int notas[] = {65, 72, 81, 93};

    for(int nota: notas){
        std::cout << nota << '\n';
    }
    
    return 0;
}
