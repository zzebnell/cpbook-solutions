/*
  user: zebnel
  created: 2025-03-23 21:04:00
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n >> q;
    vector<int> ans(230), v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < 230; i++) {
      for (int& a : v) {
        ans[i] = max(ans[i], i & a);
      }
    }
    int a;
    while (q--) {
      cin >> a;
      cout << ans[a] << '\n';
    }
  }

  return 0;
}
