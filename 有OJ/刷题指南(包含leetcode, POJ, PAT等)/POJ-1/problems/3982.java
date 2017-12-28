//Main.java
import java.util.*;
import java.math.*;

public class Main 
{
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		while (cin.hasNextBigInteger() == true)
		{
			BigInteger D = cin.nextBigInteger();
			BigInteger C = cin.nextBigInteger();
			BigInteger B = cin.nextBigInteger();
			BigInteger A = new BigInteger("0");
			for (int i=3; i<100; i++)
			{
				A = B.add(C).add(D);
        		D = C;
        		C = B;
        		B = A;
			}
			System.out.println(A);
		}
	}
}