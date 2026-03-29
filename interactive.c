#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imageprocessing.h"
#include "bmp.h"
#define LUNGIME_COMANDA_MAX 200
#define PATH 100
#define MAX 100

int main() {
    int N[MAX] = {0}, M[MAX] = {0}, idx = 0, ***V[MAX];
    int x = 0, y = 0, w = 0, h = 0;
    int rows = 0, cols = 0, R = 0, G = 0, B = 0;
    int idxd = 0, idxs = 0, x1 = 0, y1 = 0, fs[MAX] = {0};
    int idxf = 0, nr_img = 0, nr_flt = 0;
    char path[PATH], c[LUNGIME_COMANDA_MAX], *p = NULL, x2 = 'x';
    float **filter[MAX];         // c=comanda
    while (1) {
        scanf("%s", c);
        p = c;
        if (c[0] == 'a' && c[1] == 'h')
            p = c + 1;
        if (c[0] == 'a' && c[1] == 'r')
            p = c + 1;
        if (c[0] == 'a' && c[1] == 'c')
            p = c + 1;
        if (c[0] == 'a' && c[1] == 'e')
            p = c;
        if (c[0] == 'a' && c[1] == 'p')
            p = c + 1;
        if (c[0] == 'c' && c[1] == 'f')
            p = c + 1;
        if (c[0] == 'a' && c[1] == 'f')
            p = &x2;
        if (c[0] == 'd' && c[1] == 'f')
            p = c;
        if (c[0] == 'd' && c[1] == 'i')
            p = c + 1;
        switch (*p) {
            case 'e':
                if (nr_img) {
                    for (int k = 0; k < nr_img ; k++) {
                        for (int i = 0; i < N[k]; i++) {
                            for (int j = 0; j < M[k]; j++) {
                                free(V[k][i][j]);
                            }
                        free(V[k][i]);
                        }
                    free(V[k]);
                    }
                }
                if (nr_flt) {
                    for (int l = 0; l < nr_flt; l++) {
                        for (int i = 0; i < fs[l]; i++) {
                            free(filter[l][i]);
                        }
                    free(filter[l]);
                    }
                }
                    return 0;
            case 'l':
                scanf("%d %d %s", &N[nr_img], &M[nr_img], path);
                V[nr_img] = (int ***)malloc(N[nr_img] * sizeof(int **));
                for (int i = 0; i < N[nr_img]; i++) {
                    V[nr_img][i] = (int **)malloc(M[nr_img] * sizeof(int *));
                    for (int j = 0; j < M[nr_img]; j++) {
                        V[nr_img][i][j] = (int *)malloc(3 * sizeof(int));
                    }
                }
                read_from_bmp(V[nr_img], N[nr_img], M[nr_img], path);
                nr_img++;
                break;
            case 's':
                scanf("%d %s", &idx, path);
                write_to_bmp(V[idx], N[idx], M[idx], path);
                break;
            case 'h':
                scanf("%d", &idx);
                V[idx] = flip_horizontal(V[idx], N[idx], M[idx]);
                break;
            case 'r':
                scanf("%d", &idx);
                V[idx] = rotate_left(V[idx], N[idx], M[idx]);
                N[idx] = N[idx] + M[idx];
                M[idx] = N[idx] - M[idx];
                N[idx] = N[idx] - M[idx];
                break;
            case 'c':
                scanf("%d %d %d %d %d", &idx, &x, &y, &w, &h);
                V[idx] = crop(V[idx], N[idx], M[idx], x, y, h, w);
                N[idx] = h;
                M[idx] = w;
                break;
            case 'a':
                scanf("%d %d %d %d %d %d", &idx, &rows, &cols, &R, &G, &B);
                V[idx] = extend(V[idx], N[idx], M[idx], rows, cols, R, G, B);
                N[idx] = N[idx] + (2 * rows);
                M[idx] = M[idx] + (2 * cols);
                break;
            case 'p':
                scanf("%d %d %d %d", &idxd, &idxs, &x1, &y1);
                V[idxd] = paste(V[idxd], N[idxd], M[idxd], V[idxs], N[idxs], M[idxs], x1, y1);
                break;
            case 'f':
                scanf("%d", &fs[nr_flt]);
                filter[nr_flt] = (float **)malloc(fs[nr_flt] * sizeof(float *));
                for (int i = 0; i < fs[nr_flt]; i++) {
                    filter[nr_flt][i] = (float *)malloc(fs[nr_flt] * sizeof(float));
                }
                for (int i = 0; i < fs[nr_flt]; i++) {
                    for (int j = 0; j < fs[nr_flt]; j++) {
                        scanf("%f", &filter[nr_flt][i][j]);
                    }
                }
                nr_flt++;
                break;
            case 'x':
                scanf("%d %d", &idx, &idxf);
                V[idx] = apply_filter(V[idx], N[idx], M[idx], filter[idxf], fs[idxf]);
                break;
            case 'd':  // df
                scanf("%d", &idxf);
                free(filter[idxf]);
                for (int i = idxf; i < nr_flt - 1; i++) {
                    filter[i] = filter[i + 1];
                    fs[i] = fs[i + 1];
                }
                nr_flt--;
                break;
            case 'i':    // di
                scanf("%d", &idx);
                free(V[idx]);
                for (int i = idx; i < nr_img - 1; i++) {
                    V[i] = V[i+1];
                    N[i] = N[i+1];
                    M[i] = M[i+1];
                }
                nr_img--;
                break;
        }
    }
    return 0;
}
