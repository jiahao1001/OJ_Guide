import java.io.*;
import java.util.*;

public class h3434___¬“∏„Ã‚ {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		for (int test = 1; test <= ttt; test++) {
			int n = nextInt();
			int[] arr = new int[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();

			long a = 0, b = 0;
			for (int i = 2; i <= n; i++) {
				if (arr[i] > arr[i - 1])
					a += arr[i] - arr[i - 1];
				else
					b += arr[i - 1] - arr[i];
			}
			long max = Math.max(arr[1], arr[n]), min = Math.min(arr[1], arr[n]);

			long x = Math.max(a, b);
			long y = max - min + 1;
			out.println("Case " + test + ": " + x + " " + y);
		}
		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}