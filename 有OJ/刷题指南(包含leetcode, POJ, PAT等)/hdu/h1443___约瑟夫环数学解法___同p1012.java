import java.io.*;
import java.util.*;

public class h1443___约瑟夫环数学解法___同p1012 {
	static int n, k;

	static int record[] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313,
			459901, 1358657, 2504881, 13482720, 25779600, 68468401 };

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		loop: while (true) {
			k = scan.nextInt();
			if (k == 0)
				break;
			// n = k * 2;
			// for (int m = 1; m <= 100000000; m++) {
			// if (JoesphusCheck(n, m, 0)) {
			// record[k] = m;
			// System.out.println(m);
			// continue loop;
			// }
			// }
			// System.out.println("NO");
			System.out.println(record[k]);
		}
	}

	static boolean JoesphusCheck(int n, int m, int k) {
		for (int c = 1; c <= n / 2; c++) {
			k = (k + m - 1) % (n - c + 1);
			if (k < n / 2)
				return false;
		}
		return true;
	}
}
