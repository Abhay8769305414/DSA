class Solution {
public:
    int divbyD(vector<int>& nums, int D) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil((double)num / (double)D);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (divbyD(nums, mid) <= threshold) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};