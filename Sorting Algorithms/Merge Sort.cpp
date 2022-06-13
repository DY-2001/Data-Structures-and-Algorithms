#include<bits/stdc++.h>
using namespace std;

//Merge_Sort
void Merge(int a[], int lower, int mid, int upper) {    
    int i = lower;                                     
    int j = mid + 1;                                       
    int k = lower;                                      
    vector<int> b(upper + 1);                                                     
    while(i <= mid && j <= upper) {                    
        if(a[i] <= a[j]) {                            
            b[k++] = a[i++];                          
        }
        else {
            b[k++] = a[j++];                            
        }
    }
    
    if(i > mid) {                                      
        while(j <= upper) {                             
            b[k++] = a[j++];                            
        }
    }
    else  {
        while(i <= mid) {                               
            b[k++] = a[i++];                           
        }
    }
    
    for(k = lower; k <= upper; k++) {                   
        a[k] = b[k];                                     
    }
}
 
void Merge_Sort(int a[], int lower, int upper) {         
    if(lower < upper) {                                 
        int mid = (lower + upper) / 2;                   
        Merge_Sort(a, lower, mid);                       
        Merge_Sort(a, mid + 1, upper);                  
        Merge(a, lower, mid, upper);                     
    }
}

int main()
{
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    Merge_Sort(a, 0, n - 1);
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}