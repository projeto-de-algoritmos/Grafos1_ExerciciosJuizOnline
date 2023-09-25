#include <iostream>
#include <vector>

using namespace std;

const int MAX_TAMANHO = 10040;

vector<int> entrada(MAX_TAMANHO);
vector<int> visitado(MAX_TAMANHO);
vector<int> saida(MAX_TAMANHO);
vector<int> adjacencia(MAX_TAMANHO);

int n;

bool resolver();

int main()
{
    cin >> n;
    cout << (resolver() ? "S" : "N") << endl;
    return 0;
}

bool resolver()
{
    vector<int> entrada(MAX_TAMANHO, 0);
    vector<int> saida(MAX_TAMANHO, 0);

    int i, u, v;
    int ans = 0;

    for (i = 1; i <= n; ++i)
    {
        cin >> u >> v;
        adjacencia[u] = v;
        ++saida[u];
        ++entrada[v];
    }

    for (i = 1; i <= n; ++i)
        if (entrada[i] != 1 || saida[i] != 1)
            return false;

    i = 1;
    while (visitado[i] == 0)
        visitado[i] = 1, ++ans, i = adjacencia[i];

    if (ans != n)
        return false;

    return true;
}
