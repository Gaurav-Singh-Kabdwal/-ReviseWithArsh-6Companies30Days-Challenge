class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        
        vector<int> cnt(121), sumCnt(121);
        int ans = 0;

        for(int age : ages){
            cnt[age]++;
        }

        for(int i= 1; i<=120; i++){
            sumCnt[i] = cnt[i] + sumCnt[i-1];
        }

        for(int i= 15; i<=120; i++){
            if(cnt[i]==0) continue;
            int n = sumCnt[i] -  sumCnt[i/2+7];
            ans += n*cnt[i]-cnt[i];
        }

        return ans;
    }
};