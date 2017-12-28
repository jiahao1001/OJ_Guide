import java.io.*;
import java.util.*;

public class h3853___∏≈¬ dp»Î√≈ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m;
	static double dp[][], right[][], down[][], stay[][];
	static double eps = 1e-6;

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			dp = new double[n + 1][m + 1];
			right = new double[n + 1][m + 1];
			down = new double[n + 1][m + 1];
			stay = new double[n + 1][m + 1];

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					stay[i][j] = nextDouble();
					right[i][j] = nextDouble();
					down[i][j] = nextDouble();
				}

			for (int i = n - 1; i >= 0; i--)
				for (int j = m - 1; j >= 0; j--) {
					if (Math.abs(stay[i][j] - 1) < eps)
						continue;
					dp[i][j] = (right[i][j] * dp[i][j + 1] + down[i][j]
							* dp[i + 1][j] + 2)
							/ (1 - stay[i][j]);
				}

			double ans = 1.0 * (Math.round(dp[0][0] * 1000)) / 1000;
			out.printf("%.3f", ans);
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}