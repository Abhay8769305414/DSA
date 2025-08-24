class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(nums, 0, result);
        return result;
    }

private:
    void permuteHelper(vector<int>& nums, int i, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permuteHelper(nums, i + 1, result);
            swap(nums[i], nums[j]); // Backtrack
        }
    }
};