#include "../lib/LCD12864R/LCD12864R.h"
#define AR_SIZE(a) sizeof(a)/ sizeof(a[0])

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
    LCDA.Initialise(); //Pantalla
    LCDA.CLEAR();  //Pantalla
    delay(1000);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
//    LCDA.CLEAR();
//    delay(100);
//    LCDA.DisplaySig(0,0,0x20);
//    delay(100);
    LCDA.DisplayString(0,0,"Hello everyone!",AR_SIZE("Hello everyone!"));;//LOGO
    LCDA.DisplayString(1,0, "How do you do?", 14); //imprimimos en pantalla...
    LCDA.DisplayString(2,0, "How is it going?", 16); //imprimimos en pantalla......
    LCDA.DisplayString(3,0, "Is everything ok", 16); //imprimimos en pantalla...
}





