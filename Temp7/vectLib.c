#include "vectLib.h"
#include <stdio.h> //per printf e scanf
#include <time.h> //per srand e time
#include <stdlib.h> // per rand
#include <math.h> // per fabs
#include <stdbool.h> // per bool, true, false

// —— Input/Output ——

void print_vec(const double *v, size_t dim) {
    printf("[");
    for (size_t i = 0; i < dim; i++) {
        printf("%g", v[i]);
        if (i < dim - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// —— Operazioni algebriche ——

void scanf_vec(double *v, size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        scanf("%lf", &v[i]);
    }
}

void add_vec(const double *v1, const double *v2, double *res, size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        res[i] = v1[i] + v2[i];
    }
}

void adds_vec(const double *v1, double k, double *res, size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        res[i] = v1[i] + k;
    }
}

void muls_vec(const double *v, double k, double *res, size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        res[i] = v[i] * k;
    }
}

void sub_vec(const double *v1, const double *v2, double *res, size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        res[i] = v1[i] - v2[i];
    }
}

double dot_vec(const double *v1, const double *v2, size_t dim) {
    double result = 0.0;
    for (size_t i = 0; i < dim; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// —— Manipolazione vettori ——

void concat_vec(const double *v1, size_t dim1, const double *v2, size_t dim2, double *res) {
    for (size_t i = 0; i < dim1; i++) {
        res[i] = v1[i];
    }
    for (size_t i = 0; i < dim2; i++) {
        res[dim1 + i] = v2[i];
    }
}

void reverse_vec(double *v, size_t dim) {
    for (size_t i = 0; i < dim / 2; i++) {
        double temp = v[i];
        v[i] = v[dim - 1 - i];
        v[dim - 1 - i] = temp;
    }
}

void sort_vec(double *v, size_t dim) {
    for (size_t i = 0; i < dim - 1; i++) {
        for (size_t j = 0; j < dim - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                double temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void shuffle_vec(double *v, size_t dim) {
    srand(time(NULL));
    for (size_t i = dim - 1; i > 0; i--) {
        size_t j = rand() % (i + 1); 
        double temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void rshft_vec(double *v, size_t step, size_t dim) { 
    if (step >= dim) {
        for (size_t i = 0; i < dim; i++) {
            v[i] = 0;
        }
        return;
    }
    for (size_t i = dim - 1; i >= step; i--) {
        v[i] = v[i - step];
    }
    for (size_t i = 0; i < step; i++) {
        v[i] = 0;
    }
}

void lshft_vec(double *v, size_t step, size_t dim) { 
    if (step >= dim) {
        for (size_t i = 0; i < dim; i++) {
            v[i] = 0;
        }
        return;
    }
    for (size_t i = 0; i < dim - step; i++) {
        v[i] = v[i + step];
    }
    for (size_t i = dim - step; i < dim; i++) {
        v[i] = 0;
    }
}

void rrot_vec(double *v, size_t step, size_t dim) {
    if (step >= dim) {
        return;
    }
    for (size_t j = 0; j < step; j++) {
        double temp = v[dim - 1];
        for (size_t i = dim - 1; i > 0; i--) {
            v[i] = v[i - 1];
        }
        v[0] = temp;
    }
}

void lrot_vec(double *v, size_t step, size_t dim) {
    if (step >= dim) {
        return;
    }
    for (size_t j = 0; j < step; j++) {
        double temp = v[0];
        for (size_t i = 0; i < dim - 1; i++) {
            v[i] = v[i + 1];
        }
        v[dim - 1] = temp;
    }
}

void slice_vec(const double *src, double *dest, int start, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[start + i];
    }
}

// —— Inizializzazione ——

void rand_vec(int *v, size_t dim, int min, int max) {
    srand(time(NULL));
    for (size_t i = 0; i < dim; i++) {
        v[i] = rand() % max + min;
    }
}

void fill_vec(double *v, size_t dim, double val) {
    for (size_t i = 0; i < dim; i++) {
        v[i] = val;
    }
}

void zero_vec(double *v, size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        v[i] = 0;
    }
}

// —— Statistiche e utilità ——

double mean_vec(const double *v, size_t dim) {
    double sum = 0;
    double mean = 0; 
    for (size_t i = 0; i < dim; i++) {
        sum += v[i];
        mean = sum / dim;
    }
    return mean;
}

double min_vec(const double *v, size_t dim) {
    double min = v[0];
    for (size_t i = 1; i < dim; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

double max_vec(const double *v, size_t dim) {
    double max = v[0];
    for (size_t i = 1; i < dim; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

double sum_vec(const double *v, size_t dim) {
    double sum = 0;
    for (size_t i = 0; i < dim; i++) {
        sum += v[i];
    }
    return sum;
}


bool eq_vec(const double *v1, const double *v2, size_t dim, double tol) {
    for (size_t i = 0; i < dim; i++) {
        if (fabs(v1[i] - v2[i]) >= tol) {
            return false;
        }
    }
    return true;
}

void map_vec(double *v, size_t dim, double (*func)(double)) {
    for (size_t i = 0; i < dim; i++) {
        v[i] = func(v[i]);
    }
}

// —— Norme e geometria ——

double norm_vec(const double *v, size_t dim) {
    double sum = 0.0;
    double norm = 0.0;
    for (size_t i = 0; i < dim; i++) {
        sum += v[i] * v[i];
    }
    norm = sqrt(sum);
    return norm;
}