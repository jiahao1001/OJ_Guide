
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h4284___最短路___状态DP___有问题 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, money, h, INF = 100100, path[][], work[], c[], d[];

	public static void main(String[] args) throws IOException {
		int t = nextInt();
		int u, v, w;
		while (t-- > 0) {
			n = nextInt();
			m = nextInt();
			money = nextInt();
			// path = new int[n + 1][n + 1];
			// for (int i = 0; i <= n; i++) {
			// Arrays.fill(path[i], INF);
			// path[i][i] = 0;
			// }
			// for (int i = 1; i <= m; i++) {
			// u = nextInt();
			// v = nextInt();
			// w = nextInt();
			// path[u][v] = Math.min(path[u][v], w);
			// path[v][u] = path[u][v];
			// }
			// // Floyd
			// for (int k = 1; k <= n; k++)
			// for (int i = 1; i <= n; i++)
			// for (int j = 1; j <= n; j++)
			// if (i != k && i != j && j != k)
			// path[i][j] = Math.min(path[i][k] + path[k][j],
			// path[i][j]);

			path = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(path[i], INF);
				path[i][i] = 0;
			}
			for (int i = 0; i < m; i++) {
				u = nextInt() - 1;
				v = nextInt() - 1;
				w = nextInt();
				path[u][v] = Math.min(path[u][v], w);
				path[v][u] = path[u][v];
			}
			// Floyd
			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (i != k && i != j && j != k)
							path[i][j] = Math.min(path[i][k] + path[k][j],
									path[i][j]);

			int pos = -1;
			h = nextInt();

			work = new int[h + 1];
			c = new int[h + 1];
			d = new int[h + 1];
			for (int i = 0; i < h; i++) {
				work[i] = nextInt() - 1;
				c[i] = nextInt();
				d[i] = nextInt();
				if (work[i] == 0)
					pos = i;
			}
			if (pos == -1) {
				work[h] = c[h] = d[h] = 0;
				pos = h++;
			}

			int[][] dp = new int[h + 1][1 << h];
			for (int i = 0; i <= h; i++)
				Arrays.fill(dp[i], -1);

			if (money - d[pos] >= 0)
				dp[pos][1 << pos] = money - d[pos] + c[pos];
			dp[pos][0] = money;

			for (int i = 0; i < (1 << h); i++) {
				for (int j = 0; j < h; j++) {
					if (dp[j][i] == -1)
						continue;
					for (int k = 0; k < h; k++) {
						if (k == j || ((1 << k) & i) > 0)
							continue;
						// 钱够在两个城市之间移动，而且够买证
						if (dp[j][i] >= path[work[j]][work[k]] + d[k])
							dp[k][i | (1 << k)] = Math.max(dp[k][i | (1 << k)],
									dp[j][i] - path[work[j]][work[k]] - d[k]
											+ c[k]);
					}
				}
			}

			boolean ans = false;
			for (int i = 0; i < h; i++)
				// 最后判断能不能返回起点
				if (dp[i][(1 << h) - 1] >= path[work[i]][1]) {
					ans = true;
					break;
				}

			if (ans)
				out.println("YES");
			else
				out.println("NO");
		}

		out.flush();
		out.close();
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}
