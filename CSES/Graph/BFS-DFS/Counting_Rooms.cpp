#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
#define mp make_pair
#define pqueue priority_queue
#define pb push_back

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a=a*a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
// const ll mod = 998244353;
void dfs(int i, int j, vector<vector<char>>& v){
    if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]=='#') return;
    v[i][j]='#';
    dfs(i+1,j,v);
    dfs(i-1,j,v);
    dfs(i,j+1,v);
    dfs(i,j-1,v);
}
void dfs2(int i, int j, vector<vector<char>>&V){
    for(auto [x,y]:dir){
        int a=i+x,b=j+y;
        if(a>=0 && b>=0 && a<V.size() && b<V[0].size() && V[a][b]=='.'){
            V[a][b]='#';
            dfs2(a,b,V);
        }
    }
}
void solve(){}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    int cnt=0;
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(v[i][j]=='.'){
                cnt++;
                dfs(i,j,v);
            }
        }
    }
    cout<<cnt<<ln;
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}