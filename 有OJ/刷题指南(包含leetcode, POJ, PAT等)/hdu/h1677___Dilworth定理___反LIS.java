import java.io.*;
import java.util.*;

public class h1677___Dilworth∂®¿Ì___∑¥LIS {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, arr[];
	static node node[];

	static class node {
		int h, w;

		node(int h, int w) {
			this.h = h;
			this.w = w;
		}
	}

	static Comparator<node> cmp = new Comparator<node>() {
		public int compare(node o1, node o2) {
			if (o1.h < o2.h)
				return -1;
			else if (o1.h > o2.h)
				return 1;
			else if (o1.w < o2.w)
				return 1;
			else if (o1.w > o2.w)
				return -1;
			return 0;
		}
	};

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			node = new node[n + 1];
			node[0] = new node(0, 0);
			for (int i = 1; i <= n; i++)
				node[i] = new node(nextInt(), nextInt());
			Arrays.sort(node, cmp);
			arr = new int[n + 1];
			for (int i = 0; i <= n; i++)
				arr[i] = node[i].w;

			int index, d[] = new int[n + 1];
			int l, r, mid;

			index = 0;

			for (int i = n; i >= 1; i--) {
				if (arr[d[index]] <= arr[i]) {
					d[++index] = i;
				} else {
					l = 0;
					r = index;
					while (l <= r) {
						mid = (l + r) >> 1;
						if (arr[d[mid]] <= arr[i])
							l = mid + 1;
						else
							r = mid - 1;
					}
					d[l] = i;
				}
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}