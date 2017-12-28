import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h1849___ˮSG {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;

	public static void main(String[] args) throws IOException {
		while (true) {
			n = scan.nextInt();
			if (n == 0)
				break;
			int ans = 0;
			for (int i = 1; i <= n; i++)
				ans ^= scan.nextInt();
			if (ans > 0)
				out.println("Rabbit Win!");
			else
				out.println("Grass Win!");
		}
		out.flush();
		out.close();
	}

}