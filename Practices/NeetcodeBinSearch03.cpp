#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int> &piles){
    int Max = INT_MIN;
    int n = piles.size();
    for(int i=0; i<n; i++)
    {
        Max = max(Max, piles[i]);
    }
    return Max;
}

int CalcTotalHrs(vector<int> &piles, int hourly)
{
   int total_hour = 0;
   int n = piles.size();
   for(int i=0; i<n; i++)
   {
        total_hour += ceil((double)piles[i]/(double)hourly);
   }
   return total_hour;
}

int minEatingSpeed(vector<int> piles, int h) {
    int low = 1, high = findMax(piles);        
    while(low <= high)
    {
        int mid = (low + high)/2;
        int totalHrs = CalcTotalHrs(piles, mid);
        if(totalHrs <= h){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }   
    }
    return low;
}
};


int main()
{
    int n,h;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter the elements of array: ";
    vector<int> piles(n);
    for(int i=0; i<n; i++)
    {
        cin >> piles[i];
    }
    cout << "Enter maximum hour: ";
    cin >> h;
    Solution sol;
    cout << sol.minEatingSpeed(piles, h);
    return 0;
}