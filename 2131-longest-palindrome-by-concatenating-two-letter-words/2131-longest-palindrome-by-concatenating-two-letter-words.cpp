class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        int middlecount =0;
        int count=0;
        for(auto s : words){
            m[s]++;
        }
        
        for(auto s : words){
            string rev = "";
                rev = rev+s[1]+s[0];
            if( rev == s && m[rev] != -1){
                if(m[rev]>1){
                    if(m[rev]%2==0){
                        count=count+m[rev];
                    }
                    else{
                        count=count+m[rev]-1;
                        middlecount++;
                    }
                    m[rev] = -1;
                }
                else{
                middlecount++;
                }
            }
            else if(m.find(rev) != m.end() && m[rev] != -1){
                m[rev]--;
                count++;
                if(m[rev] == 0){
                    m.erase(rev);
                }
            }
        }
        
       
        int ans = 0;
        if(middlecount>=1){
            ans = count*2+2;
        }
        else{
            ans = count*2;
        }
        
        return ans;
        
        
    }
};