#include<TMpiMessage.h>
#include<TClass.h>

using namespace ROOT::Mpi;
ClassImp(TMpiMessage)
//______________________________________________________________________________
TMpiMessage::TMpiMessage(char *buffer, int size): TMessage(buffer, size)
{
   SetReadMode();
   Reset();
}

//______________________________________________________________________________
TMpiMessage::TMpiMessage(UInt_t what, Int_t bufsiz): TMessage(what, bufsiz) { }

//______________________________________________________________________________
void TMpiMessage::WriteObject(const void * obj, const TClass *cl)
{
   //overloaded method from TMessage like template to serialize any TObject
   WriteObjectAny(obj, cl);
}