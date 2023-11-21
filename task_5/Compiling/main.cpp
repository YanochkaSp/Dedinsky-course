#include "compiling.h"

int main (int argc, char* argv[])
{
    FILE *fnames = fopen (SRC_FILE, "r"); // файл с названиями команд
    printf ("Opening file\n");
    assert (fnames != NULL);
    printf("1");
    FILE *fnumbers = fopen (OUTPUT_FILE, "w"); // файл с номерами команд
    assert (fnumbers != NULL);

    char *command = (char*)calloc(MAX_LINE_LEN, sizeof(char));
     
    int commandNum = 0;
    printf("2");
    while (fgets (command, MAX_LINE_LEN, fnames) != NULL)
    {
        command[strcspn(command, "\n")] = '\0';
        for (size_t i = 0; i < sizeof(COMMANDS)/sizeof(COMMANDS[0]); ++i)
        {
            if (strcmp(command,COMMANDS[i]) == 0)
            {
                commandNum = i;
            }
        }
        fprintf (fnumbers, "%d\n", commandNum);
        printf("3\n");
    }

    fclose (fnames); 
    fclose (fnumbers);
    printf ("Files are closed\n");
}



