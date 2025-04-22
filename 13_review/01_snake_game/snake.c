#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SNAKESIZE 50

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point body[MAX_SNAKESIZE];
    int length;
    int direction;
} Snake;

void initGame(Snake *snake, Point *fruit);
void draw(const Snake *snake, const Point *fruit);
void moveSnake(Snake *snake, Point *fruit, int *speed);


int main(){
    srand(time(0));
    // Create a snake
    Snake tom;
    Point fruit;
    
    // Initialize the paramters
    initGame(&tom, &fruit);
    int speed = 50000;
    
    // Game loop
    while (TRUE) {
        int ch = getch();
        if (tom.direction == KEY_RIGHT){
            if(ch == KEY_DOWN || ch == KEY_UP){
                tom.direction = ch;
            }
        }
        else if (tom.direction == KEY_LEFT){
            if(ch == KEY_DOWN || ch == KEY_UP){
                tom.direction = ch;
            }
        }
        else if (tom.direction == KEY_UP){
            if (ch == KEY_LEFT || ch == KEY_RIGHT){
                tom.direction = ch;
            }
        }
        else if (tom.direction == KEY_DOWN){
            if (ch == KEY_LEFT || ch == KEY_RIGHT){
                tom.direction = ch;
            }
        }


        draw(&tom, &fruit);
        usleep(speed);
        moveSnake(&tom, &fruit, &speed);
    }
    
    
    return 0;
}


void initGame(Snake *snake, Point *fruit){
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100);
    
    // Init the snake
    snake->length = 5;
    snake->direction = KEY_RIGHT;
    
    for (int i = 0; i < snake->length; i++){
        snake->body[i].x = 10-i;
        snake->body[i].y = 10;
    }
    
    // Init the fruit
    fruit->x = 20;
    fruit->y = 10;
}


void draw(const Snake *snake, const Point *fruit){
    clear();
    // Print the fruit
    mvprintw(fruit->y, fruit->x, "O");
    
    // Print the snake
    for(int i = 0; i < snake->length; i++){
        if (i == 0){
            mvprintw(snake->body[i].y, snake->body[i].x, "@");
        }
        else {
            mvprintw(snake->body[i].y, snake->body[i].x, "#");
        }
    }
    refresh();
}


void moveSnake(Snake *snake, Point *fruit, int *speed){
    Point new_head = snake->body[0];

    // Move the head
    if (snake->direction == KEY_RIGHT){
        new_head.x++;
    }
    else if (snake->direction == KEY_LEFT){
        new_head.x--;
    }
    else if (snake->direction == KEY_DOWN){
        new_head.y++;
    }
    else if (snake->direction == KEY_UP){
        new_head.y--;
    }

    // Move body
    for (int i = snake->length; i > 0; i--){
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = new_head;

    if (snake->body[0].x < 0 || snake->body[0].x >= COLS || snake->body[0].y < 0 || snake->body[0].y >= LINES){
        endwin();
        printf("Score: %d\n", snake->length - 5);
        exit(0);
    }

    // Head in body
    for (int i = 1; i < snake->length; i++) {
        if(new_head.x == snake->body[i].x && new_head.y == snake->body[i].y){
            endwin();
            printf("Score: %d\n", snake->length - 5);
            exit(0);
        }
    }
    

    // Eat fruit
    if (new_head.x == fruit->x && new_head.y == fruit->y){
        snake->length++;
        fruit->x = rand() % COLS;
        fruit->y = rand() % LINES;
        *speed -= 500;
    }
}