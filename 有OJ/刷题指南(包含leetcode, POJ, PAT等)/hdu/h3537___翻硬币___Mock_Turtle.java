import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h3537___·­Ó²±Ò___Mock_Turtle {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, arr[];
	static HashSet<Integer> set = new HashSet<Integer>();

	static int lowbit(int a) {
		return a & -a;
	}

	static int sg(int x) {
		int y = x * 2;
		int sum = 0;
		while (y > 0) {
			sum++;
			y -= lowbit(y);
		}
		if ((sum % 2) == 1)
			return x * 2;
		else
			return x * 2 + 1;
	}

	public static void main(String[] args) throws IOException {
		int x;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;

			int ans = 0;
			set.clear();
			for (int i = 1; i <= n; i++) {
				x = nextInt();
				if (set.contains(x))
					continue;
				else
					set.add(x);
				ans ^= sg(x);
			}

			if (ans == 0)
				out.println("Yes");
			else
				out.println("No");
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