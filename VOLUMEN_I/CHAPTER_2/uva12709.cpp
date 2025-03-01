/*
  user: zebnel
  team: ...
  created: 2025-03-01 15:47:40
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

struct triple {
  int a, b, c;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<triple> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].a >> v[i].b >> v[i].c;
    }
    sort(v.begin(), v.end(), [&](triple t1, triple t2){
      if (t1.c == t2.c) {
        return ((t1.a * t1.b * t1.c) > (t2.a * t2.b * t2.c));
      }
      return t1.c > t2.c;
    });
    cout << v[0].a * v[0].b * v[0].c << '\n';
  }

  return 0;
}
