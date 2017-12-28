import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h1423___LCIS___注意输出_题目描述有误 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, a[], b[];
	static int N = 510, M = 510;
	static int dp[][] = new int[N][M];

	// 仅仅只是求出任意两点F[i][j]的前ai，bj并且以bj为结尾的LCIS
	static void LCIS(int n, int[] a, int m, int[] b) {
		int ret = 0;
		int max;
		for (int i = 1; i <= n; i++) {
			max = 0;
			for (int j = 1; j <= m; j++) {
				if (a[i] > b[j])
					max = Math.max(max, dp[i - 1][j]);
				if (a[i] == b[j])
					dp[i][j] = max + 1;
				else
					dp[i][j] = dp[i - 1][j];
				ret = Math.max(ret, dp[i][j]);
			}
		}
		out.println(ret);
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			a = new int[n + 1];
			for (int i = 1; i <= n; i++)
				a[i] = nextInt();
			m = nextInt();
			b = new int[m + 1];
			for (int i = 1; i <= m; i++)
				b[i] = nextInt();
			LCIS(n, a, m, b);
			if (test > 0)
				out.println();
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