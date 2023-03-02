class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>v;
        char a = chars[0];
        int count = 1;
        int ans =0;
        int i = 1;
        if(chars.size()==1){
            return 1;
        }
        while(i<=chars.size()){
           // cout<<i<<endl;
             count = 1;
            while( i<chars.size() && a == chars[i]){
                
               i++;
                count++;
                //cout<<i<<endl;
            }
            cout<<i<<endl;
            string s = to_string(count);
            if(count == 1){
                v.push_back(a);
                ans = ans+1;
            }
            else{
                v.push_back(a);
                int j =0;
                while(j<s.size()){
                    v.push_back(s[j]);
                    j++;
                }
                ans = ans+1+s.size();
            }
            //cout<<i<<endl;
            //i = i+count;
            
           if(i<chars.size()){
           a = chars[i];
           }
            i=i+1;
            //cout<<i<<endl;
           
        }
        // string s = to_string(count);
        // cout<<count<<endl;
        //     if(count == 1){
        //         v.push_back(a);
        //         ans = ans+1;
        //     }
        //     else{
        //         v.push_back(a);
        //         int j =0;
        //         while(j<s.size()){
        //             v.push_back(s[j]);
        //             j++;
        //         }
        //         ans = ans+1+s.size();
        //     }
        chars.clear();
        for(auto it : v){
            chars.push_back(it);
        }
        
        return ans;
        
    }
};