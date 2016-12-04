// battleships
#include<stdio.h>
#include<time.h>

typedef struct
{
	int x,y,s,z,h;
}ship;
ship s[5];


char a[10][10];
char b[10][10];
int c[5][2];

void display();
void init();
int hit_miss(int,int);
void ifsink(int,int);
void gridb();
int input();
int win();

void randomship()
{	srand(time(NULL));	
	int i,j,flag=0;	
	//ship with two blocks 
	s[0].x=rand()%9;
	s[0].y=rand()%9;
	s[0].s=2;	
	s[0].z=rand()%2;
	if(s[0].z==0)
	{	b[s[0].x][s[0].y]='X';
		b[s[0].x][(s[0].y+1)]='X';
	}
	else
	{	b[s[0].x][s[0].y]='X';
		b[(s[0].x)+1][s[0].y]='X';
	}
	//ship with three blocks
	
	s[1].s=3;s[2].s=3;	
	for(j=0;j<2;j++)
	{
		while(1)
		{	flag=0;	
			s[j+1].z=rand()%2;	
			s[j+1].x=rand()%8;
			s[j+1].y=rand()%8;
			if(s[j+1].z==0)
			{	for(i=0;i<3;i++)
				{	if(b[s[j+1].x][(s[j+1].y)+i]!='X')
					{}
					else flag=1;	
				}
				if(flag==0)
				{	for(i=0;i<3;i++)
					{	b[s[j+1].x][(s[j+1].y)+i]='X';
						
					}
					break;	
				}			
			}
			if(s[j+1].z==1)
			{	for(i=0;i<3;i++)
				{	if(b[(s[j+1].x)+i][s[j+1].y]!='X')
					{}
					else flag=1;	
				}
				if(flag==0)
				{	for(i=0;i<3;i++)
					{	b[(s[j+1].x)+i][s[j+1].y]='X';
						
					}
					break;	
				}			
			}
	
		}
	}
	//ship with four blocks
	s[3].s=4;	
		while(1)
		{	flag=0;	
			s[3].z=rand()%2;	
			s[3].x=rand()%7;
			s[3].y=rand()%7;
			if(s[3].z==0)
			{	for(i=0;i<4;i++)
				{	if(b[s[3].x][(s[3].y)+i]!='X')
					{}
					else flag=1;	
				}
				if(flag==0)
				{	for(i=0;i<4;i++)
					{	b[s[3].x][(s[3].y)+i]='X';
						
					}
					break;	
				}			
			}
			if(s[3].z==1)
			{	for(i=0;i<4;i++)
				{	if(b[(s[3].x)+i][s[3].y]!='X')
					{}
					else flag=1;	
				}
				if(flag==0)
				{	for(i=0;i<4;i++)
					{	b[(s[3].x)+i][s[3].y]='X';
						
					}
					break;	
				}			
			}
	
		}
		//ship with five blocks

		s[4].s=5;	
		while(1)
		{	flag=0;	
			s[4].z=rand()%2;	
			s[4].x=rand()%6;
			s[4].y=rand()%6;
			if(s[4].z==0)
			{	for(i=0;i<5;i++)
				{	if(b[s[4].x][(s[4].y)+i]!='X')
					{}
					else flag=1;	
				}
				if(flag==0)
				{	for(i=0;i<5;i++)
					{	b[s[4].x][(s[4].y)+i]='X';
						
					}
					break;	
				}			
			}
			if(s[4].z==1)
			{	for(i=0;i<5;i++)
				{	if(b[(s[4].x)+i][s[4].y]!='X')
					{}
					else flag=1;	
				}
				if(flag==0)
				{	for(i=0;i<5;i++)
					{	b[(s[4].x)+i][s[4].y]='X';
						
					}
					break;	
				}			
			}
	
		}	
}

main()
{
	int k,d=0;
	randomship();
	init();
	gridb();
	do
	{
		display();
		printf("\n Turns: %d",d);
		printf("\n Enter Missile Coordinates(0A): ");
		k=input();
		if(k==1)
		{
			d++;
		}
		else
		{
			printf("\n Invalid Input\n");
		}
	}while(!win() && d<=99);
	system("clear");
	display();
	printf("\n Turns: %d",d);
	printf("\n You Win Nigger!!!");
	printf("\n GaMe OvEr\n");
}

void display()
{
	system("clear");
	int i,j;
	char x='A';
	printf("    ");
	for(i=0; i<10; ++i)
	{
		printf("  %c  ",x+i);
	}
	for(i=0; i<10; ++i)
	{
		printf("\n %d |",i);
		for(j=0; j<10; ++j)
		{
			printf("| %c |",a[i][j]);
		}
		printf("|");
	}
	
	printf("\n\n The Ships remaining are: ");
	for(i=0; i<5; ++i)
	{
		if(!s[i].h)
		{		
			printf("%d -/ ",s[i].s,s[i].h);
		}
	}
}

void init()
{
	int i,j;
	for(i=0; i<10; ++i)
	{
		for(j=0; j<10; ++j)
		{
			a[i][j]=' ';
			b[i][j]=' ';
		}
	}
}

int hit_miss(int x, int y)
{
	if(a[x][y]==' ')
	{
		if(b[x][y]=='X')
		{
			a[x][y]='X';// 5F TO 59, 2G TO 2J, 7J TO 9J, 5C TO 5D, 1A TO 1C
		}
		else
		{
			a[x][y]='O';
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

void gridb()
{
	int i,j,k;
	for(i=0; i<5; ++i)
	{
		k=0;
		while(k<s[i].s)
		{
			if(s[i].z==0)
			{
				b[s[i].x][s[i].y+k]='X';
				k++;
			}
			else
			{
				b[s[i].x+k][s[i].y]='X';
				k++;
			}
		}
	}
	printf("    ");
	for(i=0; i<10; ++i)
	{
		printf("  %c  ",65+i);
	}
	for(i=0; i<10; ++i)
	{
		printf("\n %d |",i);
		for(j=0; j<10; ++j)
		{
			printf("| %c |",b[i][j]);
		}
		printf("|");
	}
	printf("\n");
	
}

void ifsink(int x, int y)
{
	int i, j, k;
	for(i=0; i<5; ++i)
	{
		
		k=0;
		if(s[i].z==0)
		{
			
			for(j=s[i].y; j<(s[i].y+s[i].s); ++j)
			{
				
				if(a[s[i].x][j]!='X')
				{
					k=1;
					break;
				}
			}
		}
		else
		{
		
			for(j=s[i].x; j<(s[i].x+s[i].s); ++j)
			{
				
				if(a[j][s[i].y]!='X')
				{
					k=1;
					break;
				}
			}
		}
		if(k==0)
		{
			s[i].h=1;
		}

	}
}				
	
int input()
{
	int x,y,k;
	char z;
	scanf("%d %c",&x,&z);
	y=z-65;
	if((x>=0 && x<=9) && (y>=0 && y<=9))
	{
		k=hit_miss(x,y);	
		ifsink(x,y);
		return k;
	}
	else
	{
		return 0;
	}
}
	
int win()
{
	int i,flag=0;
	for(i=0; i<5; ++i)
	{
		if(s[i].h==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
				
