import java.io.*;
import java.util.*;

public class h4155___dfs²©ÞÄ {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static String str;
	static int len;
	static int ch;
	static int dp[][][][][][][] = new int[40][5][5][5][5][5][5];

	static int dfs(int sum, int one, int two, int three, int four, int five,
			int six) {
		if (dp[sum][one][two][three][four][five][six] > -1)
			return dp[sum][one][two][three][four][five][six];
		if (sum == 31)
			return (dp[sum][one][two][three][four][five][six] = 0);

		dp[sum][one][two][three][four][five][six] = 0;

		if (sum + 1 <= 31 && one < 4
				&& dfs(sum + 1, one + 1, two, three, four, five, six) == 0)
			return (dp[sum][one][two][three][four][five][six] = 1);
		if (sum + 2 <= 31 && two < 4
				&& dfs(sum + 2, one, two + 1, three, four, five, six) == 0)
			return (dp[sum][one][two][three][four][five][six] = 1);
		if (sum + 3 <= 31 && three < 4
				&& dfs(sum + 3, one, two, three + 1, four, five, six) == 0)
			return (dp[sum][one][two][three][four][five][six] = 1);
		if (sum + 4 <= 31 && four < 4
				&& dfs(sum + 4, one, two, three, four + 1, five, six) == 0)
			return (dp[sum][one][two][three][four][five][six] = 1);
		if (sum + 5 <= 31 && five < 4
				&& dfs(sum + 5, one, two, three, four, five + 1, six) == 0)
			return (dp[sum][one][two][three][four][five][six] = 1);
		if (sum + 6 <= 31 && six < 4
				&& dfs(sum + 6, one, two, three, four, five, six + 1) == 0)
			return (dp[sum][one][two][three][four][five][six] = 1);

		return dp[sum][one][two][three][four][five][six];
	}

	public static void main(String[] args) throws IOException {

		loop: while (scan.hasNext()) {
			str = scan.next();
			len = str.length();
			int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, sum = 0;
			for (int i = 0; i < len; i++) {
				ch = str.charAt(i) - '0';
				sum += ch;
				if (ch == 1)
					one++;
				else if (ch == 2)
					two++;
				else if (ch == 3)
					three++;
				else if (ch == 4)
					four++;
				else if (ch == 5)
					five++;
				else
					six++;

				if (sum > 31) {
					if ((i & 1) == 1)
						out.println(str + " A");
					else
						out.println(str + " B");
					continue loop;
				}
			}
			for (int i = 0; i <= 31; i++)
				for (int onei = 0; onei <= 4; onei++)
					for (int twoi = 0; twoi <= 4; twoi++)
						for (int threei = 0; threei <= 4; threei++)
							for (int fouri = 0; fouri <= 4; fouri++)
								for (int fivei = 0; fivei <= 4; fivei++)
									for (int sixi = 0; sixi <= 4; sixi++)
										dp[i][onei][twoi][threei][fouri][fivei][sixi] = -1;
			dfs(sum, one, two, three, four, five, six);
			if (dp[sum][one][two][three][four][five][six] == 0) {
				if ((len & 1) == 1)
					out.println(str + " A");
				else
					out.println(str + " B");
			} else {
				if ((len & 1) == 0)
					out.println(str + " A");
				else
					out.println(str + " B");
			}
		}

		out.flush();
		out.close();
	}
}