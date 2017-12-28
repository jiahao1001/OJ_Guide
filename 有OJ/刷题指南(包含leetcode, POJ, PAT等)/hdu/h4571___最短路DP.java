import java.io.*;
import java.util.*;

public class h4571___×î¶ÌÂ·DP {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, T, st, ed;
	static int map[][];
	static int inf = 1 << 29;
	static node node[];

	static class node implements Comparable<node> {
		int s, c, id;

		node(int i) {
			id = i;
		}

		public int compareTo(node o) {
			return this.s - o.s;
		}
	}

	public static void main(String[] args) throws IOException {
		int test = nextInt(), u, v, val, temp;
		for (int ttt = 1; ttt <= test; ttt++) {
			n = nextInt();
			m = nextInt();
			T = nextInt();
			st = nextInt();
			ed = nextInt();

			node = new node[n];
			for (int i = 0; i < n; i++) {
				node[i] = new node(i);
				node[i].c = nextInt();
			}
			for (int i = 0; i < n; i++)
				node[i].s = nextInt();

			map = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(map[i], inf);
				map[i][i] = 0;
			}
			for (int i = 1; i <= m; i++) {
				u = nextInt();
				v = nextInt();
				val = nextInt();
				map[v][u] = map[u][v] = Math.min(map[u][v], val);
			}

			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++) {
					if (map[i][k] == inf)
						continue;
					for (int j = 0; j < n; j++) {
						if (map[k][j] == inf)
							continue;
						map[j][i] = map[i][j] = Math.min(map[i][j], map[i][k]
								+ map[k][j]);
					}
				}

			Arrays.sort(node);
			int dp[][] = new int[n][T + 1];
			for (int i = 0; i < n; i++) {
				Arrays.fill(dp[i], -1);
			}

			for (int i = 0; i < n; i++) {
				v = node[i].id;
				temp = map[st][v] + node[i].c;
				if (temp <= T)
					dp[v][temp] = node[i].s;
			}

			for (int i = 0; i < n; i++) {
				u = node[i].id;
				for (int t = 0; t <= T; t++) {
					for (int j = i + 1; j < n; j++) {
						v = node[j].id;
						if (node[i].s == node[j].s || dp[u][t] == -1)
							continue;
						temp = t + node[j].c + map[u][v];
						if (temp <= T)
							dp[v][temp] = Math.max(dp[v][temp], dp[u][t]
									+ node[j].s);
					}
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i++) {
				v = node[i].id;
				for (int t = 0; t <= T; t++) {
					if (t + map[v][ed] <= T)
						ans = Math.max(ans, dp[v][t]);
				}
			}

			out.println("Case #" + ttt + ":");
			out.println(ans);
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