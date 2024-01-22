class Solution {
public:
    int longestString(int x, int y, int z) {
        
        return 2*min(x,y)+2*min(min(x,y)+1,max(x,y))+2*z;  
    }
};