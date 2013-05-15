/*************************************************************************
 * Copyright (C) 2010-2012,  Gfif Developers                              *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and Maintained By Omar Andres Zapata Mesa                *
 * All rights reserved.                                                   *
 *                                                                        *
 *                                                                        *
 * Some contributions Sigifredo Escobar 2010                            *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/

#ifndef ROOT_TMpiMessage
#define ROOT_TMpiMessage

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

#include<TMessage.h>
#include<TArray.h>

namespace ROOT {
   namespace Mpi {
      class TMpiMessage: public  TMessage {
      public:
         using TMessage::WriteObject;
         TMpiMessage(char *buffer, int size);
         TMpiMessage(UInt_t what = kMESS_ANY, Int_t bufsiz = TBuffer::kInitialSize);
         virtual ~TMpiMessage() {}
         template<class ClassType>  void WriteObject(ClassType * obj);
         void WriteObject(const void * obj, const TClass *cl);
      private:
         ClassDef(TMpiMessage, 0); //The class title
      };
#ifndef __CINT__
      template<class ClassType> void TMpiMessage::WriteObject(ClassType * obj)
      {
         //overloaded method from TMessage like template to serialize any TObject
         WriteObjectAny(obj, obj->Class()->GetClass(obj->Class_Name()));
      }
#endif

   }
}

#endif
