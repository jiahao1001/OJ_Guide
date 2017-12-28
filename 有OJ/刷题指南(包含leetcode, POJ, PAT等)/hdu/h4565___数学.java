import java.io.*;
import java.util.*;

public class h4565___สýัง {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int a, b, n, m, s1, s2;
	static long adj[][] = new long[2][2];
	static double eps = 0.000000001;

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			a = (int) in.nval;
			b = nextInt();
			n = nextInt();
			m = nextInt();
			s1 = a * 2 % m;
			s2 = (a * a * 2 % m + b * 2 % m) % m;
			s1 %= m;
			s2 %= m;
			if (n == 1) {
				out.println(s1 % m);
			} else if (n == 2) {
				out.println(s2 % m);
			} else {
				adj[0][0] = 0;
				adj[0][1] = b - a * a;
				adj[1][0] = 1;
				adj[1][1] = 2 * a;
				adj = Rapidmultiply(adj, n - 2, m);
				int ans = (int) ((s1 * adj[0][1] % m + s2 * adj[1][1] % m) % m);
				if (ans < 0)
					ans += m;
				out.println(ans);
			}
		}
		out.flush();
		out.close();
	}

	static long[][] multiply(long[][] a, long[][] b, int mod) {
		int len = a.length;
		long[][] c = new long[len][len];
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++) {
				for (int k = 0; k < len; k++)
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
				c[i][j] %= mod;
			}
		return c;
	}

	static long[][] Rapidmultiply(long[][] a, int k, int mod) {
		int len = a.length;
		long[][] c = new long[len][len];
		long[][] b = new long[len][len];
		if (k == 0) {
			for (int i = 0; i < len; i++)
				c[i][i] = 1;
			return c;
		}
		if (k % 2 == 1) {
			b = Rapidmultiply(a, k / 2, mod);
			c = multiply(b, b, mod);
			c = multiply(a, c, mod);
			return c;
		} else {
			c = Rapidmultiply(a, k / 2, mod);
			c = multiply(c, c, mod);
			return c;
		}
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