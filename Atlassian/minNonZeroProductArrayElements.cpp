class Solution {

    long long mod = 1000000007;

    long long exp(long long n, long long k){

        long long res = 1, mul = n;

        while(k){

            if(k&1){
                res = (mul*res)%mod;
            } 

            k >>= 1;
            mul = (mul%mod)*(mul%mod)%mod;
        }

        return res;
    }


public:
    int minNonZeroProduct(int p) {
        
        long long max = (1ll<<p)-1;
        long long half = exp(max-1,max/2ll);

        return half*(max%mod)%mod; 
    }
};