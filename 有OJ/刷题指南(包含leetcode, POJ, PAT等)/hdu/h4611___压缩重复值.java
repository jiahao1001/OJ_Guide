import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4611___Ñ¹ËõÖØ¸´Öµ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static long N, A, B;

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			N = nextInt();
			A = nextInt();
			B = nextInt();
			long lcm = getLCM(A, B);
			long x = N / lcm;
			long y = N % lcm;

			long ans = 0;
			if (N >= lcm)
				ans = solve(lcm) * x + solve(y);
			else
				ans = solve(y);
			out.println(ans);
		}
		out.flush();
		out.close();
	}

	static long getLCM(long a, long b) {
		long c = getGCD(a, b);
		return a * b / c;
	}

	static long getGCD(long a, long b) {
		while (a != b) {
			if (a > b)
				a -= b;
			else if (b > a)
				b -= a;
		}
		return a;
	}

	static long solve(long num) {
		// out.println(num + " :");
		long a = 0, b = 0, step, charge;
		long ans = 0;
		for (int count = 0; count < num;) {
			charge = Math.abs(a - b);
			step = Math.min(A - a, B - b);
			step = Math.min(step, num - count);
			a += step;
			b += step;
			if (a >= A)
				a -= A;
			if (b >= B)
				b -= B;
			ans = ans + step * charge;
			count += step;
			// out.println(charge + " " + step + "         " + count);
		}
		return ans;
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