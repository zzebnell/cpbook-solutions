/*
  user: zebnel
  team: ...
  created: 2025-03-03 00:17:08
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
  while (cin >> n && n) {
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    string ans = "";
    string p = v[n / 2 - 1];
    string q = v[n / 2];
    for (int i = 0; i < int(p.size()); i++) {
      ans.push_back(p[i] + 1);
      if (ans >= p && ans < q && ans.back() <= 'Z') break;
      else {
        ans[int(ans.size()) - 1]--;
      }
    }
    ans[int(ans.size()) - 1]--;
    if (!(ans >= p && ans < q)) ans[int(ans.size()) - 1]++;
    cout << ans << '\n';
  }

  return 0;
}
