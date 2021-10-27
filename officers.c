#include "local.h"

void main(int argc, char *argv[])
{
    char str [10] = argv[1];
    int qid[3][10];
    qid[0] = atoi(str [0]);
    qid[1] = atoi(str [1]);
    qid[2] = atoi(str [2]);
    printf(" %d \n", qid[0]);
    printf(" %d \n", qid[1]);
    printf(" %d \n", qid[2]);

    // if( (msgrcv(mid[0],  &pasngrs[randarray[j]], sizeof(pasngrs[randarray[j]]),0) == -1 ){
    //     perror("Error: msgrcv");
    //     exit(-2);
    // }
    // else {
    //     printf("%s\n", pasngrs[randarray[j]].nationality);
    // }
    // if( ( msgrcv(mid[1],  &pasngrs[randarray[j]], sizeof(pasngrs[randarray[j]]),0) == -1 ){
    //     perror("Error: msgrcv");
    //     exit(-2);
    // }
    // else {
    //     printf("%s\n", pasngrs[randarray[j]].nationality);

    // }


    // if( (msgrcv(mid[2],  &pasngrs[randarray[j]], sizeof(pasngrs[randarray[j]]),0) == -1 ){
    //     perror("Error: msgrcv");
    //     exit(-2);
    // }
    // else {
    //     printf("%s\n", pasngrs[randarray[j]].nationality);

    // }
}