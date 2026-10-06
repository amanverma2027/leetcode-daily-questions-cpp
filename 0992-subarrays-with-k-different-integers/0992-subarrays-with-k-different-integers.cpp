class Solution {
public:

    int atMost(vector<int>& nums, int k) {
     int l = 0, r = 0, count = 0;
        unordered_map<int, int> mp;

        while (r < nums.size()) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l = l + 1;
            }
            count = count + (r - l + 1);
            r = r + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);

    }
};