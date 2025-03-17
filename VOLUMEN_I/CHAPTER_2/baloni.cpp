/*
  user: zebnel
  team: ...
  created: 2025-01-30 20:39:31
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
  cin >> n;
  int max_h = 1e6 + 1;
  vector<int> A(max_h);
  int ans = 0;
  int h;
  for (int i = 0; i < n; i++) {
    cin >> h;
    if (A[h]) {
      A[h]--;
      A[h - 1]++;
    } else {
      ans++;
      A[h - 1]++;
    }
  }
  cout << ans << '\n';

  return 0;
}
