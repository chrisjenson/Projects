public class UtilBillStatic 
{
   static int weekMb = 2500;                 //Mb's for one week (5*500)
   static int weekPhone = 500;               //Phone minutes for one week (100*500)
   static int endMb = 2048;                  //1Gb = 1024Mb, for one weekend (1024*2)
   static int endPhone = 400;                //Phone minutes for one weekend (200*2)

public static void main(String[] args)
{
   int totalBill = (4 * (weekMb + weekPhone + endMb + endPhone));     
   
   System.out.println("Your monthly bill is: " + totalBill);
}
}