class Solution {
  public:
    int findKRotation(vector<int> &arr){
        int low = 0, high = arr.size()-1, ans=INT_MAX, idx=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            if(arr[mid]<ans){
                ans= arr[mid];
                idx=mid;
            }
        }
        return idx % arr.size();
    }
};


/*
finding minimum, if arr[mid]>arr[high], second half else first half
*/