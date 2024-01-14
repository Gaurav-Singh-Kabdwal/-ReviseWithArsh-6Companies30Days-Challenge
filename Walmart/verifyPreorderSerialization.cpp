class Solution {

public:
    bool isValidSerialization(string preorder) {
        
        if(preorder.empty()) return false;
        preorder += ',';
        int n = preorder.size(), i = 0, child = 1;

        for( i=0; i<n; i++){

            if(preorder[i]!=',') continue;

            child--;
            if(child<0) return false;
            if(preorder[i-1] != '#') child += 2;

        }

        return child==0;
    }
};