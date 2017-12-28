import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2516___Fibonacci_Nim {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;

	static long[][] multiply(long[][] a, long[][] b, long mod) {
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

	static long[][] Rapidmultiply(long[][] a, int k, long mod) {
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

	static int N = 46;
	static long fib[] = new long[N];

	public static void main(String[] args) throws IOException {
		fib[0] = fib[1] = 1;
		for (int i = 2; i < N; i++)
			fib[i] = fib[i - 1] + fib[i - 2];

		loop: while (true) {
			n = nextInt();
			if (n == 0)
				break;
			for (int i = 1; i < N; i++)
				if (fib[i] == n) {
					out.println("Second win");
					continue loop;
				}
			out.println("First win");
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