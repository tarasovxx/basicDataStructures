#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "tsk1.h"

int getDouble(double *val) {
    while(1) {
        int status = scanf("%lf", val);
        if (status == -1) {
            puts("EOF");
            return -1;
        }
        else if (status != 1) {
            puts("You are wrong, repeat, please!");
            scanf("%*[^\n]");
        }
        else return 1;
    }
}

int getInt(int *val) {
    while(1) {
        int status = scanf("%d", val);
        if (status == -1) {
            puts("EOF");
            return -1;
        }
        else if (status != 1 || (*val) < 0) {
            puts("You are wrong, repeat, please!");
            scanf("%*[^\n]");
        }
        else return 1;
    }
}


int input_matrix(Matrix *mt) {
    puts("Please input sizes m * n");
    int m, n;
    getInt(&m);
    getInt(&n);
    mt->info = (double **) calloc(m, sizeof(double *));
    mt->m = m; mt->n = n;
    for (size_t i = 0; i < m; ++i) {
        mt->info[i] = (double *) calloc(n, sizeof(double));
        printf("Please input %d row", i);
        for (size_t j = 0; j < n; ++j) {
            getDouble(&mt->info[i][j]);
        }
    }
}

double maxMinElem(Matrix *mt) {
    double *maxElemToRow = (double *)calloc(mt->m, sizeof(double));
    for (size_t i = 0; i < mt->m; ++i) {
        double maxElem = 0;
        for (size_t j = 0; j < mt->n; ++j) {
            if (mt->info[i][j] > maxElem) {
                maxElem = mt->info[i][j];
            }
        }
        maxElemToRow[i] = maxElem;
    }
    double mini = INT_MAX;
    for (size_t i = 0; i < mt->m; ++i) {
        if (mini > maxElemToRow[i]) {
            mini = maxElemToRow[i];
        }
    }
    return mini;
}

void destroy_matrix(Matrix *mt) {
    for (size_t i = 0; i < mt->m; ++i) {
        free(mt->info[i]);
    }
    free(mt->info);
    free(mt);
}

int main() {
    Matrix *mt = calloc(1, sizeof(Matrix));
    input_matrix(mt);
    double ans = maxMinElem(mt);
    printf("answer: %lf\n", ans);
    destroy_matrix(mt);
    return 0;

}