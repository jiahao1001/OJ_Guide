import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4602___ÍÆ¹«Ê½ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, k;
	static long mod = 1000000007;

	public static long fastPow(int a, int p) {
		if (p == 0)
			return 1;
		if (p % 2 == 1) {
			long temp = fastPow(a, p / 2);
			return (temp * temp * a) % mod;
		} else {
			long temp = fastPow(a, p / 2);
			return (temp * temp) % mod;
		}
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			k = nextInt();

			if (n - k <= -1) {
				out.println(0);
				continue;
			} else if (n - k == 0) {
				out.println(1);
				continue;
			} else if (n - k == 1) {
				out.println(2);
				continue;
			}

			long ans = fastPow(2, n - k - 2);
			ans = (n - k + 3) * ans % mod;
			ans = (ans + mod) % mod;
			out.println(ans);
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