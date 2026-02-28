class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        
        for (int i = 1; i < numRows - 1; i++) {
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        
        prevRows.push_back(newRow);
        return prevRows;
    }
};

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans(numRows);
        
//         for(int i=1; i<=numRows; i++){
//             vector<int>col(i,1);
//             for(int j=0; j<col.size(); j++){
//                 if(j==0 || j==col.size()-1){
//                     continue;
//                 }
//                 col[j] = ans[i-1][j-1] + ans[i-1][j];
//             }
//             ans[i-1] = col;


//         }
//         return ans;
//     }
// };