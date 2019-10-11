package sample;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCase = Integer.parseInt(br.readLine());
		for (int t = 1; t <= testCase; t++) {
			int k = Integer.parseInt(br.readLine());
			k -= 1;
			String str = br.readLine();
			String[] suffixArray = new String[str.length()];
			for (int i = 0; i < str.length(); i++) {
				suffixArray[i] = str.substring(i);
			}
			Arrays.sort(suffixArray);
			if (suffixArray[k].isEmpty())
				System.out.println("#" + t + " " + "none");
			else
				System.out.println("#" + t + " " + suffixArray[k]);
		}
	}
}
