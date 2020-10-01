import java.util.*;
import java.util.Map.Entry;
public class CF1399C {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t=0;
		if(sc.hasNextInt())
			t = sc.nextInt();
		
		for(int h=0;h<t;h++)
		{
			
			int n= sc.nextInt();
			ArrayList<Integer> list = new ArrayList<>();  // to store weights of all players
			for(int i=0;i<n;i++)
			{
				int x = sc.nextInt();
				list.add(x);
			}
			HashSet<Integer> set = new HashSet<>();   // to store non duplicate sum of weights values
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++) {
					
 					int sum = list.get(i)+list.get(j);  //storing all possible vlaues of sum 
					set.add(sum);
					
				}
			}
			
			int maxans=Integer.MIN_VALUE;
			for(int sum: set) {
				int ans=0,i=0,j=0;
				boolean[] check = new boolean[n];        //if already checked array

				while(i<n)
				{
					j=i+1;
					while(j<n)
					{
						if(list.get(j)==sum-list.get(i) && check[j]==false && check[i]==false) {
							ans++;
							check[j] = true;
							check[i] = true;
						}
						j++;
					}
					i++;
				}
				maxans = Math.max(maxans, ans);    //maximum number of teams 
			}
			System.out.println(maxans);
		}
	}


}