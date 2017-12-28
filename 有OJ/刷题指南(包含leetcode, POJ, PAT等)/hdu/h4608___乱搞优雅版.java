import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4608___乱搞优雅版 {
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
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum >= 10)
				sum -= 10;
		}
		return sum == 0;
	}

	static void solve() {
		int arr[] = new int[n + 1];
		arr[0] = 0;
		for (int i = 1; i <= n; i++)
			arr[i] = str.charAt(i - 1) - '0';

		int dep = n;
		while (true) {
			arr[n]++;
			if (arr[dep] == 10) {
				while (arr[dep] >= 10) {
					arr[dep] -= 10;
					dep--;
					arr[dep]++;
				}
				dep = n;
			}
			if (check(arr))
				break;
		}

		if (arr[0] != 0)
			out.print(arr[0]);
		for (int i = 1; i <= n; i++)
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