class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq, mindq;
        int left = 0, right = 0;
        int ans = 0;

        while (right < nums.size()) {
            // Maintain max deque
            while (!maxdq.empty() && nums[maxdq.back()] < nums[right])
                maxdq.pop_back();
            maxdq.push_back(right);

            // Maintain min deque
            while (!mindq.empty() && nums[mindq.back()] > nums[right])
                mindq.pop_back();
            mindq.push_back(right);

            // Shrink window if diff exceeds limit
            while (!maxdq.empty() && !mindq.empty() && nums[maxdq.front()] - nums[mindq.front()] > limit) {
                if (maxdq.front() == left) maxdq.pop_front();
                if (mindq.front() == left) mindq.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};
