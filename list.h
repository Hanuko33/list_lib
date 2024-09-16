#ifndef LIST_H
#define LIST_H
typedef struct List
{
    struct List * next;
    struct List * previous;
    void * var;
} List;

List * List_create();
void List_new_next(List* list, void * var);
void List_append(List * list, void * var);
void List_append_left(List * list, void * var);
void List_delete(List * list);
List * List_next(List* list, int index);
List * List_previous(List* list, int index);
List * List_next_search(List* list, void * var);
List * List_previous_search(List* list, void * var);
List * List_search(List * list, void * var);

#endif
