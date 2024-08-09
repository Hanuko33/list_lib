#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main()
{
    struct List * list = List_create();
    char variable[10];

    strncpy(variable, "Hello wor\0", 10);
    list->var = variable;

    printf("Hello wor = %s\n", (const char *)list->var);
    assert(!strcmp("Hello wor\0", (const char *)list->var));
    
    char variable_2[10];
    strncpy(variable_2, "Hello now\0", 10);

    List_new_next(list, variable_2);

    struct List * next = List_next(list, 1);

    if (next)
    {
        printf("Hello now = %s\n", (const char *)next->var);
        assert(!strcmp("Hello now\0", (const char *)next->var));
    }

    printf("Hello wor = %s\n", (const char *)list->var);
    assert(!strcmp("Hello wor\0", (const char *)list->var));

    printf("Hello wor = %s\n", (const char *)(List_previous(next, 1)->var));
    assert(!strcmp("Hello wor\0", (const char *)(List_previous(next, 1)->var)));

    if (List_search(list, variable_2))
    {
        printf("Hello now = %s\n", (const char *)(List_search(list, variable_2)->var));
        assert(!strcmp("Hello now\0", (const char *)(List_search(list, variable_2)->var)));
    }

    int * variable_3 = malloc(sizeof(int));
    *variable_3 = 5;
    List_append(list, variable_3);

    if (List_search(list, variable_3))
    {
        printf("5 = %ld\n", *(long *)(List_search(list, variable_3)->var));
        assert(5 == *(long *)(List_search(list, variable_3)->var));
    }

    List_delete(List_search(list, variable_2));
    printf("Hello wor = %s\n", (const char *)list->var);
    assert(!strcmp("Hello wor\0", (const char *)list->var));

    printf("5 = %ld\n", *(long *)(list->next->var));
    assert(5 == *(long *)(list->next->var));
}
