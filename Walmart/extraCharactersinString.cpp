class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    { 
        int n = s.size();
        unordered_set<string> hm;
        for (string& word : dictionary) hm.insert(word);
        vector<int>dp(n + 1, 0);
      
        for (int index = n - 1; index >= 0; index--)
        {
            string currStr = "";
            int minExtra = s.size();
            for (int cutIdx = index; cutIdx < n; cutIdx++)
            {
                currStr += s[cutIdx];
                
                int currExtra = (hm.count(currStr))? 0 : currStr.size();
                int nextExtra = dp[cutIdx + 1]; 
                int totalExtra = currExtra + nextExtra;

                minExtra = min(minExtra, totalExtra);
            }
            dp[index] = minExtra;
        }
        
        for(int x: dp) cout<<x<<" ";
        cout<<endl;
        return dp[0];
    }
};