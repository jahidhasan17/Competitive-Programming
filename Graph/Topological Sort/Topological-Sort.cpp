/*
Input
5 4
2 3
3 4
1 3
4 5

Output

*/

#include <bits/stdc++.h>
using namespace std;


void TopSort(int u, vector<vector<int>>&g, vector<int>&startTime, vector<int>&endTime, int &currentTime) {
  currentTime++;
  startTime[u] = currentTime;

  for(int v : g[u]) {
    if(!startTime[v]) {
      TopSort(v, g, startTime, endTime, currentTime);
    }
  }

  currentTime++;
  endTime[u] = currentTime;
}


void solve() {
  int n, m; cin >> n >> m;
  vector<int>startTime(n + 1, 0), endTime(n + 1, 0);
  vector<vector<int>>g(n + 1);

  for(int i = 0; i<m; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
  }

  int currentTime = 0;

  for(int i = 1; i<=n; i++) {
    if(!startTime[i]) {
      TopSort(i, g, startTime, endTime, currentTime);
    }
  }

  vector<int>nums;
  for(int i = 1; i<=n; i++) nums.push_back(i);

  sort(nums.begin(), nums.end(), [&](int a, int b){
    return endTime[a] > endTime[b];
  });

  for(int x : nums) {
    cout << x << " ";
  }
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int tt; tt = 1;

  int cas = 1;
  while(tt--){
    //printf("Case %d: ",cas++);
    solve();
  }
}