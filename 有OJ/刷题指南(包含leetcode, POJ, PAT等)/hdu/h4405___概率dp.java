import java.io.*;
import java.util.*;

public class h4405___¸ÅÂÊdp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m;
	static int path[];
	static double dp[];

	public static void main(String[] args) throws IOException {
		int u, v;
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;

			path = new int[n + 1];
			Arrays.fill(path, -1);
			dp = new double[n + 7];

			for (int i = 1; i <= m; i++) {
				u = nextInt();
				v = nextInt();
				path[u] = v;
			}

			for (int i = n - 1; i >= 0; i--) {
				if (path[i] > 0) {
					dp[i] = dp[path[i]];
				} else
					dp[i] = (dp[i + 1] + dp[i + 2] + dp[i + 3] + dp[i + 4]
							+ dp[i + 5] + dp[i + 6] + 6) / 6;
			}
			out.printf("%.4f", dp[0]);
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