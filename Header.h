//
//  Header.h
//  EvaluateExpression
//
//  Created by Dragon on 2017/12/27.
//  Copyright © 2017年 Dragon. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <ctype.h>
#define MAXSIZE 100
using namespace std;

typedef int  elemtype;
char ch[7]={'+','-','*','/','(',')','#'};
int f1[7] = {3,3,5,5,1,6,0};
int f2[7] = {2,2,4,4,6,1,0};

typedef struct sqstack
{
    elemtype stack[MAXSIZE];
    int top;
}sqstack;

elemtype cton(char c)
{
    switch (c)
    {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        default:
            return 6;
    }
}


//比较两个字符的优先级
char Compare(char c1,char c2)
{
    int i1 = cton(c1);
    int i2 = cton(c2);
    if (f1[i1] > f2[i2])  return '>';
    else
        if(f1[i1] < f2[i2])  return '<';
        else return '=';
}//end Compare

//3.进行四则运算，并 返回计算结果
int Operate(elemtype a, elemtype t, elemtype b)
{
    int sum;
    switch(t){
        case 0: sum=a+b; break;
        case 1: sum=a-b; break;
        case 2: sum=a*b; break;
        default: sum=a/b; break;
    }
    return sum;
}//end Operate



//取栈顶元素
elemtype Gettop(sqstack s)
{
    if (s.top == 0) {
        cout<<"ERROR,Underflow!\n"<<endl;
        return 0;
    }
    else
        return s.stack[s.top];
}

//初始化栈
void Initstack(sqstack *s)
{
    s->top = 0;
}


//出栈
void Pop(sqstack *s, elemtype *x)
{
    if (s->top == 0)
        cout<<"ERROR,Underflow!\n"<<endl;
    else
    {
        *x = s->stack[s->top];
        s->top--;
    }
}

//入栈
void Push(sqstack *s, elemtype x)
{
    if (s->top == MAXSIZE-1) {
        cout<<"ERROR,Overflow!\n"<<endl;
    }
    else
    {
        s->top++;
        s->stack[s->top] = x;
        
    }
}//end Push

//4.主要的表达式计算函数
int EvaluateExpression()
{
    char c;
    int sum = 0;
    const int k = 1,j = 1;      //这里为开关变量
    elemtype x,t,a,b;
    sqstack OPTR,OPND;
    Initstack(&OPTR);
    Push(&OPTR, cton('#'));
    Initstack(&OPND);
    
    c = getchar();
    while (c != '#' || ch[Gettop(OPTR)] != '#') {
        if (isdigit(c))
        {
            sum = 0;
            while (isdigit(c))
            {
                if (!j)         //目前判读意义不大
                {
                    sum = sum*10-(c-'0');
                    
                }
                else sum = sum*10+(c-'0');
                c = getchar();
            }       //当前c不为数字，则把之前的数字串转化成十进制数字再压栈
            Push(&OPND, sum);
        }//end if
        
        else if(k)
        {
            switch (Compare(ch[Gettop(OPTR)], c))
            {
                case '<': Push(&OPTR, cton(c));
                    c = getchar();
                    break;
                case '=': Pop(&OPTR, &x);
                    c = getchar();
                    break;
                case '>': Pop(&OPTR, &t);
                    Pop(&OPND, &b);
                    Pop(&OPND, &a);
                    Push(&OPND, Operate(a, t, b));
                    break;
                    
            }
        }
        
        
    }//end while
    return (Gettop(OPND));
}//end EvaluateExpression


bool StackEmpty(sqstack S)
{
    if (S.top == 0) {
        return  true;
    }
    else
        return false;
}

#endif /* Header_h */
