#pragma once

namespace RayTracer
{
	namespace Shapes
	{
		class IShape;
		class IntersectionData
		{
			public:
				IntersectionData(const IShape* shapeIntersected = nullptr, const float tClose = 0.f, const float tExtra = 0.f)
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
					return m_shapeIntersected != nullptr;
				}

				const IShape* m_shapeIntersected;
				float m_tValue;
				float m_tExtra;
		};
	}
}