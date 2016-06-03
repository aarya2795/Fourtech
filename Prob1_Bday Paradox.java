import java.util.*;

public class parad
{
	
	public int day;
	public int occ;
	
	public parad(int day1,int num)
	{
		this.day=day1;
		this.occ=num;
	}
	public int getday()
	{
		return day;
	}
	public int getno()
	{
		return occ;
		
	}
	public void setday(int day){this.day=day;}
	public void setno(int no){this.occ=no;}
}

class paradox
{
	public static void main(String args[])
	{
		System.out.println("*-*-*-*-*-* Birthday Paradox Problem *-*-*-*-*-*");
		System.out.println("\nEnter no of students :: ");
		Scanner sc=new Scanner(System.in);
		int no=sc.nextInt();
		int arr[]=new int[no];	  //arr is to store input birthdates
		parad[] p=new parad[no]; //array of objects
		
		Random randno = new Random();
		for(int i=0;i<no;i++)
		{
			arr[i]=randno.nextInt(365)+1;
		}
		
		System.out.println("\nThe Birthdates generated randomly are as follows:-\n");
		for(int i=0;i<no;i++)
		{
			System.out.println(arr[i]);
		}
		
		int c=0;
		for(int i=0;i<no;i++)
		{
			int flag=1;
			
				for(int j=0;j<c;j++)
				{
				  	if(arr[i]==p[j].getday())
				  	{
				  		p[j].setno(p[j].getno()+1);
				  		flag=0;
				  		break;
				  	}
				}
				if(flag==1)
				{
					p[c]=new parad(arr[i],1);
					c++;
				}
		}
		int m=no*(no-1)/2;
		double probab=1-Math.pow(0.997260274,m);
		probab=probab*100;			//to express in terms of percentage
		System.out.println("PROBABILITY FOR "+no+" STUDENTS IS "+probab+" %");
		System.out.println("\nReapeated Birthdate | Occurence");
		System.out.println("===============================");
		for(int i=0;i<c;i++)
		{
			if(p[i].getno()>1)
				
				System.out.println("\t"+p[i].getday()+"\t    |\t"+p[i].getno());
		}	
	}
}
