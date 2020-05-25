//
//  operations.cpp
//  Newton(Task3)
//
//  Created by Артем Белов on 24.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//

#include "operations.hpp"
#include <stdlib.h>

void showMatr(double **A, int N, int M) {
    printf("\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%lf%s",A[i][j]," ");
        }
        printf("\n");
    }
    printf("\n");
}

void showDVect(double *v, int N) {
    for (int i = 0; i < N; ++i) {
        printf("%f ",v[i]);
    }
    printf("\n");
}

void showIVect(int *v, int N) {
    for (int i = 0; i < N; ++i) {
        printf("%i ",v[i]);
    }
    printf("\n");
}

double **multMatr(double **A, double **B, int N) {
    
    double **R = (double **)malloc(N*sizeof(double *));
    for(int i = 0; i < N; i++) {
        R[i] = (double *)malloc(N*sizeof(double));
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            R[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                R[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return R;
}

double *matrMultVect(double **A, double *v, int N) {
    
    double *res = (double*)malloc(sizeof(double) * N);
    
    for (int i = 0; i < N; ++i) {
        double sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += A[i][j]*v[j];
        }
        res[i] = sum;
    }
    return res;
}

void transpose(double **A, int N) {
    
    double **T = (double**)malloc(N*sizeof(double *));
    for(int i = 0; i < N; i++) {
        T[i] = (double *)malloc(N*sizeof(double));
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            T[i][j] = A[i][j];
        }
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = T[j][i];
}

double max(double *v, int N) {
    
    double res = -100000000;
    
    for (int i = 0; i < N; ++i) {
        if (res <= v[i]) {
            res = v[i];
        }
    }
    return res;
}

