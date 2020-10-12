 // Question- You are given two integer a and b. Print the greatest integer which completely divide a and b. (remainder=0)

import java.util.*;

public class LovelyNo {

	public static void main(String[] args) {
		int cd=0;
	 
		Scanner s= new Scanner(System.in);
		int T=s.nextInt();
		while(T-- >0) {
			int a=s.nextInt();
			int b=s.nextInt();
			for(int j=1;j<=a && j<=b;j++) {
				 if(a % j==0 && b % j==0)
		              cd = j;
				  
		}
	  
		System.out.println(cd );
		 cd=1;
		}
		
	}

}
 
 