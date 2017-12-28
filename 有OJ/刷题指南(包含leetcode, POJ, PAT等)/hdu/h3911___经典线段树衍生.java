import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Set;
import java.util.TreeMap;

public class h3911___¾­µäÏß¶ÎÊ÷ÑÜÉú {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int lazy[], n, ch;
	static h3911___node[] arr;

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			lazy = new int[n + 1];
			arr = new h3911___node[n * 4];
			for (int i = 1; i <= n; i++)
				lazy[i] = nextInt();

			build(1, n, 1);

			int m = nextInt(), a, b;
			for (int i = 1; i <= m; i++) {
				ch = nextInt();
				a = nextInt();
				b = nextInt();
				if (ch == 1) {
					update(a, b, 1);
					// System.out.println(arr[1].blmax + "  " + arr[1].bmax +
					// "  "
					// + arr[1].brmax);
				} else {
					out.println(query(a, b, 1));
				}
			}
		}
		out.flush();
		out.close();
	}

	static void build(int left, int right, int idx) {
		arr[idx] = new h3911___node(left, right);
		if (left == right) {
			arr[idx].bmax = arr[idx].blmax = arr[idx].brmax = lazy[left];
			arr[idx].wmax = arr[idx].wlmax = arr[idx].wrmax = lazy[left] ^ 1;
			return;
		}
		int mid = arr[idx].calmid();
		build(left, mid, idx << 1);
		build(mid + 1, right, idx << 1 | 1);
		pushUp(idx);
	}

	static void update(int left, int right, int idx) {
		if (left == arr[idx].left && arr[idx].right == right) {
			arr[idx].swap();
			arr[idx].lazy ^= 1;
			return;
		}

		if (arr[idx].lazy != 0) {
			arr[idx << 1].swap();
			arr[idx << 1 | 1].swap();
			arr[idx << 1].lazy ^= 1;
			arr[idx << 1 | 1].lazy ^= 1;
			arr[idx].lazy = 0;
		}

		int mid = arr[idx].calmid();
		if (right <= mid)
			update(left, right, idx << 1);
		else if (left > mid)
			update(left, right, idx << 1 | 1);
		else {
			update(left, mid, idx << 1);
			update(mid + 1, right, idx << 1 | 1);
		}
		pushUp(idx);
	}

	static int query(int left, int right, int idx) {
		if (left == arr[idx].left && arr[idx].right == right) {
			return arr[idx].bmax;
		}

		if (arr[idx].lazy != 0) {
			arr[idx << 1].swap();
			arr[idx << 1 | 1].swap();
			arr[idx << 1].lazy ^= 1;
			arr[idx << 1 | 1].lazy ^= 1;
			arr[idx].lazy = 0;
		}

		int mid = arr[idx].calmid();
		if (right <= mid)
			return query(left, right, idx << 1);
		else if (left > mid)
			return query(left, right, idx << 1 | 1);
		else {
			int a = query(left, mid, idx << 1);
			int b = query(mid + 1, right, idx << 1 | 1);
			return Math.max(Math.max(a, b), Math.min(a, arr[idx << 1].brmax)
					+ Math.min(b, arr[idx << 1 | 1].blmax));
		}
	}

	static void pushUp(int idx) {
		arr[idx].bmax = Math.max(arr[idx << 1].brmax + arr[idx << 1 | 1].blmax,
				Math.max(arr[idx << 1].bmax, arr[idx << 1 | 1].bmax));
		arr[idx].blmax = arr[idx << 1].blmax;
		arr[idx].brmax = arr[idx << 1 | 1].brmax;
		if (arr[idx << 1].bmax == arr[idx << 1].len())
			arr[idx].blmax += arr[idx << 1 | 1].blmax;
		if (arr[idx << 1 | 1].bmax == arr[idx << 1 | 1].len())
			arr[idx].brmax += arr[idx << 1].brmax;

		arr[idx].wmax = Math.max(arr[idx << 1].wrmax + arr[idx << 1 | 1].wlmax,
				Math.max(arr[idx << 1].wmax, arr[idx << 1 | 1].wmax));
		arr[idx].wlmax = arr[idx << 1].wlmax;
		arr[idx].wrmax = arr[idx << 1 | 1].wrmax;
		if (arr[idx << 1].wmax == arr[idx << 1].len())
			arr[idx].wlmax += arr[idx << 1 | 1].wlmax;
		if (arr[idx << 1 | 1].wmax == arr[idx << 1 | 1].len())
			arr[idx].wrmax += arr[idx << 1].wrmax;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}

class h3911___node {
	int left, right, bmax, blmax, brmax, wmax, wlmax, wrmax, lazy;

	h3911___node(int l, int r) {
		this.left = l;
		this.right = r;
		this.lazy = 0;
	}

	void swap() {
		bmax = bmax ^ wmax;
		wmax = bmax ^ wmax;
		bmax = bmax ^ wmax;

		blmax = blmax ^ wlmax;
		wlmax = blmax ^ wlmax;
		blmax = blmax ^ wlmax;

		brmax = brmax ^ wrmax;
		wrmax = brmax ^ wrmax;
		brmax = brmax ^ wrmax;
	}

	int calmid() {
		return (left + right) >> 1;
	}

	int len() {
		return right - left + 1;
	}
}
