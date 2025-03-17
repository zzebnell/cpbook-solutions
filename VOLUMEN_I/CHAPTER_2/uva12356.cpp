/*
  user: zebnel
  team: ...
  created: 2025-01-29 00:30:05
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int s, b;
  while (cin >> s >> b && (s && b)) {
    vector<pair<int, int>> v(s + 2);
    for (int i = 1; i <= s; i++) {
      v[i] = {i - 1, i + 1};
    }
    int l, r;
    while (b--) {
      cin >> l >> r;
      v[v[l].first].second = v[r].second;
      v[v[r].second].first = v[l].first;
      int p, q;
      p = v[l].first;
      q = v[r].second;
      if (!p || p > s) cout << "* ";
      else cout << p << ' ';
      if (!q || q > s) cout << '*' << '\n';
      else cout << q << '\n';
    }
    cout << '-' << '\n';
  }

  return 0;
}
