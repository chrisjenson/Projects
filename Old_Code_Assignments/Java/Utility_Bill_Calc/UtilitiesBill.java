public class UtilitiesBill {

   static int weekInt = 500;                 //Mb's for one week
   static int weekPhone = 100;               //Phone minutes for one week
   static int weekendInt = 1024;             //1Gb = 1024Mb, for one weekend
   static int weekendPhone = 200;            //Phone minutes for one weekend

public static int weekCost(int Mb, int minutes){       //Intakes the amount of megabytes and minutes 
      int weekTotal = (Mb + minutes);                  //since each Mb and min = $1, add for that week

      return weekTotal;                                     
}

public static int weekendCost(int Mb, int minutes){       //Intakes the amount of megabytes and minutes
      int weekendTotal = (Mb + minutes);                  //since each Mb and min = $1, add for that week 

      return weekendTotal;                                     
}

public static void main(String[] args){ 

   int weekSum = 0;        //start months bill at zero
   int weekendSum = 0;

   for(int i = 0; i < 4; ++i)    //for the 4 weeks and weekends each month
   {
      weekSum += weekCost(weekInt, weekPhone);              //get total for all weeks
      weekendSum += weekendCost(weekendInt, weekendPhone);  //get total for all weekends 
   }
 
   System.out.println("Your monthly bill is: " + (weekSum + weekendSum));     //prints sum of weeks and weekends
}
}
   