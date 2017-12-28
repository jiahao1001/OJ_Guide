import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4632___¡¥…œdp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int mod = 10007, num, n;
	static String str;

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		for (int test = 1; test <= ttt; test++) {
			str = " " + next();
			n = str.length() - 1;

			int dp[][] = new int[n + 1][n + 1];
			for (int i = 1; i <= n; i++)
				dp[i][i] = 1;

			for (int len = 1; len <= n; len++)
				for (int l = 1; l + len <= n; l++) {
					int r = l + len;
					dp[l][r] = (dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1])
							% mod;
					if (str.charAt(l) == str.charAt(r)) {
						dp[l][r]++;
						if (l + 1 <= r - 1)
							dp[l][r] = (dp[l][r] + dp[l + 1][r - 1]) % mod;
					}
				}

			out.println("Case " + test + ": " + (dp[1][n] + mod) % mod);
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