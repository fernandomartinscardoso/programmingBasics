//#include <iostream>
//#include <iomanip>
#include <time.h>
#include <conio.h>
#include <stdio.h>

main()
{
      int num=100, i;
      
      srand(time(NULL));
      
      for(i=0; i<=5; i++)
      {
               num=(rand());
               printf("%d", num);
      }
      
      getch();
}
