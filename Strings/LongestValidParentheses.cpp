class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> ind;
        int m = 0;
        ind.push(-1);
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') {
                st.push(s[i]);
                ind.push(i);
            }
            else {
                if(!st.empty() and st.top()=='('){
                    st.pop();
                    ind.pop();
                    m = max(m,i-ind.top());
                }
                else {
                    ind.push(i);
                }
            }
        }
        return m;
    }
};