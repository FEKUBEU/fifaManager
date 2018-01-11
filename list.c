#include "datastruct.h"

/**********************************************************
 * appendInList
 * Haengt ein neues Listenelement an das Ende
 * der doppelt verketteten Liste an.
 * Parameter: Neu - Zeiger auf neues Listenelement
 * Rueckgabe: Wahrheitswert, ob das neue Listenelement an
 *            die Liste angehangen werden konnte
 **********************************************************/
int appendInList(TTeam *Neu)
{
   // pruefen, ob neues Listenelement existiert
   if (Neu == NULL)
      return 0;

   if (First == NULL)
   {  // Fall 1: Liste ist leer
      Neu->Next = Neu->Prev = NULL;
      First = Last = Neu;
   }
   else
   {  // Fall 2: Liste ist nicht leer
      Neu->Next = NULL;
      Neu->Prev = Last;
      Last = Last->Next = Neu;
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
int insertInList(TTeam *Neu)
{
   TTeam *temp = First;

   // pruefen, ob neues Listenelement existiert
   if (Neu == NULL)
      return 0;

   if (First == NULL)
   {  // Fall 1: Liste ist leer
      Neu->Next = Neu->Prev = NULL;
      First = Last = Neu;
      return 1;
   }

   if (First->Index >= Neu->Index)
   {  // Fall 2: vor dem ersten Element einfuegen
      Neu->Next = First;
      Neu->Prev = NULL;
      First = First->Prev = Neu;
      return 1;
   }

   if (Last->Index <= Neu->Index)
   {  // Fall 3: nach dem letzten Element einfuegen
      Neu->Prev = Last;
      Neu->Next = NULL;
      Last = Last->Next = Neu;
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
TData *removeFromList(int delIndex)
{
   TTeam *tmp = NULL, *prev = NULL;

   // Fall 1: Liste leer?
   if (First == NULL)
      return NULL;

   // Fall 2: Listenanfang entfernen?
   if (First->Index == delIndex)
   {
      tmp = First;
      First = First->Next;
      // nur ein Element in Liste?
      if (First == NULL)
         Last = NULL;
      else
         First->Prev = NULL;
      return tmp;
   }

   // Fall 3: Listenende entfernen?
   if (Last->Index == delIndex)
   {
      tmp = Last;
      Last = Last->Prev;
      Last->Next = NULL;
      return tmp;
   }

   // Fall 4: zu entfernendes Element suchen
   tmp = First->Next;
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

typedef enum {forward, backward} TDirection;

/**********************************************************
 * printList
 * Gibt Index und Wert der doppelt verketteten Liste in
 * der gew&uuml;nschten Richtung auf dem Bildschirm aus.
 * Parameter: TDirection: gibt die Ausgaberichtung an
 *               - forward: vorwaerts
 *               - backward: rueckwaerts
 * Rueckgabe: -
 **********************************************************/
void printList(TDirection Direction)
{
   TTeam *tmp = (Direction == forward) ? First : Last;
   int AnzahlElemente = 0;

   printf("\nIndex ");
   while (tmp)
   {
      printf("| %3i ", tmp->Index);
      tmp = (Direction == forward) ? tmp->Next : tmp->Prev;
      AnzahlElemente++;
   }

   printf("\n------");
   while (AnzahlElemente--)
      printf("------");

   printf("\nWert  ");
   tmp = (Direction == forward) ? First : Last;
   while (tmp != NULL)
   {
      printf("| %3.0f ", tmp->Value);
      tmp = (Direction == forward) ? tmp->Next : tmp->Prev;
   }
   printf("\n");
}

