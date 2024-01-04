class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        vector<int> dp(forget);
        dp[0] = 1;

        long mod = 1e9+7, share = 0;

        for(int i=1; i<n;i++){

            dp[i%forget] = share = (share + dp[(i-delay+forget)%forget]-dp[i%forget]+mod)%mod;       
        }

        return accumulate(dp.begin(),dp.end(),0L)%mod;   
    }
};