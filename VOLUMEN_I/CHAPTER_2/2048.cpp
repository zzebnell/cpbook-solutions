/*
  user: zebnel
  team: ...
  created: 2025-02-10 17:43:50
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void proc_left(auto& v, int i) {
  int limit = 0;
  for (int j = 0; j < 4; j++) {
    if (v[i][j]) {
      int ji = j - 1;
      while (ji >= limit) {
        if (v[i][ji] == 0) {
          v[i][ji] = v[i][ji + 1];
          v[i][ji + 1] = 0;
        } else {
          if (v[i][ji] == v[i][ji + 1]) {
            v[i][ji] = v[i][ji] * 2;
            v[i][ji + 1] = 0;
            limit = ji + 1;
          }
        }
        ji--;
      }
    }
  }
}

void proc_right(auto& v, int i) {
  int limit = 3;
  for (int j = 3; j >= 0; j--) {
    if (v[i][j]) {
      int ji = j + 1;
      while (ji <= limit) {
        if (v[i][ji] == 0) {
          v[i][ji] = v[i][ji - 1];
          v[i][ji - 1] = 0;
        } else {
          if (v[i][ji] == v[i][ji - 1]) {
            v[i][ji] = v[i][ji] * 2;
            v[i][ji - 1] = 0;
            limit = ji - 1;
          }
        }
        ji++;
      }
    }
  }
}

void proc_up(auto& v, int j) {
  int limit = 0;
  for (int i = 0; i < 4; i++) {
    if (v[i][j]) {
      int ii = i - 1;
      while (ii >= limit) {
        if (v[ii][j] == 0) {
          v[ii][j] = v[ii + 1][j];
          v[ii + 1][j] = 0;
        } else {
          if (v[ii][j] == v[ii + 1][j]) {
            v[ii][j] = v[ii + 1][j] * 2;
            v[ii + 1][j] = 0;
            limit = ii + 1;
          }
        }
        ii--;
      }
    }
  }
}

void proc_down(auto& v, int j) {
  int limit = 3;
  for (int i = 3; i >= 0; i--) {
    if (v[i][j]) {
      int ii = i + 1;
      while (ii <= limit) {
        if (v[ii][j] == 0) {
          v[ii][j] = v[ii - 1][j];
          v[ii - 1][j] = 0;
        } else {
          if (v[ii][j] == v[ii - 1][j]) {
            v[ii][j] = v[ii - 1][j] * 2;
            v[ii - 1][j] = 0;
            limit = ii - 1;
          }
        }
        ii++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> v(4, vector<int>(4));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> v[i][j];
    }
  }
  int dir;
  cin >> dir;
  if (dir == 0 || dir == 2) {
    for (int i = 0; i < 4; i++) {
      if (dir == 0) proc_left(v, i);
      else proc_right(v, i);
    }
  } else {
    for (int j = 0; j < 4; j++) {
      if (dir == 1) proc_up(v, j);
      else proc_down(v, j);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << v[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
