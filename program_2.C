scanf是C语言提供的
scanf_s不是标准C语言提供的，VS编译器提供的额，若使用此函数，则不具备可移植性/跨平台性

#define _CRT_SECURE_NO_WARNINGS 1//加在源文件的第一行。
//scanf 
//strcpy
//strlen
//strcat
//...以上都是C语言提供的库函数，理论上都是不安全的，所以需要加上#define _CRT_SECURE_NO_WARNINGS 1，以消除警告。

变量/常量
局部变量
在main函数里的变量是局部变量，但是局部变量不都全在main函数里，放在大括号内部的变量都是局部变量。

常量
C语言中的常量分为以下几种
字面常量
const 修饰的常变量
#define 定义的标识符常量
枚举常量


#include <stdio.h>

int main()
{
	//const--常属性
	//const修饰的常变量，当想让某个量不变时，可以用const
	//num本质属性还是变量，只是具有了常属性的特性（中国人去美国拿了绿卡，本质上还是中国人，只是取得了美国的身份。）
	int n = 10;
	int arr[n] = {0};//报错，应该输入常量表达式。
	
	const int n = 10;//n是变量，但是又有常属性，所以我们说n是常变量。
	int arr[n] = {0};//依然报错，应输入常量表达式。
	
	/*
	const int num = 4;
	printf("%d\n",num);
	//num = 8; 此时num为常量
	//printf("%d\n",num);
	3;//字面常量
	100;
	3.14;//从字面意思看就是个数值。
	*/
	return 0;
}

#define 定义的标识符常量

#include<stdio.h>

//#define 定义的标识符常量
#define MAX 10

int main()
{
	int arr[MAX] = {0}；
	printf("%d\n", MAX);//打印数值为10,
	return 0；
}

//枚举常量
//枚举：一一列举
//性别：男、女、保密
//三原色：红、黄、蓝
//星期：一、二、三、四、五、六、七
//枚举关键字： enum
#include<stdio.h>

enum Sex
{
	MALE,
	FEMALE,
	SECRET
};
//MALE,FEMALE,SECRET - 称为枚举常量。
int main()
{
	enum Sex s = FEMALE;
	printf("%d\n",MALE);//打印数值为0
	printf("%d\n",FEMALE);//打印数值为1
	printf("%d\n",SECRET);//打印数值为2
	return 0;
}

#include<stdio.h>
enum Color
{
	RED,
	YELLOW,
	BULE
};

int main()
{
	enum Color color = BLUE;
	color = YELLOW;//color是一个变量，可以更改。RED,YELLOW,BULE是常量，变不了。默认RED为0,YELLOW为1,BULE为2。
	BLUE = 6;//运行报错，左操作数必须为左值。枚举常量是不能改的，但是枚举常量定义的变量是可以改的。
	return 0;
}


字符串+转义字符+注释

字符串

"hello bit.\n"

这种由双引号（double quote）引起来的一串字符称为字符串字面值（String Literal）,或者简称为字符串。
注：字符串的结束标志是一个\0的转义字符。在计算机字符串长度的时候\0是结束标志，不算做字符串内容。


// int float
//char
//但是没有字符串类型，那C语言是如何表现一个字符串的呢？
 
#include<stdio.h>
int main 
{
	"abcdef";//字符串
	"hello bit";//字符串
	"";//空字符串
	
	return 0；
}


#include<stdio.h>

int main()
{
	"abc";//需要将它存起来，用数组（一组数）
	char arr1[] = "abc";//将字符串放到一个字符数组里，即可存下一个字符串。
	//以字符串的形式存入数组，数组默认增加元素0--'a' 'b' 'c' '\0',\0是字符串的结束标志。
	char arr2[] = {'a','b','c'};
	//以字符的形式存入数组，数组只有三个元素。
	printf("%s\n", arr1);//arr1是数组里的第一个元素。abc 
	printf("%s\n", arr2);//abc烫烫烫烫蘟bc，，烫烫烫烫蘟bc是随机的值，因为没有结束的标志。
	char arr2[] = {'a','b','c',0};
	printf("%s\n", arr2);//abc
	//\0的值为0。
	//'a' = 97(ASCII码值) 'A' = 65(ASCII码值)
	//'b' = 98(ASCII码值) 'B' = 66(ASCII码值)
	//'c' = 99(ASCII码值) 'C' = 67(ASCII码值)
	//\0的ASCII码值为0，
	//以上的为ASCII编码，计算机只能识别二进制，所以数据在计算机上存储的时候，存储的是二进制。
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	char arr1[] = "abc";
	char arr2[] = {'a','b','c'};
	printf("%d\n",strlen(arr1));//strlen - string length字符串长度--计算字符串长度的 打印3
	printf("%d\n",strlen(arr2));//打印15 'a' 'b' 'c' '随机值' '...'直到随机值出现数字0为止。
	char arr3[] = {'a','b','c','\0'};//'\0' 或者0都可以，但是一般用'\0'，'\0'是字符串的结束标志。
	printf("%d\n",strlen(arr2));//打印3
	return 0;
}

