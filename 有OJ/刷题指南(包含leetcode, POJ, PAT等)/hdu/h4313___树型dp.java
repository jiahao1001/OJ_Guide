import java.io.*;
import java.util.*;

public class h4313___树型dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int head[], toll;
	static edge edge[];

	static class edge {
		int v, next;
		long val;

		edge(int v, long val) {
			this.v = v;
			this.val = val;
		}
	}

	static void addEdge(int u, int v, int val) {
		edge[toll] = new edge(v, val);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	static int n;
	static boolean record[];
	static long dp[][], inf = (long) 1e15;
	static boolean vis[];

	static void init() {
		head = new int[n + 1];
		Arrays.fill(head, -1);
		edge = new edge[2 * n];
		toll = 0;
		dp = new long[n + 1][2];
		for (int i = 0; i <= n; i++)
			dp[n][0] = inf;
		record = new boolean[n + 1];
		Arrays.fill(record, false);
		vis = new boolean[n + 1];
		Arrays.fill(vis, false);
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt(), u, v, val;
		while (test-- > 0) {
			n = nextInt();
			int q = nextInt();
			init();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				val = nextInt();
				addEdge(u, v, val);
				addEdge(v, u, val);
			}
			while (q-- > 0)
				record[nextInt()] = true;
			vis[0] = true;
			dfs(0);
			// 为什么输出的是dp[0][1]，而不是dp[0][0]呢？
			// 因为如果要保证舍去的边权最小，那么我们所需要的包含root0的那个森林里面应该至少有一个是k点，也就是dp[0][1]
			out.println(dp[0][1]);
		}
		out.flush();
		out.close();
	}

	static void dfs(int u) {
		int v;
		long val;
		if (record[u])
			dp[u][0] = inf;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			v = edge[i].v;
			val = edge[i].val;
			if (!vis[v]) {
				vis[v] = true;
				dfs(v);
				long cut = Math.min(dp[v][0], dp[v][1] + val);
				dp[u][1] = Math.min(dp[u][0] + dp[v][1], dp[u][1] + cut);
				if (!record[u])
					dp[u][0] += cut;
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