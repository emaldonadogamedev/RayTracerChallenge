#pragma once

#include <vector>

namespace RayTracer
{
	namespace Shapes
	{
		class IShape;

		class Scene
		{
			public:
				Scene();
				~Scene();

				void PushShape(const IShape* m_shapes);
				void ClearShapes();

				const std::vector<IShape*>& GetShapes() const;

			protected:
				std::vector<IShape*> m_shapes;
		};
	}
}