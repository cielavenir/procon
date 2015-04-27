/* Note: semi-auto generation from jd-gui decompiler. Submission in Java is not accepted */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

class Solution
{
  static String[][] dp;
  static String str;
  static int Ill;
  static long Il1 = 1000000007L;
  static long IlI = 1000000009L;
  static String I1l;

  static String solve(int paramInt1, int paramInt2)
  {
    if (paramInt1 > paramInt2) return "";
    if (!dp[paramInt1][paramInt2].equals("n")) return dp[paramInt1][paramInt2];
    String str1 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    if ((str.charAt(paramInt1) == '[') && (str.charAt(paramInt2) == ']')) str1 = "[" + solve(paramInt1 + 1, paramInt2 - 1) + "]";
    if ((str.charAt(paramInt1) == '(') && (str.charAt(paramInt2) == ')')) str1 = "(" + solve(paramInt1 + 1, paramInt2 - 1) + ")";
    if ((str.charAt(paramInt1) == '[') && (solve(paramInt1 + 1, paramInt2).length() + 2 < str1.length())) str1 = "[" + solve(paramInt1 + 1, paramInt2) + "]";
    if ((str.charAt(paramInt1) == '(') && (solve(paramInt1 + 1, paramInt2).length() + 2 < str1.length())) str1 = "(" + solve(paramInt1 + 1, paramInt2) + ")";
    if ((str.charAt(paramInt2) == ']') && (solve(paramInt1, paramInt2 - 1).length() + 2 < str1.length())) str1 = "[" + solve(paramInt1, paramInt2 - 1) + "]";
    if ((str.charAt(paramInt2) == ')') && (solve(paramInt1, paramInt2 - 1).length() + 2 < str1.length())) str1 = "(" + solve(paramInt1, paramInt2 - 1) + ")";
    for (int i = paramInt1; i < paramInt2; i++) {
      if (solve(paramInt1, i).length() + solve(i + 1, paramInt2).length() < str1.length()) str1 = solve(paramInt1, i) + solve(i + 1, paramInt2);
    }
    return dp[paramInt1][paramInt2] = str1;
  }
  public static void precalc(String[] paramArrayOfString) {
    Scanner localScanner = new Scanner(System.in);
    if (!localScanner.hasNext()) {
      System.out.println();
      System.exit(0);
    }
    str = localScanner.next();
    dp = new String[str.length()][str.length()];
    for (int i = 0; i < str.length(); i++) {
      for (int j = 0; j < str.length(); j++)
        dp[i][j] = "n";
    }
    System.out.println(solve(0, str.length() - 1));
  }

