import java.io.*;
import java.util.*;

public class h4203___SGÕÒ¹æÂÉ {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, s, k;

	public static void main(String[] args) throws IOException {
		n = scan.nextInt();
		int left;
		while (n-- > 0) {
			s = scan.nextInt();
			k = scan.nextInt();
			if (k % 2 == 1)
				out.println(s % 2);
			else {
				left = s % (k + 1);
				if (left == k)
					out.println(k);
				else
					out.println(left % 2);
			}
		}
		out.flush();
		out.close();
	}
}