// 4/7,6/11,8/13,10/17,.....N terms
import java.util.*;
public class Series_1
{
    
        
    public static void main(String args[])
        {
            int i,c=0,d;
            
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter the denominator limit:");
            int p=sc.nextInt();
            
            System.out.println("Enter the starting value of numerator:");
            d=sc.nextInt();
             
            System.out.println("Enter the starting value of denominator:");
            int n=sc.nextInt();
            
            
            
            System.out.println("The series is :");
            while(n<=p)
            {
                for(i=1;i<=n;i++)
               {
               if(n%i==0)
               {
                   c=c+1;
                }
            }
            if(c==2)
            {
                System.out.print(d+"/"+n+" ");
                 d=d+2;
            
            }
           
            n=n+1;
            c=0;
        }
        
    }
}