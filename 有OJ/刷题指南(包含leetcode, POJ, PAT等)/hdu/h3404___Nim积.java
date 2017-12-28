import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h3404___Nim»ý {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int choice[] = { 1 << (1 << 0), 1 << (1 << 1), 1 << (1 << 2),
			1 << (1 << 3), 1 << (1 << 4) };
	// {2,4,16,356,65536}
	static int sg[][] = new int[17][17];
	static boolean vis[] = new boolean[500];

	public static void main(String[] args) throws IOException {
		// create the table
		for (int i = 1; i <= 16; i++)
			for (int j = 1; j <= 16; j++) {
				Arrays.fill(vis, false);
				for (int a = 0; a < i; a++)
					for (int b = 0; b < j; b++)
						vis[sg[a][b] ^ sg[i][b] ^ sg[a][j]] = true;
				for (int temp = 0; temp < 500; temp++)
					if (!vis[temp]) {
						sg[i][j] = temp;
						break;
					}
			}

		int test = nextInt(), x, y;
		while (test-- > 0) {
			int ans = 0;
			n = nextInt();
			while (n-- > 0) {
				x = nextInt();
				y = nextInt();
				ans ^= Nim_Multi(x, y);
			}
			if (ans == 0)
				out.println("Don't waste your time.");
			else
				out.println("Have a try, lxhgww.");
		}

		out.flush();
		out.close();
	}

	static int Nim_Multi(int x, int y) {
		if (x < y)
			return Nim_Multi(y, x);
		if (x < 16)
			return sg[x][y];
		int M = 0, p = 0, q = 0, s = 0, t = 0;
		for (int i = 0; i < 5; i++) {
			if (choice[i] <= x && choice[i + 1] > x) {
				M = choice[i];
				p = x / M;
				q = x % M;
				s = y / M;
				t = y % M;
				break;
			}
		}

		int c1 = Nim_Multi(p, s);
		int c2 = Nim_Multi(p, t) ^ Nim_Multi(q, s);
		int c3 = Nim_Multi(q, t);

		return (M * (c1 ^ c2)) ^ c3 ^ Nim_Multi_Power(M / 2, c1);
	}

	static int Nim_Multi_Power(int x, int y) {
		if (x <= 16)
			return sg[x][y];
		int M = 0, p = 0, s = 0, t = 0;
		for (int i = 0; i < 5; i++) {
			if (choice[i] <= x && choice[i + 1] > x) {
				M = choice[i];
				p = x / M;
				s = y / M;
				t = y % M;
				break;
			}
		}

		int d1 = Nim_Multi_Power(p, s);
		int d2 = Nim_Multi_Power(p, t);
		return (M * (d1 ^ d2)) ^ Nim_Multi_Power(M / 2, d1);
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