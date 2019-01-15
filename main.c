

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	//
	IMPORT_BUFF_APPEND_CREATE, // add to the tail
	IMPORT_BUFF_TAIL_DELETE_OLD_FILE,  // add to the head remove the old data first,
	
	IMPORT_BUFF_HEAD_CREATE,	 // add to the head
	IMPORT_BUFF_HEAD_DELETE_OLD_FILE, // add to the head remove the old data,

	
	//IMPORT_NUM_APPEND_CREATE, // add to the tail, if file no exist then create.
	//IMPORT_NUM_TAIL_DELETE_OLD_FILE,  // add to the tail remove the old data first, if exist then remove and create new.
	
	//IMPORT_NUM_HEAD_CREATE,	 // add to the head
	//IMPORT_NUM_HEAD_DELETE_OLD_FILE, // add to the head remove the old data,



	IMPORT_MAX,
	
}E_C_FILE_IMPORT_MODE;


int C_FILE_OPERATOR_import_data(char * fileName, E_C_FILE_IMPORT_MODE eimportMode, void * buff, unsigned int ByteNum)
{
	if(!fileName || eimportMode > IMPORT_MAX || !buff)
	{
		printf("param err!%s:%d\n",__func__, __LINE__);
		return -1;
	}
	static FILE *fp = NULL;
	int ret = -1;
	
	switch(eimportMode)
	{
		case IMPORT_BUFF_APPEND_CREATE:
			if(0 == access(fileName, F_OK))
			{
				
			}
			else
			{
				char buff[128] = {0};
				sprintf(buff, "touch %s", fileName);
				system(buff);
				if(0 != access(fileName, F_OK))
				{
					printf("touch file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
			}

			if(!fp)
			{
				fp = fopen(fileName, "r+");
				if(!fp)
				{
					printf("open file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
				
				ret = fseek(fp, 0L, SEEK_END);
				if(0!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}

				ret = fwrite(buff, 1, ByteNum, fp);
				if(ByteNum!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}				

				fclose(fp);

				fp = NULL;
				
			}
			else
			{
				printf(" err! %s:%d\n",__func__, __LINE__);
			}
			break;
		case IMPORT_BUFF_TAIL_DELETE_OLD_FILE:
			if(0 == access(fileName, F_OK))
			{
				char buff[128] = {0};
				sprintf(buff, "rm %s", fileName);
				system(buff);
				if(0 == access(fileName, F_OK))
				{
					printf("rm file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}			
				else
				{
					char buff[128] = {0};
					sprintf(buff, "touch %s", fileName);
					system(buff);
					if(0 != access(fileName, F_OK))
					{
						printf("touch file err! %s:%d\n",__func__, __LINE__);
						return -1;
					}						
				}				
				
			}
			else
			{
			
				char buff[128] = {0};
				sprintf(buff, "touch %s", fileName);
				system(buff);
				if(0 != access(fileName, F_OK))
				{
					printf("touch file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
			}

			if(!fp)
			{
				fp = fopen(fileName, "r+");
				if(!fp)
				{
					printf("open file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
				
				ret = fseek(fp, 0L, SEEK_END);
				if(0!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}

				ret = fwrite(buff, 1, ByteNum, fp);
				if(ByteNum!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}				

				fclose(fp);

				fp = NULL;
				
			}
			else
			{
				printf(" err! %s:%d\n",__func__, __LINE__);
			}			
			break;
		case IMPORT_BUFF_HEAD_CREATE:
			if(0 == access(fileName, F_OK))
			{
				
			}
			else
			{
				char buff[128] = {0};
				sprintf(buff, "touch %s", fileName);
				system(buff);
				if(0 != access(fileName, F_OK))
				{
					printf("touch file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
			}

			if(!fp)
			{
				fp = fopen(fileName, "r+");
				if(!fp)
				{
					printf("open file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
				
				ret = fseek(fp, 0L, SEEK_SET);
				if(0!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}

				ret = fwrite(buff, 1, ByteNum, fp);
				if(ByteNum!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}				

				fclose(fp);

				fp = NULL;
				
			}
			else
			{
				printf(" err! %s:%d\n",__func__, __LINE__);
			}			
			break;
		case IMPORT_BUFF_HEAD_DELETE_OLD_FILE:

			if(0 == access(fileName, F_OK))
			{
				char buff[128] = {0};
				sprintf(buff, "rm %s", fileName);
				system(buff);
				if(0 == access(fileName, F_OK))
				{
					printf("rm file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}			
				else
				{
					char buff[128] = {0};
					sprintf(buff, "touch %s", fileName);
					system(buff);
					if(0 != access(fileName, F_OK))
					{
						printf("touch file err! %s:%d\n",__func__, __LINE__);
						return -1;
					}	
				}					
			}
			else
			{			
				char buff[128] = {0};
				sprintf(buff, "touch %s", fileName);
				system(buff);
				if(0 != access(fileName, F_OK))
				{
					printf("touch file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
			}

			if(!fp)
			{
				fp = fopen(fileName, "r+");
				if(!fp)
				{
					printf("open file err! %s:%d\n",__func__, __LINE__);
					return -1;
				}
				
				ret = fseek(fp, 0L, SEEK_SET);
				if(0!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}

				ret = fwrite(buff, 1, ByteNum, fp);
				if(ByteNum!=ret)
				{
					printf("fseek file err! %s:%d\n",__func__, __LINE__);
					return -1;					
				}				

				fclose(fp);

				fp = NULL;
				
			}
			else
			{
				printf(" err! %s:%d\n",__func__, __LINE__);
			}			
			break;

		default:
			printf(" err! %s:%d\n",__func__, __LINE__);
			break;
		
	}

	return 0;
}

int main()
{
	char buff[128] = "test.file";
	char buff1[128] = {0};
	int i = 0;
	while(1)
	{
		sprintf(buff1, "test %d\n",i++);
		static int flag = -1;
		if(flag == -1)
		{
			C_FILE_OPERATOR_import_data(buff, IMPORT_BUFF_TAIL_DELETE_OLD_FILE, buff1, strlen(buff1));
			flag = 1;
		}
		else
		{
			C_FILE_OPERATOR_import_data(buff, IMPORT_BUFF_APPEND_CREATE, buff1, strlen(buff1));
		}
		usleep(1000*1000);
	}
	
	return 0;
}
