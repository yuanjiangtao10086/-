#pragma once
#include<stdio.h>
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
const char chaozuo[5][10] = { "վ�㽨��","վ���޸�","��·����","��·�޸�","��ѯ" };
static clock_t lastClickTime = 0;
const int CLICK_DELAY = 1000; // 1000����ķ������


//������Ϣ�ṹ�����
ExMessage msg = { 0 };
/////////////////////////Ư���İ���+������Ϣ���������ң�
//mx,my�Ƿ���ָ���ľ�������
bool inArea(int mx, int my, int x, int y, int w, int h) {
	if (mx > x && mx<x + w && my>y && my < y + h) {
		return true;
	}
	return false;
}
bool button(int x, int y, int w, int h, const char* text) {
	setbkmode(TRANSPARENT);  // ���ñ���͸��

	// ���ư�ť��ɫ
	if (inArea(msg.x, msg.y, x, y, w, h)) {
		setfillcolor(RGB(195, 153, 137));  // ��ͣ״̬��ɫ
	}
	else {
		setfillcolor(RGB(250, 250, 250));  // ����״̬��ɫ
	}

	// ���ư�ťԲ�Ǿ���
	fillroundrect(x, y, x + w, y + h, 5, 5);

	// �����ı���ʽ��������������ʽ������ȷ�����ı��ߴ磩
	settextstyle(28, 0, "΢���ź�");
	settextcolor(BLACK);

	// �����ı��ߴ�
	int textWidth = textwidth(text);
	int textHeight = textheight(text);

	// �������λ��
	int centerX = x + (w - textWidth) / 2;
	int centerY = y + (h - textHeight) / 2;

	// ���ƾ��ж���İ�ť�ı�
	outtextxy(centerX, centerY, text);

	// �жϰ�ť�Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h)) {
		return true;
	}
	return false;
}
	//setbkmode(TRANSPARENT);//���ñ�����ɫ
	////���ư�ť��ɫ
	//if (inArea(msg.x, msg.y, x, y, w, h)) {
	//	setfillcolor(RGB(195, 153, 137));
	//}
	//else {
	//	setfillcolor(RGB(250, 250, 250));
	//}
	////���ư�ť
	//fillroundrect(x, y, x + w, y + h, 5, 5);
	////���ư�ť�ı�
	//int hspace = (w - textwidth(text)) / 2;
	//int vspace = (h - textheight(text)) / 2;
	//settextcolor(BLACK);
	//settextstyle(28, 0, "΢���ź�");
	//outtextxy(x + hspace, y + vspace, text);
	////�жϰ�ť�Ƿ񱻵��
	//if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h)) {
	//	return true;
	//}
	//return false;
bool buttonziti(int x, int y, int w, int h, const char* text, int daxiao) {
	setbkmode(TRANSPARENT);  // ���ñ���͸��

	// ���ư�ť��ɫ
	if (inArea(msg.x, msg.y, x, y, w, h)) {
		setfillcolor(RGB(195, 153, 137));  // ��ͣ״̬��ɫ
	}
	else {
		setfillcolor(RGB(250, 250, 250));  // ����״̬��ɫ
	}

	// ���ư�ťԲ�Ǿ���
	fillroundrect(x, y, x + w, y + h, 5, 5);

	// �����ı���ʽ��������������ʽ������ȷ�����ı��ߴ磩
	settextstyle(daxiao, 0, "΢���ź�");
	settextcolor(BLACK);

	// �����ı��ߴ�
	int textWidth = textwidth(text);
	int textHeight = textheight(text);

	// �������λ��
	int centerX = x + (w - textWidth) / 2;
	int centerY = y + (h - textHeight) / 2;

	// ���ƾ��ж���İ�ť�ı�
	outtextxy(centerX, centerY, text);

	// �жϰ�ť�Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h)) {
		return true;
	}
	return false;
}
//���־���
void printf0(int x, int y, int w, int h,const char* text,COLORREF color) {//��������
	setbkmode(TRANSPARENT);//���ñ�����ɫ
	settextcolor(color);
	settextstyle(38, 0, "΢���ź�");
	setfillcolor(WHITE);
	solidrectangle(x, y, x + w, y + h);
	int hspace = (w - textwidth(text)) / 2;
	int vspace = (h - textheight(text)) / 2;
	outtextxy(x + hspace, y + vspace, text);
}
void printf3(int x, int y, int w, int h,  char* text, COLORREF color) {//��������
	setbkmode(TRANSPARENT);//���ñ�����ɫ
	setfillcolor(WHITE);
	settextcolor(color);
	settextstyle(38, 0, "΢���ź�");
	solidrectangle(x, y, x + w, y + h);
	outtextxy(x, y, text);
}
void printf1(int x, int y, int w, int h, string s, int i) {
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	settextstyle(28, 0, "΢���ź�");
	settextcolor(BLACK);
	solidrectangle(x, y, x + w, y + h);
	int vspace = (h - textheight(s.c_str())) / 2;
	int hspace = (w - textwidth(s.c_str())) / 2;
	outtextxy(x+hspace , y + vspace, s.c_str());
}
void printf2(int x, int y, int w, int h, string s) {
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	settextcolor(BLACK);
	settextstyle(28, 0, "΢���ź�");
	solidrectangle(x, y, x + w, y + h);
	int vspace = (h - textheight(s.c_str())) / 2;
	int hspace = (w - textwidth(s.c_str())) / 2;
	
	outtextxy(x+hspace, y + vspace, s.c_str());
}
bool fanhui() {
	int x = 2, y = 2, w = 25, h = 25;
	setbkmode(TRANSPARENT);//���ñ�����ɫ
	settextstyle(15, 0, "΢���ź�");
	//���ư�ť��ɫ
	if (inArea(msg.x, msg.y, x, y, w, h)) {
		setfillcolor(RGB(195, 153, 137));
	}
	else {
		setfillcolor(RGB(250, 250, 250));
	}
	//���ư�ť
	fillcircle(15,15,15);
	//���ư�ť�ı�
	int hspace = (w - textwidth("����")) / 2;
	int vspace = (h - textheight("����")) / 2;
	settextcolor(BLACK);
	outtextxy(x + hspace, y + vspace, "����");
	//�жϰ�ť�Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h)) {
		return true;
	}
	return false;
}
int zhuanhuan(char a[]) {
	int i = 0;
	int sum = 0;
	while (a[i] != '\0') {
		sum *= 10;
		sum += a[i++] - '0';
	}
	return sum;
}
void jiazai() {
	//����ͼƬ����  int a;
	IMAGE img_mm;//img ͼƬ
	//����ͼƬ     scanf("%d",&a);
	//ͼƬ��ַ��1������·�������̷���·������б��Ҫ��б�ܣ��Ҹ�ʽҪ��ȷ��//E:\\��ҵ1\\easyx��������˫���壬֡�ʿ���\\easyx��������˫���壬֡�ʿ���\\ok\\LLjLEqie8G.jpg.jpg
	//2�����·�� ���������Ե�·�������ã������ڱ��˵������� ��//ok/LLjLEqie8G.jpg.jpg
	loadimage(&img_mm, "ok/LLjLEqie8G.jpg.jpg");//loadimage(&img_mm, ""480��400);��������ָ��ͼƬ��С
	//���ͼƬ    printf("%d", a);
	putimage(1000, 500, &img_mm);
}
//��ֹ�������
bool Interval(clock_t currentTime) {
	if (currentTime - lastClickTime > CLICK_DELAY) {
		lastClickTime = currentTime;
		return true;
	}
	else {
		return false;
	}
}
