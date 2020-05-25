//
//  LUP.hpp
//  Newton(Task3)
//
//  Created by Артем Белов on 25.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//

#ifndef LUP_hpp
#define LUP_hpp

#include <stdio.h>

void LUPDecompose(double **A, int *p, int N, int *numit);
void LUPSolve(double **A, int *p, double *b, double *x, int N, int *numit);
#endif /* LUP_hpp */
