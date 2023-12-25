/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
   public:
    std::vector<int> twoSum1(std::vector<int>& nums, int target) {
        /**
         * 61/61 cases passed (308 ms)
         * Your runtime beats 23.01 % of cpp submissions
         * Your memory usage beats 77.44 % of cpp submissions (10.6 MB)
        */
        for (unsigned long i = 0; i < nums.size(); i++) {
            for (unsigned long j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    // bad design by LeetCode
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return {};
    }


    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        /**
         * 1 pass add to hashmap and 
         * 61/61 cases passed (7 ms)
         * Your runtime beats 89.52 % of cpp submissions
         * Your memory usage beats 20.59 % of cpp submissions (11.4 MB)
        */
       
        std::unordered_map<int, unsigned long> hashMap;
        for (unsigned long i = 0; i < nums.size(); i++) {
            auto search = hashMap.find(target - nums[i]);
            if (search != hashMap.end()) {
                return {static_cast<int>(i), static_cast<int>(search->second)};
            } else {
                hashMap.insert({nums[i], i});
            }
        }
        return {};
    }
};
// @lc code=end
