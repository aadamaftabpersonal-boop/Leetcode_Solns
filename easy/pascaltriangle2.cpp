class Solution {
public:
    vector<int> getRow(int rowIndex){
        vector<int> row(rowIndex+1, 0);
        row[0]=1;
        long long current =1;
        for(int i=1;i<=rowIndex;i++){
            current = current * (rowIndex-i+1)/i;
            row[i] = current;
        }
        return row;
    }
};

/*
shouldve used formula nck = nc(k-1) * (n-k+1)/k*/