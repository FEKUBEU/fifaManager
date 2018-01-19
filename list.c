
#include "list.h"
#include "datastruct.h"
/*
extern TeamList *FirstTeam = NULL;
extern TeamList *LastTeam = NULL;
*/

/**********************************************************
 * appendInList
 * Haengt ein neues Listenelement an das Ende
 * der doppelt verketteten Liste an.
 * Parameter: Neu - Zeiger auf neues Listenelement
 * Rueckgabe: Wahrheitswert, ob das neue Listenelement an
 *            die Liste angehangen werden konnte
 **********************************************************/
/*
int appendInList(TeamList *Neu)
{
   // pruefen, ob neues Listenelement existiert
   if (Neu == NULL)
      return 0;

   if (FirstTeam == NULL)
   {  // Fall 1: Liste ist leer
      Neu->Next = Neu->Prev = NULL;
      FirstTeam = LastTeam = Neu;
   }
   else
   {  // Fall 2: Liste ist nicht leer
      Neu->Next = NULL;
      Neu->Prev = LastTeam;
      LastTeam = LastTeam->Next = Neu;
   }

   return 1;
}

/**********************************************************
 * insertInList
 * Fuegt ein neues Listenelement in eine doppelt verkettete
 * Liste sortiert nach dem Index ein.
 * Parameter: Neu - Zeiger auf das neue Listenelement
 * Rueckgabe: Wahrheitswert, ob das neue Listenelement in
 *            der Liste eingefuegt werden konnte.
 **********************************************************/
/*
int insertInList(TeamList *Neu)
{
   TeamList *temp = FirstTeam;

   // pruefen, ob neues Listenelement existiert
   if (Neu == NULL)
      return 0;

   if (FirstTeam == NULL)
   {  // Fall 1: Liste ist leer
      Neu->Next = Neu->Prev = NULL;
      FirstTeam = LastTeam = Neu;
      return 1;
   }

   if (FirstTeam->Index >= Neu->Index)
   {  // Fall 2: vor dem ersten Element einfuegen
      Neu->Next = FirstTeam;
      Neu->Prev = NULL;
      FirstTeam = FirstTeam->Prev = Neu;
      return 1;
   }

   if (LastTeam->Index <= Neu->Index)
   {  // Fall 3: nach dem letzten Element einfuegen
      Neu->Prev = LastTeam;
      Neu->Next = NULL;
      LastTeam = LastTeam->Next = Neu;
      return 1;
   }

   // Fall 4: zwischen zwei Listenelement einfuegen
   while (temp->Next != NULL)
   {  // pruefen, ob neues Listenelement vor dem
      // naechsten Element eingefuegt werden muss
      if (temp->Next->Index >= Neu->Index)
      {
         Neu->Next = temp->Next;
         Neu->Prev = temp;
         temp->Next = temp->Next->Prev = Neu;
         return 1;
      }
      temp = temp->Next;
   }

   return 0;
}

/**********************************************************
 * removeFromList
 * Entfernt das (erste) Listenelement, dessen Index dem
 * delIndex (Parameter) entspricht, aus der verketteten
 * Liste
 * Parameter: delIndex - der Index des zu entfernenden Elements
 * Rueckgabe: Zeiger auf das entfernte Listenelement bzw.
 *            NULL-Zeiger, wenn das Listenelement nicht
 *            gefunden wurde
 **********************************************************/
/*
TeamList *removeFromList(int delIndex)
{
   TeamList *tmp = NULL, *prev = NULL;

   // Fall 1: Liste leer?
   if (FirstTeam == NULL)
      return NULL;

   // Fall 2: Listenanfang entfernen?
   if (FirstTeam->Index == delIndex)
   {
      tmp = FirstTeam;
      FirstTeam = FirstTeam->Next;
      // nur ein Element in Liste?
      if (FirstTeam == NULL)
         LastTeam = NULL;
      else
         FirstTeam->Prev = NULL;
      return tmp;
   }

   // Fall 3: Listenende entfernen?
   if (LastTeam->Index == delIndex)
   {
      tmp = LastTeam;
      LastTeam = LastTeam->Prev;
      LastTeam->Next = NULL;
      return tmp;
   }

   // Fall 4: zu entfernendes Element suchen
   tmp = FirstTeam->Next;
   while (tmp != NULL)
   {
      if (tmp->Index == delIndex)
      {
         prev = tmp->Prev;
         prev->Next = tmp->Next;
         prev->Next->Prev = prev;
         return tmp;
      }
      tmp = tmp->Next;
   }

   return NULL;
}

*/


