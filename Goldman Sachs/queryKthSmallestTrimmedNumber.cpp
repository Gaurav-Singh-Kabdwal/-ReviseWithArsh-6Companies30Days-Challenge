class Solution {

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries){
        
        vector<int> ans;
        

        for(auto q: queries){
            
            int k = q[0];
            int n = q[1];
            vector<pair<string,int>> v;

            for(int i=0; i<nums.size(); i++){

                string num = nums[i].substr(nums[i].size()-n,n);

                v.push_back({num,i});

            }
            sort(v.begin(),v.end());
            ans.push_back(v[k-1].second);
        }
                
        return ans;
    }
};