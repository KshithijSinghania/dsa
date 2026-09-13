class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int kid = find(nums.begin(), nums.end(), k) - nums.begin();

        unordered_map<int, int> mp;

        int balance = 0;
        mp[0]++;

        // Process elements to the right of k
        for (int i = kid + 1; i < n; i++) {
            balance += (nums[i] > k ? 1 : -1);
            mp[balance]++;
        }

        int ans = mp[0] + mp[1];

        balance = 0;

        // Process elements to the left of k
        for (int i = kid - 1; i >= 0; i--) {
            balance += (nums[i] > k ? 1 : -1);

            ans += mp[-balance];
            ans += mp[1 - balance];
        }

        return ans;
    }
};
