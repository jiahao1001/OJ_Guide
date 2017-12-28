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

public class h2680___dijkstra___PriorityQueue {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = Integer.MAX_VALUE;
	static int dist[], visit[], head[];
	static path edge[];
	static PriorityQueue<node> queue = new PriorityQueue<node>();

	public static void main(String[] args) throws IOException {
		int s, line, a, b, val;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			s = nextInt();
			head = new int[n + 1];
			Arrays.fill(head, -1);
			edge = new path[m + n + 1];

			for (int i = 1; i <= m; i++) {
				a = nextInt();
				b = nextInt();
				val = nextInt();
				edge[i] = new path(b, val);
				edge[i].next = head[a];
				head[a] = i;
			}

			line = nextInt();
			for (int i = 1; i <= line; i++) {
				int v = nextInt();
				edge[m + i] = new path(v, 0);
				edge[m + i].next = head[0];
				head[0] = m + i;
			}

			dijkstra(0);

			if (dist[s] == inf)
				out.println(-1);
			else
				out.println(dist[s]);
		}

		out.flush();
		out.close();
	}

	static void dijkstra(int s) {
		queue.clear();
		visit = new int[n + 1];
		dist = new int[n + 1];
		visit[s] = 1;
		Arrays.fill(dist, inf);
		dist[s] = 0;

		int v, val;
		node tempNode;
		path temp;

		for (int i = head[s]; i != -1; i = edge[i].next) {
			temp = edge[i];
			tempNode = new node(temp.v, temp.val);
			queue.add(tempNode);
		}

		while (!queue.isEmpty()) {
			tempNode = queue.poll();
			v = tempNode.v;
			val = tempNode.val;
			if (visit[v] == 1)
				continue;
			visit[v] = 1;
			dist[v] = val;

			for (int i = head[v]; i != -1; i = edge[i].next) {
				if (visit[edge[i].v] == 0
						&& dist[v] + edge[i].val < dist[edge[i].v]) {
					tempNode = new node(edge[i].v, dist[v] + edge[i].val);
					queue.add(tempNode);
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

	static class path {
		int v, next, val;

		path(int v, int val) {
			this.v = v;
			this.val = val;
		}
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
}