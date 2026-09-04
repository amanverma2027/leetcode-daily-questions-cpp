class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int idx = nums2.size()-1;
        unordered_map<int, int> mp;

        for(idx = nums2.size()-1; idx>=0; idx--) {
    int curr = nums2[idx];
            while(!s.empty() && curr >= s.top()) {
                s.pop();
            }

            if(s.empty()) {
                mp[curr] = -1;
            } else {
                mp[curr] = s.top();
            }

            s.push(curr);
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};