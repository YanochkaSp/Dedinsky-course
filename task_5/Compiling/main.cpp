#include "compiling.h"

int main (int argc, char* argv[])
{
    FILE *fnames = fopen (SRC_FILE, "r"); // файл с названиями команд
    assert (fnames != NULL);
    FILE *fnumbers = fopen (OUTPUT_FILE, "w"); // файл с номерами команд
    assert (fnumbers != NULL);

    NameToNum (fnames, fnumbers);
    
    fclose (fnames); 
    fclose (fnumbers);
}

void NameToNum (FILE *fnames, FILE *fnumbers)
{
    char *command = (char*)calloc(MAX_LINE_LEN, sizeof(char));
    int commandNum = 0;
    while (fgets (command, MAX_LINE_LEN, fnames) != NULL)
    {
        command[strcspn(command, "\n")] = '\0';
        for (size_t i = 0; i < sizeof(COMMANDS)/sizeof(COMMANDS[0]); ++i)
        {
            if (strcmp(command,COMMANDS[i]) == 0)
            {
                commandNum = i;
            }
            if (strcmp(command,"out")  == 0)
            {
                commandNum = -1;
            }
        }
        fprintf (fnumbers, "%d\n", commandNum);
    }
}

