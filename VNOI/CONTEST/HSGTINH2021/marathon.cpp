#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5;
struct Edge{
	int v,w;
};
int n,m;
int res = INT_MAX;
vector<Edge> adj[N];
int visited[N];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
}
void dfs(int u , int sum , int cnt){
	visited[u] = 1;
    if (sum > m) return;
    if(sum==m){
        res = min(res,cnt);
        return;
    }
	for(auto x : adj[u]){
		int v = x.v;
		int w = x.w;
		if(!visited[v]){
			dfs(v,sum + w,cnt + 1);
		}
	}
}
void solve(){
	nhap();
	for(int i=1;i<=n;i++){
		memset(visited , 0 , sizeof(visited));
		dfs(i,0,0);
	}
	if(res!=INT_MAX)cout<<res;
	else cout << -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
// 	//freopen("test.txt" , "r" , stdin);
  freopen("marathon.inp" , "r" , stdin);
  freopen("marathon.out" , "w" , stdout);
	solve();
	return 0;
}

