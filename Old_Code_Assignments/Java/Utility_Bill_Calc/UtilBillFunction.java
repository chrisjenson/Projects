public class UtilBillFunction 
{

public static int weekCost(int Mb, int minutes){       //Intakes the amount of megabytes and minutes 
      int weekTotal = (4 * (Mb + minutes));            //since each Mb and min = $1, add for that week
                                                       //times 4 for each week
      return weekTotal;                                     
}

public static int endCost(int Mb, int minutes){       //Intakes the amount of megabytes and minutes
      int weekendTotal = (4 * (Mb + minutes));        //since each Mb and min = $1, add for that week 
                                                      //times 4 for each week
      return weekendTotal;                                     
}

public static void main(String[] args)
{
   int weekMb = 2500;                 //Mb's for one week (5*500)
   int weekPhone = 500;               //Phone minutes for one week (100*500)
   int endMb = 2048;                  //1Gb = 1024Mb, for one weekend (1024*2)
   int endPhone = 400;                //Phone minutes for one weekend (200*2)
    
   int totalBill = (weekCost(weekMb, weekPhone) + endCost(endMb, endPhone));     
   
   System.out.println("Your monthly bill is: " + totalBill);
}
}