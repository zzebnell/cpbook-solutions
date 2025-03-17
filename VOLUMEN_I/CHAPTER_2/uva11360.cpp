/*
  user: zebnel
  team: ...
  created: 2025-02-12 20:48:39
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void swap_row(int i, int j, vector<string>& v) {
  int n = v[0].size();
  for (int k = 0; k < n; k++) {
    swap(v[i][k], v[j][k]);
  }
}

void swap_col(int i, int j, vector<string>& v) {
  int n = v[0].size();
  for (int k = 0; k < n; k++) {
    swap(v[k][i], v[k][j]);
  }
}

void inc(vector<string>& v) {
  int val;
  for (string& s : v) {
    for (char& c : s) {
      val = ((c - '0' + 1) % 10);
      c = ((val > 9) ? '0' : val + '0');
    }
  }
}

void dec(vector<string>& v) {
  int val;
  for (string& s : v) {
    for (char& c : s) {
      val = (c - '0' - 1);
      c = ((val < 0) ? '9' : val + '0');
    }
  }
}

vector<string> trans(vector<string>& v) {
  int n = v[0].size();
  vector<string> ans(n, string(n, '?'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[j][i] = v[i][j];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  int tc = 1;
  while (t--) {
    cout << "Case #" << tc++ << '\n';
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int m;
    cin >> m;
    string op;
    while (m--) {
      cin >> op;
      if (op == "row" || op == "col") {
        int i, j;
        cin >> i >> j;
        i--, j--;
        if (op == "row") {
          swap_row(i, j, v);
        } else {
          swap_col(i, j, v);
        }
        continue;
      }
      if (op == "inc") inc(v);
      if (op == "dec") dec(v);
      if (op == "transpose") v = trans(v);
    }
    for (string& s : v) {
      cout << s << '\n';
    }
    cout << '\n';
  }

  return 0;
}
