/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */
/* 
 * File:   main.c
 * Author: Emanuel
 *
 * 
 */

#include <stdio.h>
#include "assign_rooms.h"

int main() {
    struct Grafo* grafo = crearGrafo();

    
    int option;
    do {
        printf("1. Asignar sala a un curso\n");
        printf("2. Laboratorio optimo para un curso\n");
        printf("3. Eliminar cursos asignados\n");
        printf("4. Listar bloques de tiempo disponibles en cada laboratorio\n");
        printf("5. Visualizacion de Asignaciones\n");
        //printf("6. Encontrar emparejamiento maximo\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int curso, lab, hora;

                printf("Ingrese el numero del curso (0-5): ");
                scanf("%d", &curso);
                printf("Ingrese el numero del laboratorio (0-6): ");
                scanf("%d", &lab);
                printf("Ingrese la hora militar para el bloque de tiempo (7-18): ");
                scanf("%d", &hora);

                if (!laboratorio_disponibilidad(grafo, lab, hora)) {
                    printf("---¡Error!--- El laboratorio ya esta ocupado en la misma hora.\n");
                } else {
                    assign_rooms(grafo, curso, lab, hora);
                    printf("Bloque de tiempo asignado con exito.\n");
                }
                break;
            }
            case 2: {
                int num_estudiantes;

                printf("Ingrese el numero de estudiantes en su curso: ");
                scanf("%d", &num_estudiantes);

                int lab = laboratorio_optimo(grafo, num_estudiantes);

                if (lab == -1) {
                    printf("No hay laboratorio disponible para esa cantidad de estudiantes.---\n");
                } else {
                    char labAsign = obtenerLab(lab);
                    printf("El laboratorio más adecuado para %d estudiantes es el laboratorio %c.\n", num_estudiantes, labAsign);
                }
                break;
            }
            case 3: {
                int curso1, curso2;
                printf("Ingrese el primer curso: ");
                scanf("%d", &curso1);
                remove_overlapping_blocks(grafo, curso1);
                break;
            }
            case 4: {
                listado_tiempo_disponible(grafo);
                break;
            default:
                  printf("Opcion no valida.\n");
            }
            case 5: {
                printf("Asignaciones de bloques:\n");
                for (int i = 0; i < MAX_CURSOS; i++) {
                    printf("Curso %d:\n", i);
                    for (int j = 0; j < MAX_LABS; j++) {
                        if (grafo->mmcjMatrix[i][j].hora > 0) {
                            printf("  Lab %c: Hora %d\n", obtenerLab(j), grafo->mmcjMatrix[i][j].hora);
                        }
                    }
                    printf("\n");
                }
                break;
            }
            /*case 6: {
                int source = MAX_CURSOS; 
                int sink = MAX_CURSOS + 1; 

                struct Grafo* flow_grafo = crearGrafo();
                for (int curso = 0; curso < MAX_CURSOS; curso++) {
                    for (int lab = 0; lab < MAX_LABS; lab++) {
                        if (grafo->mmcjMatrix[curso][lab].hora > 0) {
                            assign_rooms(flow_grafo, curso, lab, grafo->mmcjMatrix[curso][lab].hora);
                        }
                    }
                }

                for (int curso = 0; curso < MAX_CURSOS; curso++) {
                    assign_rooms(flow_grafo, source, curso, 0);
                }

                for (int lab = 0; lab < MAX_LABS; lab++) {
                    assign_rooms(flow_grafo, lab, sink, 0);
                }

                int max_matching = edmonds_karp(flow_grafo, source, sink);

                printf("El emparejamiento máximo en el grafo es: %d\n", max_matching);

                free(flow_grafo);
                break;
            }*/

            case 7:
                printf("Saliendo...\n");
                break;
      }
    } while (option != 7);
    free(grafo);

    return 0;
}