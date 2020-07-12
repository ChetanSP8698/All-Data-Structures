#include <stdio.h>
/*
 Function Pointers. 

 Function pointer is a pointer.
 It is a variable (not a function), like int i.
 It can store address of a function. (the address of the code of the function in memory)
 Dereferncing a function pointer is possible using ()
 Derefrencing a function pointer, will call the function it is pointing to. 

 Function pointer has a type : signature of the function
 */
void h(int (*gp) (int), int n) {
	printf("%d\n", gp(n));
}
int g(int y) {
	return y + 5;
}
int f(int x) {
	return x + 2;
}
int main() {
	int n;
	int (*fp)(int);
	scanf("%d", &n);
	fp = f;
	h(fp, n);
	fp = g;
	h(fp, n);
	h(f, n);
	h(g, n);
	return 0;	
}
