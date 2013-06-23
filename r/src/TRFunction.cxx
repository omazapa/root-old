/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#include<TRFunction.h>
//______________________________________________________________________________
/* Begin_Html
<center><h2>InternalFunction class</h2></center>

<p>
The TRFunction's class lets you to pass ROOT functions to R enviroment<br>
</p>
<hr>
End_Html
*/


using namespace ROOT::R;
ClassImp(TRFunction)

//______________________________________________________________________________
TRFunction::TRFunction(const TRFunction &fun): TObject(fun)
{
   f = fun.f;
}