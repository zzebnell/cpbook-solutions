/*
  user: zebnel
  team: ...
  created: 2025-03-02 23:40:41
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
    vector<pair<string, string>> v(n, {"", ""});
    for (int i = 0; i < n; i++) {
      cin >> v[i].second;
      v[i].first.push_back(v[i].second[0]), v[i].first.push_back(v[i].second[1]);
    }
    stable_sort(v.begin(), v.end(), [&](auto a, auto b) {
      return a.first < b.first;
    });
    for (auto& p : v) {
      cout << p.second << '\n';
    }
    cout << '\n';
  }

  return 0;
}
