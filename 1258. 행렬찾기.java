import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class solution {
	static int[][] map;
    static int n;

	public static void main(String[] args) {
		BuffferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine());
		
		for(int testCase=1; testCase<=T; testCase++) {
			n = Integer.parseInt(bf.readLine());
			map = new int[n][n];
			
			for(int i=0;i<n;i++) {
				StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
				for(int j=0;j<n;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
		}
		
		ArrayList<pair> list = new ArrayList<>();
		int cnt = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(map[i][j] != 0) {
					
				}
			}
		}
	}

}