转义字符

假如要在屏幕上打印一个目录：c:\code\test.c
该如何编写一个代码呢？

#include<stdio.h>

int main()
{
	printf("c:\code\test.c");//打印c:     est-> 
	printf("c:\\code\\test.c");//打印\code\test.c
	return 0;
}

转义字符:转变原来的意思

#include<stdio.h>

int main()
{
	printf("abcn");//打印abcn
	printf("abc\n");//打印abc（换行）
	//\n，将原来的n转变了，变成换行
	return 0;
}

#include<stdio.h>

int main()
{
	printf("c:\test\32\test.c");//打印c:     est->   
    //\t  -- 水平制表符
	/*
    \?    -- 在书写多个？时使用，防止他们被解析成三字母词,得在VC6.0里测试。
	\'    -- 用于表示字符常量
	\"    -- 用于表示一个字符串内部的双引号 
	\\    -- 用于表示一个反斜杠，防止它被解释为一个转移序列符,让斜杠就是一个斜杠。
	\a    -- 警告字符，蜂鸣
	\b    -- 退格符
	\f    -- 进纸符
	\n    -- 换行
	\r    -- 回车
	\t    -- 水平制表符
	\v    -- 垂直制表符
	\ddd  -- ddd表示1-3的八进制的数字。如：\130X
	\xdd  -- dd表示2个十六进制数字。如：\x30 0
	*/
	return 0;
}

#include<stdio.h>

int main()
{
	printf("(are you ok??)\n");//打印 (are you ok]  ?? + ) (三字母词) ---> ]
	printf("(are you ok\??)\n");//打印 (are you ok??)
	return 0;
}

#include<stdio.h>

