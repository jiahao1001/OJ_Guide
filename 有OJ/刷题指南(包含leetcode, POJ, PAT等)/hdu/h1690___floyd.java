//2711
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h1690___floyd {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static Scanner scan = new Scanner(System.in);
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m;
	static long inf = -1;

	// floyd
	static long adj[][];

	// dijkstra
	// static int dist[], visit[], head[];
	// static path[] edge;
	// static PriorityQueue<node> queue = new PriorityQueue<node>();

	public static void main(String[] args) throws IOException {
		long l1, l2, l3, l4, c1, c2, c3, c4;
		int a, b;
		int test = nextInt();
		for (int tt = 1; tt <= test; tt++) {
			l1 = nextInt();
			l2 = nextInt();
			l3 = nextInt();
			l4 = nextInt();
			c1 = nextInt();
			c2 = nextInt();
			c3 = nextInt();
			c4 = nextInt();
			n = nextInt();
			m = nextInt();
			init();
			long[] dis = new long[n + 1];
			for (int i = 1; i <= n; i++)
				dis[i] = nextInt();

			long temp;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					temp = Math.abs(dis[i] - dis[j]);
					if (temp <= l1)
						adj[i][j] = adj[j][i] = c1;
					else if (temp <= l2)
						adj[i][j] = adj[j][i] = c2;
					else if (temp <= l3)
						adj[i][j] = adj[j][i] = c3;
					else if (temp <= l4)
						adj[i][j] = adj[j][i] = c4;
					else
						adj[i][j] = adj[j][i] = inf;
				}
			}

			floyd();

			out.println("Case " + tt + ":");
			for (int i = 1; i <= m; i++) {
				a = nextInt();
				b = nextInt();
				if (adj[a][b] != inf)
					out.println("The minimum cost between station " + a
							+ " and station " + b + " is " + adj[a][b] + ".");
				else
					out.println("Station " + a + " and station " + b
							+ " are not attainable.");
			}
		}
		out.flush();
		out.close();
	}

	static void init() {
		adj = new long[n + 1][n + 1];
	}

	static void floyd() {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				if (adj[i][k] == inf)
					continue;
				for (int j = 1; j <= n; j++) {
					if (adj[k][j] == inf)
						continue;
					if (adj[i][j] == inf || adj[i][k] + adj[k][j] < adj[i][j])
						adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}

	//
	//
	//
	// dijkstra
	// static void init() {
	// head = new int[(n + 1) * (m + 1) + 1];
	// Arrays.fill(head, -1);
	// edge = new path[(m * n * 2 + m + n) * 2 + 2];
	// }
	//
	// static void dijkstra(int s) {
	// dist = new int[(n + 1) * (m + 1) + 1];
	// Arrays.fill(dist, inf);
	// dist[s] = 0;
	// visit = new int[(n + 1) * (m + 1) + 1];
	// visit[s] = 1;
	// queue.clear();
	// node tempN;
	// for (int i = head[1]; i != -1; i = edge[i].next) {
	// tempN = new node(edge[i].v, edge[i].val);
	// queue.add(tempN);
	// }
	// int v, val;
	// while (!queue.isEmpty()) {
	// tempN = queue.poll();
	// v = tempN.v;
	// val = tempN.val;
	// if (visit[v] == 1)
	// continue;
	// visit[v] = 1;
	// dist[v] = val;
	// for (int i = head[v]; i != -1; i = edge[i].next) {
	// if (visit[edge[i].v] == 0
	// && dist[v] + edge[i].val < dist[edge[i].v]) {
	// tempN = new node(edge[i].v, dist[v] + edge[i].val);
	// queue.add(tempN);
	// }
	// }
	// }
	// }

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

	static class node implements Comparable<node> {
		int v, val;

		node(int v, int val) {
			this.v = v;
			this.val = val;
		}

		public int compareTo(node o) {
			if (this.val < o.val)
				return -1;
			else if (this.val > o.val)
				return 1;
			return 0;
		}
	}

	static class path {
		int v, next, val;

		path(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

}