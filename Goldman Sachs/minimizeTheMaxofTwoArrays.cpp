class Solution {
public:
    int minimizeSet(int div1, int div2, int unCnt1, int unCnt2) {
        
        typedef long long ll;
        int high = INT_MAX;
        int low = 1;
        
        while(low<=high){

            int mid = low + (high-low)/2;
            ll llcm = (ll)div1/gcd(div1,div2)*div2;
            int lcm = llcm>INT_MAX?INT_MAX:llcm;
            
            if(unCnt1<=(mid-mid/div1)&&unCnt2<=(mid-mid/div2)
            &&unCnt1+unCnt2<=(mid-mid/lcm)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;

    }
};