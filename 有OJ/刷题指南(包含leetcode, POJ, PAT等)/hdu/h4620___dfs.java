import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4620___dfs {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 40;
	static cutter[] cut = new cutter[N];

	static class cutter implements Comparable<cutter> {
		int c, t, idx;
		int num[] = new int[12];

		cutter(int a) {
			idx = a;
		}

		public int compareTo(cutter o) {
			if (t < o.t)
				return -1;
			else
				return 1;
		}
	}

	static int n, m, w, max;
	static int ans[] = new int[N], current[] = new int[N];
	static boolean vis[] = new boolean[220];

	static void init() {
		for (int i = 0; i < N; i++)
			cut[i] = new cutter(i);
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		init();
		while (test-- > 0) {

			n = nextInt();
			m = nextInt();
			w = nextInt();

			for (int i = 1; i <= n; i++) {
				cut[i].c = nextInt();
				cut[i].t = nextInt();
				cut[i].idx = i;
				for (int j = 1; j <= cut[i].c; j++)
					cut[i].num[j] = nextInt();
			}

			Arrays.sort(cut, 1, n + 1);

			max = 0;
			Arrays.fill(vis, false);

			dfs(1, -1, 0);

			out.println(max);
			Arrays.sort(ans, 0, max);
			for (int i = 0; i < max; i++) {
				out.print(ans[i]);
				if (i < max - 1)
					out.print(" ");
				else
					out.println();
			}
		}
		out.flush();
		out.close();
	}

	static void dfs(int pos, int lastTime, int count) {
		if (count > max) {
			max = count;
			for (int i = 0; i < count; i++)
				ans[i] = current[i];
		}

		if (pos == n + 1 || n - pos + count < max)
			return;
		if (lastTime >= 0 && cut[pos].t - lastTime > w)
			return;
		dfs(pos + 1, lastTime, count);

		int tCnt = 0, trr[] = new int[12], v;
		for (int i = 1; i <= cut[pos].c; i++) {
			v = cut[pos].num[i];
			if (!vis[v])
				trr[tCnt++] = v;
		}
		if (tCnt < 3)
			return;
		for (int i = 0; i < tCnt; i++)
			vis[trr[i]] = true;
		current[count] = cut[pos].idx;
		dfs(pos + 1, cut[pos].t, count + 1);
		for (int i = 0; i < tCnt; i++)
			vis[trr[i]] = false;
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