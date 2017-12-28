import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h3450___LIS {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int modder = 9901, n, c[], d, arr[], brr[], dp[], a, b, ans, tmp;
	static ha hash[];

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			d = nextInt();
			c = new int[n + 1];
			arr = new int[n + 1];
			brr = new int[n + 1];
			hash = new ha[n + 1];

			for (int i = 1; i <= n; i++) {
				hash[i] = new ha(nextInt(), i);
			}

			Arrays.sort(hash, 1, 1 + n, null);
			for (int i = 1; i <= n; i++) {
				arr[hash[i].index] = i;
			}

			dp = new int[n + 1];
			insert(arr[1], 1);
			dp[1] = 0;
			for (int i = 2; i <= n; i++) {
				a = find(hash[arr[i]].val + d);
				b = find(hash[arr[i]].val - d - 1);
				tmp = ((sum(a) - sum(b)) % modder + modder) % modder;
				dp[i] = ((dp[i - 1] + tmp) % modder + modder) % modder;
				insert(arr[i], tmp + 1);
			}
			out.println(dp[n]);
		}
		out.flush();
		out.close();
	}

	static int find(int k) {
		int left = 1, right = n, ret = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (hash[mid].val <= k) {
				ret = mid;
				left = mid + 1;
			} else
				right = mid - 1;
		}
		return ret;
	}

	static int lowbit(int x) {
		return x & -x;
	}

	static void insert(int x, int k) {
		k %= modder;
		while (x <= n) {
			c[x] += k;
			c[x] %= modder;
			x += lowbit(x);
		}
	}

	static int sum(int x) {
		int ans = 0;
		while (x > 0) {
			ans += c[x];
			if (ans > modder)
				ans -= modder;
			x -= lowbit(x);
		}
		return ans;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}

class ha implements Comparable<ha> {
	int val, index;

	ha(int a, int b) {
		this.val = a;
		this.index = b;
	}

	public int compareTo(ha o) {
		if (this.val < o.val)
			return -1;
		return 1;
	}

}
