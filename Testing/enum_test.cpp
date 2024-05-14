// gcc -o day_test enum_test.cpp && ./day_test
#include <stdio.h>
 
enum DAY
{
      MON=-1, TUE=1, WED, THU, FRI, SAT, SUN
};
 
int main()
{
    enum DAY day;
    day = MON;
    printf("%d\n",day);
    day = TUE;
    printf("%d\n",day);
    day = WED;
    printf("%d\n",day); 
    day = THU;
    printf("%d\n",day);
    return 0;
}