#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;
 

void test_thread(int i)
{
	while (1)
	{
		cout << "This is thead " << i << endl;
		Sleep(200*(i+1));
	}
}


int main()
{
	cout << "This is main thread." << endl;
	for (int i = 0; i < 3; i++)
	{
		thread t(test_thread, i);
		//t.join();//wait until the above thread exit
		t.detach();//the above thread run backstage
	}

	cout << "create threads successfully." << endl;
	getchar();
	return 0;

}