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
    
int edge[9][3] = {{1, 2, 28}, {1, 6, 10}, {2, 3, 16}, {2, 7, 14}, {3, 4, 12}, {4, 5, 22}, {4, 7, 18}, {5, 6, 25}, {5, 7, 24}}; 
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; 
int included[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 
void join(int u, int v) 
{ 
    if(set[u] < set[v]) 
    { 
        set[u] += set[v]; 
        set[v] = u; 
    } 
    else
    { 
        set[v] += set[u]; 
        set[u] = v; 
    } 
} 
int find(int u) 
{ 
    int x = u, v = 0; 
    while(set[x] > 0) 
    { 
        x = set[x]; 
    } 
    while(u != x) 
    { 
        v = set[u]; 
        set[u] = x; 
        u = v; 
    } 
    
    return x; 
}  
int t[2][7]; 
int main(int argc, const char * argv[]) 
{ 
    int u = 0, v = 0, i, j, k = 0, min = 65535, n = 9; 
    i = 0; 
    
    while(i < 6) 
    { 
        min = 65535; 
        for(j = 0; j < n; j++) 
        { 
            if(included[j] == 0 && edge[j][2] < min) 
            { 
                u = edge[j][0]; v = edge[j][1]; min = edge[j][2]; 
                k = j; 
            } 
        } 
        if(find(u) != find(v)) 
        { 
            t[0][i] = u; t[1][i] = v; 
            join(find(u), find(v)); 
            included[k] = 1; 
            i++; 
        
        } 
        else
        { 
            included[k] = 1; 
        } 
    } 
    printf("Spanning Tree\n"); 
    for(i = 0; i < 6; i++) 
    { 
        printf("%d %d\n",t[0][i], t[1][i]); 
    } 
    return 0; 
}
 