//sorted matlab binary search
class Solution {
public:
    int findMin(vector<int>& nums){
        int n = nums.size();
        int low = 0, high = n-1, ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            ans = min(ans, nums[mid]);
        }
        return ans;
    }
};

//if nums[mid]>nums[high], sure that array is rotated
//for a normal array -> nums[low]<nums[mid]<nums[high]
//mathematically can prove that if nums[mid]>nums[high], nums[low]>nums[high]
