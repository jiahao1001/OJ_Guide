import java.util.Scanner;

public class h4611 {

	static void solve(int n, int a, int b) {
		if (a == b) {
			System.out.println("0");
			return;
		}
		int i = a;
		long ans = 0L;
		for (; i < n;) {
			long j = (long) Math.abs((i % a) - (i % b));
			int c = a - i % a;
			int d = b - i % b;
			if (c < d) {
				if (i + c < n) {
					ans += j * c;
					i += c;
				} else
					break;
			} else {
				if (i + d < n) {
					ans += j * d;
					i += d;
				} else
					break;
			}
		}
		for (; i < n; i++)
			ans += Math.abs((i % a) - (i % b));
		System.out.println(ans);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		while (T-- > 0) {
			int N = scan.nextInt();
			int A = scan.nextInt();
			int B = scan.nextInt();
			if (A < B)
				solve(N, A, B);
			else
				solve(N, B, A);
		}
	}
}