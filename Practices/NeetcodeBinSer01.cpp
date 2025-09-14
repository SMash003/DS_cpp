#include<bits/stdc++.h>
using namespace std;
int search(int arr[], int size, int target){
    int l=0, r, mid;
    r = size - 1;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(target == arr[mid])
        {
            return mid;
        }
        else if(target > arr[mid])
        {
            l = mid + 1;
        }
        else 
            r = mid - 1;
    }
    return -1;
}
int main(){
    int n, target;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Target: ";
    cin >> target;
    cout << "Found at index: ";
    cout << search(arr, n, target);
    return 0;
}