#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
  
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    //Bubble Sort
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j + 1] < a[j]) {
                swap(a[j + 1], a[j]);
            }
        }
    }
    
    for(auto it: a) {
        cout << it << " ";
    }
    return 0;
}