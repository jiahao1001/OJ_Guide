import java.io.*;
import java.util.*;

public class h4091___大背包___数学方法做TLE___要用Long {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static long cost[] = new long[3], weight[] = new long[3], change;

	public static void main(String[] args) throws IOException {
		// 要用long！！！
		int t = nextInt();
		long max, lcm, num, mod, vol, temp, ans;

		for (int test = 1; test <= t; test++) {
			vol = nextInt();
			for (int i = 1; i <= 2; i++) {
				cost[i] = nextInt();
				weight[i] = nextInt();
			}
			sort();

			lcm = getLCM(cost[1], cost[2]);
			mod = vol % lcm;
			num = vol / lcm;
			if (num > 0) {
				num--;
				mod += lcm;
			}
			double k1 = 1.0 * weight[1] / cost[1];
			double k2 = 1.0 * weight[2] / cost[2];
			if (k1 > k2)
				ans = num * (lcm / cost[1]) * weight[1];
			else
				ans = num * (lcm / cost[2]) * weight[2];

			max = 0;
			for (int i = 0; i * cost[2] <= mod; i++) {
				temp = (mod - i * cost[2]) / cost[1] * weight[1] + weight[2]
						* i;
				if (temp > max)
					max = temp;
			}

			out.println("Case #" + test + ": " + (max + ans));
		}

		out.flush();
		out.close();
	}

	// 求解最小公倍数
	// Least Common Multiple
	static long getLCM(long a, long b) {
		long c = getGCD(a, b);
		return a * b / c;
	}

	// 辗转相除法，欧几里得算法，求解最大公约数
	// Greatest Common Divisor
	static long getGCD(long a, long b) {
		if (a < b) {
			change = a;
			a = b;
			b = change;
		}
		if (a % b == 0)
			return b;
		else
			return getGCD(b, a % b);
	}

	static void sort() {
		if (cost[2] < cost[1]) {
			change = weight[1];
			weight[1] = weight[2];
			weight[2] = change;
			change = cost[1];
			cost[1] = cost[2];
			cost[2] = change;
		}
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