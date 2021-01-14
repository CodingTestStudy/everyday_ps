#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int findN(Node* root, int target,bool ok) {
    if (ok) {
        int cnt = 0;
        if (root->left != nullptr)cnt++;
        if (root->right != nullptr)cnt++;
        return cnt;
    }
    if (root->data == target) {
        return findN(root, target, 1);
    }
    else if (root->data > target) {
        if (root->left == nullptr)return -1;
        return findN(root->left, target, 0);
    }
    else
    {
        if (root->right == nullptr)return -1;
        return findN(root->right, target, 0);
    }
}
Node* insert(Node* root, int data) {

    if (root == nullptr)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;

}
int degree(Node* root, int target, int cnt) {
    if (root->data == target) {
        return cnt;
    }
    if (root->data > target) {
        return degree(root->left, target, cnt + 1);
    }
    if (root->data < target) {
        return degree(root->right, target, cnt + 1);
    }
    return cnt;
}
Node* root;

int main() {
    fastio;
    int n; cin >> n;
    while (n--) {
        root = nullptr;
        int num; cin >> num;
        for (int i = 0; i < num; i++) {
            int a; cin >> a;
            root = insert(root, a);
        }
        cin >> num;
        for (int i = 0; i < num; i++) {
            int a; cin >> a;
            if (findN(root, a, 0) == -1)cout << "0" << "\n";
            else cout << findN(root, a, 0) <<" "<< degree(root, a,0) << "\n";
        }
    }
    return 0;
}
