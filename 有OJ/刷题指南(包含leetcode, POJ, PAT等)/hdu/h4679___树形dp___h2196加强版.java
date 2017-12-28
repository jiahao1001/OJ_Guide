import java.io.*;
import java.util.*;

public class h4679___树形dp___h2196加强版 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 100010;
	static int head[] = new int[N], toll;
	static edge edge[] = new edge[N * 2];
	static int first[] = new int[N], second[] = new int[N],
			third[] = new int[N], firstFrom[] = new int[N],
			secondFrom[] = new int[N], diameter[] = new int[N];

	static class edge {
		int u, v, next, val, id;

		edge(int u, int v, int val, int id) {
			this.u = u;
			this.v = v;
			this.val = val;
			this.id = id;
		}
	}

	static void init() {
		Arrays.fill(head, -1);
		toll = 0;
		edge = new edge[n * 2];
		Arrays.fill(first, 0);
		Arrays.fill(second, 0);
		Arrays.fill(third, 0);
	}

	static void addEdge(int u, int v, int val, int id) {
		edge[toll] = new edge(u, v, val, id);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	static int n, min, id;
	static int inf = 1 << 29;

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		int u, v, val;
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			init();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				val = nextInt();
				addEdge(u, v, val, i);
				addEdge(v, u, val, i);
			}

			min = inf;
			id = 0;
			dfsDown(1, -1);
			dfsUp(1, -1, 0);
			out.println("Case #" + test + ": " + id);
		}
		out.flush();
		out.close();
	}

	static void dfsDown(int u, int father) {
		int v;
		first[u] = second[u] = third[u] = -1;
		diameter[u] = 0;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == father)
				continue;
			dfsDown(v, u);
			update(u, v, 1);
			diameter[u] = Math.max(diameter[u], diameter[v]);
		}
		diameter[u] = Math.max(diameter[u], first[u] + second[u]);
		first[u] = Math.max(first[u], 0);
	}

	static void dfsUp(int u, int father, int outerBiggest) {
		if (father != -1)
			update(u, father, 1);
		if (second[u] == -1)
			second[u] = 0;
		if (third[u] == -1)
			third[u] = 0;

		int v, val, temp, big;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == father)
				continue;
			val = edge[e].val;

			if (firstFrom[u] == v)
				big = second[u] + third[u];
			else if (secondFrom[u] == v)
				big = first[u] + third[u];
			else
				big = first[u] + second[u];

			big = Math.max(big, outerBiggest);
			if (big < diameter[u])
				for (int i = head[u]; i != -1; i = edge[i].next)
					if (edge[i].v != v && edge[i].v != father)
						big = Math.max(big, diameter[edge[i].v]);

			temp = val * Math.max(diameter[v], big);

			if (temp < min) {
				min = temp;
				id = edge[e].id;
			} else if (temp == min)
				id = Math.min(id, edge[e].id);

			dfsUp(v, u, big);
		}
	}

	// 用v来更新u
	static void update(int u, int v, int w) {
		if (firstFrom[v] == u) {
			if (second[v] != -1)
				if (second[v] + w >= first[u]) {
					third[u] = second[u];
					second[u] = first[u];
					first[u] = second[v] + w;
					secondFrom[u] = firstFrom[u];
					firstFrom[u] = v;
				} else if (second[v] + w >= second[u]) {
					third[u] = second[u];
					second[u] = second[v] + w;
					secondFrom[u] = v;
				} else if (second[v] + w > third[u])
					third[u] = second[v] + w;
		} else if (secondFrom[v] == u) {
			third[u] = second[u];
			second[u] = first[u];
			first[u] = first[v] + w;
			secondFrom[u] = firstFrom[u];
			firstFrom[u] = v;
		} else {
			if (first[v] + w >= first[u]) {
				third[u] = second[u];
				second[u] = first[u];
				first[u] = first[v] + w;
				secondFrom[u] = firstFrom[u];
				firstFrom[u] = v;
			} else if (first[v] + w >= second[u]) {
				third[u] = second[u];
				second[u] = first[v] + w;
				secondFrom[u] = v;
			} else if (first[v] + w >= third[u])
				third[u] = first[v] + w;
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