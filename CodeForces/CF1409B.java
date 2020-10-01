 
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class CF1409B {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int t=0;
		if(sc.hasNextInt())
			t=sc.nextInt();
		
		for(int i=0;i<t;i++) {
			
			long x= sc.nextInt();                                 //taking inputs accroding to question
			long y= sc.nextInt();
			long a = sc.nextInt();
			long b = sc.nextInt();
			long n = sc.nextInt();
			
			long ch1 = x-a;                                      //maximum change in a
			long ch2 = y-b;                                      //maximum change in b  
			
			long minprod = Long.MAX_VALUE;
			
			if(ch1+ch2<=n) minprod = a*b;                          //sum of maximum changes in both a and b allowed
			else {                                                 // sum of maximum changes is not allowed
				if((n>=ch1) &&y-n+ch1>=b)
				minprod = Math.min(minprod, a*(y-n+ch1));              
				if(n>=ch2 && x-n+ch2>=a)
				minprod = Math.min(minprod, b*(x-n+ch2));
				if(x-n>=a)minprod = Math.min(minprod, (x-n)*y); 
				if(y-n>=b)minprod = Math.min(minprod, x*(y-n));
			}
			
			
			System.out.println(minprod);
			
		}

}
}