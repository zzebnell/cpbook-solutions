/*
  user: zebnel
  team: ...
  created: 2025-03-01 16:06:25
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

int insertion_sort(vector<int>& v) {
  int n = v.size();
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && key < v[j]) {
      v[j + 1] = v[j];
      j--;
      ans++;
    }
    v[j + 1] = key;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p;
  cin >> p;
  int k;
  for (int i = 0; i < p; i++) {
    cin >> k;
    vector<int> v(20);
    for (int j = 0; j < 20; j++) {
      cin >> v[j];
    }
    int ans = insertion_sort(v);
    cout << k << ' ' << ans << '\n';
  }

  return 0;
}
