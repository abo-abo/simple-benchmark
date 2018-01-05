import java.util.Vector;
import java.util.Arrays;

class Concat
{
  public static Vector<Integer> repeat(int N, int a) {
    Vector<Integer> v = new Vector<Integer>(N);
    for (int i = 0; i < N; ++i)
      v.add(a);
    return v;
  }

  public static Vector<Integer> range(int N) {
    Vector<Integer> v = new Vector<Integer>(N);
    for (int i = 0; i < N; ++i)
      v.add(i);
    return v;
  }

  public static Vector<Integer> concat(Vector<Integer> v1, Vector<Integer> v2) {
    Vector<Integer> r = new Vector<Integer>();
    r.addAll(v1);
    r.addAll(v2);
    return r;
  }

  public static long sum(Vector<Integer> v) {
    Integer[] a = (Integer[])v.toArray(new Integer[0]);
    long r = 0;
    for (int i = 0; i < a.length; ++i)
      r += a[i];
    return r;
  }

  static void tic() {
    tic_start = System.currentTimeMillis();
  }

  static void toc() {
    long tic_end = System.currentTimeMillis();
    System.out.println("toc(): " + (tic_end - tic_start) + "ms");
  }

  public static void main(String[] args) {
    System.out.println("Java:");
    int N = 10000000;
    Vector<Integer> a = range(N);
    Vector<Integer> b = range(N);
    tic();
    Vector<Integer> c = concat(a, b);
    toc();
    tic();
    long s = sum(c);
    toc();
    System.out.println("sum: " + s);
  }

  static long tic_start;
}
