#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n*m -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col] < target)
            {
                low = mid + 1;
            }
            else
            high = mid - 1;
        }
        return false;
    }
};
int main(){
    int rows, cols, target;
    cout << "Enter number of row: " << endl;
    cin >> rows;
    cout << "Enter number of column: " << endl;
    cin >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter elements of the matrix: "<< endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Target: " << endl;
    cin >> target;
    Solution sol;
    bool found = sol.searchMatrix(matrix, target);
    if(found)
    {
        cout<< "Found.";
    }
    else
    cout << "Not found.";
}