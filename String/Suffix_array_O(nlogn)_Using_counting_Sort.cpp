// "mississippi"

/*

10 i
7 ippi
4 issippi
1 ississippi
0 mississippi
9 pi
8 ppi
6 sippi
3 sissippi
5 ssippi
2 ssissippi

*/

/*

Suffix Array will stored in ar[i].indx array

*/


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MEM(x,val) memset(x,val,sizeof(x))


const int Mx = 2000005,K = 22;
int Rank[K][Mx],step;

struct info
{
  int tup[2],indx;
  bool operator<(const info &a)const{
    return (tup[0] != a.tup[0] ? tup[0] < a.tup[0] : tup[1] < a.tup[1]);
  }
}ar[Mx];

info temp[Mx];
int cnt[Mx];

void Counting_Sort(int N){
  MEM(cnt,0);
  int mi = -2;  // Supppose minimum value of tuple[0],tuple[1]
  
  // Sorting tuple[1]
  for(int i = 0; i<N; i++){
    cnt[ar[i].tup[1] - mi]++;
  }
  for(int i = 1; i<Mx; i++) cnt[i] += cnt[i-1];
  for(int i = N-1; i>=0; i--){
    temp[--cnt[ar[i].tup[1] - mi]] = ar[i];
  }
  for(int i = 0; i<N; i++) ar[i] = temp[i];


  //Sorting tuple[0]
  MEM(cnt,0);
  for(int i = 0; i<N; i++){
    cnt[ar[i].tup[0] - mi]++;
  }
  for(int i = 1; i<Mx; i++) cnt[i] += cnt[i-1];
  for(int i = N-1; i>=0; i--){
    temp[--cnt[ar[i].tup[0] - mi]] = ar[i];
  }
  for(int i = 0; i<N; i++) ar[i] = temp[i];
}

void Build_Suffix_Array(string s){
  int N = s.size();
  for(int i = 0; i<N; i++){
    Rank[0][i] = s[i];
  }
  int jump;
  for(step = 1,jump = 1; jump <= N; step++,jump <<= 1){
    for(int i = 0; i<N; i++){
      ar[i].indx = i;
      ar[i].tup[0] = Rank[step-1][i];
      ar[i].tup[1] = (i + jump < N ? Rank[step-1][i + jump] : -1);
    }
    //sort(ar,ar + N);
    Counting_Sort(N);

    Rank[step][ar[0].indx] = 0;
    for(int i = 1; i<N; i++){
      Rank[step][ar[i].indx] = (ar[i-1].tup[0] == ar[i].tup[0] && ar[i-1].tup[1] == ar[i].tup[1]) ? Rank[step][ar[i-1].indx] : i;
    }
  }
}

vector<int> Build_LCP_Array(int N){

  //ans[i] = LCP of ar[i].indx and ar[i-1].indx

  vector<int>ans(N);
  for(int i = 1; i<N; i++){
    int x = ar[i].indx,y = ar[i-1].indx;
    ans[i] = 0;
    for(int j = step - 1; j>=0; j--){
      if(Rank[j][x] == Rank[j][y]){
        ans[i] += (1<<j);
        x += (1<<j);
        y += (1<<j);
      }
    }
  }
  return ans;
}

int st[K][Mx];  // sparse table

void build(vector<int>lcp){
  int N = lcp.size();

  for(int i = 0; i<N; i++){
    st[0][i] = lcp[i];
  }

  for(int k = 1; k<K; k++){
    for(int i = 0; i<N; i++){
      int next = i + (1<<k-1);
      if(next >= N) continue;
      st[k][i] = min(st[k-1][i],st[k-1][next]);
    }
  }
}

int get(int l,int r){
  l++;
  int lg = log2(r - l + 1);
  return min(st[lg][l],st[lg][r - (1<<lg) + 1]);
}

//First position l such that lcp(l...r) >= lcp[r]
int find_first(int l,int r,int val){
  int re = r,lo = l,hi = r;

  while(lo < hi){
    int mid = (lo + hi)/2;
    if(get(mid,r) >= val){
      re = mid;
      hi = mid;
    }else lo = mid + 1;
  }
  return re;
}


//Last position r such that lcp(l...r) >= lcp[l] or lcp(l...r) >= val
int find_last(int l,int r,int val){
  int re = l,lo = l,hi = r;

  while(lo < hi){
    int mid = (lo + hi + 1)/2;
    if(get(l,mid) >= val){
      re = mid;
      lo = mid;
    }else hi = mid - 1;
  }
  return re;
}


void solve(){
  string s = "mississippi";
  Build_Suffix_Array(s);

  vector<int>lcp = Build_LCP_Array((int)s.size());

  build(lcp);
}

 
int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}
