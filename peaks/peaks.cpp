#include <bits/stdc++.h>
using namespace std;

bool isGood(vector<int> &adj,  vector<int> &h, int i){
  for(int viz : adj){
    if(h[i] <= h[viz]){
      return false;
    }
  }
  
  return true;
}


int main(){
  long long n, m;
  int ans = 0;

  cin >> n >> m;

  vector<int> h(n + 1);
  vector<int> adj[n + 1];

  for(int i = 1; i < n + 1; ++i){
    cin >> h[i];
  }

  for(int i = 1; i < m + 1 ; ++i){
    int a,b; 
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i < n + 1; ++i){
    // entrar em cada array e verificar o h dos vizinhos, se h[i] > h[vizinhos] ans++
    if(isGood(adj[i], h, i)){
      ans++;
    }
  }
  cout << ans << "\n";

  return 0; 
}


 