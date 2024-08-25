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
void solve(){}
int32_t main(){
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    vvi dp(n+1,vi(m+1,0));
    repv(i,0,n){
        repv(j,0,m){
            if(a[i]==b[j])dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    // u have to print the longest subsequence
    // so u have to backtrack the dp array
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            cout<<a[i];
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1])i++;
        else j++;
    }
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}