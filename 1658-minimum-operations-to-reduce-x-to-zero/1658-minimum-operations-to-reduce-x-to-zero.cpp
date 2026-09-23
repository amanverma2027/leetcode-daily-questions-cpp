class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size(), sum = 0, left = 0, maxi = -1;

        for(int right = 0; right < n; right++) {
            sum+= nums[right];

            while(left <= right && sum > target)
                sum-=nums[left++];

            if(sum == target)
                maxi = max(maxi, right - left + 1);
        }

        return maxi == -1 ? -1 : n - maxi;
        
    }
};