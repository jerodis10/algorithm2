import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc=1;tc<=T;tc++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			long AA = toNine(A);
			long BB = toNine(B);
			long AAA = toDigit(AA);
			long BBB = toDigit(BB);
			long res = BBB-AAA;
			
			if( (AAA<0 && BBB<0) || (AAA>0 && BBB>0) )
			{ } else {
				res = res - 1;
			}

			System.out.println("#"+tc+" "+res);
		} 
		
	}
	
	public static long toNine(long A) {
		boolean minus = false;; 
		if( A < 0 ) {
			minus = true;
		}
		String s = Math.abs(A)+"";
		StringBuffer sb = new StringBuffer("");
		if ( minus ) {
			sb.append("-");
		}
		for(int i=0; i<s.length();i++) {
			if( (s.charAt(i)-'0') > 4 ) {
				sb.append(s.charAt(i)-'1');
			} else {
				sb.append(s.charAt(i)-'0');
			}
		}
		return Long.parseLong(sb.toString());
	}
	
	public static long toDigit(long A) {
		boolean minus = false;; 
		if( A < 0 ) {
			minus = true;
		}
		String s = A+"";
		Long res = (long) 0;
		Long cipher = (long) 0;
		
		for(int i=s.length()-1; i>=0;i--) {
			if ( s.charAt(i) == '-')
				continue;
			res += (s.charAt(i)-'0') * (long)Math.pow(9, cipher++);
		}
		if ( minus ) {
			res = res * -1;
		}
		return res;
	}
}