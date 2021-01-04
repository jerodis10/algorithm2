import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	
	static int n,k, ret, tc;
    static int [] loc,dist;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		tc = Integer.parseInt(br.readLine());
		
        for(int t=1;t<=tc;t++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	k = Integer.parseInt(st.nextToken());
        	loc = new int[n];
        	dist = new int[n-1];
        	ret = 0;
        	st=new StringTokenizer(br.readLine());
        	for(int i=0;i<n;i++) {
        		loc[i] = Integer.parseInt(st.nextToken());
        	}
            for(int i=0;i<n-1;i++){
                dist[i]=loc[i+1]-loc[i];
            }
            Arrays.sort(dist);
            for(int i=0;i<n-k;i++){
                ret+=dist[i];
            }
        	
            System.out.printf("#%d %d\n", t, ret);
        }
	}
}
