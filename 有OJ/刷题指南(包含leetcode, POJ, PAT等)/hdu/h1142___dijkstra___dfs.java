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

public class h1142___dijkstra___dfs {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = Integer.MAX_VALUE, dp[], map[][];
	static int head[];
	static path edge[];

	static int dist[];

	public static void main(String[] args) throws IOException {
		int a, b, val;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			m = nextInt();

			map = new int[n + 1][n + 1];
			for (int i = 0; i <= n; i++)
				Arrays.fill(map[i], inf);
			for (int i = 1; i <= m; i++) {
				a = nextInt();
				b = nextInt();
				map[a][b] = map[b][a] = nextInt();
			}

			// head = new int[n + 1];
			// Arrays.fill(head, -1);
			// edge = new path[m * 2 + 1];
			//
			// for (int u = 1; u <= m; u++) {
			// a = nextInt();
			// b = nextInt();
			// val = nextInt();
			//
			// edge[u * 2 - 1] = new path(a, b, val);
			// edge[u * 2 - 1].next = head[a];
			// head[a] = u * 2 - 1;
			//
			// edge[u * 2] = new path(b, a, val);
			// edge[u * 2].next = head[b];
			// head[b] = u * 2;
			// }

			// visit = new int[n + 1];
			// dist = new int[n + 1];
			// dijkstra(2);

			dist = new int[n + 1];
			dij(2);
			// for (int i = 1; i <= n; i++)
			// out.print(dist[i] + " ");
			// out.println();

			dp = new int[n + 1];
			Arrays.fill(dp, -1);
			dfs(1);
			out.println(dp[1]);

		}
		out.flush();
		out.close();
	}

	// static int dfs(int v) {
	// if (dp[v] != -1)
	// return dp[v];
	// if (v == 2)
	// return 1;
	// int sum = 0;
	// for (int i = head[v]; i != -1; i = edge[i].next) {
	// if (dist[v] > dist[edge[i].v])
	// sum += dfs(edge[i].v);
	// }
	// dp[v] = sum;
	// return sum;
	// }
	//
	// static int visit[], dist[];
	// static PriorityQueue<path> list = new PriorityQueue<path>();
	//
	// static void dijkstra(int s) {
	// Arrays.fill(visit, 0);
	// visit[s] = 1;
	// Arrays.fill(dist, inf);
	// dist[s] = 0;
	// list.clear();
	//
	// for (int i = head[s]; i != -1; i = edge[i].next) {
	// dist[edge[i].v] = edge[i].val;
	// list.add(edge[i]);
	// }
	//
	// path temp;
	// int v;
	// while (!list.isEmpty()) {
	// temp = list.poll();
	// v = temp.v;
	// if (visit[v] == 1)
	// continue;
	// visit[v] = 1;
	// dist[v] = dist[temp.u] + temp.val;
	// for (int i = head[v]; i != -1; i = edge[i].next) {
	// if (visit[edge[i].v] == 0 && dist[v] < inf
	// && dist[edge[i].v] > dist[v] + edge[i].val) {
	// dist[edge[i].v] = dist[v] + edge[i].val;
	// list.add(edge[i]);
	// }
	// }
	// }
	// }

	static int dfs(int v) {
		if (dp[v] != -1)
			return dp[v];
		if (v == 2)
			return 1;
		int i, temp, sum = 0;
		for (i = 1; i <= n; i++) {
			if (map[v][i] != inf && dist[v] > dist[i]) {
				temp = dfs(i);
				sum += temp;
			}
		}
		dp[v] = sum;
		return sum;
	}

	static void dij(int v) { // dijsktra 算法 求到v点的最短路
		int i, j, u, min;
		int vis[] = new int[n + 1];
		for (i = 1; i <= n; i++)
			dist[i] = map[i][v];
		dist[v] = 0;
		Arrays.fill(vis, 0);
		vis[v] = 1;
		for (i = 1; i < n; i++) {
			min = inf;
			u = v;
			for (j = 1; j <= n; j++) {
				if (vis[j] == 0 && dist[j] < min) {
					min = dist[j];
					u = j;
				}
			}
			vis[u] = 1;
			for (j = 1; j <= n; j++) {
				if (vis[j] == 0 && map[u][j] < inf
						&& dist[j] > dist[u] + map[u][j])
					dist[j] = dist[u] + map[u][j];
			}
		}
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static class path implements Comparable<path> {
		int u, v, val, next;

		path(int a, int b, int val) {
			this.u = a;
			this.v = b;
			this.val = val;
		}

		public int compareTo(path o) {
			if (this.val < o.val)
				return -1;
			else if (this.val > o.val)
				return 1;
			else
				return 0;
		}
	}
}