#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            if(m.count(x)) return {m[x],i};
            m[nums[i]]=i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=s.twoSum(nums,target);
    for(int i:ans) cout<<i<<" ";
}
