import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class h2232___¾ØÕó¿ìËÙÃÝ___dfs {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int mod = 9937;

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			int n = (int) in.nval;

			int a[][] = new int[5][5];
			for (int i = 1; i <= 4; i++)
				for (int j = 1; j <= 4; j++)
					a[i][j] = 1;
			a[1][3] = a[2][4] = a[3][1] = a[4][2] = 0;

			a = fastPow(a, n);

			int[] mark = new int[5];
			int ans = 0;
			for (int x = 1; x <= 4; x++) {
				mark[x] = 1;
				for (int y = 1; y <= 4; y++) {
					if (mark[y] == 0) {
						mark[y] = 1;
						for (int z = 1; z <= 4; z++) {
							if (mark[z] == 0) {
								mark[z] = 1;
								for (int w = 1; w <= 4; w++) {
									if (mark[w] == 0) {
										ans += (((a[x][1] * a[y][2]) % mod * a[z][3])
												% mod * a[w][4])
												% mod;
										ans %= mod;
									}
								}
								mark[z] = 0;
							}
						}
						mark[y] = 0;
					}
				}
				mark[x] = 0;
			}

			out.println(ans);
		}
		out.flush();
		out.close();
	}

	static int[][] multiply(int a[][], int b[][]) {
		int c[][] = new int[a.length][b[0].length];
		int temp;
		for (int i = 1; i < a.length; i++)
			for (int j = 1; j < b[0].length; j++) {
				temp = 0;
				for (int k = 1; k < a[0].length; k++)
					temp += a[i][k] * b[k][j];
				c[i][j] = temp % mod;
			}
		return c;
	}

	static int[][] fastPow(int[][] a, int n) {
		int c[][] = new int[a.length][a.length];
		for (int i = 1; i < a.length; i++)
			c[i][i] = 1;

		while (n > 0) {
			if ((n & 1) == 1) {
				c = multiply(c, a);
			}
			n >>= 1;
			a = multiply(a, a);
		}
		return c;
	}
}