int main()
{
	printf("%c\n",'a');//打印a
	printf("%c\n",''');//报错
	printf("%c\n",'\'');//打印'
	printf("%s\n","abc");//打印a
	printf("%s\n","\"");//打印"
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	printf("%d\n",strlen("c:\test\32\test.c"));//打印13
	//\32--32为两个八进制的数字
	//32作为八进制代表的那个十进制数字，作为ASCII值，对应的那个字符。
	/*
	32-->10进制
	3 -->8的一次方   24
	2 -->8的零次方   2
	32 -->  24+2=26-->作为ASCII值，对应的那个字符。
	*/
	printf("%c\n",'\32');//打印->(转义字符)
	return 0;
}

注释

1、代码中有不需要的代码可以直接删除，也可以注释掉。
2、代码中有些代码比较难懂，可以加一下注释文字。

#include<stdio.h>

int ADD(int x,int y)
{
	return x+y;
}
/*C语言风格注释

*/

//C++语言风格注释
C语言风格注释缺不能嵌套注释。
/*
int main()
{
	/*
	int a = 10;
    */
	return 0;
}
*/
C++可以注释一行也可以注释多行。

Ctrl + k 增加注释
Ctrl + u 取消注释


选择语句
如果你好好学习，校招时拿一个好offer,走上人生巅峰。
如果你不学习，毕业等于失业，回家买红薯。
这就是选择！

#include<stdio.h>
#include<string.h>

int main()
{
	int input = 0;
	printf("加入比特\n");
	printf("你要好好学习么？(1/0)>:");
	scanf("%d\n",&input);//1/0
	if(input == 1)
		printf("好offer\n");
	else
		printf("买红薯\n");
	return 0;
}

循环语句
有些事必须一直做，比如日复一日的讲课，比如日复一日的学习。
还比如:...
C语言中的循环

1、while语句
2、for语句
3、do...while



#include<stdio.h>
#include<string.h>

int main()
{
	int line = 0;
	printf("加入比特\n");
	
	while(line<20000)
	{
		printf("敲一行代码%d\n",line);
		line++;
	}
	if(line>=20000)
	printf("好offer\n");
	return 0;
}

#include<stdio.h>
int main()
{
	printf("加入比特\n");
	int line = 0;
	while(line<=20000)
	{
		line++;
		printf("我要继续努力敲代码\n");
	}
	if(line>20000)
		printf("好offer\n");
		printf("赢取白富美\n");
	return 0;
}

函数

#include<stdio.h>

int ADD(int x,int y)
{
	int z=x+y;
	return z;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	printf("输入两个操作数:>");
	scanf("d% d%"&a,&b);
	sum = num1 + num2;
	printf("sum = %d\n",sum);
	sum = ADD(num1,num2);	
	return 0;
}

函数
f(x)=2*x+1;
f(x,y)=x+y;

自定义函数
库函数

数组

要存储 1-10 的数字，怎么存储？
C语言中给了数组的定义：一组相同类型元素的集合
数组定义
int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个整型数组，最多放10个元素。
数组的使用


#include<stdio.h>
#include<string.h>

int main()
{
	/*
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	...
	int j = 10;
	*/
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个存放10个整型数字的数组。
	printf("%d\n",&arr[4]);//打印5，利用下标方式来访问元素。arr[下标]
	int i = 0;
	while(i<10)
	{
		printf("%d ",arr[i]);
		i++;
	}
	//char ch[20];
	//float arr2[5];
	
	return 0;
}

/*
arr[10] = {1,2,3,4,5,6,7,8,9,10};
      下标:0 1 2 3 4 5 6 7 8 9       
语法规定：数组的元素下标由0开始。
*/


操作符

算数操作符
+ - * / %(取模，取余数)

移位操作符
>> <<

位操作符
& ^ |

赋值操作符
= += -= *= /= &= ^= |= >>= <<=

#include<stdio.h>
#include<string.h>

int main()
{
	int a = 5/2;
	printf("%d\n",a);//打印2
	int b = 5%2;//取模
	printf("%d\n",b);//打印1
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	//移(二进制位)位操作符
	//<< 左移
	//>> 右移
	int a = 1;
	//1的二进制表达 ，整型1占4个字节，是32个bit位
	//00000000000000000000000000000001
	int b = a<<1;
	//00000000000000000000000000000010,左边丢弃，右边补0
	printf("%d\n",b);//打印2
	int c = a<<2;
	//00000000000000000000000000000100,左边丢弃，右边补0
	printf("%d\n",b);//打印4
	printf("%d\n",a);//打印1
	return 0;
}

位操作
#include<stdio.h>
#include<string.h>

int main()
{
	//(二进制)位操作
    //& 按位与  :全一则一
	//| 按位或  :有一则一
	//^ 按位异或:有一则一全一则零,,对应的二进制位相同则为0，对应的二进制位相异则为1。
	int a = 3;//3的二进制为00000000000000000000000000000011
	int b = 5;//5的二进制为00000000000000000000000000000101
	int c = a & b;//00000000000000000000000000000011 & 00000000000000000000000000000101
	int d = a | b;//00000000000000000000000000000011 | 00000000000000000000000000000101
	int e = a ^ b;//00000000000000000000000000000011 ^ 00000000000000000000000000000101
	printf("%d\n",c);//00000000000000000000000000000001--->1
	printf("%d\n",d);//00000000000000000000000000000111--->7
	printf("%d\n",e);//00000000000000000000000000000110--->6
	return 0;
}

赋值操作符

#include<stdio.h>
#include<string.h>

int main()
{
	int a = 10;
	a = 20;//= --->赋值   == --->判断是否相等

	a = a + 10;
	a += 10;//两种写法完全等价

	a = a - 20;
	a -= 20;//两种写法完全等价

	a = a & 2;
	a &= 2;//两种写法完全等价
//复合赋值符 = += -= *= /= &= ^= |= >>= <<=
	
	return 0;
}

单目操作符
！       逻辑操作符      
-        负值 
+        正值
&        取地址
sizeof   操作数的类型长度
~        对一个数的二进制按位取反
--       前置、后置--
++       前置、后置++
*        间接访问操作符(解引用操作符)
(类型)   强制类型转换

#include<stdio.h>
#include<string.h>

//单目操作符
//双目操作符
//三目操作符

int main()
{
	/*
	int a = 10;
	int b = 20;
	a + b;// +为双目操作符(因为有两个操作数)
	*/
	//C语言中，需要表示真假，0表示假，一切的非0表示真
	
	/*
	int a = 10;
	printf("%d\n",a)；//真 打印10
	printf("%d\n",!a);//假 打印0
	
	int b = 0;
	printf("%d\n",b)；//假 打印0
	printf("%d\n",!b);//真 打印1
	*/
	
	int a = -2;//- 为单目操作符(只有2一个操作数)
	int b = -a;
	int c = +3;//正号都会省略
	
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	int a = 10;
	//sizeof 计算的是变量或者类型所占空间的大小，单位是字节
	printf("%d\n",sizeof(a));//打印4
	printf("%d\n",sizeof(int));//打印4
	printf("%d\n",sizeof a);//打印4
	printf("%d\n",sizeof int);//报错
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	int sz = 0;
	int arr[10] = {0};//10个整型元素的数组
	//10*sizeof(int) = 40;
	printf("%d\n",sizeof(arr));//40,单位是字节
	//计算数组的元素个数
	//元素个数=数组的总大小/每个元素的大小
	sz = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n",sz);
	return 0;
}