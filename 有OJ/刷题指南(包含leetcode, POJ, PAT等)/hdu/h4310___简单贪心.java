//2711
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h4310___¼òµ¥Ì°ÐÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	static int n;
	static enemy enemy[];

	static class enemy implements Comparable<enemy> {
		int hp, dps;

		enemy(int hp, int dps) {
			this.hp = hp;
			this.dps = dps;
		}

		public int compareTo(enemy o) {
			long a = this.dps * this.hp + o.dps * (o.hp + this.hp);
			long b = o.dps * o.hp + this.dps * (this.hp + o.hp);
			if (a < b)
				return -1;
			else if (a > b)
				return 1;
			else
				return 0;
		}
	}

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			enemy = new enemy[n + 1];
			for (int i = 1; i <= n; i++)
				enemy[i] = new enemy(nextInt(), nextInt());
			Arrays.sort(enemy, 1, n + 1);
			for (int i = 2; i <= n; i++)
				enemy[i].hp += enemy[i - 1].hp;
			long ans = 0;
			for (int i = 1; i <= n; i++)
				ans += enemy[i].dps * enemy[i].hp;
			out.println(ans);

		}

		out.flush();
		out.close();
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

}