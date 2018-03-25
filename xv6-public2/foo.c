#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{
	int k,n,id,priority;
	double x = 0, z,d;

	n = 1;
	d = 0.1;
	priority = 80;

	if(argc == 2) priority = atoi(argv[1]);


	// if(argc < 2) n = 1;
	// else n = atoi( argv[1]);
	// if( n < 0 || n > 20) n= 2;

	// if(argc < 3) d = 0.1;
	// else d = atoi( argv[2]);

	// if(argc < 4) priority = 70;
	// else d = atoi(argv[3]);

	x = 0;
	id = 0;
	for(k=0;k<n;k++) {
		id = fork();
		if(id < 0) printf(1,"%d failed in fork!\n",getpid());
		else if (id > 0) {
			printf(1,"Parent %d creating child", getpid(), id);
			wait();
		}
		else {
			printf(1,"Child %d created\n",getpid());
			set_priority(priority);
			for( z =0; z< 8000000.0; z +=d) {
				x = x + 3.14 * 89.64;
			}
			break;
		}
	}
	exit();
}
