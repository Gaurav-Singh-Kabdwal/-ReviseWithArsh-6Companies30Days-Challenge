class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size(), maxi = 0;
        vector<int> ans, dp(n,1),pred(n,-1);
        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++){
            for(int j = 0;j<i; j++){

                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1, pred[i] = j;

                if(dp[i]>dp[maxi]) maxi = i;
            }
        }

        for(; maxi>=0; maxi = pred[maxi]){
            ans.push_back(nums[maxi]);
        }

        return ans;
    }
};