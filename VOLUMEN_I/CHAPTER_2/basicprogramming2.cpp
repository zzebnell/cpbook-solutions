/*
  user: zebnel
  team: ...
  created: 2025-02-24 17:19:40
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (t == 1) {
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
      int l = i - 1;
      int r = n;
      int k = 7777 - v[i];
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (k < v[m]) {
          r = m;
        } else {
          l = m;
        }
      }
      if (v[l] == k) {
        ok = false;
      }
    }
    cout << (ok ? "No" : "Yes") << '\n';
  } else if (t == 2) {
    bool ok = true;
    for (int i = 1; i < n && ok; i++) {
      ok = v[i] != v[i - 1];
    }
    cout << (ok ? "Unique" : "Contains duplicate") << '\n';
  } else if (t == 3) {
    int times = 1;
    int target = n / 2;
    int number = -1;
    for (int i = 1; i < n; i++) {
      if (v[i] == v[i - 1]) {
        times++;
      } else {
        if (times > target) {
          number = v[i - 1];
        }
        times = 1;
      }
    }
    if (times > target) {
      number = v.back();
    }
    cout << number << '\n';
  } else if (t == 4) {
    if (n & 1) {
      cout << v[n / 2] << '\n';
    } else {
      cout << v[n / 2 - 1] << ' ' << v[n / 2] << '\n';
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (v[i] >= 100 && v[i] <= 999) {
        cout << v[i] << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}
