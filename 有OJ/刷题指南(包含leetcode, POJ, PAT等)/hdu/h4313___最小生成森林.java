import java.io.*;
import java.util.*;

public class h4313___最小生成森林 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int father[], rank[];
	static edge edge[];
	static boolean record[];

	static class edge implements Comparable<edge> {
		int u, v;
		int val;

		edge(int u, int v, int val) {
			this.u = u;
			this.v = v;
			this.val = val;
		}

		public int compareTo(edge o) {
			return o.val - this.val;
		}
	}

	static void init() {
		edge = new edge[n];
		record = new boolean[n + 1];
		father = new int[n + 1];
		rank = new int[n + 1];
		for (int i = 0; i < n; i++) {
			father[i] = i;
			rank[i] = 1;
		}
	}

	static int find(int x, boolean f) {
		if (f)
			record[x] = true;
		if (father[x] == x)
			return x;
		father[x] = find(father[x], f);
		return father[x];
	}

	static void union(int ra, int rb) {
		if (rank[ra] > rank[rb]) {
			father[rb] = ra;
		} else {
			if (rank[ra] == rank[rb])
				rank[rb]++;
			father[ra] = rb;
		}
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt(), u, v, val, fa, fb;
		while (test-- > 0) {
			n = nextInt();
			int q = nextInt();
			init();
			for (int i = 1; i < n; i++) {
				edge[i] = new edge(nextInt(), nextInt(), nextInt());
			}
			while (q-- > 0)
				record[nextInt()] = true;
			Arrays.sort(edge, 1, n);
			long sum = 0;
			for (int i = 1; i < n; i++) {
				u = edge[i].u;
				v = edge[i].v;
				val = edge[i].val;

				fa = find(u, record[u]);
				fb = find(v, record[v]);
				if (fa == fb)
					continue;
				if (record[fa] && record[fb])
					sum += val;
				else {
					union(fa, fb);
					if (record[fa] || record[fb])
						record[fa] = record[fb] = true;
				}
			}
			out.println(sum);
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}