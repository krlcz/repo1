#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 3;

    double A[3][3] = { {25., 15., 5.}, {15., 13., 11.}, {5., 11., 21.} };

    double b[3] = { -5., 7., 1. };

    double L[3][3];

// wypelnienie zerami
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0.0;
        }
    }
    
    
    // l_00 = sqrt(a_00)
    L[0][0] = sqrt(A[0][0]);

    // l_i0 = ai_0 / l_00 | i > 0

    for (int i = 1; i < n; i++) {
        L[i][0] = A[i][0] / L[0][0];
        printf("A: %lf %lf\n", L[i][0], A[i][0]);
    }

    // l_ii = sqrt(a_ii - sum_from_k=0_to_i-1(l_ik ^2) | 0 < i < n

    double sum = 0.0;
    for (int i = 1; i < n; i++) {
        sum = 0.0;
        for (int k = 0; k < i; k++) {
            sum += powf(L[i][k], 2.0);
            printf("U: %d %d %lf   %lf   %lf\n", i, k, powf(L[i][k], 2.0), L[i][k], L[k][i]);
        }
        L[i][i] = sqrt(A[i][i] - sum);
        printf("B: %lf  %lf %lf\n", L[i][i], sum, A[i][i]);
    }

    // l_ij = (a_ij - sum_from_k=0_to_j-1(l_ik*l_jk)) / (l_ij) | i > j

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * L[j][k];
            }
            L[i][j] = (A[i][j] - sum) / L[j][j];
            printf("C: %lf %lf  %lf\n", L[i][j], sum, A[i][j]);
        }
    }

    // l_ij = 0 | i < j -- juz zrobione bo L na start jest wypelniana zerami
    

    double y[3];

    // y_0 = b_0 / l_00

    y[0] = b[0] / L[0][0];

    // y_i = (b_i - sum_from_k=0_to_i-1(l_ik * y_k)) / l_ii | i > 0

    for (int i = 1; i < n;i++) {
        sum = 0.0;
        for (int k = 0; k < i; k++) {
            sum += L[i][k] * y[k];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    double x[3];

    // x_n = y_n / L_nn

    x[2] = y[2] / L[2][2];

    // x_i = (y_i - sum_from_k=i+1_to_n(l_ki * x_k)) / l_ii | i < n

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", L[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", L[j][i]);
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 0; i--) {
        sum = 0.0;
        for (int k = i + 1; k < n; k++) {
            sum += L[k][i] * x[k];
        }
        x[i] = (y[i] - sum) / L[i][i];
    }

    for (int i = 0; i < n; i++) {
        printf("x_%d = %lf\n", i, x[i]);
    }




    return 0;
}