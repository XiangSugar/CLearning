# include <stdio.h>
# define MAX 10 //二进制数组的最大长度

int count;  //统计用户输入的总字符个数
int htoi(char s[]);  

int main()
{
	int c, i;
	extern int count;
	count = 0;
	int result;  //存储最终的转换结果
	char Input[MAX];  //用于存储用户的输入
	//初始化输入
	for (i = 0; i < MAX; ++i) {
		Input[i] = '\0';
	}
	// for(i = 0; i < MAX; ++i){
	// 	printf("%3d", Input[i]);
	// }
	// printf("\n");
	i = 0;
	while ((c = getchar()) != 's' && c != 'S') {
		Input[i] = c;
		++count;
		++i;
		if (i >= MAX) {
			printf("Error:The date has overflowed the length of limitation!\n");
			return 0;
		}
	}
	for(i=0; i<count; ++i){
		printf("%c", Input[i]);
	}
	printf("\n");
	//调用转换函数
	result = htoi(Input);
	//对转换结果进行判断
	if (-1 == result){
		return 0;
	}
	else{
		printf("The result = %d\n", result);
	}

	return 0;
}

int htoi(char s[])
{
	int i;
	extern int count;
	int n = 0;  //存储每一步转化后的计算结果
	int temp = 0; //存储字符串中当前位对应的的int类型的值
	int flag = 0;  //用于标识是否需要跳过 ‘0x’ 或 ‘0X’ 的开头
	if (s[0] == '0') {
		flag = 2;
	}
	else {
		flag = 0;
	}
	for (i = flag; i < count; ++i) {
		//判断输入的字符是否满足十六进制数的标准
		if (('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') || ('A' <= s[i] && s[i] <= 'F')) {
			if ('0' <= s[i] && s[i] <= '9') {
				temp = s[i] - '0';
				printf("s[i] = %d, temp1 = %d\n", s[i], temp);
			}
			else if ('a' <= s[i] && s[i] <= 'f') {
				temp = s[i] - 'a' + 10;
				printf("s[i] = %d, temp2 = %d\n", s[i], temp);
			}
			else if ('A' <= s[i] && s[i] <= 'F'){
				temp = s[i] - 'A' + 10;
				printf("s[i] = %d, temp3 = %d\n", s[i], temp);
			}
		}
		//对于不满足标准的情况报错，并结束程序
		else {
			printf("Error: The value entered does not match the hexadecimal number standard!");
			return -1;
		}
		
		printf("i = %d\n", i);

		n = n * 16 + temp;
	}
	return n;
}