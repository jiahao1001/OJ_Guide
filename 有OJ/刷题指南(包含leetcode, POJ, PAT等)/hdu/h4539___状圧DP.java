import java.io.*;
import java.util.*;

public class h4539___×´ˆRDP {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m, condition[], s[], type, c[], mark[][], replace[][],
			repNum;

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			condition = new int[n + 1];
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					if (nextInt() == 1)
						condition[i] = condition[i] << 1 | 1;
					else
						condition[i] = condition[i] << 1;

			type = 0;
			s = new int[1 << m | 1];
			preWork(0, 0);

			c = new int[1 << m | 1];
			for (int i = 1; i <= type; ++i) {
				long tmp = s[i];
				while (tmp != 0) {
					c[i]++;
					tmp -= (tmp & -tmp);
				}
			}

			repNum = 0;
			replace = new int[type + 1][type + 1];
			preWork();

			mark = new int[n + 1][repNum + 1];
			for (int i = 0; i <= n; i++)
				Arrays.fill(mark[i], -1);

			int temp = dfs(n, 1, 1);
			out.println(temp);
		}
		out.flush();
		out.close();
	}

	static void preWork(int stop, int state) {
		if (stop == m) {
			s[++type] = state;
		} else {
			preWork(stop + 1, state << 1);
			if ((((state << 1) ^ 1) & (((state << 1) ^ 1)) << 2) == 0)
				preWork(stop + 1, (state << 1) ^ 1);
		}
	}

	static void preWork() {
		for (int i = 1; i <= type; i++)
			for (int j = 1; j <= type; j++)
				if (((s[i] << 1) & s[j]) == 0 && (s[i] & (s[j] << 1)) == 0)
					replace[i][j] = ++repNum;
	}

	static int temp;

	static int dfs(int line, int curCondition, int preCondition) {
		if (line >= 1) {
			int ans = 0;
			boolean[] record = new boolean[1 << m ^ 1];
			for (int i = 1; i <= type; i++) {
				temp = s[i] & condition[line];
				if (!record[temp]) {
					record[temp] = true;
					if ((temp & (s[curCondition] << 1)) == 0
							&& ((temp << 1) & s[curCondition]) == 0
							&& (temp & s[preCondition]) == 0) {
						if (mark[line - 1][replace[i][curCondition]] == -1)
							mark[line - 1][replace[i][curCondition]] = dfs(
									line - 1, i, curCondition);
						ans = Math
								.max(
										ans,
										mark[line - 1][replace[i][curCondition]]
												+ c[i]);
					}
				}
			}
			return ans;
		} else {
			return 0;
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