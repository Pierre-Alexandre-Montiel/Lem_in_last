#ifndef MY_LEMIN_H_
# define MY_LEMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COUNT 10

int pos;
int nb;
int len;

typedef struct  s_matrix
{
    int room_nums;
	bool **m;
}		            t_matrix;

typedef struct  s_paths
{
    int** paths;
}		            t_paths;

typedef struct s_parsing
{
	bool start;
	bool end;
	bool ants;
	bool rooms;
	bool empty;
}	             t_parsing;

typedef struct s_node
{
	int val;
    char pos;
    int key;
    char x;
    char y;
    int *neighboors;
    struct s_node *left;
    struct s_node *right;
}              t_node;

typedef struct s_p
{
	int val;
    char *room;
    struct s_p *next;
    struct s_p *prev;
}              t_p;

typedef struct s_store
{
	char   *line;
    struct s_store *next;
    struct s_store *prev;
}              t_store;

int	ft_putstr(char *s);
int	ft_strcmp(char *s1, char *s2);
int ft_strlen(const char *str);
int	ft_strlen_int(int *theString, int dest);
int		count_word(const char *str, char c);
char		*tab_malloc(const char *str, char c);
char	**ft_split(char const *s, char c);
t_matrix* create_matrix(int room_nums);
void	print_matrix(t_matrix *g);
bool add_link(t_matrix *g, int x, int y);
void addNode(t_node **tree, int key, char x, char y, char pos);
void addNode_path(t_p **tree, int key, char *room);
void printTree(t_node *tree);
void printTree_path(t_p *tree);
void print2D(t_node* root, int space);
int isin(char *str, char c);
int find_node(t_node* root, int key);
void DFS(t_p **root, t_matrix *g , int src, int dest, bool *v, int *path, int pathLen, t_paths *p);
int nbpaths(t_p **root, t_matrix *g, int src, int dest, bool *v, t_paths *p);
void DFS_2(t_p **root, t_matrix *g , int src, int dest, bool *v, int *path, int pathLen, t_p **sol);
int nbpaths_2(t_p **root, t_matrix *g, int src, int dest, bool *v, t_p **sol);
void find_rooms(t_node *root, char **stock, int room_num);
void find_links(t_p *rooms, t_matrix *g, t_store *store);
int fill_rooms_start(t_parsing *par, t_p **rooms, t_store *store);
int fill_rooms_end(t_parsing *par, t_p **rooms, t_store *store);
int fill_rooms(t_parsing *par, t_p **rooms, t_store *store);
int    print_map(char **stock);
void    pars_init(t_parsing *par);
void    paths_init(t_paths *p);
void    init_room_val(t_p *rooms);
void    storage(t_store **store);
void addNode_store(t_store **tree, char *line);
void print_store(t_store *store);
int nb_ants(t_store *store, t_parsing *par);
void deleteNode(t_store** head, t_store* nodeToDelete);
int tab_len(char **tab);
int nb_adj(t_matrix *g, int val);
void all_shortest_paths(t_paths *p, int nb_ways, int size, int dest, t_p *sol);
int shortest_path_index(t_p **p, int nb_ways, int size, int dest);
int ants_vs_paths(int ants, int nb_ways);
char *find_room_name(t_p *root, int key);
bool    path_comp(int *src1, int *src2, int dest);
int already(int *src, int c, int dest);
void add_node_list(t_p **tree, int key);
//void printt(t_p **tree);
int list_size(t_p *tree);
void    init_list_struct(t_p **solv, int len);
#endif