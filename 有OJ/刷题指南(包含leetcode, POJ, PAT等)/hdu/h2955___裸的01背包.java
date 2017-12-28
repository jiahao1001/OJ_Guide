import java.io.*;
import java.util.*;

public class h2955___ÂãµÄ01±³°ü {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, V;
	static float dp[];
	static int mm[];
	static float pp[];

	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		double limit;
		while (test-- > 0) {
			limit = scan.nextDouble();
			n = scan.nextInt();
			V = 0;
			mm = new int[n];
			pp = new float[n];
			for (int i = 0; i < n; i++) {
				mm[i] = scan.nextInt();
				pp[i] = scan.nextFloat();
				V += mm[i];
			}
			dp = new float[V + 1];
			Arrays.fill(dp, 0);
			dp[0] = 1;
			for (int i = 0; i < n; i++)
				ZeroPack(mm[i], 1 - pp[i]);

			for (int i = V; i >= 0; i--)
				if (dp[i] > 1 - limit) {
					out.println(i);
					break;
				}

		}
		out.flush();
		out.close();
	}

	static void ZeroPack(int cost, float weight) {
		for (int i = V; i >= cost; i--)
			dp[i] = Math.max(dp[i], dp[i - cost] * weight);
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