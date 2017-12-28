import java.io.*;
import java.util.*;

public class h3590___Ê÷ÉÏÉ¾±ß²©ÞÄ___Anti_SG {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int N = 100010;
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
		int u, v;
		while (scan.hasNext()) {
			int part = scan.nextInt();
			int ans = 0;
			boolean flag = true;
			for (int p = 1; p <= part; p++) {
				n = scan.nextInt();
				init();
				for (int i = 1; i < n; i++) {
					u = scan.nextInt();
					v = scan.nextInt();
					addEdge(u, v);
					addEdge(v, u);
				}
				int temp = dfs(1);
				ans ^= temp;
				if (temp > 1)
					flag = false;
			}

			if (flag) {
				if (ans > 0)
					out.println("QQ");
				else
					out.println("PP");
			} else {
				if (ans > 0)
					out.println("PP");
				else
					out.println("QQ");
			}
		}
		out.flush();
		out.close();
	}
}