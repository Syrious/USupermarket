// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RRefillObject.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "CacheAssetLoader.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemSpawned, AActor*, SpawnedActor);

UCLASS()
class REFILL_API ACacheAssetLoader : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACacheAssetLoader();

	UPROPERTY(EditAnywhere, Category = "REFILLS")
		ATriggerBox* SpawnPoint;

	UPROPERTY()
		TArray<FString> AssetsInChache;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnAsset(const FString Path, const FVector Location, const FRotator Rotation);
	void SpawnAsset(const FString Path);

	UPROPERTY()
		FItemSpawned OnItemSpawend;

	ARRefillObject* GetSpawnedItem() {
		return CurrentObject;
	}

private:


	FString CachePath;

	ARRefillObject* CurrentObject;

	void ReadAdditionalObjectParameters(ARRefillObject* RefillObj, FString PathToAsset);
	void SetupHoleTab(ARRefillObject* RefillObj, FVector HoleTabPosition);


};