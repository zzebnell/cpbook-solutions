/*
  user: zebnel
  team: ...
  created: 2025-03-04 00:17:57
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

struct Data {
  int number, solved, penalty;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  string s;
  cin.ignore();
  cin.ignore();
  int contestant, problem, time;
  char state;
  for (int tt = 0; tt < t; tt++) {
    vector<Data> temp(101);
    for (int i = 0; i < 101; i++) {
      temp[i].number = i;
    }
    set<int> st;
    vector<vector<int>> penalty(101, vector<int>(10));
    vector<vector<bool>> solved(101, vector<bool>(10));
    while (getline(cin, s)) {
      if (s.empty()) break;
      stringstream ss(s);
      ss >> contestant >> problem >> time >> state;
      st.insert(contestant);
      if (state == 'I') {
        penalty[contestant][problem] += 20;
      } else if (state == 'C' && !solved[contestant][problem]) {
        solved[contestant][problem] = true;
        temp[contestant].solved++;
        temp[contestant].penalty += (time + penalty[contestant][problem]);
      }
    }
    vector<Data> ans;
    for (auto a : st) {
      ans.push_back(temp[a]);
    }
    sort(ans.begin(), ans.end(), [](Data& d1, Data& d2) {
      if (d1.solved == d2.solved) {
        if (d1.penalty == d2.penalty) {
          return d1.number < d2.number;
        } else return d1.penalty < d2.penalty;
      } else {
        return d1.solved > d2.solved;
      }
    });
    for (Data& d : ans) {
      cout << d.number << ' ' << d.solved << ' ' << d.penalty << '\n';
    }
    if (tt < t - 1) cout << '\n';
  }

  return 0;
}
