//Main.java

import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		int n;
		boolean[] prime=new boolean[1301882];
		for (int i=2;i<=1141;i++)
			for (int j=i+i;j<1301882;j+=i)
				prime[j]=true;
		while ((n=cin.nextInt())!=0)
		{
			int a=n,b=n;
			while (prime[a]==true)
				a--;
			while (prime[b]==true)
				b++;
			System.out.println(b-a);
		}
	}
}
