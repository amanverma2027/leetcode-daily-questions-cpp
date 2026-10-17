class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        int n = chars.size();

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch) {
                i++;
                count++;
            }

            chars[j++] = ch;

            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[j++] = c;
                }
            }
        }

        return j;   
    }
};