/*
  user: zebnel
  team: ...
  created: 2025-02-03 17:03:44
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
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> mx(n + 1, -INF), mn(n + 1, INF);
  for (int i = 0; i < n; i++) {
    mx[i + 1] = max(mx[i], v[i]);
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    mn[i + 1] = min(mn[i], v[i]);
  }
  reverse(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((mx[i] <= v[i]) && (mn[n - (i + 1)] > v[i])) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
