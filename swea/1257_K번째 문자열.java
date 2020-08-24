import java.io.*;
import java.util.*;

public class Solution {
	static String originalWord;
	static int T, K;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		for(int tc=1; tc<=T; tc++) {
			K = Integer.parseInt(br.readLine());
			originalWord = br.readLine();
			Set<String> allWords = new TreeSet<String>();
			for(int i=1; i<=originalWord.length(); i++) {
				for(int j=originalWord.length()-i; j>=0; j--) {
					allWords.add(originalWord.substring(j, i+j));
				}
			}
			List<String> sortedAllWords = new ArrayList<String>(allWords);
			
			if(K>sortedAllWords.size()) {
				System.out.printf("#%s none%n", tc);
			}
			else {
				System.out.printf("#%s %s%n", tc, sortedAllWords.get(K-1));
			}

		}
	}
}

