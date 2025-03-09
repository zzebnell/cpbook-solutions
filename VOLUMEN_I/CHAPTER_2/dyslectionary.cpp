/*
  user: zebnel
  team: ...
  created: 2025-03-05 19:16:21
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  vector<string> v;
  while (getline(cin, s)) {
    if (s.empty()) {
      int mx_l = 0;
      sort(v.begin(), v.end());
      for (string& ss : v) {
        reverse(ss.begin(), ss.end());
        mx_l = max(mx_l, int(ss.size()));
      }
      for (string& ss : v) {
        int spaces = mx_l - int(ss.size());
        for (int i = 0; i < spaces; i++) {
          cout << ' ';
        }
        cout << ss << '\n';
      }
      v.clear();
      cout << '\n';
      continue;
    }
    reverse(s.begin(), s.end());
    v.push_back(s);
  }
  int mx_l = 0;
  sort(v.begin(), v.end());
  for (string& ss : v) {
    reverse(ss.begin(), ss.end());
    mx_l = max(mx_l, int(ss.size()));
  }
  for (string& ss : v) {
    int spaces = mx_l - int(ss.size());
    for (int i = 0; i < spaces; i++) {
      cout << ' ';
    }
    cout << ss << '\n';
  }

  return 0;
}
