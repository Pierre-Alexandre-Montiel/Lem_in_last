#include "my_lemin.h"


void DFS(t_p **root, t_matrix *g , int src, int dest, bool *v, int *path, int pathLen, t_paths *p)
{
	if (src == dest)
	{
		//printf("SRC=DEST = %i %i\n", src, dest);
		nb++;

		/*for (int i = 0; i < pathLen; i++)
        {
            printf("%i -> ", path[i]);
        }
        printf("%i\n", dest);*/
		v[dest] = false;
		return;
	}
    //v[src] = true;
	v[src] = true;
    path[pathLen] = src;
    pathLen++;
    for (int i = 0; i < g->room_nums; i++) 
	{
        if (v[i] == false && g->m[src][i] == true) 
		{
            DFS(root, g, i, dest, v, path, pathLen, p);
        }
    }
	//printf("SOURCE = %i\n", src);
	v[src]= false;
    pathLen--;
}

int nbpaths(t_p **root, t_matrix *g, int src, int dest, bool *v, t_paths *p)
{
 	int *path = (int *)malloc(g->room_nums * sizeof(int));
    int pathLen = 0;
    for (int i = 0; i < g->room_nums; i++) 
	{
        if (i == src) 
		{
			//printf("SRC = %i\n", i);
			//printf("DEST = %i\n", dest);
			v[src] = true;
            DFS(root, g, src, dest, v, path, pathLen, p);
			//printf("NB value oput =		
        }

    }
	return nb;
}

void DFS_2(t_p **root, t_matrix *g , int src, int dest, bool *v, int *path, int pathLen, t_paths *p)
{
	if (src == dest)
	{
		//printf("SRC=DEST = %i %i\n", src, dest);
		int i = 0;
		//printf("LEN == %i ", len);
		//printf("LEN path == %i ", pathLen);
		p->paths[len] = (int *)malloc(sizeof(int) * pathLen + 1);
		while (i < pathLen)
		{
			p->paths[len][i] = path[i];
            printf("TAB = %i ", p->paths[len][i]);
			i++;
		}
		p->paths[len][i] = dest;
        printf("TAB = %i ", p->paths[len][i]);
        printf("\n");
		//[i] = '\0';
		//free
		v[dest] = false;
		len++;
		nb++;
		/*for (int j = 0; j < pathLen; j++)
            printf("TAB = %i\n", p->paths[nb][j]);*/
		return;
	}
    //v[src] = true;
	v[src] = true;
    path[pathLen] = src;
    pathLen++;
    for (int i = 0; i < g->room_nums; i++) 
	{
        if (v[i] == false && g->m[src][i] == true) 
		{
            DFS_2(root, g, i, dest, v, path, pathLen, p);
        }
    }
	//printf("SOURCE = %i\n", src);
	v[src]= false;
    pathLen--;
}

int nbpaths_2(t_p **root, t_matrix *g, int src, int dest, bool *v, t_paths *p)
{
 	int *path = (int *)malloc(g->room_nums * sizeof(int));
    int pathLen = 0;
    for (int i = 0; i < g->room_nums; i++) 
	{
        if (i == src) 
		{
			//printf("SRC = %i\n", i);
			//printf("DEST = %i\n", dest);
			v[src] = true;
            DFS_2(root, g, src, dest, v, path, pathLen, p);
			//printf("NB value oput =		
        }

    }
	return nb;
}