#include "AppController.h"

int main(void) {

	AppController* appController = AppController_new();	//AppController ��ü ����
	AppController_run(appController);	//AppController ��ü ����
	AppController_delete(appController);	//AppController ��ü ����

	system("pause"); // �ܼ� �ڵ� ���� ����
	return 0;
}
