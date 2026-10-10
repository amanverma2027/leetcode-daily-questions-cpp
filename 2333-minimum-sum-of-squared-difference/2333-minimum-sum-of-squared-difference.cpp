class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        vector<int> d;
        long long k = 1LL * k1 + k2, sum = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int x = abs(nums1[i] - nums2[i]);
            d.push_back(x);
            sum += x;
            mx = max(mx, x);
        }

        if (sum <= k) return 0;

        int l = 0, r = mx;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;

            for (int x : d)
                need += max(0, x - mid);

            if (need <= k) r = mid;
            else l = mid + 1;
        }

        long long ans = 0;
        for (int x : d) {
            int y = min(x, l);
            k -= max(0, x - l);
            ans += 1LL * y * y;
        }

        for (int i = 0; i < d.size() && k > 0; i++) {
            if (d[i] >= l && d[i] > 0) {
                ans -= 1LL * l * l;
                ans += 1LL * (l - 1) * (l - 1);
                k--;
            }
        }

        return ans;
        
    }
};