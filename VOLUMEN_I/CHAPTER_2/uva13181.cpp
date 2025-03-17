/*
  user: zebnel
  team: ...
  created: 2025-01-30 17:56:12
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int ans = -INF;
    int counter = 0;
    int i = 0;
    int n = s.size();
    while (s[i] != 'X') {
      counter++;
      i++;
    }
    ans = max(ans, counter - 1);
    for (; i < n; i++) {
      if (s[i] == 'X') {
        ans = max(ans, counter / 2 - !(counter & 1));
        counter = 0;
      } else counter++;
    }
    ans = max(ans, counter - 1);
    cout << ans << '\n';
  }

  return 0;
}
