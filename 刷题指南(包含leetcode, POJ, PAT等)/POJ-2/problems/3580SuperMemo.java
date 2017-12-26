import java.util.*;
class Node{
    public int value;
    public int size;
    public int rev;
    public int min;
    public int add;
    public Node parent, left, right;
    public Node(int value, Node parent){
        this.value = value;
        this.min = value;
        this.size = 1;
        this.parent = parent;
    }
}
class Splay{
    public Node root;
    public void insert(int x){
        if(root==null){
            root = new Node(x,null);
            return;
        }
        root.right = new Node(x,root);
        splay(root.right,null);
    }
    public int size(Node x){
        if(x==null) return 0;
        else return x.size;
    }
    public void pushDown(Node x){
        if(x.add!=0){
            if(x.left!=null) {
                x.left.value += x.add;
                x.left.add+=x.add;
                x.left.min += x.add;
            }
            if(x.right!=null) {
                x.right.value += x.add;
                x.right.add+=x.add;
                x.right.min+=x.add;
            }
            x.add = 0;
        }
        if(x.rev==1){
            Node t = x.left;
            x.left = x.right;
            x.right = t;
            if(x.left!=null) x.left.rev ^= 1;
            if(x.right!=null) x.right.rev ^=1;
            x.rev = 0;
        }


    }
    public void rotate(Node x,boolean left){
        Node y = x.parent;
        pushDown(y);
        pushDown(x);
        x.parent = y.parent;
        if(x.parent==null) root=x;
        else if(x.parent.left==y) x.parent.left=x;
        else x.parent.right =x;
        y.parent = x;
        Node t = null;
        if(left) {
            t = x.right;
            x.right = y;
            y.left = t;
        }
        else{
            t=x.left;
            x.left=y;
            y.right=t;
        }
        if(t!=null) t.parent=y;
        update(y);

    }
    public void splay(Node x,Node y){
        while(x.parent!=y){
            if(x.parent.parent!=y){
                if((x.parent.left==x)^(x.parent.parent.left == x.parent))
                    rotate(x,x.parent.left==x);
                else rotate(x.parent,x.parent.parent.left == x.parent);
            }
            rotate(x,x.parent.left==x);
        }
        update(x);
    }
    public void update(Node x){
        x.size = 1+size(x.left) + size(x.right);
        x.min = x.value;
        if(x.left!=null) x.min = Math.min(x.min,x.left.min);
        if(x.right!=null) x.min = Math.min(x.min,x.right.min);

    }
    public Node select(int k){
        if(k>size(root)) throw new RuntimeException();
        Node t = root;
        while(true){
            pushDown(t);
            if(1+size(t.left)==k) return t;
            else if(1+size(t.left)<k){
                k -= (1+size(t.left));
                t = t.right;

            }else{
                t = t.left;
            }
        }
    }

    public void add(int l,int r,int d){
        Node x = select(l);
        splay(x,null);
        Node y = select(r);
        splay(y,x);
        if(y.left!=null) {
            y.left.value += d;
            y.left.add += d;
            y.left.min += d;
        }

    }
    public int getMin(int l,int r){
        Node x = select(l);
        splay(x,null);
        Node y = select(r);
        splay(y,x);
        return y.left.min;
    }
    public void reverse(int l,int r){
        Node x = select(l);
        splay(x,null);
        Node y = select(r);
        splay(y,x);
        if(y.left!=null)
            y.left.rev ^= 1;

    }
    public void insert(int l,int r,int xx){
        Node x = select(l);
        splay(x,null);
        Node y = select(r);
        splay(y,x);
        y.left = new Node(xx,y);
        splay(y.left,null);
    }
    public void erase(int l,int r){
        Node x = select(l);
        splay(x,null);
        Node y = select(r);
        splay(y,x);
        y.left = null;
        splay(y,null);
    }
}
public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        Splay splay = new Splay();
        splay.insert(Integer.MAX_VALUE);
        for(int i=0;i<n;i++){
            int x = cin.nextInt();
            splay.insert(x);
        }
        splay.insert(Integer.MAX_VALUE);
        int m = cin.nextInt();
        cin.nextLine();
        for(int i=0;i<m;i++){
            String line = cin.nextLine();
            String[] parts = line.split(" ");
            if(parts[0].equals("ADD")){
                int l = Integer.parseInt(parts[1]);
                int r = Integer.parseInt(parts[2]);
                int x = Integer.parseInt(parts[3]);
                splay.add(l,r+2,x);
            }else if(parts[0].equals("MIN")){
                int l = Integer.parseInt(parts[1]);
                int r = Integer.parseInt(parts[2]);
                System.out.println(splay.getMin(l,r+2));
            }else if(parts[0].equals("REVERSE")) {
                int l = Integer.parseInt(parts[1]);
                int r = Integer.parseInt(parts[2]);
                splay.reverse(l,r+2);
            }else if(parts[0].equals("INSERT")) {
                int l = Integer.parseInt(parts[1]);
                int x = Integer.parseInt(parts[2]);
                splay.insert(l + 1, l + 2, x);
            }
            else if(parts[0].equals("DELETE")) {
                int l = Integer.parseInt(parts[1]);
                splay.erase(l,l+2);
            }else if(parts[0].equals("REVOLVE")) {
                int l = Integer.parseInt(parts[1]);
                int r = Integer.parseInt(parts[2]);
                int T = Integer.parseInt(parts[3]);
                int len = r-l+1;
                T %= (r-l+1);
                splay.reverse(l,l+len-T+1);
                splay.reverse(r+1-T,r+2);
                splay.reverse(l,r+2);
            }
        }
    }
}
