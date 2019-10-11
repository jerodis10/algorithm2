package sample;

import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
	static int T;
	static int v, e, a, b;
	static int n;
	static Node nodes[];
	static int[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		int t = 1;
		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			v=Integer.parseInt(st.nextToken());
			e=Integer.parseInt(st.nextToken());
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			
			nodes=new Node[v+1];
			visited=new int[v+1];
			n=0;
			for(int i=1; i<=v;i++){
				nodes[i]=new Node(i);
			}
			
			st= new StringTokenizer(br.readLine());
			
			for(int i=0;i<e;i++){
				int p=Integer.parseInt(st.nextToken());
				int c=Integer.parseInt(st.nextToken());
				
				if(nodes[p].l == 0){
					nodes[p].l=c;
				}
				else{
					nodes[p].r=c;
				}
				nodes[c].p=p;
			}
				
				int parent=1;
				
				while (true) {
					if(a!=1){
						int pa=nodes[a].p;
						
						if(visited[pa]==1){
							parent=pa;
							break;
						}
						visited[pa]=1;
						a=pa;
					}
					if(b!=1){
						int pb=nodes[b].p;
						
						if(visited[pb]==1){
							parent=pb;
							break;
						}
						visited[pb]=1;
						b=pb;
					}
				}
				get(nodes[parent]);
				System.out.println("#"+t + " "+parent+" "+n);
				t++;
			}
		}
		
		static void get(Node node){
			n++;
			if(node.l!=0) get(nodes[node.l]);
			if(node.r!=0) get(nodes[node.r]);
		}
}


class Node {
	int data;
	int p;
	int l;
	int r;

	Node(int data) {
		this.data = data;
		this.p = 0;
		this.l = 0;
	}
}
