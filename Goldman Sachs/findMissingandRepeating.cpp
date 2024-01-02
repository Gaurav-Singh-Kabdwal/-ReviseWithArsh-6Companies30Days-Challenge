class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        int xori = 0;
        
        for(int i=0; i<n; i++){
            xori ^= (i+1);
            xori ^= arr[i];
        }
        
        int diffBit = xori&~(xori-1);
        
        int xor1 = 0, xor0 = 0;
        
        for(int i=0; i<n; i++){
            
            if(arr[i]&diffBit) xor1 ^= arr[i];
            else xor0 ^= arr[i];
            
            if((i+1)&diffBit) xor1 ^= (i+1);
            else xor0 ^= (i+1);
        }
        
        
        int i;
        for(i=0; i<n; i++){
            if(arr[i]==xor0) break;
        }
        
        if(i!=n) return {xor0,xor1};
        return {xor1,xor0};
    }
};