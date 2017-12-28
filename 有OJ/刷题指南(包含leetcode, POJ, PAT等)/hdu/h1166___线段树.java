import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class h1166___Ïß¶ÎÊ÷ {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static int n, lazy[];
	static node[] arr;
	static char ch;

	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		int t = nextInt();
		for (int yy = 1; yy <= t; yy++) {
			pw.println("Case " + yy + ":");
			n = nextInt();
			lazy = new int[n + 1];
			arr = new node[n * 3 + 1];

			for (int i = 1; i <= n; i++)
				lazy[i] = nextInt();
			build(1, n, 1);

			int i, j;
			while ((ch = next().charAt(0)) != 'E') {
				if (ch == 'A') {
					i = nextInt();
					j = nextInt();
					update(i, j, 1);
				} else if (ch == 'S') {
					i = nextInt();
					j = nextInt();
					update(i, -j, 1);
				} else {
					i = nextInt();
					j = nextInt();
					pw.println(query(i, j, 1));
				}
			}
		}

		pw.flush();
		pw.close();
	}

	static int nextInt() throws Exception {
		in.nextToken();
		return (int) in.nval;
	}

	static String next() throws IOException {
		in.nextToken();
		return (String) in.sval;
	}

	static int build(int left, int right, int idx) {
		arr[idx] = new node();
		arr[idx].left = left;
		arr[idx].right = right;
		if (left == right)
			return arr[idx].lazy = lazy[left];
		int mid = (left + right) >> 1;
		return arr[idx].lazy = build(left, mid, idx << 1)
				+ build(mid + 1, right, idx << 1 | 1);
	}

	static void update(int id, int x, int idx) {
		arr[idx].lazy += x;
		if (arr[idx].left == arr[idx].right)
			return;
		int mid = arr[idx].calmid();
		if (id <= mid) {
			update(id, x, idx << 1);
		} else {
			update(id, x, idx << 1 | 1);
		}
	}

	static int query(int left, int right, int idx) {
		if (left == arr[idx].left && right == arr[idx].right) {
			return arr[idx].lazy;
		}
		int mid = arr[idx].calmid();
		if (right <= mid) {
			return query(left, right, idx << 1);
		} else if (mid < left) {
			return query(left, right, idx << 1 | 1);
		} else {
			return query(left, mid, idx << 1)
					+ query(mid + 1, right, idx << 1 | 1);
		}
	}

	static class node {
		int left, right, lazy;

		node() {
		}

		int calmid() {
			return (left + right) >> 1;
		}
	}
}
