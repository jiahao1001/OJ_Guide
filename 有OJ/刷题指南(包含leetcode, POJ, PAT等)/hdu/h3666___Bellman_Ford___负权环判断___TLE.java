import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;

public class h3666___Bellman_Ford___¸ºÈ¨»·ÅÐ¶Ï___TLE {
    static BufferedReader br = new BufferedReader(new InputStreamReader(
            System.in));
    static StreamTokenizer in = new StreamTokenizer(br);
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static int n, m, l, u, limit = 10010, adj[][], cnt;
    static double dis[];
    static p3666___path edge[];

    public static void main(String[] args) throws IOException {
        while (in.nextToken() != in.TT_EOF) {
            n = (int) in.nval;
            m = nextInt();
            l = nextInt();
            u = nextInt();
            adj = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    adj[i][j] = nextInt();
            cnt = -1;
            edge = new p3666___path[2 * n * m + 1];
            cnt++;
            edge[cnt] = new p3666___path(0, 1, 0);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cnt++;
                    edge[cnt] = new p3666___path(j + n, i, Math.log(u)
                            - Math.log(adj[i][j]));
                    cnt++;
                    edge[cnt] = new p3666___path(i, j + n, Math.log(adj[i][j])
                            - Math.log(l));
                }
            }
            System.out.println(Bellman_Ford());

        }
        out.flush();
        out.close();
    }

    static String Bellman_Ford() {
        dis = new double[m + n + 1];
        Arrays.fill(dis, limit);
        dis[0] = 0;

        for (int j = 1; j < m + n; j++) {
            for (int i = 0; i <= cnt; i++) {
                if (dis[edge[i].v] > dis[edge[i].u] + edge[i].val)
                    dis[edge[i].v] = dis[edge[i].u] + edge[i].val;
            }
        }

        for (int i = 0; i <= cnt; i++)
            if (dis[edge[i].v] > dis[edge[i].u] + edge[i].val) {
                System.out.println(edge[i].val);
                return "NO";
            }

        return "YES";
    }

    static String next() throws IOException {
        in.nextToken();
        return in.sval;
    }

    static double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }

    static int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

}

class p3666___path {
    int u, v;
    double val;

    p3666___path(int u, int v, double len) {
        this.u = u;
        this.v = v;
        this.val = len;
    }
}
