class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums){
        int  n = nums.size();
        int current_slices=0, total_slices=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                current_slices+=1;
            }
            else{
                current_slices=0;
            }
            total_slices+=current_slices;
        }   
        return total_slices;
    }
};

//total_slices accumulates
