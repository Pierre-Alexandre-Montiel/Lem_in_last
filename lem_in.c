#include "my_lemin.h"
#include "get_next_line.h"

int main()
{
    //##### Init ########

	t_parsing par;
    pars_init(&par);
    //t_node *root = NULL;
    t_p *path = NULL;
    t_p *rooms = NULL;
    //t_p *sol = NULL;
    t_store *store = NULL;
    t_paths all;
    paths_init(&all);
    len = 0;

    //####### Parsing STDIN ########
    storage(&store);
    //print_store(store);
    printf("#########\n");
	//gestion d'erreur input a prevoir
    int ants = nb_ants(store, &par);
    printf("ANTS = %i\n", ants);
    int room_num = 0;
    room_num += fill_rooms_start(&par, &rooms, store);
    printf("#########\n");
    room_num += fill_rooms_end(&par, &rooms, store);
    printf("#########\n");
    room_num += fill_rooms(&par, &rooms, store);
    init_room_val(rooms);
    //###### Neighboor matrice #######
	t_matrix *g = create_matrix(room_num);
    find_links(rooms, g, store);
	print_matrix(g);
    int dest = nb_adj(g, room_num - 1);
    printf("RES = %i\n", dest);
    printf("RoomNUM = %i\n", room_num);
//	int p = find_node(root, 0);
//	printf("%i \n", p);

    //###### DFS #######
    bool *visited = malloc(sizeof(bool) * room_num);
	int res = 0;
	res = nbpaths(&path, g, 0, room_num - 1, visited, &all);
    if (res <= 0)
    {
        exit(1);
    }
	printf("NB of paths = %i\n", res);
    t_p *roads[res];
    init_list_struct(roads, res);
    //all.paths = (int **)malloc(sizeof(int*) * res + 1);
	res = nbpaths_2(&path, g, 0, room_num - 1, visited, roads);
    printf("[DEST] = %i\n", dest);
    res = res / 2;
    /*for (int i = 0; i < res; i++)
    {
        printf("strlen = %i \n", ft_strlen_int(all.paths[i], room_num - 1));
        for (int j = 0; j < ft_strlen_int(all.paths[i], room_num - 1); j++)
            printf("node -> %i ", all.paths[i][j]);
        printf("\n");
    }*/
	printf("end\n");
	printf("NB of paths = %i\n", res);
    //printf("path val = %i\n", path->val);
	printf("#########\n");
    //int nb_paths = ants / res;
	//printf("Rapport Ants / Rooms = %i\n", nb_paths);
	//printf("NB of paths = %i\n", res);

    //####### Processing ########    
    // PEUT ETRE FAIRE UNE MATRICE DE CORRESPONDANCE POUR LES VALEUR ET LES NOM DES ROOMS

    //int index = shortest_path_index(roads, dest, res, room_num - 1);
   // printTree_path(roads[index]);
    t_p *out = all_shortest_paths(roads, dest, res, room_num - 1);
    int nb_sol = list_size(out);    
    int p = ants_vs_paths(ants, nb_sol);
    printf("P = %i\n", p);
    printf("NB Solutions paths = %i\n", nb_sol);
    printf("Good Index Paths = ");
    printTree_path(out);
    printf("\n");
    reverse_paths(roads, out);
    //####### Print Output #######
    //char *test = find_room_name(rooms, roads[0]->val);
    //printf("TEST = %s\n", test);
    int max = max_len(roads, &out);
    printf("MAX = %i\n", max);
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < p; j++)
        {
                if (roads[j] != NULL)
                {
                    printf("L%i-%i ", j + 1, roads[j]->val);
                    roads[j] = roads[j]->next;
                }
        }
        printf("\n");
    }
    /*for (int i = 0; i < p; i++)
        printf("solutions = %i\n", solve[i]);*/
    return (0);
}