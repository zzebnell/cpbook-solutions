/*
  user: zebnel
  team: ...
  created: 2025-01-28 19:00:07
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
    vector<int> v(n - 1);
    iota(v.begin(), v.end(), 1);
    set<int> s(v.begin(), v.end());
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (int i = 1; i < n; i++) {
      s.erase(abs(A[i] - A[i - 1]));
    }
    cout << (s.empty() ? "Jolly" : "Not jolly") << '\n';
  }

  return 0;
}
