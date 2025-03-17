/*
  user: zebnel
  team: ...
  created: 2025-01-31 19:53:38
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
  int tt = 0;
  while (t--) {
    int s;
    vector<set<int>> v(3);
    for (int i = 0; i < 3; i++) {
      cin >> s;
      int p;
      for (int j = 0; j < s; j++) {
        cin >> p;
        v[i].insert(p);
      }
    }
    vector<pair<int, int>> others = {{1, 2}, {0, 2}, {0, 1}};
    vector<pair<int, set<int>>> ans(3);
    for (int i = 0; i < 3; i++) {
      ans[i].first = i + 1;
      for (int pr : v[i]) {
        if (!v[others[i].first].count(pr) && !v[others[i].second].count(pr)) {
          ans[i].second.insert(pr);
        }
      }
    }
    sort(ans.begin(), ans.end(), [&](pair<int, set<int>> p1, pair<int, set<int>> p2) {
      if (p1.second.size() == p2.second.size()) {
        return p1.first < p2.first;
      }
      return p1.second.size() > p2.second.size();
    });
    cout << "Case #" << ++tt << ':' << '\n';
    for (int i = 0; i < 3; i++) {
      if (ans[i].second.size() == ans[0].second.size()) {
        cout << ans[i].first << ' ' << ans[i].second.size();
        for (int a : ans[i].second) {
          cout << ' ' << a;
        }
        cout << '\n';
      }
    }
  }

  return 0;
}
