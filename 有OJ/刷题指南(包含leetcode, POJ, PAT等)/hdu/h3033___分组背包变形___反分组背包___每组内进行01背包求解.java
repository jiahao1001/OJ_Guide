import java.io.*;
import java.util.*;

public class h3033___分组背包变形___反分组背包___每组内进行01背包求解 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int n, m, k;
		int brand[], cost[], weight[];
		int dp[][];
		int inf = 1 << 29;

		loop: while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			k = nextInt();
			brand = new int[n + 1];
			cost = new int[n + 1];
			weight = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				brand[i] = nextInt();
				cost[i] = nextInt();
				weight[i] = nextInt();
			}

			int V = m;
			dp = new int[k + 1][V + 1];
			for (int i = 1; i <= k; i++)
				Arrays.fill(dp[i], -inf);

			for (int b = 1; b <= k; b++)
				for (int i = 1; i <= n; i++) {
					if (brand[i] == b) {
						for (int v = V; v >= cost[i]; v--) {
							if (dp[b][v - cost[i]] >= 0)
								dp[b][v] = Math.max(dp[b][v],
										dp[b][v - cost[i]] + weight[i]);
							if (dp[b - 1][v - cost[i]] >= 0)
								dp[b][v] = Math.max(dp[b][v], dp[b - 1][v
										- cost[i]]
										+ weight[i]);
						}
					}
				}

			if (dp[k][m] < 0)
				out.println("Impossible");
			else
				out.println(dp[k][m]);
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