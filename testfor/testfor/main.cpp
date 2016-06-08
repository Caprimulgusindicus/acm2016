//
//  main.cpp
//  testfor
//
//  Created by ChanVain on 16/6/5.
//  Copyright © 2016年 ChanVain. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n)
    {
        if(n<=0||n>=1000)
            if(n==0) cout<<0;
        else
        {
            int num=0;
            int sum=0;
            char cod[1000][1000];
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    if(cod[i-1][j]!='C'&&cod[i+1][j]!='C'&&)
        }
    }
    return 0;
}
