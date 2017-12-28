//2711
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

public class h1548___dijkstra {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = 300000, dp[], map[][];
	static int dist[];

	public static void main(String[] args) throws IOException {
		int a, b, temp, step;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			a = nextInt();
			b = nextInt();

			map = new int[n + 1][n + 1];
			for (int i = 1; i <= n; i++)
				Arrays.fill(map[i], inf);

			for (int i = 1; i <= n; i++) {
				temp = nextInt();
				step = i - temp;
				if (step >= 1) {
					map[i][step] = 1;
				}
				step = i + temp;
				if (step <= n) {
					map[i][step] = 1;
				}
				// map[i][i] = 0;
			}

			dist = new int[n + 1];
			dijkstra(a, b);

			if (dist[b] == inf)
				out.println(-1);
			else
				out.println(dist[b]);

			// for (int i = 1; i <= n; i++)
			// out.print(dist[i] + " ");
			// out.println();
		}

		out.flush();
		out.close();
	}

	static void dijkstra(int s, int t) { // dijsktra 算法 求到v点的最短路
		int i, j, u, min;
		int vis[] = new int[n + 1];
		for (i = 1; i <= n; i++)
			dist[i] = map[s][i];
		dist[s] = 0;
		Arrays.fill(vis, 0);
		vis[s] = 1;
		for (i = 1; i < n; i++) {
			min = inf;
			u = s;
			for (j = 1; j <= n; j++) {
				if (vis[j] == 0 && dist[j] < min) {
					min = dist[j];
					u = j;
				}
			}
			vis[u] = 1;
			if (u == t)
				return;
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

}