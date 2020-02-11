#include <iostream>
#include <cmath>

using namespace std;

//  типы фигур
//  1   2   3   4
//  X   XX   X  XX
//  XX  X   XX   X

// X < size-1
// Y < size-1

int last_figure_number;
int size;

bool check_figure_coordinates(int x1, int y1, int x2, int y2, int x3, int y3, int desk[512][512]) {
    return (desk[y1][x1] == -1) && (desk[y2][x2] == -1) && (desk[y3][x3] == -1);
}

bool rec_solving(int figure_counter, int x, int y, int desk[512][512]) {
    if (figure_counter == last_figure_number) {
        if (check_figure_coordinates(x, y, x, y+1, x+1, y+1, desk)) {
            desk[y][x] = figure_counter;
            desk[y+1][x] = figure_counter;
            desk[y + 1][x + 1] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x, y, x, y+1, x+1, y, desk)) {
            desk[y][x] = figure_counter;
            desk[y+1][x] = figure_counter;
            desk[y][x+1] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x+1, y, x, y+1, x+1, y+1, desk)) {
            desk[y][x + 1] = figure_counter;
            desk[y + 1][x] = figure_counter;
            desk[y + 1][x + 1] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x, y, x+1, y, x+1, y+1, desk)) {
            desk[y][x] = figure_counter;
            desk[y][x + 1] = figure_counter;
            desk[y + 1][x + 1] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x-1, y, x-1, y+1, x, y+1, desk)) {
            desk[y][x-1] = figure_counter;
            desk[y+1][x-1] = figure_counter;
            desk[y+1][x] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x - 1, y, x - 1, y+1, x, y, desk)) {
            desk[y][x - 1] = figure_counter;
            desk[y+1][x - 1] = figure_counter;
            desk[y][x] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x, y, x - 1, y+1, x, y+1, desk)) {
            desk[y][x] = figure_counter;
            desk[y + 1][x - 1] = figure_counter;
            desk[y + 1][x] = figure_counter;
            return true;
        } else if (check_figure_coordinates(x - 1, y, x, y, x, y+1, desk)) {
            desk[y][x - 1] = figure_counter;
            desk[y][x] = figure_counter;
            desk[y + 1][x] = figure_counter;
            return true;
        } else {
            return false;
        }
    }


    int next_x = x;
    int next_y = y;
    if (x == size - 2) {
        next_y++;
        next_x = 1;
    } else {
        next_x++;
    }

    if (y == size - 1) {
        return false;
    }

    int next_figure = figure_counter + 1;

    if (check_figure_coordinates(x, y, x, y+1, x+1, y+1, desk)) {
        desk[y][x] = figure_counter;
        desk[y + 1][x] = figure_counter;
        desk[y+1][x+1] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x] = -1;
            desk[y+1][x] = -1;
            desk[y+1][x+1] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x, y, x, y+1, x+1, y, desk)) {
        desk[y][x] = figure_counter;
        desk[y+1][x] = figure_counter;
        desk[y][x+1] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x] = -1;
            desk[y+1][x] = -1;
            desk[y][x+1] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x+1, y, x, y+1, x+1, y+1, desk)) {
        desk[y][x+1] = figure_counter;
        desk[y+1][x] = figure_counter;
        desk[y+1][x+1] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x+1] = -1;
            desk[y+1][x] = -1;
            desk[y+1][x+1] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x, y, x+1, y, x+1, y+1, desk)) {
        desk[y][x] = figure_counter;
        desk[y][x+1] = figure_counter;
        desk[y+1][x+1] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x] = -1;
            desk[y][x+1] = -1;
            desk[y+1][x+1] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x - 1, y, x-1, y+1, x, y+1, desk)) {
        desk[y][x - 1] = figure_counter;
        desk[y+1][x-1] = figure_counter;
        desk[y+1][x] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x - 1] = -1;
            desk[y+1][x-1] = -1;
            desk[y+1][x] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x - 1, y, x - 1, y+1, x, y, desk)) {
        desk[y][x - 1] = figure_counter;
        desk[y+1][x-1] = figure_counter;
        desk[y][x] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x - 1] = -1;
            desk[y+1][x - 1] = -1;
            desk[y][x] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x, y, x - 1, y+1, x, y+1, desk)) {
        desk[y][x] = figure_counter;
        desk[y+1][x - 1] = figure_counter;
        desk[y+1][x] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x] = -1;
            desk[y+1][x - 1] = -1;
            desk[y+1][x] = -1;
        } else {
            return true;
        }
    }

    if (check_figure_coordinates(x - 1, y, x, y, x, y+1, desk)) {
        desk[y][x - 1] = figure_counter;
        desk[y][x] = figure_counter;
        desk[y+1][x] = figure_counter;
        if (!rec_solving(next_figure, next_x, next_y, desk)) {
            desk[y][x - 1] = -1;
            desk[y][x] = -1;
            desk[y+1][x] = -1;
        } else {
            return true;
        }
    }

    return rec_solving(figure_counter, next_x, next_y, desk);

}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    last_figure_number = (int) (pow(2, 2 * n) - 1) / 3;

    int x, y;
    cin >> x >> y;

    size = (int) pow(2, n);

    int desk[512][512];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            desk[i][j] = -1;
        }
    }

    desk[y-1][x-1] = 0;

    rec_solving(1, 1, 0, desk);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << desk[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}