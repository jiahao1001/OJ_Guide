import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class h4655___数学___加上推断 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	// 所有的情况就是prod(ai)*n
	// 然后就是减去出现了重复的个数
	// 可以枚举相邻连个点ai和ai+1,prod(1..a-1)*prod(i+2..n)是排除ai和ai+1的所有可能出现的不同染色种数
	// 那么很明显的可以知道就是ai和ai+1相同时候我们的pieces会减少
	// 所有单单考虑ai和ai+1时，我们的需要减去的pieces数目应该就是prod(1..ai-1)*min(ai,ai+1)*prod(i+2..n)
	// 注意应该这么写:prod(1..ai-1)*min(ai,ai+1)%mod*prod(i+2..n)%mod

	static int n;
	static long arr[], brr[];
	static long mod = 1000000007;
	static long left[], right[];

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			arr = new long[n + 1];
			long mul = 1;
			for (int i = 1; i <= n; i++) {
				arr[i] = nextInt();
				mul = (mul * arr[i] % mod + mod) % mod;
			}
			Arrays.sort(arr, 1, n + 1);

			brr = new long[n + 1];
			for (int i = 1; i <= n; i += 2)
				brr[i] = arr[(i + 1) / 2];
			for (int i = 2; i <= n; i += 2)
				brr[i] = arr[n + 1 - i / 2];

			left = new long[n + 2];
			right = new long[n + 2];
			left[0] = 1;
			for (int i = 1; i <= n; i++)
				left[i] = (left[i - 1] * brr[i] % mod + mod) % mod;
			right[n + 1] = 1;
			for (int i = n; i >= 1; i--)
				right[i] = (right[i + 1] * brr[i] % mod + mod) % mod;

			long ans = 0;
			for (int i = 1; i < n; i++) {
				ans = ((ans + Math.min(brr[i], brr[i + 1]) * left[i - 1] % mod
						* right[i + 2])
						% mod + mod)
						% mod;
			}

			ans = (mul * n % mod - ans) % mod;
			ans = (ans + mod) % mod;
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
