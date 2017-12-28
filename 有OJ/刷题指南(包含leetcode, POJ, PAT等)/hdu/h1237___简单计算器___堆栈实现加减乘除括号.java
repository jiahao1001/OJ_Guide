//2711
import java.io.BufferedReader;
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

public class h1237___¼òµ¥¼ÆËãÆ÷___¶ÑÕ»ÊµÏÖ¼Ó¼õ³Ë³ýÀ¨ºÅ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static Scanner scan = new Scanner(System.in);
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m;
	static long inf = -1;

	public static void main(String[] args) throws IOException {
		String line, temp;
		StringTokenizer stoke;
		char ope, preO, t;
		double num, cur, pre;
		Stack<Character> operator = new Stack<Character>();
		Stack<Double> number = new Stack<Double>();
		while (scan.hasNextLine()) {
			line = scan.nextLine();
			if (line.equals("0"))
				break;
			stoke = new StringTokenizer(line);
			operator.clear();
			number.clear();

			while (stoke.hasMoreTokens()) {
				temp = stoke.nextToken();
				if (isDigit(temp)) {
					num = Integer.parseInt(temp);
					number.push(num);
				} else {
					ope = temp.charAt(0);
					if (ope == '+' || ope == '-' || ope == '*' || ope == '/') {
						if (operator.isEmpty()) {
							operator.push(ope);
						} else {
							preO = operator.peek();
							while (preO != '(' && check(preO, ope)) {
								pre = number.pop();
								cur = number.pop();
								operator.pop();
								switch (preO) {
								case '+':
									cur += pre;
									break;
								case '-':
									cur -= pre;
									break;
								case '*':
									cur *= pre;
									break;
								case '/':
									cur /= pre;
									break;
								}
								number.push(cur);
								if (operator.isEmpty())
									break;
								else
									preO = operator.peek();
							}
							operator.push(ope);
						}
					} else if (ope == '(') {
						operator.push(ope);
					} else {
						preO = operator.peek();
						while (preO != '(') {
							pre = number.pop();
							cur = number.pop();
							operator.pop();
							switch (preO) {
							case '+':
								cur += pre;
								break;
							case '-':
								cur -= pre;
								break;
							case '*':
								cur *= pre;
								break;
							case '/':
								cur /= pre;
								break;
							}
							number.push(cur);
							preO = operator.peek();
						}
						operator.pop();
					}
				}
			}

			while (!operator.isEmpty()) {
				pre = number.pop();
				cur = number.pop();
				preO = operator.pop();
				switch (preO) {
				case '+':
					cur += pre;
					break;
				case '-':
					cur -= pre;
					break;
				case '*':
					cur *= pre;
					break;
				case '/':
					cur /= pre;
					break;
				}
				number.push(cur);
			}

			double ans = number.pop();
			out.printf("%.2f", ans);
			out.println();
		}

		out.flush();
		out.close();
	}

	static boolean check(char a, char b) {
		if ((a == '+' || a == '-') && (b == '*' || b == '/'))
			return false;
		return true;
	}

	static boolean isDigit(String s) {
		if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")
				|| s.equals("(") || s.equals(")"))
			return false;
		else
			return true;
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