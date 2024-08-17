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
class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0), size(n, 1), num_components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite_by_rank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            num_components--;
            return true;
        }
        return false;
    }

    int component_size(int x) {
        return size[find(x)];
    }

    int components() const {
        return num_components;
    }

    private:
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> size;
    int num_components;
};
void solve(){}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<pii> adj;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj.pb({a-1,b-1});
    }
    DSU d(n);
    // leaders n then connect them
    rep(i,0,m){
        d.unite_by_rank(adj[i].ff,adj[i].ss);
    }
    vector<int> leaders;
    cout<<d.components()-1<<ln;
    rep(i,0,n){
        if(d.find(i)==i){
            leaders.pb(i);
        }
    }
    rep(i,1,sz(leaders)){
        cout<<leaders[i-1]+1<<" "<<leaders[i]+1<<ln;
    }
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}