
#include <bits/stdc++.h>


#include <iostream>

iostream>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;  
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }
            mp[nums[i]] = i;

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

    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    if(!ans.empty()){
        cout << "Indices: " << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;

    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=s.twoSum(nums,target);
    for(int i:ans) cout<<i<<" ";

}
