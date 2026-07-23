class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        
        int ans = 1;
        while(ans <= n)
            ans <<= 1;    // this left shift by 1 double the value so it keeps doubling the ans as 2^ until it becomes larger or equal to the n and then return ans 
        
        return ans;
    }
};