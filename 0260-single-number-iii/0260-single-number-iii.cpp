class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for (int num : nums) {
            xorAll ^= num;
        }

        unsigned int x = static_cast<unsigned int>(xorAll);
        unsigned int bit = x & (~x + 1u);

        int a = 0, b = 0;

        for (int num : nums) {
            if ((static_cast<unsigned int>(num) & bit) != 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};