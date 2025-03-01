/*
  user: zebnel
  team: ...
  created: 2025-03-01 15:22:20
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
  string name;
  string old, young;
  int dd, mm, yy;
  cin >> name >> dd >> mm >> yy;
  old = young = name;
  pair<int, pair<int, int>> o, y;
  o = y = {yy, {mm, dd}};
  for (int i = 1; i < n; i++) {
    cin >> name >> dd >> mm >> yy;
    pair<int, pair<int, int>> p = {yy, {mm, dd}};
    if (p < o) {
      o = p;
      old = name;
    } else if (p > y) {
      y = p;
      young = name;
    }
  }
  cout << young << '\n' << old << '\n';

  return 0;
}
