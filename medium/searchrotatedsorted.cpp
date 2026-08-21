class Solution {
public:
    int search(vector<int>& nums, int target){
        //find minm
        int low=0, high=nums.size()-1, ans=INT_MAX, idx=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[high]){
                low= mid+1;
            }
            else{
                high=mid-1;
            }
            if(nums[mid]<ans){
                ans=nums[mid];
                idx=mid;
            }
        }
        int i=0, j=idx-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)i=mid+1;
            else j=mid-1;
        }
        i=idx;
        j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};

//just an improvised version of find min in sorted array
