import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h1561___Ê÷ÉÏ·ºÐÍ±³°ü {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int N = 205;
	static int head[] = new int[N], tot;
	static edge[] edge = new edge[N * 2];
	static int inf = 1 << 29;

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

	static void dfs(int u, int f) {
		int v;
		dp[u][0] = 0;
		dp[u][1] = cost[u];

		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == f)
				continue;
			dfs(v, u);
			for (int i = m + 1; i > 0; i--)
				for (int j = 1; j < i; j++)
					dp[u][i] = Math.max(dp[u][i], dp[v][j] + dp[u][i - j]);
		}
	}

	static int n, m;
	static int dp[][] = new int[N][N];
	static int cost[] = new int[N];

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		for (int i = 0; i < N; i++)
			Arrays.fill(dp[i], 0);
	}

	public static void main(String[] args) throws IOException {
		int a, b;
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			init();
			for (int i = 1; i <= n; i++) {
				a = nextInt();
				b = nextInt();
				addEdge(a, i);
				addEdge(i, a);
				cost[i] = b;
			}

			dfs(0, -1);
			out.println(dp[0][m + 1]);
		}
		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

}