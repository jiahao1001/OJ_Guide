import java.io.*;

import java.util.*;

public class h4651___分拆数___五边形数解决 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	// a[i]=(3*i*i-i)/2是五边形数，表示边长为i的正五边形需要几个
	//dp[n]=dp[n-a[1]]+dp[n+a[-1]]-dp[n-a[2]]-dp[n-a[-2]]+dp[n-a[3]]+dp[n-a[-3]]-dp[n-a[4]]..(a[+/-i]<=n)
	
	static int N = 100010, mod = 1000000007;
	static long dp[] = new long[N];

	static int a(int i) {
		return (3 * i * i - i) / 2;
	}

	static long work(int n) {
		if (dp[n] > -1)
			return dp[n];
		long ans = 0;
		int index = 1;
		while (a(index) <= n) {
			if ((index & 1) == 1) {
				ans = (ans + work(n - a(index))) % mod;
				if (a(-index) > n)
					break;
				ans = (ans + work(n - a(-index))) % mod;
			} else {
				ans = (ans - work(n - a(index))) % mod;
				if (a(-index) > n)
					break;
				ans = (ans - work(n - a(-index))) % mod;
			}
			index++;
			ans = (ans + mod) % mod;
		}
		ans = (ans + mod) % mod;
		dp[n] = ans;
		return dp[n];
	}

	public static void main(String[] args) throws IOException {
		int casenum = nextInt();
		Arrays.fill(dp, -1);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		while (casenum-- > 0) {
			int n = nextInt();
			out.println(work(n));
		}

		out.flush();
		out.close();
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
