//Main.java
import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[]) throws Exception {
		Scanner cin=new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 0; i < t; i++) {
			if (cin.hasNextBigInteger() == false)
				cin.skip("\\s\\D");
			BigInteger a = cin.nextBigInteger();
			if (cin.hasNextBigInteger() == false)
				cin.skip("\\s\\D");
			BigInteger b = cin.nextBigInteger();
			a = a.add(b);
			System.out.println(a);
		}
	}
}
