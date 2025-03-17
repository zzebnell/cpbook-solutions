/*
  user: zebnel
  created: 2025-03-17 13:26:13
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void counting_sort(vector<ll>& v, ll fac) {
  ll L, R;
  L = INF;
  R = -INF;
  int n = v.size();
  for (int i = 0; i < n; i++) {
    L = min(L, (v[i] / fac % 10));
    R = max(R, (v[i] / fac % 10));
  }
  int k = R - L + 1;
  vector<int> f(k);
  for (int i = 0; i < n; i++) {
    ++f[(v[i] / fac % 10) - L];
  }
  for (int i = 1; i < k; i++) {
    f[i] = f[i - 1] + f[i];
  }
  vector<ll> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    int pos = (v[i] / fac % 10) - L;
    ans[f[pos] - 1] = v[i];
    f[pos]--;
  }
  v = ans;
}


void radix_sort(vector<ll>& v) {
  ll d = *max_element(v.begin(), v.end());
  ll fac = 1LL;
  while (d) {
    counting_sort(v, fac);
    d /= 10;
    fac *= 10;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  ll n, a, b, c, x, y;
  while (tc--) {
    cin >> n;
    cin >> a >> b >> c;
    cin >> x >> y;
    vector<ll> s(n);
    s[0] = a;
    for (int i = 1; i < n; i++) {
      s[i] = (s[i - 1] * b + a) % c;
    }
    radix_sort(s);
    ll v = 0;
    for (int i = 0; i < n; i++) {
      v = (v * x + s[i]) % y;
    }
    cout << v << '\n';
  }
  /*vector<ll> v = {2, 3, 1, 0, 4, 8, 5, 4};
  radix_sort(v);
  for (ll& a : v) {
    cout << a << ' ';
  }
  cout << '\n';*/

  return 0;
}
