import java.io.*;
import java.util.*;

public class h4511___最短路优化___不允许出现某些特定路径 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m;
	static double inf = Double.MAX_VALUE;

	static int N = 52;
	static double dist[] = new double[N];
	static int path[] = new int[N];
	static double adj[][] = new double[N][N];
	static double point[][] = new double[N][2];
	static HashMap<String, Integer> map = new HashMap<String, Integer>();

	static void init() {
		for (int i = 1; i <= n; i++)
			Arrays.fill(adj[i], inf);
		Arrays.fill(dist, inf);
		Arrays.fill(path, -1);
	}

	public static void main(String[] args) throws IOException {
		int k;
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			init();
			for (int i = 1; i <= n; i++) {
				point[i][0] = nextDouble();
				point[i][1] = nextDouble();
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					adj[i][j] = getDist(i, j);
				}
			}

			map.clear();
			for (int i = 1; i <= m; i++) {
				k = nextInt();

				if (k == 2) {
					adj[nextInt()][nextInt()] = inf;
				} else {
					String str = "";
					for (int j = 1; j < k; j++)
						str = str + nextInt() + ",";
					str = str + nextInt();
					map.put(str, 0);
				}
			}

			ShortestPath(1);
			if (Math.abs(dist[n] - inf) < 0.0000001) {
				out.println("Can not be reached!");
			} else {
				out.printf("%.2f", dist[n]);
				out.println();
			}
		}

		out.flush();
		out.close();
	}

	static double getDist(int i, int j) {
		double ans = Math.sqrt((point[i][0] - point[j][0])
				* (point[i][0] - point[j][0]) + (point[i][1] - point[j][1])
				* (point[i][1] - point[j][1]));
		return ans;
	}

	static void ShortestPath(int source) {
		dist[1] = 0;
		path[1] = -1;

		int visit[] = new int[n + 1];
		Arrays.fill(visit, 0);
		visit[source] = 1;

		for (int i = 1; i <= n; i++) {
			dist[i] = adj[source][i];
			if (dist[i] < inf)
				path[i] = source;
		}

		double min;
		int u;
		for (int step = 1; step < n; step++) {
			min = inf;
			u = source;
			for (int i = 1; i <= n; i++) {
				if (visit[i] == 0 && dist[i] < min) {
					u = i;
					min = dist[i];
				}
			}

			visit[u] = 1;
			loop: for (int i = 1; i <= n; i++) {
				if (visit[i] == 0 && adj[u][i] < inf
						&& dist[i] > dist[u] + adj[u][i]) {

					int temp = u, cnt = 0;
					String str = u + "," + i;
					while (path[temp] != -1) {
						cnt++;
						if (cnt > 5)
							continue loop;
						temp = path[temp];
						str = temp + "," + str;
						if (map.containsKey(str))
							continue loop;
					}

					dist[i] = dist[u] + adj[u][i];
					path[i] = u;
				}
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