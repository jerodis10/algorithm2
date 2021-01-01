import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	
	static int T;
	static int N;
	static int ret;
	static String[] map;
	static int[] row;
	static int[] col;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		int t = 1;
        while(T-- >0) {
        	N = Integer.parseInt(br.readLine());
        	ret = 0;
        	map = new String[1000];
        	row = new int[1000];
        	col = new int[1000];
        	
            for(int i=0;i<N;i++) {
            		map[i] = br.readLine();
            } 
            
            for(int i=0;i<N;i++) {
            	for(int j=0;j<N;j++) {
            		if(map[i].charAt(j) == 'B') {
	        			row[i]++;
	        			col[j]++;
	        		}
            	}
            }
            
            for(int i=0;i<N;i++) {
            	for(int j=0;j<N;j++) {
            		int cnt = row[i] + col[j];
            		if(map[i].charAt(j) == 'B') cnt++;
            		if(cnt % 2 == 1) ret++;
            	}
            }
            
            System.out.printf("#%d %d\n", t++, ret);
        }
	}
}
