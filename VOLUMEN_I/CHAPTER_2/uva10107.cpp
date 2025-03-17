/*
  user: zebnel
  team: ...
  created: 2025-03-01 15:13:35
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;
  vector<int> v;
  while (cin >> a) {
    v.push_back(a);
    int n = v.size();
    nth_element(v.begin(), (v.begin() + (n / 2)), v.end());
    if (!(n & 1)) {
      nth_element(v.begin(), (v.begin() + (n / 2) - 1), v.end());
      cout << ((v[n / 2] + v[n / 2 - 1]) / 2) << '\n';
    } else {
      cout << v[n / 2] << '\n';
    }
  }

  return 0;
}
