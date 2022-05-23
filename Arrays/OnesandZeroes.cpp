class Solution {
public:
    
    int calculateMax(vector <pair <int, int> > &vec, int i, int m, int n, int dp[601][101][101]) {
        
        if(i >= vec.size() || m < 0 || n < 0)
            return  0;
        
        int a = 0;
        
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        if(m - vec[i].first >= 0 && n - vec[i].second >= 0) {
            
            a = 1 + calculateMax(vec, i + 1, m - vec[i].first, n - vec[i].second, dp);
        }
        
        
        return dp[i][m][n] = max(a, calculateMax(vec, i + 1, m , n , dp) );
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[601][101][101];
        
        for(int i = 0 ;  i < 601 ; i++)
            for(int j = 0  ; j < 101 ; j++)
                for(int k =0. ; k < 101; k++)
                dp[i][j][k] = -1;
        
        vector <pair <int, int> > vec;
        
        for(int i = 0 ; i < strs.size() ; i++) {
            
            string s = strs[i];
            int ones = 0;
            int zeros = 0;
            for(int i = 0 ; i < s.size() ; i++) {
                if(s[i] == '1') 
                    ones ++;
                else
                  zeros ++;
            }
            
            vec.push_back({zeros, ones});
        }
        
       return calculateMax(vec, 0, m, n, dp);
        
    }
};