class Solution{   
public:
    string printMinNumberForPattern(string S){
         
        stack<char> st;
        char cnt = '1';
        
        st.push(cnt);
        string ans= "";
        
        for(char ch : S){
            
            if(ch=='I'){
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
            }
            
            cnt++;
            st.push(cnt);
            
            
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
