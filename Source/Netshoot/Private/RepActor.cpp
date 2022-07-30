// Fill out your copyright notice in the Description page of Project Settings.


#include "RepActor.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ARepActor::ARepActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ARepActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARepActor::OnOverlap);
}

void ARepActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OterComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UKismetSystemLibrary::PrintString(this, "Hit");
}

// Called every frame
void ARepActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

