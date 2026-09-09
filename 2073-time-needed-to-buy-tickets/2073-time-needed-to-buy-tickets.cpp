class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            q.push({tickets[i], i});
        }
        int time = 0;
        while(!q.empty()) {
            auto [num_tickets, og_i] = q.front();
            q.pop();
            num_tickets--;
            time++;
            if(og_i == k && num_tickets == 0) {
                return time;
            }
            if(num_tickets > 0) {
                q.push({num_tickets, og_i});
            }
        }

        return time;
        
    }
};