/*
  user: zebnel
  team: ...
  created: 2025-02-11 16:49:43
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

vector<string> rotate90(vector<string>& patt) {
  int n = patt.size();
  vector<string> ans(n, string(n, '?'));
  for (int i = 0, ji = n - 1; i < n; i++, ji--) {
    for (int j = 0; j < n; j++) {
      ans[j][ji] = patt[i][j];
    }
  }
  return ans;
}

vector<string> reflect(vector<string>& patt) {
  int n = patt.size();
  vector<string> ans = patt;
  int times = (n >> 1);
  for (int i = 0; i < times; i++) {
    ans[i].swap(ans[n - 1 - i]);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int np = 1;
  while (cin >> n) {
    vector<string> patt(n), trans(n);
    for (int i = 0; i < n; i++) {
      cin >> patt[i] >> trans[i];
    }
    cout << "Pattern " << np++ << ' ';
    // preservation
    if (patt == trans) {
      cout << "was preserved." << '\n';
      continue;
    }
    // only rotations
    bool nmal = true;
    for (int i = 1; i <= 3; i++) {
      patt = rotate90(patt);
      if (patt == trans) {
        cout << "was rotated " << (i * 90) << " degrees." << '\n';
        nmal = false;
        break;
      }
    }
    if (!nmal) continue;
    patt = rotate90(patt);
    // reflection and rotations
    nmal = true;
    patt = reflect(patt);
    if (patt == trans) {
      cout << "was reflected vertically." << '\n';
      continue;
    }
    for (int i = 1; i <= 3; i++) {
      patt = rotate90(patt);
      if (patt == trans) {
        cout << "was reflected vertically and rotated " << (i * 90) << " degrees." << '\n';
        nmal = false;
        break;
      }
    }
    if (!nmal) continue;
    cout << "was improperly transformed." << '\n';
  }

  return 0;
}
