#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "fs.h"
#include "file.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// added system calls
// save process state to memory
int
sys_procsave(void)
{
  cprintf("Save System Call");
  //uint size = proc->sz;                     // Size of process memory (bytes)
  //pde_t* paget = proc->pgdir;                // Page table
  //char *kstack = proc->kstack;                // Bottom of kernel stack for this process
  //enum procstate pstate = proc->state;        // Process state
  //int proid = proc->pid;                     // Process ID
  //struct proc *pproc = proc->parent;         // Parent process
  //struct trapframe *trapf = proc->tf;        // Trap frame for current syscall
  //struct context *proccontext = proc->context;     // swtch() here to run process
  //void *procchan = proc->chan;                  // If non-zero, sleeping on chan
  //int prockill = proc->killed;                  // If non-zero, have been killed
  //struct file *openfile[NOFILE]; strcpy (openfile,proc->ofile);  // Open files
  //struct inode *currentdi = proc->cwd;           // Current directory
  //char procname[16]; strcpy (procname, proc->name);              // Process name (debugging)

  // Allocate file to save data
  //struct file* filealloc(void);
  return procsave();
}

// load saved process state to cpu
int
sys_procload(int procid)
{
 cprintf("Load System Call");
 return procload();
}
