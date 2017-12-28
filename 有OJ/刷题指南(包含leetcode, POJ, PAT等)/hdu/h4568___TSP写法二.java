import java.io.*;
import java.util.*;

public class h4568___TSPÐ´·¨¶þ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, k;
	static int dp[][], map[][], floyd[][];
	static int inf = 1 << 29;
	static node node[];

	static class node {
		int x, y;

		node(int a, int b) {
			x = a;
			y = b;
		}
	}

	public static void main(String[] args) throws IOException {
		int a, b, test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			m = nextInt();
			map = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					map[i][j] = nextInt();

			k = nextInt();
			node = new node[k + 1];
			for (int i = 1; i <= k; i++) {
				a = nextInt();
				b = nextInt();
				node[i] = new node(a, b);
			}

			dist = new int[n][m];
			inQ = new boolean[n][m];
			floyd = new int[k + 1][k + 1];
			for (int i = 0; i <= k; i++)
				Arrays.fill(floyd[i], inf);
			for (int i = 1; i <= k; i++)
				spfa(node[i], i);

			int state = (1 << (k + 1));
			dp = new int[state][k + 1];
			for (int i = 0; i < state; i++)
				Arrays.fill(dp[i], inf);
			dp[1][0] = 0;
			for (int s = 0; s < state; s++) {
				for (int u = 0; u <= k; u++) {
					if (dp[s][u] == inf)
						continue;
					for (int v = 0; v <= k; v++) {
						dp[s | 1 << v][v] = Math.min(dp[s | 1 << v][v],
								dp[s][u] + floyd[u][v]);
					}
				}
			}

			out.println(dp[state - 1][0]);
		}
		out.flush();
		out.close();
	}

	static LinkedList<node> queue = new LinkedList<node>();
	static boolean inQ[][];
	static int dist[][];
	static int dir[][] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

	static void spfa(node source, int st) {
		for (int i = 0; i < n; i++) {
			Arrays.fill(inQ[i], false);
			Arrays.fill(dist[i], inf);
		}
		inQ[source.x][source.y] = true;
		dist[source.x][source.y] = 0;
		queue.clear();
		queue.add(source);
		node u;
		int x, y;
		while (!queue.isEmpty()) {
			u = queue.poll();
			inQ[u.x][u.y] = false;
			for (int choice = 0; choice < 4; choice++) {
				x = u.x + dir[choice][0];
				y = u.y + dir[choice][1];
				if (check(x, y) && dist[x][y] >= dist[u.x][u.y] + map[x][y]) {
					dist[x][y] = map[x][y] + dist[u.x][u.y];
					if (!inQ[x][y]) {
						inQ[x][y] = true;
						queue.add(new node(x, y));
					}
				}
			}
		}

		for (int i = 1; i <= k; i++)
			floyd[st][i] = Math.min(floyd[st][i], dist[node[i].x][node[i].y]);

		int min = inf;
		for (int i = 0; i < m; i++)
			min = Math.min(min, Math.min(dist[0][i], dist[n - 1][i]));
		for (int i = 0; i < n; i++)
			min = Math.min(min, Math.min(dist[i][0], dist[i][m - 1]));
		floyd[st][0] = min;
		floyd[0][st] = min + map[source.x][source.y];
	}

	static boolean check(int i, int j) {
		if (i < 0 || i >= n || j < 0 || j >= m)
			return false;
		if (map[i][j] == -1)
			return false;
		return true;
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