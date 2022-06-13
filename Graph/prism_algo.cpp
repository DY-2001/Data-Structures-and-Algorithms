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
 
#define pb push_back;
#define op pop_back;
#define ft front;
#define bk back;
#define first ff;
#define second ss;
#define make_pair mp;
#define ub upper_bound;
#define lb lower_bound;
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
 
using pi = pair<int, int>;
using vi = vector<int , int>;
using mi = map<int, int>;
using si = set<int, int>;
 
const int mod = 1000000007;
const ll MODE = 1e9 + 7;
const ll MOD = 998244353;
const ll inf = 1e9;
const int MX = 2e5 + 5;
 
int smallest_digit(int n) {
   int min = n % 10;
   n /= 10;
   while (n != 0) {
      if (min > n % 10)
         min = n % 10;
      n /= 10;
   }
   return min;
}
 
bool ignore_case(char a, char b) {  
   return (tolower(a) == tolower(b));  
}  
 
ll _lis(ll arr[], ll n, ll* max_ref)
{
    if (n == 1)
        return 1;
 
    ll res, max_ending_here = 1;
 
    for (ll i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    return max_ending_here;
}
 
ll lis(ll arr[], ll n)
{
    ll max = 1;
    _lis(arr, n, &max);
    return max;
}
    
int main() {
    ll I = LLONG_MAX;
    ll n;
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    
    ll cost[][8] =  {{I, I, I, I, I, I, I, I}, 
                    {I, I, 25, I, I, I, 5, I}, 
                    {I, 25, I, 12, I, I, I, 10}, 
                    {I,I , 12, I, 8, I, I, I}, 
                    {I, I, I, 8, I, 16, I, 14}, 
                    {I, I, I, I, 16, I, 20, 18}, 
                    {I, 5, I, I, I, 20, I, I}, 
                    {I, I, 10, I, 14, 18, I, I}}; 

        ll near[8]={I, I, I, I, I, I, I, I}; 
        ll t[2][6]; 
        ll i, j, k,  u, v, n = 7, min = I; 
        
        for(i = 1; i <= n; i++) { 
            for(j = i; j <= n; j++) { 
                if(cost[i][j] < min) { 
                    min = cost[i][j]; 
                    u = i; 
                    v = j; 
                } 
            } 
        } 
        t[0][0] = u; 
        t[1][0] = v; 
        near[u] = 0;
        near[v] = 0; 
        
        for(i = 1; i <= n; i++) { 
            if(near[i] != 0) 
            { 
                if(cost[i][u] < cost[i][v]) 
                    near[i]=u; 
                else
                    near[i]=v; 
            } 
        } 
        
        for(i = 1; i < n - 1; i++) { 
            min = I; 
            for(j = 1; j <= n; j++) { 
                if(near[j] != 0 && cost[j][near[j]] < min) { 
                    k = j; 
                    min = cost[j][near[j]]; 
                } 
            } 
            t[0][i] = k; 
            t[1][i] = near[k]; 
            near[k] = 0; 
            
            for(j = 1; j <= n; j++) { 
                if(near[j] != 0 && cost[j][k] < cost[j][near[j]]) 
                near[j] = k; 
            } 
        
        } 
        
        for(i = 0; i < n - 1; i++) { 
            cout<< "(" << t[0][i] << "," << t[1][i] << ")" << endl; 
        } 

    return 0;
}
 