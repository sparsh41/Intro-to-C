#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DELAY 100000
#define MAX_SNAKE_LENGTH 100
#define WIDTH 40
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

Point snake[MAX_SNAKE_LENGTH];
int snake_length = 5;
int dir_x = 1, dir_y = 0;
Point food;

void init_game();
void draw_board();
void move_snake();
int check_collision();
void generate_food();

int main() {
    int ch;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100); // getch() timeout

    srand(time(NULL));
    init_game();

    while (1) {
        ch = getch();
        switch (ch) {
            case KEY_UP:    if (dir_y != 1)  { dir_x = 0; dir_y = -1; } break;
            case KEY_DOWN:  if (dir_y != -1) { dir_x = 0; dir_y = 1; }  break;
            case KEY_LEFT:  if (dir_x != 1)  { dir_x = -1; dir_y = 0; } break;
            case KEY_RIGHT: if (dir_x != -1) { dir_x = 1; dir_y = 0; }  break;
            case 'q': endwin(); return 0;
        }

        move_snake();
        if (check_collision()) {
            break;
        }
        draw_board();
        usleep(DELAY);
    }

    endwin();
    printf("Game Over! Your score: %d\n", snake_length - 5);
    return 0;
}

void init_game() {
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = WIDTH / 2 - i;
        snake[i].y = HEIGHT / 2;
    }
    generate_food();
}

void draw_board() {
    clear();

    // Draw borders
    for (int x = 0; x < WIDTH + 2; x++) {
        mvprintw(0, x, "#");
        mvprintw(HEIGHT + 1, x, "#");
    }
    for (int y = 0; y < HEIGHT + 2; y++) {
        mvprintw(y, 0, "#");
        mvprintw(y, WIDTH + 1, "#");
    }

    // Draw snake
    for (int i = 0; i < snake_length; i++) {
        mvprintw(snake[i].y + 1, snake[i].x + 1, i == 0 ? "O" : "o");
    }

    // Draw food
    mvprintw(food.y + 1, food.x + 1, "*");

    refresh();
}

void move_snake() {
    Point new_head = { snake[0].x + dir_x, snake[0].y + dir_y };

    // Check food
    if (new_head.x == food.x && new_head.y == food.y) {
        snake_length++;
        generate_food();
    } else {
        for (int i = snake_length - 1; i > 0; i--) {
            snake[i] = snake[i - 1];
        }
    }

    snake[0] = new_head;
}

int check_collision() {
    if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
        return 1; // wall hit
    }

    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return 1; // self hit
        }
    }

    return 0;
}

void generate_food() {
    while (1) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int collision = 0;

        for (int i = 0; i < snake_length; i++) {
            if (snake[i].x == x && snake[i].y == y) {
                collision = 1;
                break;
            }
        }

        if (!collision) {
            food.x = x;
            food.y = y;
            break;
        }
    }
}
