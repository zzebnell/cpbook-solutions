/*
  user: zebnel
  team: ...
  created: 2025-03-01 16:20:11
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v(5);
  cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
  while (!(v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4])) {
    for (int i = 0; i < 4; i++) {
      if (v[i] > v[i + 1]) {
        swap(v[i], v[i + 1]);
        for (int& a : v) {
          cout << a << ' ';
        }
        cout << '\n';
      }
      
    }
    
  }

  return 0;
}
