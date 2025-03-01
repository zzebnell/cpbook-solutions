/*
  user: zebnel
  team: ...
  created: 2025-03-01 16:35:49
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  while (cin >> r >> c && (r && c)) {
    vector<string> v(r, string(c, '?'));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> v[i][j];
      }
    }
    vector<string> ans(c, "");
    for (int j = 0; j < c; j++) {
      for (int i = 0; i < r; i++) {
        ans[j].push_back(v[i][j]);
      }
    }
    sort(ans.begin(), ans.end(), [&](string s1, string s2) {
      return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), [&](char c1, char c2) {
        return tolower(c1) < tolower(c2);
      });
    });
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << ans[j][i];
      }
      cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}
