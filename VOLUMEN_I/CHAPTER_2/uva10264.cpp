/*
  user: zebnel
  created: 2025-03-18 00:10:15
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
  while (cin >> n) {
    int k = (1 << n);
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
      cin >> v[i];
    }
    vector<int> sum(k);
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        sum[i] += v[i ^ (1 << j)];
      }
    }
    int ans = -INF;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, sum[i] + sum[i ^ (1 << j)]);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
