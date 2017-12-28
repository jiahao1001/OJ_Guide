import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h3389___½×ÌÝ²©ÞÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			int ans = 0, temp;
			for (int i = 1; i <= n; i++) {
				temp = nextInt();
				if (i % 6 == 0 || i % 6 == 2 || i % 6 == 5)
					ans ^= temp;
			}
			out.print("Case " + test + ": ");
			if (ans > 0)
				out.println("Alice");
			else
				out.println("Bob");

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