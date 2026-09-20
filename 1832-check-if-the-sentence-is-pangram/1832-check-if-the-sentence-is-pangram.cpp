class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st(sentence.begin(), sentence.end());
        return st.size() == 26;

        // unordered_set <char> st;

        // for (char c: sentence) {
        //     st.insert(c);
        // }
        
    }
};