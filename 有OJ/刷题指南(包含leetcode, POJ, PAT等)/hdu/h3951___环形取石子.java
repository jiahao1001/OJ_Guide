import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h3951___环形取石子 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, k;

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			k = nextInt();

			out.print("Case " + test + ": ");
			if (n <= k)
				out.println("first");
			else if (k > 1)
				out.println("second");
			else {
				if (n % 2 == 1)
					out.println("first");
				else
					out.println("second");
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