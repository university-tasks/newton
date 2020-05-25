//
//  main.cpp
//  Newton(Task3)
//
//  Created by Артем Белов on 01.05.2020.
//  Copyright © 2020 Артем Белов. All rights reserved.
//
#define eps 0.000000001
#define CLOCKS_PER_SEC

#include <iostream>
#include <cmath>
#include <ctime>

#include "count/count.hpp"
#include "Newton/Newton.hpp"
#include "Operations/operations.hpp"





int main() {
    
    const int N = 10;
    
    double *x0 = new double(10);
    x0[0] = 0.5; x0[1] = 0.5; x0[2] = 1.5; x0[3] = -1.0; x0[4] = -0.5; x0[5] = 1.5; x0[6] = 0.5; x0[7] = -0.5; x0[8] = 1.5; x0[9] = -1.5;
    
    int action;
    bool x5_flag = false;
    std::cout << "x0[5] = −0.2?" << std::endl;
    std::cout << "1)YES" << std::endl;
    std::cout << "1)NO" << std::endl;
    std::cout << "3)EXIT" << std::endl;
    std::cout << ">>>>>>>> ";
    std::cin >> action;
    switch (action) {
        case 1:
            x0[4] = -0.2;
            x5_flag = true;
            break;
        default:
            return 0;;
    }
    
 
    
    double *b = new double(10);
    b[0] = -2.0004339741653854440; b[1] = -10.886272036407019994;
    b[2] = 3.1361904761904761904;  b[3] = 0.1707472705022304757;
    b[4] = 0.3685896273101277862;  b[5] = -2.049108601677187511;
    b[6] = 0.7380430076202798014;  b[7] = -3.5668321989693809040;
    b[8] = 8.4394734508383257499;  b[9] = 0.78238095238095238096;
    
    double *x = new double[N];
   
    
    int *numit = new int[1];
    int *numit1= new int[1];
    int *numit2= new int[1];
    int *numit3= new int[1];
    action = -1;
    while (action!= 3) {
    
        std::cout << "Which method?\n";
        std::cout << "1)Newton\n";
        std::cout << "2)Newton modified\n";
        std::cout << "3)Start with classic and finish with modified\n";
        std::cout << "4)Count Jacobi matrix after each k iterations\n";
        std::cout << "5)Return\n";
        std::cout << ">>>>>>>> ";
        std::cin >> action;
        
        switch (action) {
            case 1:
                
                clock_t start;
                start = clock();
                
                x = Newton(x0, N, numit, 0, false, false, true);
                
                clock_t end;
                end = clock();
                
                std::cout << "Number of iterations: " << numit[0] << std::endl;
                std::cout << "Time spent: " << ((float)(end - start))/CLOCKS_PER_SEC << " seconds" << std::endl;
                printf("x: ");
                showDVect(x, N);
                
                return 0;
            case 2:
                
                
                clock_t start1;
                start1 = clock();
                
                x = NewtonModified(x0, N, numit1);
                
                clock_t end1;
                end1 = clock();
                
                std::cout << "Number of iterations: " << numit1[0] << std::endl;
                std::cout << "Time spent: " << ((float)(end1 - start1))/CLOCKS_PER_SEC << " seconds" << std::endl;
                
                printf("x: ");
                showDVect(x, N);
                return 0;
                
            case 3:

//               x^0_5 = -0.5
//               k = 1   time = 0.000186
//               k = 2   time = 0.000185
//          !!!! k = 3   time = 0.000162 !!!!
//               k = 4   time = 0.000236
//               k = 5   time = 0.000183
//               k = 6   time = 0.000175
//               k = 7   time = 0.000203
//               k = 8   time = 0.000204
                    
//экспериментальным путем нашли оптимальное k: 3
                
                int k;
                
                if (x5_flag == true) {
                    k = 8;
                } else {
                    k = 3;
                }
                    
                    clock_t start2;
                    start2 = clock();
                    
                    x = Newton(x0, N, numit2, k, true, false, true);
                    
                    clock_t end2;
                    end2 = clock();
                    
                    std::cout << "Number of iterations: " << numit2[0] << std::endl;
                    std::cout << "Time spent: " << ((float)(end2 - start2))/CLOCKS_PER_SEC << " seconds" << std::endl;
                    printf("x: ");
                    showDVect(x, N);
                
                return 0;
                
            case 4:
                int k1;
                
                clock_t start3;
                start3 = clock();
//             x^0_5 = -0.5
//             k = 1 time =  0.000217
//             k = 2 time =  0.000227
//             k = 3 time =  0.000239
//             k = 4 time =  0.000252  выдает nan'ы
//       !!!!  k = 5 time =  0.000185 !!!!
//             k = 6 time =  0.00022
//             k = 7 time =  0.000209
//             k = 8 time =  0.000209
                
//экспериментальным путем нашли оптимальное k: 5
                
                if (x5_flag == true) {
                    k1 = 1;
                } else {
                    k1 = 8;
                }
            
                x = Newton(x0, N, numit3, k1, false, true, false);
                
                clock_t end3;
                end3 = clock();
                
                std::cout << "Number of iterations: " << numit3[0] << std::endl;
                std::cout << "Time spent: " << ((float)(end3 - start3))/CLOCKS_PER_SEC << " seconds" << std::endl;
                printf("x: ");
                showDVect(x, N);
                
                
                return 0;
                
            default:
                return 0;
        }
    }
    
    
    
    
    
    
    return 0;
}
