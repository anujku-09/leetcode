class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int neg = n / 2;
        long long ans = 0;
        for(int i = 0; i < neg; i++){
            ans -= 1LL * nums[i] * nums[i];
        }
        for(int i = neg; i < n; i++){
            ans += 1LL * nums[i] * nums[i];
        }
        return ans;
    }
};