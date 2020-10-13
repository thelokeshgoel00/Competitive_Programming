import java.util.*;


public class AnaGramcheck{

	public static void main(String[] args) {
		 Scanner s= new Scanner (System.in);
		 int T= s.nextInt();
		 s.nextLine();
		 while(T-- >0) {
		 String s1=s.nextLine();
		 String s2=s.nextLine();
		 s1.trim();
		 s2.trim();
		  
		  ArrayList<Integer> a =new ArrayList<>();
		  ArrayList<Integer> b =new ArrayList<>();
		  if(s1.length()==s2.length()) {
			  int size=s1.length();
			 int m=0,n=0;
		 
			  for(int i=0;i< size;i++) {
				  m=s1.charAt(i);
				  n=s2.charAt(i);
				  a.add(m);
				  b.add(n);
			  }
			   
		 Collections.sort(a);
		 Collections.sort(b);
		 if(a.equals(b)) 
			 System.out.println("YES");
		 else 
			 System.out.println("NO");
		 
			 
		 }
		  else
			  System.out.println("NO");
		  
           
		 }
	 }
	}
 
