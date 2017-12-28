import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h3068___manacher___回文序列 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 2000200, p[] = new int[N];
	static char list[] = new char[N];

	static int solve(char arr[], int len) {
		// arr是从0..len-1记录的
		int n = len * 2 + 1;
		Arrays.fill(list, '#');
		Arrays.fill(p, 0);
		for (int i = 1; i <= len; i++)
			list[i * 2] = arr[i - 1];
		list[0] = '$';
		list[n + 1] = '(';

		int ret = 0;

		int max = 0, id = 0;
		for (int i = 1; i <= n; i++) {
			if (max > i)
				p[i] = Math.min(p[2 * id - i], max - i);
			else
				p[i] = 1;
			while (list[i + p[i]] == list[i - p[i]])
				p[i]++;
			if (p[i] + i > max) {
				max = p[i] + i;
				id = i;
			}
			ret = Math.max(ret, p[i]);
		}

		return ret - 1;
	}

	public static void main(String[] args) throws IOException {
		String str;
		char ch[] = new char[1000100];
		int len;
		while ((str = br.readLine()) != null) {
			len = str.length();
			for (int i = 0; i < len; i++)
				ch[i] = str.charAt(i);
			out.println(solve(ch, len));
			br.readLine();
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