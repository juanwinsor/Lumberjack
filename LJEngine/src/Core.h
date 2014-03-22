#ifndef LFCORE_H_
#define LFCORE_H_


class GameTime;
class EntityManager;

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

	private:

		EntityManager* m_EntityManager;

	};
}



#endif