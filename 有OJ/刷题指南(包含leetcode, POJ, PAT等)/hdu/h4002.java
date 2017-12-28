import java.math.BigInteger;
import java.util.Scanner;

public class h4002 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int turn = scan.nextInt();
		// 求出1000以内的素数
		int[] prime = new int[1001];
		for (int i = 2; i <= 1000; i++)
			if (prime[i] == 0)
				for (int j = 2; j * i <= 1000; j++)
					prime[j * i] = 1;
		for (int tt = 0; tt < turn; tt++) {
			BigInteger limit = scan.nextBigInteger();
			BigInteger result = BigInteger.valueOf(1);
			int token = 2;
			while (token <= 1000) {
				if (prime[token] == 0) {
					if (result.multiply(BigInteger.valueOf(token)).compareTo(
							limit) == -1
							|| result.multiply(BigInteger.valueOf(token))
									.compareTo(limit) == 0) {
						result = result.multiply(BigInteger.valueOf(token));
					} else {
						token = 1001;
					}
				}
				token++;
			}
			System.out.println(result);
		}
	}
}
