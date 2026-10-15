
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* insert(struct node *r, int x) {
    if (r == NULL) {
        r = malloc(sizeof(struct node));
        r->data = x;
        r->left = r->right = NULL;
    } else if (x < r->data)
        r->left = insert(r->left, x);
    else if (x > r->data)
        r->right = insert(r->right, x);
    return r;
}
void inorder(struct node *r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}
struct node* minNode(struct node *r) {
    while (r->left != NULL)
        r = r->left;
    return r;
}
struct node* deleteNode(struct node *r, int x) {
    if (r == NULL)
        return NULL;
    if (x < r->data)
        r->left = deleteNode(r->left, x);
    else if (x > r->data)
        r->right = deleteNode(r->right, x);
    else {
        if (r->left == NULL) {
            struct node *temp = r->right;
            free(r);
            return temp;
        }
        if (r->right == NULL) {
            struct node *temp = r->left;
            free(r);
            return temp;
        }
        struct node *temp = minNode(r->right);
        r->data = temp->data;
        r->right = deleteNode(r->right, temp->data);
    }
    return r;
}
int main() {
    struct node *root = NULL;
    int n, x, key, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder before deletion: ");
    inorder(root);
    printf("\nEnter node to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("Inorder after deletion: ");
    inorder(root);
    return 0;
}
