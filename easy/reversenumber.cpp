class Solution {
public:
    int reverseBits(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1); // Shift result left, append last bit of n
            n >>= 1;                           // Shift n right to process next bit
        }
        return result;
    }
};