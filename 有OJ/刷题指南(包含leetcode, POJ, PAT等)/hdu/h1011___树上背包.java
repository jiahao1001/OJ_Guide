import java.io.*;
import java.util.*;

public class h1011___树上背包 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 120;
	static int head[] = new int[N], tot;
	static edge edge[] = new edge[N * 2];

	static class edge {
		int v, val, next;

		edge(int v) {
			this.v = v;
		}

		edge(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

	static void addEdge(int u, int v) {
		edge[tot] = new edge(v);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static void addEdge(int u, int v, int val) {
		edge[tot] = new edge(v, val);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		for (int i = 0; i < N; i++)
			Arrays.fill(dp[i], 0);
	}

	// 5 2
	// 0 1
	// 0 1
	// 0 5
	// 0 1
	// 0 2
	// 1 2
	// 1 3
	// 2 4
	// 2 5
	// -1 -1
	// 这组测试数据是最大的bug

	static void dfs(int u, int f) {
		for (int i = bug[u]; i <= m; i++)
			dp[u][i] = brain[u];
		int v;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == f)
				continue;
			dfs(v, u);
			for (int i = m; i >= 0; i--)
				for (int j = 1; j < i; j++)
					// 在u至少放下bug[u]个，这是和其他树上背包最大的不同点
					dp[u][i] = Math.max(dp[u][i], dp[u][i - j] + dp[v][j]);
		}
	}

	static int n, m;
	static int bug[] = new int[N], brain[] = new int[N];
	static int dp[][] = new int[N][N];
	static int inf = 1 << 29;

	public static void main(String[] args) throws IOException {
		int u, v;
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == -1 && m == -1)
				break;
			init();
			for (int i = 1; i <= n; i++) {
				bug[i] = nextInt();
				bug[i] = (bug[i] + 19) / 20;
				brain[i] = nextInt();
			}
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				addEdge(u, v);
				addEdge(v, u);
			}

			dfs(1, -1);
			if (m == 0)
				out.println(0);
			else
				out.println(dp[1][m]);

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