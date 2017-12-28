import java.io.*;
import java.util.*;

public class h4003___Ê÷ÐÎdp___±³°ü {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, k;
	static int head[], toll;
	static edge edge[];
	static long dp[][];

	static class edge {
		int v, next;
		long val;

		edge(int v, long val) {
			this.v = v;
			this.val = val;
		}
	}

	static void init() {
		toll = 0;
		head = new int[n + 1];
		Arrays.fill(head, -1);
		edge = new edge[n * 2];
		dp = new long[n + 1][k + 1];
	}

	static void addEdge(int u, int v, int val) {
		edge[toll] = new edge(v, val);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	public static void main(String[] args) throws IOException {
		int root, u, v, val;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			root = nextInt();
			k = nextInt();
			init();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				val = nextInt();
				addEdge(u, v, val);
				addEdge(v, u, val);
			}
			dfs(root, -1);
			out.println(dp[root][k]);
		}
		out.flush();
		out.close();
	}

	static void dfs(int u, int father) {
		int v;
		long val;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v != father)
				dfs(v, u);
		}
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			val = edge[e].val;
			if (v != father) {
				for (int i = k; i >= 0; i--) {
					dp[u][i] += dp[v][0] + val * 2;
					for (int j = 1; j <= i; j++)
						dp[u][i] = Math.min(dp[u][i], dp[v][j] + dp[u][i - j]
								+ val * j);
				}
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}