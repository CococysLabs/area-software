#include <iostream>

int main(int argc, char const *argv[])
{
    int age;

    std::cout << "Ingesa tu edad" << std::endl;
    std::cin >> age;

    if (age >= 18)
    {
        std::cout << "Eres mayor de edad" << std::endl;
    
    }else
    {
        std::cout << "No mayor de edad" << std::endl;
    }
    
    
    int month;
    std::cout << "Ingrese un número de mes: " << std::endl;
    std::cin >> month;

    switch(month){
        case 1:
            std::cout << "Enero" << std::endl;
            break;

        case 2:
            std::cout << "Febrero" << std::endl;
            break;

        default:
            std::cout << "No existe este mes" << std::endl;
            break;
    }

    int nota = 62;
    std::cout << (nota >= 61 ? "Aprobaste" : "Reprobaste");
    return 0;
}
