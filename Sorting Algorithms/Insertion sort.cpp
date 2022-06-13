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
    
    //Insertion sort
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(a[i] < a[j]) {
                swap(a[i], a[j]);
                i = j;
            }
        }
    }
    
    for(auto it: a) {
        cout << it << " ";
    }
    return 0;
}