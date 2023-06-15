#ifndef AISD2023_TSK1_H
#define AISD2023_TSK1_H


typedef struct Matrix {
    int m;
    int n;
    double **info;
} Matrix;


int getDouble(double *);

int getSize(int *);

int input_matrix(Matrix *);

#endif //AISD2023_TSK1_H
