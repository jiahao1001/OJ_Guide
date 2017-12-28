import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4616___树形dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 50050, M = 100100;
	static int tot, head[] = new int[N];
	static edge edge[] = new edge[M];

	static class edge {
		int v, next;

		edge(int v) {
			this.v = v;
		}
	}

	static void addEdge(int u, int v) {
		edge[tot] = new edge(v);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static int n, c;
	static long cost[] = new long[N];
	static boolean trap[] = new boolean[N];
	static long dp[][][] = new long[N][5][2], max;
	static int inf = 1 << 29;

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 4; j++)
				Arrays.fill(dp[i][j], -inf);
		max = 0;
	}

	public static void main(String[] args) throws IOException {
		int u, v, test = nextInt(), tmp;
		while (test-- > 0) {
			n = nextInt();
			c = nextInt();
			init();
			for (int i = 0; i < n; i++) {
				cost[i] = nextInt();
				tmp = nextInt();
				if (tmp == 0)
					trap[i] = false;
				else
					trap[i] = true;
			}
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				addEdge(u, v);
				addEdge(v, u);
			}

			for (int i = 0; i < n; i++) {
				if (trap[i])
					dp[i][1][0] = dp[i][1][1] = cost[i];
				else
					dp[i][0][0] = dp[i][0][1] = cost[i];
			}

			dfs(0, -1);

			out.println(max);
		}

		out.flush();
		out.close();
	}

	static void dfs(int u, int father) {
		int temp, v;
		if (trap[u])
			temp = 1;
		else
			temp = 0;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == father)
				continue;
			dfs(v, u);
			for (int i = 0; i <= c; i++)
				for (int j = 0; j + i <= c; j++) {
					// 如果等于c，那么在子树就会停下来了
					if (i < c)
						max = Math.max(max, dp[u][i][1] + dp[v][j][0]);
					if (j < c)
						max = Math.max(max, dp[u][i][0] + dp[v][j][1]);
					if (i + j < c)
						max = Math.max(max, dp[u][i][1] + dp[v][j][1]);
				}
			for (int i = temp; i <= c; i++) {
				if (i > temp)
					dp[u][i][0] = Math.max(dp[u][i][0], dp[v][i - temp][0]
							+ cost[u]);
				dp[u][i][1] = Math.max(dp[u][i][1], dp[v][i - temp][1]
						+ cost[u]);
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