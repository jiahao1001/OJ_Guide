import java.io.*;
import java.util.*;

public class h4336___×´Ì¬Ñ¹Ëõ___¸ÅÂÊdp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, limit;
	static double chance[], dp[];

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			chance = new double[n + 1];
			double left = 1;
			for (int i = 0; i < n; i++) {
				chance[i] = nextDouble();
				left -= chance[i];
			}
			limit = (1 << (n)) - 1;
			dp = new double[limit + 1];

			double p, sum;
			for (int s = 1; s <= limit; s++) {
				p = left;
				sum = 0;
				for (int i = 0; i < n; i++) {
					if (((1 << i) & s) > 0) {
						sum += chance[i] * dp[s ^ (1 << i)];
					} else {
						p += chance[i];
					}
				}
				dp[s] += (sum + 1) / (1 - p);
			}

			out.printf("%.4f", dp[limit]);
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