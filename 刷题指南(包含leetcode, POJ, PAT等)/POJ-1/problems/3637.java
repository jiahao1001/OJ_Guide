import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		int test = cin.nextInt();
		for (int t = 0; t < test; t++)
		{
			int num = cin.nextInt();
			int[] item = new int[num];
			for (int i = 0; i < num; i++)
			{
				item[i] = cin.nextInt();
			}
			Arrays.sort(item);
			int sum = 0;
			for (int i = num - 3; i >= 0; i-=3)
				sum+=item[i];
			System.out.println(sum);
		}
	}
}
