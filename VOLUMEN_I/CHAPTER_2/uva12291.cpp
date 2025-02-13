/*
  user: zebnel
  team: ...
  created: 2025-02-13 16:25:46
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
    vector<string> lpol(n), spol(m);
    for (int i = 0; i < n; i++) {
      cin >> lpol[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> spol[i];
    }
    int mn_i = INF, mn_j = INF;
    int mx_i = -INF, mx_j = -INF;
    int scnt = 0, lcnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (lpol[i][j] == '*') lcnt++;
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (spol[i][j] == '*') {
          scnt++;
          mn_i = min(mn_i, i);
          mn_j = min(mn_j, j);
          mx_i = max(mx_i, i);
          mx_j = max(mx_j, j);
        }
      }
    }
    //cout << mn_i << ' ' << mn_j << ' ' << mx_i << ' ' << mx_j << '\n';
    int sn = mx_i - mn_i + 1;
    int sm = mx_j - mn_j + 1;
    int fully = 0;
    int ans = 0;
    for (int i = 0; i + sn <= n && !ans; i++) {
      for (int j = 0; j + sm <= n && !ans; j++) {
        int matches = 0;
        vector<string> c_lpol(lpol);
        for (int ii = mn_i, ci = i; ii <= mx_i; ii++, ci++) {
          for (int ji = mn_j, cj = j; ji <= mx_j; ji++, cj++) {
            if (spol[ii][ji] == '*' && c_lpol[ci][cj] == '*') {
              matches++;
              c_lpol[ci][cj] = '$';
            }
          }
        }
        if (matches == scnt) {
          fully++;
          lpol = c_lpol;
        }
        if (fully == 2) {
          int tot = 0;
          for (string& s : lpol) {
            for (char& c : s) {
              if (c == '$') {
                tot++;
              }
            }
          }
          ans = (tot == lcnt);
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
