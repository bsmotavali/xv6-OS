/* Hello World program */

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
  int count = 1;

  //for(i = 1; i < argc; i++)
    //printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");
    //int n = 10000;
    //int c = 50;
    //i = 0; 
  //for(i = 0; i<n; i++){
    // for(i = 0; i<c; i++){
      //  count = count + 1;
        //printf(1,"Hello World ...\n");
        //exit();
//}
//}
  
  int pid;
  // Fork a process to count to 4 and save state
  pid = fork();
  if (pid < 0) {
        printf(1, "Fork error! \n");
        exit();
    }
  if (pid == 0) {
        int i;
        for (i = 0; i < 4; i++) {
            count++;
            printf(1, "Counted Number : %d\n", count);
            sleep(50);
        }
        // Call to procsave to save process state
        // PC will remain here
        procsave();
        // Reload process it should start PC from here
        for (i = 4; i < 8; i++) {
            count++;
            printf(1, "Counted Number : %d\n", count);
            sleep(50);
        }
    }
    else {
        sleep(500);
        procload();
    }

    wait();
    exit();

}
