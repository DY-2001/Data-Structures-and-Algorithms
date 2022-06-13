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
    ll n, value = 0, connection = 0;
    cin >> n;

    vll v;
    vvll adj;
    fori(i, n) {
        cout << "Enter the Number of vertices connected to " << i << " vertice and then give those vertices:" << endl;
        cin >> connection;
        for(ll j = 0; j < connection; j++) {
            cin >> value;
            v.push_back(value);
            
        }
        adj.push_back(v);
        v.clear();
    }
    
    ll s;
    cout << "Enter the source vertice :" << endl;
    cin >> s;

    qu q;
    vb used(n);
    vll d(n), p(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;

    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        for(ll u : adj[v]) {
            if(!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    ll t;
    cout << "Enter the Vertices for which you want to find the shortest path :" << endl;
    cin >> t;

    if(!used[t]) {
        cout << "No Path!";
    }
    else {
        vi path;
        for(ll v = t; v != -1; v = p[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());      
        cout << "Path : ";
        
        for(ll v: path) {
            cout << v << " ";
        }
    }

	return 0;
}