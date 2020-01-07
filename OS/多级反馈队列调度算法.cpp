#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node                             /*���̽ڵ���Ϣ*/
{
	char		name[20];               /*���̵�����*/
	int		prio;                   /*���̵����ȼ�*/
	int		round;                  /*����CPU��ʱ��Ƭ*/
	int		cputime;                /*CPUִ��ʱ��*/
	int		needtime;               /*����ִ������Ҫ��ʱ��*/
	char		state;                  /*���̵�״̬��W��������̬��R����ִ��̬��F�������̬*/
	int		count;                  /*��¼ִ�еĴ���*/
	struct node	*next;                  /*����ָ��*/
}PCB;
typedef struct Queue                            /*�༶�������нڵ���Ϣ*/
{
	PCB		*LinkPCB;               /*���������еĽ��̶���ָ��*/
	int		prio;                   /*���������е����ȼ�*/
	int		round;                  /*�����������������ʱ��Ƭ*/
	struct Queue	*next;                  /*ָ����һ���������е�����ָ��*/
}ReadyQueue;
PCB		*run	= NULL, *finish = NULL; /*�����������У��������У�ִ�ж��к���ɶ���*/
ReadyQueue	*Head	= NULL;                 /*�����һ����������*/
int		num;                            /*���̸���*/
int		ReadyNum;                       /*�������и���*/
void Output();                                  /*������Ϣ�������*/


void InsertFinish( PCB *in );                   /*�����̲��뵽��ɶ���β��*/


void InsertPrio( ReadyQueue *in );              /*�����������У��涨������ԽС�����ȼ�Խ��*/


void PrioCreate();                              /*���������������뺯��*/


void GetFirst( ReadyQueue *queue );             /*ȡ��ĳһ�����������еĶ�ͷ����*/


void InsertLast( PCB *in, ReadyQueue *queue );  /*�����̲��뵽��������β��*/


void ProcessCreate();                           /*���̴�������*/


void RoundRun( ReadyQueue *timechip );          /*ʱ��Ƭ��ת�����㷨*/


void MultiDispatch();                           /*�༶�����㷨��ÿ��ִ��һ��ʱ��Ƭ*/


int main( void )
{
	PrioCreate();                           /*������������*/
	ProcessCreate();                        /*�����������̶���*/
	MultiDispatch();                        /*�㷨��ʼ*/
	Output();                               /*������յĵ�������*/
	return(0);
}


void Output()                                   /*������Ϣ�������*/
{
	ReadyQueue	*print = Head;
	PCB		*p;
	printf( "������\t���ȼ�\t����\tcpuʱ��\t��Ҫʱ��\t����״̬\t������\n" );
	while ( print )
	{
		if ( print->LinkPCB != NULL )
		{
			p = print->LinkPCB;
			while ( p )
			{
				printf( "%s\t%d\t%d\t%d\t%d\t\t%c\t\t%d\n", p->name, p->prio, p->round, p->cputime, p->needtime, p->state, p->count );
				p = p->next;
			}
		}
		print = print->next;
	}
	p = finish;
	while ( p != NULL )
	{
		printf( "%s\t%d\t%d\t%d\t%d\t\t%c\t\t%d\n", p->name, p->prio, p->round, p->cputime, p->needtime, p->state, p->count );
		p = p->next;
	}
	p = run;
	while ( p != NULL )
	{
		printf( "%s\t%d\t%d\t%d\t%d\t\t%c\t\t%d\n", p->name, p->prio, p->round, p->cputime, p->needtime, p->state, p->count );
		p = p->next;
	}
}


void InsertFinish( PCB *in ) /*�����̲��뵽��ɶ���β��*/
{
	PCB *fst;
	fst = finish;
	if ( finish == NULL )
	{
		in->next	= finish;
		finish		= in;
	}else  {
		while ( fst->next != NULL )
		{
			fst = fst->next;
		}
		in->next	= fst->next;
		fst->next	= in;
	}
}


void InsertPrio( ReadyQueue *in )                       /*�����������У��涨������ԽС�����ȼ�Խ��*/
{
	ReadyQueue *fst, *nxt;
	fst = nxt = Head;
	if ( Head == NULL )                             /*���û�ж��У���Ϊ��һ��Ԫ��*/
	{
		in->next	= Head;
		Head		= in;
	}else  { /*�鵽���ʵ�λ�ý��в���*/
		if ( in->prio >= fst->prio )            /*�ȵ�һ����Ҫ������뵽��ͷ*/
		{
			in->next	= Head;
			Head		= in;
		}else  {
			while ( fst->next != NULL )     /*�ƶ�ָ����ҵ�һ������С��Ԫ�ص�λ�ý��в���*/
			{
				nxt	= fst;
				fst	= fst->next;
			}
			if ( fst->next == NULL )        /*�Ѿ���������β���������ȼ�����С��������뵽��β����*/
			{
				in->next	= fst->next;
				fst->next	= in;
			}else  { /*���뵽������*/
				nxt		= in;
				in->next	= fst;
			}
		}
	}
}


