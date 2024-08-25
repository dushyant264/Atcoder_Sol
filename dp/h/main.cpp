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
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long>>
#define vb vector<bool>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define repvb(i,a,b) for(int i=b;i>=a;i--)
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
ll solve(vvll& dp,vvc& grid,int i,int j){
    if(i>=grid.size()||j>=grid[0].size())return 0;
    if(grid[i][j]=='#')return 0;
    if(i==grid.size()-1&&j==grid[0].size()-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=solve(dp,grid,i+1,j)+solve(dp,grid,i,j+1);
    return dp[i][j]%=mod;
    }
int32_t main(){
    int n,m;
    cin>>n>>m;
    vvc grid(n,vc(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
        }
    }
    vvll dp(n,vll(m,-0));
    dp[n-1][m-1]=1;
    repv(i,0,n){
        repv(j,0,m){
            if(grid[i][j]=='#')dp[i][j]=0;
            else{
                if(i+1<n)dp[i][j]+=dp[i+1][j];
                if(j+1<m)dp[i][j]+=dp[i][j+1];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[0][0];
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}