class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            return right - left - 1;
        };

        for (int i =0; i < n; i++) {
            int len1 = expand(i, i);

            int len2 = expand(i, i + 1);

            int len = max(len1, len2);

            if (len > maxlen) {
                maxlen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxlen);
    }
};