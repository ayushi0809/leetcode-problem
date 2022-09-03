class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
		stack<char> s;
		s.push(num[0]);
		for(int i=1;i<n;i++)
		{
			while(!s.empty() && k>0 && num[i]<s.top())
			{
				k--;
				s.pop();
			}
			if(!s.empty() || num[i]!='0')
				s.push(num[i]);
		}
		while(!s.empty() && k--)
		{
			s.pop();
		}
		if(s.empty())
			return "0";
		while(!s.empty())
		{
			num[n-1]=s.top();
			s.pop();
			n--;
		}
		return num.substr(n);

	}
};