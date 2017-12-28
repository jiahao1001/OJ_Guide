import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h1760___DFS___NP²©ÞÄ {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;
	static String str;
	static int arr[][];

	static boolean dfs() {
		boolean ret = false;
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++) {
				if (arr[i][j] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0
						&& arr[i + 1][j + 1] == 0) {
					arr[i][j] = arr[i][j + 1] = arr[i + 1][j] = arr[i + 1][j + 1] = 1;
					if (!dfs())
						ret = true;
					arr[i][j] = arr[i][j + 1] = arr[i + 1][j] = arr[i + 1][j + 1] = 0;
				}
			}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		while (scan.hasNext()) {
			n = scan.nextInt();
			m = scan.nextInt();
			scan.nextLine();
			arr = new int[n + 1][m + 1];
			for (int i = 1; i <= n; i++) {
				str = scan.nextLine();
				for (int j = 1; j <= m; j++)
					arr[i][j] = str.charAt(j - 1) - '0';
			}
			if (dfs())
				out.println("Yes");
			else
				out.println("No");
		}
		out.flush();
		out.close();
	}

}