/*
  user: zebnel
  team: ...
  created: 2025-02-03 17:20:41
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
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (v[i][j] != '_') {
        ok = 0;
        break;
      }
    }
    ans += ok;
  }
  cout << ans + 1 << '\n';

  return 0;
}
