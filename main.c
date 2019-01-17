

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


extern int my_file_operation();

int main()
{
	my_file_operation();

	return 0;
}
