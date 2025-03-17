/*
  user: zebnel
  team: ...
  created: 2025-03-04 12:23:41
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<string, string>> v(n, {"", ""});
    string name, s, trash;
    for (int i = 0; i < n; i++) {
      cin >> v[i].second >> s >> trash;
      v[i].second.pop_back();
      // process s
      stringstream ss(s);
      string token;
      while (getline(ss, token, '-')) {
        v[i].first.push_back((token == "upper" ? 'a' : (token == "middle" ? 'b' : 'c')));
      }
      reverse(v[i].first.begin(), v[i].first.end());
      while (int(v[i].first.size()) < 10) v[i].first.push_back('b');
    }
    sort(v.begin(), v.end(), [](auto& s1, auto& s2) {
      if (s1.first == s2.first) return s1.second < s2.second;
      return s1.first < s2.first;
    });
    for (auto& p : v) {
      cout << p.second << '\n';
    }
    for (int i = 0; i < 30; i++) cout << '=';
    cout << '\n';
  }

  return 0;
}
