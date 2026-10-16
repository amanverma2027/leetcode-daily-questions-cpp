
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> s(4 * n), sq(4 * n), lazy(4 * n);
        vector<int> last(100001, -1);
        long long ans = 0;

        function<void(int, int, int)> push = [&](int p, int l, int r) {
            if (lazy[p] == 0 || l == r) return;

            int m = (l + r) / 2;
            long long v = lazy[p];

            for (int child : {p * 2, p * 2 + 1}) {
                int len = (child == p * 2) ? (m - l + 1) : (r - m);

                sq[child] = (sq[child] + 2 * v * s[child]
                           + v * v * len) % MOD;
                s[child] = (s[child] + v * len) % MOD;
                lazy[child] += v;
            }

            lazy[p] = 0;
        };

        function<void(int, int, int, int, int)> upd =
        [&](int p, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                sq[p] = (sq[p] + 2 * s[p] + (r - l + 1)) % MOD;
                s[p] = (s[p] + (r - l + 1)) % MOD;
                lazy[p]++;
                return;
            }

            push(p, l, r);

            int m = (l + r) / 2;
            upd(p * 2, l, m, ql, qr);
            upd(p * 2 + 1, m + 1, r, ql, qr);

            s[p] = (s[p * 2] + s[p * 2 + 1]) % MOD;
            sq[p] = (sq[p * 2] + sq[p * 2 + 1]) % MOD;
        };

        for (int i = 0; i < n; i++) {
            upd(1, 0, n - 1, last[nums[i]] + 1, i);
            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};
