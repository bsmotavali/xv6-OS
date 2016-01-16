
#include "types.h"
#include "user.h"
#include "fcntl.h"
//#include "param.h"
//#include "mmu.h"
//#include "proc.h"
//#include "spinlock.h"
//#include "syscall.h"

int _write_to_file();
int main(){

  printf(1,"my process started ...\n");
  int a =0 ;
  for( ; a< 100 ; a ++ ){
    if(a == 50){
      if(_write_to_file() >= 0)
        printf(1,"successfully...\n");
      else
        printf(1,"bad happen ...\n");
    }
  }

//  int pid = getpid();


  return 0;
}

int  _write_to_file()
{
//  struct proc *p;
  int fd;
  fd = open("/myCodes/ah.bin", O_CREATE | O_RDWR);

  printf(1, "file open status : %d\n", fd);
  char * s ="salam khubi";
//  p = getinfo(getpid());
//  printf(1, "%d \n", fd);
  int ss =  write(fd , s, sizeof s );
  printf(1, "\n write status :: %d  \n", ss);
  s="";
  int l = read(fd , s , 10);
  printf(1,"%d byte readed ... \n", l);
  printf(1, "\n read  :: %s  \n", s);
  return 1;
//  struct file *file;

//  write(fd, buf, 10);
//  int s = read(fd , buf , 10);
//  printf(1,"%s" , buf);
//  printf(1, "status :    %d\n", s);
//  filewrite(file, buf, 10);

}
