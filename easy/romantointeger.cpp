class Solution {
public:
    int romanToInt(string s){
        int ans = 0;
        int i=0;
        while(i<s.size()){
            char x = s[i];
            if(i+1<s.size() && s[i]=='C' && s[i+1]=='M'){
                ans+=900;
                i++;
            }
            else if(i+1<s.size() && s[i]=='C' && s[i+1]=='D'){
                ans+=400;
                i++;
            }
            else if(i+1<s.size() && s[i]=='X' && s[i+1]=='L'){
                ans+=40;
                i++;
            }
            else if(i+1<s.size() && s[i]=='X' && s[i+1]=='C'){
                ans+=90;
                i++;
            }
            else if(i+1<s.size() && s[i]=='I' && s[i+1]=='V'){
                ans+=4;
                i++;
            }
            else if(i+1<s.size() && s[i]=='I' && s[i+1]=='X'){
                ans+=9;
                i++;
            }
            else if(x=='I'){
                ans+=1;
            }
            else if(x=='V'){
                ans+=5;
            }
            else if(x=='X'){
                ans+=10;
            }
            else if(x=='L'){
                ans+=50;
            }          
            else if(x=='C'){
                ans+=100;
            }
            else if(x=='D'){
                ans+=500;
            }
            else if(x=='M'){
                ans+=1000;
            }
            i++;
        }
        return ans;
    }
};