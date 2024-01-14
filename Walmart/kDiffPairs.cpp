class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        int ans = 0;

        for(int x: nums) mpp[x]++;

        for(auto it : mpp){

            if((k==0)&&it.second>1||k>0&&mpp.count(it.first+k)) 
                ans++ ;    
        }

        return ans;
    }
};