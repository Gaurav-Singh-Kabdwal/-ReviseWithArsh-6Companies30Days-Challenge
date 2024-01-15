class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       
        int n = s.size(), j = 0, sum = 0, ans = 0;

        for(int i=0; i<n; i++){

            sum += abs(s[i]-t[i]);
 
            while(j<=i&&sum>maxCost){
                sum -= abs(t[j]-s[j++]);
            }

            ans = max(ans, i-j+1);
        }

        return ans;
    }
};