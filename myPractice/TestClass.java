import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class TestClass
{
   public static int gEnergy = -1;
   public static void maxEnergyIncreasingSS(int arr[], int n,
         int k, int prevI, int curI, int size, int energy)
   {
      if( size >= k )
      {
         if( energy > gEnergy )
            gEnergy = energy;
         return;
      }

      if( curI >= n )
         return;

      if( prevI == -1 )
      {
         maxEnergyIncreasingSS(arr, n, k, prevI+1, curI+1, size+1, energy);
         maxEnergyIncreasingSS(arr, n, k, prevI, curI+1, size, energy);
      }
      else
      {
         if( arr[curI] < arr[prevI] )
            return;

         maxEnergyIncreasingSS(arr, n, k, curI, curI+1, size+1, energy+arr[curI]-arr[prevI]);
         maxEnergyIncreasingSS(arr, n, k, prevI, curI+1, size, energy);
      }
   }

   public static void main(String args[] ) throws Exception
   {
      Scanner s = new Scanner(System.in);
      int n, k;
      n = s.nextInt();
      k = s.nextInt();
      s.nextLine();
      int arr[] = new int[n];
      for( int i = 0; i < n; ++i )
         arr[i] = s.nextInt();
      s.nextLine();
      maxEnergyIncreasingSS(arr, n, k, -1, 0, 0, 0);
      System.out.println(gEnergy);
   }
}

