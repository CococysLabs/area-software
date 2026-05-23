#include "ListaCircular.h"

ListaCircular::ListaCircular(){
    largo = 0;
    primero = nullptr;
}

ListaCircular::~ListaCircular(){
    Nodo *temp = primero->getSig();
    Nodo *aux;

    while(temp != primero){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }

    delete temp;
}

void ListaCircular::push(int data){
    Nodo *nuevo = new Nodo(data);
    Nodo *temp;

    //Si la lista cirular no se encuentra vacía
    if(primero != nullptr){
        temp = primero;

        //Obtenemos el nodo cuyo siguiente es el "primero" de nuestra lista
        while(temp->getSig() != primero){
            temp = temp->getSig();
        }

        //El siguiente de nuestro nuevo nodo debe ser el primero
        nuevo->setSig(primero);

        //Como "temp" contiene el valor del nodo que anteriormente tenía en su
        //siguiente a "primero", cambiamos este puntero al nuevo nodo, ya que este será
        //el nuevo "primero"
        temp->setSig(nuevo);
    }else{

        //Si la lista se encuentra vacía entonces simplemente se establece el siguiente 
        //de nuestro nuevo nodo a sí mismo, ya que es una lista circular
        nuevo->setSig(nuevo);
    }

    //Nuestro "primero" siempre se establecerá al nuevo nodo que estemos agregando
    //Ya que esta función es un push
    primero = nuevo;
    largo++;
}

void ListaCircular::append(int data){
    Nodo *nuevo = new Nodo(data);
    Nodo *temp;

    //Si la lista circular no se encuentra vacía
    if(primero != nullptr){

        //Se almacena en la variable "temp" el puntero al nodo cuyo siguiente es el primero de la lista
        temp = primero;
        while(temp->getSig() != primero){
            temp = temp->getSig();
        }

        //Se establece el siguiente de nuevo como el primero de nuestra lista
        nuevo->setSig(primero);

        //Posteriormente el nodo que anteriormente tenía en su siguiente al primero de la lista
        //Se actualiza para que ahora tenga al nuevo que acabamos de insertar
        temp->setSig(nuevo);
    
    }else{
        //Si la lista se encuentra vacía simplemente se inserta el nodo nuevo 
        //En su siguiente se establece a sí mismo
        nuevo->setSig(nuevo);

        //En el caso del append solamente se establece el primero como el nodo nuevo si la lista se
        //encuentra vacía, ya que es un append y los valores se insertan al final
        primero = nuevo;
    }
    largo++;
}

void ListaCircular::print(){
    Nodo *temp = primero;

    if(primero != nullptr){
        //En este caso se usa un ciclo do-while, ya que como les comentaba en clase
        //este tipo de ciclo siempre realiza la primera iteración, lo que nos permite que se escriba el 
        //nodo que se encuentra en "primero" y que cuando ya se haya escrito toda la lista circular
        //y nuestro puntero "temp" vuelva a encontrarse señalando a "primero" se active la condición
        //temp != primero y se termine el ciclo.
        do{
            std::cout << temp->getData() << ", " << std::endl;
            temp = temp->getSig();
        }while(temp != primero);
    }
}

void ListaCircular::graph(){
    //Deben tener incluído <fstream>, en este ejemplo se encuentra incluído en 
    //El archivo nodo.h

    //Se crea el archivo .dot
    std::ofstream outfile("listaCircular.dot");

    //Variable string donde se guardarán las conexiones entre los nodos del grafo
    std::string conexiones;

    //En esta variable se almacena el valor de "index" en formato string
    std::string numeroNodo;

    //Variable para recorrer la lista circular
    Nodo *temp = primero;

    //Índice que servirá para darle nombre a los nodos
    int index = 0;

    //Se da nombre al grafo que se creará y se abre llaves
    //esto se escribe en el archivo que se acaba de crear
    outfile << "digraph G {" << std::endl;

    //Solamente se entra al if si la lista no se encuentra vacía
    
    if(primero != nullptr){
        //Se usa un ciclo do-while para recorrer la lista circular
        do{
            //Se convierte el valor de "index" a cadena y se almacena en "numeroNodo"
            numeroNodo = std::to_string(index);

            //Se escribe en el archivo que se creó la declaración del nodo
            //Ejemplo: Nodo0[label="5"]
            outfile << "Nodo" + numeroNodo + "[label = \""+std::to_string(temp->getData())+"\"]" << std::endl;

            //Se escribe la conexión que tendrá el nodo actual con su siguiente nodo en la lista
            //Ejemplo: Nodo0->
            conexiones = conexiones + "Nodo" + numeroNodo + "->";

            temp = temp->getSig();
            index+=1;
        }while(temp != primero);

        //Como sabemos, es una lista circular por lo cual el nodo al que tiene
        //que apuntar el último nodo de la lista es al primero, por lo cual lo
        //último que se concatena a "conexiones" es el nombre de nuestro primero nodo 
        //en la lista, que siempre será Nodo0
        conexiones = conexiones + "Nodo0";
    }

    //Se escriben las conexiones en el archivo .dot
    outfile << conexiones << std::endl;

    //Rankdir sirve para que la orientación de nuestro grafo sea de izquierda a derecha
    //LR = Left->Rigth
    outfile << "rankdir = LR" << std::endl;

    //Se cierran llaves
    outfile << "}" << std::endl;

    //Se cierra el archivo
    outfile.close();

    //Ejecutamos el comando para generar la imagen en base al archivo recién creado
    int returnCode = system("dot -Tpng ./listaCircular.dot -o ./listaCircular.png");

    //Mensaje en caso el comando se haya ejecutado de forma correcta o no
    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl;}
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}
}