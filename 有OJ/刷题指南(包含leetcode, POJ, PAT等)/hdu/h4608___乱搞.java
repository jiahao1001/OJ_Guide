import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4608___乱搞 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	// 题目有一个结论
	// y这个数的取值范围(x,x+20]
	// 所以我们可以放心地用while(ture)来做

	static String str;
	static int n;

	static boolean check(int[] arr) {
		int sum = 0;
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			sum += arr[i];
			if (sum >= 10)
				sum -= 10;
		}
		return sum == 0;
	}

	static void solve() {
		int len = n;
		int arr[] = new int[len + 100];
		for (int i = 1; i <= n; i++)
			arr[i] = str.charAt(n - i) - '0';

		int dep = n;
		while (true) {
			arr[1]++;
			dep = 1;
			while (arr[dep] >= 10) {
				if (dep == len) {
					len++;
					arr[len] = 0;
				}
				arr[dep] -= 10;
				dep++;
				arr[dep]++;
			}

			if (check(arr))
				break;
		}

		for (int i = len; i >= 1; i--)
			out.print(arr[i]);
		out.println();
	}

	public static void main(String[] args) throws IOException {
		int test = Integer.parseInt(br.readLine());
		while (test-- > 0) {
			str = br.readLine();
			n = str.length();
			solve();
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