package java_assignment;

import java.util.Scanner;

public class ques_7 
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter First String: ");
		String str1=sc.nextLine();
		System.out.print("Enter Second String: ");
		String str2=sc.nextLine();
		int count=0;
		for(int i=0;i<(str2.length()-str1.length())+1;i++)
		{
			String substr=str2.substring(i,str1.length()+i);
			if(str1.compareTo(substr)==0)
			{
				count++;
			}
			substr="";
		}
		if(count>0)
		{
			System.out.println("String 2 contains string 1 ");
			System.out.print("No of occurences: "+count);
		}
		else
		{
			System.out.print("String 2 does not contain string 1");
		}
		sc.close();
	}
}
