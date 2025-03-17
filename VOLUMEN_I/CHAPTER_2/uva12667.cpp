/*
  user: zebnel
  team: ...
  created: 2025-02-08 16:52:02
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, m;
  cin >> n >> t >> m;
  vector<pair<int, int>> v(n + 1);
  vector<bool> solved(n + 1);
  vector<vector<bool>> info(t + 1, vector<bool>(n + 1));
  int time, team;
  char pr;
  string vdct;
  while (m--) {
    cin >> time >> team >> pr >> vdct;
    if (vdct == "Yes" && (!info[team][pr - 'A'])) {
      info[team][pr - 'A'] = 1;
      solved[pr - 'A'] = 1;
      v[pr - 'A'].first = time;
      v[pr - 'A'].second = team;
    }
  }
  for (int i = 0; i < n; i++) {
    if (solved[i]) {
      cout << (char) (i + 'A') << ' ' << v[i].first << ' ' << v[i].second << '\n';
    } else {
      cout << (char) (i + 'A') << " - -\n";
    }
  }

  return 0;
}
