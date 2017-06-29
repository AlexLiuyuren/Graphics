#include "transform.h"
#include "board.h"
void Transform::transform() {
	if (board.shapes.size() == 0){
		cout << "目前没有图形可以选择" << endl;
		return;
	}
	cout << "请输入序号选择图形 e.g: 0" << endl;
	board.showShapes();
	int num;
	cin >> num;
	cout << "请输入你要进行的操作: shift 或 rotate 或 scale" << endl;
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
		cout << "没有该命令" << endl;
	}
	return;
}

void Transform::shift(int num) {
	cout << "请输入x方向y方向各平移多少像素，e.g: 20 40" << endl;
	int dx, dy;
	cin >> dx >> dy;
	for (Point &i : board.shapes[num].points) {
		i = i.add(dx, dy);
	}
	board.flush();
}

void Transform::rotate(int num) {
	cout << "请输入旋转参考点坐标和旋转角度, e.g: 50 50 1(表示参考点坐标(50, 50), 旋转弧度1)" << endl;
	int x, y;
	double theta;
	cin >> x >> y >> theta;
	for (Point &i : board.shapes[num].points) {
		i = i.rotate(Point(x, y), theta);
	}
	board.flush();
}

void Transform::scale(int num) {
	cout << "请输入放大参考点和放大倍数， e.g: 50 50 2(表示参考点坐标(50, 50), 放大倍数为2)" << endl;
	int x, y;
	float scale;
	cin >> x >> y >> scale;
	for (Point &i : board.shapes[num].points) {
		i = i.scale(Point(x, y), scale);
	}
	board.flush();
}