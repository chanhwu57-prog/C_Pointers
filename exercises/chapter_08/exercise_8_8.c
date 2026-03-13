#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N];
int solution_count = 0;

bool is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col) {
            return false;
        }
        if (board[i] - i == col - row) {
            return false;
        }
        if (board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void print_board(void) {
    printf("Solution %d:\n", solution_count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == N) {
        solution_count++;
        print_board();
        return;
    }
    
    for (int col = 0; col < N; col++) {
        if (is_safe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main(void) {
    printf("Solving %d-Queens problem...\n\n", N);
    solve(0);
    printf("Total solutions: %d\n", solution_count);
    return 0;
}
