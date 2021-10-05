#include "WinGLApplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "FontCache.h"


namespace T3D
{
	//! \brief Tutorial1 Driver
	class Tutorial4 :
		public WinGLApplication
	{
	public:
		//Tutorial4(void);
		//~Tutorial4(void) = default;

		bool init();


	private:
		Texture* drawArea;
		DrawTask* drawTask;

	};

}




