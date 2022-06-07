#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("03")
#pragma GCC optimization ("unroll-loops")
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned char uc;
typedef string str;
 
// #define pb push_back;
#define op pop_back;
#define ft front;
#define bk back;
// #define first ff;
// #define second ss;
#define make_pair mp;
#define ub upper_bound;
#define lb lower_bound;
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvll vector<vll>
#define qu queue<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sll set<ll, ll>
#define vpll vector<pll>
#define mpll map<pll>
#define spll set<pll>
#define mlpll map<ll, pll>
#define slpll set<ll, pll>
#define fori(i, n) for(ll i = 0; i < n; i++)
#define forij(j, n) for(ll j = 0; j < n; j++)
#define forijm(j, m) for(ll j = 0; j < m; j++)
#define foriji(j, i, n) for(ll j = i + 1; j < n; j++)
#define ford(i, n) for(ll i = n - 1; i >= 0; i--)
#define from(v) ((v).begin(), (v).end())
#define forii(i, n) for(int i = 0; i < n; i++)
#define fordi(i, n) for(int i = n - 1; i >= 0; i--) 
 
using pii = pair<int, int>;
using vii = vector<int , int>;
using mii = map<int, int>;
using sii = set<int, int>;
 
const int mod = 1000000007;
const ll MODE = 1e9 + 7;
const ll MOD = 998244353;
const ll inf = 1e9;
const int MX = 2e5 + 5;

int main() {
    cout << "Enter the number of vertices n : " << endl;
    ll n;
    cin >> n;

    ll adj[n][n];
    
    fori(i, n) {
        forij(j, n) {
            cout << "Enter " << i << " and " << j << " connected or not :" << endl;
            cin >> adj[i][j];
        }
    }

    vll vis(n);
    fori(i, n) {
        vis[i] = 0;
    }

    qu q;

    cout << "Enter the source vertice" << endl;
    ll s;
    cin >> s;
    

    cout << s << " ";
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v = 0; v < n; v++) {
            if(adj[u][v] == 1 && vis[v] == 0) {
                cout << v << " ";
                q.push(v);
                vis[v] = 1;
            }
        }
    }

	return 0;
}