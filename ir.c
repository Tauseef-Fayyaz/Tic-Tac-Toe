#include <time.h>
#include "Iris.h"
#include "Map.h"

#define color(param) printf("\033[%sm",param)

data_t* load_data_file(int lengh, int size_db, const char* file_name){

	FILE *file; 
	file = fopen(file_name,"r"); 
	data_t *data; 
	data = (data_t *)malloc(sizeof(data_t)*(size_db));
	char *token = NULL;
	char *str, *tok=NULL, *tmp = NULL;
	size_t l;
	size_t r;
	int nb_line = 0, nb_fields = 0;
	double *vect, norm = 0.0f;

	while((r = getline (&str,&l,file))!= -1 && nb_line < size_db){
			token = str;
			
			data[nb_line].v = (double *) malloc(lengh * sizeof(double));
			vect = data[nb_line].v;
			nb_fields = 0;
			norm = 0.0f;
			for (tok = token; nb_fields < lengh; tok = NULL)
			{
				token = strtok(tok, ",");
				
				if (token != NULL && nb_fields < lengh-1)
				{
					vect[nb_fields] = strtod(token, &tmp);
					norm += vect[nb_fields] * vect[nb_fields];
					tmp = NULL;
				}
				else
				{
					
					data[nb_line].norm = sqrt(norm);
					normalization(data[nb_line].v, lengh, data[nb_line].norm);
					
					if(token)
					{
					token[strlen(token) - 1] = '\0';
					data[nb_line].nom_espece = strdup(token);
					}
					
				}	
				nb_fields++;
			}
			nb_line++;
		}
	return data;
}


void display(data_t *data,int length, int size_db){
	int i; 
	int j;
	for(i = 0; i < size_db; i++){
		printf("%s ",data[i].nom_espece);
		for(j = 0; j < length; j++){
			printf("%f ",data[i].v[j]);
		}
		printf("\n \n");
	}
}

void normalization(double *v, int length, double norm){
	int i;
	for(i = 0; i < length; i++){
		v[i] /= norm;
	}
}

double *average(data_t *data,int length, int size_db){
	double *aver = calloc (length, sizeof * aver); // reintialiser tt a zero 
	int i, j;
	for (i = 0; i < size_db; ++i){ // parcours les donner 
		for (j = 0; j < length; ++j){ // parcours le vecteur 
			aver[j] += data[i].v[j];
		}


		for (j = 0; j < length; ++j){
			aver[j] /= size_db;
		}		
	}
	return aver;
}


double m_random(double min,double max){
	double r = 0.0;
	r = (double)rand()/(double)RAND_MAX *(max - min) + min;
	return r;
}


void shuffle (int *tab, int nb_line){
	int tmp;
	int i;
	int j;

	for(i = (nb_line - 1); i > 1 ; i--){ 

		j = rand()%i;
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;		
	}
}

int* generate_table(int size_db){
	int *tab = malloc(sizeof(int)*size_db);
	for(int i = 0; i < size_db;i++){
		tab[i] = i;
	}
	return tab;
}

double euclidean_distance(double *vect1,double *vect2, int dimension){
	int i;
	double distance = 0.0; 
	for (i = 0; i < dimension;i++){
		distance += (vect1[i] - vect2[i])*(vect1[i] - vect2[i]);
	}

	distance = sqrt(distance);

	return distance;
}


map_t *init_map(int height,int width, int length, double *v_aver, double min, double max){

	map_t *map = (map_t*)malloc(sizeof(map_t));
	map -> sensor = NULL;
	map -> height = height;
	map -> width = width;
	map -> map = malloc(height * sizeof(neuron_t*));

	int i;
	int j;
	int k;

	for(i = 0; i < height; i++){
		map -> map[i] = malloc(width * sizeof(neuron_t));

		for(j = 0; j < width; j++){
			map -> map[i][j].weight = malloc(sizeof(double) * length);
			for (k = 0; k < length; k++){
				map -> map[i][j].weight[k] = m_random(v_aver[k] - min,v_aver[k] + max);

			}
		}
	}
	return map;
}


