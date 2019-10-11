import java.util.Scanner;
 
class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
public class Solution {
    static int customer;
    static int result;
    static int min;
    static Pair[] arr;
    static int[] check;
 
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
        int testcase = sc.nextInt();
        for (int t = 1; t <= testcase; t++) {
            result = 0;
            min = Integer.MAX_VALUE;
            customer = sc.nextInt();
            arr = new Pair[customer + 2];
            check = new int[customer + 2];
            arr[0] = new Pair(sc.nextInt(), sc.nextInt()); // start
            arr[customer + 1] = new Pair(sc.nextInt(), sc.nextInt()); // end
            for (int i = 1; i <= customer; i++) {
                arr[i] = new Pair(sc.nextInt(), sc.nextInt());
            }
            check[0] = 1;
            find(0, 0, 0);
 
            System.out.println("#" + t + " " + min);
        }
 
    }
 
    private static void find(int index, int depth, int result) {
        if(min<=result) {    //여기 시간 줄이기에 제일 중요
            return;
        }
        if (depth == customer) {
            result += Math.abs(arr[index].x - arr[customer + 1].x) + Math.abs(arr[index].y - arr[customer + 1].y);
            if (min > result) {
                min = result;
            }
        }
 
        for (int i = 1; i <= customer; i++) {
            if (check[i] == 0) {
                // result = Math.abs(arr[index].x- arr[i].x)+ Math.abs(arr[index].y- arr[i].y);
                check[i] = 1;
                find(i, depth + 1, result + Math.abs(arr[index].x - arr[i].x) + Math.abs(arr[index].y - arr[i].y));
                check[i] = 0;
 
            }
        }
    }
 
}