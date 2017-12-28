import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4681___LCS±‰–Œ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 1100;

	static String stra, strb, strc;
	static char a[] = new char[N], b[] = new char[N], c[] = new char[N];
	static int la, lb, lc;
	static int dp1[][] = new int[N][N], dp2[][] = new int[N][N],
			path[][][] = new int[N][N][2];

	static void init() {
		for (int i = 0; i < N; i++) {
			Arrays.fill(dp1[i], 0);
			Arrays.fill(dp2[i], 0);
		}
	}

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		for (int test = 1; test <= ttt; test++) {
			stra = next();
			strb = next();
			strc = next();
			la = stra.length();
			for (int i = 1; i <= la; i++)
				a[i] = stra.charAt(i - 1);
			lb = strb.length();
			for (int i = 1; i <= lb; i++)
				b[i] = strb.charAt(i - 1);
			lc = strc.length();
			for (int i = 1; i <= lc; i++)
				c[i] = strc.charAt(i - 1);

			init();
			for (int i = 1; i <= la; i++)
				for (int j = 1; j <= lb; j++)
					if (a[i] == b[j])
						dp1[i][j] = dp1[i - 1][j - 1] + 1;
					else
						dp1[i][j] = Math.max(dp1[i - 1][j], dp1[i][j - 1]);

			for (int i = la; i >= 1; i--)
				for (int j = lb; j >= 1; j--)
					if (a[i] == b[j])
						dp2[i][j] = dp2[i + 1][j + 1] + 1;
					else
						dp2[i][j] = Math.max(dp2[i + 1][j], dp2[i][j + 1]);

			int index, ans = 0;
			int listA[][] = new int[N + 1][2], totA = 0;
			for (int i = 1; i <= la - lc + 1; i++) {
				if (a[i] == c[1]) {
					index = 1;
					for (int k = i; k <= la; k++) {
						if (a[k] == c[index])
							index++;
						if (index == lc + 1) {
							listA[++totA][0] = i;
							listA[totA][1] = k;
							break;
						}
					}
				}
			}

			int listB[][] = new int[N + 1][2], totB = 0;
			for (int i = 1; i <= lb - lc + 1; i++) {
				if (b[i] == c[1]) {
					index = 1;
					for (int k = i; k <= lb; k++) {
						if (b[k] == c[index])
							index++;
						if (index == lc + 1) {
							listB[++totB][0] = i;
							listB[totB][1] = k;
							break;
						}
					}
				}
			}

			ans = 0;
			int fa, fb, la, lb;
			for (int i = 1; i <= totA; i++) {
				for (int j = 1; j <= totB; j++) {
					fa = listA[i][0];
					la = listA[i][1];
					fb = listB[j][0];
					lb = listB[j][1];
					ans = Math.max(ans, dp1[fa][fb] + lc - 2 + dp2[la][lb]);
				}
			}

			out.println("Case #" + test + ": " + ans);
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