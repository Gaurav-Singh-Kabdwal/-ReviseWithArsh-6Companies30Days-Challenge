class Solution {

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2]<b[2];
    }

public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        vector<vector<int>> ans;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                ans.push_back({i,j, abs(i-rCenter)+abs(j-cCenter)});
            }
        }

        sort(ans.begin(),ans.end(),cmp);

        for(auto &arr : ans){
            arr.pop_back();
        }

        return ans; 
    }
};