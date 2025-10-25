#include <iostream> //entrada salida
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>  // Para el comando del sistema (graphviz)

using namespace std;

// Definición de un nodo en el Árbol de Merkle
struct Node {
    string hash;
    Node* left;
    Node* right;

    Node(const string& data) : hash(data), left(nullptr), right(nullptr) {}
};

// Implementación básica del algoritmo SHA-256 (simplificado para fines didácticos)
string sha256(const string &input) {
    // Simulación de SHA-256 para hacerlo más sencillo
    string hash = "0000"; // Representa un hash simulado
    return hash + input; // Añade el input al hash simulado
}

// Función para combinar dos nodos y crear su nodo padre
Node* combineNodes(Node* left, Node* right) {
    string combinedHash = sha256(left->hash + right->hash);
    Node* parent = new Node(combinedHash);
    parent->left = left;
    parent->right = right;
    return parent;
}

// Función recursiva para construir el Árbol de Merkle
Node* buildMerkleTree(Node** leaves, int start, int end) {
    // Si solo hay una hoja, retorna el nodo hoja
    if (start == end) {
        return leaves[start];
    }

    // Encuentra el punto medio para dividir la lista de hojas
    int mid = (start + end) / 2;

    // Construir el subárbol izquierdo y derecho de manera recursiva
    Node* leftSubTree = buildMerkleTree(leaves, start, mid);
    Node* rightSubTree = buildMerkleTree(leaves, mid + 1, end);

    // Combinar los dos subárboles en un nodo padre
    return combineNodes(leftSubTree, rightSubTree);
}

// Función para generar el archivo .dot para Graphviz
void generateDotFile(Node* node, ofstream &outFile, int& nodeCounter) {
    if (!node) return;

    int currentNode = nodeCounter++;
    outFile << "node" << currentNode << " [label=\"" << node->hash << "\"];\n";

    if (node->left) {
        int leftNode = nodeCounter;
        outFile << "node" << currentNode << " -- node" << leftNode << ";\n";
        generateDotFile(node->left, outFile, nodeCounter);
    }

    if (node->right) {
        int rightNode = nodeCounter;
        outFile << "node" << currentNode << " -- node" << rightNode << ";\n";
        generateDotFile(node->right, outFile, nodeCounter);
    }
}

// Función para generar el gráfico del Árbol de Merkle
void graphMerkleTree(Node* root) {
    ofstream outFile("merkle_tree.dot");
    outFile << "graph MerkleTree {\n";

    int nodeCounter = 0;
    generateDotFile(root, outFile, nodeCounter);

    outFile << "}\n";
    outFile.close();

    // Ejecutar el comando para generar la imagen con Graphviz
    system("dot -Tpng merkle_tree.dot -o merkle_tree.png");
    cout << "Árbol de Merkle graficado en merkle_tree.png\n";
}

int main() {
    // Ejemplo de datos que serán las hojas del árbol de Merkle
    const int numLeaves = 4;
    string data[numLeaves] = {"data1", "data2", "data3", "data4"};

    // Crear los nodos hojas dinámicamente
    Node* leaves[numLeaves];
    for (int i = 0; i < numLeaves; ++i) {
        leaves[i] = new Node(sha256(data[i]));
    }

    // Construir el Árbol de Merkle recursivamente
    Node* root = buildMerkleTree(leaves, 0, numLeaves - 1);

    // Imprimir el hash raíz del Árbol de Merkle
    cout << "Merkle Root Hash: " << root->hash << endl;

    // Generar el archivo .dot y graficar el árbol
    graphMerkleTree(root);

    // Liberar memoria (opcional)
    delete root;

    return 0;
}
