// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* constructTree(char x[])
{
//code here
stack<et*>st;
for(int i=0; x[i] != '\0'; i++){
    //cout<<x[i]<<endl;
    if(x[i] != '+' && x[i] != '-' && x[i] != '*' && x[i] != '/' && x[i] != '^'){
        //cout<<x[i]<<endl;
        et* node = new et(x[i]);
        st.push(node);
    }
    else{
        et* r = st.top();
        st.pop();
        et* l = st.top();
        st.pop();
        et* root = new et(x[i]);
        root->right = r;
        root->left = l;
        st.push(root);
    }
    
}
return st.top();
}
