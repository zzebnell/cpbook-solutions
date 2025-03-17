/*
  user: zebnel
  team: ...
  created: 2025-02-03 00:33:57
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string n, m;
  cin >> n >> m;

  if (m == "1") {
    cout << n << '\n';
  } else {
    int n_size = n.size();
    int m_size = m.size();
    if (m_size > n_size) {
      string ans = "";
      ans.append("0.");
      for (int i = 0; i < (m_size - n_size) - 1; i++) {
        ans.push_back('0');
      }
      ans.append(n);
      while (ans.back() == '0') ans.pop_back();
      cout << ans << '\n';
    } else {
      string ans = "";
      int i;
      for (i = 0; i < (n_size - (m_size - 1)); i++) ans.push_back(n[i]);
      ans.push_back('.');
      for (; i < n_size; i++) ans.push_back(n[i]);
      while (ans.back() == '0') ans.pop_back();
      if (ans.back() == '.') ans.pop_back();
      cout << ans << '\n';
    }
  }

  return 0;
}
