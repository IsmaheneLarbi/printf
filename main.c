#include <locale.h>
#include "ft_printf.h"

int		main()
{
	wchar_t *wstr = L"لكمنهسزرذدخحجغففللنيء؟؛ونقففغ";
	setlocale(LC_ALL, "");
	ft_putnbr(printf("%60ls\n", wstr));
	//ft_putnbr(ft_printwstr(wstr, 4));
	return (0);
}
