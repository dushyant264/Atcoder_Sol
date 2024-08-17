#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define revp(i,a,b) for(int i=a;i>=b;i--)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl

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
const int dirx[]={0,0,1,-1};
const int diry[]={1,-1,0,0};
const int dir[]={'R','L','D','U'};
// const ll mod = 998244353;
bool inlimit(int i, int j, int n, int m){
    return i>=0 && i<n && j>=0 && j<m;
}
int bfs(vvi &adj, vi &vis, vi &parent) {
    queue<pii>q;
    q.push({1,1});
    vis[1]=true;
    while(!q.empty()){
        int nd=q.front().ff,dis=q.front().ss;
        q.pop();

        if(nd==sz(adj)-1)return dis;
        rep(i,0,sz(adj[nd])){
            if(!vis[adj[nd][i]]){
                vis[adj[nd][i]]=true;
                parent[adj[nd][i]]=nd;
                q.push({adj[nd][i],dis+1});
            }
        }
    }
    return -1;
}
void solve(){}
int32_t main(){
   int n,m;
   cin>>n>>m;
   vvi adj(n+1);
   vi vis(n+1,0);
   rep(i,0,m){
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
   }

    vi parent(n+1,-1);

    int ans=bfs(adj,vis,parent);

    if(ans==-1){
        cout<<"IMPOSSIBLE"<<ln;
    }else{
        vi anss;
        int x=n;
        while(x!=1){
            anss.pb(x);
            x=parent[x];
        }
        anss.pb(1);
        cout<<ans<<ln;
        revp(i,sz(anss)-1,0){
            cout<<anss[i]<<" ";
        }
    }
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}