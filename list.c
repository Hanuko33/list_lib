#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List * List_create()
{
    List * list = malloc(sizeof(List));

    list->var=NULL;
    list->next=NULL;
    list->previous=NULL;

    return list;
}

void List_new_next(List* list, void * var)
{
    list->next = List_create();
    list->next->previous = list;
    list->next->var = var;
}

void List_delete(List* list)
{
    if (list->previous && list->next)
    {
        List * previous = list->previous;
        List * next = list->next;
        next->previous = previous;
        previous->next = next;
    }
    else if (!list->next && list->previous)
        list->previous->next = NULL;
    else if (!list->previous && list->next)
        list->next->previous = NULL;

    list->next=NULL;
    list->previous=NULL;
    free(list);
    list = NULL;
}

void List_append(List * list, void * var)
{
    List * current = list;
    for (int i = 0;; i++)
    {
        if (current->next)
            current=current->next;
        else 
            break;
    }

    current->next = List_create();
    current->next->previous = current;
    current->next->var = var;
}

void List_append_left(List * list, void * var)
{
    List * current = list;
    for (int i = 0;; i++)
    {
        if (current->previous)
            current=current->previous;
        else 
            break;
    }

    current->previous = List_create();
    current->previous->next = current;
    current->previous->var = var;
}


List * List_next(List* list, int index)
{
    List * current = list;
    for (int i = 0; i < index; i++) 
    {
        if (current->next)
        {
            current = current->next;
        }
        else 
        {
            return NULL;
        }
    }
    return current;
}

List * List_previous(List* list, int index)
{
    List * current = list;
    for (int i = 0; i < index; i++) 
    {
        if (current->previous)
        {
            current = current->previous;
        }
        else 
        {
            return NULL;
        }
    }
    return current;
}

List * List_next_search(List* list, void * var)
{
    List * current = list;
    for (int i = 0;; i++) 
    {
        if (!current)
        {
            return NULL;
        }
        if (current->var && current->var == var)
        {
            break;
        }
        if (current->next)
        {
            current = current->next;
        }
        else 
        {
            return NULL;
        }
    }
    return current;
}

List * List_previous_search(List* list, void * var)
{
    List * current = list;
    for (int i = 0;; i++) 
    {
        if (!current)
        {
            return NULL;
        }
        if (current->var && current->var == var)
        {
            break;
        }
        if (current->previous)
        {
            current = current->previous;
        }
        else 
        {
            return NULL;
        }
    }
    return current;
}

List * List_search(List * list, void * var)
{
    if (List_previous_search(list, var))
        return List_previous_search(list, var);
    else if (List_next_search(list, var))
        return List_next_search(list, var);
    else
        return NULL;
}

