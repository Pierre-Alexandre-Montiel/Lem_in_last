#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_p
{
	int val;
    char *room;
    struct s_p *next;
    struct s_p *prev;
}              t_p;


void add_node_list(t_p **tree, int key)
{
    t_p *element = malloc(sizeof(t_p));
    if(!element) 
        exit(1);
    element->val = key;
    element->room = "r";
    element->next = *tree;
    *tree = element;
    element->prev = NULL;
}

void printTree_path(t_p *tree)
{
    while (tree != NULL)
    {
        printf("val = %i\n", tree->val);
        printf("room = %s\n", tree->room);
        tree = tree->next;
    }
}

int main()
{
    t_p *test[4];

    for (int i = 0; i <= 4; i++)
    {
        add_node_list(&test[i], 57);
        add_node_list(&test[i], 100);
        add_node_list(&test[i], 55);
        add_node_list(&test[i], 22);
        add_node_list(&test[i], 33);
        printTree_path(test[i]);
    }
}