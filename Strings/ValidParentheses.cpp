class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s) {
            if(i=='(' or i=='{' or i=='[') st.push(i);
            else {
                if(st.empty()) return false;
                char c = st.top();
                if(c=='(' and i==')' or c=='[' and i==']' or c=='{' and i=='}') {
                    st.pop();
                }
                else return 0;
            }
        }
        if(st.empty()) return 1;
        return 0;
    }
};