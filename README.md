# Knapsack-problem
## Решение задачи:
### 1) Каждому предмету сопоставляю коэффициент - удельную стоимсоть = value / weight
### 2) Сортирую предметы по этому коэффициенту по убыванию
### 3) Прохожу по отсортированному массиву от начала до конца кладу предметы пока есть свободное место
### 4) Вывожу полученную ценность, остаток объёма и список принадлежности (на i-ом месте стоит 1 если i-й предмет входит и 0 - иначе)

## Программа:
###   Программа состоит из нескольких файлов: main.cpp, Input.cpp, Solver.cpp, Knapsack.hpp
###   Основная функция - решатель лежит в Solver
###   В Input.cpp - описана функция занимающая вводом всех данных из файла

## Работа программы:
### 1) Компиляция через makefile
### 2) Запустить run.exe
### 3) При запуске есть выбор выполнения программы:
###      a) для всех имеющихся файлов (их список вначале main.cpp)
###      ( все файлы должны лежать в той же папке, что и все основные файлы программы )
####        В этом случае массив принадлежности НЕ выводится
####        В командную строку выводятся только названия всех файлов
####        Результат в Result_all

###      b) для конкретного файла (необходимо будет ввести его название)
####        В командную строку выводится название файла, итоговая ценность и остаток веса
####        Полный результат в Result_one