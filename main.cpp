//
//  main.cpp
//  EvaluateExpression
//
//  Created by Dragon on 2017/12/27.
//  Copyright © 2017年 Dragon. All rights reserved.
//
#include "Header.h"
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int result;
    cout<<"*************欢迎使用表达式求值小程序*************\n"<<endl;
    cout<<"请输入您的算术表达式(以#号结束):";
    result = EvaluateExpression();
    cout<<"表达式的计算结果是:"<<result<<endl;
    cout<<"\n*************感谢使用表达式求值小程序*************\n"<<endl;
    
    return 0;
}
