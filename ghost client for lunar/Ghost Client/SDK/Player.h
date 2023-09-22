#include "../Java.h"

class CPlayer
{
public:
	CPlayer(jobject istance);
	void Cleanup();
private:
	jobject playerInstance;
};