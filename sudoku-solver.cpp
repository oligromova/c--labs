#include "sudoku-solver.h"
#include "field-checker.h"

static bool good_num(int num, std::vector<std::vector<int> > &field, int x, int y) {
    for (int i = 0; i < 9; ++i) {
        if ((field[x][i] == num && i != y) || (field[i][y] == num && i != x)) {
            return false;
        }
    }
    for (int i = x / 3 * 3; i < x / 3 * 3 + 3; ++i) {
        for (int j = y / 3 * 3; j < y / 3 * 3 + 3; ++j) {
            if (field[i][j] == num && (i != x || j != y)) {
                return false;
            }
        }
    }
    return true;
}

static void sudoku_solve_current(const std::vector<std::vector<int>> &field, std::vector<std::vector<int>> &cur_field, std::vector<std::vector<int>> &solution, size_t &ans, int x, int y) {
    for (int i = x; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cur_field[i][j] == 0) {
                for (int num = 1; num < 10; ++num) {
                    if (good_num(num, cur_field, i, j)) {
                        cur_field[i][j] = num;
                        sudoku_solve_current(field, cur_field, solution, ans, i, j);
                        cur_field[i][j] = 0;
                    }
                }
                return;
            }
        }
    }

    ans++;
    solution = cur_field;
    return;
}

std::pair<size_t, std::vector<std::vector<int>>> sudoku_solve(const std::vector<std::vector<int>> &field) {
    std::vector<std::vector<int>> cur_field = field;
    std::vector<std::vector<int> > answerSudoku;
    size_t answer = 0;
    sudoku_solve_current(field, cur_field, answerSudoku, answer, 0, 0);
    return std::make_pair(answer, answerSudoku);
}
