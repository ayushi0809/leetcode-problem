class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int>stk;
        string result;
        for (int i = 0; i <= pattern.size(); i++)
    {
        stk.push(i + 1);
        if (i == pattern.size() || pattern[i] == 'I')
        {
            while (!stk.empty())
            {
                result += to_string(stk.top());
                //result += " ";
                stk.pop();
            }
        }
    }
        return result;
    }
};