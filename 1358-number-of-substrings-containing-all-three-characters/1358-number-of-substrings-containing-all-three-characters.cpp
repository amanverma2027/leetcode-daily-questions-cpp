class Solution {
public:
    int numberOfSubstrings(string s) {

        int hash[3] = {0};
        int left = 0, count = 0;

        for (int right = 0; right < s.size(); right++) {
            hash[s[right] - 'a']++;

            while(hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
                count += s.size() - right;
                hash[s[left] - 'a']--;
                left++;
            }
        }
        return count;
        // long long count = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     long long hash[3] = {0};

        //     for (int j = i; j < s.size(); j++) {
        //         hash[s[j] - 'a'] = 1;

        //         if (hash[0] + hash[1] + hash[2] == 3)
        //         count = count + 1;
        //     }
        // }
        // return count;
    } 
};