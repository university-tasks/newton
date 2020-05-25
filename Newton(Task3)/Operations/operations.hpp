//
//  operations.hpp
//  Newton(Task3)
//
//  Created by Артем Белов on 24.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//

#ifndef operations_hpp
#define operations_hpp

#include <stdio.h>

void showMatr(double **A, int N, int M);
void showDVect(double *v, int N);
void showIVect(int *v, int N);
double **multMatr(double **A, double **B, int N);
double *matrMultVect(double **A, double *v, int N);
void transpose(double **A, int N);
double max(double *v, int N);
void inverse(double **A, double **inverse, int N);
#endif /* operations_hpp */
