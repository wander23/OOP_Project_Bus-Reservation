#include"Bus.h"

int main()
{
	BusStation a;
//Create Admin Account && Log In 
	//a.setAdmin();
	//a.logInForAdmin();

	a.Install();
	a.Rev();
	a.saveInfoIntoHistory();
	system("pause");
	return 0;
}