#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Лабараторная работа No.1
void lab1() {
    // Ввод чисел
    int m, n;
    cout << "введите число m: ";
    while (!(cin >> m)) {                                   // Здесь и далее в программе
        cout << "Неверный ввод. Введите целое число.: ";    // Проверка на дурака
        cin.clear();                                        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    cout << "введите число n: ";
    while (!(cin >> n)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    //
    // Проверка делимости m на n нацело и вывод результата
    if (m % n != 0) {
        cout << m << " на " << n << " нацело не делится" << endl;
    }
    else {
        cout << "result: ";
        cout << m / n << endl;
    }
    system("pause");
    return;
}
// Лабараторная работа No.2
void lab2() {
    // Ввод двух целых чисел
    int x, y;
    bool flag = false;
    while (!(cin >> x)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (!(cin >> y)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Умножение числа на число
    int res = 0;
    int sign = 1;
    if (x < 0) {
        sign = -sign;
        x = -x;
    }
    if (y < 0) {
        sign = -sign;
        y = -y;
    }
    x = abs(x);
    y = abs(y);
    for (int i = 1; i <= x; i++) {
        res += y;
    }
    res *= sign;
    // Вывод результата в консоль
    cout << res << endl;
    system("pause");
    return;
}
// Лабараторная работа No.3
void lab3() {
    int y = 1;
    int factorial = 1;
    unsigned int n;
    // Ввод максимльного числа факториал которого надо взять
    cout << "Введите положительное целое число n: ";
    while (!(cin >> n)) {
        cout << "Неверный ввод. Введите положительное целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    // Вычисление суммы факториалов от 1 до n
    for (unsigned int i = 1; i <= n; i++) {
        factorial *= i;
        y += factorial;
    }
    // Вывод результата в консоль
    cout << y << endl;
    system("pause");
    return;
}
// Лабараторная работа No.4
void lab4() {
    // Ввод длины массива
    unsigned n;
    bool flag = false;
    cout << "Введите длину массива (минимально допустимая длина равна 3): ";
    do {
        cout << "Длина массива меньше минимально допустимой длины" << endl;
        while (!(cin >> n)) {
            cout << "Неверный ввод. Введите целое число.: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (n < 3);
    cout << "\n";
    // Инициализация и заполнение массива
    int* m{ new int[n] };
    cout << "Введите 0, если хотите заполнить массив сами, или 1, если хотите заполнить массив рандомными значениями." << endl;
    bool rand_or_not;
    while (!(cin >> rand_or_not)) {
        cout << "Неверный ввод. Введите 1 или 0.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!rand_or_not) {
        for (unsigned i{ 0 }; i < n; i++) {
            while (!(cin >> m[i])) {
                cout << "Неверный ввод. Введите целое число.: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    else {
        srand(time({}));
        for (unsigned i{ 0 }; i < n; i++) {
            m[i] = rand();
        }
    }
    // Поиск 3х подряд идущих 0ых элементов
    for (unsigned i = 0; i < n - 2; i++) {
        if (m[i] == m[i + 1] == m[i + 2] == 0) {
            cout << "В массиве имеются 3 идущих подряд нулевых элементов" << endl;
            return;
        }
    }
    cout << "В массиве нет трёх подряд идущих нулевых элементов" << endl;
    delete[] m;
    m = nullptr;
    system("pause");
}
// Лабараторная работа No.5
void lab5() {
    // Ввод длины массива
    unsigned n;
    bool flag = false;
    cout << "введите длину массива: ";
    while (!(cin >> n)) {
        cout << "Неверный ввод. Введите положительное целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    // Инициализация и заполнения массива
    int tmp;
    int* m = new int[n];
    cout << "Введите 0, если хотите заполнить массив сами, или 1, если хотите заполнить массив рандомными значениями." << endl;
    bool rand_or_not;
    while (!(cin >> rand_or_not)) {
        cout << "Неверный ввод. Введите 1 или 0.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!rand_or_not) {
        for (unsigned i{ 0 }; i < n; i++) {
            while (!(cin >> m[i])) {
                cout << "Неверный ввод. Введите целое число.: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    else {
        srand(time({}));
        for (unsigned i{ 0 }; i < n; i++) {
            m[i] = rand();
        }
    }
    // Сортировка массива по убыванию
    for (unsigned i = 1; i < n; i++) {
        for (unsigned j = 0; j < i; j++) {
            if (m[i] > m[j]) {
                tmp = m[j];
                m[j] = m[i];
                m[i] = tmp;
            }
        }
    }
    // Вывод упорядоченного массива
    cout << "результат сортировки по убыванию: {";
    for (int* num{ m }; num != m + n - 1; num++) {
        cout << *num << ", ";
    }
    cout << m[n - 1] << "}" << endl;
    delete[] m;
    m = nullptr;
    return;
    system("pause");
}
// Лабараторная работа No.6
void lab6() {
    // Ввод размера матрицы
    unsigned int n;
    cout << "введите размер матрицы: ";
    while (!(cin >> n)) {
        cout << "Неверный ввод. Введите положительное целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    // Инициализация матрицы
    int** matrix{ new int* [n] {} };
    for (unsigned i = 0; i < n; i++) {
        matrix[i] = new int[n] {};
    }
    // Заполнение матрицы
    cout << "Введите 0, если хотите заполнить матрицу сами, или 1, если хотите заполнить матрицу рандомными значениями." << endl;
    bool rand_or_not;
    while (!(cin >> rand_or_not)) {
        cout << "Неверный ввод. Введите 1 или 0.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!rand_or_not) {

        for (unsigned i{ 0 }; i < n; i++) {
            cout << "row " << i + 1 << ": \n";
            for (unsigned j{ 0 }; j < n; j++) {
                while (!(cin >> matrix[i][j])) {
                    cout << "Неверный ввод. Введите целое число.: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
    else {
        srand(time({}));
        for (unsigned i{ 0 }; i < n; i++) {
            for (unsigned j{ 0 }; j < n; j++) {
                matrix[i][j] = rand();
            }
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
    bool isSymmetric = true;
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = i + 1; j < n; j++) { 
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        cout << "Матрица симметрична относительно главной диагонали.\n";
    }
    else {
        cout << "Матрица не симметрична относительно главной диагонали.\n";
    }

    // Удаление матрицы
    for (unsigned i{}; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    system("pause");
}
// Лабараторная работа No.7
void lab7() {
    // Ввод размеров прямоугольной матрицы
    unsigned int col;
    unsigned int row;
    cout << "введите размер матрицы в формате [ len_col len_row ]: ";
    while (!(cin >> col >> row)) {
        cout << "Неверный ввод. Введите положительные целые числа.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    // инициализация матрицы
    int** matrix{ new int* [col] {} };
    for (unsigned i = 0; i < col; i++) {
        matrix[i] = new int[row] {};
    }
    // заполнение матрицы
    cout << "Введите 0, если хотите заполнить матрицу сами, или 1, если хотите заполнить матрицу рандомными значениями." << endl;
    bool rand_or_not;
    while (!(cin >> rand_or_not)) {
        cout << "Неверный ввод. Введите 1 или 0.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!rand_or_not) {
        
        for (unsigned i{ 0 }; i < col; i++) {
            cout << "row " << i + 1 << ": \n";
            for (unsigned j{ 0 }; j < row; j++) {
                while (!(cin >> matrix[i][j])) {
                    cout << "Неверный ввод. Введите целое число.: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
    else {
        srand(time({}));
        for (unsigned i{ 0 }; i < col; i++) {
            for (unsigned j{ 0 }; j < row; j++) {
                matrix[i][j] = rand();
            }
        }
    }
    // Вывод введённой матрицы
    cout << "Введённая матрица:\n";
    for (unsigned i{}; i < col; i++) {
        cout << i+1 << ".\t";
        for (unsigned j{}; j < row; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    // Ввод номера строки для удаления
    unsigned int k;
    cout << "Введите номер строки для удаления: ";
    while (!(cin >> k)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl;
    do {
        if (k >= col) {
            cout << "В матирце нет строки с таким номером. Попробуйте ещё раз: ";
            while (!(cin >> k)) {
                cout << "Неверный ввод. Введите целое число.: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
    } while (k >= col);
    // Создание копии матрицы с отсутствующей строкой
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
                swap(new_matrix[i - 1][j], matrix[i][j]);
            }
            else {
                swap(new_matrix[i][j], matrix[i][j]);
            }

        }
    }
    // Вывод полученной матрицы
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
    system("pause");
}
// Лабараторная работа No.8
void lab8() {
    // Ввод размера квадратной матрицы
    unsigned int n;
    cout << "введите размер матрицы: ";
    while (!(cin >> n)) {
        cout << "Неверный ввод. Введите положительное целое число.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    // инициализация матрицы
    int** matrix{ new int* [n] {} };
    for (unsigned i = 0; i < n; i++) {
        matrix[i] = new int[n] {};
    }
    // заполнение матрицы
    cout << "Введите 0, если хотите заполнить матрицу сами, или 1, если хотите заполнить матрицу рандомными значениями." << endl;
    bool rand_or_not;
    while (!(cin >> rand_or_not)) {
        cout << "Неверный ввод. Введите 1 или 0.: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!rand_or_not) {

        for (unsigned i{ 0 }; i < n; i++) {
            cout << "row " << i + 1 << ": \n";
            for (unsigned j{ 0 }; j < n; j++) {
                while (!(cin >> matrix[i][j])) {
                    cout << "Неверный ввод. Введите целое число.: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
    else {
        srand(time({}));
        for (unsigned i{ 0 }; i < n; i++) {
            for (unsigned j{ 0 }; j < n; j++) {
                matrix[i][j] = rand();
            }
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
    // Поиск упорядоченных строк
    bool flag = true;
    int tmp;
    int* id_ordered_rows = new int[n];
    for (unsigned i = 0; i < n; i++) {
        int* ordered_row = new int[n];
        // создание копии строки
        for (unsigned j = 0; j < n; j++) {
            ordered_row[j] = matrix[i][j];
        }
        // сортировка копии строки по убыванию
        for (unsigned or_i = 1; or_i < n; or_i++) {
            for (unsigned or_j = 0; or_j < or_i; or_j++) {
                if (ordered_row[or_i] > ordered_row[or_j]) {
                    tmp = ordered_row[or_j];
                    ordered_row[or_j] = ordered_row[or_i];
                    ordered_row[or_i] = tmp;
                }
            }
        }
        // сравнение полученной строки с строкой в матрице
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
            // сортировка копии строки по возрастанию
            for (unsigned or_i = 1; or_i < n; or_i++) {
                for (unsigned or_j = 0; or_j < or_i; or_j++) {
                    if (ordered_row[or_i] < ordered_row[or_j]) {
                        tmp = ordered_row[or_j];
                        ordered_row[or_j] = ordered_row[or_i];
                        ordered_row[or_i] = tmp;
                    }
                }
            }
            // сравнение полученной строки с строкой в матрице
            for (unsigned j = 0; j < n; j++) {
                if (ordered_row[j] == matrix[i][j]) {
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
            }
            // запись результата сравнения в массив с индексами упорядоченных строк
            if (flag) {
                id_ordered_rows[i] = i;
            }
            else {
                id_ordered_rows[i] = n + 1;
                continue;
            }
        }
        // отчистка копии строки
        delete[] ordered_row;
    }
    // вычисление длины столбца матрицы содержащей только упорядоченные строки
    unsigned counter = 0;
    for (unsigned i = 0; i < n; i++) {
        if (id_ordered_rows[i] != n + 1) {
            counter++;
        }
    }
    if (counter != 0) {
        // сборка матрицы содержащей только упорядоченные строки
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
        // поиск минимального элемента матрицы содержащей только упорядоченные строки
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
    system("pause");
}
// Лабараторная работа No.9
void lab9() {
    // Ввод текста
    cout << "Введите текст: ";
    string a;
    cin >> a;
    string input_string;
    getline(cin, input_string);
    cout << endl;
    input_string = a + input_string;
    size_t len_is = input_string.length();
    // Подсчет числа пробелов для генерации массива с словами
    int space_count = 0;
    for (size_t i = 0; i < len_is; i++) {
        if (input_string[i] == ' ') {
            space_count++;
        }
    }
    // Инициализация и заполнение массива словами
    string* words = new string[space_count+1];
    string word = "";
    size_t w_i = 0;
    for (size_t is_i{}; is_i < len_is; is_i++) {
        if (input_string[is_i] == ' ') {
            words[w_i] = word;
            word = "";
            w_i++;
        }
        else {
            word = word + input_string[is_i];
        }
    }
    if (input_string[len_is - 1] != ' ') {
        words[w_i] = word;
    }
    // Создание динамически расширяющегося массива элементами которого является пара: слово, количество этих слов в тексте
    bool flag = true;
    unsigned counter{};
    vector<pair<string, unsigned>> list;
    for (int i{}; i < space_count + 1; i++) {
        flag = true;
        if (list.size() != 0) {
            // проверка есть ли для отсеивания дубликатов
            for (pair<string, unsigned> ptr : list) {
                if (ptr.first == words[i]) {
                    flag = false;
                    break;
                } 
            }
        }
        if (flag) {
            // подсчет количества повторов слова в текте
            for (int j = i; j < space_count + 1; j++) {
                if (words[i] == words[j]) {
                    counter++; 
                } 
            }
            list.push_back(pair<string, unsigned>{words[i], counter});
            counter = 0;
        }
    }
    // Вывод повторяющихся слов и то сколько раз они встречаются в тексте
    for (pair<string, unsigned> ptr : list) {
        if (ptr.second != 1) {cout << "Слово: " << ptr.first << "\tВстретилось: " << ptr.second << endl;}
        
    }
    system("pause");
}

void lab10() {
    string line;
    string a;
    cin >> a;
    getline(cin, line);
    line = a + line;
    vector<char> list;
    size_t len_line = line.size();
    bool flag = true;
    for (size_t i = 0; i < len_line; i++) {
        if (not list.empty()) {
            for (size_t j = 0; j < list.size(); j++) {
                if (list[j] == line[i]) {
                    flag = false;
                }
            }
        } 
        if (flag) {
            list.push_back(line[i]);
        }
        flag = true;
    }
    for (char ptr : list) {
        if (ptr == ' ') {
            cout << "space ";
        }
        else {
            cout << ptr << " ";
        }
    }
    cout << endl;
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned no_lab;
    do {
        cout << "type number of lab or 0 to exit: ";
        while (!(cin >> no_lab)) {
            cout << "Неверный ввод. Введите целое число.: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (no_lab == 0) {
            break;
        }
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
        case (9): { lab9(); break; }
        case (10): { lab10(); break; }
        }
    } while (no_lab != 0);
}