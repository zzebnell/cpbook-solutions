/*
  user: zebnel
  team: ...
  created: 2025-02-08 16:19:58
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void print_m(vector<vector<int>>& v) {
  int n = v.size();
  int m = v[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (j ? " ": "") << v[i][j];
    }
    cout << '\n';
  }
}

vector<vector<int>> trans(vector<vector<int>>& v, int N) {
  int n = v.size();
  int m = v[0].size();
  vector<vector<int>> ans = v;
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
  int x, y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int target = (v[i][j] + 1) % N;
      for (int k = 0; k < 4; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if ((x >= 0 && x < n) && (y >= 0 && y < m)) {
          if (v[x][y] == target) {
            ans[x][y] = target - 1;
            if (ans[x][y] < 0) ans[x][y] = N - 1;
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, c, k;
  while (cin >> n >> r >> c >> k && (n && r && c && k)) {
    vector<vector<int>> v(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> v[i][j];
      }
    }
    for (int i = 0; i < k; i++) {
      v = trans(v, n);
    }
    print_m(v);
  }

  return 0;
}
