
#include <malloc.h>
#include<stdio.h>
#include<time.h>

typedef struct node_t {
    char frontSide;
    char mine;
    char backSide;
    int numbergrid;
} node_t;

void init(node_t **array, int row, int column) {

    array[row][column].frontSide = '.';
    array[row][column].mine = '*';
    array[row][column].backSide = '0';
    array[row][column].numbergrid = 0;

}
void testForMine(node_t **array, int x, int y) {
    if (x == 0 || y == 0)
        return;
    if (array[x][y].backSide != '*')
        array[x][y].backSide += 1;

}

void fill_board(node_t **array, int x, int y, double difficulty) {

    int i, row, column;

    int numberOfMines = (int) ((x * y) * difficulty);


    for (row = 0; row <= x; row++) {                     // fill board with'.'
        for (column = 0; column <= y; column++) {
            init(array, row, column);
        }
    }


    for (i = 1; i <= numberOfMines; i++) {                       // number of mines
        int numbers = 1;
        int y1 = (1 + rand() % y);
        int x1 = (1 + rand() % x);

        array[y1][x1].backSide = array[y1][x1].mine;
        // sets box to a mine
        testForMine(array, y1 + 1, x1);
        testForMine(array, y1 + 1, x1 + 1);
        testForMine(array, y1 + 1, x1 - 1);
        testForMine(array, y1 - 1, x1);
        testForMine(array, y1 - 1, x1 + 1);
        testForMine(array, y1 - 1, x1 - 1);
        testForMine(array, y1, x1 + 1);
        testForMine(array, y1 + 1, x1 - 1);

    }
    for (row = 1; row <= x; row++)
        array[row][0].numbergrid = row;
    for (column = 1; column <= x; column++)
        array[0][column].numbergrid = column;
}


int main(int argc, char **argv) {

    int x, y, input, i, adjustment = 2;
    int input1, input2;
    double difficulty = 0;
    node_t **array;
    srand((unsigned int) time(NULL));

    printf("Inter board size X Y\n");
    scanf("%d %d", &x, &y);

    printf("Enter the  difficulty 1, 2, or 3\n1:10%% mines\n2: 15%% mines\n3: 25%% mines\n");
    scanf("%d", &input);


    if (input = 1)
        difficulty = .10;
    else if (input = 2)
        difficulty = .15;
    else if (input = 3)
        difficulty = .25;


    array = (node_t **) malloc(sizeof(node_t *) * (x + adjustment));

    for (i = 1; i < (x + adjustment); i++) {
        array[i] = (node_t *) malloc(sizeof(node_t) * (y + adjustment));
        // creating the grid
    }


}