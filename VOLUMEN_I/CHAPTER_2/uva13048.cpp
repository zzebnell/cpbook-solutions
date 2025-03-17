/*
  user: zebnel
  team: ...
  created: 2025-02-03 00:06:00
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  int tt = 1;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int p, q;
      if (s[i] == 'B') {
        p = max(0, i - 2);
        q = max(0, i - 1);
        s[p] = (s[p] == '-' ? '*' : s[p]);
        s[q] = (s[q] == '-' ? '*' : s[q]);
      } else if (s[i] == 'S') {
        p = max(0, i - 1); 
        q = min(n - 1, i + 1);
        s[p] = (s[p] == '-' ? '*' : s[p]);
        s[q] = (s[q] == '-' ? '*' : s[q]);
      }
    }
    int ans = 0;
    for (char& c : s) {
      ans += c == '-';
    }
    cout << "Case " << tt++ << ": " << ans << '\n';
  }

  return 0;
}
