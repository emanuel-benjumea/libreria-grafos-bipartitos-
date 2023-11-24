/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/*
 * File:   assign_rooms.h
 * Author: Emanuel
 *Colaborator: Alejandro Navarro
 * Created on 23 de noviembre de 2023, 10:19 p. m.
 */

#ifndef ASSIGN_ROOMS_H
#define ASSIGN_ROOMS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "cJSON.h"

#define MAX_CURSOS 8
#define MAX_LABS 7

struct TiempoBloq {
    int hora;
};

struct Grafo {
    struct TiempoBloq mmcjMatrix[MAX_CURSOS][MAX_LABS];
};

struct Grafo* crearGrafo();
extern int lab_capacidad[];
char obtenerLab(int labIndex);


int laboratorio_optimo(struct Grafo* grafo, int num_estudiantes);
void assign_rooms(struct Grafo* grafo, int curso, int lab, int hora);
void remove_overlapping_blocks(struct Grafo* grafo, int curso1);
void select_blocks(struct Grafo* grafo, int curso, int hora);
bool laboratorio_disponibilidad(struct Grafo* grafo, int lab, int hora);
void listado_tiempo_disponible(struct Grafo* grafo);

#endif /* ASSIGN_ROOMS_H */

