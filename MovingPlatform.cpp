// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	inRot = GetActorRotation();
	// SetActorScale3D(Scale);
	FString Name = GetName();
	UE_LOG(LogTemp, Display, TEXT("%s Spawned"),*Name); //* important for dereferncing

}
bool Check;
// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	movingPlatform(DeltaTime);
	RotatePlatform(DeltaTime);  
	}

void AMovingPlatform::movingPlatform(float DeltaTime){
	Super::Tick(DeltaTime);
	// FString Name = GetName();
	// float DistanceMoved = FVector::Distance(StartLocation,Currentlocation);

	if (distanceCheck())
	{   
	    // float overshot = DistanceMoved - MoveDistance;
		// UE_LOG(LogTemp, Warning, TEXT("%s overshot by %f cm"), *Name, overshot); //gives error of movement therfore we have used GetSafeNormal
        FVector MoveDirection = VelocityVector.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection*MoveDistance; 
		SetActorLocation(StartLocation);
		VelocityVector = -VelocityVector; 
		// inRot.Yaw = inRot.yaw - 180;
		// SetActorRotation(inRot);
	}
	else
	{
    FVector Currentlocation = GetActorLocation();
	Currentlocation = Currentlocation + (VelocityVector*DeltaTime);
    SetActorLocation(Currentlocation);

	}
	// roll is rotating along X
	// Scale.X += 0.1;
	// Scale.Y += 0.1;
	// SetActorScale3D(Scale);

	//Move forward 
	    // get current vector
		//add vector to that location
		// set the location
	// Move backward if gone too far (Like if gone more than hundred units)
	    // 	check how far it has moved
		// 	reverse direction of motion 
}

void AMovingPlatform::RotatePlatform(float DeltaTime){
    UE_LOG(LogTemp, Display, TEXT("Will Rotate"));
}

bool AMovingPlatform::distanceCheck(){
	// FVector Currentlocation = GetActorLocation();
	float DistanceMoved = FVector::Distance(StartLocation,GetActorLocation());
    return DistanceMoved > MoveDistance;
}