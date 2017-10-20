// Fe-eze Anya 2017

#include "TankTurret.h"
//#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"

void UTankTurret::Traverse(float RelativeSpeed)
{
	auto RelSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto TraverseChange = RelSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; // deltatimesec makes it frame independent
	auto RawNewTraverse = RelativeRotation.Yaw + TraverseChange;
//	auto Traverse = FMath::Clamp<float>(RawNewTraverse, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(0, RawNewTraverse, 0));
}




