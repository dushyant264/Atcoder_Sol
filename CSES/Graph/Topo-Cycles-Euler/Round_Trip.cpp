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
vi dfs(vvi& adj,vi& parent, vi& vis, int n){
    vi ans;
    stack<int>st;
    st.push(n);
    while(!st.empty()){
        int nd=st.top();
        st.pop();
        vis[nd]=1;

        for(auto x:adj[nd]){
            if(!vis[x]){
                parent[x]=nd;
                st.push(x);
            }
            else if(parent[nd]!=x){
                ans.pb(x);
                while(nd!=x){
                    ans.pb(nd);
                    nd=parent[nd];
                }
                ans.pb(x);
                return ans;
            }
        }
    }
    return ans;
}

void solve(){}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vi parent(n+1,0),vis(n+1,0);
    vvi adj(n+1);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    repb(i,1,n){
        if(!vis[i]){
            vi ans=dfs(adj,parent,vis,i);
            if(sz(ans)){
                cout<<sz(ans)<<ln;
                for(auto x:ans)cout<<x<<" ";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}