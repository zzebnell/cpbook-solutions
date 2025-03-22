/*
  user: zebnel
  created: 2025-03-21 23:44:48
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
  int a;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a;
      v[i] |= a;
    }
  }
  for (int& i : v) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}
