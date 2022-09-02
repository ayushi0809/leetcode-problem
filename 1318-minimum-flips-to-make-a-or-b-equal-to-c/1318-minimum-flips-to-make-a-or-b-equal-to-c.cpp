class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count =0;
        for (int i = 31; i >= 0; i--) {
        int k = a >> i;
        int q = b >> i;
        int r = c>> i;
        if(r&1){
            int s = k&1;
            cout<<s;
            if(!(k&1) && !(q&1)){
                count++;
            }
             cout<<count<<endl;
        }
           
        else{
            if((k&1) && (q&1)){
                count = count+2;
            }
            else if(((k&1) && !(q&1)) || (!(k&1) && (q&1))){
                count++;
            }
        }
        }
        
      return count;  
    }
};