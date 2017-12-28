import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4630___Êý×Ödp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int getGCD(int a, int b) {
		while (a != b) {
			if (a > b)
				a -= b;
			else if (b > a)
				b -= a;
		}
		return a;
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			int n = nextInt();
			int arr[] = new int[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();
			int dp[][] = new int[n + 1][n + 1];

			for (int i = n; i >= 1; i--) {
				for (int j = i + 1; j <= n; j++) {
					dp[i][j] = Math.max(Math.max(dp[i + 1][j], dp[i][j - 1]),
							getGCD(arr[i], arr[j]));
				}
			}

			int q = nextInt();
			int l, r;
			while (q-- > 0) {
				l = nextInt();
				r = nextInt();
				out.println(dp[l][r]);
			}
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