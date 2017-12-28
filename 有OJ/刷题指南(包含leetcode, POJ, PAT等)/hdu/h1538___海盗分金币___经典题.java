import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h1538___海盗分金币___经典题 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, p;
	static int fab[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 521, 1024, 2048,
			4096, 8192, 16384 };

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			m = nextInt();
			p = nextInt();

			if (n <= m * 2 + 1) {
				if (p == n)
					out.println(m - (n - 1) / 2);
				else {
					if (((p + n) & 1) == 0)
						out.println(1);
					else
						out.println(0);
				}
			} else {
				int choice = 0;
				int k = 0;
				for (; choice <= 14; choice++)
					if (fab[choice] + 2 * m <= n)
						k = 2 * m + fab[choice];
					else
						break;
				if (p <= 2 * m)
					out.println(0);
				else if (p > k)
					out.println("Thrown");
				else
					out.println(0);
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