class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        freq[0] = 1;

        int odd = 0;
        int ans = 0;

        for (int num : nums) {
            odd += num % 2;

            if (freq.count(odd - k))
                ans += freq[odd - k];

            freq[odd]++;
        }

        return ans;
        
    }
};