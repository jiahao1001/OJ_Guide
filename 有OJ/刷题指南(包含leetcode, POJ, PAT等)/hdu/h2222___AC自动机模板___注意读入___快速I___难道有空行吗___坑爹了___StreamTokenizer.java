import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.LinkedList;

public class h2222___AC自动机模板___注意读入___快速I___难道有空行吗___坑爹了___StreamTokenizer {

	static class TreeNode {
		char ch;
		TreeNode[] link = new TreeNode[26];
		TreeNode fail = null;
		int number;

		public TreeNode() {
			this.fail = null;
			this.number = 0;
		}

		public TreeNode(char c) {
			this.ch = c;
		}

	}

	static class TrieTree {
		TreeNode root;
		LinkedList<TreeNode> q = new LinkedList<TreeNode>();

		public TrieTree() {
			root = new TreeNode();
			root.fail = null;
		}

		public void insert(String str) {
			TreeNode current = root;
			int ch;
			for (int i = 0; i < str.length(); i++) {
				ch = str.charAt(i) - 'a';
				if (current.link[ch] == null)
					current.link[ch] = new TreeNode(str.charAt(i));
				current = current.link[ch];
			}
			current.number++;
		}

		public void visit() {
			TreeNode current, fail;
			for (int i = 0; i < 26; i++)
				if (root.link[i] != null) {
					root.link[i].fail = root;
					q.add(root.link[i]);
				}
			while (!q.isEmpty()) {
				current = q.poll();
				for (int i = 0; i < 26; i++)
					if (current.link[i] != null) {
						fail = current.fail;
						while (fail != null && fail.link[i] == null)
							fail = fail.fail;
						if (fail == null)
							fail = root;
						else
							fail = fail.link[i];
						current.link[i].fail = fail;
						q.add(current.link[i]);
					}
			}
		}

		public int find(String str) {
			int len = str.length();
			int ret = 0;
			TreeNode current = root, temp;
			int ch;
			for (int i = 0; i < len; i++) {
				ch = str.charAt(i) - 'a';
				while (current.link[ch] == null && current != root)
					current = current.fail;
				current = current.link[ch];
				if (current == null)
					current = root;

				temp = current;
				while (temp != root) {
					if (temp.number > 0) {
						ret += temp.number;
						temp.number = 0;
					}
					temp = temp.fail;
				}
			}
			return ret;
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int turn = nextInt();
		String str;
		TrieTree tree;

		for (int tt = 1; tt <= turn; tt++) {
			tree = new TrieTree();
			int n = nextInt();
			for (int i = 1; i <= n; i++)
				tree.insert(next());
			tree.visit();

			str = next();
			out.println(tree.find(str));
		}
		out.flush();
		out.close();
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

	static float nextFloat() throws IOException {
		in.nextToken();
		return (float) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}
