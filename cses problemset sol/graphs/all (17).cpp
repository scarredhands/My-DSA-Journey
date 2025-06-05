#include <bits/stdc++.h>
using namespace std;

void dfs(int r,int c,vector<vector<char>> &a,vector<int> &vis,int n,int m){
    vis[m*r+c]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    for(int i=0;i<4;++i){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow*m +ncol]==0 && a[nrow][ncol]=='.' ){
            dfs(nrow,ncol,a,vis,n,m);
        }
    }
    return;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    int ans=0;
    vector<int> vis(n*m,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(vis[i*m +j]==0 && a[i][j]=='.'){
                ans++;
                dfs(i,j,a,vis,n,m);
            }
        }
    }
    cout<<ans<<endl;

}
