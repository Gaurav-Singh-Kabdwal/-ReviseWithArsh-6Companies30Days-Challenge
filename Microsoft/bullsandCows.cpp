class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bulls = 0, cows = 0;
        vector<int> hash(10);

        for(int i=0; i<secret.size();i++){

            if(secret[i]==guess[i]) bulls++;
            else{
                if(hash[secret[i]-'0']++ < 0) cows++;
                if(hash[guess[i]-'0']-- > 0) cows++;
            }
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};