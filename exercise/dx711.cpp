#include <iostream>
#include <cstdio>
#include <string.h>
#include <stack>
using namespace std;
char ss[1111111];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {

        stack<char> s;
        int n;
        scanf("%d", &n);
        getchar();
        scanf("%s",ss);
        for(int i = 0; i < n; i++) 
        {
            char mark;
            mark=ss[i];
            if(!s.empty()) {
                if(mark == ')' && s.top() == '(') s.pop();
                else s.push(mark);
            }
            else s.push(mark);
        }

        if(n==2)
        {
        	if(ss[0]==')'&&ss[1]=='(') puts("Yes");
        	else puts("No");
        }
        else if(n&1) 
        {
			puts("No");
        }
        else 
        {
            if(s.size()<=4) 
            {
            	if(s.empty()) puts("Yes");
            	else if(s.size()==1) puts("No");
            	else if(s.size()==2)
            	{
            		char a=s.top();
            		s.pop();
            		char b=s.top();
            		if(a==b) puts("No");
            		else puts("Yes");
            	}
            	else if(s.size()==4)
            	{
            		char x,y,xx,yy;
                            x = s.top();
                            s.pop();
                            y = s.top();
                            s.pop();
                            xx=s.top();
                            s.pop();
                            yy=s.top();
                            if(x=='('&&y=='('&&xx==')'&&yy==')')
                                printf("Yes\n");
                            else
                                printf("No\n");
            	}
            }
            else puts("No");
        }
    }

    return 0;
}