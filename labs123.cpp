#include <iostream>
#include <math.h>
using namespace std;

void lab1() {
    int m, n;
    cout << "введите число m: ";
    cin >> m;
    cout << "\n";
    cout << "введите число n: ";
    cin >> n;
    cout << "\n";
    if (m % n != 0) {
        cout << m << " на " << n << " нацело не делится" << endl;
    }
    else {
        cout << "result: ";
        cout << m / n << endl;
    }
    return;
}

void lab2() {
    int x, y;
    bool flag = false;
    cin >> x;
    cin >> y;
    int res = 0;
    if ((x < 0 or y < 0) and not (x < 0 and y < 0)) {
        flag = true;
    }
    x = abs(x);
    y = abs(y);
    for (int i = 1; i <= x; i++) {
        res += y;
    }
    if (flag == true) {
        res *= -1;
    }
    cout << res << endl;
    return;
}

void lab3() {
    int y = 1;
    int factorial = 1;
    unsigned int n;
    cout << "введите число n: ";
    cin >> n;
    cout << "\n";
    for (unsigned int i = 1; i <= n; i++) {
        factorial *= i;
        y += factorial;
    }
    cout << y << endl;
    return;
}

void lab4() {
    unsigned n;
    bool flag = false;
    cout << "введите длину массива: ";
    cin >> n;
    cout << "\n";
    int* m{ new int[n] };
    if (n < 3) {
        cout << "длина массива меньше минимально допустимой длины" << endl;
        return;
    }
    cout << "введите элементы массива: \n";
    for (int* num{ m }; num != m + n; num++) {
        cin >> *num;
    }
    for (unsigned i = 0; i < n - 2; i++) {
        if (m[i] == m[i + 1] == m[i + 2] == 0) {
            flag = true;
        }
    }
    if (flag == true) {
        cout << "в массиве имеются 3 идущих подряд нулевых элементов" << endl;
    }
    else {
        cout << "в массиве нет трёх подряд идущих нулевых элементов" << endl;
    }
    delete[] m;
    m = nullptr;
    return;
}

void lab5() {
    unsigned n;
    bool flag = false;
    cout << "введите длину массива: ";
    cin >> n;
    cout << "\n";
    int tmp;
    int* m{ new int[n] };
    cout << "введите элементы массива: \n";
    for (int* num{ m }; num != m + n; num++) {
        cin >> *num;
    }
    for (unsigned i = 1; i < n; i++) {
        for (unsigned j = 0; j < i; j++) {
            if (m[i] > m[j]) {
                tmp = m[j];
                m[j] = m[i];
                m[i] = tmp;
            }
        }
    }
    cout << "результат сортировки по убыванию: {";
    for (int* num{ m }; num != m + n - 1; num++) {
        cout << *num << ", ";
    }
    cout << m[n - 1] << "}" << endl;
    delete[] m;
    m = nullptr;
    return;
}

