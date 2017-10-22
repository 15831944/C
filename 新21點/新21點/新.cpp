#include"�s.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<time.h>

FILE *filePtr;
int main(void)
{
	
	
	begin =true;
	state = INIT;
	while(begin == true)
	{
		switch(state)
		{
		case INIT:
			init();
			break;
		case RULE:
			rule();
			break;
		case PRE:
			pre();
			break;
		case EXE:
			exe();
			break;
		case PLAYER_CARD1:
			player_card1();
			break;
		case PLAYER_CARD2:
			player_card2();
			break;
		case PLAYER_CARD3:
			player_card3();
			break;
		case PLAYER_CARD4:
			player_card4();
			break;
		case PLAYER_CARD5:
			player_card5();
			break;
		case COMPUTER_CARD1:
			computer_card1();
			break;
		case COMPUTER_CARD2:
			computer_card2();
			break;
		case COMPUTER_CARD3:
			computer_card3();
			break;
		case COMPUTER_CARD4:
			computer_card4();
			break;
		case COMPUTER_CARD5:
			computer_card5();
			break;
		case GG:
			gg();
			break;
		case WIN:
			win();
			break;
		case TIE:
			tie();
			break;
		case END:
			end();
			break;
		}
	}
	return 0;
}
int init(void)
{
	int a;
	money =4000;
	char highpt[20];
	highestpoint =0;
	filePtr = fopen("..\\highestpoint.txt","r");
	fgets( highpt , 20 ,filePtr );
	fclose(filePtr);
	highestpoint = atoi(highpt);
	printf("21�I,�C���}�l!!\n");
	printf("���e�̰�����:%lf\n\n",highestpoint);
	printf("�������}�l�Ы�0,�����W�h�Ы�1,�������Ы�2\n");
	scanf("%d",&a);
	if(a==0)
	{
		state = PRE;
	}
	else if (a==1)
	{
		state  = RULE;
	}
	else if(a==2)
	{
		begin = false;
	}
	else
	{
		state = INIT;
	}

	return 0;
}
int rule(void)
{
	printf("�A�N�|���t��4000�����w�X\n");
	printf("�C�@�����a���n�U��`\n");
	printf("����,�q���|�O���a,�Ӫ��a�����a\n");
	printf("���^�X,�|�������a��i�P,�i�̵P���`�M�M�w��Τ���\n");
	printf("�̰��I��21�I\n");
	printf("���a�M�w�����\n");
	printf("�q���|���ۨ��P\n");
	printf("�Y�q���]�S�z�I,�h�|��j�p\n\n");
	state = INIT;
	return 0;
	
}
int pre(void)
{
	int a;
	re_money=0;
	player_point =0;
	computer_point =0;
	printf("�{�b���B:%d\n",money);
	printf("�ФU�`,�̤p5���̤j100��\n");
	scanf("%d",&bet);
	money-=bet;
	re_money+=bet;
	state = PLAYER_CARD1;
	return 0;
}
int exe(void)
{
	return 0;
}
int card(void)
{   A=0;
	srand(time(NULL));
	A = 1+rand()%52;
	
	return A;
}
int pattern(void)
{
	int a=0;
	if(A<=13)
	{
		printf("�®�");
		a=A;
		if(a==1)
		{
			printf("A\n");
		}
		else if(a==11)
		{
			printf("J\n");
		}
		else if (a==12)
		{
			printf("Q\n");
		}
		else if(a==13)
		{
			printf("K\n");
		}
		else
		{
		printf("%d\n",a);
		}
	}
	else if (A>13&&A<=26)
	{
		printf("�R��");
		a=A-13;
		if(a==1)
		{
			printf("A\n");
		}
		else if(a==11)
		{
			printf("J\n");
		}
		else if (a==12)
		{
			printf("Q\n");
		}
		else if(a==13)
		{
			printf("K\n");
		}
		else
		{
		printf("%d\n",a);
		}
	}
	else if (A>26&&A<=39)
	{
		printf("���");
		a=A-26;
		if(a==1)
		{
			printf("A\n");
		}
		else if(a==11)
		{
			printf("J\n");
		}
		else if (a==12)
		{
			printf("Q\n");
		}
		else if(a==13)
		{
			printf("K\n");
		}
		else
		{
		printf("%d\n",a);
		}
	}
	else if (A>39&&A<=52)
	{
		printf("����");
		a=A-39;
		if(a==1)
		{
			printf("A\n");
		}
		else if(a==11)
		{
			printf("J\n");
		}
		else if (a==12)
		{
			printf("Q\n");
		}
		else if(a==13)
		{
			printf("K\n");
		}
		else
		{
		printf("%d\n",a);
		}
	}
	return 0;
}
int point(void)
{
	B=0;
	int b;
	if(A<=13)
	{
		b=A;
	if(b==1)
	{
		B=11;
	}
	else if(b==11)
	{
		B=10;
	}
	else if(b==12)
	{
		B=10;
	}
	else if(b==13)
	{
		B=10;
	}
	else 
	{
		B=b;
	}
	}
	else if(A<=26&&A>13)
	{
		b=A-13;
	if(b==1)
	{
		B=11;
	}
	else if(b==11)
	{
		B=10;
	}
	else if(b==12)
	{
		B=10;
	}
	else if(b==13)
	{
		B=10;
	}
	else 
	{
		B=b;
	}
	}
	else if(A<=39&&A>26)
	{
		b=A-26;
	if(b==1)
	{
		B=11;
	}
	else if(b==11)
	{
		B=10;
	}
	else if(b==12)
	{
		B=10;
	}
	else if(b==13)
	{
		B=10;
	}
	else 
	{
		B=b;
	}
	}
	else if(A<=52&&A>39)
	{
		b=A-39;
	if(b==1)
	{
		B=11;
	}
	else if(b==11)
	{
		B=10;
	}
	else if(b==12)
	{
		B=10;
	}
	else if(b==13)
	{
		B=10;
	}
	else 
	{
		B=b;
	}
	}
	return B;
}
int player_card1(void)
{
	printf("�Ĥ@�i�P\n");
	card1 =card();
	pattern();
	point1 = point();
	state =PLAYER_CARD2;
	return 0;
}
int player_card2(void)
{
	int a;
	card2 =card();
	while(card1 == card2)
	{
		card2 =card();
	}
	point2= point();
	printf("�ĤG�i�P\n");
	pattern();
	player_point = point1 +point2;
	if(player_point>21)
	{
		player_point-=10;
		printf("�ثe�̤j�I�Ƭ�%d\n",player_point);
		printf("��(�Ы�0)�Τ���(�Ы�1)?\n");
	    scanf("%d",&a);
	if (a==0)
	{
		player_point+=10;
		state = PLAYER_CARD3;
	}
	else if(a==1)
	{
		state = COMPUTER_CARD1;
	}
	}
	else
	{
	printf("�ثe�̤j�I�Ƭ�%d\n",player_point);
	printf("��(�Ы�0)�Τ���(�Ы�1)?\n");
	scanf("%d",&a);
	if (a==0)
	{
		
		state =  PLAYER_CARD3;
	}
	else if(a==1)
	{
		state = COMPUTER_CARD1;
	}


	}
	return 0;
}
int player_card3(void)
{
	int a=0;
	int temp;
	card3 =card();
	while(card1 == card3||card2==card3)
	{
		card3 =card();
	}
	point3=point();
	printf("�ĤT�i�P\n");
	pattern();
	player_point +=point3;
	if(player_point>21)
	{
		if(point1==11||point2==11||point3==11)
		{
			temp =player_point;
			int special=0;
			
			if(point1==11)
			{
				special++;
			}
			else if(point2==11)
			{
				special++;
			}
			else if(point3==11)
			{
				special++;
			}
			for (int i=1;i<special+1;i++)
			{
				while(player_point>21)
				{
				player_point-=10;
				}
			}
			if(player_point>21)
			{
			state = GG;
			}
			else if(player_point<21)
			{
			printf("�{�b�̤j�I�Ƭ�%d\n",player_point);
			printf("��(�Ы�0)�Τ���(�Ы�1)?\n");
	        scanf("%d",&a);
             	if (a==0)
	           {
				   player_point=temp;
	             	state =  PLAYER_CARD4;
             	}
                 	else if(a==1)
	            {
	              	state = COMPUTER_CARD1;
	            }


	         }
		}
	
	    else
	    {
		printf("�{�b�̤j�I�Ƭ�%d\n",player_point);
		state =GG;
	    }
	}
	else //  1
	{
		printf("�{�b�̤j�I�Ƭ�%d\n",player_point);
		printf("��(�Ы�0)�Τ���(�Ы�1)?\n");
	       scanf("%d",&a);
             	if (a==0)
	           {
		
	             	state =  PLAYER_CARD4;
             	}
                 	else if(a==1)
	            {
	              	state = COMPUTER_CARD1;
	            }
	}
	return 0;
}
int player_card4(void)
{
	int a;
	int temp;
	card4=card();
	while(card1 == card4||card2==card4||card3==card4)
	{
		card4=card();
	}
	point4 =point();
	printf("�ĥ|�i�P\n");
	pattern();
	player_point +=point4;
	if(player_point>21)
	{
		if(point1==11||point2==11||point3==11||point4==11)
		{
			temp=player_point;
			int special=0;
			
			if(point1==11)
			{
				special++;
			}
			else if(point2==11)
			{
				special++;
			}
			else if(point3==11)
			{
				special++;
			}
			else if(point4==11)
			{
				special++;
			}
			for (int i=1;i<special+1;i++)
			{
				while(player_point>21)
				{
				player_point-=10;
				}
			}
			if(player_point>21)
			{
			state = GG;
			}
			else if(player_point<21)
			{
			printf("�{�b�̤j�I�Ƭ�%d\n",player_point);
			printf("��(�Ы�0)�Τ���(�Ы�1)?\n");
	        scanf("%d",&a);
             	if (a==0)
	           {
		           player_point = temp;
	             	state =  PLAYER_CARD5;
             	}
                 	else if(a==1)
	            {
	              	state = COMPUTER_CARD1;
	            }
			}
		}
		else
		{
			printf("�{�b�̤j�I�Ƭ�%d\n",player_point);
			state =GG;
		}
		
	}
	else  //��Ĥ��i�P
	{
	printf("�ثe�̰��I�Ƭ�%d\n",player_point);
	printf("��(�Ы�0)�Τ���(�Ы�1)?\n");
	scanf("%d",&a);
	if (a==0)
	{
	  state =  PLAYER_CARD5;
    }
    else if(a==1)
    {
	  state = COMPUTER_CARD1;
	}
	}
	return 0;
}
int player_card5(void)
{
	int a;
	int temp;
	card5 = card();
	while(card1 == card5||card2==card5||card3==card5||card4==card5)
	{
		card5=card();
	}
	point5 =point();
	printf("�Ĥ��i�P\n");
	pattern();
	player_point +=point5;
	if(player_point>21)
	{
		if(point1==11||point2==11||point3==11||point4==11||point5==11)
		{
			temp = player_point;
			int special=0;
			
			if(point1==11)
			{
				special++;
			}
			else if(point2==11)
			{
				special++;
			}
			else if(point3==11)
			{
				special++;
			}
			else if(point4==11)
			{
				special++;
			}
			else if(point5==11)
			{
				special++;
			}
			for (int i=1;i<special+1;i++)
			{
				while(player_point>21)
				{
				player_point-=10;
				}
			}
			if(player_point>21)
			{
			state = GG;
			}
			else
			{
			  state = WIN;
			}
			
	    }
		else
		{
			printf("�{�b�̤j�I�Ƭ�%d\n",player_point);
			state =GG;
		}
	}
	else
	{
		state = WIN;
	}
	
	
	return 0;
}
int computer_card1(void)
{
	printf("�q����P�}�l\n");
	printf("�Ĥ@�i�P\n");
	card1 =card();
	pattern();
	point1 = point();
	state =COMPUTER_CARD2;
	return 0;
}
int computer_card2(void)
{
	int a;
	card2 =card();
	while(card1 == card2)
	{
		card2 =card();
	}
	point2= point();
	printf("�ĤG�i�P\n");
	pattern();
	computer_point = point1 +point2;
	if(computer_point>21)
	{
		state = COMPUTER_CARD3;
	}
	else if(computer_point<=player_point)
	{
		state = COMPUTER_CARD3;
	}
	else if (computer_point>player_point)
	{
		state = GG;
	}
	else if (computer_point==21)
	{
		if(player_point ==21)
		{
			state =TIE;
		}
		else if (player_point<21)
		{
			state = GG;
		}
	}
	return 0;
}
int computer_card3(void)
{
	int a=0;
	int temp;
	card3 =card();
	while(card1 == card3||card2==card3)
	{
		card3 =card();
	}
	point3=point();
	printf("�ĤT�i�P\n");
	pattern();
	computer_point +=point3;
	if(computer_point==21)
	{
		if(player_point==21)
		{
			state =TIE;
		}
		else if (player_point<21)
		{
			state =GG;
		}
	}
	else if(computer_point>21)                  //////////////////////////////
	{
		if(point1==11||point2==11||point3==11)
		{
			temp =computer_point;
			int special=0;
			
			if(point1==11)
			{
				special++;
			}
			else if(point2==11)
			{
				special++;
			}
			else if(point3==11)
			{
				special++;
			}
			for (int i=1;i<special+1;i++)
			{
				while(computer_point>21)
				{
				computer_point-=10;
				}
			}
			if(computer_point>21)
			{
			state = WIN;
			}
			else if(computer_point<=21)
			{
			  if(computer_point>player_point)
			  {
				  state = GG;
			  }
			  else if (computer_point<=player_point)
			  {
				  computer_point = temp;
				  state = COMPUTER_CARD4;
			  }
			  else if (computer_point==21)                      ///////////////
			  {
				  if(player_point==21)
	            	{
	        		state =TIE;
	            	}
	           	  else if (player_point<21)
		            {
			        state =GG;
		            }
			  }
	        }
		}
	
	    else
	    {
		state =WIN;
	    }
	}
	else //  1
	{
		if(computer_point>player_point)
		{
			state = GG;
		}
		else if (computer_point<=player_point)
		{
			state = COMPUTER_CARD4;
		}
	}
	return 0;
}
int computer_card4(void)
{   int a=0;
	int temp;
	card4 =card();
	while(card1 == card4||card2==card4||card3==card4)
	{
		card4 =card();
	}
	point4=point();
	printf("�ĥ|�i�P\n");
	pattern();
	computer_point +=point4;
	if(computer_point==21)
	{
		if(player_point==21)
		{
			state =TIE;
		}
		else if (player_point<21)
		{
			state =GG;
		}
	}
	else if(computer_point>21)                  //////////////////////////////
	{
		if(point1==11||point2==11||point3==11||point4==11)
		{
			temp =computer_point;
			int special=0;
			
			if(point1==11)
			{
				special++;
			}
			else if(point2==11)
			{
				special++;
			}
			else if(point3==11)
			{
				special++;
			}
			else if(point4==11)
			{
				special++;
			}
			for (int i=1;i<special+1;i++)
			{
				while(computer_point>21)
				{
				computer_point-=10;
				}
			}
			if(computer_point>21)
			{
			state = WIN;
			}
			else if(computer_point<=21)
			{
			  if(computer_point>player_point)
			  {
				  state = GG;
			  }
			  else if (computer_point<=player_point)
			  {
				  computer_point =temp;
				  state = COMPUTER_CARD5;
			  }
			   else if (computer_point==21)                      ///////////////
			  {
				  if(player_point==21)
	            	{
	        		state =TIE;
	            	}
	           	  else if (player_point<21)
		            {
			        state =GG;
		            }
			  }
	        }
		}
	
	    else
	    {
		state =WIN;
	    }
	}
	else //  1
	{
		if(computer_point>player_point)
		{
			state = GG;
		}
		else if (computer_point<=player_point)
		{
			state = COMPUTER_CARD5;
		}
	}
	return 0;
}
int computer_card5(void)
{
	int a=0;
	int temp;
	card5 =card();
	while(card1 == card5||card2==card5||card3==card5||card4==card5)
	{
		card5 =card();
	}
	point5=point();
	printf("�Ĥ��i�P\n");
	pattern();
	computer_point +=point5;

	if(computer_point==21)
	{
		if(player_point==21)
		{
			state =TIE;
		}
		else if (player_point<21)
		{
			state =GG;
		}
	}
	else if(computer_point>21)                  //////////////////////////////
	{
		if(point1==11||point2==11||point3==11||point4==11||point5==11)
		{
			temp =computer_point;
			int special=0;
			
			if(point1==11)
			{
				special++;
			}
			else if(point2==11)
			{
				special++;
			}
			else if(point3==11)
			{
				special++;
			}
			else if(point4==11)
			{
				special++;
			}
			else if(point5==11)
			{
				special++;
			}
			for (int i=1;i<special+1;i++)
			{
				while(computer_point>21)
				{
				computer_point-=10;
				}
			}
			if(computer_point>21)
			{
			state = WIN;
			}
			else if(computer_point<=21)
			{
			  if(computer_point>player_point)
			  {
				  state = GG;
			  }
			  else if (computer_point<player_point)
			  {
				  state = WIN;
			  }
			  else if (computer_point==player_point)
			  {
				  state =TIE;
			  }
	        }
		}
	
	    else
	    {
		state =WIN;
	    }
	}
	else //  1
	{
		if(computer_point>player_point)
		{
			state = GG;
		}
		else if (computer_point<player_point)
		{
			state =WIN ;
		}
		else if(computer_point==player_point)
		{
			state =TIE;
		}
	}
	return 0;
}
int gg(void)
{
	printf("�A��F\n");
	printf("����ٳ�%d\n",money);
	state = END;
	return 0;
}
int win(void)
{
	printf("�AĹ�F\n");
	money=money+2*re_money;
	printf("����ٳ�%d\n",money);
	state = END;
	return 0;
}
int tie(void)
{
	printf("����\n");
	money=money+re_money;
	printf("����ٳ�%d\n",money);
	state =END;
	return 0;
}
int end(void)
{
	int a;
	printf("���~��,�Ы�0,�����},�Ы�1\n");
	scanf("%d",&a);
	if(a==0)
	{
		state = PRE;
	}
	else if (a==1)
	{
		if(money>highestpoint)
		{
	highestpoint = money;
	filePtr  = fopen("..\\highestpoint.txt" , "w");
	fprintf(filePtr , "%lf" , highestpoint);
	fclose(filePtr);
		}
	begin = false;
	}
	return 0;
}