#include "Utilities/precompiled/precompiled.h"

#include "Rendering/Lights/Lights.h"
#include "Rendering/Materials/Materials.h"
#include "Rendering/ShapeRenderer/ShapeRenderer.h"

#include "Serialization/Canvas/Canvas.h"
#include "Serialization/CanvasExporter/CanvasExporter.h"

#include "Shapes/IntersectionData.h"
#include "Shapes/Sphere/Shpere.h"

#include "Utilities/Math/Matrix4x4/Matrix4x4.h"
#include "Utilities/Math/Ray/Ray.h"

using namespace RayTracer::Math;
using namespace RayTracer::Rendering;
using namespace RayTracer::Serialization;
using namespace RayTracer::Shapes;

int main(int argc, char** argv)
{
	Matrix4x4 sqrMtx(4);

	////DET = -2120
	//sqrMtx.SetElement(0, 0, 6.f); sqrMtx.SetElement(0, 1, 4.f); sqrMtx.SetElement(0, 2, 4.f); sqrMtx.SetElement(0, 3, 4.f);
	//sqrMtx.SetElement(1, 0, 5.f); sqrMtx.SetElement(1, 1, 5.f); sqrMtx.SetElement(1, 2, 7.f); sqrMtx.SetElement(1, 3, 6.f);
	//sqrMtx.SetElement(2, 0, 4.f); sqrMtx.SetElement(2, 1, -9.f); sqrMtx.SetElement(2, 2, 3.f); sqrMtx.SetElement(2, 3, -7.f);
	//sqrMtx.SetElement(3, 0, 9.f); sqrMtx.SetElement(3, 1, 1.f); sqrMtx.SetElement(3, 2, 7.f); sqrMtx.SetElement(3, 3, -6.f);

	//DET = 0
	//sqrMtx.SetElement(0, 0, -4.f); sqrMtx.SetElement(0, 1, 2.f); sqrMtx.SetElement(0, 2, -2.f); sqrMtx.SetElement(0, 3, -3.f);
	//sqrMtx.SetElement(1, 0, 9.f); sqrMtx.SetElement(1, 1, 6.f); sqrMtx.SetElement(1, 2, 2.f); sqrMtx.SetElement(1, 3, 6.f);
	//sqrMtx.SetElement(2, 0, 0.f); sqrMtx.SetElement(2, 1, -5.f); sqrMtx.SetElement(2, 2, 1.f); sqrMtx.SetElement(2, 3, -5.f);
	//sqrMtx.SetElement(3, 0, 0.f); sqrMtx.SetElement(3, 1, 0.f); sqrMtx.SetElement(3, 2, 0.f); sqrMtx.SetElement(3, 3, -0.f);

	//float d = sqrMtx.Determinant();

	Ray ray(Vector3(0,0,-5.f), Vector3(0,0,1));

	const float wall_z = 10.f;
	const float wall_size = 7.f;

	const float canvas_pixels = 512.f;
	const unsigned canvas_pixels_uint = (unsigned)canvas_pixels;

	const float pixel_size = wall_size / canvas_pixels;
	const float half_wall_size = wall_size / 2.0f;

	Color sphereColor = Color(255, 0, 0);

	Canvas canvas(canvas_pixels_uint, canvas_pixels_uint);
	Shpere sphere;
	sphere.SetTransformData(Vector3(.23f,.10f,0), Vector3(0,0,0), Vector3(1, .5f, 1.f));
	
	PhongMaterial phongMaterial;
	phongMaterial.color = Vector4(1.f, .2f, 1.f, 1.f);
	phongMaterial.m_ambient = .1f;
	phongMaterial.m_diffuse = .9f;
	phongMaterial.m_specular = .9f;
	phongMaterial.m_shininess = 200.f;

	sphere.m_shapeMaterial = &phongMaterial;

	Light light;
	light.position = Vector3(-10.f, 10.f, -10.f);
	light.color = Vector4(1,1,1,1);

	IntersectionData intersectionData;

	Vector3 currentRayTargetPos;
	currentRayTargetPos.z = wall_z; //set the z value here, no need to updated it for now

	for (int y = 0; y < canvas_pixels_uint; ++y)
	{
		float world_y = half_wall_size - pixel_size * y;
		
		for (int x = 0; x < canvas_pixels_uint; ++x)
		{
			float world_x = -half_wall_size + pixel_size * x;

			currentRayTargetPos.x = world_x;
			currentRayTargetPos.y = world_y;

			ray.m_direction = (currentRayTargetPos - ray.m_origin).Normalized();

			if (sphere.Intersects(ray, intersectionData))
			{
				Vector3 point = ray.Evaluate(intersectionData.m_tValue);
				Vector3 normal = sphere.CalculateNormal(point);

				canvas.AddColorValue(x, y, CaculatePhongLighting(phongMaterial, light, point, -ray.m_direction, normal).AsColor());
			}
		}
	}

	CanvasExporter::ExportToPPMimage(canvas, "test1stRayTracedSphere");

	return 0;
}