void learning(map_t *map,data_t *data,int size_db, double alpha, int neighbors_radius, int nb_iteration,int dimension){
	int *tab = generate_table(size_db);
	int line = 0;
	int column = 0;
	double alpha_init = alpha;
	int decrement = (int) nb_iteration / neighbors_radius;
	decrement = (decrement <= 0) ? 1 : decrement; // eviter que decrement vaut 0 decrementer le rayon
	for(int i = 1; i <= nb_iteration; i++){
		shuffle(tab,size_db);
		alpha = alpha_init * (1.0 - ((double) i / (double) nb_iteration));
		neighbors_radius -= (i % decrement == 0 && neighbors_radius > 1) ? 1 : 0;
		for(int j = 0; j < size_db;j++){
			double min_dist = 1000.0;
			for(int h = 0; h < map ->height; h++){
				for(int w = 0; w < map -> width; w++){
					double distance = euclidean_distance(map->map[h][w].weight,data[tab[j]].v,dimension);
					if(distance < min_dist){
						line = h;
						column = w;
						min_dist = distance;
					}
				}
			}
			int begin_line =(line - neighbors_radius < 0) ? 0: line - neighbors_radius;
			int end_line = (line + neighbors_radius < map->height)? line + neighbors_radius: map->height - 1;

			int begin_column =(column - neighbors_radius < 0)? 0: column - neighbors_radius;
			int end_column = (column + neighbors_radius < map->width)? column + neighbors_radius: map->width - 1;

			for(int l = begin_line; l <= end_line; l++){
				for(int c = begin_column; c <= end_column; c++){
					for(int k = 0; k < dimension; k++){

					map->map[l][c].weight[k] += alpha * (data[tab[j]].v[k] - map->map[l][c].weight[k]);
				}
				}
			}
		}
	}
}

void labeling(map_t *map,data_t *data,int size_db,int dimension){

	for(int h = 0; h < map->height; h++){
		for(int w = 0; w < map->width; w++){
			double min_dist = 1000.0;
			int index_min = 0;
			for(int i = 0; i < size_db; i++){
				double distance = euclidean_distance(map->map[h][w].weight,data[i].v,dimension);
				if(distance < min_dist){
					index_min = i;
					min_dist = distance;
				}

			}
			map->map[h][w].label = data[index_min].nom_espece;

			if(strcmp (map->map[h][w].label, "Iris-setosa") == 0){
				color("31");
				color("1");
				printf("S");
			}

			if(strcmp(map->map[h][w].label,"Iris-versicolor") == 0){
				color("32");
				color("1");
				printf("V");
			}

			if(strcmp (map->map[h][w].label,"Iris-virginica") == 0){
				color("33");
				color("1");
				printf("A");
			}

		} 
		printf("\n");
	}
}

int main(int argc, char** argv){
	double * aver;
	srand(time(NULL));
	int w = 11;
	int h = 6;
	map_t *map = NULL;
	double alpha = 0.7;
	double alpha2 = 0.07;
	int neighbors_radius = 3;
	int rayon_voisin2 = 1;
	int nb_iteration = 500;
	int nb_iteration2 = 2000;

	if (argc < 3){
		fprintf(stderr, "Usage : ./Iris nom_file dim_vect size_bd\n");
		exit(0);
	}
	
	int dim = atoi(argv[2]), size = atoi(argv[3]);
	data_t *data = load_data_file(dim, size, argv[1]);

	aver = average(data, dim, size);
	map = init_map(h, w, dim, aver, 0.001, 0.001);
	learning(map,data,size,alpha,neighbors_radius,nb_iteration,dim);
	learning(map,data,size,alpha2,rayon_voisin2,nb_iteration2,dim);
	
	labeling(map,data,size,dim);

	return 0;
}
