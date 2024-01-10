class Solution {

private:

    int helper(vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& mp, int k) {
        if (mp.count(k)) return mp[k];
        int n = price.size(), ans = 0;
        
        vector<int> pows(n, 1);
        for (int i = n-2; i >= 0; i--) pows[i] = pows[i+1]*11;
        for (int i = 0; i < n; i++) ans += ((k/pows[i])%11)*price[i];
        for (auto spe:special) {
            int key = 0, i = 0;
            
            while (i < n) {
                int t = (k/pows[i])%11;
                if (t >= spe[i]) 
                    key = key*11+(t-spe[i++]);
                else
                    break;
            } 
            if (i == n) ans = min(ans, spe[n]+helper(price, special, mp, key));
        }
        mp[k] = ans;
        return ans;
    }
    int get_key(vector<int>& needs) {
        int n = needs.size(), key = 0;
        for (int i = n-1, p = 1; i >= 0; i--, p *= 11)
            key += needs[i]*p;
        return key;
    }

public:

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> mp;
        return helper(price, special, mp, get_key(needs));
    }

};