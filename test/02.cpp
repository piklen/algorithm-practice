#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "共输入了" << argc << "分别是:\n";
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << endl;
    return 0;
}