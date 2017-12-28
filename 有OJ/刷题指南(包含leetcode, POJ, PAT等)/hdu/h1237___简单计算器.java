//2711
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
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

public class h1237___¼òµ¥¼ÆËãÆ÷ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out;
	static int n, m;
	static long inf = -1;

	// floyd
	// static int adj[][];

	// dijkstra
	// static int dist[], visit[], head[];
	// static path[] edge;
	// static PriorityQueue<node> queue = new PriorityQueue<node>();

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("test.in"));
		out = new PrintWriter("test.out");

		double ans;
		double num, pre, cur;
		char ch;
		String line;
		Stack<Double> s1 = new Stack();
		Stack<Character> s2 = new Stack();
		StringTokenizer stoke;
		while (true) {
			line = br.readLine();
			if (line.equals("0"))
				break;
			stoke = new StringTokenizer(line);
			s1.clear();
			s2.clear();
			int index = 0;
			num = Integer.parseInt(stoke.nextToken());
			s1.add(num);
			while (stoke.hasMoreTokens()) {
				ch = stoke.nextToken().charAt(0);
				num = Integer.parseInt(stoke.nextToken());
				switch (ch) {
				case '+':
					s1.add(num);
					s2.add('+');
					break;
				case '-':
					s1.add(-num);
					s2.add('+');
					break;
				case '*':
					pre = s1.pop();
					pre = pre * num;
					s1.add(pre);
					break;
				case '/':
					pre = s1.pop();
					pre = pre / num;
					s1.add(pre);
					break;
				}
			}
			while (!s2.isEmpty()) {
				ch = s2.pop();
				cur = s1.pop();
				pre = s1.pop();
				pre = pre + cur;
				s1.add(pre);
			}

			out.printf("%.2f", s1.pop());
			out.println();
		}

		out.flush();
		out.close();
	}

}