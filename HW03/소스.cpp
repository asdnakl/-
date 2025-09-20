#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
    //��ź�� �׻� 7ĭ
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )");
}

int main()
{
    // ������� �ڵ带 �ۼ��ϼ���----------------------
    int bombX = 5, bombY = 6;
    int centerX = 14, centerY = 9;
    int pathX[MAX_PATH], pathY[MAX_PATH];
    int numPoints = 30;


    moveCursor(bombX, bombY);
    printBomb(0);


    int x = centerX, y = centerY;
    int dx[] = { 0, -1, 0, 1 };
    int dy[] = { -1, 0, 1, 0 };
    int dir = 0, stepSize = 1, stepCount = 0, changeDir = 0;

    for (int i = 0; i < numPoints; i++) {
        pathX[i] = x;
        pathY[i] = y;

        moveCursor(x, y);
        printf("#");

        x += dx[dir];
        y += dy[dir];
        stepCount++;

        if (stepCount == stepSize) {
            stepCount = 0;
            dir = (dir + 1) % 4;
            changeDir++;
            if (changeDir % 2 == 0) stepSize++;
        }
    }


    for (int i = 0; i < numPoints; i++) {
        if (i > 0) {
            moveCursor(pathX[i - 1], pathY[i - 1]);
            printf(" ");
        }
        moveCursor(pathX[i], pathY[i]);
        printf("*");
        Sleep(200);
    }


    moveCursor(bombX, bombY);
    printBomb(1);

    // ������ Ŀ�� ��ġ
    moveCursor(0, 20);
    return 0;
}