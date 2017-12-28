import java.io.*;
import java.util.*;

public class h3537___Mcok_Turtles___´ò±í {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int dp[];
	static boolean vis[];

	public static void main(String[] args) throws IOException {
		n = 100;
		dp = new int[2 * 2 * n + 1];
		vis = new boolean[2 * 2 * n + 1];
		dp[1] = 0;
		for (int i = 2; i <= n; i++) {
			Arrays.fill(vis, false);

			for (int j = 0; j < i; j++)
				for (int k = 0; k < i; k++)
					if (j != k) {
						int temp = dp[j] ^ dp[k];
						vis[temp] = true;
					}

			for (int j = 1; j <= 2 * 2 * n; j++)
				if (!vis[j]) {
					dp[i] = j;
					break;
				}
		}

		for (int i = 1; i <= n; i++) {
			out.println(i - 1 + "  " + dp[i]);
		}
		out.println();

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