import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h4315___½×ÌÝ²©ÞÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, k;
	static int arr[];

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			k = nextInt();
			arr = new int[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();
			if (k == 1) {
				out.println("Alice");
				continue;
			}
			int ans = 0;
			if (n % 2 == 0) {
				for (int i = n; i >= 1; i -= 2)
					ans ^= arr[i] - arr[i - 1] - 1;
			} else {
				ans = arr[1];
				if (k == 2)
					ans--;
				for (int i = n; i >= 2; i -= 2)
					ans ^= arr[i] - arr[i - 1] - 1;
			}
			if (ans > 0)
				out.println("Alice");
			else
				out.println("Bob");
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