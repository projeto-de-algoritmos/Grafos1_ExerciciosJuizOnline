#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define TAMANHOMAXIMO 2010

vector<vector<bool>> grafo(TAMANHOMAXIMO, vector<bool>(TAMANHOMAXIMO, false));
vector<bool> visitado(TAMANHOMAXIMO);

int n;

void buscaProfundidade(int u);

int main() {
    int m, u, v, p, i, j;

    while (cin >> n >> m, m && n) {
        grafo.assign(TAMANHOMAXIMO, vector<bool>(TAMANHOMAXIMO, false));

        for (i = 0; i < m; ++i) {
            cin >> u >> v >> p;
            if (p == 1)
                grafo[u][v] = true;
            else
                grafo[u][v] = grafo[v][u] = true;
        }

        bool flag = false;
        for (i = 1; i <= n; ++i) {
            visitado.assign(TAMANHOMAXIMO, false);
            buscaProfundidade(i);
            flag = false;
            for (j = 1; j < n && !flag; ++j)
                if (!visitado[j])
                    flag = true;

            if (flag)
                break;
        }

        cout << (flag ? 0 : 1) << endl;
    }

    return 0;
}

void buscaProfundidade(int u) {
    visitado[u] = true;
    for (int i = 1; i <= n; ++i)
        if (grafo[u][i] && !visitado[i])
            buscaProfundidade(i);
}
