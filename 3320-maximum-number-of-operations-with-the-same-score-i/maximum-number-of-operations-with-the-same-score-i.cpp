class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1];
        int count =1;

        for(int i=2; i<nums.size(); i +=2){
            if(nums[i] + nums[i+1] == score)
            count++;
            else
            break;
        }
        return count;
    }
};