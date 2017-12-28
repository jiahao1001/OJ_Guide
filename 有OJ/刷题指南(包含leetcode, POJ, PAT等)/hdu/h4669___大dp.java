import java.io.*;

import java.util.*;

public class h4669___´ódp {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	static int n, k, a[], ccoe[][];
	static long dp1[][] = new long[2][250], dp2[][] = new long[2][250];

	static void init() {
		for (int i = 0; i < 2; i++)
			Arrays.fill(dp1[i], 0);
		for (int i = 0; i < 2; i++)
			Arrays.fill(dp2[i], 0);
	}

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			k = nextInt();
			a = new int[2 * n + 1];
			ccoe = new int[n + 1][2];

			init();

			int sscoe = 0;
			for (int i = 1; i <= n; i++) {
				a[i] = a[i + n] = nextInt();
				int t = 1;
				while (t <= a[i]) {
					t *= 10;
					ccoe[i][0]++;
				}
				ccoe[i][1] = t;
				sscoe += ccoe[i][0];
			}

			int t, coe;
			long ans = 0;

			int pre = 1, cur = 0;
			for (int i = 1; i <= n; i++) {
				cur = 1 - cur;
				pre = 1 - pre;
				Arrays.fill(dp1[cur], 0);

				t = (a[i] % k + k) % k;
				coe = ccoe[i][1];
				dp1[cur][t]++;

				for (int v = 0; v < k; v++)
					dp1[cur][((v * coe % k + t) % k + k) % k] += dp1[pre][v];

				ans += dp1[cur][0];
			}

			for (int i = n + 1; i <= n * 2; i++) {
				cur = 1 - cur;
				pre = 1 - pre;
				Arrays.fill(dp1[cur], 0);

				t = (a[i] % k + k) % k;
				coe = ccoe[i - n][1];

				for (int v = 0; v < k; v++)
					dp1[cur][((v * coe % k + t) % k + k) % k] += dp1[pre][v];

				ans += dp1[cur][0];
			}

			// part 2
			int ch = a[1];
			for (int i = 2; i <= n; i++) {
				t = (a[i] % k + k) % k;
				coe = ccoe[i][1];
				ch = ((ch * coe % k + a[i]) % k + k) % k;
			}

			int fast = fastPow(10, sscoe, k);
			fast = (fast % k + k) % k;
			for (int i = 1; i <= n; i++) {
				cur = 1 - cur;
				pre = 1 - pre;
				Arrays.fill(dp2[cur], 0);

				t = (a[i] % k + k) % k;
				coe = ccoe[i][1];

				ch = ((ch * coe + t) % k + k) % k;

				dp2[cur][ch]++;

				for (int v = 0; v < k; v++)
					dp2[cur][((v * coe + t) % k + k) % k] += dp2[pre][v];

				ch = ((ch - t * fast % k + k) % k + k) % k;
				ans -= dp2[cur][0];
			}

			if (ans < 0)
				ans = 0;
			out.println(ans);
		}
		out.flush();
		out.close();
	}

	public static int fastPow(int a, int p, int mod) {
		if (p == 0)
			return 1;
		if (p % 2 == 1) {
			int temp = fastPow(a, p / 2, mod);
			return (temp * temp % mod * a % mod) % mod;
		} else {
			int temp = fastPow(a, p / 2, mod);
			return (temp * temp) % mod;
		}
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static char nextChar() throws IOException {
		in.nextToken();
		return in.sval.charAt(0);
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	static float nextFloat() throws IOException {
		in.nextToken();
		return (float) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}