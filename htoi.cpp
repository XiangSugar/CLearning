# include <stdio.h>
# define MAX 10 //�������������󳤶�

int count;  //ͳ���û���������ַ�����
int htoi(char s[]);  

int main()
{
	int c, i;
	extern int count;
	count = 0;
	int result;  //�洢���յ�ת�����
	char Input[MAX];  //���ڴ洢�û�������
	//��ʼ������
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
	//����ת������
	result = htoi(Input);
	//��ת����������ж�
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
	int n = 0;  //�洢ÿһ��ת����ļ�����
	int temp = 0; //�洢�ַ����е�ǰλ��Ӧ�ĵ�int���͵�ֵ
	int flag = 0;  //���ڱ�ʶ�Ƿ���Ҫ���� ��0x�� �� ��0X�� �Ŀ�ͷ
	if (s[0] == '0') {
		flag = 2;
	}
	else {
		flag = 0;
	}
	for (i = flag; i < count; ++i) {
		//�ж�������ַ��Ƿ�����ʮ���������ı�׼
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
		//���ڲ������׼�������������������
		else {
			printf("Error: The value entered does not match the hexadecimal number standard!");
			return -1;
		}
		
		printf("i = %d\n", i);

		n = n * 16 + temp;
	}
	return n;
}