class Solution {
public:
    int minBitFlips(int start, int goal) {
        int s = start ^ goal;
        int count = 0;
        for (int i = 31; i >= 0; i--) {
        int k = s >> i;
        if (k & 1)
            count++;
        
    }
        return count;
        
    }
};