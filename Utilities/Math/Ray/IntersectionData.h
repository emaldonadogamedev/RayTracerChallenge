#pragma once

namespace RayTracer
{
	namespace Shapes {
		class IShape;
	}

	namespace Math
	{
		class IntersectionData
		{
			public:
				IntersectionData(const Shapes::IShape* shapeIntersected, const float tClose = 0.f, const float tExtra = 0.f)
					:m_shapeIntersected(shapeIntersected)
					,m_tValue(tClose)
					, m_tExtra(tExtra)
				{
				}
				
				~IntersectionData()
				{
				}

				bool DidIntersect() const 
				{
					m_shapeIntersected != nullptr;
				}

				const Shapes::IShape* m_shapeIntersected;
				float m_tValue;
				float m_tExtra;
		};
	}
}