class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        vector<int> dp(n);
        int sum = 0; 

        for(int i =0; i<n; i++){
            sum += nums[i];
            dp[0] += i*nums[i];
        }

        int maxi = dp[0];

        for(int i=1; i<n; i++){

            dp[i] = dp[i-1] + sum - n*nums[n-i];
            maxi = max(maxi,dp[i]);

        }

        return maxi;
    }
};