#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

const int TAM_MAXIMO_NOS = 600;
const int TAM_MAXIMO_ARESTAS = (TAM_MAXIMO_NOS * (TAM_MAXIMO_NOS - 1)) >> 1;

int pai[TAM_MAXIMO_NOS];
int tamanhoConjunto[TAM_MAXIMO_NOS];
vector<Aresta> arestas(TAM_MAXIMO_ARESTAS);

int encontrar(int no) {
    if (no == pai[no])
        return no;
    else
        return pai[no] = encontrar(pai[no]);
}

void trocar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool compararArestas(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

int kruskal(int numArestas) {
    int pesoTotal = 0;
    for (int i = 0; i < numArestas; ++i) {
        int raiz1 = encontrar(arestas[i].origem);
        int raiz2 = encontrar(arestas[i].destino);
        if (raiz1 != raiz2) {
            if (tamanhoConjunto[raiz1] > tamanhoConjunto[raiz2])
                trocar(raiz1, raiz2);
            pai[raiz1] = raiz2;
            tamanhoConjunto[raiz2] += tamanhoConjunto[raiz1];
            pesoTotal += arestas[i].peso;
        }
    }
    return pesoTotal * 2;
}

int main(int argc, char **argv) {
    int numNos, numArestas, numConsultas;
    int origem, destino, peso;

    cin >> numNos >> numArestas >> numConsultas;

    for (int i = 0; i < numArestas; ++i)
        cin >> arestas[i].origem >> arestas[i].destino >> arestas[i].peso;

    for (int i = 0; i <= numNos; ++i)
        pai[i] = i, tamanhoConjunto[i] = 1;

    sort(arestas.begin(), arestas.begin() + numArestas, compararArestas);

    cout << kruskal(numArestas) << endl;

    return 0;
}