#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp;
	char ch;
	int count = 0;         // 字符数
	int num = 0;           // 单词数
	int flag=0;
	int flag1=1;           // 输入合法性判断 
	char od[22];           // 读取输入的所有字符 
	char order[2];         // 指令 c/w
	char fileName[20];     // 文件名 
	int i;
	int j=0;

	do {
		flag1=1;
		gets(od);
		if(od[0]!='-' || od[2]!=' ') {
			flag1=0;
		}
		if(od[1]!='c' && od[1]!='w') {
			flag1=0;
		}
		if(flag1==0) {
			printf("格式错误请重新输入！格式：“-c/w 文件名”\n");
		}
		if(flag1==1) {
			order[0] = od[0];
			order[1] = od[1];
			for(i=3; od[i]!='\0'; i++) {
				fileName[j]=od[i];
				j++;
			}
			fileName[j]='\0';
			if((fp=fopen(fileName,"r+"))==NULL) {
				flag1=0;
				printf("文件不存在，请重新输入\n");
				j=0;
			}
		}
	} while(flag1!=1);

	while((ch=fgetc(fp)) != EOF) {
//		putchar(ch);
		count++;
		if(ch != ' ' && ch != ',' && flag == 0) {
			flag = 1;
		}
		if(flag==1 && (ch == ' ' || ch == ',')) {
			num++;
			flag=0;
		}
	}
	if(flag==1) {
		num++;
	}
	if(order[1]=='c') {
		printf("字符数 = %d\n",count);
	} else {
		printf("单词数 = %d\n",num);
	}
	fclose(fp);
	return 0;
}

