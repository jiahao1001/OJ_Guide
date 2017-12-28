
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class h2276___¾ØÕó¿ìËÙÃÝ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, mod = 2;

	public static void main(String[] args) throws IOException {
		int time, a[][], arr[];
		String str;
		while (true) {
			try {
				time = Integer.parseInt(br.readLine());
				str = br.readLine();
				n = str.length();
				arr = new int[n + 1];
				for (int i = 1; i <= n; i++)
					arr[i] = (int) (str.charAt(i - 1) - '0');

				a = new int[n + 1][n + 1];
				a[n][1] = a[1][1] = 1;
				for (int i = 2; i <= n; i++)
					a[i][i] = a[i - 1][i] = 1;

				arr = multiplyFinal(arr, fastPow(a, time));

				for (int i = 1; i <= n; i++) {
					out.print(arr[i]);
				}
				out.println();
			} catch (Exception e) {
				break;
			}
		}
		br.close();
		out.flush();
		out.close();
	}

	static int[][] multiply(int a[][], int b[][]) {
		int c[][] = new int[a.length][b[0].length];
		int temp;

		for (int j = 1; j < b[0].length; j++) {
			temp = 0;
			for (int k = 1; k < a[0].length; k++) {
				temp += a[1][k] * b[k][j] % mod;
				temp %= mod;
			}
			c[1][j] = temp % mod;
		}

		for (int i = 2; i <= n; i++) {
			c[i][1] = c[i - 1][n];
			for (int j = 2; j <= n; j++) {
				c[i][j] = c[i - 1][j - 1];
			}
		}

		return c;

	}

	static int[] multiplyFinal(int a[], int b[][]) {
		int c[] = new int[a.length];
		int temp;
		for (int j = 1; j < b[0].length; j++) {
			temp = 0;
			for (int k = 1; k < a.length; k++) {
				temp += a[k] * b[k][j] % mod;
				temp %= mod;
			}
			c[j] = temp % mod;
		}
		return c;
	}

	static int[][] fastPow(int[][] a, int p) {
		int c[][] = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++)
			c[i][i] = 1;

		while (p > 0) {
			if ((p & 1) == 1) {
				c = multiply(c, a);
			}
			p >>= 1;
			a = multiply(a, a);
		}
		return c;
	}

}