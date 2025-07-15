/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 04:36:58 by msariasl          #+#    #+#             */
/*   Updated: 2022/12/22 09:15:23 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int test_tlist(int *s) // LSTNEW
{
    int i = 0;
    t_list *head = NULL;
    head = (t_list *)malloc(sizeof(t_list));
    if (!head)
    {
        printf("\nMALLOC ERROR!\n");
        i--;
    }
    char *str = "MALLOC ALLOCATION FOR TEST PURPOSES ONLY";
    head->content = str;
    head->next = NULL;
    if (strcmp(head->content, "MALLOC ALLOCATION FOR TEST PURPOSES ONLY") == 0)
        i++;
    return i;
}

int test_lstnew(int *s) // LSTNEW
{
    int i = 0;
    t_list *mylist = ft_lstnew("THIS LIST IS AWESOME!");
    if (strcmp(mylist->content, "THIS LIST IS AWESOME!") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstaddfront(int *s) // LSTADDFRONT
{
    int i = 0;
    t_list *head = ft_lstnew("THIS LIST IS AWESOME!");
    t_list *l1 = ft_lstnew("LETS ADD MORE ITEM");
    ft_lstadd_front(&head, l1);
    if (strcmp(head->content, "LETS ADD MORE ITEM") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstsize(int *s) // LSTSIZE
{
    int i = 0;
    t_list *l1 = ft_lstnew("THIS LIST IS AWESOME!");
    l1->next = ft_lstnew("THIS LIST IS PERFECT!");
    ft_lstadd_back(&l1, ft_lstnew("THIS LIST IS LEGEND!"));
    int lst_len = ft_lstsize(l1);
    if (lst_len == 3)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstaddback(int *s) // LASTADDBACK
{
    int i = 0;
    t_list *head = ft_lstnew("THIS LIST IS AWESOME!");
    t_list *l1 = ft_lstnew("LETS ADD MORE ITEM..");
    ft_lstadd_back(&head, l1);
    if (strcmp(head->next->content, "LETS ADD MORE ITEM..") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstlast(int *s) // LSTLAST
{
    int i = 0;
    t_list *head = ft_lstnew("THIS LIST IS AWESOME!");
    ft_lstadd_back(&head, ft_lstnew("AAAAA"));
    ft_lstadd_back(&head, ft_lstnew("BBBBB"));
    ft_lstadd_back(&head, ft_lstnew("CCCCC"));
    t_list *last = ft_lstlast(head);
    if (strcmp(last->content, "CCCCC") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

static int is_deleted;
void del_one(void *x)
{
    t_list *head = x;
    if (strcmp(head->content, "Hell World.") == 0)
        is_deleted++;
    free(head->content);
}

int test_lstdelone(int *s) // DELONE (IN DEV.)
{
    int i = 0;
    t_list *head = ft_lstnew(ft_strdup("Hell World."));
    is_deleted = 0;
    ft_lstdelone((head), &del_one);
    if (is_deleted > 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

static int is_deleted_m;
void del_multiple(void *x)
{
    if (strcmp(x, "Air Blast"))
        is_deleted_m++;
    else if (strcmp(x, "Modern Clay"))
        is_deleted_m++;
    else if (strcmp(x, "Modern Clay"))
        is_deleted_m++;
    free(x);
}

int test_lstclear(int *s) // LSTCLEAR  (IN DEV.)
{
    int i = 0;
    t_list *head = ft_lstnew(ft_strdup("Air Blast"));
    t_list *next = ft_lstnew(ft_strdup("Modern Clay"));
    t_list *nextn = ft_lstnew(ft_strdup("City In the Air"));
    head->next = next;
    next->next = nextn;
    is_deleted = 0;
    ft_lstclear(&head, &del_multiple);
    if (is_deleted_m == 3)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

static int apply_count;
void apply(void *x)
{
    int i = 0;
    char *s = ft_strdup(x);
    char *c = (char *)malloc(strlen(x) * sizeof(char) + 1);
    if (!c)
    {
        printf("\nMALLOC ERROR!\n");
        apply_count--;
    }
    while (s[i] != 0)
    {
        c[i] = toupper(s[i]);
        i++;
    }
    if (strcmp(c, "AIR BLAST"))
        apply_count++;
    else if (strcmp(c, "MODERN CLAY"))
        apply_count++;
    else if (strcmp(c, "CITY IN THE AIR"))
        apply_count++;
}

int test_lstiter(int *s) // LSTITER (IN DEV.)
{
    int i = 0;
    t_list *head = ft_lstnew(ft_strdup("Air Blast"));
    t_list *next = ft_lstnew(ft_strdup("Modern Clay"));
    t_list *nextn = ft_lstnew(ft_strdup("City In the Air"));
    head->next = next;
    next->next = nextn;
    apply_count = 0;
    ft_lstiter(head, &apply);
    if (apply_count == 3)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

static int app_lie_count;
void *app_lie(void *x)
{
    int i = 0;
    char *s = ft_strdup(x);
    char *c = (char *)malloc(strlen(x) * sizeof(char) + 1);
    if (!c)
    {
        printf("\nMALLOC ERROR!\n");
        app_lie_count--;
    }
    while (s[i] != 0)
    {
        c[i] = toupper(s[i]);
        i++;
    }
    if (strcmp(c, "AIR BLAST"))
        app_lie_count++;
    else if (strcmp(c, "MODERN CLAY"))
        app_lie_count++;
    else if (strcmp(c, "CITY IN THE AIR"))
        app_lie_count++;
    return ((void *)c);
}

int test_lstmap(int *s) // LSTMAP (IN DEV.)
{
    int i = 0;
    t_list *head = ft_lstnew(ft_strdup("Air Blast"));
    t_list *next = ft_lstnew(ft_strdup("Modern Clay"));
    t_list *nextn = ft_lstnew(ft_strdup("City In the Air"));
    head->next = next;
    next->next = nextn;
    app_lie_count = 0;
    t_list *new_head = ft_lstmap(head, &app_lie, &del_multiple);
    if (ft_lstsize(new_head) == 3 && app_lie_count == 3)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

void TESTAREA() // CASUAL AREA
{
}

void HR()
{
    printf("\n\n#################################\n\n");
}

int main(void)
{
    int s = 0;
    printf("\n\n\n----> B O N U S ___ $ ___ P A R T <-----\n\n");
    HR();
    printf("0.  typdef t_list check: %d/1", test_tlist(&s));
    HR();
    printf("1.  lstNew successfully test count: %d/1", test_lstnew(&s));
    HR();
    printf("2.  lstAdd_front successfully test count: %d/1", test_lstaddfront(&s));
    HR();
    printf("3.  lstSize successfully test count: %d/1", test_lstsize(&s));
    HR();
    printf("4.  lstAdd_back successfully test count: %d/1", test_lstaddback(&s));
    HR();
    printf("5.  lstLast successfully test count: %d/1", test_lstlast(&s));
    HR();
    printf("6.  lstDelone successfully test count: %d/1  (IN DEV.)", test_lstdelone(&s));
    HR();
    printf("7.  lstClear successfully test count: %d/1  (IN DEV.)", test_lstclear(&s));
    HR();
    printf("8.  lstIter successfully test count: %d/1  (IN DEV.)", test_lstiter(&s));
    HR();
    printf("9.  lstMap successfully test count: %d/1  (IN DEV.)", test_lstmap(&s));
    HR();
    printf("SUCCESSFUL FUNCTION COUNT IN TOTAL: %d/9", s);
    HR();
    TESTAREA();
    return 0;
}

/*
IT CAN BE USABLE FOR BONUS PART AND NEXT PROJECTS
https://stackoverflow.com/questions/72118615/how-to-detect-if-a-block-of-memory-already-freed
*/