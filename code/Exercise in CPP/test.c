
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static const char *FLAG = "-d1";
static const char *EXTENSION = ".deck";

int is_deck_file(char const *string)
{
    int length = strlen(string);

    if (length < 6)
        return 0;
    if (strcmp(string + (length - 5),EXTENSION ) == 0)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int fd = -2;

    for (unsigned int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],FLAG) == 0)
        {
            if ( i+1 < argc && is_deck_file(argv[i+1]))
            {
                i++;
                fd = open(argv[i], O_RDONLY);
            }
            else
            {
                dprintf(2, "Error: %s flag must be followned by a filepath.\n", FLAG);
            }
        }
        
    }
    if (fd == -2)
        dprintf(2, "No file was provided.\n");
    else if (fd == -1)
        dprintf(2, "Unable to open file.\n");
    else
        dprintf(1, "File provided, with right extension!\n");
}
