#include <stdio.h>
#include <stdlib.h>
#include "imageprocessing.h"
#define MAX_VALUE_FILTER 255
#define MIN_VALUE_FILTER 0

//  Task 1
int ***flip_horizontal(int ***image, int N, int M) {
    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M/2; j++) {
            for (int k = 0; k < 3; k++) {
                temp = image[i][j][k];
                image[i][j][k] = image[i][M - j - 1][k];
                image[i][M - j - 1][k] = temp;
            }
        }
    }
    return image;
}

//  Task 2
int ***rotate_left(int ***image, int N, int M) {
    int ***a = (int ***)malloc(M * sizeof(int **));
    for (int i = 0; i < M; i++) {
        a[i] = (int **)malloc(N * sizeof(int *));
        for (int j = 0; j < N; j++) {
            a[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                a[i][j][k] = image[j][M-i-1][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return a;
}
//  Task 3
int ***crop(int ***image, int N, int M, int x, int y, int h, int w) {
    int ***a = (int ***)malloc(h * sizeof(int **));
    for (int i = 0; i < h; i++) {
        a[i] = (int **)malloc(w * sizeof(int *));
        for (int j = 0; j < w; j++) {
            a[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 3; k++) {
                a[i][j][k] = image[y+i][x+j][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return a;
}

//  Task 4
int ***extend(int ***image, int N, int M, int rows, int cols, int new_R, int new_G, int new_B) {
    int ***a = (int ***)malloc((N+(2*rows)) * sizeof(int **));
    for (int i = 0; i < N+(2*rows); i++) {
        a[i] = (int **)malloc((M+(2*cols)) * sizeof(int *));
        for (int j = 0; j < M+(2*cols); j++) {
            a[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }
    for (int i = 0; i < N+(2*rows); i++) {
        for (int j = 0; j < M+(2*cols); j++) {
            a[i][j][0] = new_R;
            a[i][j][1] = new_G;
            a[i][j][2] = new_B;
        }
    }
    for (int i = rows; i < N+rows ; i++) {
        for (int j = cols; j < M+cols; j++) {
            for (int k = 0; k < 3; k++) {
                a[i][j][k] = image[i-rows][j-cols][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return a;
}

//  Task 5
int ***paste(int ***image_dst, int N_dst, int M_dst, int ***image_src, int N_src, int M_src, int x, int y) {
    for (int i = 0; i < (N_src+y < N_dst ? N_src : N_dst-y); i++) {
        for (int j = 0; j < (M_src+x < M_dst ? M_src : M_dst-x); j++) {
            for (int k = 0; k < 3; k++) {
                image_dst[y+i][x+j][k] = image_src[i][j][k];
            }
        }
    }
    return image_dst;
}

//  Task 6
int ***apply_filter(int ***image, int N, int M, float **filter, int filter_size) {
    int ***a = (int ***)calloc((N+(filter_size-1)) , sizeof(int **));
    for (int i = 0; i < N+(filter_size-1); i++) {
        a[i] = (int **)calloc((M+(filter_size-1)) , sizeof(int *));
        for (int j = 0; j < M+(filter_size-1); j++) {
            a[i][j] = (int *)calloc(3 , sizeof(int));
        }
    }
    for (int i = (filter_size-1)/2; i < N+(filter_size-1)/2; i++) {
        for (int j = (filter_size-1)/2; j < M+(filter_size-1)/2; j++) {
            for (int k = 0; k < 3; k++) {
                a[i][j][k] = image[i-(filter_size-1)/2][j-(filter_size-1)/2][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 3; k++) {
                float t = 0;
                for (int l = i;  l< filter_size + i; l++) {
                    for (int m = j; m < filter_size + j; m++) {
                        t+=(float)a[l][m][k]*filter[l-i][m-j];
                    }
                }
                if (t > MAX_VALUE_FILTER)
                    t = MAX_VALUE_FILTER;
                if (t < MIN_VALUE_FILTER)
                    t = MIN_VALUE_FILTER;
                image[i][j][k] =(int)t;
            }
        }
    }
    for (int i = 0; i < N+(filter_size-1); i++) {
        for (int j = 0; j < M+(filter_size-1); j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
    return image;
}
