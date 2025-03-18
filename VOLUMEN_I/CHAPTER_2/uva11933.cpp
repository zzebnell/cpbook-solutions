/*
  user: zebnel
  created: 2025-03-17 23:42:20
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  while (cin >> n && n) {
    vector<ll> v;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        v.push_back(i);
      }
    }
    ll a, b;
    a = b = 0;
    int v_size = v.size();
    for (int i = 0; i < v_size; i++) {
      if (i & 1) {
        b = b | (1 << v[i]);
      } else {
        a = a | (1 << v[i]);
      }
    }
    cout << a << ' ' << b << '\n';
  }

  return 0;
}
