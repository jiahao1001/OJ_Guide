//Main.java

import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		for (int i=0;i<n;i++)
		{
			String s=cin.next();
			char t=s.charAt(0),r;
			int sum=1;
			for (int j=1;j<s.length();j++)
			{
				r=s.charAt(j);
				if (r==t)
					sum++;
				else {
					System.out.print(sum);
					System.out.print(t);
					sum=1;
					t=r;
				}
			}
			System.out.print(sum);
			System.out.print(t);
			System.out.println();
		}
	}
}
