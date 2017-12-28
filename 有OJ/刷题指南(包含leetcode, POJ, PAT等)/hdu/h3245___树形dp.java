import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h3245___Ê÷ÐÎdp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 10010, M = 110;
	static int head[] = new int[N], tot;
	static edge edge[] = new edge[N * 2];
	static int size[] = new int[N], dist[] = new int[N],
			dp[][] = new int[N][M];
	static int inf = 1 << 29;
	static int ans[] = new int[N];

	static class edge {
		int v, next;

		edge(int a) {
			v = a;
		}
	}

	static void addEdge(int u, int v) {
		edge[tot] = new edge(v);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static void dfs1(int u, int f) {
		size[u] = 1;
		dist[u] = 0;
		int v;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == f)
				continue;
			dfs1(v, u);
			size[u] += size[v];
			dist[u] += size[v] + dist[v];
		}

		Arrays.fill(dp[u], inf);
		dp[u][0] = dist[u];
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == f)
				continue;
			for (int i = 1; i <= L; i++) {
				dp[u][i] = Math.min(dp[u][i], dp[v][i - 1] + dist[u]
						- (dist[v] + size[v]));
				dp[u][i] = Math.min(dp[u][i], dp[u][i - 1]);
			}
		}
	}

	static void dfs2(int u, int f) {
		int v;
		if (f != -1)
			dist[u] = dist[f] + n - size[u] - size[u];
		ans[u] = dist[u];

		int temp[] = new int[M], min = inf;
		Arrays.fill(temp, inf);

		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == f)
				continue;
			if (L > 1)
				for (int a = 0; a <= L - 2; a++) {
					int b = L - 2 - a;
					min = Math.min(min, temp[b] + dp[v][a] - dist[v] - size[v]);
				}
			for (int a = 0; a <= L; a++) {
				temp[a] = Math.min(temp[a], dp[v][a] - dist[v] - size[v]);
				if (a > 0)
					temp[a] = Math.min(temp[a], temp[a - 1]);
			}
		}
		min = Math.min(min, temp[L - 1]);
		ans[u] += min;

		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == f)
				continue;
			dfs2(v, u);
		}
	}

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		Arrays.fill(size, 0);
		Arrays.fill(dist, 0);
		for (int i = 0; i < N; i++)
			Arrays.fill(dp[i], 0);
		Arrays.fill(ans, inf);
	}

	static int n, L, sum, min, vert;

	public static void main(String[] args) throws IOException {
		int u, v;
		while (true) {
			n = nextInt();
			L = nextInt();
			if (n == 0 && L == 0)
				break;
			if (n == 1) {
				out.println(0);
				continue;
			}
			init();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				addEdge(u, v);
				addEdge(v, u);
			}

			dfs1(0, -1);
			dfs2(0, -1);

			int min = ans[0];
			for (int i = 1; i < n; i++)
				min = Math.min(min, ans[i]);
			out.println(min);
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