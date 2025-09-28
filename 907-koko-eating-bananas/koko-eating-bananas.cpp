class Solution {
public:
   bool canFinishInTime(const vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            // Use integer division for ceiling: (pile + k - 1) / k
            totalHours += (pile + k - 1) / k;
            if (totalHours > h) return false; // Early exit if already over
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinishInTime(piles, h, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};