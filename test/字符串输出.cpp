#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;
// 一行行读
void readTxt(string file)
{
    ifstream infile;
    infile.open("C:\\Users\\xiaobao\\Desktop\\a.txt"); // 将文件流对象与文件连接起来
    assert(infile.is_open());                          // 若失败,则输出错误消息,并终止程序运行

    string s;
    while (getline(infile, s))
    {
        cout << s << endl;
    }
    infile.close(); // 关闭文件输入流
}
// 一字符字符读  忽略空格与回车
void readTxt2(string file)
{
    ifstream infile;
    infile.open(file.data()); // 将文件流对象与文件连接起来
    assert(infile.is_open()); // 若失败,则输出错误消息,并终止程序运行

    char c;
    while (!infile.eof())
    {
        infile >> c;
        cout << c << endl;
    }
    infile.close(); // 关闭文件输入流
}
// 一字符字符读  不忽略空格与回车
void readTxt3(string file)
{
    ifstream infile;
    infile.open(file.data()); // 将文件流对象与文件连接起来
    assert(infile.is_open()); // 若失败,则输出错误消息,并终止程序运行

    char c;
    infile >> noskipws;
    while (!infile.eof())
    {
        infile >> c;
        cout << c << endl;
    }
    infile.close(); // 关闭文件输入流
}

int main()
{

    readTxt("C:\\Users\\xiaobao\\Desktop\\a.txt");
    readTxt2("C:\\Users\\xiaobao\\Desktop\\a.txt");
    readTxt3("C:\\Users\\xiaobao\\Desktop\\a.txt");

    return 0;
}
