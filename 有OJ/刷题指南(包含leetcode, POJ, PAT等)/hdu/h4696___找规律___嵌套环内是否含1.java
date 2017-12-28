import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h4696___找规律___嵌套环内是否含1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, q, t[], c[], temp;
	static int N = 100010;
	static boolean ok, vis[] = new boolean[N];

	static int head[] = new int[N], tot;
	static edge edge[] = new edge[N];

	static class edge {
		int v, next;

		edge(int v) {
			this.v = v;
		}
	}

	static void addEdge(int u, int v) {
		edge[tot] = new edge(v);
		edge[tot].next = head[u];
		head[u] = tot++;
	}

	static void dfs(int u, int f) {
		if (c[u] == 1)
			ok = true;
		int v;
		vis[u] = true;
		if (u == f)
			return;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			dfs(v, f);
		}
	}

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
		ok = false;
		Arrays.fill(vis, false);
	}

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			q = nextInt();

			init();
			t = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				t[i] = nextInt();
				addEdge(i, t[i]);
			}
			c = new int[n + 1];
			for (int i = 1; i <= n; i++)
				c[i] = nextInt();
			for (int i = 1; i <= n; i++) {
				if (!vis[i])
					dfs(i, i);
			}

			while (q-- > 0) {
				temp = nextInt();
				if (temp <= 0)
					out.println("NO");
				else if (ok)
					out.println("YES");
				else if (temp % 2 == 0)
					out.println("YES");
				else
					out.println("NO");
			}
		}

		out.flush();
		out.close();
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