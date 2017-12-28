import java.io.*;
import java.util.*;

public class h2196___树形dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int head[], toll;
	static edge edge[];
	static int first[], second[], firstFrom[];

	static class edge {
		int v, next, val;

		edge(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

	static void init() {
		toll = 0;
		head = new int[n + 1];
		Arrays.fill(head, -1);
		edge = new edge[n * 2];
		first = new int[n + 1];
		second = new int[n + 1];
		firstFrom = new int[n + 1];
	}

	static void addEdge(int u, int v, int val) {
		edge[toll] = new edge(v, val);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	public static void main(String[] args) throws IOException {
		int u, v, val;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			init();
			for (int i = 2; i <= n; i++) {
				v = nextInt();
				val = nextInt();
				addEdge(v, i, val);
				addEdge(i, v, val);
			}

			dfsDown(1, -1);
			dfsUp(1, -1, 0);

			for (int i = 1; i <= n; i++)
				out.println(first[i]);
		}
		out.flush();
		out.close();
	}

	// first[u]表示u子树的最长
	// second[u]表示u子树的次长
	// 自上到下
	// 每次维护三条边
	// first[u],second[u],first[v]+val
	static void dfsDown(int u, int father) {
		int v, val;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == father)
				continue;
			dfsDown(v, u);
			val = edge[e].val;
			if (first[v] + val >= first[u]) {
				second[u] = first[u];
				first[u] = first[v] + val;
				firstFrom[u] = v;
			} else if (first[v] + val > second[u])
				second[u] = first[v] + val;
		}
	}

	// first[u]表示u到所有节点最长距离
	// second[u]表示u到所有节点的次长距离
	// 自下而上
	// 每次维护三条边
	// 1、first[u],second[u],w+second[father]
	// 2、first[u],second[u],w+first[father]
	// 这里看出了dfs的一个特点——我永远可以进行这个顺序的dfs，但是自下而上或者自上而下是有dfs放在的地点决定的
	static void dfsUp(int u, int father, int w) {
		if (father != -1) {
			if (firstFrom[father] == u) {
				if (first[u] <= w + second[father]) {
					second[u] = first[u];
					first[u] = w + second[father];
					firstFrom[u] = father;
				} else if (second[u] <= w + second[father])
					second[u] = w + second[father];
			} else {
				if (first[u] <= w + first[father]) {
					second[u] = first[u];
					first[u] = w + first[father];
					firstFrom[u] = father;
				} else if (second[u] <= w + first[father])
					second[u] = w + first[father];
			}
		}
		int v, val;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (v == father)
				continue;
			val = edge[e].val;
			dfsUp(v, u, val);
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