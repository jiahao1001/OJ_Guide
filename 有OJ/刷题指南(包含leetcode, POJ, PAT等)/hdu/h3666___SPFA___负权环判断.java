import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;

public class h3666___SPFA___负权环判断 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, l, u, limit = 10010, adj[][], cnt, head[], num[];
	static double dis[];
	static boolean visit[];
	static p366__road edge[];
	static PriorityQueue<Integer> queue = new PriorityQueue<Integer>();

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			l = nextInt();
			u = nextInt();
			adj = new int[n + 1][m + 1];
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					adj[i][j] = nextInt();
			cnt = -1;
			edge = new p366__road[2 * n * m + 1];
			head = new int[n + m + 1];
			Arrays.fill(head, -1);
			cnt++;
			edge[cnt] = new p366__road(1, 0);
			edge[cnt].next = head[0];
			head[0] = cnt;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					cnt++;
					edge[cnt] = new p366__road(i, Math.log(u) - Math.log(adj[i][j]));
					edge[cnt].next = head[j + n];
					head[j + n] = cnt;
					cnt++;
					edge[cnt] = new p366__road(j + n, Math.log(adj[i][j])
							- Math.log(l));
					edge[cnt].next = head[i];
					head[i] = cnt;
				}
			}
			System.out.println(SPFA());

		}
		out.flush();
		out.close();
	}

	static String SPFA() {
		dis = new double[n + m + 1];
		visit = new boolean[n + m + 1];
		num = new int[n + m + 1];
		Arrays.fill(dis, limit);
		Arrays.fill(visit, false);
		dis[0] = 0;
		visit[0] = true;
		num[0] = 1;
		queue.clear();
		queue.add(0);

		int id;
		while (!queue.isEmpty()) {
			id = queue.poll();
			visit[id] = false;
			for (int i = head[id]; i >= 0; i = edge[i].next) {
				if (dis[edge[i].v] > dis[id] + edge[i].val) {
					dis[edge[i].v] = dis[id] + edge[i].val;
					if (!visit[edge[i].v]) {
						visit[edge[i].v] = true;
						num[edge[i].v]++;
						queue.add(edge[i].v);
						// 这里只需要判断每个元素是否进队sqrt(n)次就可以了???
						if (num[edge[i].v] > (int) Math.sqrt(1.0 * (n + m)))
							return "NO";
					}
				}
			}
		}
		return "YES";
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}

class p366__road {
	int v, next;
	double val;

	p366__road(int v, double len) {
		this.v = v;
		this.val = len;
		this.next = -1;
	}
}
