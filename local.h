#ifndef __LOCAL_H__
#define __LOCAL_H__

/*
 * Common header file for Message Queue Example
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_FILE "./input.txt"

union semun
{
  int val;
  struct semid_ds *buf;
  ushort *array;
};

struct passanger
{
    char nationality;
    int havepassport;
    int P_lvl;
};

typedef struct
{
  long msg_to; /* Placed in the queue for */
  long msg_fm; /* Placed in the queue by  */
  struct passanger buffer[BUFSIZ];
} MESSAGE;

// static struct sembuf acquire = {0, -1, SEM_UNDO},
//                      release = {0, 1, SEM_UNDO};

#endif
