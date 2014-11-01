// @(#)root/cont
// Author: Philippe Canal Aug 2013

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TListOfDataMembers                                                   //
//                                                                      //
// A collection of TDataMember objects designed for fast access given a //
// DeclId_t and for keep track of TDataMember that were described       //
// unloaded data member.                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TListOfDataMembers.h"
#include "TClass.h"
#include "TExMap.h"
#include "TDataMember.h"
#include "TGlobal.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"
#include "TEnumConstant.h"

constexpr unsigned int idsSize=19;

ClassImp(TListOfDataMembers)

//______________________________________________________________________________
TListOfDataMembers::TListOfDataMembers(TClass *cl /*=0*/) :
   fClass(cl),fIds(0),fUnloaded(0),fIsLoaded(kFALSE), fLastLoadMarker(0)
{
   // Constructor.
}

//______________________________________________________________________________
TListOfDataMembers::~TListOfDataMembers()
{
   // Destructor.

   THashList::Delete();
   delete fIds;
   if (fUnloaded) fUnloaded->Delete();
   delete fUnloaded;
}

//______________________________________________________________________________
void TListOfDataMembers::MapObject(TObject* obj)
{
   // Add a pair<id, object> to the map of data members and their ids.
   if (!fIds) fIds = new TExMap(idsSize);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         fIds->Add((Long64_t)d->GetDeclId(),(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g && g->GetDeclId()) {
         fIds->Add((Long64_t)g->GetDeclId(),(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddFirst(TObject *obj)
{
   // Add object at the beginning of the list.

   THashList::AddFirst(obj);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddFirst(TObject *obj, Option_t *opt)
{
   // Add object at the beginning of the list and also store option.
   // Storing an option is useful when one wants to change the behaviour
   // of an object a little without having to create a complete new
   // copy of the object. This feature is used, for example, by the Draw()
   // method. It allows the same object to be drawn in different ways.

   THashList::AddFirst(obj,opt);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddLast(TObject *obj)
{
   // Add object at the end of the list.

   THashList::AddLast(obj);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddLast(TObject *obj, Option_t *opt)
{
   // Add object at the end of the list and also store option.
   // Storing an option is useful when one wants to change the behaviour
   // of an object a little without having to create a complete new
   // copy of the object. This feature is used, for example, by the Draw()
   // method. It allows the same object to be drawn in different ways.

   THashList::AddLast(obj, opt);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddAt(TObject *obj, Int_t idx)
{
   // Insert object at location idx in the list.

   THashList::AddAt(obj, idx);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddAfter(const TObject *after, TObject *obj)
{
   // Insert object after object after in the list.

   THashList::AddAfter(after, obj);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddAfter(TObjLink *after, TObject *obj)
{
   // Insert object after object after in the list.

   THashList::AddAfter(after, obj);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddBefore(const TObject *before, TObject *obj)
{
   // Insert object before object before in the list.

   THashList::AddBefore(before, obj);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::AddBefore(TObjLink *before, TObject *obj)
{
   // Insert object before object before in the list.

   THashList::AddBefore(before, obj);
   MapObject(obj);
}

//______________________________________________________________________________
void TListOfDataMembers::Clear(Option_t *option)
{
   // Remove all objects from the list. Does not delete the objects unless
   // the THashList is the owner (set via SetOwner()).

   if (fUnloaded) fUnloaded->Clear(option);
   if (fIds) fIds->Clear();
   THashList::Clear(option);
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
void TListOfDataMembers::Delete(Option_t *option /* ="" */)
{
   // Delete all TDataMember object files.

   if (fUnloaded) fUnloaded->Delete(option);
   THashList::Delete(option);
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
TObject *TListOfDataMembers::FindObject(const char *name) const
{
   // Specialize FindObject to do search for the
   // a data member just by name or create it if its not already in the list

   TObject *result = THashList::FindObject(name);
   if (!result) {
      if (IsLoaded() && fClass && fClass->Property() & (kIsClass|kIsStruct|kIsUnion)) {
         // We already have all the information, no need to search more
         return 0;
      }

      R__LOCKGUARD(gInterpreterMutex);

      TInterpreter::DeclId_t decl;
      if (fClass) decl = gInterpreter->GetDataMember(fClass->GetClassInfo(),name);
      else        decl = gInterpreter->GetDataMember(0,name);
      if (decl) result = const_cast<TListOfDataMembers*>(this)->Get(decl);
   }
   return result;
}

//______________________________________________________________________________
TDictionary *TListOfDataMembers::Get(DeclId_t id)
{
   // Return (after creating it if necessary) the TDataMember
   // describing the data member corresponding to the Decl 'id'.

   if (!id) return 0;

   TDictionary *dm = fIds ? (TDataMember*)fIds->GetValue((Long64_t)id) : 0;
   if (!dm) {
      if (fClass) {
         if (!fClass->HasInterpreterInfoInMemory()) {
            // The interpreter does not know about this class yet (or a problem
            // occurred that prevented the proper updating of fClassInfo).
            // So this decl can not possibly be part of this class.
            // [In addition calling GetClassInfo would trigger a late parsing
            //  of the header which we want to avoid].
            return 0;
         }
         if (!gInterpreter->ClassInfo_Contains(fClass->GetClassInfo(),id)) return 0;
      } else {
         if (!gInterpreter->ClassInfo_Contains(0,id)) return 0;
      }

      R__LOCKGUARD(gInterpreterMutex);

      DataMemberInfo_t *info = gInterpreter->DataMemberInfo_Factory(id,fClass ? fClass->GetClassInfo() : 0);

      // Let's see if this is a reload ...
      const char *name = gInterpreter->DataMemberInfo_Name(info);

      TDictionary *update = fUnloaded ? (TDictionary *)fUnloaded->FindObject(name) : 0;
      if (update) {
         if (fClass) {
            ((TDataMember*)update)->Update(info);
         } else {
            ((TGlobal*)update)->Update(info);
         }
         dm = update;
      }
      if (!dm) {
         if (fClass) dm = new TDataMember(info, fClass);
         else dm = new TGlobal(info);
      }
      // Calling 'just' THahList::Add would turn around and call
      // TListOfDataMembers::AddLast which should *also* do the fIds->Add.
      THashList::AddLast(dm);
      if (!fIds) fIds = new TExMap(idsSize);
      fIds->Add((Long64_t)id,(Long64_t)dm);
   }
   return dm;
}

//______________________________________________________________________________
TDictionary *TListOfDataMembers::Get(DataMemberInfo_t *info)
{
   // Return (after creating it if necessary) the TDataMember
   // describing the data member corresponding to the Decl 'id'.

   if (!info) return 0;

   TDictionary::DeclId_t id = gInterpreter->GetDeclId(info);
   R__ASSERT( id != 0 && "DeclId should not be null");
   TDictionary *dm = fIds ? (TDataMember*)fIds->GetValue((Long64_t)id) : 0;
   if (!dm) {
      if (fClass) {
         if (!fClass->HasInterpreterInfoInMemory()) {
            // The interpreter does not know about this class yet (or a problem
            // occurred that prevented the proper updating of fClassInfo).
            // So this decl can not possibly be part of this class.
            // [In addition calling GetClassInfo would trigger a late parsing
            //  of the header which we want to avoid].
            return 0;
         }
         if (!gInterpreter->ClassInfo_Contains(fClass->GetClassInfo(),id)) return 0;
      } else {
         if (!gInterpreter->ClassInfo_Contains(0,id)) return 0;
      }

      R__LOCKGUARD(gInterpreterMutex);

      DataMemberInfo_t *dm_info = gInterpreter->DataMemberInfo_FactoryCopy(info);

      // Let's see if this is a reload ...
      const char *name = gInterpreter->DataMemberInfo_Name(info);
      TDataMember *update = fUnloaded ? (TDataMember *)fUnloaded->FindObject(name) : 0;
      if (update) {
         update->Update(dm_info);
         dm = update;
      }
      if (!dm) {
         if (fClass) dm = new TDataMember(dm_info, fClass);
         else dm = new TGlobal(dm_info);
      }
      // Calling 'just' THahList::Add would turn around and call
      // TListOfDataMembers::AddLast which should *also* do the fIds->Add.
      THashList::AddLast(dm);
      if (!fIds) fIds = new TExMap(idsSize);
      fIds->Add((Long64_t)id,(Long64_t)dm);
   }
   return dm;
}

//______________________________________________________________________________
void TListOfDataMembers::UnmapObject(TObject* obj)
{
   // Remove a pair<id, object> from the map of data members and their ids.
   if (!fIds) return;
   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         if (d->GetDeclId()) {
            fIds->Remove((Long64_t)d->GetDeclId());
         }
         d->Update(0);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         if (g->GetDeclId()) {
            fIds->Remove((Long64_t)g->GetDeclId());
         }
         g->Update(0);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::RecursiveRemove(TObject *obj)
{
   // Remove object from this collection and recursively remove the object
   // from all other objects (and collections).
   // This function overrides TCollection::RecursiveRemove that calls
   // the Remove function. THashList::Remove cannot be called because
   // it uses the hash value of the hash table. This hash value
   // is not available anymore when RecursiveRemove is called from
   // the TObject destructor.

   if (!obj) return;

   THashList::RecursiveRemove(obj);
   if (fUnloaded) fUnloaded->RecursiveRemove(obj);
   UnmapObject(obj);

}

//______________________________________________________________________________
TObject* TListOfDataMembers::Remove(TObject *obj)
{
   // Remove object from the list.

   Bool_t found;

   found = THashList::Remove(obj);
   if (!found && fUnloaded) {
      found = fUnloaded->Remove(obj);
   }
   UnmapObject(obj);
   if (found) return obj;
   else return 0;
}

//______________________________________________________________________________
TObject* TListOfDataMembers::Remove(TObjLink *lnk)
{
   // Remove object via its objlink from the list.

   if (!lnk) return 0;

   TObject *obj = lnk->GetObject();

   THashList::Remove(lnk);
   if (fUnloaded) fUnloaded->Remove(obj);

   UnmapObject(obj);
   return obj;
}

//______________________________________________________________________________
void TListOfDataMembers::Load()
{
   // Load all the DataMembers known to the intepreter for the scope 'fClass'
   // into this collection.

   if (fClass && fClass->Property() & (kIsClass|kIsStruct|kIsUnion)) {
      // Class and union are not extendable, if we already
      // loaded all the data member there is no need to recheck
      if (fIsLoaded) return;
   }

   // This will provoke the parsing of the headers if need be.
   if (fClass && fClass->GetClassInfo() == 0) return;

   R__LOCKGUARD(gInterpreterMutex);

   ULong64_t currentTransaction = gInterpreter->GetInterpreterStateMarker();
   if (currentTransaction == fLastLoadMarker) {
      return;
   }
   fLastLoadMarker = currentTransaction;

   // In the case of namespace, even if we have loaded before we need to
   // load again in case there was new data member added.

   // Mark the list as loaded to avoid an infinite recursion in the case
   // where we have a data member that is a variable size array.  In that
   // case TDataMember::Init needs to get/load the list to find the data
   // member used as the array size.
   fIsLoaded = kTRUE;

   ClassInfo_t *info;
   if (fClass) info = fClass->GetClassInfo();
   else info = gInterpreter->ClassInfo_Factory();

   DataMemberInfo_t *t = gInterpreter->DataMemberInfo_Factory(info);
   while (gInterpreter->DataMemberInfo_Next(t)) {
      if (gInterpreter->DataMemberInfo_IsValid(t)) {
         // Get will check if there is already there or create a new one
         // (or re-use a previously unloaded version).
         Get(t);
      }
   }
   if (!fClass) gInterpreter->ClassInfo_Delete(info);
}

//______________________________________________________________________________
void TListOfDataMembers::Streamer(TBuffer &R__b)
{
   // Stream an object of class TListOfDataMembers.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TListOfDataMembers::Class(),this);
      fIsLoaded = kTRUE;
   } else {
      R__b.WriteClassBuffer(TListOfDataMembers::Class(),this);
   }
}

//______________________________________________________________________________
void TListOfDataMembers::Update(TDictionary *member) {
   // Move the member or data member to the expect set of list.

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(member);
      if (d) {
         if (d->GetDeclId()) {
            if (!fIds) fIds = new TExMap(idsSize);
            fIds->Add((Long64_t)d->GetDeclId(),(Long64_t)d);
         }
         TDictionary *update = fUnloaded ? (TDictionary *)fUnloaded->FindObject(d->GetName()) : 0;
         if (update) fUnloaded->Remove(update);

         if (! THashList::FindObject(d) ) {
            // Calling 'just' THahList::Add would turn around and call
            // TListOfDataMembers::AddLast which should *also* do the fIds->Add.
            THashList::AddLast(d);
         }
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(member);
      if (g) {
         if (g->GetDeclId()) {
            if (!fIds) fIds = new TExMap(idsSize);
            fIds->Add((Long64_t)g->GetDeclId(),(Long64_t)g);

            TDictionary *update = fUnloaded ? (TDictionary *)fUnloaded->FindObject(g->GetName()) : 0;
            if (update) fUnloaded->Remove(update);

            if (! THashList::FindObject(g) ) {
               // Calling 'just' THahList::Add would turn around and call
               // TListOfDataMembers::AddLast which should *also* do the fIds->Add.
               THashList::AddLast(g);
            }
         }
      }
   }


}

//______________________________________________________________________________
void TListOfDataMembers::Unload()
{
   // Mark 'all func' as being unloaded.
   // After the unload, the data member can no longer be found directly,
   // until the decl can be found again in the interpreter (in which
   // the func object will be reused.

   TObjLink *lnk = FirstLink();
   while (lnk) {
      TDictionary *data = (TDictionary *)lnk->GetObject();
      UnmapObject(data);
      fUnloaded = new THashList;
      fUnloaded->Add(data);

      lnk = lnk->Next();
   }

   THashList::Clear();
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
void TListOfDataMembers::Unload(TDictionary *mem)
{
   // Mark 'func' as being unloaded.
   // After the unload, the data member can no longer be found directly,
   // until the decl can be found again in the interpreter (in which
   // the func object will be reused.

   if (THashList::Remove(mem)) {
      // We contains the object, let remove it from the other internal
      // list and move it to the list of unloaded objects.

      UnmapObject(mem);
      fUnloaded = new THashList;
      fUnloaded->Add(mem);
   }
}
