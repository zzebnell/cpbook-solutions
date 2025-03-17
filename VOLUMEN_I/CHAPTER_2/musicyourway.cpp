/*
  user: zebnel
  team: ...
  created: 2025-03-05 19:40:30
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
  getline(cin, s);

  int att = 0;
  stringstream ss(s);
  string token;
  map<string, int> mp;
  vector<string> o;
  while (getline(ss, token, ' ')) {
    mp[token] = att++;
    o.push_back(token);
  }
  int n;
  cin >> n;
  vector<vector<string>> v(n, vector<string>(att));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < att; j++) {
      cin >> v[i][j];
    }
  }
  int m;
  cin >> m;
  int index;
  for (int i = 0; i < m; i++) {
    cin >> s;
    index = mp[s];
    stable_sort(v.begin(), v.end(), [&](auto& s1, auto& s2) {
      return s1[index] < s2[index];
    }); 
    cout << (i ? "\n" : "");
    for (string& st : o) {
      cout << st << ' ';
    }
    cout << '\n';
    for (auto& st : v) {
      for (string& st : st) {
        cout << st << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}
