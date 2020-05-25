//
//  Newton.hpp
//  Newton(Task3)
//
//  Created by Артем Белов on 25.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//

#ifndef Newton_hpp
#define Newton_hpp

#include <stdio.h>

double *Newton(double  *x0, int N, int *numit, int k, bool turnToModifiedFlag, bool countJacobiEachKIterationsFlag, bool noModifications);
double *NewtonModified(double  *x0, int N, int *numit);

#endif /* Newton_hpp */
