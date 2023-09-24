#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 };

bitset<MAX> found;

int dfs(int u, const vector<int>& pn)
{
    if (found[u])
        return u;

    found[u] = true;

    return dfs(pn[u], pn);
}

vector<int> solve(int N, const vector<int>& pn)
{
    vector<int> ans(N + 1);

    for (int u = 1; u <= N; ++u)
    {
        found.reset();
        ans[u] = dfs(u, pn);
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;

    vector<int> pn(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> pn[i];

    auto ans = solve(N, pn);

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << (i == N ? '\n' : ' ');

    return 0;
}