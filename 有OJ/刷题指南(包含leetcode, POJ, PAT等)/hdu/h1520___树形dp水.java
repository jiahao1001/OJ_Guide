import java.io.*;
import java.util.*;

public class h1520___Ê÷ÐÎdpË® {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, arr[], dp[][];
	static int head[], toll;
	static edge edge[];

	static class edge {
		int v, next;

		edge(int v) {
			this.v = v;
		}
	}

	static void addEdge(int u, int v) {
		edge[toll] = new edge(v);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	public static void main(String[] args) throws IOException {
		int u, v;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;

			arr = new int[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();

			head = new int[n + 1];
			Arrays.fill(head, -1);
			toll = 0;
			edge = new edge[100 + n];
			int degree[] = new int[n + 1];
			while (true) {
				v = nextInt();
				u = nextInt();
				if (u == 0 && v == 0)
					break;
				addEdge(u, v);
				degree[v] = 1;
			}

			int ans = 0;
			dp = new int[n + 1][2];
			for (int i = 1; i <= n; i++)
				if (degree[i] == 0) {
					dfs(i);
					ans += Math.max(dp[i][0], dp[i][1]);
					break;
				}

			out.println(ans);
		}

		out.flush();
		out.close();
	}

	static void dfs(int u) {
		int v;
		dp[u][1] = arr[u];
		for (int i = head[u]; i != -1; i = edge[i].next) {
			v = edge[i].v;
			dfs(v);
			dp[u][0] += Math.max(dp[v][0], dp[v][1]);
			if (dp[v][0] > 0)
				dp[u][1] += dp[v][0];
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