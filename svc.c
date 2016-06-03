/*
 ============================================================================
 Name        : svc.c
 Author      : suneha
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp1, *fp2;
	char filename[40];
	char c;
	int del_line,temp=1;
	printf("Enter filename:");
	scanf("%s", filename);
	fp1=fopen(filename,"r");        //open file in read mode
	c=getc(fp1);
	while(c!=EOF)                   //until the last character of file  is obtained 
	{
		printf("%c",c);         //print current character and read next character
		c=getc(fp1);       
	}
	rewind(fp1);                   //rewind
	printf("\nEnter line number of the line to be deleted");
	scanf("%d",&del_line);
	fp2=fopen("copy.c","w");
	c=getc(fp1);
	while(c!=EOF)
	{
		c=getc(fp1);
		if(c=='\n')
			temp++;       //except the line to be deleted
		if(temp!=del_line)
		{
			putc(c,fp2);       //copy all lines in file copy.c
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove(filename);                 //remove original file
	rename("copy.c",filename);
	printf("\nThe content of file after being modification are as follow:");
	fp1=fopen(filename,"r");
	c=getc(fp1);
	while(c!=EOF)
	{
		printf("%c",c);
		c=getc(fp1);

	}
	fclose(fp1);
	return 0;
}

