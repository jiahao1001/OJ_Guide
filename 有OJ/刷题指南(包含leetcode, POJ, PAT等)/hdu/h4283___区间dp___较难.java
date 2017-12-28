import java.io.*;
import java.util.*;

public class h4283___区间dp___较难 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, arr[], s[], dp[][];

	static int inf = (int) 1e9;

	public static void main(String[] args) throws IOException {
		int i, j, k, len, temp;

		int ttt = nextInt();
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			arr = new int[n + 1];
			for (i = 1; i <= n; i++)
				arr[i] = nextInt();
			s = new int[n + 1];
			for (i = 1; i <= n; i++)
				s[i] = s[i - 1] + arr[i];

			dp = new int[n + 10][n + 10];
			for (i = 1; i <= n; i++)
				for (j = i + 1; j <= n; j++)
					dp[i][j] = inf;

			// dp[i][j]表示的是i到j，不考虑前后，只有i到j的最小屌丝值
			for (len = 1; len <= n; len++)
				for (i = 1; i + len <= n; i++) {
					j = i + len;
					for (k = i; k <= j; k++) {
						temp = dp[i + 1][k] + arr[i] * (k - i) + (k - i + 1)
								* (s[j] - s[k]) + dp[k + 1][j];
						dp[i][j] = Math.min(dp[i][j], temp);
					}
				}

			out.println("Case #" + test + ": " + dp[1][n]);
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}