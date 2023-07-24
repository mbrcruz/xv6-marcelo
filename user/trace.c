#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
  char **args;
  int i,nargs, trace_id;
  if ( argc <= 3)
  {
   printf("Usage %s [code] cmd args\n",argv[0]);
  }
  trace_id = atoi(argv[1]);
  trace(trace_id);
  nargs=argc - 3;
  args=(char**)malloc(sizeof(char*)* nargs);

  for(i=0;i<nargs;i++){
  	args[i] = (char*) malloc(sizeof(char)*strlen(argv[i+3]));
  	memcpy(args[i],argv[i+3],strlen(argv[i+3]));
  }
  exec(argv[2],args);
  trace(0);
  return 0;
}
