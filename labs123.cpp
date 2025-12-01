#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <regex>
using namespace std;
const regex SignedNumPattern("-?[0-9]+");
const regex UnsignedNumPattern("[0-9]+");

bool isInt(string input, bool isSigned=true) {
    if (isSigned) {
        if (regex_match(input, SignedNumPattern)) {
            return true;
        }
        return false;
    }
    else {
        if (regex_match(input, UnsignedNumPattern)) {
            return true;
        }
        return false;
    }
}
int* sorting(int* arr, bool reversed=true) {
    if (reversed) {
        for (size_t i = 1; i < sizeof(arr); i++) {
            for (size_t j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    else {
        for (size_t i = 1; i < sizeof(arr); i++) {
            for (size_t j = 0; j < i; j++) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    return arr;
}
// Лабараторная работа No.1
void lab1() {
    // Ввод чисел
    int m, n;
    string mInput, nInput;
    cout << "введите число m: ";
    cin >> mInput;
    while (!isInt(mInput)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> mInput;
    }
    m = stoi(mInput);
    cout << "\n";
    cout << "введите число n: ";
    cin >> nInput;
    while (!isInt(nInput)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> nInput;
    }
    cout << "\n";
    n = stoi(nInput);
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
    string xInput, yInput;
    bool flag = false;
    while (!isInt(xInput)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> xInput;
    }
    x = stoi(xInput);
    while (!isInt(yInput)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> yInput;
    }
    y = stoi(yInput);
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
    string nInput;
    // Ввод максимльного числа факториал которого надо взять
    cout << "Введите положительное целое число n: ";
    cin >> nInput;
    while (!isInt(nInput, false)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> nInput;
    }
    n = stoi(nInput);
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
    string nInput;
    cout << "Введите длину массива (минимально допустимая длина равна 3): ";
    do {
        cout << "Длина массива меньше минимально допустимой длины" << endl;
        cin >> nInput;
        while (!isInt(nInput, false)) {
            cout << "Неверный ввод. Введите целое число.: ";
            cin >> nInput;
        }
        n = stoi(nInput);
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
            cin >> nInput;
            while (!isInt(nInput)) {
                cout << "Неверный ввод. Введите целое число.: ";
                cin >> nInput;
            }
            m[i] = stoi(nInput);
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
    string nInput;
    bool flag = false;
    cout << "введите длину массива: ";
    cin >> nInput;
    while (!isInt(nInput, false)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> nInput;
    }
    n = stoi(nInput);
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
            cin >> nInput;
            while (!isInt(nInput)) {
                cout << "Неверный ввод. Введите целое число.: ";
                cin >> nInput;
            }
            m[i] = stoi(nInput);
        }
    }
    else {
        srand(time({}));
        for (unsigned i{ 0 }; i < n; i++) {
            m[i] = rand();
        }
    }
    // Сортировка массива по убыванию
    m = sorting(m);
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
    string nInput;
    cout << "введите размер матрицы: ";
    cin >> nInput;
    while (!isInt(nInput, false)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> nInput;
    }
    n = stoi(nInput);
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
                cin >> nInput;
                while (!isInt(nInput)) {
                    cout << "Неверный ввод. Введите целое число.: ";
                    cin >> nInput;
                }
                matrix[i][j] = stoi(nInput);
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
    string colInput, rowInput, valInput, delInput;
    cout << "введите размер матрицы в формате [ len_col len_row ]: ";
    cin >> colInput >> rowInput;
    while (!isInt(colInput, false) and !isInt(rowInput, false)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> colInput >> rowInput;
    }
    col = stoi(colInput);
    row = stoi(rowInput);
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
                cin >> valInput;
                while (!isInt(valInput)) {
                    cout << "Неверный ввод. Введите целое число.: ";
                    cin >> valInput;
                }
                matrix[i][j] = stoi(valInput);
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
    unsigned int delrow;
    cout << "Введите номер строки для удаления: ";
    cin >> delInput;
    while (!isInt(delInput, false)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> delInput;
    }
    delrow = stoi(delInput);
    cout << endl;
    do {
        if (delrow >= col or delrow <= 0) {
            cout << "В матирце нет строки с таким номером. Попробуйте ещё раз: ";
            cin >> delInput;
            while (!isInt(delInput, false)) {
                cout << "Неверный ввод. Введите целое число.: ";
                cin >> delInput;
            }
            delrow = stoi(delInput);
        }
        
    } while (delrow >= col);
    // Создание копии матрицы с отсутствующей строкой
    unsigned int new_col = col - 1;
    int** new_matrix{ new int* [new_col] {} };
    for (unsigned i = 0; i < new_col; i++) {
        new_matrix[i] = new int[row] {};
    }
    for (unsigned i{ 0 }; i < col; i++) {
        if (i == delrow - 1) {
            continue;
        }
        for (unsigned j{ 0 }; j < row; j++) {
            if (i > delrow - 1) {
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
    string valInput, nInput;
    cout << "введите размер матрицы: ";
    cin >> nInput;
    while (!isInt(nInput, false)) {
        cout << "Неверный ввод. Введите целое число.: ";
        cin >> nInput;
    }
    n = stoi(nInput);
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
                cin >> valInput;
                while (!isInt(valInput)) {
                    cout << "Неверный ввод. Введите целое число.: ";
                    cin >> valInput;
                }
                matrix[i][j] = stoi(valInput);
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
        ordered_row = sorting(ordered_row);
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
            ordered_row = sorting(ordered_row, false);
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
    unsigned NoLab;
    string noLabInput;
    do {
        cout << "type number of lab or 0 to exit: ";
        cin >> noLabInput;
        while (!isInt(noLabInput, false)) {
            cout << "Неверный ввод. Введите целое число.: ";
            cin >> noLabInput;
        }
        NoLab = stoi(noLabInput);
        if (NoLab == 0) {
            break;
        }
        switch (NoLab)
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
    } while (NoLab != 0);
}