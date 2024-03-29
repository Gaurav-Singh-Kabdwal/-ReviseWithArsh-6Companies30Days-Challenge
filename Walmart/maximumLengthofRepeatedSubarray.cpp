class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size(), ans = 0;
        vector<int> prev(m+1), cur(m+1);
        
        for(int i=1; i<=n; i++){
            
            for(int j=1; j<=m; j++){

                if(nums1[i-1]==nums2[j-1])
                    cur[j] = prev[j-1]+1;
                else
                    cur[j] = 0;

                ans = max(ans, cur[j]);    
            }
            prev = cur;
        }

        return ans;
    }
};