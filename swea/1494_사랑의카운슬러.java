import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int T;
	static int N;
	static int sumX, sumY;
	static int[][] m;
	static long min;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		int t = 1;
        while(T-- >0) {
        	N = Integer.parseInt(br.readLine());
        	m = new int[N][2];
        	sumX=0;
        	sumY=0;
        	
        	for(int i=0;i<N;i++) {
        		StringTokenizer st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken());
        		int y = Integer.parseInt(st.nextToken());
        		
        		m[i][0] = x;
        		m[i][1] = y;
        		
        		sumX += x;
        		sumY += y;
        	}
        	
        	int[] set = new int[100];
        	
        	min = Long.MAX_VALUE;
        	comb(set, 0, N, N/2, 0);
            
            System.out.printf("#%d %d\n", t++, min);
        }
	}
	
	public static void comb(int[] set, int size, int N, int K, int index) {
		if(K==0) {
			int sumSelectX=0;
			int sumSelectY=0;
			for(int i=0;i<size;i++) {
				sumSelectX += m[set[i]][0];
				sumSelectY += m[set[i]][1];
			}
			
			int sumUnselectX = sumX - sumSelectX;
			int sumUnselectY = sumY - sumSelectY;
			
			long vX = sumSelectX - sumUnselectX;
			long vY = sumSelectY - sumUnselectY;
			long v = vX * vX + vY * vY;
			if(min > v) min = v;
			return;
		} else if(N == index) return;
		
		set[size] = index;
		comb(set, size+1, N, K-1, index+1);
		comb(set, size, N, K, index+1);
	}
}
