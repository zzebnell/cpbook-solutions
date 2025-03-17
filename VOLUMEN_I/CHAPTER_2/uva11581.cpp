/*
  user: zebnel
  team: ...
  created: 2025-02-04 16:36:14
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

vector<string> f(vector<string>& v) {
  vector<string> ans(3, string(3, '?'));
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
  auto is_valid = [&](int x, int y) {
    return ((x >= 0 && x < 3) && (y >= 0 && y < 3));
  };
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int total = 0;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (is_valid(x, y)) {
          total += v[x][y] - '0';
        }
      }
      ans[i][j] = (total & 1) + '0';
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin.ignore();
    vector<string> v(3);
    cin >> v[0] >> v[1] >> v[2];
    vector<string> prev;
    int i = 0;
    do {
      prev = v;
      v = f(v);
      i++;
    } while (prev != v);
    cout << i - 2 << '\n';
  }

  return 0;
}
