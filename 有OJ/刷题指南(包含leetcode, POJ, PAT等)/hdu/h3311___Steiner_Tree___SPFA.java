import java.io.*;
import java.util.*;

public class h3311___Steiner_Tree___SPFA {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int inf = 1 << 29;
	static int N = 1010, M = 15000, head[] = new int[N], toll;
	static edge edge[] = new edge[M];
	static int S = 1 << 7, condition;
	static int dp[][] = new int[N][S];
	static boolean inQ[][] = new boolean[N][S];
	static int st[] = new int[N];
	static LinkedList<node> queue = new LinkedList<node>();

	static void init() {
		Arrays.fill(head, -1);
		toll = 0;
		for (int i = 0; i <= N; i++) {
			Arrays.fill(dp[i], inf);
			Arrays.fill(inQ[i], false);
		}
		condition = (1 << (1 + n)) - 1;
	}

	static void addEdge(int u, int v, int val) {
		edge[toll] = new edge(v, val);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	static boolean update(int u, int state, int val) {
		if (dp[u][state] > val) {
			dp[u][state] = val;
			return true;
		}
		return false;
	}

	static class node {
		int vert, state;

		node(int v, int s) {
			vert = v;
			state = s;
		}
	}

	static class edge {
		int v, val, next;

		edge(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

	static void spfa() {
		node temp;
		int u, v, state, val, s;
		while (!queue.isEmpty()) {
			temp = queue.poll();
			u = temp.vert;
			state = temp.state;
			inQ[u][state] = false;
			for (int e = head[u]; e != -1; e = edge[e].next) {
				v = edge[e].v;
				val = edge[e].val;
				s = st[v] | state;
				// 这里很容易打错
				if (update(v, s, dp[u][state] + val) && state == s
						&& !inQ[v][state]) {
					inQ[v][state] = true;
					queue.add(new node(v, state));
				}
			}
		}
	}

	// n个必选点
	// N个所有点
	static void steiner_tree() {
		Arrays.fill(st, 0);
		// 这里需要变化
		for (int i = 0; i <= n; i++) {
			st[i] = 1 << i;
			dp[i][1 << i] = 0;
		}

		for (int state = 1; state <= condition; state++) {
			for (int u = 0; u <= N; u++) {
				for (int sub = (state - 1) & state; sub > 0; sub = (sub - 1)
						& state)
					dp[u][state] = Math.min(dp[u][state], dp[u][sub | st[u]]
							+ dp[u][(state - sub) | st[u]]);
				if (dp[u][state] < inf) {
					inQ[u][state] = true;
					queue.add(new node(u, state));
					// out.println(u + " " + Integer.toBinaryString(state));
				}
			}
			// 每次spfa对应的都是某种state
			spfa();
		}
	}

	static int solve() {
		int min = inf;
		for (int i = 0; i <= N; i++)
			min = Math.min(min, dp[i][condition]);
		return min;
	}

	static int n;

	public static void main(String[] args) throws IOException {
		int u, v, val, m, q;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			N = n + m;
			q = nextInt();
			init();
			for (int i = 1; i <= N; i++) {
				val = nextInt();
				addEdge(0, i, val);
				addEdge(i, 0, val);
			}
			for (int i = 1; i <= q; i++) {
				u = nextInt();
				v = nextInt();
				val = nextInt();
				addEdge(u, v, val);
				addEdge(v, u, val);
			}
			steiner_tree();
			out.println(solve());
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