#include <iostream>
using namespace std;

void GoldenRatio() {
	float A=1.,fib=1.6180339,err=1., result = 1.;
	int n;
	cout << "Введите точность: ";
	cin >> n;

	__asm
	{
		CMP n, 0
		JE endd

		CMP n, 1
		JE endd

		MOV ecx, n
mainloop :

		MOVSS xmm1, A       //xmm1=1
		DIVSS xmm1, result  //xmm1/result
		ADDSS xmm1, A       //xmm1=xmm1+1
		MOVSS result, xmm1

LOOP mainloop
        MOVSS xmm1, fib
        SUBSS xmm1 ,result
        MOVSS err, xmm1
endd :
	};
	cout << "ответ: " << result<<endl;
	cout << "ошибка: " << err;
}

int main()
{
	setlocale(0, "");
	GoldenRatio();	
	//system("pause");
	return 0;
}