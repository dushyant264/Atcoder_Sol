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
const int dirx[]={0,0,1,-1};
const int diry[]={1,-1,0,0};
const int dir[]={'R','L','D','U'};
// const ll mod = 998244353;
bool inlimit(int i, int j, int n, int m){
    return i>=0 && i<n && j>=0 && j<m;
}
bool bfs(int i, int j, vector<vector<char>>& v, vector<vector<int>>& parent , vector<vector<bool>>& vis) {
    queue<pii>q;
    q.push({i,j});
    vis[i][j]=true;
    while(!q.empty()){
        int x=q.front().ff,y=q.front().ss;
        q.pop();

        if(v[x][y]=='B')return true;

        rep(i,0,4){
            int xx=x+dirx[i],yy=y+diry[i];
            if(inlimit(xx,yy,sz(v),sz(v[0])) && !vis[xx][yy] && v[xx][yy]!='#'){
                vis[xx][yy]=true;
                q.push({xx,yy});
                parent[xx][yy]=i;
            }
        }
    }
    return false;
}
void solve(){}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int a=-1,b=-1,c=-1,d=-1;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<int>> parent(n,vector<int>(m,-1));
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                a=i;b=j;
            }else if(v[i][j]=='B'){
                c=i;d=j;
            }
        }
    }
    
    string pat="";

    // form string
    
    if(bfs(a,b,v,parent,vis)){
        while(c!=a || d!=b){
            int x=parent[c][d];
            pat+=dir[x];
            c-=dirx[x];
            d-=diry[x];
        }
        reverse(all(pat));
        cout<<"YES"<<ln;
        cout<<pat.size()<<ln;
        cout<<pat<<ln;
    }else{
        cout<<"NO"<<ln;
    }

ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;}