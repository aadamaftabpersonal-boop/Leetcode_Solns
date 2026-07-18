    class Solution {
    public:
        long long gcd(int a, int b){
            if(b==0)return a;
            return gcd(b, a%b);
        }
        long long gcdSum(vector<int>& nums){
            int maxm=nums[0];
            for(int i=0;i<nums.size();i++){
                if(nums[i]>maxm)maxm=nums[i];
                nums[i] = gcd(nums[i], maxm);
            }
            sort(nums.begin(), nums.end());
            int i=0, j=nums.size()-1;
            long long sum=0;
            while(i<j){
                sum+=gcd(nums[i], nums[j]);
                i++;j--;
            }
            return sum;
        }
    };