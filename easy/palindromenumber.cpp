class Solution {
public:
    bool isPalindrome(int x){
        if(x<0)return false;
        long long palindrome = 0;
        int t = x;
        while(x>0){
            int mod = x%10;
            palindrome = (long long) palindrome * 10 + mod;
            x = x/10;
        }   
        if(t==palindrome)return true;
        return false;
    }
};


/*
optimised solution:
only check the halfs */

class Solution {
public:
    bool isPalindrome(int x){
        if(x<0 || ((x%10==0) && x!=0)){
            return false;
        }
        int reversedhalf = 0;
        while(x>reversedhalf){
            reversedhalf = reversedhalf * 10 + x%10;
            x/=10;
        }
        return (x==reversedhalf) || (x==reversedhalf/10);
    }
};