import java.io.*;
import java.util.*;

public class h3094___¿ìËÙIO {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int N = 100010;
	static int head[] = new int[N], tot;
	static edge edge[] = new edge[N * 2];
	static boolean vis[] = new boolean[N];

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
	}

	static void addEdge(int u, int v) {
		edge[tot] = new edge(v);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static class edge {
		int v, next;

		edge(int v) {
			this.v = v;
		}
	}

	static int dfs(int u) {
		int v;
		int ret = 0;
		vis[u] = true;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (!vis[v])
				ret ^= dfs(v);
		}
		return ret + 1;
	}

	public static void main(String[] args) throws IOException {
		int t = nextInt();
		int u, v;
		while (t-- > 0) {
			n = nextInt();
			init();
			for (int i = 1; i < n; i++) {
				u = nextInt();
				v = nextInt();
				addEdge(u, v);
				addEdge(v, u);
			}
			Arrays.fill(vis, false);
			int ans = dfs(1) - 1;

			if (ans > 0)
				out.println("Alice");
			else
				out.println("Bob");

		}
		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}