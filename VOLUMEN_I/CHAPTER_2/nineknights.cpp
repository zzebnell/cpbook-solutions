/*
  user: zebnel
  team: ...
  created: 2025-02-10 17:14:53
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> v(5);
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
  }
  vector<int> dx = {-2, -1, 1, 2,  2,  1, -1, -2};
  vector<int> dy = { 1,  2, 2, 1, -1, -2, -2, -1};
  bool ok = true;
  auto is_valid = [&](int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
  };
  int knights = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (v[i][j] == 'k') {
        knights++;
        int x, y;
        for (int k = 0; k < 8; k++) {
          x = i + dx[k];
          y = j + dy[k];
          if (is_valid(x, y) && v[x][y] == 'k') {
            ok = false;
          }
        }
      }
    }
  }
  cout << (ok && (knights == 9) ? "valid" : "invalid") << '\n';

  return 0;
}
