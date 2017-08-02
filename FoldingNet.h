#pragma once
#include <stack>
#include "Plane.h"
#include "opencv.hpp"
#include "../glut/glut.h"
#include"Modeling.h"



using namespace std;


class FoldingNet
{
public:
	FoldingNet();
	~FoldingNet();

	void LoadParameters();
	void ReadLinesFromTxt();
	//�и��߶�
	void CutOffLines();

	//�Ҷ�ͼת����α��ɫͼ��
	cv::Mat GrayToRGB(cv::Mat img);
	cv::Mat GrayToRainbow(cv::Mat img);
	//OpenGl��ʾ
	static void Show2DPattern();
	static FoldingNet * pThis;   //��̬����ָ��

	//�߶����ػ�����ƽ��
	void BresenhamRasterization(LineSegment lineSeg, int number);  //Bresenham�������߶����ػ�
	void FloodFill4Stack(int x, int y, int planenumber);
	void FindPolygonByFloodFill();  //floodfill�����Ҷ����

	//3D modeling
	void Folding();

	//opencv �Ļ���
	static void MouseClick(int event, int x, int y, int flags, void* param);
	static void myShowImageScroll(char* title, IplImage* src_img, int winWidth, int winHeight);

	static double mx , my ;
	static int dx , dy , horizBar_x , vertiBar_y ;
	static bool clickVertiBar , clickHorizBar , needScroll ;
	static CvRect rect_bar_horiz, rect_bar_verti;
	static int src_x , src_y ; // Դͼ���� rect_src �����Ͻ�λ��


private:
	vector<LineSegment> _LineList;
	vector<Plane> _PolygonList;

	//�������飬һ�����߶ε���ţ�����flood����ε����
	//�����СΪ�߶������ȡֵ��Χ
	int _RangeofPX;
	int _RangeofPY;
	int _MinPX;
	int _MinPY;

	cv::Mat _LineLabel;    //������Ѱ�ұ߽�
	cv::Mat _PolygonLabel; //���������ͼ��


	stack<Point> _MyStack;

	//for openmesh
	MyMesh _SM;
	MyMesh _TM;
	vector<MyMesh::VertexHandle> _VHandle;

};

