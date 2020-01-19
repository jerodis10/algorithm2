import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static int[][] map;
    static int n;

	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
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
		
		
			ArrayList<pair> list = new ArrayList<>();
			int cnt = 0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(map[i][j] != 0) {
						endY = -1;
						endX = -1;
						dfs(i,j);
						list.add(new pair(endY-i+1, endX-j+1));
						cnt++;
					}
				}
			}
			System.out.println("#" + testCase + " " + cnt);
			
			list.sort(null);
			for(pair p : list) {
				System.out.println(" "+p.y+" "+p.x);
			}
			System.out.println();
		}
	}
	
	static int endY, endX;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	
	public static void dfs(int y, int x) {
		map[y][x] = 0;
		endY = endY < y ? y : endY;
		endX = endX < x ? x : endX;
		for(int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0 || ny>n-1 || nx<0 || nx>n-1 || map[ny][nx]==0)
				continue;
			
			dfs(ny,nx);
		}
	}
	
	static class pair implements Comparable<pair> {
		int y;
		int x;
		
		public pair(int y, int x) {
			super();
			this.y=y;
			this.x=x;
		}
		
		@Override
		public int compareTo(pair o) {
			int oMul = o.y * o.x;
			int thisMul = this.y * this.x;
			
			if(oMul == thisMul) {
				return this.y - o.y;
			} else {
				return thisMul - oMul;
			}
		}
	}
}
