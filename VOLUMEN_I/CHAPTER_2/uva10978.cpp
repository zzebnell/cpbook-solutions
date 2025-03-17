/*
  user: zebnel
  team: ...
  created: 2025-01-31 18:51:57
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  //vector<string> names = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
  int n;
  while ((cin >> n) && n) {
    int j = -1;
    vector<string> ans(n, "?");
    string s1, s2;
    for (int i = 0; i < n; i++) {
      cin >> s1 >> s2;
      while (!s2.empty()) {
        j = (j + 1) % n;
        if (ans[j] != "?") continue;
        s2.pop_back();
      }
      ans[j] = s1;
    }
    for (int i = 0; i < int(ans.size()); i++) {
      cout << (i ? " " : "") << ans[i];
    }
    cout << '\n';
  }

  return 0;
}
