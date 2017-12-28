import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h1730___Nim±‰“Ï {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m;
	static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			int ans = 0;
			for (int i = 1; i <= n; i++)
				ans ^= Math.abs(nextInt() - nextInt()) - 1;

			if (ans > 0)
				out.println("I WIN!");
			else
				out.println("BAD LUCK!");

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