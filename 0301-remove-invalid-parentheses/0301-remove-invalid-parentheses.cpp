class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> seen;
        queue<string> q;

        q.push(s);
        seen.insert(s);

        while (!q.empty()) {
            int n = q.size();
            bool found = false;

            while (n--) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                    continue;
                }

                if (found)
                    continue;

                for (int i = 0; i < curr.size(); i++) {
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if (!seen.count(next)) {
                        seen.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found)
                return ans;
        }

        return {""};
    }

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(')
                balance++;
            else if (c == ')')
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }
};