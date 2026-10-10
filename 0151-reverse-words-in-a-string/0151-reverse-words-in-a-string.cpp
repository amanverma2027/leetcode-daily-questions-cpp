class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string word, ans;

        while (ss >> word) {
            if (!ans.empty())
                ans = word + " " + ans;
            else
                ans = word;
        }

        return ans;
        
    }
};