#ifndef LFCORE_H_
#define LFCORE_H_

#include "Time/GameTime.h"


typedef int l_s32;
typedef float l_f32;


struct GLFWwindow;

namespace lj
{
	class Core
	{
	public:
		Core();
		~Core();

		void initialize();

		void fixedUpdate(GameTime* gameTime);
		void update(GameTime* gameTime);
		void lateUpdate(GameTime* gameTime);

		void preDraw();
		void draw(GameTime* gameTime);

		void drawNative(GameTime* gameTime);

		void setWindowSize(int width, int height);

	private:
		int m_Width;
		int m_Height;
	};
}



#endif