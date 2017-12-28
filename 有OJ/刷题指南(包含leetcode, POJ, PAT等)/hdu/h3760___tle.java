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

public class h3760___tle {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = 200000000;
	static boolean visit[];
	static int head[], deep[], dis[];
	static h3760___node edge[];
	static PriorityQueue<h3760___node> queue = new PriorityQueue<h3760___node>();
	static PriorityQueue<h3760___node> minVert = new PriorityQueue<h3760___node>();

	public static void main(String[] args) throws IOException {
		// int t = nextInt();
		int u, v, c;
		// while (t-- > 0) {
		n = nextInt();
		m = nextInt();
		edge = new h3760___node[m * 2 + 1];
		head = new int[n + 1];
		dis = new int[n + 1];
		deep = new int[n + 1];
		visit = new boolean[n + 1];
		Arrays.fill(head, -1);
		for (int i = 1; i <= m; i++) {
			u = nextInt();
			v = nextInt();
			c = nextInt();
			edge[i * 2 - 1] = new h3760___node(u);
			edge[i * 2 - 1].v = v;
			edge[i * 2 - 1].cost = c;
			edge[i * 2 - 1].next = head[u];
			head[u] = i * 2 - 1;

			edge[i * 2] = new h3760___node(v);
			edge[i * 2].v = u;
			edge[i * 2].cost = c;
			edge[i * 2].next = head[v];
			head[v] = i * 2;
		}

		bfs();

		// for (int i = 1; i <= n; i++)
		// out.println(i + " :     " + deep[i] + " " + dis[i]);

		out.println(deep[n]);

		print();
		// }

		out.flush();
		out.close();
	}

	static void print() {
		out.print(dis[1] + " ");
		h3760___node temp;
		queue.clear();
		for (int i = head[1]; i != -1; i = edge[i].next) {
			if (deep[edge[i].v] != 1)
				continue;
			if (edge[i].cost == dis[1]) {
				queue.add(edge[i]);
			}
		}
		int min;
		minVert.clear();
		for (int ddd = 1; ddd < deep[n]; ddd++) {
			min = inf;
			while (!queue.isEmpty()) {
				temp = queue.poll();
				if (min > dis[temp.v]) {
					min = dis[temp.v];
					minVert.clear();
					minVert.add(temp);
				} else if (min == dis[temp.v]) {
					minVert.add(temp);
				}
			}

			out.print(min + " ");

			while (!minVert.isEmpty()) {
				temp = minVert.poll();
				for (int i = head[temp.v]; i != -1; i = edge[i].next) {
					if (deep[edge[i].v] != ddd + 1)
						continue;
					if (edge[i].cost == min) {
						queue.add(edge[i]);
					}
				}
			}

		}
		out.println();
		return;
	}

	static void bfs() {
		Arrays.fill(visit, false);
		Arrays.fill(dis, inf);
		Arrays.fill(deep, inf);
		queue.clear();
		for (int i = head[1]; i != -1; i = edge[i].next) {
			if (dis[1] > edge[i].cost) {
				dis[1] = edge[i].cost;
			}
			queue.add(edge[i]);
			deep[edge[i].v] = 1;
		}
		h3760___node temp;
		visit[1] = true;
		deep[1] = 0;
		while (!queue.isEmpty()) {
			temp = queue.poll();
			if (visit[temp.v])
				continue;
			visit[temp.v] = true;
			deep[temp.v] = temp.deep + 1;

			if (temp.v == n) {
				return;
			}

			for (int i = head[temp.v]; i != -1; i = edge[i].next) {
				edge[i].deep = deep[temp.v];
				if (deep[edge[i].v] == inf)
					deep[edge[i].v] = deep[temp.v] + 1;

				if (deep[edge[i].v] == deep[temp.v] + 1) {
					dis[temp.v] = Math.min(dis[temp.v], edge[i].cost);
				}
				queue.add(edge[i]);
			}
		}

	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
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

class h3760___node implements Comparable<h3760___node> {
	int v, next, cost, u, deep;

	h3760___node(int u) {
		this.u = u;
		this.deep = 0;
	}

	public int compareTo(h3760___node o) {
		if (this.deep < o.deep)
			return -1;
		else if (this.deep > o.deep)
			return 1;
		else if (this.cost < o.cost)
			return -1;
		else if (this.cost > o.cost)
			return 1;
		else
			return 0;
	}
}