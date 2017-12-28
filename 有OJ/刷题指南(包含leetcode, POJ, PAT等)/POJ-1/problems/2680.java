//Main.java
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
        BigInteger[] num=new BigInteger[1001];
        BigInteger pow=new BigInteger("1");
        BigInteger base=new BigInteger("2");
        num[1]=new BigInteger("0");
        num[2]=new BigInteger("1");
        for (int i=3;i<=1000;i++)
        {
        	num[i]=num[i-2].add(pow);
        	pow=pow.multiply(base);
        }
        while (cin.hasNextInt()==true)
        {
        	int in=cin.nextInt();
        	System.out.println(num[in]);
        }
	}
}
