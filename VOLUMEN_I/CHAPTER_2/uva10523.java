import java.util.Scanner;
import java.math.BigInteger;

public class uva10523 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      int n = sc.nextInt();
      int a = sc.nextInt();
      BigInteger ans = BigInteger.ZERO;
      for (int i = 1; i <= n; i++) {
        ans = ans.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(a).pow(i)));
      }
      System.out.println(ans);
    }
  }
}
