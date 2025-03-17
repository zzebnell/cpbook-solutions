/*
  user: zebnel
  team: ...
  created: 2025-02-08 17:47:09
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  vector<int> stage(m + 1);
  for (int i = 0; i < m; i++) {
    stage[i + 1] = stage[i] + v[0][i];
  }
  vector<int> ans;
  ans.push_back(stage[m]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      stage[j + 1] = max(stage[j + 1], stage[j]) + v[i][j];
    }
    ans.push_back(stage[m]);
  }
  for (int i = 0; i < int(ans.size()); i++) {
    cout << (i ? " " : "") << ans[i];
  }
  cout << '\n';

  return 0;
}
