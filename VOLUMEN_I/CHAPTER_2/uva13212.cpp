/*
  user: zebnel
  team: ...
  created: 2025-03-09 22:19:01
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

ll merge(vector<int>& v, int p, int r) {
  ll ans = 0;
  int q = (p + r) / 2;
  int n1 = q - p;
  int n2 = r - q;
  vector<int> v1(n1), v2(n2);
  int k = p;
  for (int i = 0; i < n1; i++) v1[i] = v[k++];
  for (int i = 0; i < n2; i++) v2[i] = v[k++];
  k = p;
  int i, j;
  i = j = 0;
  while (i < n1 && j < n2) {
    if (v1[i] > v2[j]) {
      ans += n1 - i;
      v[k++] = v2[j];
      j++;
    } else {
      v[k++] = v1[i];
      i++;
    }
  }
  while (i < n1) v[k++] = v1[i++];
  while (j < n2) v[k++] = v2[j++];
  return ans;
}

ll merge_sort(vector<int>& v, int p, int r) {
  int n = r - p;
  if (n <= 1) {
    return 0;
  }
  ll ans = 0;
  int q = (p + r) / 2;
  ans += merge_sort(v, p, q);
  ans += merge_sort(v, q, r);
  ans += merge(v, p, r);
  return ans;
}

ll merge_sort(vector<int>& v) {
  return merge_sort(v, 0, int(v.size()));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    ll inv = merge_sort(v);
    cout << inv << '\n';
  }

  return 0;
}
