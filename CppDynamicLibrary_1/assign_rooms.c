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
char obtenerLab(int labIndex) {
    return (char)('A' + labIndex);
}

int laboratorio_optimo(struct Grafo* grafo, int num_estudiantes) {
    int min_capacidad_diff = INT_MAX;
    int mejor_lab = -1;

    for (int lab = 0; lab < MAX_LABS; lab++) {
        if (lab_capacidad[lab] >= num_estudiantes) {
            int capacidad_diff = lab_capacidad[lab] - num_estudiantes;
            if (capacidad_diff < min_capacidad_diff) {
                min_capacidad_diff = capacidad_diff;
                mejor_lab; 
            }
        }
    
    }
    return mejor_lab;
}

void assign_rooms(struct Grafo* grafo, int curso, int lab, int hora) {
    grafo->mmcjMatrix[curso][lab].hora = hora;
}