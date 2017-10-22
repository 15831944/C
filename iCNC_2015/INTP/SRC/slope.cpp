#include "stdafx.h"
#include "..\INC\INTP.h"
#include "..\..\CNC\INC\CNC.h"

void slopeMain(INTP_DATA *intpDataPtr)
{
	//���iLONG��steadyStep�O�_�p��0(�O�_SHORT)
	if(intpDataPtr->slopeData.state == SLOPE_LONG)
	{

	//�p��X��樫�h�ֶZ��
	intpDataPtr->slopeData.vStep = intpDataPtr->slopeData.acceleration *intpDataPtr->slopeData.cyclingTime;
	intpDataPtr->slopeData.stepDist = intpDataPtr->slopeData.vStep*intpDataPtr->slopeData.cyclingTime*(0.001);
	
    //�[�t����ƩM�Z��
	intpDataPtr->slopeData.accStep = (int)(intpDataPtr->slopeData.steadyFeed / intpDataPtr->slopeData.vStep);
	intpDataPtr->slopeData.accDist = (0.5)*(1 + intpDataPtr->slopeData.accStep)*(intpDataPtr->slopeData.accStep)*(intpDataPtr->slopeData.stepDist);
	
	//��t=�[�t
	intpDataPtr->slopeData.diccStep = intpDataPtr->slopeData.accStep;
    intpDataPtr->slopeData.diccDist = intpDataPtr->slopeData.accDist;
	
	//�̰��t
	intpDataPtr->slopeData.steadyFeed = (intpDataPtr->slopeData.accStep)*(intpDataPtr->slopeData.vStep);
	
	//���t��ƩM�Z��
	intpDataPtr->slopeData.steadyStep =(int)((intpDataPtr->slopeData.pathLength-intpDataPtr->slopeData.accDist-intpDataPtr->slopeData.diccDist)/(intpDataPtr->slopeData.steadyFeed*intpDataPtr->slopeData.cyclingTime*0.001));
	intpDataPtr->slopeData.steadyDist = (intpDataPtr->slopeData.steadyStep)*(intpDataPtr->slopeData.accStep)*(intpDataPtr->slopeData.stepDist);
	
	//�ѤU�Z���M�t��
	intpDataPtr->slopeData.restLength = intpDataPtr->slopeData.pathLength-intpDataPtr->slopeData.accDist-intpDataPtr->slopeData.diccDist- intpDataPtr->slopeData.steadyDist;
	intpDataPtr->slopeData.restVelocity = intpDataPtr->slopeData.restLength/(intpDataPtr->slopeData.cyclingTime*(0.001));
	
	//�`�O��
	intpDataPtr->slopeData.totalCount = intpDataPtr->slopeData.accStep + intpDataPtr->slopeData.diccStep + intpDataPtr->slopeData.steadyStep;
	

	if(intpDataPtr->slopeData.restLength >0)
	{
		intpDataPtr->slopeData.restCheck = true;
	}

	if(intpDataPtr->slopeData.steadyStep <= 0)
	{
		double check;
		check = intpDataPtr->slopeData.pathLength-intpDataPtr->slopeData.accDist-intpDataPtr->slopeData.diccDist;
		if(check <0)
		{
		intpDataPtr->slopeData.state = SLOPE_SHORT;
		slopeShort(intpDataPtr);
		}
	}
	}

	else if (intpDataPtr->slopeData.state == SLOPE_SHORT)
	{
		slopeShort(intpDataPtr);
	}
	return ;
}

void slopeShort(INTP_DATA *intpDataPtr)
{
	
	int accStep = 0;
	double shortDist;

	bool pass=false;

	while(shortDist < intpDataPtr->slopeData.pathLength && pass==false)
	{
		//�Q�εu�Z���M�w�[�t���
		accStep++;
		shortDist = ((accStep)*(accStep-1)+accStep)*(intpDataPtr->slopeData.stepDist);
		
		//����j��һ�
		if(shortDist > (intpDataPtr->slopeData.pathLength))
		{
			//���T���[�t���
			accStep--;
			intpDataPtr->slopeData.accStep = accStep;

			//restLength restVelocity totalCount�w�q
			shortDist = ((accStep)*(accStep-1)+accStep)*(intpDataPtr->slopeData.stepDist);
			intpDataPtr->slopeData.restLength = intpDataPtr->slopeData.pathLength - shortDist;
			intpDataPtr->slopeData.restVelocity = (intpDataPtr->slopeData.restLength)/(intpDataPtr->slopeData.cyclingTime*0.001);
			intpDataPtr->slopeData.totalCount = (accStep-1)*2-1;
			
			intpDataPtr->slopeData.restCheck = true;
			pass = true;
		}
		else if(shortDist == intpDataPtr->slopeData.pathLength)
		{
			//restLength restVelocity totalCount�w�q
			intpDataPtr->slopeData.accStep = accStep;
			intpDataPtr->slopeData.restVelocity = 0;
			intpDataPtr->slopeData.totalCount = accStep*2-1;
			
			intpDataPtr->slopeData.restCheck = false;
			pass = true;
		}

	}

	return ;
}