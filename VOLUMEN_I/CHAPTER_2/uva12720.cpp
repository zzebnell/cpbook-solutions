/*
  user: zebnel
  created: 2025-03-23 21:15:40
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  int tn = 1;
  cin >> tc;
  while (tc--) {
    string a;
    cin >> a;
    int p, r;
    int n = a.size();
    p = n / 2 - !(n & 1);
    r = p + 1;
    string s = "";
    int cn = n;
    bool choosen = 0;
    while (n) {
      if (n & 1) {
        if (!choosen) {
          s.push_back(a[p]);
          p--;
        } else {
          s.push_back(a[r]);
          r++;
        }
      } else {
        if (a[p] > a[r]) {
          s.push_back(a[p]);
          p--;
          choosen = 1;
        } else {
          s.push_back(a[r]);
          choosen = 0;
          r++;
        }
      }
      n--;
    }
    n = cn;
    ll ans = 0;
    int s_size = s.size();
    ll power = 1LL;
    for (int i = s_size - 1; i >= 0; i--) {
      if (s[i] == '1') {
        ans = (ans + power) % MOD;
      }
      power = (2 * power) % MOD;
    }
    cout << "Case #" << tn++ << ": " << ans << '\n';
  }

  return 0;
}
