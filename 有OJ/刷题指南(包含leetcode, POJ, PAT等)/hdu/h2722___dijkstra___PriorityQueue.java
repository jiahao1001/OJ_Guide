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

public class h2722___dijkstra___PriorityQueue {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static Scanner scan = new Scanner(System.in);
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = 200000;

	// dijkstra
	static int dist[], visit[], head[];
	static path[] edge;
	static PriorityQueue<node> queue = new PriorityQueue<node>();

	public static void main(String[] args) throws IOException {
		int line, u, v, val, num;
		String direct;
		in.wordChars('*', '*');
		in.wordChars('<', '<');
		in.wordChars('>', '>');
		in.wordChars('^', '^');
		in.wordChars('v', 'v');
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;

			init();
			num = 0;
			for (int i = 1; i <= n * 2 + 1; i++) {
				line = (i + 1) / 2;
				if ((i & 1) == 1) {
					for (int j = 1; j <= m; j++) {
						val = nextInt();
						direct = next();
						u = (line - 1) * (m + 1) + j;
						v = u + 1;
						if (val != 0) {
							val = 2520 / val;
							if (direct.charAt(0) == '<') {
								edge[++num] = new path(u, val);
								edge[num].next = head[v];
								head[v] = num;
							} else if (direct.charAt(0) == '>') {
								edge[++num] = new path(v, val);
								edge[num].next = head[u];
								head[u] = num;
							} else {
								edge[++num] = new path(u, val);
								edge[num].next = head[v];
								head[v] = num;
								edge[++num] = new path(v, val);
								edge[num].next = head[u];
								head[u] = num;
							}
						}
					}
				} else {
					for (int j = 1; j <= m + 1; j++) {
						val = nextInt();
						direct = next();
						u = (line - 1) * (m + 1) + j;
						v = u + (m + 1);
						if (val != 0) {
							val = 2520 / val;
							if (direct.charAt(0) == '^') {
								edge[++num] = new path(u, val);
								edge[num].next = head[v];
								head[v] = num;
							} else if (direct.charAt(0) == 'v') {
								edge[++num] = new path(v, val);
								edge[num].next = head[u];
								head[u] = num;
							} else {
								edge[++num] = new path(u, val);
								edge[num].next = head[v];
								head[v] = num;
								edge[++num] = new path(v, val);
								edge[num].next = head[u];
								head[u] = num;
							}
						}
					}
				}
			}

			dijkstra(1);

			if (dist[(n + 1) * (m + 1)] == inf)
				out.println("Holiday");
			else
				out.println(dist[(n + 1) * (m + 1)] + " blips");

		}

		out.flush();
		out.close();
	}

	static void init() {
		head = new int[(n + 1) * (m + 1) + 1];
		Arrays.fill(head, -1);
		edge = new path[(m * n * 2 + m + n) * 2 + 2];
	}

	static void dijkstra(int s) {
		dist = new int[(n + 1) * (m + 1) + 1];
		Arrays.fill(dist, inf);
		dist[s] = 0;
		visit = new int[(n + 1) * (m + 1) + 1];
		visit[s] = 1;
		queue.clear();
		node tempN;
		for (int i = head[1]; i != -1; i = edge[i].next) {
			tempN = new node(edge[i].v, edge[i].val);
			queue.add(tempN);
		}
		int v, val;
		while (!queue.isEmpty()) {
			tempN = queue.poll();
			v = tempN.v;
			val = tempN.val;
			if (visit[v] == 1)
				continue;
			visit[v] = 1;
			dist[v] = val;
			for (int i = head[v]; i != -1; i = edge[i].next) {
				if (visit[edge[i].v] == 0
						&& dist[v] + edge[i].val < dist[edge[i].v]) {
					tempN = new node(edge[i].v, dist[v] + edge[i].val);
					queue.add(tempN);
				}
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