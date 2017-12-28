import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4619___二分图匹配___最大点独立 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 1100, M = 1100;
	static int nx, ny, cx[] = new int[N], cy[] = new int[M],
			mark[] = new int[M], map[][] = new int[N][M];

	static void init(int a, int b) {
		nx = a;
		ny = b;
		Arrays.fill(cx, -1);
		Arrays.fill(cy, -1);
		for (int i = 0; i < N; i++)
			Arrays.fill(map[i], 0);
	}

	static int hungary() {
		int ans = 0;
		for (int i = 1; i <= nx; i++) {
			if (cx[i] == -1) {
				Arrays.fill(mark, 0);
				ans += path(i);
			}
		}
		return ans;
	}

	static int path(int u) {
		for (int v = 1; v <= ny; v++) {
			if (map[u][v] == 1 && mark[v] == 0) {
				mark[v] = 1;
				if (cy[v] == -1 || path(cy[v]) == 1) {
					cx[u] = v;
					cy[v] = u;
					return 1;
				}
			}
		}
		return 0;
	}

	static int n, m;
	static int hori[][] = new int[N][2], vert[][] = new int[N][2];

	public static void main(String[] args) throws IOException {
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			for (int i = 1; i <= n; i++) {
				hori[i][0] = nextInt();
				hori[i][1] = nextInt();
			}
			for (int i = 1; i <= m; i++) {
				vert[i][0] = nextInt();
				vert[i][1] = nextInt();
			}

			init(n, m);
			int x1, y1, x2, y2, x3, y3, x4, y4;
			for (int i = 1; i <= n; i++) {
				x1 = hori[i][0];
				y1 = hori[i][1];
				x2 = hori[i][0] + 1;
				y2 = y1;
				for (int j = 1; j <= m; j++) {
					x3 = vert[j][0];
					y3 = vert[j][1];
					x4 = x3;
					y4 = vert[j][1] + 1;

					if ((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)
							|| (x1 == x4 && y1 == y4) || (x2 == x4 && y2 == y4))
						map[i][j] = 1;
				}
			}

			out.println(n + m - hungary());

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

	static float nextFloat() throws IOException {
		in.nextToken();
		return (float) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}