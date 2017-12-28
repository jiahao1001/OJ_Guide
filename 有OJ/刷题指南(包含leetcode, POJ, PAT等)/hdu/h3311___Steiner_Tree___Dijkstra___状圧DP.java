import java.io.*;
import java.util.*;

//http://hi.baidu.com/yy17yy/item/27422fee2878110f570f1d5a

public class h3311___Steiner_Tree___Dijkstra___×´ˆRDP {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int N = 1010, M = 15000;
	static int head[] = new int[N], toll;
	static edge edge[] = new edge[M];
	static PriorityQueue<node> queue = new PriorityQueue();

	static boolean vis[][] = new boolean[N][1 << 6];
	static int dp[][] = new int[N][1 << 6];

	static void init() {
		toll = 0;
		Arrays.fill(head, -1);
		for (int i = 0; i < N; i++)
			Arrays.fill(vis[i], false);
		for (int i = 0; i < N; i++)
			Arrays.fill(dp[i], 1 << 29);
	}

	static void addEdge(int u, int v, int val) {
		edge[toll] = new edge(v, val);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	static int Dijkstra() {
		int tot = (1 << n) - 1;
		for (int i = 0; i <= n + m; i++)
			dp[i][0] = 0;
		for (int i = 0; i < n; i++)
			queue.add(new node(i, 1 << i, dp[i][1 << i] = 0));
		node temp;
		int u, state, v, val;
		while (!queue.isEmpty()) {
			temp = queue.poll();
			u = temp.u;
			state = temp.state;
			vis[u][state] = true;
			if (u == n + m && state == tot)
				return dp[u][state];
			for (int e = head[u]; e != -1; e = edge[e].next) {
				v = edge[e].v;
				val = edge[e].val;
				for (int k = 0; k <= tot; k++) {
					if ((k & state) > 0)
						continue;
					int subState = k | state;
					if (dp[v][subState] > dp[u][state] + val + dp[v][k]) {
						dp[v][subState] = dp[u][state] + val + dp[v][k];
						queue.add(new node(v, subState, dp[v][subState]));
					}
				}
			}
		}
		return 0;
	}

	static class edge {
		int v, next = -1, val;

		edge(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

	static class node implements Comparable<node> {
		int u, state, val;

		node(int v, int state, int val) {
			this.u = v;
			this.state = state;
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

	static int n, m, q;

	public static void main(String[] args) throws IOException {
		int u, v, val;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			q = nextInt();
			init();
			int s = n + m;
			for (int i = 0; i < n + m; i++) {
				val = nextInt();
				addEdge(s, i, val);
				addEdge(i, s, val);
			}
			for (int i = 1; i <= q; i++) {
				u = nextInt() - 1;
				v = nextInt() - 1;
				val = nextInt();
				addEdge(u, v, val);
				addEdge(v, u, val);
			}
			out.println(Dijkstra());
		}
		out.flush();
		out.close();
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