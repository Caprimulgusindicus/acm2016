
import java.math.*;
import java.util.Scanner;

public class Main{
  public static void main(String args[]){
  Scanner cin=new Scanner(System.in);
  BigInteger N;
  int y=0;
  int flag=0;
  BigInteger cmp=new BigInteger("1");
  String s=cin.next();
  BigInteger remain=BigInteger.ZERO;
  BigInteger odd=BigInteger.ZERO;
  BigInteger ans=BigInteger.ZERO;
  for(int ii=1;ii<=5;ii++)
  {

              
               
                      remain=BigInteger.ZERO;
                      odd=BigInteger.ZERO;
                      ans=BigInteger.ZERO;
                      int group=0,k=0;
                      if(s.length()%2==1)
                      {
                              group=s.charAt(0)-'0';
                              k=-1;
                      }
                      else
                      {
                              group=(s.charAt(0)-'0')*10+s.charAt(1)-'0';
                              k=0;
                      }
                      for(int j=0;j<(s.length()+1)/2;j++)
                      {
                              if(j!=0)
                              group=(s.charAt(j*2+k)-'0')*10+s.charAt(j*2+k+1)-'0';
                              odd=BigInteger.valueOf(20).multiply(ans).add(BigInteger.ONE);
                              remain=BigInteger.valueOf(100).multiply(remain).add(BigInteger.valueOf(group));
                              int count=0;
                              while(remain.compareTo(odd)>=0)
                              {
                                     count++;
                                     remain=remain.subtract(odd);
                                     odd=odd.add(BigInteger.valueOf(2));
                              }
                              ans=ans.multiply(BigInteger.TEN).add(BigInteger.valueOf(count));
                      }
                      //System.out.println(ans);
                      //if(i!=t-1)   System.out.println();
              
      
    //BigDecimal lala=N.sqrt;
    if(ans==cmp) 
    {
      flag=1;break;
    }
  }
  if(flag==0)
    System.out.print("TAT");
  else System.out.println(y);
  }
}