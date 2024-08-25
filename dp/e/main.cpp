#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vector<long long>>
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
const ll len = 110;
const ll maxval = 100100;

int32_t main() {
    ll n, w;
    cin >> n >> w;
    vvll wtval(n, vll(2)); // Weight and Value pairs
    rep(i, 0, n) {
        cin >> wtval[i][0] >> wtval[i][1];
    }

    vll prev(maxval, 1e17),curr(maxval, 1e17);
    prev[0] = 0;

    rep(i, 1, n+1) { // Iterate from 1 to n
        rep(j, 0, maxval) {
            curr[j] = prev[j];
            if (j - wtval[i-1][1] >= 0) {
                curr[j] = min(curr[j], wtval[i-1][0] + prev[j - wtval[i-1][1]]);
            }
        }
        prev = curr;
    }

    ll ans = 0;
    rep(j, 0, maxval) {
        if (prev[j] <= w) {
            ans = j;
        }
    }

    cout << ans << ln;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}