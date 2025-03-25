import java.util.Scanner;
import java.math.BigInteger;

public class uva10925 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n, f;
    int tn = 1;
    while (true) {
      n = sc.nextInt();
      f = sc.nextInt();
      if (n == 0 && f == 0) break;
      BigInteger ans = BigInteger.ZERO;
      for (int i = 0; i < n; i++) {
        String s;
        s = sc.next();
        ans = ans.add(new BigInteger(s));
      }
      // if (tn > 1) System.out.println();
      System.out.println("Bill #" + (tn++) + " costs " + ans + ": each friend should pay " + ans.divide(BigInteger.valueOf(f)) + "\n");
    }
  }
}
