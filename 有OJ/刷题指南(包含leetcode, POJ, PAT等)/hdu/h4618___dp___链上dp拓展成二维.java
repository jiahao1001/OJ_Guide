import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4618___dp___链上dp拓展成二维 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 310;
	static int n, m, a[][] = new int[N][N];
	static boolean dp[][][] = new boolean[N][N][N];

	static void init() {
		for (int i = 0; i < N; i++)
			Arrays.fill(a[i], -1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Arrays.fill(dp[i][j], false);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				dp[i][j][0] = dp[i][j][1] = true;

	}

	static boolean check(int I, int J, int k) {
		// {I,I+k-1},{J,J+k-1}的组合
		for (int i = I; i <= I + k - 1; i++)
			if (a[i][J] != a[i][J + k - 1])
				return false;
		for (int j = J; j <= J + k - 1; j++)
			if (a[I][j] != a[I + k - 1][j])
				return false;
		for (int i = 0; i <= k / 2 + 1; i++)
			if (a[I + i][J] != a[I + k - 1 - i][J])
				return false;
		for (int j = 0; j <= k / 2 + 1; j++)
			if (a[I][J + j] != a[I][J + k - 1 - j])
				return false;
		return true;
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			m = nextInt();
			init();
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					a[i][j] = nextInt();

			int max = 1;
			int min = Math.min(n, m);
			for (int k = 2; k <= n; k++)
				for (int i = 1; i <= n - k + 1; i++)
					for (int j = 1; j <= m - k + 1; j++)
						if (dp[i + 1][j + 1][k - 2] && check(i, j, k)) {
							dp[i][j][k] = true;
							max = Math.max(max, k);
						}

			out.println(max);
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