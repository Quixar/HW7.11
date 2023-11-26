#include <iostream>

using namespace std;

void AddRow(int**& array, int& rows, int columns, int rowIndex) {
    // Создание нового массива с увеличенным числом строк
    int** newArray = new int* [rows + 1];

    // Копирование строк до указанной
    for (int i = 0; i < rowIndex; ++i) {
        newArray[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            newArray[i][j] = array[i][j];
        }
    }

    // Вставка строки из нулей
    newArray[rowIndex] = new int[columns] {0, 0, 0, 0};

    // Копирование строк после указанной
    for (int i = rowIndex + 1; i <= rows; ++i) {
        newArray[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            newArray[i][j] = array[i - 1][j];
        }
    }

    // Увеличение числа строк
    ++rows;

    // Освобождение памяти исходного массива
    for (int i = 0; i < rows - 1; ++i) {
        delete[] array[i];
    }
    delete[] array;

    // Переприсвоение указателя
    array = newArray;
}

void AddColumn(int**& array, int rows, int& columns, int columnIndex) {
    // Создание нового массива с увеличенным числом столбцов
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[columns + 1];
    }

    // Копирование столбцов до указанного
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columnIndex; ++j) {
            newArray[i][j] = array[i][j];
        }

        // Вставка нулевого элемента в новый столбец, с учетом максимального значения 9
        newArray[i][columnIndex] = (array[i][columnIndex - 1] + 1) % 10;

        // Копирование столбцов после указанного
        for (int j = columnIndex + 1; j <= columns; ++j) {
            newArray[i][j] = array[i][j - 1];
        }
    }

    // Увеличение числа столбцов
    ++columns;

    // Освобождение памяти исходного массива
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    // Переприсвоение указателя
    array = newArray;
}

int main() {
    int rows = 4;
    int columns = 4;

    // Создание и инициализация исходного массива
    int** ar = new int* [rows];
    for (int y = 0; y < rows; y++) {
        ar[y] = new int[columns];
        for (int x = 0; x < columns; x++) {
            ar[y][x] = y * columns + x + 1;
        }
    }

    // Вывод исходного массива
    cout << "Original Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }

    // Добавление строки
    int rowIndex;
    cout << "\nEnter the index where to add the row: ";
    cin >> rowIndex;
    AddRow(ar, rows, columns, rowIndex);

    // Вывод массива после добавления строки
    cout << "\nArray After Adding Row:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }

    // Добавление столбца
    int columnIndex;
    cout << "\nEnter the index where to add the column: ";
    cin >> columnIndex;
    AddColumn(ar, rows, columns, columnIndex);

    // Вывод массива после добавления столбца
    cout << "\nArray After Adding Column:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }

    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] ar[i];
    }
    delete[] ar;

    return 0;
}
