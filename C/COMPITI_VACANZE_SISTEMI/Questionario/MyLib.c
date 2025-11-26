#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "MyLib.h"

//------------------------------- Function to add a question
void aggiungi_domanda(void)
{
    FILE *file_handle = fopen("questionario.txt","a"); // Opens the file in append mode
    int i, e;
    char* domanda = calloc(1,250); // Variable used to store the question
    char* opzione = calloc(1,250); // Variable used to store the option
    char giusta;
    char c = 65;  // Variable used to store the character for the options

    printf("\nInsert question:");

    while ((e = getchar()) != '\n');  // Clears the input buffer, checking for a newline character
    fgets(domanda, 250, stdin);       // Reads the question from the keyboard

    fprintf(file_handle,"%d. %s",indice,domanda); // Writes the question to the file

    printf("Insert the 4 options:\n");

    // Reads the options from the keyboard and writes them to the file
    for (i=0; i<4; i++)
    {
        fgets(opzione, 250, stdin);
        fprintf(file_handle,"%c:%s",c,opzione);
        c++; // Increments the character for the options
    }

    printf("Insert the correct option\n");

    scanf("%c",&giusta); // Reads the correct answer
    fprintf(file_handle,"%c\n",toupper(giusta)); // Writes the correct answer to the file

    fclose(file_handle); // Closes the file
    indice++;            // Increments the question index
    // Frees the allocated memory
    free(domanda);
    free(opzione);
}
//------------------------------- Function to administer the questionnaire to the user
void somministra_questionario(void)
{
    FILE *file_handle = fopen("questionario.txt","r"); // Opens the file in read mode
    char risposta;
    char corretta;
    char line[250]; // Variable used to store the read line
    size_t len = sizeof(line);
    int punteggio = 0;
    int i;

    // Loops through the sequence of questions and answers
    while (fgets(line,len,file_handle) != NULL)
    {
        fflush(stdin); // Clears the keyboard buffer
        printf("\n");
        for (i = 0; i < 5; i++)
        {
            printf("%s",line);
            fgets(line,len,file_handle); // Moves to the next line
        }

        corretta = line[0]; // Takes the first character (the correct answer)

        printf("Insert the correct answer:");
        scanf("%c",&risposta); // Reads the user's answer

        // Checks if the answer is correct, if so increments the score
        if (toupper(risposta) != corretta )
        {
            printf("\nWrong answer.\n");
        }
        else
        {
            printf("\nCorrect answer.\n");
            punteggio++;
            printf("\nScore: %d\n\n", punteggio);
        }

    }
    fclose(file_handle); // Closes the file
}

//------------------------------- Function to delete a question
void cancella_domanda()
{
    FILE *file_handle = fopen("questionario.txt", "r");
    int i;
    size_t len;
    char line[250];

    // Displays the list of questions
    while(fgets(line, sizeof(line), file_handle) != NULL)
    {
        len = strlen(line);
        if (len > 50) // If the line is longer than 50 characters, truncate it
        {
            line[50] = '\0';
            printf("%s...\n", line);
        }
        else
        {
            printf("%s", line);
        }

        for(i = 0; i < 5; i++) // Skip the next 5 lines (the options and the correct answer)
            fgets(line, sizeof(line), file_handle);
    }
    fclose(file_handle);

    // Asks the user which question to delete
    unsigned int question = 0;
    printf("\nChoose which question to delete: ");
    scanf("%u", &question);

    FILE *file_handle2 = fopen("questionario.txt", "r");
    FILE *appoggio = fopen("questionario_appoggio.txt", "w");

    // Copies all questions except the one to be deleted into a temporary file
    int flag = 0;

    while(fgets(line, sizeof(line), file_handle2) != NULL)
    {
        unsigned int n = 0;
        char s[250];

        // Reads the question number and text
        sscanf(line, "%u %[^\n]", &n, s);
        if (n != question)
        {
            if(flag == 0)
            {
                fprintf(appoggio, "%s", line);
            }
            else // If this is not the first question, decrement the question number
            {
                fprintf(appoggio, "%u%s\n", n - 1, s);
            }

            for(i = 0; i < 5 ; i++)
            {
                if (fgets(line, sizeof(line), file_handle2) != NULL)
                    fprintf(appoggio, "%s", line);
            }
        }
        else // If it's the question to delete, skip the next 5 lines
        {
            flag = 1;
            for(i = 0; i < 5; i++)
                fgets(line, sizeof(line), file_handle2);
        }
    }

    // Close the files and replace the original file with the temporary one
    fclose(file_handle2);
    fclose(appoggio);
    remove("questionario.txt");
    rename("questionario_appoggio.txt", "questionario.txt");

}
