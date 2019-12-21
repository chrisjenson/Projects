public class UtilBillForLoop 
{
public static void main(String[] args)
{ 
   int weekMb = 2500;                 //Mb's for one week (5*500)
   int weekPhone = 500;               //Phone minutes for one week (100*500)
   int endMb = 2048;                  //1Gb = 1024Mb, for one weekend (1024*2)
   int endPhone = 400;                //Phone minutes for one weekend (200*2)0
   
   int weekSum = 0;
   int endSum = 0;
   
   for(int i = 0; i < 4; ++i)    //for the 4 weeks and weekends each month
   {
      weekSum += (weekMb + weekPhone);              //get total for all weeks
      endSum += (endMb + endPhone);             //get total for all weekends 
   }
 
   System.out.println("Your monthly bill is: " + (weekSum + endSum));     //prints sum of weeks and weekends  
}
}