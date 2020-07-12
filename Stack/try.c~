/*#include "stack.h"
int main() {
	stack a;
	int i;
	init(&a);
	for(i = 0; i < 10; i++)
		push(&a, i);
	while(!isempty(&a))
		printf("%d\n", pop(&a));
}
#include <stdio.h>
#include "stack.h"
int main() {
    stack s;
    int i;
    init(&s);
    for(i = 0; i < 10; i++)
        if(i % 2 == 0) 
            push(&s, i + 1);
        if(i % 3 == 0) 
            push(&s, i);
    while(!isempty(&s))
        printf("%d\n", pop(&s));
    return 0;
}
*/
#include <stdio.h>
#include "stack.h"
int main() {
    stack s;
    int i;
    init(&s);
    for(i = 0; i < 4; i++)
        if(i % 2 == 0)  {
            push(&s, i + 1);
        }
        if(i % 3 == 0)  {
            push(&s, i);
            push(&s, i + 1);
            if(!isempty(&s))
                pop(&s);
            if(!isempty(&s))
                pop(&s);
        }
    while(!isempty(&s)) {
        push(&s, 8);
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
    }
    return 0;
}
