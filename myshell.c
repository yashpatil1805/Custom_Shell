#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
void count(char c,char*fn)
{
	int lc=0,cc=0,wc=0,handle;
	char ch;
	if((handle=open(fn,O_RDONLY))==-1)
	{
		printf("file %s not found\n",fn);
		return;
	}
	while(read(handle,&ch,1)!=0)
	{
		if(ch==' ')
			wc++;
		else if(ch=='\n'){
			lc++;
			wc++;
		}
		else
			cc++;
	}
	close(handle);
	switch(c)
	{
		case 'c':
			printf("\nTotal number of characters=%d\n",cc);
			break;
		case 'l':
			printf("\nTotal number of lines=%d\n",lc);
			break;
		case 'w':
			printf("\nTotal number of words=%d\n",wc);
			break;
		default:
			printf("\n Invalid");
	}
}
int main(){
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n;
	system("clear");
	while(1)
	{
		printf("myshell$");
		/*fflush(stdin) is used to flush or clear the output buffer of the stream.When it is used after the scanf(),it flushes the input buffer also.It returns zero if successful,otherwise returns EOF*/
		fflush(stdin);
		fgets(command,80,stdin);
		/*sscanf() function is used to read formatted input from a string*/
		n=sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
		switch(n){
			case 1:
				if(fork()==0){
					/*execlp replaces the calling process image with a new process image
					 * This has the efffect of running a new program with the process ID of the calling process.*/
					execlp(t1,t1,NULL);
					perror(t1);
				}
				break;
			case 2:
				if(!fork())
				{
					execlp(t1,t1,t2,NULL);
					perror(t1);
				}
				break;
			case 3:
				if(strcmp(t1,"count")==0)
					count(t2[0],t3);
				else{
					if(!fork()){
						execlp(t1,t1,t2,t3,NULL);
						perror(t1);
					}
				}
				break;
			case 4:
				if(!fork())
				{
					execlp(t1,t1,t2,t3,t4,NULL);
					perror(t1);
				}
		}
	}
}