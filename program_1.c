#include<stdio.h>//include 包含 stdio.h 的文件
//std-标准 standard input output

int main()//主函数-程序的入口-main函数有且只有一个 int 整型，main前面的int是指main函数调用之后，返回一个整型值。
{
	printf("This is a C program.\n");//print f--print function 打印函数--库函数-C语言本身提供给我们使用的函数。
	return 0;//返回 0 
}

void main()//这种写法是过时的写法
{
	
	
}

数据类型
char   //字符数据类型   
//    双引号 char ch = 'A' ;a b c d ..  printf("%c\n",ch);  c%--打印字符格式的数据
short  //短整型
int    //整型
//  int age = 20; printf("%d\n",age); %d--打印整型十进制数据
long   //长整型
long long //更长的整型
float  //单精度浮点型
//int f = 5.0; printf("%f\n",f);
double  //双精度浮点型
//int d = 3.14; printf("%lf\n",d);

// %d --打印整型
// %c --打印字符
// %f --打印浮点数字-打小数
// %p --以地址的形式打印
// %x --打印16进制数字

int main()
{
	printf("%d\n",sizeof(char));     // 1字节  --8个二进制位  0-255
	printf("%d\n",sizeof(short));    // 2字节  --16个二进制位 0-65535
	printf("%d\n",sizeof(int));      // 4字节  --32个二进制位 0-2的32次方-1
	printf("%d\n",sizeof(long));     // 4/8字节--64个二进制位 0-2的64次方-1 C语言标准规定sizeof(long)>=sizeof(int)即可
	printf("%d\n",sizeof(long long));// 8字节  --64个二进制位 0-2的64次方-1
	printf("%d\n",sizeof(float));    // 4字节  --32个二进制位 0-2的32次方-1
	printf("%d\n",sizeof(double));  //  8字节  --64个二进制位 0-2的64次方-1
	return 0; 
}
//同一类型的无符号和有符号所占字节大小一致。

//字节 
//计算机中的单位
/*计算机中最小的单位 bit  比特位 存1或者0---存一个二进制位
byte 字节  1个byte 字节 = 8个比特 bit 位
kb  1kb = 1024 byte
mb  1mb = 1024 kb
gb  1gb = 1024 mb
tb  1tb = 1024 gb
pb  1pb = 1024 tb
*/

short age = 20;//向内存申请2个字节=16bit位的空间来存放20；
float weight = 95.6f;//向内存申请4个字节=32bit位的空间来存放小数95.6；

常量和变量

定义变量的方法（类型 变量名 赋值）
int age = 20；
float weight = 45.5f;
char ch = 'w';

变量的分类

局部变量
全局变量

#include<stdio.h>

int num2 = 20;//num2 在此为全局变量：定义在代码块（大括号{}）之外的变量

int main()
{
	int num1 = 10;//num1 在此为局部变量：定义在代码块（大括号{}）内部的变量
	return 0;	
}

#include<stdio.h>

int a = 100;//num2 在此为全局变量：定义在代码块（大括号{}）之外的变量

int main()
{
	int a = 10;//num1 在此为局部变量：定义在代码块（大括号{}）内部的变量
	printf("%d\n",a);
	return 0;	
}
//此时全局变量和局部变量同时存在，但局部变量优先,打印数值为10。
//局部变量和全局变量的名字建议不要相同，容易误会，产生bug.


#include<stdio.h>

int main()
{
	{
		int a = 10;//局部变量只能在局部使用
	}
	printf("%d\n",a);//此时运行环境报错，无法打印。
	return 0;	
}

#include<stdio.h>

int main()
{
	//计算两个数的和
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	//输入数据--使用输入函数scanf()
	scanf("%d%d",&num1,&num2);//取地址符号&
	//int sum = num1 + num2;在此定义sum会报错
	//C语言语法规定，变量要定义在当前代码块的最前面。
	sum = num1 + num2;
	printf("sum = %d\n",sum);
	return 0;
}

变量的作用域和生命周期

作用域（scope）,程序设计概念，通常来说，一段程序代码中所用到的名字不总是有效/可用的，而限定这个名字的可用性的
代码范围就是这个名字的作用域。

1、局部变量的作用域是变量所在的局部范围
2、全局变量的作用域是整个工程。

#include<stdio.h>

int main()
{
	int num = 0；
	printf("num = %d\n",num);
	return 0;
}//正常运行

#include<stdio.h>

int main()
{
	{
		int num = 0；	
	}//此大括号为num的作用域	
	printf("num = %d\n",num);
	return 0;
}//报错，未正常运行，num是未声明的标识符。

#include<stdio.h>

int main()
{
	//为声明的标识符
	//声明extern外部符号的
	extern int g_val；//其他c文件里定义的变量。	
	printf("num = %d\n",num);
	return 0;
}

生命周期
变量的生命周期指的是变量的创建到变量销毁之间的一个时间段。

1、局部变量的生命周期是：进入作用域生命周期开始，出作用域生命周期结束。
2、全局变量的生命周期是：整个程序的生命周期。


