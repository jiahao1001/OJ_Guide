import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4628___×´ˆRËÑË÷ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static String str;
	static int n;
	static int state[], tot, limit;
	static int count;
	static int record[];

	static void init() {
		n = str.length();
		count = n;
		tot = 0;
		state = new int[1 << 17];
		limit = 1 << n;
		record = new int[n + 2];
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			str = next();
			init();
			prework();
			dfs(0, n - 1, 0);
			out.println(count);
		}
		out.flush();
		out.close();
	}

	static void prework() {
		for (int i = 0; i < n; i++) {
			record[i] = tot;
			for (int j = 0; j < (1 << i); j++) {
				int t = (1 << i) | j;
				if (ok(t)) {
					// out.println("ok  :  " + Integer.toBinaryString(t));
					state[tot++] = t;
				}
			}
		}
		record[n] = tot;
		// for (int i = 0; i < n; i++)
		// System.out.println(i + " :   " + record[i]);
		// System.out.println(tot);
	}

	static boolean ok(int a) {
		String s = "";
		for (int i = 0; i < n; i++)
			if (((1 << i) & (a)) > 0)
				s += str.charAt(n - 1 - i);
		int l = s.length();
		for (int i = 0; i < l; i++)
			if (s.charAt(i) != s.charAt(l - 1 - i))
				return false;
		// out.println(s + "     " + Integer.toBinaryString(a));
		return true;
	}

	static void dfs(int cur, int dep, int num) {
		if (num >= count)
			return;
		if (dep == -1) {
			if (cur == limit - 1)
				count = Math.min(num, count);
			return;
		} else if (((1 << dep) & cur) > 0) {
			dfs(cur, dep - 1, num);
			return;
		} else {
			for (int j = record[dep]; j < record[dep + 1]; j++) {
				int s = state[j];
				if ((s & cur) > 0)
					continue;
				dfs(s | cur, dep - 1, num + 1);
			}

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

	static float nextFloat() throws IOException {
		in.nextToken();
		return (float) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}