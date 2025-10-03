
#include <bits/stdc++.h>


#include <iostream>

iostream>

#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans; */

        // Optimal
        /* unordered_map<int, int> num_map; // Map to store number and its index
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the complement

            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                ans.push_back(
                    num_map[complement]); // Add the index of the complement
                ans.push_back(i);         // Add the current index
                return ans; // Return the answer as soon as we find it
            }

            // Store the current number and index in the map
            num_map[nums[i]] = i;
        }

        return ans; */

        /* vector<int> ans;
        
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0;i<n;i++){
           map[nums[i]] = i;
        }

        for(int i = 0;i<n;i++){
            int rem = target - nums[i];
            if(map.find(rem) != map.end() && map[rem] != i){
                ans.push_back(i);
                ans.push_back(map[rem]);
                
                return ans;
            }
        }
        return ans; */


        /* unordered_map<int,int> map;
        int n = nums.size();

        for(int i = 0;i<n;i++){
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
