#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
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
bool bfs(vvi& adj, vi& side){
    bool is_bipartite=true;
    queue<int>q;
    rep(i,0,sz(side)){
        if(side[i]==-1){
            q.push(i);
            side[i]=0;
            while(!q.empty()){
                int nd=q.front();
                q.pop();
        
                for(auto x:adj[nd]){
                    if(side[x]==-1){
                        side[x]=side[nd]^1;
                        q.push(x);
                    }else if(side[x]==side[nd]){
                        is_bipartite=false;
                        return is_bipartite;
                    }
                }
            }
        }
    }
    return is_bipartite;
}
void solve(){
    // bipartite graph
    int n,m;
    cin>>n>>m;
    vvi adj(n);
    vi side(n,-1);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
if(bfs(adj,side)){
    rep(i,0,n){
        cout<<side[i]+1<<" ";
    }
}else{
    cout<<"IMPOSSIBLE";
}
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}