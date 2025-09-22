// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
        
//         HashSet<Integer> ans = new HashSet<>();
        
//  for(int i=0; i< nums.length; i++){
//     if(ans.contains(nums[i])){
//         return true;
//     }
//     else{
//         ans.add(nums[i]);
//     }

//  }
//  return false;

//     }
// };


#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ans;   
        for (int i = 0; i < nums.size(); i++) {
            if (ans.count(nums[i])) {
                return true;
            } else {
                ans.insert(nums[i]);    
            }
        }
        return false;  
    }
};