/*
  user: zebnel
  created: 2025-03-23 01:21:45
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  int tn = 1;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    bool ans = true;
    for (int i = 0; i < n && ans; i++) {
      ans = ans && (k & (1 << i));
    }
    cout << "Case #" << tn++ << ": " << (ans ? "ON" : "OFF") << '\n';
  }

  return 0;
}
