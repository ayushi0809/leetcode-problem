class Solution {
public:
    int romanToInt(string s) {
        int nums[7] = {1,5,10,50,100,500,1000};
char roman[7] = {'I','V','X','L','C','D','M'};
int res = 0,i=0;
while(i<s.size()){
for(int j = 0;j<7;j++){
if(s[i] == roman[j]){
if(j == 0 || j == 2 || j==4){
if(s[i+1] == roman[j+1]){
res = res + nums[j+1]-nums[j];
i+=2;
} else if(s[i+1] == roman[j+2]){
res = res + nums[j+2]-nums[j];
i+=2;
} else{
res = res + nums[j];
i+=1;
}
} else{
res = res + nums[j];
i+=1;
}
}
}
}
return res;
}
        
    
};