class Solution {
public:
    //f(6) -> f(3) -> f(1)
    bool solve(int n){
        if(n==1){
            return true;
        }
        if(n%2==0){
            n=n/2;
        }
        else if(n%5==0){
            n=n/5;
        }
        else if(n%3==0){
            n=n/3;
        }
        else{
            return false;
        }
        return solve(n);
    }
    bool isUgly(int n){
        if(n<=0)return false;
        return solve(n);
    }
};