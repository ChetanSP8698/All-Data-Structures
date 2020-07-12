typedef struct node {
	/* The data will be stored in malloced memory
	 * and 'str' will point to it
	 */
	char *str;
	struct node *left, *right;
}node;

typedef node *tree;

void tinit(tree *t);
int depth(tree t);
int count(tree t);
void insert(tree *t, char *str);
tree copy(tree t);
void remov(tree *t, char *str);
void preorder(tree t);
void inorder(tree t);
void postorder(tree t);
tree mirror(tree t);
void levelwise(tree t);
void print(tree t);
char *max(tree t);
void preorder_norecur(tree t);
char *search(tree t, char *str);
void printtree(tree t);