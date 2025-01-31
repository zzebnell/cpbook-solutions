/*
  user: zebnel
  team: ...
  created: 2025-01-30 21:34:26
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int max_t = 2e5 + 2;
  vector<int> time(max_t);
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    time[t]++;
    time[t + 1000]--;
  }
  int ans = 0;
  int curr = 0;
  for (int i = 0; i < max_t; i++) {
    curr += time[i];
    ans = max(ans, (curr + k - 1) / k);
  }
  cout << ans << '\n';

  return 0;
}
