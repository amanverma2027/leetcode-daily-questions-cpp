class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, maxi = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }

        maxi = count;

        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i - k]))
                count--;

            if (isVowel(s[i]))
                count++;

            maxi = max(maxi, count);
        }

        return maxi;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};