
import java.math.*;
import java.util.Scanner;

public class Main{
	public static void main(String args[]){
	Scanner s=new Scanner(System.in);
	BigInteger N;
	int y;
	int flag=0;
	N=s.nextBigInteger(10);
	for(int i=1;i<=5;i++)
	{
		y++;
		double lala=Math.sqrt(N);
		if(lala==1.0) 
		{
			flag=1;break;
		}
	}
	if(flag==0)
		System.out.print("TAT");
	else System.out.println(y);
	}
}