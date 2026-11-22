class Solution {
public:
    bool checkString(string s) {
        bool foundb = false;

        for (char c : s) {
            if (c == 'b') {
                foundb = true;
            }
            else if (foundb) {
                return false;
            }
        }

        return true;
    }
};