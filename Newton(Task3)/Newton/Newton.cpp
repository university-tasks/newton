//
//  Newton.cpp
//  Newton(Task3)
//
//  Created by Артем Белов on 25.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//
# define eps 0.000001

#include "Newton.hpp"
#include "LUP.hpp"
#include "count.hpp"
#include "operations.hpp"

#include <cmath>

double *TurnToModified(double **J, int *p, double *F, double *prev_x, double *delta_x, int *numit, int N) {
    
    double norm;
    double *x = new double[N];
    
    do {
        
        countF(F, prev_x);

        for (int i = 0; i < N; i++) {
            F[i] = -F[i];
        }
        
        LUPSolve(J, p, F, delta_x, N, numit);

        for (int i = 0; i < N; i++) {
            x[i] = prev_x[i] + delta_x[i];
            
        }

        norm = fabs(x[0] - prev_x[0]);
        for (int j = 0; j < N; j++) {
            
            if (fabs(x[j] - prev_x[j]) > norm) {
                norm = fabs(x[j] - prev_x[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            prev_x[i] = x[i];
        }
        
        
        
    } while (norm > eps);

    return x;
    
}


double *Newton(double  *x0, int N, int *numit, int k, bool turnToModifiedFlag, bool countJacobiEachKIterationsFlag, bool noModifications) {
    
    double norm;
    int count = 0;

    double **J = new double *[N];

    double *prev_x = new double[N];
    double *F = new double[N];
    double *delta_x = new double[N];
    double *x = new double[N];
    int *p = new int[N];

    for (int i = 0; i < N; ++i) {
        J[i] = new double[N];
        
        prev_x[i] = x0[i];
    }
    int i = 0;
    
    do {
        i++;
        if (i == k && countJacobiEachKIterationsFlag == true) {
            countJ(J, prev_x);
            LUPDecompose(J, p, N, numit);
            i = 0;
        }
        
        if (noModifications == true) {
            countJ(J, prev_x);
            LUPDecompose(J, p, N, numit);
        }
        
        countF(F, prev_x);

        for (int i = 0; i < N; i++) {
            F[i] = -F[i];
        }
        
        LUPSolve(J, p, F, delta_x, N, numit);

        for (int i = 0; i < N; i++) {
            x[i] = prev_x[i] + delta_x[i];
            
        }

        norm = fabs(x[0] - prev_x[0]);
        for (int j = 0; j < N; j++) {
            
            if (fabs(x[j] - prev_x[j]) > norm) {
                norm = fabs(x[j] - prev_x[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            prev_x[i] = x[i];
        }
        
        count++;
        
        if (count == k && turnToModifiedFlag == true) {
            printf("Turn to modified on this step: %i\n",k);
            TurnToModified(J, p, F, prev_x, delta_x, numit, N);
        }
        
        
    } while (norm > eps);

    return x;
}

double *NewtonModified(double  *x0, int N, int *numit) {
    
    double norm;
    double **J = new double *[N];

    double *prev_x = new double[N];
    double *F = new double[N];
    double *delta_x = new double[N];
    double *x = new double[N];
    int *p = new int[N];

    for (int i = 0; i < N; ++i) {
        J[i] = new double[N];
        
        prev_x[i] = x0[i];
    }
    
    

    countJ(J, prev_x);
    LUPDecompose(J, p, N, numit);
    
    do {

        
        countF(F, prev_x);

        for (int i = 0; i < N; i++) {
            F[i] = -F[i];
        }
        
        LUPSolve(J, p, F, delta_x, N, numit);

        for (int i = 0; i < N; i++) {
            x[i] = prev_x[i] + delta_x[i];
            
        }

        norm = fabs(x[0] - prev_x[0]);
        for (int j = 0; j < N; j++) {
            
            if (fabs(x[j] - prev_x[j]) > norm) {
                norm = fabs(x[j] - prev_x[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            prev_x[i] = x[i];
        }
        
        
        
    } while (norm > eps);

    return x;
}
