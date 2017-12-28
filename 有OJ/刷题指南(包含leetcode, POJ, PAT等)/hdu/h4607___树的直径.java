import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4607___树的直径 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 100010, M = 200020;
	static int tot, head[] = new int[N];
	static edge edge[] = new edge[M];

	static class edge {
		int v, next;

		edge(int v) {
			this.v = v;
		}
	}

	static void addedge(int u, int v) {
		edge[tot] = new edge(v);
		edge[tot].next = head[u];
		head[u] = tot++;

		edge[tot] = new edge(u);
		edge[tot].next = head[v];
		head[v] = tot++;
	}

	static void init() {
		tot = 0;
		Arrays.fill(head, -1);
	}

	static void dfs(int u, int dep) {
		if (dep > longest) {
			longest = dep;
			vert = u;
		}
		int v;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (!vis[v]) {
				vis[v] = true;
				dfs(v, dep + 1);
			}
		}
	}

	static int n, q;
	static boolean vis[];
	static int longest, vert;

	public static void main(String[] args) throws IOException {
		int test = nextInt(), u, v, num;
		while (test-- > 0) {
			init();
			n = nextInt();
			q = nextInt();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				addedge(u, v);
			}

			// 求出直径
			vis = new boolean[n + 1];
			vis[1] = true;
			longest = 1;
			vert = 1;
			dfs(1, 1);

			Arrays.fill(vis, false);
			vis[vert] = true;
			dfs(vert, 1);

			while (q-- > 0) {
				num = nextInt();
				if (num <= longest)
					out.println(num - 1);
				else
					out.println(2 * num - longest - 1);
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