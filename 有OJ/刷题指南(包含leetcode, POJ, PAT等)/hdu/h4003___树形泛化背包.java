import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h4003___Ê÷ÐÎ·º»¯±³°ü {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int N = 10100;
	static int head[] = new int[N], tot;
	static edge[] edge = new edge[N * 2];
	static int inf = 1 << 29;

	static class edge {
		int v, next, val;

		edge(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

	static void addEdge(int u, int v, int val) {
		edge[tot] = new edge(v, val);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static void dfs(int u, int f) {
		int v, val;
		dp[u][0] = 0;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			val = edge[e].val;
			if (v == f)
				continue;
			dfs(v, u);
			for (int i = k; i >= 0; i--) {
				dp[u][i] += dp[v][0] + val * 2;
				for (int j = 0; j <= i; j++)
					dp[u][i] = Math.min(dp[u][i], dp[u][i - j] + dp[v][j] + val
							* j);
			}
		}

	}

	static int n, s, k;
	static int dp[][] = new int[N][12];

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		for (int i = 0; i < N; i++)
			Arrays.fill(dp[i], 0);
	}

	public static void main(String[] args) throws IOException {
		int u, v, c;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			s = nextInt();
			k = nextInt();
			init();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				c = nextInt();
				addEdge(u, v, c);
				addEdge(v, u, c);
			}
			dfs(s, -1);
			out.println(dp[s][k]);
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