  static long I11(long paramLong1, long paramLong2)
  {
    long l1 = 1L;
    long l2 = paramLong1;
    while (paramLong2 > 0L) {
      if (paramLong2 % 2L == 1L) {
        l1 = l1 * l2 % IlI;
      }
      paramLong2 /= 2L;
      l2 = l2 * l2 % IlI;
    }
    return l1;
  }
  static long l11() {
    long l=0;
    if (I1l.charAt(Ill) == '(') {
      Ill += 1;
      l = lII();
      Ill += 1;
      return l;
    }
    /*long*/ l = 0L;
    while (('0' <= I1l.charAt(Ill)) && (I1l.charAt(Ill) <= '9')) {
      l = (l * 10L + (I1l.charAt(Ill) - '0')) % Il1;
      Ill += 1;
    }
    return l;
  }
  static long l1I() {
    long l1 = l11();
    while ((I1l.charAt(Ill) == '*') || (I1l.charAt(Ill) == '/')) {
      int i = I1l.charAt(Ill);
      Ill += 1;
      long l2 = l11();
      if (i == 42) l1 = l1 * l2 % Il1; else
        l1 = l1 * I11(l2, IlI - 2L) % Il1;
    }
    return l1;
  }
  public static void III(String[] paramArrayOfString) throws Exception {
    BufferedReader localBufferedReader = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));
    BigInteger[][] arrayOfBigInteger = new BigInteger[51][101];
    int[] arrayOfInt1 = new int[256];
    int[][] arrayOfInt = new int[101][256];
    int[] arrayOfInt2 = new int[101];
    int[] arrayOfInt3 = new int[101];
    int[] arrayOfInt4 = new int[101];
    int[] arrayOfInt5 = new int[101];
    int[] arrayOfInt6 = new int[1000];
    int i = 0;
    int j = 0;
    int k = 0;
    String str1 = localBufferedReader.readLine();
    int m = Integer.parseInt(str1.split(" ")[0]);
    int n = Integer.parseInt(str1.split(" ")[1]);
    int i1 = Integer.parseInt(str1.split(" ")[2]);
    for (int i2 = 0; i2 < 256; i2++) arrayOfInt1[i2] = -1;
    for (int i2 = 0; i2 < 101; i2++)
      for (int i3 = 0; i3 < 256; i3++)
        arrayOfInt[i2][i3] = -1;
    String str2 = localBufferedReader.readLine();
    byte[] arrayOfByte1 = str2.getBytes("ISO-8859-1");
    int[] arrayOfInt7 = new int[arrayOfByte1.length];
    for (int i4 = 0; i4 < arrayOfByte1.length; i4++) arrayOfByte1[i4] += 128;
    for (int i4 = 0; i4 < arrayOfByte1.length; i4++) arrayOfInt1[arrayOfInt7[i4]] = i4;
    for (int i4 = 0; i4 < 101; i4++)
      for (int i5 = 0; i5 < 26; i5++)
        arrayOfInt[i4][i5] = -1;
    arrayOfInt4[0] = -1;
    k++;
    int i7;
    int i8;
    for (int i4 = 0; i4 < i1; i4++) {
      str2 = localBufferedReader.readLine();
      byte[] arrayOfByte2 = str2.getBytes("ISO-8859-1");
      i7 = 0;
      for (i8 = 0; i8 < arrayOfByte2.length; i8++)
        if (arrayOfInt[i7][(arrayOfByte2[i8] + 128)] == -1) {
          arrayOfInt[i7][(arrayOfByte2[i8] + 128)] = k;
          arrayOfInt4[k] = i7;
          k++;
          arrayOfInt5[(k - 1)] = (arrayOfByte2[i8] + 128);
          i7 = k - 1; } else {
          i7 = arrayOfInt[i7][(arrayOfByte2[i8] + 128)];
        }
      arrayOfInt2[i7] = 1;
    }
    arrayOfInt3[0] = -1;
    arrayOfInt6[(j++)] = 0;
    while (j > i)
    {
      int i4 = arrayOfInt6[(i++)];
      for (int i6 = 0; i6 < 256; i6++) {
        if (arrayOfInt[i4][i6] != -1) arrayOfInt6[(j++)] = arrayOfInt[i4][i6];
      }
      if (i4 != 0) {
        int i6 = arrayOfInt5[i4];
        i7 = i4;
        i4 = arrayOfInt4[i4];
        do
        {
          if (i4 == -1) {
            arrayOfInt3[i7] = 0;
            break;
          }
          i4 = arrayOfInt3[i4];
          if (i4 == -1) {
            arrayOfInt3[i7] = 0;
            break;
          }
        }
        while (arrayOfInt[i4][i6] == -1);
        arrayOfInt3[i7] = arrayOfInt[i4][i6];
      }

    }

    arrayOfInt3[0] = 0;
    for (int i4 = 0; i4 < 51; i4++)
      for (int i6 = 0; i6 < 101; i6++)
        arrayOfBigInteger[i4][i6] = BigInteger.ZERO;
    arrayOfBigInteger[0][0] = BigInteger.ONE;
    for (int i4 = 0; i4 < n; i4++) {
      for (int i6 = 0; i6 < k; i6++) {
        for (i7 = 0; i7 < m; i7++)
        {
          int i9;
          if (arrayOfInt[i6][arrayOfInt7[i7]] == -1) {
            i8 = arrayOfInt3[i6];
            i9 = 0;
            while (arrayOfInt[i8][arrayOfInt7[i7]] == -1) {
              if (i8 == 0) {
                i8 = -1;
                break;
              }
              i8 = arrayOfInt3[i8];
            }
            int i10 = i8;
            while (i10 >= 0) {
              if ((arrayOfInt[i10][arrayOfInt7[i7]] != -1) && (arrayOfInt2[arrayOfInt[i10][arrayOfInt7[i7]]] == 1)) i9 = 1;
              if (i10 == 0) break;
              i10 = arrayOfInt3[i10];
            }
            if (i8 == -1) arrayOfBigInteger[(i4 + 1)][0] = arrayOfBigInteger[(i4 + 1)][0].add(arrayOfBigInteger[i4][i6]);
            else if ((arrayOfInt2[arrayOfInt[i8][arrayOfInt7[i7]]] != 1) && (i9 != 1)) arrayOfBigInteger[(i4 + 1)][arrayOfInt[i8][arrayOfInt7[i7]]] = arrayOfBigInteger[(i4 + 1)][arrayOfInt[i8][arrayOfInt7[i7]]].add(arrayOfBigInteger[i4][i6]); 
          }
          else { i8 = i6;
            i9 = 0;
            while (i8 >= 0) {
              if ((arrayOfInt[i8][arrayOfInt7[i7]] != -1) && (arrayOfInt2[arrayOfInt[i8][arrayOfInt7[i7]]] == 1)) i9 = 1;
              if (i8 == 0) break;
              i8 = arrayOfInt3[i8];
            }
            if ((i9 != 1) && (arrayOfInt2[arrayOfInt[i6][arrayOfInt7[i7]]] != 1)) arrayOfBigInteger[(i4 + 1)][arrayOfInt[i6][arrayOfInt7[i7]]] = arrayOfBigInteger[(i4 + 1)][arrayOfInt[i6][arrayOfInt7[i7]]].add(arrayOfBigInteger[i4][i6]);
          }
        }
      }
    }
    BigInteger localBigInteger = BigInteger.ZERO;
    for (int i6 = 0; i6 < k; i6++) localBigInteger = localBigInteger.add(arrayOfBigInteger[n][i6]);
    System.out.println(localBigInteger.toString());
  }

  static long lII() {
    long l1 = l1I();
    while ((I1l.charAt(Ill) == '+') || (I1l.charAt(Ill) == '-')) {
      int i = I1l.charAt(Ill);
      Ill += 1;
      long l2 = l1I();
      if (i == 43) l1 = (l1 + l2) % Il1; else
        l1 = (l1 + Il1 - l2) % Il1;
    }
    return l1;
  }
  public static void main(String[] paramArrayOfString) {
    Scanner localScanner = new Scanner(System.in);
    I1l = localScanner.next();
    I1l += ";";
    Ill = 0;
    System.out.println(lII());
  }

  public static void criticalcrystal(String[] paramArrayOfString) throws IOException {
    InputStreamReader localInputStreamReader = new InputStreamReader(System.in);
    BufferedReader localBufferedReader = new BufferedReader(localInputStreamReader);

    String str1 = localBufferedReader.readLine();
    HashMap localHashMap = new HashMap();
    String[][] arrayOfString = new String[101][''];
    int[][] arrayOfInt1 = new int[101][''];
    String[] arrayOfString1 = new String[101];
    String[] arrayOfString2 = new String[101];
    String[] arrayOfString3 = new String[5000];
    int[][] arrayOfInt2 = new int[''][''];
    int[][] arrayOfInt3 = new int[''][''];
    int[][] arrayOfInt4 = new int[''][''];
    int[] arrayOfInt5 = new int[''];
    int[] arrayOfInt6 = new int[''];
    int[] arrayOfInt7 = new int[''];
    int[] arrayOfInt8 = new int[''];
    boolean[] arrayOfBoolean1 = new boolean[''];
    boolean[] arrayOfBoolean2 = new boolean[''];

    int i = 0;
    String str2 = localBufferedReader.readLine();
    while (true) {
      arrayOfString1[i] = "";
      if (str2.equals("#")) break;
      arrayOfString2[i] = str2.substring(4);
      localHashMap.put(str2.substring(0, 3), Integer.valueOf(i));
      while (true) {
        str2 = localBufferedReader.readLine();
        if (str2.charAt(0) != ' ')
          break;
        int tmp245_243 = i;
        String[] tmp245_241 = arrayOfString1; tmp245_241[tmp245_243] = (tmp245_241[tmp245_243] + str2.substring(1, 2));
        arrayOfString[i][str2.charAt(1)] = str2.substring(3);
        arrayOfInt1[i][str2.charAt(1)] = (arrayOfString1[i].length() - 1);
      }
      i++;
    }int j = 0;
    Object localObject;
    while (true) {
      localObject = localBufferedReader.readLine();
      if (((String)localObject).equals("#")) break;
      arrayOfString3[(j++)] = (String)localObject;
    }
    while (true)
    {
      localObject = new StringBuffer(10000);

      String str3 = localBufferedReader.readLine();
      if (str3.equals("#")) break;
      String[] arrayOfString4 = str3.split(" ");
      ((StringBuffer)localObject).append(str1 + " - " + str3.substring(8) + "\n");
      int k = ((Integer)localHashMap.get(arrayOfString4[0])).intValue();
      ((StringBuffer)localObject).append(arrayOfString4[0] + " " + arrayOfString2[k] + "\n");
      int m = arrayOfString1[k].length();
      char[] arrayOfChar1 = arrayOfString1[k].toCharArray();
      for (int n = 0; n < m; n++) {
        ((StringBuffer)localObject).append(" " + arrayOfChar1[n] + " " + arrayOfString[k][arrayOfChar1[n]] + "\n");
      }
      int n = ((Integer)localHashMap.get(arrayOfString4[1])).intValue();
      int i1 = arrayOfString1[n].length();
      char[] arrayOfChar2 = arrayOfString1[n].toCharArray();
      ((StringBuffer)localObject).append(arrayOfString4[1] + " " + arrayOfString2[n] + "\n");
      for (int i2 = 0; i2 < i1; i2++) {
        ((StringBuffer)localObject).append(" " + arrayOfChar2[i2] + " " + arrayOfString[n][arrayOfChar2[i2]] + "\n");
      }
      ((StringBuffer)localObject).append("\n");
      ((StringBuffer)localObject).append("      ");
      for (int i2 = 0; i2 < i1; i2++) {
        ((StringBuffer)localObject).append(" " + arrayOfString4[1] + ":" + arrayOfChar2[i2]);
      }
      ((StringBuffer)localObject).append(" TOTAL\n");
      for (int i2 = 0; i2 < m; i2++)
        for (int i3 = 0; i3 < i1; i3++)
        {
          int tmp847_846 = (arrayOfInt4[i2][i3] = 0); arrayOfInt3[i2][i3] = tmp847_846; arrayOfInt2[i2][i3] = tmp847_846;
        }
      int i4;
      for (int i2 = 0; i2 < j; i2++) {
        int i3 = arrayOfInt1[k][arrayOfString3[i2].charAt(k)];
        i4 = arrayOfInt1[n][arrayOfString3[i2].charAt(n)];

        arrayOfInt2[i3][i4] += 1;
      }
      int i7;
      int i8;
      for (int i2 = 0; i2 < m; i2++) {
        int i3 = 0;
        for (i4 = 0; i4 < i1; i4++) {
          i3 += arrayOfInt2[i2][i4];
        }
        if (i3 == 0) {
          for (i4 = 0; i4 < i1; i4++) arrayOfInt3[i2][i4] = -1; 
        }
        else
        {
          boolean[] arrayOfBoolean3 = new boolean[i1];
          i7 = 0;
          for (i8 = 0; i8 < i1; i8++) {
            if (arrayOfInt2[i2][i8] * 100 % i3 == 0) {
              i7 += (arrayOfInt3[i2][i8] = arrayOfInt2[i2][i8] * 100 / i3);
            }
            else {
              i7 += (arrayOfInt3[i2][i8] = arrayOfInt2[i2][i8] * 100 / i3);
              arrayOfBoolean3[i8] = true;
            }
          }
          for (i8 = 0; (i8 < i1) && (i7 < 100); i8++) {
            if (arrayOfBoolean3[i8]/* != 0*/) {
              i7++;
              arrayOfInt3[i2][i8] += 1;
            }
          }
        }
      }
      for (int i2 = 0; i2 < i1; i2++) {
        int i3 = 0;
        for (int i5 = 0; i5 < m; i5++) {
          i3 += arrayOfInt2[i5][i2];
        }
        if (i3 == 0) {
          for (int i5 = 0; i5 < m; i5++) arrayOfInt4[i5][i2] = -1; 
        }
        else
        {
          boolean[] arrayOfBoolean4 = new boolean[m];
          i7 = 0;
          for (i8 = 0; i8 < m; i8++) {
            if (arrayOfInt2[i8][i2] * 100 % i3 == 0) {
              i7 += (arrayOfInt4[i8][i2] = arrayOfInt2[i8][i2] * 100 / i3);
            }
            else {
              i7 += (arrayOfInt4[i8][i2] = arrayOfInt2[i8][i2] * 100 / i3);
              arrayOfBoolean4[i8] = true;
            }
          }
          for (i8 = 0; (i8 < m) && (i7 < 100); i8++)
            if (arrayOfBoolean4[i8]/* != 0*/) {
              i7++;
              arrayOfInt4[i8][i2] += 1;
            }
        }
      }
      for (int i2 = 0; i2 < m; i2++) {
        arrayOfInt5[i2] = 0;
        arrayOfBoolean1[i2] = false;
        for (int i3 = 0; i3 < i1; i3++) arrayOfInt5[i2] += arrayOfInt2[i2][i3];
      }
      for (int i2 = 0; i2 < i1; i2++) {
        arrayOfInt6[i2] = 0;
        arrayOfBoolean2[i2] = false;
        for (int i3 = 0; i3 < m; i3++) arrayOfInt6[i2] += arrayOfInt2[i3][i2];
      }
      int i2 = 0;
      for (int i3 = 0; i3 < m; i3++) {
        i2 += (arrayOfInt7[i3] = arrayOfInt5[i3] * 100 / j);
        if (arrayOfInt5[i3] * 100 % j != 0) arrayOfBoolean1[i3] = true;
      }
      for (int i3 = 0; (i3 < m) && (i2 < 100); i3++) {
        if (arrayOfBoolean1[i3]/* != 0*/) {
          arrayOfInt7[i3] += 1;
          i2++;
        }
      }
      i2 = 0;
      for (int i3 = 0; i3 < i1; i3++) {
        i2 += (arrayOfInt8[i3] = arrayOfInt6[i3] * 100 / j);
        if (arrayOfInt6[i3] * 100 % j != 0) arrayOfBoolean2[i3] = true;
      }
      for (int i3 = 0; (i3 < i1) && (i2 < 100); i3++) {
        if (arrayOfBoolean2[i3]/* != 0*/) {
          arrayOfInt8[i3] += 1;
          i2++;
        }
      }
      for (int i3 = 0; i3 < m; i3++) {
        ((StringBuffer)localObject).append(" " + arrayOfString4[0] + ":" + arrayOfChar1[i3]);
        for (int i6 = 0; i6 < i1; i6++) {
          ((StringBuffer)localObject).append(String.format("%6d", new Object[] { Integer.valueOf(arrayOfInt2[i3][i6]) }));
        }
        int i6 = 0;
        for (i7 = 0; i7 < i1; i7++) i6 += arrayOfInt2[i3][i7];
        ((StringBuffer)localObject).append(String.format("%6d", new Object[] { Integer.valueOf(i6) }));
        ((StringBuffer)localObject).append("\n      ");
        for (i7 = 0; i7 < i1; i7++)
          if (arrayOfInt3[i3][i7] != -1) {
            ((StringBuffer)localObject).append(String.format("%5d", new Object[] { Integer.valueOf(arrayOfInt3[i3][i7]) }));
            ((StringBuffer)localObject).append("%"); } else {
            ((StringBuffer)localObject).append("     -");
          }
        if (arrayOfInt5[i3] != 0) ((StringBuffer)localObject).append("  100%\n      "); else
          ((StringBuffer)localObject).append("     -\n      ");
        for (i7 = 0; i7 < i1; i7++) {
          if (arrayOfInt4[i3][i7] != -1) {
            ((StringBuffer)localObject).append(String.format("%5d", new Object[] { Integer.valueOf(arrayOfInt4[i3][i7]) }));
            ((StringBuffer)localObject).append("%"); } else {
            ((StringBuffer)localObject).append("     -");
          }
        }
        ((StringBuffer)localObject).append(String.format("%5d", new Object[] { Integer.valueOf(arrayOfInt7[i3]) }));
        ((StringBuffer)localObject).append("%\n");
      }
      ((StringBuffer)localObject).append(" TOTAL");
      for (int i3 = 0; i3 < i1; i3++) {
        ((StringBuffer)localObject).append(String.format("%6d", new Object[] { Integer.valueOf(arrayOfInt6[i3]) }));
      }
      ((StringBuffer)localObject).append(String.format("%6d\n", new Object[] { Integer.valueOf(j) }));
      ((StringBuffer)localObject).append("      ");
      for (int i3 = 0; i3 < i1; i3++) {
        ((StringBuffer)localObject).append(String.format("%5d", new Object[] { Integer.valueOf(arrayOfInt8[i3]) }));
        ((StringBuffer)localObject).append("%");
      }
      ((StringBuffer)localObject).append("  100%\n");
      ((StringBuffer)localObject).append("      ");
      for (int i3 = 0; i3 < i1; i3++) {
        if (arrayOfInt6[i3] > 0) ((StringBuffer)localObject).append("  100%"); else
          ((StringBuffer)localObject).append("     -");
      }
      ((StringBuffer)localObject).append("  100%\n\n");
      System.out.print(localObject);
    }
  }
}