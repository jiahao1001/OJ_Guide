import java.io.*;
import java.util.*;

public class h3364___高斯消元___同poj1830 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int ttt = nextInt(), n, m, q, arr[][], matrix[][];
		for (int test = 1; test <= ttt; test++) {
			out.println("Case " + test + ":");
			n = nextInt();
			m = nextInt();
			matrix = new int[n][m];
			for (int i = 0; i < m; i++) {
				int k = nextInt();
				while (k-- > 0)
					matrix[nextInt() - 1][i] = 1;
			}

			arr = new int[n][m + 1];
			q = nextInt();
			while (q-- > 0) {
				for (int i = 0; i < n; i++)
					arr[i][m] = nextInt();
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						arr[i][j] = matrix[i][j];
				out.println(gauss(arr, n, m));
			}
		}
		out.flush();
		out.close();
	}

	static long gauss(int a[][], int r, int c) {
		int row, col, maxr;
		for (row = 0, col = 0; row < r && col < c; row++, col++) {
			maxr = row;
			for (int i = row + 1; i < r; i++)
				if (Math.abs(a[i][col]) > Math.abs(a[maxr][col]))
					maxr = i;
			if (a[maxr][col] == 0) {
				row--;
				continue;
			}
			if (maxr != row)
				for (int j = col; j < c + 1; j++) {
					int temp = a[row][j];
					a[row][j] = a[maxr][j];
					a[maxr][j] = temp;
				}

			for (int i = row + 1; i < r; i++)
				if (a[i][col] != 0)
					for (int j = col; j < c + 1; j++)
						a[i][j] ^= a[row][j];
		}

		for (int i = row; i < r; i++)
			if (a[i][c] > 0)
				return 0;
		return 1l << (c - row);
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