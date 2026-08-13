class Solution {
public:
    bool isugly(int n){
        if(n==1){
            return true;
        }
        if(n%2==0){
            n/=2;
        }
        else if(n%3==0){
            n/=3;
        }
        else if(n%5==0){
            n/=5;
        }
        else{
            return false;
        }
        return isugly(n);
    }
    int nthUglyNumber(int n){
        int m=1, count=0;
        while(count!=n){
            if(isugly(m)){
                count++;
            }
            m++;
        }
        return m-1;
    }
};

class Solution {
public:
    int nthUglyNumber(int n){
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> visited;
        pq.push(1);
        vector<int> primes = {2, 3, 5};
        visited.insert(1);
        long long top = 0;
        for(int i=1;i<=n;i++){
            top = pq.top();
            pq.pop();
            for(auto prime: primes){
                long long ugly= top*prime;
                if(visited.find(ugly) == visited.end()){
                    visited.insert(ugly);
                    pq.push(ugly);
                }
            }
        }
        return top;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1; // First ugly number
        
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < n; i++) {
            int next2 = ugly[p2] * 2;
            int next3 = ugly[p3] * 3;
            int next5 = ugly[p5] * 5;
            
            int nextUgly = min({next2, next3, next5});
            ugly[i] = nextUgly;
            
            // Advance pointer(s) matching the chosen minimum.
            // Using separate 'if's (not else-if) automatically deduplicates!
            if (nextUgly == next2) p2++;
            if (nextUgly == next3) p3++;
            if (nextUgly == next5) p5++;
        }
        
        return ugly[n - 1];
    }
};