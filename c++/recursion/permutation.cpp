#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>& nums, int start, vector<vector<int>>& ans) {
    if (start == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, ans);
        swap(nums[start], nums[i]); // backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    permute(nums, 0, ans);

    cout << "Permutations:\n";
    for (auto v : ans) {
        cout << "[ ";
        for (auto x : v) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
