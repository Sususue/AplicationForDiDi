#ifndef  _FINDWAY_H_
#define  _FINDWAY_H_

#define MAXSIZE 10
#define INF 9999
#define NOWAY -1
#define DIRECTNUM 4
#define AREONUM 8 //道路分为八个区，四个横着，四个竖着

void Dijkstra(int start, int end, int way[], int *count);

void direction(int way[], int count, int direct[]);

void judgeAreo(PLACE node[MAXSIZE],int x, int y, PLACE *placeto, int *flag, int *nodenum);

void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag);

void StartAndEnd(PLACE node[MAXSIZE], PLACE place, int nearplace[2],int *placenum);

void linkCartoon(CAR_CONDITION *car_position,PLACE node[MAXSIZE], int way[MAXSIZE], int direct[MAXSIZE], int count, int *energe, int *x,int *y);

void find(int *x, int *y, int startx,int starty, int *energe);

int mousepress(int mx,int my);

#endif