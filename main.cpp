#include "FoldingNet.h"
#include "../glut/glut.h"

void main(int argc, char *argv[])
{

	FoldingNet foldingPaper;
	
	foldingPaper.LoadParameters();

	//��ȡtxt�ļ�
	foldingPaper.ReadLinesFromTxt();

	//��ƽ��
	foldingPaper.FindPolygonByFloodFill();

	//modeling
	foldingPaper.Folding();

	system("pause");

}


