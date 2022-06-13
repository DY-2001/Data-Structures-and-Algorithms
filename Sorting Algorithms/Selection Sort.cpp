	#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, min_ele = INT_MAX, temp;
    cout << "Please give the value of n" << endl;
    cin >> n;
    
    int a[n];
    cout << "Please write the elements of array" << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    //Selection Sort
    for(int i = 0; i < n - 1; i++) {
        temp = i;
        for(int j = i + 1; j < n; j++) {
            if(a[temp] > a[j]) {
                min_ele = a[j];
                temp = j;
            }
        }
        swap(a[i], a[temp]);
    }
    cout << "The Sorted Array" << endl;
    for(int i = 0; i < n; i++) {
        cout <<  a[i] << " ";
    }
    return 0;
}