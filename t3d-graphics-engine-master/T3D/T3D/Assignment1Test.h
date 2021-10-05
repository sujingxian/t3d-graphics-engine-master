#include "WinGLApplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "FontCache.h"

namespace T3D
{
	
	class Assignment1Test :
		public WinGLApplication
	{
	public:
		//Assignment1Test(void);
		//~Assignment1Test(void) = default;

		bool init();


	private:
		Texture* drawArea;
		DrawTask* drawTask;

	};

}
