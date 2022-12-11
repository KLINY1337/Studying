#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int Rows = 7;
const int Cols = 7;

void initialize_static(double(*matrix)[Cols], int n) {
    int choice;

    cout << "¬ведите способ заполнени€ массива:\n1) ¬ручную\n2) —лучайными числами\n";

    do {

        cin >> choice;

        if (choice != 1 && choice != 2) cout << "¬ведено неверное значение, попробуйте снова.\n";
    } while (choice != 1 && choice != 2);

    switch (choice) {
    case 1:

        cout << "¬ведите двумерный массив:\n";

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];

        break;
    case 2:

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = rand() % 50 + 1;

        break;
    }
}

void cout_static(double(*matrix)[Cols], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j] ;
        }
        cout << "\n";
    }
}


double static_determinant(double(*matrix)[Cols], int n) {
    int i, j, k, r;
    double c, M, max, s, det = 1;

    for (k = 0; k < n; k++)
    {
        max = fabs(matrix[k][k]); r = k;

        for (i = k + 1; i < n; i++)
            if (fabs(matrix[i][k]) > max)
            {
                max = fabs(matrix[i][k]); r = i;
            }
        if (r != k) det = -1*det;

        for (j = 0; j < n; j++)
        {
            swap(matrix[k][j] , matrix[r][j]);
        }

        for (i = k + 1; i < n; i++)
            for (M = matrix[i][k] / matrix[k][k], j = k; j < n; j++)
                matrix[i][j] -= M * matrix[k][j];

    }
    for (i = 0; i < n; i++)
        det *= matrix[i][i];

    return det;
}