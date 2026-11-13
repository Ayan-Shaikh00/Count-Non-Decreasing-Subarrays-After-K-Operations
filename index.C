#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        // Step 1: Initialize the monotonic deque and sliding window.
        int n = nums.size();
        deque<int> dq;
        long long cost = 0, ans = 0;
        int j = n - 1;

        // Step 2: Expand the window from right to left.
        for (int i = n - 1; i >= 0; i--) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int left = dq.back();
                dq.pop_back();
                int right = dq.empty() ? j + 1 : dq.back();
                cost += 1LL * (right - left) * (nums[i] - nums[left]);
            }

            dq.push_back(i);

            // Step 3: Shrink the window until the cost is valid.
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                j--;
            }

            // Step 4: Count all valid subarrays starting at i.
            ans += j - i + 1;
        }

        return ans;
    }
};
