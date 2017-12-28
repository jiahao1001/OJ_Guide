import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class h3499___两边最短路___枚举中间边 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m;
	static long inf = 100000000000l;

	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		String str1, str2;
		int a, b, val, edge[][];

		while (scan.hasNext()) {
			n = scan.nextInt();
			m = scan.nextInt();
			map.clear();
			int index = 0;

			edge = new int[m + 1][3];

			SPFA s1 = new SPFA(n, m);
			SPFA s2 = new SPFA(n, m);
			for (int i = 1; i <= m; i++) {
				str1 = scan.next();
				str2 = scan.next();
				val = scan.nextInt();
				if (map.containsKey(str1))
					a = map.get(str1);
				else {
					map.put(str1, ++index);
					a = index;
				}
				if (map.containsKey(str2))
					b = map.get(str2);
				else {
					map.put(str2, ++index);
					b = index;
				}
				edge[i][0] = a;
				edge[i][1] = b;
				edge[i][2] = val;

				s1.addEdge(a, b, val);
				s2.addEdge(b, a, val);
			}

			str1 = scan.next();
			str2 = scan.next();
			if (map.containsKey(str1))
				a = map.get(str1);
			else {
				map.put(str1, ++index);
				a = index;
			}
			if (map.containsKey(str2))
				b = map.get(str2);
			else {
				map.put(str2, ++index);
				b = index;
			}

			s1.ShortestPath(a);
			s2.ShortestPath(b);

			long ans = inf;
			for (int i = 1; i <= m; i++) {
				a = edge[i][0];
				b = edge[i][1];
				val = edge[i][2];
				ans = Math.min(ans, s1.dist[a] + s2.dist[b] + val / 2);
			}
			if (ans == inf)
				ans = -1;
			out.println(ans);
		}

		out.flush();
		out.close();
	}

	static class SPFA {
		int n, m, head[], index;
		edge edge[];
		LinkedList<Integer> queue = new LinkedList<Integer>();
		int inQ[], path[];
		long dist[], inf = 100000000000l;

		SPFA(int nn, int mm) {
			this.n = nn;
			this.m = mm;
			head = new int[n + 1];
			Arrays.fill(head, -1);
			edge = new edge[m + 1];
			index = 0;
			dist = new long[n + 1];
			path = new int[n + 1];
			inQ = new int[n + 1];
		}

		void addEdge(int u, int v, int val) {
			edge[index] = new edge(v, val);
			edge[index].next = head[u];
			head[u] = index;
			index++;
		}

		void ShortestPath(int source) {
			queue.add(source);
			Arrays.fill(dist, inf);
			dist[source] = 0;
			inQ[source] = 1;
			Arrays.fill(path, -1);

			int u;
			while (!queue.isEmpty()) {
				u = queue.poll();
				inQ[u] = 0;
				for (int i = head[u]; i != -1; i = edge[i].next) {
					if (dist[edge[i].v] > dist[u] + edge[i].val) {
						dist[edge[i].v] = dist[u] + edge[i].val;
						path[edge[i].v] = u;
						if (inQ[edge[i].v] == 0) {
							inQ[edge[i].v] = 1;
							queue.add(edge[i].v);
						}
					}
				}
			}
		}
	}

	static class edge {
		int v, next;
		long val;

		edge(int v, int val) {
			this.v = v;
			this.val = val;
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
