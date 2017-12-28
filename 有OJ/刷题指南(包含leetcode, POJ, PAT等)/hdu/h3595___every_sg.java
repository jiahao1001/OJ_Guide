import java.io.*;

import java.util.*;

public class h3595___every_sg {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int p, q;
	static int f[] = new int[1000];

	public static void main(String[] args) throws IOException {
		while (scan.hasNext()) {
			n = scan.nextInt();
			int ans = 0;
			while (n-- > 0) {
				p = scan.nextInt();
				q = scan.nextInt();
				if (p < q) {
					p = p + q;
					q = p - q;
					p = p - q;
				}
				int count = 2;
				f[1] = p;
				f[2] = q;
				while (f[count] > 0) {
					f[count + 1] = f[count - 1] % f[count];
					count++;
				}
				int k = count - 2;
				int j = -1;
				for (int i = 1; i < count - 1; i++) 
					if (f[i] / f[i + 1] > 1) {
						if (j > 0 && i % 2 != j % 2)
							k++;
						j = i;
					}
				
				ans = Math.max(ans, k);
			}
			if ((ans & 1) == 1)
				out.println("MM");
			else
				out.println("GG");
		}
		out.flush();
		out.close();
	}
}