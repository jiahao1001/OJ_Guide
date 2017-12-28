import java.awt.Stroke;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.*;

public class h2444___¶þ·ÖÍ¼ÅÐ¶Ï___Hungary {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	static int n, m, N, cnt;
	static int color[];
	static int cx[], cy[], mark[], map[][];

	public static void main(String[] args) throws IOException {
		int a, b;
		LinkedList<Integer> list;
		loop: while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();

			map = new int[n + 1][n + 1];

			for (int i = 1; i <= m; i++) {
				a = nextInt();
				b = nextInt();
				map[a][b] = map[b][a] = 1;
			}

			color = new int[n + 1];
			Arrays.fill(color, -1);
			color[1] = 0;
			list = new LinkedList<Integer>();
			list.add(1);
			int temp;
			while (!list.isEmpty()) {
				temp = list.poll();

				for (int i = 1; i <= n; i++) {
					if (map[i][temp] == 1)
						if (color[i] == color[temp]) {
							out.println("No");
							continue loop;
						} else if (color[i] == -1) {
							color[i] = 1 ^ color[temp];
							list.add(i);
						}
				}
			}

			int ans = 0;
			cx = new int[n + 1];
			Arrays.fill(cx, -1);
			cy = new int[n + 1];
			Arrays.fill(cy, -1);
			mark = new int[n + 1];
			for (int i = 1; i <= n; i++)
				if (cx[i] == -1) {
					Arrays.fill(mark, 0);
					ans += hungary(i);
				}

			out.println(ans / 2);
		}

		out.flush();
		out.close();
	}

	static int hungary(int u) {
		for (int i = 1; i <= n; i++) {
			if (mark[i] == 0 && map[u][i] == 1) {
				mark[i] = 1;
				if (cy[i] == -1 || hungary(cy[i]) == 1) {
					cx[u] = i;
					cy[i] = u;
					return 1;
				}
			}
		}
		return 0;
	}

	static class Dinic {
		int inf = Integer.MAX_VALUE;
		int n, m, level[], queue[];

		int head[], index;
		edge edge[];

		Dinic(int nn, int mm) {
			this.n = nn;
			this.m = mm * 2;
			edge = new edge[m];
			head = new int[n];
			Arrays.fill(head, -1);
			index = 0;
			level = new int[n];
			queue = new int[n];
		}

		int getDinic(int source, int destination) {
			int sum = 0, temp;
			while (bfs(source, destination)) {
				temp = dfs(source, destination, inf);
				if (temp == 0)
					break;
				sum += temp;
			}
			return sum;
		}

		void addEdge(int u, int v) {
			edge[index] = new edge(v, inf);
			edge[index].next = head[u];
			head[u] = index;
			index++;

			edge[index] = new edge(u, 0);
			edge[index].next = head[v];
			head[v] = index;
			index++;
		}

		void addEdge(int u, int v, int cap) {
			edge[index] = new edge(v, cap);
			edge[index].next = head[u];
			head[u] = index;
			index++;

			edge[index] = new edge(u, 0);
			edge[index].next = head[v];
			head[v] = index;
			index++;
		}

		boolean bfs(int source, int destination) {
			Arrays.fill(level, -1);
			level[source] = 0;

			int temp, start = 0, end = 1;
			queue[start] = source;
			while (start < end) {
				temp = queue[start++];
				for (int i = head[temp]; i != -1; i = edge[i].next) {
					if (level[edge[i].v] == -1 && edge[i].val > 0) {
						queue[end++] = edge[i].v;
						level[edge[i].v] = level[temp] + 1;
					}
				}
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

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}