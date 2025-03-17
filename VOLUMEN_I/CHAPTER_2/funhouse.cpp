/*
  user: zebnel
  team: ...
  created: 2025-02-23 18:37:26
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, l;
  vector<vector<int>> dir = {{1, 3},
                             {0, 2},
                             {3, 1},
                             {2, 0}};
  int tt = 1;
  while (cin >> w >> l && (w && l)) {
    vector<string> v(l);
    int x, y;
    x = y = -1;
    bool f = true;
    int state = -1;
    for (int i = 0; i < l; i++) {
      cin >> v[i];
      if (f)
        for (int j = 0; j < w; j++) {
          if (v[i][j] == '*') {
            x = i, y = j;
            f = false;
          }
        }
      if (x == 0) {
        state = 2;
      } else if (x == l - 1) {
        state = 0;
      } else if (y == 0) {
        state = 1;
      } else if (y == w - 1) {
        state = 3;
      }
    }
    vector<int> dx = {-1, 0, 1,  0};
    vector<int> dy = { 0, 1, 0, -1};
    while (true) {
      x += dx[state];
      y += dy[state];
      if (v[x][y] == 'x') {
        v[x][y] = '&';
        break;
      } else if (v[x][y] != '.') {
        state = dir[state][(v[x][y] == '/' ? 0 : 1)];
      }
    }
    cout << "HOUSE " << tt++ << '\n';
    for (string& s : v) {
      cout << s << '\n';
    }
  }

  return 0;
}
