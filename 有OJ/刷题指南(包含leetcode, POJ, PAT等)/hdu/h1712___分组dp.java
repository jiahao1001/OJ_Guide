import java.io.*;
import java.util.*;

public class h1712___分组dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {

		int n, m, cost[][], dp[], V = 10000;
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			cost = new int[n + 1][m + 1];
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					cost[i][j] = nextInt();

			// 分组dp
			// dp[i][v]表示前i门功课学了v天的最大收益
			// dp[i][v]=Math.max(dp[i][v],dp[i-1][v-d])
			// d表示前i门功课学了v天的最大收益 很明显是前i天学了v天的收益，和前i天学了v-d天 和 第i天学了d天的收益取最大值
			// 这里的分组（也就是每一组内相互冲突）是没门功课学习的次数，所以每一门功课就是一组

			dp = new int[m + 1];
			for (int i = 1; i <= n; i++) {
				for (int v = m; v >= 0; v--) {
					for (int d = 1; d <= m; d++)
						if (v - d >= 0)
							dp[v] = Math.max(dp[v], dp[v - d] + cost[i][d]);
				}
			}

			out.println(dp[m]);
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