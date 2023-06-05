#include "my_lemin.h"
#include "get_next_line.h"

t_matrix* create_matrix(int room_nums)
{
	t_matrix *g = malloc(sizeof(*g));
	if (g == NULL)
		return NULL;
	g->room_nums = room_nums;
	g->m = malloc(sizeof(bool*) * g->room_nums);
	for (int i = 0; i < g->room_nums; i++)
	{
		g->m[i] = malloc(sizeof(bool) * g->room_nums);
		if (g->m[i] == NULL)
		{
			free(g);
			return NULL;
		}
	}
	return g;	
}

int	ft_putstr(char *s)
{
    int res = 0;
	res = write(1, s, ft_strlen(s));
    return res;
}

int    print_map(char **stock)
{
    int i = 0;
    int res = 0;
    while (stock[i] != NULL)
    {
        ft_putstr(stock[i]);
        res = write(1, "\n", 1);
        i++;
    }
    return res;
}

void	print_matrix(t_matrix *g)
{
	printf("  0 ");
    for (int i = 1; i < g->room_nums; i++)
	    printf("%i ", i);
	printf("\n");
	for (int i = 0; i < g->room_nums; i++)
	{
		printf("%i ", i);
		for (int j = 0; j < g->room_nums; j++)
		{
			printf("%i ", g->m[i][j]);
		}
		printf("\n");
	}
}

bool add_link(t_matrix *g, int x, int y)
{
    //printf("%i, %i\n", x, y);
	g->m[x][y] = true;
	return true;
}

void addNode(t_node **tree, int key, char x, char y, char pos)
{
    t_node *tmpNode;
    t_node *tmpTree = *tree;

    t_node *elem = malloc(sizeof(t_node));
    elem->key = key;
    elem->x = x;
    elem->y = y;
    elem->pos = pos;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key)
        {
            tmpTree = tmpTree->right;
            if(!tmpTree)
            {
                tmpNode->right = elem;
            }
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) 
            {
                tmpNode->left = elem;
            }
        }
    }
    while(tmpTree);
    else  *tree = elem;
}

void addNode_path(t_p **tree, int key, char *room)
{
    t_p *element = malloc(sizeof(t_p));
    if(!element) 
        exit(1);
    element->val = key;
    element->room = room;
    element->next = *tree;
    *tree = element;
    element->prev = NULL;
}

void add_node_list(t_p **tree, int key)
{
    t_p *element = malloc(sizeof(t_p));
    if(!element) 
        exit(1);
    element->val = key;
    element->next = *tree;
    *tree = element;
    element->prev = NULL;
}

void addNode_store(t_store **tree, char *line)
{
    t_store *element = malloc(sizeof(t_store));
    if(!element) 
        exit(1); 
    element->line = line;
    element->prev = NULL;
    element->next = *tree;
    if (*tree != NULL) {
        (*tree)->prev = element;
    }
    *tree = element;
}

void printTree(t_node *tree)
{
    printf("PRINTTREE\n");
    if(!tree)
    {
        printf("return\n");
        return;
    }
    if(tree->left)
    {
        printf("left\n");
        printTree(tree->left);
    }
    printf("key = %i\n", tree->key);
    //printf("Coor x = %c\n", tree->x);
    //printf("Coor y = %c\n", tree->y);
    //printf("Pos = %c\n", tree->pos);
    if(tree->right)
    {
        printf("right\n");
        printTree(tree->right);
    }
}

void printTree_path(t_p *tree)
{
    while (tree != NULL)
    {
        printf("val = %i\n", tree->val);
        //printf("room = %s\n", tree->room);
        tree = tree->next;
    }
}

void    init_list_struct(t_p **solv, int len)
{
    int i = - 1;
    while (i++ < len)
        solv[i] = NULL;
}

int list_size(t_p *tree)
{
    int i = 0;
    while (tree != NULL)
    {

        //printf("treeval = %i\n",tree->val);
        tree = tree->next;
        i++;
    }
    return i;
}
/*void printt(t_p **tree)
{
    printf("CALL PRINT LIST\n");
    while ((*tree)->next != NULL)
    {
        printf("BEGIN PRINT LIST\n");
        printf("val = %i\n", (*tree)->val);
        printf("room = %s\n", (*tree)->room);
        tree = (*tree)->next;
    }
}*/



