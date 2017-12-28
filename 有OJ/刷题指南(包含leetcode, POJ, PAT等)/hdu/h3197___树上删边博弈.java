import java.io.*;
import java.util.*;

public class h3197___Ê÷ÉÏÉ¾±ß²©ÞÄ {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int N = 10100;
	static int head[] = new int[N], tot;
	static edge edge[] = new edge[N * 2];
	static boolean vis[] = new boolean[N];

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		Arrays.fill(vis, false);
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
				ret ^= 1 + dfs(v);
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int v;
		Stack<Integer> stack = new Stack<Integer>();
		while (scan.hasNext()) {
			n = scan.nextInt();
			init();
			for (int i = 0; i < n; i++) {
				v = scan.nextInt();
				if (v != -1) {
					addEdge(i, v);
					addEdge(v, i);
				} else
					stack.add(i);
			}
			int ans = 0;
			while (!stack.isEmpty()) {
				int t = stack.pop();
				ans ^= dfs(t);
			}
			if (ans > 0)
				out.println("YES");
			else
				out.println("NO");
		}
		out.flush();
		out.close();
	}

}