void PrioCreate() /*���������������뺯��*/
{
	ReadyQueue	*tmp;
	int		i;
	printf( "����������еĸ�����\n" );
	scanf( "%d", &ReadyNum );
	printf( "����ÿ���������е�CPUʱ��Ƭ��\n" );
	for ( i = 0; i < ReadyNum; i++ )
	{
		if ( (tmp = (ReadyQueue *) malloc( sizeof(ReadyQueue) ) ) == NULL )
		{
			perror( "malloc" );
			exit( 1 );
		}
		scanf( "%d", &(tmp->round) );           /*����˾��������и�ÿ�������������CPUʱ��Ƭ*/
		tmp->prio	= 50 - tmp->round;      /*���������ȼ���ʱ��ƬԽ�ߣ������ȼ�Խ��*/
		tmp->LinkPCB	= NULL;                 /*��ʼ�������ӵĽ��̶���Ϊ��*/
		tmp->next	= NULL;
		InsertPrio( tmp );                      /*�������ȼ��Ӹߵ��ͣ����������������*/
	}
}


void GetFirst( ReadyQueue *queue )                      /*ȡ��ĳһ�����������еĶ�ͷ����*/
{
	run = queue->LinkPCB;
	if ( queue->LinkPCB != NULL )
	{
		run->state	= 'R';
		queue->LinkPCB	= queue->LinkPCB->next;
		run->next	= NULL;
	}
}


void InsertLast( PCB *in, ReadyQueue *queue ) /*�����̲��뵽��������β��*/
{
	PCB *fst;
	fst = queue->LinkPCB;
	if ( queue->LinkPCB == NULL )
	{
		in->next	= queue->LinkPCB;
		queue->LinkPCB	= in;
	}else  {
		while ( fst->next != NULL )
		{
			fst = fst->next;
		}
		in->next	= fst->next;
		fst->next	= in;
	}
}


void ProcessCreate() /*���̴�������*/
{
	PCB	*tmp;
	int	i;
	printf( "������̵ĸ�����\n" );
	scanf( "%d", &num );
	printf( "����������ֺͽ�������ʱ�䣺\n" );
	for ( i = 0; i < num; i++ )
	{
		if ( (tmp = (PCB *) malloc( sizeof(PCB) ) ) == NULL )
		{
			perror( "malloc" );
			exit( 1 );
		}
		scanf( "%s", tmp->name );
		getchar();                              /*���ջس�����*/
		scanf( "%d", &(tmp->needtime) );
		tmp->cputime	= 0;
		tmp->state	= 'W';
		tmp->prio	= 50 - tmp->needtime;   /*���������ȼ�����Ҫ��ʱ��Խ�࣬���ȼ�Խ��*/
		tmp->round	= Head->round;
		tmp->count	= 0;
		InsertLast( tmp, Head );                /*�������ȼ��Ӹߵ��ͣ����뵽��������*/
	}
}


void RoundRun( ReadyQueue *timechip )                   /*ʱ��Ƭ��ת�����㷨*/
{
	int flag = 1;
	GetFirst( timechip );
	while ( run != NULL )
	{
		while ( flag )
		{
			run->count++;
			run->cputime++;
			run->needtime--;
			if ( run->needtime == 0 )                       /*����ִ�����*/
			{
				run->state = 'F';
				InsertFinish( run );
				flag = 0;
			}else if ( run->count == timechip->round )      /*ʱ��Ƭ����*/
			{
				run->state	= 'W';
				run->count	= 0;                    /*���������㣬Ϊ�´���׼��*/
				InsertLast( run, timechip );
				flag = 0;
			}
		}
		flag = 1;
		GetFirst( timechip );
	}
}


void MultiDispatch() /*�༶�����㷨��ÿ��ִ��һ��ʱ��Ƭ*/
{
	int		flag	= 1;
	int		k	= 0;
	ReadyQueue	*point;
	point = Head;
	GetFirst( point );
	while ( run != NULL )
	{
		Output();
		if ( Head->LinkPCB != NULL )
			point = Head;
		while ( flag )
		{
			run->count++;
			run->cputime++;
			run->needtime--;
			if ( run->needtime == 0 )                               /*����ִ�����*/
			{
				run->state = 'F';
				InsertFinish( run );
				flag = 0;
			}else if ( run->count == run->round )                   /*ʱ��Ƭ����*/
			{
				run->state	= 'W';
				run->count	= 0;                            /*���������㣬Ϊ�´���׼��*/
				if ( point->next != NULL )
				{
					run->round = point->next->round;        /*������ʱ��Ƭ����һ���������е�ʱ��Ƭ*/
					InsertLast( run, point->next );         /*�����̲��뵽��һ������������*/
					flag = 0;
				}else  {
					RoundRun( point );                      /*���Ϊ���һ���������о͵���ʱ��Ƭ��ת�㷨*/
					break;
				}
			}
			++k;
			if ( k == 3 )
			{
				ProcessCreate();
			}
		}
		flag = 1;
		if ( point->LinkPCB == NULL ) /*��������ָ������*/
			point = point->next;
		if ( point->next == NULL )
		{
			RoundRun( point );
			break;
		}
		GetFirst( point );
	}
}
