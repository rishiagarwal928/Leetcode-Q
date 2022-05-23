class Solution {
public:
    int m  = 0;
    int x = 0,y=0;
   void solve(string s, int i, int j){
        
        while(i >= 0 && j <= s.size() && s[i] == s[j]){
            int len = j-i+1;
            if(m<len) {
                m = len;
                x = i; y=j;
            }
            --i; ++j;
        }
    }
    
string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); ++i){
             solve(s, i, i);
             solve(s, i, i + 1);
        }
        return s.substr(x,m);
    }
};