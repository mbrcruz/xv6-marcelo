#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include <stddef.h>


int main(int argc,char **argv){


	struct sysinfo info;
	sysinfo(&info);
	printf("free mem pages=%d\n",info.pages);
	printf("Number running processes=%d\n",info.procs);
	return 0;
}
