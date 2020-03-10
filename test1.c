#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define PR "你的体力节律"//Physical rhythm
#define ER "你的情绪节律"//Emotional rhythm
#define IR "你的智力节律"//Intellectual rhythm 
#define CD "刚好处于周期日"
#define HD "处于高潮期第"
#define MD "刚好处于临界日"
#define LD "处于低潮期第"
 
int sum(int y,int m,int d)//人体内存在着三大生物节律，即体力节律、情绪节律、智力节律。它们的周期分别为28天、33天、23天。
{
	int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,s=0;
	for(i=1;i<y;i++)
	if(i%4==0&&i%100!=0||i%400==0)
	s+=366;
	else
	s+=365;
		
	if(y%4==0&&y%100!=0||y%400==0)
	md[1]=29;
		
	for(i=1;i<m;i++)
	s+=md[i];
	s+=d;
		
	return s; 
}

int main()
{
	int YB,MB,DB,YI,MI,DI,md[12]={31,28,31,30,31,30,31,31,30,31,30,31};//这是我设计的出生年月日的简写year of birth。。。
 	printf("请输入你的出生年月日（请以“年，月，日”的格式输入）（此程序可以计算任意天数人体的生物节律，为读者提供向导，规避风险，仅为客观规律，切勿迷信）：");
 	scanf("%d,%d,%d",&YB,&MB,&DB);
 	md[1]=YB%4==0&&YB%100!=0||YB%400==0?29:28; 
 	
 	if(YB>0&&MB>0&&DB>0&&MB<13&&DB<=md[MB-1])
 	    printf("请输入你想知道节律的日期(请以“年，月，日”的格式输入)：");
 	else
	{
		printf("时间格式输入错误！");
    	exit(1);
	}
	scanf("%d,%d,%d",&YI,&MI,&DI);
	md[1]=YI%4==0&&YI%100!=0||YI%400==0?29:28;
	if((YI>YB&&MI>0&&DI>0&&MI<13&&DI<=md[MI-1])||(YI==YB&&MI>MB&&DI>0&&MI<13&&DI<=md[MI-1])||(YI==YB&&MI==MB&&DI>=DB&&MI<13&&DI<=md[MI-1])) 
	{
		int s1,s2;
    s1=sum(YB,MB,DB);
    s2=sum(YI,MI,DI);
	int day_diff;
	day_diff=s2-s1;

    int rm1,rm2,rm3;
    rm1=day_diff%23;
	rm2=day_diff%28;
	rm3=day_diff%33; 
	
	if(rm1==0)
	    printf("%s%s。\n",PR,CD);
	if(0<rm1&&rm1<12)
	    printf("%s%s%d天。\n",PR,HD,rm1);
	if(rm1==12)
	    printf("%s%s。\n",PR,MD);
	if(12<rm1&&rm1<23)
	    printf("%s%s%d天。\n",PR,LD,rm1-12);
	    
	if(rm2==0)
	    printf("%s%s。\n",ER,CD);
	if(0<rm2&&rm2<14)
	    printf("%s%s%d天。\n",ER,HD,rm2);
	if(rm2==14)
	    printf("%s%s。\n",ER,MD);
	if(14<rm2&&rm2<28)
	    printf("%s%s%d天。\n",ER,LD,rm2-14);
	
	if(rm3==0)
	    printf("%s%s。\n",IR,CD);
	if(0<rm3&&rm3<17)
	    printf("%s%s%d天。\n",IR,HD,rm3);
	if(rm3==17)
	    printf("%s%s。\n",IR,MD);
	if(17<rm3&&rm3<33)
	    printf("%s%s%d天。\n",IR,LD,rm3-17);
	}
		
	else 
	    {
		printf("时间格式输入错误！");
	    } 

	system("pause"); 
 } 
