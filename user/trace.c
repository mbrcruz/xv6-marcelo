#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include <stddef.h>

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
  nargs=argc - 2;
  args=(char**)malloc(sizeof(char*)* nargs+1);

  for(i=0;i<nargs;i++){
  	args[i] = (char*) malloc(sizeof(char)*strlen(argv[i+2]));
  	memcpy(args[i],argv[i+2],strlen(argv[i+2]));
  }

  args[i]=NULL;
  exec(argv[2],args);
  trace(0);
  return 0;
}
