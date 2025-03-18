/*
  user: zebnel
  created: 2025-03-17 22:56:16
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void _clear(string& mask, int i) {
  mask[i] = '0';
}

void _set(string& mask, int i) {
  mask[i] = '1';
}

void _or(string& mask, int i, int j) {
  if (mask[i] == '1' || mask[j] == '1') {
    mask[i] = '1';
  } else if (mask[i] == '?' || mask[j] == '?') {
    mask[i] = '?';
  } else {
    mask[i] = (((mask[i] - '0') | (mask[j] - '0')) + '0');
  }
}

void _and(string& mask, int i, int j) {
  if (mask[i] == '0' || mask[j] == '0') {
    mask[i] = '0';
  } else if (mask[i] == '?' || mask[j] == '?') {
    mask[i] = '?';
  } else {
    mask[i] = (((mask[i] - '0') & (mask[j] - '0')) + '0');
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string op;
  while (cin >> n && n) {
    string mask(32, '?');
    while (n--) {
      cin >> op;
      if (op == "CLEAR") {
        int i;
        cin >> i;
        _clear(mask, i);
      } else if (op == "SET") {
        int i;
        cin >> i;
        _set(mask, i);
      } else if (op == "OR") {
        int i, j;
        cin >> i >> j;
        _or(mask, i, j);
      } else {
        int i, j;
        cin >> i >> j;
        _and(mask, i, j);
      }
    }
    for (int i = 31; i >= 0; i--) {
      cout << mask[i];
    }
    cout << '\n';
  }

  return 0;
}
