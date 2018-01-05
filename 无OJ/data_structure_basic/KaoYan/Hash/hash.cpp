#include "hash.h"
int main(int argc, char const *argv[])
{
	std::map<string, string> mapstr;
	mapstr["U201112375"] = "靳杰";
	mapstr["U201112374"] = "龙方正";
	mapstr["U201112376"] = "刘本熙";
	cout<<mapstr["U201112375"]<<endl;
	cout<<mapstr["U201112374"]<<endl;
	cout<<mapstr["U201112376"]<<endl;
	return 0;
}