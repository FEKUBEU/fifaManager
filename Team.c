#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Team.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "datastruct.h"

extern int TeamCounter;     //Deklaration von globalen variabeln,
extern TTeam Teams[MAXTEAM];


//---------------------Funktionen-----------------------------------------//




void createTeam(void){

    clearScreen();
    printf("Erfassung einer neuen Mannschaft\n");
    printline('-',strlen("Erfassung einer neuen Mannschaft"));


    if(TeamCounter == MAXTEAM)
        return;

    TTeam *newTeam = &(Teams[TeamCounter]);

    newTeam=malloc(sizeof(TTeam));

    printf("Teamcounter: %i\n", TeamCounter);

    //printf("%i",newTeam->AnzPlayer);

    //Teamname
    do{} while( !getText("Teamname: ", 25, &(Teams[TeamCounter].Teamn), 0 ) );

    //printf("Teamnametest: %i\n", *(Teams+TeamCounter) );        // schmiert ab !!!!!
    //printf("Teamnametest: %i\n", Teams+TeamCounter);
    //printf("Teamnametest: %i\n", *newTeam );
    //printf("Teamnametest: %i\n", newTeam );
    //printf("%s", newTeam->Teamn);
    //printf("Teamname Test: %s\n", (Teams[1].Teamn));
    //printf("Teamname Test: %s\n", (Teams[TeamCounter].Teamn));
    //printf("Teamname Test: %s\n", *(Teams[TeamCounter].Teamn));     // schmiert ab

    //trainername
    do{} while( !getText("Trainername: ", 25, &(Teams[TeamCounter].Coach), 1 ) );

    //printf("Teamname Test: %s\n", (Teams[1].Coach));
    //printf("Teamname Test: %s\n", (Teams[TeamCounter].Coach));

    //anzahl spieler
    (Teams[TeamCounter]).AnzPlayer = 0;

    //TeamCounter++;

    printf("Bitte Eingaben mit Enter bestaetigen!\n");
    WaitForEnter();
    free(newTeam);
    do
    {
        TPlayer *newPlayer = (Teams[TeamCounter].Player);
        newPlayer = malloc(sizeof(TPlayer));

        if ( newPlayer == NULL )
        {
            printf("ERROR:SPEICHERRESERVIERUNG NEWPLAYER");
        }
        else
        {
            addPlayer();
            Teams[TeamCounter].AnzPlayer++;
            printf("Teamcounter: %i\n", TeamCounter);
            printf("Anzahl d. Spieler: %i\n", Teams[TeamCounter].AnzPlayer);
        }
        free(newPlayer);
    } while( askYesorNo("Wollen sie noch einen Spieler anlegen?") );
    TeamCounter++;
}

void deleteTeam(void)
{
    printf("deleteTeam\n");
}

void addPlayer(void)
{
    clearScreen();
    //MenuTitel
    printf("Erfassung eines neuen Spielers\n");
    printline('-',strlen("Erfassung eines neuen Spielers"));

    if(askYesorNo("Wollen sie einem bestehendem Team einen Spieler hinzufuegen"))
    {

        TMTitel ArrMTeams[TeamCounter];
        char MenuT[]={"Angelegte Teams"};
        int i;

        for(i=0;i<TeamCounter;i++)
        {
            strcpy(ArrMTeams[i].MTitel,(Teams+i)->Teamn);
        }

        int TC = ( getmenu(MenuT,ArrMTeams,TeamCounter) );

        ((Teams+TC)->AnzPlayer)++;
        int AnzPlayer = (Teams+TC)->AnzPlayer;

        //Spielername
        do{} while( !getText("Spielername: ",30, &( (((Teams+TC)->Player)+AnzPlayer)->Playern), 0 ) ) ;
        printf("%s\n",(((Teams+TC)->Player)+AnzPlayer)->Playern);
        //Birthday

        //Trikonummer

        //Goals


    }
    else
    {
        createTeam();
    }

}

void deletePlayer(void){

    printf("deletePlayer\n");

}

void searchPlayer(void){

    printf("searchPlayer\n");

}

void sortTeams(void){

    printf("sortTeams\n");

}

void listTeams(void)
{
    int i = 0;

    clearScreen();

    for(i=0; i<TeamCounter; i++)
    {
        listOneTeam(i);
    }
}

void listOneTeam(int TC)
{
    int j = 0;
    printf("------------------->Team: %i\n",TC+1);
    printf("Team: %s\n", (Teams+TC)->Teamn );

    if( ((Teams+TC)->Coach) )
        printf("Trainer: %s\n", (Teams+TC)->Coach);
    else
        printf("Trainer         :   \n");


    printf("Anzahl Spieler  : %i\n", (Teams+TC)->AnzPlayer);

    for(j=0; j<((Teams+TC)->AnzPlayer); j++)
    {
        listOnePlayer(j, TC);
    }
}

void listOnePlayer(int PC, int TC)
{
    printf("  ------------------->Player: %i\n",PC+1);

    //Spielername
    printf("  Spielername: %s\n",(((Teams+TC)->Player)+PC)->Playern);

    //Birthday
    /*printf("  Birthday: %i.%i.%i\n" ,((((Teams+TC)->Player)+PC)->Birthday)->Day
                                    ,((((Teams+TC)->Player)+PC)->Birthday)->Month
                                    ,((((Teams+TC)->Player)+PC)->Birthday)->Year  );
    */
    //Trikonummer
    //printf("  TrikotNr: %i\n",(((Teams+TC)->Player)+PC)->Trikotn );

    //Goals
    //printf("  Goals: %i\n",(((Teams+TC)->Player)+PC)->Goals);

}

void endprog(void){
    printf("Programmende\n");
}

