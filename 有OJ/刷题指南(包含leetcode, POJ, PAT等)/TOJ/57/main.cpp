#include <bits/stdc++.h>
using namespace std;

int p, n, m;
unordered_set<string> q[2];
void bfs(int cnt)
{
    if (cnt > m)
        return;

    for (string backup : q[(cnt + 1) & 1]) {
        for (int i = 0; i < n; i++) {
            string inp = backup;
            for (int j = i; j < p; j += (i + 1)) {
                inp[j] = inp[j] == '1' ? '0' : '1';
            }
            if (q[cnt & 1].find(inp) != q[cnt & 1].end())
                continue;
            q[cnt & 1].insert(inp);
        }
    }
    q[(cnt + 1) & 1].clear();
    bfs(cnt + 1);
}

typedef struct node {
    struct node *left, *right;
} Node;

Node *create_node()
{
    Node *curr = (Node *)malloc(sizeof(Node));
    curr->left = NULL;
    curr->right = NULL;

    return curr;
}

void trie_push(Node *head, string inp)
{
    // printf("trie_push inp %s\n", inp.c_str());
    // printf("i = 0 %p\n", head);

    for (int i = 0; i < p; i++) {
        if (inp[i] == '0') {
            if (head->left == NULL) {
                head->left = create_node();
            }
            head = head->left;
        } else {
            if (head->right == NULL) {
                head->right = create_node();
            }
            head = head->right;
        }
        // printf("i = %d %p\n", i + 1, head);
    }
    // printf("%p %p\n", head->left, head->right);
}

/*
string path;
void print_trie(Node *head, int depth)
{
    printf("%d %d %s\n", depth, p, path.c_str());
    if (depth == p) {
        printf("Here!\n");
        printf("%s\n", path.c_str());
        return;
    }

    if (head->left != NULL) {
        path[depth] = '0';
        print_trie(head->left, depth + 1);
    }

    if (head->right != NULL) {
        path[depth] = '1';
        print_trie(head->right, depth + 1);
    }
}
*/
char path[20010];
void print_trie(Node *head, int depth)
{
    // printf("%d %d %s\n", depth, p, path);
    if (depth == p) {
        printf("%s\n", path);
        return;
    }

    if (head->left != NULL) {
        path[depth] = '0';
        print_trie(head->left, depth + 1);
    }

    if (head->right != NULL) {
        path[depth] = '1';
        print_trie(head->right, depth + 1);
    }
}

void clear_trie(Node *head)
{
    if (head->left != NULL) {
        clear_trie(head->left);
    }
    if (head->right != NULL) {
        clear_trie(head->right);
    }

    free(head);
    return;
}

int main()
{
    bool first = true;
    while (scanf("%d %d %d", &p, &n, &m) == 3 && (p || n || m)) {
        if (first)
            first = false;
        else
            printf("\n");

        q[0].clear();
        q[1].clear();
        string orig;
        for (int i = 0; i < p; i++)
            orig += "1";

        q[0].insert(orig);
        bfs(1);
        /*
        // TLE
        vector<string> ans;
        for (string i : q[m & 1])
            ans.push_back(i.c_str());

        sort(ans.begin(), ans.end());

        for (int i = 0; i < (int)ans.size(); i++)
            printf("%s\n", ans[i].c_str());
        */

        // Make trie
        Node *head = create_node();
        for (string i : q[m & 1]) {
            trie_push(head, i);
        }

        // path.clear();
        memset(path, 0, sizeof(path));
        print_trie(head, 0);
        clear_trie(head);
    }
    return 0;
}
