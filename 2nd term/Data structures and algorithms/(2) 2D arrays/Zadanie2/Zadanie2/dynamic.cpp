#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void initialize_dynamic(double **matrix, int n) {
    int choice;

    cout << "������� ������ ���������� �������:\n1) �������\n2) ���������� �������\n";

    do {

        cin >> choice;

        if (choice != 1 && choice != 2) cout << "������� �������� ��������, ���������� �����.\n";
    } while (choice != 1 && choice != 2);

    switch (choice) {
    case 1:

        cout << "������� ��������� ������:\n";

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

void cout_dynamic(double **matrix, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

double dynamic_determinant(double** matrix, int n)
{
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

        if (r != k) det = -det;

        for (j = 0; j < n; j++)
        {
           std :: swap(matrix[k][j], matrix[r][j]);
        }

        for (i = k + 1; i < n; i++)
            for (M = matrix[i][k] / matrix[k][k], j = k; j < n; j++)
                matrix[i][j] -= M * matrix[k][j];

    }
    for (i = 0; i < n; i++)
        det *= matrix[i][i];
    
    return det;
}