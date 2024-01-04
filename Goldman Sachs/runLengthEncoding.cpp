string encode(string src)
{     
    string ans = "";
    int cnt, j;
    
    for(int i= 0; i<src.size(); ){
        
        j = i;
        
        while(src[j]==src[i]){
            j++;
        }
        
        ans += src[i]+to_string(j-i);
        
        i = j;
    }
    
    return ans;
}     
 