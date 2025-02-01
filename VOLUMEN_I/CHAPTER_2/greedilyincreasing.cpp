/*
  user: zebnel
  team: ...
  created: 2025-01-31 18:31:48
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
  int mx = v[0];
  vector<int> ans;
  ans.push_back(v[0]);
  for (int i = 1; i < n; i++) {
    if (v[i] > mx) {
      mx = v[i];
      ans.push_back(mx);
    }
  }
  cout << ans.size() << '\n';
  for (int& a : ans) {
    cout << a << ' ';
  }
  cout << '\n';

  return 0;
}
