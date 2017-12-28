//Main.java

import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		int l=cin.nextInt();
		int[] tree=new int[l];
		for (int i=0;i<n;i++)
		{
			int j=cin.nextInt();
			tree[j%l]++;
		}
		int min=0;
		int year=0,temp;
		for (int i=1;i<l;i++)
			min+=i*tree[i];
		for (int i=1;i<l;i++)
		{
			temp=min-l*tree[l-i]+n;
			if (temp<min)
			{
				min=temp;
				year=i;
			}
		}
		System.out.println(year);
	}
}
