#include "assign_rooms.h"


int lab_capacidad[] = {20, 60, 30, 40, 20, 30, 25};

struct Grafo* crearGrafo() {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    int i, j;
    for (i = 0; i < MAX_CURSOS; i++) {
        for (j = 0; j < MAX_LABS; j++) {
            grafo->mmcjMatrix[i][j].hora = 0;
        }
    }
    return grafo;
}