/*
  user: zebnel
  team: ...
  created: 2025-02-13 17:51:36
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string question;
  getline(cin, question);
  int n;
  cin >> n;
  cin.ignore();
  vector<int> v(n, -INF);
  string s;
  vector<vector<string>> opt(n);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    s.push_back(',');
    string partial = "";
    int s_size = s.size();
    for (int j = 0; j < s_size; j++) {
      if (s[j] == ',') {
        opt[i].push_back(partial);
        partial = "";
        j++;
      } else {
        partial.push_back(s[j]);
      }
    }
  }
  assert(opt[0].size() == opt[n - 1].size());
  int m = opt[0].size();
  for (int i = 0; i < n; i++) {
    for (int k = i + 1; k < n; k++) {
      int diffs = 0;
      for (int j = 0; j < m; j++) {
        if (opt[i][j] != opt[k][j]) {
          diffs++;
        }
      }
      v[i] = max(v[i], diffs);
      v[k] = max(v[k], diffs);
    }
  }
  int mn_diff = *min_element(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i] == mn_diff) {
      for (int j = 0; j < m; j++) {
        cout << (j ? ", " : "") << opt[i][j];
      }
      cout << '\n';
    }
  }
  
  return 0;
}
