import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4512___LCIS±‰–Œ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, a[], b[];
	static int N = 510, M = 510;
	static int dp[][] = new int[N][M];

	static int getLCIS(int n, int[] a, int m, int[] b) {
		int max, ret = 0;
		int path[][] = new int[n + 1][m + 1];
		for (int i = 1; i <= n; i++)
			Arrays.fill(path[i], 0);

		int t;

		for (int i = 1; i <= n; i++) {
			max = 0;
			for (int j = 1; j <= m; j++) {
				if (a[i] > b[j] && max < dp[i - 1][j])
					max = dp[i - 1][j];
				if (a[i] == b[j])
					dp[i][j] = max + 1;
				else
					dp[i][j] = dp[i - 1][j];

				if (i + j == n + 1)
					ret = Math.max(ret, dp[i][j] * 2 - 1);
				else if (i + j < n + 1)
					ret = Math.max(ret, dp[i][j] * 2);
			}
		}

		return ret;
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = m = nextInt();
			a = new int[n + 1];
			b = new int[n + 1];
			for (int i = 1; i <= n; i++)
				a[i] = b[n - i + 1] = nextInt();

			out.println(getLCIS(n, a, m, b));
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