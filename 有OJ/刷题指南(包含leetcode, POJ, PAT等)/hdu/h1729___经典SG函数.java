import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h1729___¾­µäSGº¯Êý {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int s[], c[];
	static HashMap<node, Integer> set = new HashMap<node, Integer>();
	static int N = 1000000;

	static class node implements Comparable<node> {
		int s, c;

		node(int a, int b) {
			s = a;
			c = b;
		}

		public int compareTo(node o) {
			if (this.s == o.s && this.c == o.c)
				return 0;
			if (this.s == o.s)
				return this.c - o.c;
			return this.s - o.s;
		}
	}

	static node temp;

	static int mex(int s, int c) {
		int t = (int) Math.sqrt(1.0 * s);
		temp = new node(s, c);
		if (set.containsKey(temp))
			return set.get(temp);
		while (t + t * t >= s)
			t--;
		int ret;
		if (c > t)
			ret = s - c;
		else
			ret = mex(t, c);
		set.put(temp, ret);
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int test = 0;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			int ans = 0;
			for (int i = 1; i <= n; i++)
				ans ^= mex(nextInt(), nextInt());

			out.println("Case " + (++test) + ":");
			if (ans > 0)
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