void lab6() {
    unsigned int n;
    cout << "введите размер матрицы: ";
    cin >> n;
    cout << "\n";
    // инициализация матрицы
    int** matrix{ new int* [n] {} };
    for (unsigned i = 0; i < n; i++) {
        matrix[i] = new int[n] {};
    }
    // заполнение матрицы
    for (unsigned i{ 0 }; i < n; i++) {
        cout << "row " << i + 1 << ": \n";
        for (unsigned j{ 0 }; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    // Вывод введённой матрицы
    cout << "Введённая матрица:\n";
    for (unsigned i{}; i < n; i++) {
        for (unsigned j{}; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    // Проверка на симметричность
    for (unsigned i{}; i < n - 1; i++) {
        for (unsigned j{}; j < n - 1; j++) {
            if (matrix[i][n - 1 - j] != matrix[n - 1 - i][j]) {
                cout << "Матрица не симметрична относительно главной диагонали.\n";
                return;
            }
        }
    }
    cout << "Матрица симметрична относительно главной диагонали.\n";
    // Удаление матрицы
    for (unsigned i{}; i < n; i++) { delete[] matrix[i]; }
    delete[] matrix;
}

void lab7() {
    unsigned int col;
    unsigned int row;
    cout << "введите размер матрицы в формате [ len_col len_row ]: ";
    cin >> col >> row;
    cout << "\n";
    // инициализация матрицы
    int** matrix{ new int* [col] {} };
    for (unsigned i = 0; i < col; i++) {
        matrix[i] = new int[row] {};
    }
    // заполнение матрицы
    for (unsigned i{ 0 }; i < col; i++) {
        cout << "row " << i + 1 << ": \n";
        for (unsigned j{ 0 }; j < row; j++) {
            cin >> matrix[i][j];
        }
    }
    // Вывод введённой матрицы
    cout << "Введённая матрица:\n";
    for (unsigned i{}; i < col; i++) {
        for (unsigned j{}; j < row; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    unsigned int k;
    cout << "Введите номер строки для удаления: ";
    cin >> k;
    cout << endl;
    do {
        if (k > col) {
            cout << "В матирце нет строки с таким номером. Попробуйте ещё раз: ";
            cin >> k;
        }
    } while (k > col);
    unsigned int new_col = col - 1;
    int** new_matrix{ new int* [new_col] {} };
    for (unsigned i = 0; i < new_col; i++) {
        new_matrix[i] = new int[row] {};
    }
    for (unsigned i{ 0 }; i < col; i++) {
        if (i == k - 1) {
            continue;
        }
        for (unsigned j{ 0 }; j < row; j++) {
            if (i > k - 1) {
                new_matrix[i - 1][j] = matrix[i][j];
            }
            else {
                new_matrix[i][j] = matrix[i][j];
            }

        }
    }
    cout << "Полученная матрица: " << endl;
    for (unsigned i{}; i < new_col; i++) {
        for (unsigned j{}; j < row; j++) {
            cout << new_matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    for (unsigned i{}; i < col; i++) { delete[] matrix[i]; }
    delete[] matrix;
    for (unsigned i{}; i < new_col; i++) { delete[] new_matrix[i]; }
    delete[] new_matrix;

}
void lab8() {
    unsigned int n;
    cout << "введите размер матрицы: ";
    cin >> n;
    cout << "\n";
    // инициализация матрицы
    int** matrix{ new int* [n] {} };
    for (unsigned i = 0; i < n; i++) {
        matrix[i] = new int[n] {};
    }
    // заполнение матрицы
    for (unsigned i{ 0 }; i < n; i++) {
        cout << "row " << i + 1 << ": \n";
        for (unsigned j{ 0 }; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    // Вывод введённой матрицы
    cout << "Введённая матрица:\n";
    for (unsigned i{}; i < n; i++) {
        for (unsigned j{}; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    bool flag = true;
    int tmp;
    int* id_ordered_rows = new int[n];
    for (unsigned i = 0; i < n; i++) {
        int* ordered_row = new int[n];
        for (unsigned j = 0; j < n; j++) {
            ordered_row[j] = matrix[i][j];
        }
        for (unsigned or_i = 1; or_i < n; or_i++) {
            for (unsigned or_j = 0; or_j < or_i; or_j++) {
                if (ordered_row[or_i] > ordered_row[or_j]) {
                    tmp = ordered_row[or_j];
                    ordered_row[or_j] = ordered_row[or_i];
                    ordered_row[or_i] = tmp;
                }
            }
        }
        for (unsigned j = 0; j < n; j++) {
            if (ordered_row[j] == matrix[i][j]) {
                flag = true;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            id_ordered_rows[i] = i;
        }
        else {
            for (unsigned or_i = 1; or_i < n; or_i++) {
                for (unsigned or_j = 0; or_j < or_i; or_j++) {
                    if (ordered_row[or_i] < ordered_row[or_j]) {
                        tmp = ordered_row[or_j];
                        ordered_row[or_j] = ordered_row[or_i];
                        ordered_row[or_i] = tmp;
                    }
                }
            }
            for (unsigned j = 0; j < n; j++) {
                if (ordered_row[j] == matrix[i][j]) {
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                id_ordered_rows[i] = i;
            }
            else {
                id_ordered_rows[i] = n + 1;
                continue;
            }
        }
        delete[] ordered_row;
    }
    unsigned counter = 0;
    for (unsigned i = 0; i < n; i++) {
        if (id_ordered_rows[i] != n + 1) {
            counter++;
        }
    }
    if (counter != 0) {
        int** only_ordered_rows = new int* [counter];
        for (unsigned i = 0; i < counter; i++) {
            only_ordered_rows[i] = new int[n];
        }
        int id_oor_row = 0;
        for (unsigned i = 0; i < n; i++) {
            if (id_ordered_rows[i] != 0) {
                for (unsigned j = 0; j < n; j++) {
                    only_ordered_rows[id_oor_row][j] = matrix[i][j];
                }
                id_oor_row++;
            }

        }
        int min_oor = only_ordered_rows[0][0];
        for (unsigned i = 0; i < counter; i++) {
            for (unsigned j = 0; j < n; j++) {
                if (only_ordered_rows[i][j] < min_oor) {
                    min_oor = only_ordered_rows[i][j];
                }
            }
        }
        cout << "Минимальный среди элементов упорядоченных строк: " << min_oor << endl;
        for (unsigned i{}; i < counter; i++) { delete[] only_ordered_rows[i]; }
        delete[] only_ordered_rows;
    }
    else {
        cout << "В матрице нет упорядоченных строк" << endl;
    }
    for (unsigned i{}; i < n; i++) { delete[] matrix[i]; }
    delete[] matrix;
    delete[] id_ordered_rows;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned no_lab;
    do {
        cout << "type number of lab or 0 to exit: ";
        cin >> no_lab;
        if (no_lab == 0) {
            break;
        }
        cout << "\n";
        switch (no_lab)
        {
        case (1): { lab1(); break; }
        case (2): { lab2(); break; }
        case (3): { lab3(); break; }
        case (4): { lab4(); break; }
        case (5): { lab5(); break; }
        case (6): { lab6(); break; }
        case (7): { lab7(); break; }
        case (8): { lab8(); break; }
        }
    } while (no_lab != 0);
}



