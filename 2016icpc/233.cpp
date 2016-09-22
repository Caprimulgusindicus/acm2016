    for (int i=0;i<=9;i++)
        dp[1][i][(i+1)%2]=1;

    for (int i=2;i<19;i++) 
        for (int j=0;j<=9;j++) 
            for (int k=0;k<=9;k++)
            { 
                if(j&1)
                {
                    dp[i][j][0]+=dp[i-1][k][1];
                    if(k&1) dp[i][j][1]+=dp[i-1][k][0];
                }
                else
                {
                    if(!(k&1))
                    {
                        dp[i][j][1]+=dp[i-1][k][0];
                        dp[i][j][0]+=dp[i-1][k][1];
                    }
                    else dp[i][j][1]+=dp[i-1][k][1];
                }
            }