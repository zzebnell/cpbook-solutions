/*
  user: zebnel
  team: ...
  created: 2025-02-01 14:42:30
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
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int qq;
  cin >> qq;
  int qu;
  while (qq--) {
    cin >> qu;
    qu--;
    if (s[qu] == "?") {
      int p = qu - 1, q = qu + 1;
      while (p >= 0) {
        if (s[p] != "?") break;
        p--;
      }
      while (q < n) {
        if (s[q] != "?") break;
        q++;
      }
      int dp = (p < 0 ? INF : abs(qu - p));
      int dq = (q >= n ? INF : abs(q - qu));
      if (dp == dq) {
        cout << "middle of " << s[p] << " and " << s[q] << '\n';
      } else {
        string dir = (dp < dq) ? "right" : "left";
        int choosen = (dp < dq) ? p : q;
        for (int i = 0; i < min(dp, dq); i++) {
          cout << dir << " of ";
        }
        cout << s[choosen] << '\n';
      }
    } else {
      cout << s[qu] << '\n';
    }
  }

  return 0;
}
