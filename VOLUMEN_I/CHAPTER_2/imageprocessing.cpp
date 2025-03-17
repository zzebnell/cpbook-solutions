/*
  user: zebnel
  team: ...
  created: 2025-02-10 16:32:35
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<vector<int>> image(h, vector<int>(w)), kernel(n, vector<int>(m)), ans(h - n + 1, vector<int>(w - m + 1));
  for (vector<int>& v : image) {
    for (int& a : v) {
      cin >> a;
    }
  }
  for (vector<int>& v : kernel) {
    for (int& a : v) {
      cin >> a;
    }
  }
  for (int i = 0; (i + n) <= h; i++) {
    for (int j = 0; (j + m) <= w; j++) {
      for (int x = i, it = n - 1; x < (i + n); x++, it--) {
        for (int y = j, jt = m - 1; y < (j + m); y++, jt--) {
          ans[i][j] += (image[x][y] * kernel[it][jt]);
        }
      }
    }
  }
  for (vector<int>& v : ans) {
    for (int& a : v) {
      cout << a << ' ';
    }
    cout << '\n';
  }

  return 0;
}
