/*
  user: zebnel
  team: ...
  created: 2025-03-08 23:28:33
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M;
  cin >> M;
  cin.ignore();
  string s;
  int obs = 0;
  while (M--) {
    getline(cin, s);
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i].second;
      for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          v[i].first += v[i].second[j] > v[i].second[k];
        }
      }
    }
    stable_sort(v.begin(), v.end(), [](const pair<int, string>& p1, const pair<int, string>& p2) {
      return p1.first < p2.first;
    });
    if (obs++) cout << '\n';
    for (const pair<int, string>& p : v) {
      cout << p.second << '\n';
    }
  }

  return 0;
}
