class Solution {
public:
    int reverseBits(int n) {
        uint32_t num = n;
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++){
            ans = (ans << 1) | (num & 1);
            num >>= 1;
        }
        return ans;
    }
};