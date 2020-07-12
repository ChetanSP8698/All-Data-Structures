typedef struct node {
	char *str;
	struct node *prev, *next;
}node;

typedef struct list{
	node *p, *q;
} list;

void init(list *l);
void insert(list *l, char *str, int pos);
void traverse(list l);
list merge(list a, list b);
void reverse(list *l);
void appendright(list *, char *str);
void appendleft(list *, char *str);
char *removeright(list *);
char *removeleft(list *);
int length(list l);
void sort(list *l);
int search(list l, char *str);
void destroy(list *l);
list split(list *l);
