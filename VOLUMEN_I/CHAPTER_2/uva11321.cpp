/*
  user: zebnel
  team: ...
  created: 2025-03-04 11:26:47
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
  while (cin >> n >> m && (n && m)) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end(), [&](int& a, int& b) {
      int moda = a % m;
      int modb = b % m;
      if (moda == modb) {
        if (((b & 1) && !(a & 1)) || (!(b & 1) && (a & 1))) {
          if (a & 1) return true;
          return false;
        }
        if ((b & 1) && (a & 1)) {
          return a > b;
        }
        return a < b;
      }
      return moda < modb;
    });
    cout << n << ' ' << m << '\n';
    for (int& a : v) {
      cout << a << '\n';
    }
  }
  cout << 0 << ' ' << 0 << '\n';

  return 0;
}
