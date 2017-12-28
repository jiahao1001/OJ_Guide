import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class h4002测试BigInteger {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		// int t = Integer.parseInt(scan.nextLine());
		// BigInteger limit;
		// for (int tt = 0; tt < t; tt++) {
		// limit = scan.nextBigInteger();
		BigInteger[] arr = new BigInteger[10001];
		int[] arr2 = new int[1001];

		for (int i = 2; i < 1000; i++)
			if (arr2[i] == 0)
				for (int j = 2; j * i <= 1000; j++)
					arr2[i * j] = 1;

		// 输出1000以内的素数
		for (int i = 2; i < 1000; i++) {
			if (arr2[i] == 0)
				System.out.println(i);
		}

		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();

		int index = 0;
		for (int i = 2; i < 1001; i++) {
			if (arr2[i] == 0) {
				arr[index] = BigInteger.valueOf(i);
				index++;
			}
		}

		// 输出前100个素数
		BigInteger result = arr[0];
		for (int k = 1; k <= 100; k++) {
			System.out.println(arr[k]);
			result = result.multiply(arr[k]);
		}

		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println(result);
		// }
	}
}
