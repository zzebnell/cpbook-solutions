/*
  user: zebnel
  team: ...
  created: 2025-01-28 19:22:25
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<pair<int, int>> curr(n);
    for (int i = 0; i < n; i++) {
      cin >> curr[i].first >> curr[i].second;
    }
    vector<int> ans(n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int pos = curr[i].second;
      if (ans[i + pos] || (i + pos < 0 || i + pos >= n)) {
        ok = false;
        break;
      }
      ans[i + pos] = curr[i].first;
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
      }
      cout << '\n';
    }
  }

  return 0;
}
