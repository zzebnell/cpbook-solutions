import java.util.Scanner;
import java.math.BigInteger;

public class uva713 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    BigInteger b1, b2;
    for (int i = 0; i < n; i++) {
      b1 = sc.nextBigInteger();
      b2 = sc.nextBigInteger();
      StringBuilder sb1 = new StringBuilder(b1.toString());
      StringBuilder sb2 = new StringBuilder(b2.toString());
      sb1.reverse();
      sb2.reverse();
      b1 = new BigInteger(sb1.toString());
      b2 = new BigInteger(sb2.toString());
      BigInteger bi = b1.add(b2);
      StringBuilder ans = new StringBuilder(bi.toString());
      ans.reverse();
      System.out.println(new BigInteger(ans.toString()));
    }
  }
}