void print_store(t_store *store)
{
    while (store != NULL)
    {
        printf("store = %s\n", store->line);
        store = store->next;
    }
}

void print2D(t_node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2D(root->left, space);
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%i\n", root->key);
    print2D(root->right, space);
}

int isin(char *str, char c)
{
    int i= 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}


int find_node(t_node* root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
        return pos;
    find_node(root->left, key);
    find_node(root->right, key);
	pos++;
    return pos;
}

char *find_room_name(t_p *root, int key)
{
    if (root == NULL)
        return 0;
    while (root->next != NULL)
    {
        if (root->val == key)
            return root->room;
        root = root->next;
    }
    return NULL;
}

void find_rooms(t_node *root, char **stock, int room_num)
{
    int i = 1;
    while (stock[i] != NULL)
    {
        printf("%s\n", stock[i]);
        if (isin(stock[i], '-') == 0 && isin(stock[i], '#') == 0)
        {
            char **tmp = ft_split(stock[i], ' ');
            addNode(&root, i, tmp[1][0], tmp[2][0], 'm');
			room_num++;
        }
        i++;
    }
}

int find_val_room(t_p *rooms, char *str)
{
    while (rooms != NULL)
    {            
        //printf("ROOM name = %s ", rooms->room);
        //printf("ROOM name = %i\n", ft_strlen(rooms->room));
        //printf("STR = %s ", str);
        //printf("STR = %i\n", ft_strlen(str));
       // printf("strcmp = %i\n", ft_strcmp(str, rooms->room));  
        //int j = 0;
       /* while (rooms->room[j] != '\0')
        {
            printf("room c = %c\n", rooms->room[j]);
            j++;
        }
        j = 0;
        while (str[j] != '\0')
        {
            printf("str c = %c\n", str[j]);
            j++;
        }*/
        if (ft_strcmp(str, rooms->room) == 0)
        {
            //printf("VAL -> = %i\n", rooms->val);
            return rooms->val;
        }
        rooms = rooms->next;
    }
    return -1;
}

void    init_room_val(t_p *rooms)
{
    int i = 1;
    while (rooms != NULL)
    {
        if (rooms->val)
            rooms->val = i;
        rooms = rooms->next;
        i++;
    }
}

void find_links(t_p *rooms, t_matrix *g, t_store *store)
{
    //int i = 1;
    while (store != NULL)
	{
		if (isin(store->line, '-') == 1)
        {
            //printf("LINE -> %s\n", store->line);
            char **tiret = ft_split(store->line, '-');
          
           // printf("tiret0 = %s\n", tiret[0]);
           // printf("tiret1 = %s\n", tiret[1]);
            int x = find_val_room(rooms, tiret[0]);
            int y = find_val_room(rooms, tiret[1]);
            //printf("x = %i\n", x);
            //printf("y = %i\n", y);

           // printf("%i, %i\n", x, y);
            if (x >= 0 && y >= 0)
            {
            //    printf("ADD\n");
			    add_link(g, x, y);
			    add_link(g, y, x);
            }
        }
		//i++;
        store = store->next;
	}
}

void    pars_init(t_parsing *par)
{
    par->ants = false;
    par->rooms = false;
    par->start = false;
    par->end = false;
    par->empty = false;
}

void    paths_init(t_paths *p)
{
    p->paths = NULL;
}

int fill_rooms_start(t_parsing *par, t_p **rooms, t_store *store)
{
    int room_num = 0;
	while (store != NULL)
	{
		if (isin(store->line, '-') == 0 && isin(store->line, '#') == 1) 
		{
            //printf("START\n");
            //printf("LINE = %s\n", store->line);
            //printf("STRCMP = %i\n", ft_strcmp(store->line, "##start"));
            //printf("line = %s\n", store->line);
            //printf("len = %i\n", ft_strlen(store->line));
            //printf("len 2 = %i\n", ft_strlen("##start\0"));
            //for (int i = ft_strlen(store->line); i > 0; i--)
            //    printf("line[i] = %c\n", store->line[i]);
			if (ft_strcmp(store->line, "##start") == 0)
			{
				char **s = ft_split(store->prev->line, ' ');
				addNode_path(rooms, 0, s[0]);
                deleteNode(&store, store->prev);
                deleteNode(&store, store);
				room_num += 1;
                par->start = true;   
	            return room_num;
			}
        }
        store = store->next;
		//i++;
	}
	return room_num;
}

