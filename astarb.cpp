import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void Init()
    {
        dp[1]=new BigInteger("1");
        dp[2]=new BigInteger("2");
        for(int i=3;i<=201;i++)
        {
            dp[i]=dp[i-1].add(dp[i-2]);
        }
    }

    public static BigInteger[]dp=new BigInteger[222];
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        Init();
        while(cin.hasNext())
        {
            int n=cin.nextInt();
            if(n>=1&&n<=200)
            {
                System.out.print(dp[n]);
            }
            System.out.println();
        }


    }
}
