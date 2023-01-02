package review;

public class a {
    // 已知一个函数能够返回1~5的等概率随机数，请实现一个函数返回等概率1~7的随机数
    public static void main(String[] args) {
        int testTimes = 10000000;
        int counts = 0;
        for (int i = 1; i <= testTimes; i++) {
            if (fuc2() < 1) {
                counts++;
            }
        }
        System.out.println((double) counts / (double) testTimes);
    }

    public static int fuc1() {
        return Math.random() < 0.8 ? 0 : 1;
    }

    public static int fuc2() {
        int ans;
        do {
            ans = fuc1();
        } while (ans == fuc1());
        return ans;
    }
}