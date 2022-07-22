原题链接：[AcWing 282. 石子合并](https://www.acwing.com/activity/content/problem/content/1007/1/)

**题意**：合并 N 堆石子，每次只能合并相邻的两堆石子，求最小代价

**解题思路**：

关键点：最后一次合并一定是左边连续的一部分和右边连续的一部分进行合并

**状态表示**：$ f[i][j] $ 表示将 $ i $ 到 $ j $ 这一段石子合并成一堆的方案的集合，属性 Min

**状态计算**：  
（1） $ i < j $ 时，$ f[i][j] = \min\limits_{i\leq k \leq {j - 1}}{f[i][k]+f[k+1][j] + s[j] -s[i - 1]} $  
（2）$ i = j $ 时， $ f[i][i] = 0 $ （合并一堆石子代价为 0）

**问题答案**： $ f[1][n] $

区间 DP 常用模版
----------

所有的区间dp问题枚举时，第一维通常是枚举区间长度，并且一般 len = 1 时用来初始化，枚举从 len = 2 开始；第二维枚举起点 i （右端点 j 自动获得，j = i + len - 1）

模板代码如下：

```cpp
for (int len = 1; len <= n; len++) {         // 区间长度
    for (int i = 1; i + len - 1 <= n; i++) { // 枚举起点
        int j = i + len - 1;                 // 区间终点
        if (len == 1) {
            dp[i][j] = 初始值
            continue;
        }

        for (int k = i; k < j; k++) {        // 枚举分割点，构造状态转移方程
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + w[i][j]);
        }
    }
}
```

本题C++代码
=======

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 307;

int a[N], s[N];
int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }

    memset(f, 0x3f, sizeof f);
    // 区间 DP 枚举套路：长度+左端点 
    for (int len = 1; len <= n; len ++) { // len表示[i, j]的元素个数
        for (int i = 1; i + len - 1 <= n; i ++) {
            int j = i + len - 1; // 自动得到右端点
            if (len == 1) {
                f[i][j] = 0;  // 边界初始化
                continue;
            }

            for (int k = i; k <= j - 1; k ++) { // 必须满足k + 1 <= j
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;


    return 0;
}
```

补充1：从下往上倒着枚举状态
--------------

除了按长度枚举，也可以倒着枚举，因为**只要保证每种状态都被提前计算**即可

从下往上倒着枚举，可以保证你算dp\[i\]\[j\]时，dp\[i\]\[k\]和dp\[k + 1\]\[j\]一定是被提前计算好的，而从上往下枚举则无法保证这一点。所以我们采用倒着枚举

图解：  
![](https://img-blog.csdnimg.cn/8b588b33240e452d973df0dc61798bc6.png)

```cpp
#include <iostream>

using namespace std;

const int N = 307;

int s[N];
int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            if (j == i) {
                f[i][j] = 0;
                continue;
            }
            f[i][j] = 1e9;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}
```

补充2：记忆化搜索
---------

如果学过后面的记忆化搜索，那也可以用下面的代码。虽然时间会比递推稍微慢一丢丢，但是呢他的思路比较好写

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 307;

int a[N], s[N];
int f[N][N];

// 记忆化搜索：dp的记忆化递归实现
int dp(int i, int j) {
    if (i == j) return 0; // 判断边界
    int &v = f[i][j];

    if (v != -1) return v;

    v = 1e8;
    for (int k = i; k <= j - 1; k ++)
        v = min(v, dp(i, k) + dp(k + 1, j) + s[j] - s[i - 1]);

    return v;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }

    memset(f, -1, sizeof f);

    cout << dp(1, n) << endl;


    return 0;
}
```