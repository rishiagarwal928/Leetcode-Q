class Solution {
public:
    int missingNumber(vector<int>& nums) { 
        int sum = 0;
        int total = nums.size()*(nums.size() + 1)/2;
        sum = accumulate(nums.begin(),nums.end(),0);
        return total-sum;
    }
};