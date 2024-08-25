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
#define vb vector<bool>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define repvb(i,a,b) for(int i=b;i>=a;i--)
#define vd vector<double>
#define vvd vector<vector<double>>
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
void solve(vvd& dp, int i, int j, int n, vd& a){
    // if(i==n)return j>(n/2)?1.00:0.00;
    // if(dp[i][j]!=-1)return dp[i][j];
    // return dp[i][j]=dp[i+1][j]*(1-a[i])+dp[i+1][j+1]*a[i];
}
int32_t main(){
    int n;
    cin>>n;
    vd a(n);
    rep(i,0,n)cin>>a[i];

    vvd dp(n+1,vd(n+1,0.00));
    // solve(dp,0,0,n,a);
    repb(i,n/2 + 1,n)dp[n][i]=1.00;

    repv(i,0,n){
        repb(j,0,i+1){
             double take_heads = (j < n) ? a[i] * dp[i + 1][j + 1] : 0;
            double take_tails = (1 - a[i]) * dp[i + 1][j];
            dp[i][j] = take_heads + take_tails;
        }
    }

    cout<<setprecision(10)<<dp[0][0];
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}