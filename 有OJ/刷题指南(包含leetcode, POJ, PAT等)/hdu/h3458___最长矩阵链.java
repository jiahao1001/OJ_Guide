import java.io.*;
import java.util.*;

public class h3458___最长矩阵链 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static class point implements Comparable<point> {
		int x, y, id, pos;

		// pos=0表示点在左下角
		// pos=1表示点在右上角

		point(int a, int b, int c, int d) {
			x = a;
			y = b;
			id = c;
			pos = d;
		}

		public int compareTo(point o) {
			if (this.x < o.x)
				return -1;
			else if (this.x > o.x)
				return 1;
			else if (this.pos == 0 && o.pos == 1)
				return -1;
			else if (this.y > o.y)
				return -1;
			else if (this.y < o.y)
				return 1;
			return 0;
		}
	}

	static boolean compare(point a, point b) {
		if (a.x > b.x && a.y > b.y)
			return true;
		else
			return false;
	}

	static int BinarySearch(int l, int r, int y) {
		int mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (y <= dp[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
		return l;
	}

	static int n;
	static int N = 100100;
	static int dp[] = new int[N], pos[] = new int[N];
	static point[] point = new point[N * 2];

	public static void main(String[] args) throws IOException {
		int x, y;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			for (int i = 1; i <= n; i++) {
				x = nextInt();
				y = nextInt();
				point[i * 2 - 1] = new point(x, y, i, 0);
				x = nextInt();
				y = nextInt();
				point[i * 2] = new point(x, y, i, 1);
			}

			Arrays.fill(pos, 0);
			Arrays.fill(dp, 0);
			Arrays.sort(point, 1, n * 2 + 1);

			point temp;
			int index = 0;
			for (int i = 1; i <= n * 2; i++) {
				temp = point[i];
				if (temp.pos == 1)
					// right
					if (pos[temp.id] > index)
						dp[++index] = temp.y;
					else
						dp[pos[temp.id]] = Math.min(dp[pos[temp.id]], temp.y);
				else
					// left
					pos[temp.id] = BinarySearch(1, index, temp.y);
			}

			out.println(index);
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