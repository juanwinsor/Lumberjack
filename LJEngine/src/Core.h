#ifndef LFCORE_H_
#define LFCORE_H_

#include "Time/GameTime.h"


typedef int l_s32;
typedef float l_f32;



class GLFWwindow;

namespace lj
{
	class Core
	{
	public:
		Core();
		~Core();

		void initialize(GLFWwindow* window);

		void fixedUpdate(GameTime* gameTime);
		void update(GameTime* gameTime);
		void lateUpdate(GameTime* gameTime);

		void preDraw();
		void draw(GameTime* gameTime);

	private:
		GLFWwindow* m_Window;
	};
}



#endif