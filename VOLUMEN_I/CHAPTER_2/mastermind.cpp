/*
  user: zebnel
  team: ...
  created: 2025-02-03 16:38:33
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string code, guess;
  cin >> n >> code >> guess;

  int r, s;
  r = s = 0;
  for (int i = 0; i < n; i++) {
    if (guess[i] == code[i]) {
      r++;
      code[i]  = '*';
      guess[i] = '*';
    }
  }

  for (int i = 0; i < n; i++) {
    if (guess[i] == '*') continue;
    char key = guess[i];
    for (int j = 0; j < n; j++) {
      if (code[j] == key) {
        code[j] = '*';
        guess[i] = '*';
        s++;
        break;
      }
    }
  }
  cout << r << ' ' << s << '\n';

  return 0;
}
