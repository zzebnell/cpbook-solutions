/*
  user: zebnel
  team: ...
  created: 2025-02-23 19:48:29
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
  cin >> n >> m;
  vector<string> v(n, string('?', m));
  vector<vector<int>> eq(n + 2, vector<int>(m + 2));
  //int eq[n + 2][m + 2];
  //memset(eq, 0, sizeof eq);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      eq[i + 1][j + 1] = ((v[i][j] == '.') ? 0 : INF);
    }
  }
  
  vector<int> dx = {-1, 0, 1,  0};
  vector<int> dy = { 0, 1, 0, -1};
  set<int> st;
  st.insert(0);
  int x = 1;
  for (int v = 0; v < 1000; v++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (eq[i][j] == INF) {
          for (int k = 0; k < 4; k++) {
            if (st.count(eq[i + dx[k]][j + dy[k]])) {
              eq[i][j] = x;
            }
          }
        }
      }
    }
    st.insert(x);
    x++;
  }
  /*for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << eq[i][j];
    }
    cout << '\n';
  }*/
  int rings = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      rings = max(rings, eq[i][j]);
    }
  }
  int times = (rings < 10 ? 2 : 3);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!eq[i][j]) {
        for (int k = 0; k < times; k++) {
          cout << '.';
        }
      } else {
        int a = (eq[i][j] < 10 ? 1 : 2);
        for (int k = 0; k < times - a; k++) {
          cout << '.';
        }
        cout << eq[i][j];
      }
    }
    cout << '\n';
  }

  //cout << "FIN" << '\n';

  return 0;
}
