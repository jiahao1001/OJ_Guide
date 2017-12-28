import java.io.*;
import java.util.*;

public class h3535___分组背包___反分组背包___01背包 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 110, M = 110;
	static int n, T, m, s;
	static int c[] = new int[N], g[] = new int[N], dp[][] = new int[N][M];

	public static void main(String[] args) throws IOException {
		int temp;

		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			T = nextInt();

			for (int i = 0; i < N; i++)
				Arrays.fill(dp[i], -1);

			Arrays.fill(dp[0], 0);
			boolean flag = true;

			for (int turn = 1; turn <= n; turn++) {
				m = nextInt();
				s = nextInt();
				for (int i = 1; i <= m; i++) {
					c[i] = nextInt();
					g[i] = nextInt();
				}

				if (s == 0) {
					// 反分组背包
					for (int i = 1; i <= m; i++)
						for (int v = T; v >= c[i]; v--) {
							temp = dp[turn][v - c[i]];
							if (temp != -1)
								dp[turn][v] = Math
										.max(dp[turn][v], temp + g[i]);
							temp = dp[turn - 1][v - c[i]];
							if (temp != -1)
								dp[turn][v] = Math
										.max(dp[turn][v], temp + g[i]);
						}
				} else if (s == 1) {
					// 分组背包
					for (int i = 0; i <= T; i++)
						dp[turn][i] = dp[turn - 1][i];
					for (int v = T; v >= 0; v--)
						for (int i = 1; i <= m; i++)
							if (v >= c[i]) {
								temp = dp[turn - 1][v - c[i]];
								if (temp != -1)
									dp[turn][v] = Math.max(dp[turn][v], temp
											+ g[i]);
							}
				} else {
					// 01背包
					for (int i = 0; i <= T; i++)
						dp[turn][i] = dp[turn - 1][i];
					for (int i = 1; i <= m; i++)
						for (int v = T; v >= c[i]; v--) {
							temp = dp[turn][v - c[i]];
							if (temp != -1)
								dp[turn][v] = Math
										.max(dp[turn][v], temp + g[i]);
							temp = dp[turn - 1][v - c[i]];
							if (temp != -1)
								dp[turn][v] = Math
										.max(dp[turn][v], temp + g[i]);
						}
				}

				if (dp[turn][T] == -1)
					flag = false;
			}

			if (!flag)
				out.println(-1);
			else
				out.println(dp[n][T]);

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