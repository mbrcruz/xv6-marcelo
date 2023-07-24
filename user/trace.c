#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
  char **args;
  if ( argc <= 3)
  {
   printf("Usage %s [code] cmd args\n",argv[0]);
  }
  args=(char**)malloc(sizeof(char*)* 1);
  args[0] = (char*) malloc(sizeof(char)*strlen(argv[3]));
  memcpy(args[0],argv[3],strlen(argv[3]));
  exec(argv[2],args);
  return 0;
}
