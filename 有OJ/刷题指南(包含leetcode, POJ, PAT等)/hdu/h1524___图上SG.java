import java.io.*;
import java.util.*;

public class h1524___Í¼ÉÏSG {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;
	static int N = 10005;
	static int sg[] = new int[N];
	static int head[] = new int[N], tot;
	static edge edge[] = new edge[N];

	static void init() {
		Arrays.fill(head, -1);
		tot = 0;
	}

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

	static void SG(int u) {
		if (sg[u] != -1)
			return;
		int v;
		boolean vis[] = new boolean[n];
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			SG(v);
			vis[sg[v]] = true;
		}
		for (int i = 0;; i++) {
			if (!vis[i]) {
				sg[u] = i;
				break;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		int cnt, x;
		while (scan.hasNext()) {
			n = scan.nextInt();
			init();
			for (int i = 0; i < n; i++) {
				cnt = scan.nextInt();
				while (cnt-- > 0) {
					x = scan.nextInt();
					addEdge(i, x);
				}
			}
			Arrays.fill(sg, -1);
			for (int i = 0; i < n; i++)
				if (sg[i] == -1)
					SG(i);

			while (true) {
				m = scan.nextInt();
				if (m == 0)
					break;
				int ans = 0;
				while (m-- > 0)
					ans ^= sg[scan.nextInt()];

				if (ans > 0)
					out.println("WIN");
				else
					out.println("LOSE");
			}
		}

		out.flush();
		out.close();
	}
}