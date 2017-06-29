#include "transform.h"
#include "board.h"
void Transform::transform() {
	if (board.shapes.size() == 0){
		cout << "Ŀǰû��ͼ�ο���ѡ��" << endl;
		return;
	}
	cout << "���������ѡ��ͼ�� e.g: 0" << endl;
	board.showShapes();
	int num;
	cin >> num;
	cout << "��������Ҫ���еĲ���: shift �� rotate �� scale" << endl;
	string cmd;
	cin >> cmd;
	if (cmd == "shift") {
		shift(num);
	}
	else if (cmd == "rotate") {
		rotate(num);
	}
	else if (cmd == "scale") {
		scale(num);
	}
	else {
		cout << "û�и�����" << endl;
	}
	return;
}

void Transform::shift(int num) {
	cout << "������x����y�����ƽ�ƶ������أ�e.g: 20 40" << endl;
	int dx, dy;
	cin >> dx >> dy;
	for (Point &i : board.shapes[num].points) {
		i = i.add(dx, dy);
	}
	board.flush();
}

void Transform::rotate(int num) {
	cout << "��������ת�ο����������ת�Ƕ�, e.g: 50 50 1(��ʾ�ο�������(50, 50), ��ת����1)" << endl;
	int x, y;
	double theta;
	cin >> x >> y >> theta;
	for (Point &i : board.shapes[num].points) {
		i = i.rotate(Point(x, y), theta);
	}
	board.flush();
}

void Transform::scale(int num) {
	cout << "������Ŵ�ο���ͷŴ����� e.g: 50 50 2(��ʾ�ο�������(50, 50), �Ŵ���Ϊ2)" << endl;
	int x, y;
	float scale;
	cin >> x >> y >> scale;
	for (Point &i : board.shapes[num].points) {
		i = i.scale(Point(x, y), scale);
	}
	board.flush();
}