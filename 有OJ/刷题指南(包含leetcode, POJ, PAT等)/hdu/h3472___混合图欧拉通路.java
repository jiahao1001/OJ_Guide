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

public class h3472___混合图欧拉通路 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, root;
	static double eps = 0.0000001;
	static int indegree[] = new int[26], outdegree[] = new int[26];
	static Dinic dinic;

	public static void main(String[] args) throws IOException {
		int tttt = nextInt();
		String str;
		int mark, u, v;
		dinic = new Dinic(30, 1000 * 3 + 52);
		for (int test = 1; test <= tttt; test++) {
			n = nextInt();
			Arrays.fill(indegree, 0);
			Arrays.fill(outdegree, 0);
			dinic.init();

			for (int i = 0; i < 26; i++)
				father[i] = i;
			for (int i = 1; i <= n; i++) {
				str = next();
				mark = nextInt();
				u = str.charAt(0) - 'a';
				v = str.charAt(str.length() - 1) - 'a';
				union(u, v);
				if (mark == 1) {
					dinic.addEdge(u, v, 1);
				}
				// dinic.addEdge(v, u, 1);
				// } else
				// dinic.addEdge(u, v, 1);
				outdegree[u]++;
				indegree[v]++;
			}
			if (solve())
				out.println("Case " + test + ": Well done!");
			else
				out.println("Case " + test + ": Poor boy!");
		}
		out.flush();
		out.close();
	}

	static int father[] = new int[26];

	static int find(int x) {
		if (x != father[x])
			father[x] = find(father[x]);
		return father[x];
	}

	static void union(int a, int b) {
		int ra = find(a);
		int rb = find(b);
		if (ra != rb)
			father[ra] = rb;
	}

	static boolean solve() {
		root = -1;
		for (int i = 0; i < 26; i++)
			if (indegree[i] > 0 || outdegree[i] > 0)
				if (root == -1)
					root = find(i);
				else if (find(i) != root)
					return false;

		int a = 0, b = 0, num = 0, source = 27, destination = 28;
		for (int i = 0; i < 26; i++) {
			if ((Math.abs(indegree[i] - outdegree[i]) & 1) == 1) {
				num++;
				if (num == 1)
					a = i;
				else if (num == 2)
					b = i;
				else
					return false;
			}
		}

		if (num == 2) {
			outdegree[a]++;
			indegree[b]++;
			dinic.addEdge(a, b, 1);
		}

		int sum = 0, temp;
		for (int i = 0; i < 26; i++) {
			temp = (outdegree[i] - indegree[i]) / 2;
			if (temp > 0) {
				sum += temp;
				dinic.addEdge(source, i, temp);
			} else if (temp < 0)
				dinic.addEdge(i, destination, -temp);
		}

		if (sum == dinic.getDinic(source, destination))
			return true;
		else
			return false;
	}

	static class Dinic {
		int inf = Integer.MAX_VALUE;
		int n, m, level[], queue[];

		int head[], toll;
		edge edge[];

		Dinic(int nn, int mm) {
			this.n = nn;
			this.m = mm;
			edge = new edge[m + 1];
			head = new int[n + 1];
			level = new int[n + 1];
			queue = new int[n + 1];
		}

		void init() {
			Arrays.fill(head, -1);
			toll = 0;
		}

		int getDinic(int source, int destination) {
			int sum = 0;
			while (bfs(source, destination))
				sum += dfs(source, destination, inf);
			return sum;
		}

		void addEdge(int u, int v) {
			edge[toll] = new edge(v, inf);
			edge[toll].next = head[u];
			head[u] = toll;
			toll++;

			edge[toll] = new edge(u, 0);
			edge[toll].next = head[v];
			head[v] = toll;
			toll++;
		}

		void addEdge(int u, int v, int cap) {
			edge[toll] = new edge(v, cap);
			edge[toll].next = head[u];
			head[u] = toll;
			toll++;

			edge[toll] = new edge(u, 0);
			edge[toll].next = head[v];
			head[v] = toll;
			toll++;
		}

		boolean bfs(int source, int destination) {
			Arrays.fill(level, -1);
			level[source] = 0;

			int temp, start = 0, end = 1;
			queue[start] = source;
			while (start < end) {
				temp = queue[start];
				for (int i = head[temp]; i != -1; i = edge[i].next) {
					if (level[edge[i].v] == -1 && edge[i].val > 0) {
						queue[end++] = edge[i].v;
						level[edge[i].v] = level[temp] + 1;
					}
				}
				start++;
			}
			return level[destination] != -1;
		}

		int dfs(int vert, int destination, int sum) {
			if (vert == destination)
				return sum;
			int s = sum, temp;
			for (int i = head[vert]; i != -1; i = edge[i].next) {
				if (edge[i].val > 0 && level[edge[i].v] == level[vert] + 1) {
					temp = dfs(edge[i].v, destination, Math.min(sum,
							edge[i].val));
					edge[i].val -= temp;
					edge[i ^ 1].val += temp;
					sum -= temp;
				}
			}
			return s - sum;
		}

		static class edge {
			int v, next;
			int val;

			edge(int v, int val) {
				this.v = v;
				this.val = val;
			}
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
