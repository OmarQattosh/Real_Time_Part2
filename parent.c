#include "local.h"

// static ushort semPal[2];
// static ushort semJor[2];
// static ushort semFor[2];

void main(int argc, char *argv[])
{

    key_t key;

    char u_char = 'A';
    MESSAGE msg; // MESSAGE is defiend in the local.h
    void process_msg(char *, int);

    int num_of_pass = 10;
    int passchance = 0;
    srand(time(0));
    // num_of_pass = (int)(10 + rand() % 400);
    struct passanger pasngrs[num_of_pass];
    FILE *fptr_input;

    key_t ipc_key;
    // read the input file
    char inp_file_values[25][40];

    if ((fptr_input = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("INPUT_FILE");
        exit(-1);
    }

    // reading the file
    for (int i = 0; i < 25; i++)
    {
        fscanf(fptr_input, "%s\n", inp_file_values[i]);
        printf("file_values[%d] = %s  \n", i, inp_file_values[i]);
    }

    // static ushort semPal[2] = {inp_file_values[7], 0};  // number of officers in semaphore
    // static ushort semJor[2] = {inp_file_values[9], 0};  // number of officers in semaphore
    // static ushort semFor[2] = {inp_file_values[11], 0}; // number of officers in semaphore
    int mid[num_of_pass];
    int numPal = num_of_pass * atof(inp_file_values[1]);
    int numJor = num_of_pass * atof(inp_file_values[3]);
    int numFor = num_of_pass - numPal - numJor; //um_of_pass * atof(inp_file_values[5];

    // filling the structure array
    for (int j = 0; j < num_of_pass; j++)
    {

        if (j < numPal)
        {

            pasngrs[j].nationality = 'P';
            pasngrs[j].P_lvl = (int)(1 + rand() % 5);
            // srand(time(0));
            passchance = (int)(1 + rand() % 99);
            if (passchance > 10)
                pasngrs[j].havepassport = 1;
            else
                pasngrs[j].havepassport = 0;
            printf("Nation = %c  and %d\n", pasngrs[j].nationality, j);
        }
        else if (j >= numPal && j < (num_of_pass - numFor))
        {
            pasngrs[j].nationality = 'J';
            // srand(time(0));
            pasngrs[j].P_lvl = (int)(1 + rand() % 5);
            passchance = (int)(1 + rand() % 100);
            if (passchance > 10)
                pasngrs[j].havepassport = 1;
            else
                pasngrs[j].havepassport = 0;
            printf("Nation = %c  and %d\n", pasngrs[j].nationality, j);
        }
        else
        {
            pasngrs[j].nationality = 'F';
            pasngrs[j].P_lvl = (int)(1 + rand() % 5);
            passchance = (int)(1 + rand() % 100);
            if (passchance > 10)
                pasngrs[j].havepassport = 1;
            else
                pasngrs[j].havepassport = 0;
            printf("Nation = %c  and %d\n", pasngrs[j].nationality, j);
        }
    }

    // message queue is created
    for (int k = 0; k < 3; k++, u_char++)
    {
        key = ftok(".", u_char);
        if ((mid[k] = msgget(key, IPC_CREAT | 0666)) == -1)
        {
            perror("Queue create");
            exit(1);
        }
    }
    // generate random sequence

    int randarray[num_of_pass];
    //int randpass = rand() % num_of_pass;
    for (int k = 0; k < num_of_pass; k++)
    {
        randarray[k] = k;
    }
    for (int k = 0; k < num_of_pass; k++)
    {
        int temp = randarray[k];
        int randomIndex = rand() % num_of_pass;
        randarray[k] = randarray[randomIndex];
        randarray[randomIndex] = temp;
    }

    for (int j = 0; j < num_of_pass; j++)
    {
        if (randarray[j] < numPal)
        {
            if (msgsnd(mid[0], &pasngrs[randarray[j]], sizeof(pasngrs[randarray[j]]), 0) == -1)
            {
                perror("Error: msgsnd PAlestinian");
                exit(-1);
            }
        }
        else if (randarray[j] >= numPal && randarray[j] < (num_of_pass - numFor))
        {
            if (msgsnd(mid[1], &pasngrs[randarray[j]], sizeof(pasngrs[randarray[j]]), 0) == -1)
            {
                perror("Error: msgsnd Jordanian");
                exit(-2);
            }
        }
        else
        {
            if (msgsnd(mid[2], &pasngrs[randarray[j]], sizeof(pasngrs[randarray[j]]), 0) == -1)
            {
                perror("Error: msgsnd Foriegn");
                exit(-3);
            }
        }
    }
    char qid[3][10];
    sprintf(qid[0], "%d", mid[0]);
    sprintf(qid[1], "%d", mid[1]);
    sprintf(qid[2], "%d", mid[2]);
    printf("%s  \n", qid[0]);
    printf("%s  \n", qid[1]);
    printf("%s  \n", qid[2]);
    execl("./officers", qid[10], NULL);

    //  msgctl(mid, IPC_RMID, (struct msqid_ds *) 0 );
    // All passengers arrives randomly

    //num_of_pass = (int)(1 + rand() % 199);
    printf("number of passengers = %d\n", num_of_pass);
}
