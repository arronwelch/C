#include <stdio.h>

// const int red = 0;
// const int yellow = 1;
// const int green = 2;

// enum COLOR
// {
//     RED,
//     YELLOW,
//     GREEN,
//     NumCOLORS
// };
enum COLOR
{
    RED = 1,
    YELLOW,
    GREEN = 5,
    NumCOLORS
};

int main(int argc, const char *argv[])
{
    int color = -1;
    char *ColorNames[NumCOLORS] = {"red", "yellow", "green"};
    char *colorName = NULL;

    printf("please input you like color code:");
    scanf("%d", &color);
    // switch (color)
    // {
    // case RED:
    //     colorName = "red";
    //     break;
    // case YELLOW:
    //     colorName = "yellow";
    //     break;
    // case GREEN:
    //     colorName = "green";
    //     break;
    // default:
    //     colorName = "unknown";
    //     break;
    // }

    if (color >= 0 && color < NumCOLORS)
    {
        colorName = ColorNames[color];
    }
    else
    {
        colorName = "unknown";
    }

    printf("you like color is:%s\n", colorName);

    return 0;
}