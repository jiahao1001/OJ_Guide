import java.io.*;
import java.util.*;

public class h3944___Lucas¶¨Àí {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, k, mod;
	static long d, x, y;

	static void gcd(int a, int b) {
		if (b == 0) {
			d = a;
			x = 1;
			y = 0;
		} else {
			long t = x;
			x = y;
			y = t;
			gcd(b, a % b);
			y -= x * (a / b);
		}
	}

	static int inv(int a) {
		int x = mod;
		gcd(a, x);
		return d == 1 ? (x + mod) % mod : -1;
	}

	public static void main(String[] args) throws IOException {
		int count = 0;
		long ans;

		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			k = nextInt();
			mod = nextInt();
			if (k > n / 2)
				k = n - k;
			count++;
			init(mod);
			ans = (n - k + Lucas(n + 1, k, mod)) % mod;
			if (ans < 0)
				ans += mod;
			out.println("Case #" + count + ": " + ans);
		}
		out.flush();
		out.close();
	}

	static int fac[];

	static void init(int mod) {
		int i;
		fac = new int[mod + 1];
		fac[0] = 1;
		for (i = 1; i <= mod; i++)
			fac[i] = fac[i - 1] * i % mod;
	}

	static long pow(int a, int b, int mod) {
		long tmp = a % mod, ans = 1;
		while (b > 0) {
			if ((b & 1) > 0)
				ans = ans * tmp % mod;
			tmp = tmp * tmp % mod;
			b >>= 1;
		}
		return ans;
	}

	static long C(int n, int m, int mod) {
		if (m > n)
			return 0;
		return fac[n] * pow(fac[m] * fac[n - m], mod - 2, mod) % mod;
	}

	static long Lucas(int n, int m, int mod) {
		if (m == 0)
			return 1;
		else
			return (C(n % mod, m % mod, mod) * Lucas(n / mod, m / mod, mod))
					% mod;
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}