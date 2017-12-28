import java.io.*;

import java.util.*;

public class h4648___乱搞___有trick {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, arr[], left[], right[];

	public static void main(String[] args) throws IOException {
		int t, dp[];
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			arr = new int[n + 1];
			left = new int[m];
			right = new int[m];
			Arrays.fill(left, -1);

			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();
			for (int i = 1; i <= n; i++) {
				arr[i] = ((arr[i - 1] + arr[i]) % m + m) % m;
				t = arr[i];
				// 这里要注意了，如果都能够消掉，%m==0,那么可以消掉的点是i
				if (t == 0) {
					left[t] = 0;
					right[t] = i;
				} else if (left[t] == -1) {
					left[t] = right[t] = i;
				} else {
					right[t] = i;
				}
			}

			int ans = 0;
			for (int i = 0; i < m; i++)
				if (left[i] > -1) {
					ans = Math.max(right[i] - left[i], ans);
				}
			out.println(ans);
		}
		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}