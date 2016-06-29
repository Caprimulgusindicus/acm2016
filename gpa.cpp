//包含txt文件读入
//不包含容错处理，需要自行核对数据格式，输入错误会导致程序崩溃
/*
标准算法:成绩乘以课程学分并求和再乘以4，再除以总学分与100之积
四分制算法：四个等级，学分×绩点除以绩点
北大算法：请自行百度
保留小数算法：分数转换成绩点时保留小数
*/
//by LR，2015-07-19
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;
int c1,c2=0;
double  divisor,dividend1,dividend2,dividend3,dividend4=0;
double t1,t2,t3,t4=0;
int size=0;

struct subject
{
    double credit;
    double grade;
}Sx;

queue <subject> init;


void del()
{
    while(!init.empty())
    {
        init.pop();
    }
}

double change1(double k)
{
    return k;
}

double change2(double k)//四分制算法转换
{
    if(k>=90) return 4;
    if(k>=80&&k<90) return 3;
    if(k>=70&&k<80) return 2;
    if(k>=60&&k<70) return 1;
    if(k<60) return 0;
}

double change3(double k)//北大四分制算法转换
{
    if(k>=90&&k<=100) return 4;
    if(k>=85&&k<90) return 3.7;
    if(k>=82&&k<85) return 3.3;
    if(k>=78&&k<82) return 3;
    if(k>=75&&k<78) return 2.7;
    if(k>=72&&k<75) return 2.3;
    if(k>=68&&k<72) return 2;
    if(k>=64&&k<68) return 1.5;
    if(k>=60&&k<64) return 1;
    if(k<60) return 0;
}

double change4(double k)//保留小数点算法转换
{
    if(k>=60)
        return double(k)/double(10)-double(5);
    else return double(0);
}

void add()
{
    int flag=0;
    ifstream source_file("source.txt");//自行替换输入文件，文件格式为每行两个数字
    if(!source_file)
    {
        cout<<"打开文件失败!请手动写入数据:"<<endl;
        flag=1;
    }
    do
    {
        source_file>>Sx.grade>>Sx.credit;
        init.push(Sx);
    }
    while(!source_file.eof());

    if(flag==1)
    {
        cout<<"成绩在前，学分在后"<<endl;
        while(cin>>Sx.grade&&Sx.grade>0)
    {
        cin>>Sx.credit;
        init.push(Sx);
    }
    }

}


void cal()
{
     //ofstream out_file("d://out.txt");感觉不需要输出所以删除了
    int size=init.size();
    dividend1=0;
    dividend2=0;
    dividend3=0;
    dividend4=0;//被除数;上面的
    divisor=0;//除数；下面的
    t1=0;t2=0;t3=0;t3=0;
    for(int i=1;i<=size;i++)
    {
        subject a=init.front();
        init.pop();
        divisor+=a.credit;
        t1=a.credit*change1(a.grade);
        t2=a.credit*change2(a.grade);
        t3=a.credit*change3(a.grade);
        t4=a.credit*change4(a.grade);
        dividend1+=t1;
        dividend2+=t2;
        dividend3+=t3;
        dividend4+=t4;
    }

    double result1=double(dividend1)*double(4)/double(divisor*100);//标准算法
    cout<<"采用标准算法:";
    printf("%.2f\n",result1);
    double result2=double(dividend2)/double(divisor);
    cout<<"采用标准四分制算法：";
    printf("%.2f\n",result2);
    double result3=double(dividend3)/double(divisor);
    cout<<"采用北大四分制算法：";
    printf("%.2f\n",result3);
    double result4=double(dividend4)/double(divisor);
    cout<<"采用保留小数算法：";
    printf("%.2f\n",result4);
}

int ui()
{
    cout<<endl<<
    "\t\tGPA计算器 (by LR)"<<endl<<
    "\t\t1.输入科目"<<endl
    <<"\t\t2.清零"<<endl
    <<"\t\t3.计算"<<endl;
    cin>>c1;
    return c1;
}
int main()
{
    c1=0;
    while(!init.empty())
    {
        init.pop();
    }
    while(1)
    {
        switch(ui())//with no error fuction
        {
        case 1:add();break;
        case 2:del();break;
        case 3:cal();break;
        default:break;
        }
    }
    return 0;
}