int fill_rooms_end(t_parsing *par, t_p **rooms, t_store *store)
{
    int room_num = 0;
	while (store != NULL)
	{
		if (isin(store->line, '-') == 0 && isin(store->line, '#') == 1) 
		{
			if (isin(store->line, 'e') == 1)
			{
				char **s = ft_split(store->prev->line, ' ');
				addNode_path(rooms, 1, s[0]);
                deleteNode(&store, store->prev);
                deleteNode(&store, store);
				room_num += 1;
                par->end = true;
	            return room_num;
			}
        }
        store = store->next;
		//i++;
	}
	return room_num;
}

void deleteNode(t_store** head, t_store* nodeToDelete)
{
    if (*head == NULL || nodeToDelete == NULL) {
        return;
    }

    // Cas où le nœud à supprimer est la tête de liste
    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
    }

    // Rétablir les liens des nœuds adjacents
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    free(nodeToDelete);
}

int tab_len(char **tab)
{
    int i = 0;
    while (tab[i] != NULL)
        i++;
    return i;
}

int fill_rooms(t_parsing *par, t_p **rooms, t_store *store)
{
    int room_num = 0;
	while (store != NULL)
	{
        if (isin(store->line, '-') == 0 && isin(store->line, '#') == 0)
        {
            char **tmp = ft_split(store->line, ' ');
            if (tab_len(tmp) == 3)
            {
			    addNode_path(rooms, 1, tmp[0]);
                //deleteNode(&store, store);
		        room_num += 1;
                par->rooms = true;
            }
        }
        store = store->next;
	}
	return room_num;
}

void storage(t_store **store)
{
    char *res;
	while ((res = get_next_line(STDIN_FILENO)))
    {
        char **tiret = ft_split(res, '\n');
	    addNode_store(store, tiret[0]);
    }
}

int nb_ants(t_store *store, t_parsing *par)
{
    int ants;

    ants = 0;
    /*while (store->next != NULL)
    {
        if (ft_strcmp(store->line, "##start") == 0)
            break;
        store = store->next;
    }
    store = store->next;*/
    while (store != NULL)
    {
        //char **tmp = ft_split(store->line, ' ');
        printf("LINE len = %i\n", ft_strlen(store->line));
        printf("LINE = %s\n", store->line);
        if (ft_strlen(store->line) == 1 && isin(store->line, '#') == 0)
        {
            ants = atoi(store->line);
            deleteNode(&store, store);    
            par->ants = true;
            return ants;
        }
        store = store->next;
    }
    return ants;
}

int nb_adj(t_matrix *g, int val)
{
    int res;

    res = 0;
    for (int i = 0; i < g->room_nums; i++)
    {
        if (g->m[val][i] == 1)
            res++;
    }
    return res;
}


int shortest_path_index(t_p **p, int nb_ways, int size, int dest)
{
    int i;
    int s;
    int tmp;

    i = 1;
    s = 0;
    printf("nb ways = %i\n", nb_ways);
    printf("size = %i\n", dest);
    tmp = list_size(p[0]);
    while (i < size)
    {
        if (tmp > list_size(p[i]))
            s = i;
        i++;
    }
    if (s > 0)
        s -= 1;
    return s;
}

int already(t_p *src, int c)
{
    int i= 0;
    while (src[i] != dest)
    {
        if (src[i] == c)
            return 1;
        i++;
    }
    return 0;
}

bool    path_comp(t_p *src1, t_p *src2)
{
    int i = 0;
    int j = 0;

    while (src1->val == src2->val)
    {
        src1 = src1->next;
        src2 = src2->next;
    }
    while (src1[i] != dest)
    {
        if (already(src2, src1[i]) == 1)
            return false;
        i++;
    }
    return true;
}

/*void all_shortest_paths(t_paths *p, int nb_ways, int size, int dest, t_p *sol)
{
    int i;
    int s;
    int index;

    i = 0;
    s = 0;
    index = 0;

    s = shortest_path_index(p, nb_ways, size, dest);
    while (i < size)
    {
        if (i != s)
        {
            bool res = path_comp(p->paths[i], p->paths[i + 1], dest);
            if (res == true)
            {
                printf("SOL = %s", sol->room);
            }
        }
        i++;
    }
}*/

int ants_vs_paths(int ants, int nb_ways)
{
    if (ants % nb_ways == 0)
        return ants;
    return -1;
}
