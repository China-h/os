#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fa,*fb;
	long alen,blen,len,i,j;
	if (argc != 6)
	{
		printf("%s 目标文件 扇区 源文件 扇区 长度\n",argv[0]);
		exit(1);
	}
	alen = strtol(argv[2],NULL,10) * 512;
	blen = strtol(argv[4],NULL,10) * 512;
	len = strtol(argv[5],NULL,10);
	fa = fopen(argv[1],"wb");
	if (fa == NULL)
	{
		printf("打开目标文件错误\n");
		exit(1);
	}
	fb = fopen(argv[3],"rb");
	if (fb == NULL)
	{
		printf("打开源文件错误\n");
		fclose(fa);
		exit(1);
	}

	fseek(fa,alen,SEEK_SET);
	fseek(fb,blen,SEEK_SET);
	for (i = 0 ;i < len; i++)
	{
		for (j = 0 ;j < 512; j++)
		{
			fputc(fgetc(fb),fa);
		}
	}

}


