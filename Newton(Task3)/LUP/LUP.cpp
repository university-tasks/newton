//
//  LUP.cpp
//  Newton(Task3)
//
//  Created by Артем Белов on 25.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//

#include "LUP.hpp"
#include "operations.hpp"

#define myExp 0.00000001

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void LUPDecompose(double **A, int *p, int N, int *numit) {

    int i, j, k, imax;
    double maxA, *ptr, absA;

    for (i = 0; i <= N; i++) {
        p[i] = i;
    }
        

    for (i = 0; i < N; i++) {
        maxA = 0.0;
        imax = i;

        for (k = i; k < N; k++) {
            if ((absA = fabs(A[k][i])) > maxA) {
                maxA = absA;
                imax = k;
            }
            numit[0]++;
        }
            


        if (imax != i) {
            
            j = p[i];
            p[i] = p[imax];
            p[imax] = j;

            
            ptr = A[i];
            A[i] = A[imax];
            A[imax] = ptr;

            
            p[N]++;
        }

        for (j = i + 1; j < N; j++) {
            A[j][i] /= A[i][i];

            for (k = i + 1; k < N; k++) {
                A[j][k] -= A[j][i] * A[i][k];
                
                numit[0]++;
            }
                
        }
    }
}

void LUPSolve(double **A, int *p, double *b, double *x, int N, int *numit) {

    for (int i = 0; i < N; i++) {
        x[i] = b[p[i]];

        for (int k = 0; k < i; k++) {
            x[i] -= A[i][k] * x[k];
            numit[0]++;
        }
            
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int k = i + 1; k < N; k++) {
            x[i] -= A[i][k] * x[k];
            
            numit[0]++;
        }
        x[i] = x[i] / A[i][i];
    }
}
